/*-------------------------------------------------------------------------
*
* kmeans.c
*    Generic k-means implementation
*
* Copyright (c) 2016, Paul Ramsey <pramsey@cleverelephant.ca>
*
*------------------------------------------------------------------------*/


#include <float.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include <hyperdrive.h>
#include <hdthread.h>

#ifdef __BORLANDC__
#  pragma hdrstop
#  pragma argsused
#endif

#include "kmeans.h"

/**** Prototypes ****/

static HD_VOID  HD_FASTCALL update_r(kmeans_config *config);
static HD_VOID  HD_FASTCALL update_means(kmeans_config *config);

HD_VOID         HD_FASTCALL update_r_threaded(kmeans_config *config);


#ifdef KMEANS_THREADED
static HD_LONG  HD_CALLBACK update_means_threaded_main(HD_VOID *arg);
static HD_VOID              update_means_threaded(kmeans_config *config);
static HD_LONG  HD_CALLBACK update_r_threaded_main(HD_VOID *args);
#endif


/**** Main code ****/

kmeans_result HD_FASTCALL kmeans(kmeans_config *config)
{
  HD_LONG *           clusters_last;
  HD_ULONG            iterations;

  HD_SIZE             clusters_sz = sizeof(HD_LONG) * config -> num_objs;
  kmeans_result       RetCode     = KMEANS_EXCEEDED_MAX_ITERATIONS;

#ifdef KMEANS_THREADED
  HD_ULONG            MaxLocalThreads;
  HD_ULONG            update_means_k;
  kmeans_thread_data  ThreadData;

  HD_ULONG            MaxThreads  = HD_MthThreads();

  config -> ThreadData            = &ThreadData;
  ThreadData.NumThreadK           = config -> num_objs * config -> k / KMEANS_THR_THRESHOLD;
  ThreadData.NumThreadObj         = config -> num_objs / KMEANS_THR_THRESHOLD;
  ThreadData.Thread               = new HD_THREAD [MaxThreads];
  ThreadData.update_means_k       = &update_means_k;
  ThreadData.update_means_k_mutex = HD_MthCreateMutexEx();

  if (ThreadData.NumThreadK   > MaxThreads) ThreadData.NumThreadK   = MaxThreads;
  if (ThreadData.NumThreadObj > MaxThreads) ThreadData.NumThreadObj = MaxThreads;

  if ((ThreadData.NumThreadK > 1) || (ThreadData.NumThreadObj > 1)) {
    MaxLocalThreads = (ThreadData.NumThreadK > ThreadData.NumThreadObj) ?
                       ThreadData.NumThreadK : ThreadData.NumThreadObj;
    ThreadData.ConfigVect = new kmeans_config[MaxLocalThreads];
  } else {
    ThreadData.ConfigVect = config;
    MaxLocalThreads       = 1;
  }
#endif

  /**** Zero out cluster numbers, just in case user forgets ****/

  HD_MemZero(config -> clusters, clusters_sz);

  /**** Set default max iterations if necessary ****/

  if (!config -> max_iterations)
    config -> max_iterations = KMEANS_MAX_ITERATIONS;

#ifdef KMEANS_THREADED
  if (ThreadData.ConfigVect) {
    HD_ULONG i;

    for(i = 0; i < MaxLocalThreads; ++ i)
      ThreadData.ConfigVect[i] = *config;
  }
#endif

  /*
   * Previous cluster state array. At this time, r doesn't mean anything
   * but it's ok
   */

  clusters_last = new HD_LONG [clusters_sz];

  for(iterations = 0; iterations < config -> max_iterations; ++iterations) {

    /**** Store the previous state of the clustering ****/

    HD_MemCpy(clusters_last, config -> clusters, clusters_sz);

#ifdef KMEANS_THREADED
    update_r_threaded(config);
    update_means_threaded(config);
#else
    update_r(config);
    update_means(config);
#endif
    /*
     * if all the cluster numbers are unchanged since last time,
     * we are at a stable solution, so we can stop here
     */
    if (memcmp(clusters_last, config -> clusters, clusters_sz) == 0) {
      RetCode = KMEANS_OK;
      break;
    }
  } /* End of for (iterations) */

  /**** Free the resources ****/

#ifdef KMEANS_THREADED
  HD_MthCloseMutexEx(ThreadData.update_means_k_mutex);

  if (MaxLocalThreads > 1)
    delete [] ThreadData.ConfigVect;
  delete [] ThreadData.Thread;
#endif

  delete [] clusters_last;
  config -> total_iterations = iterations;

  return RetCode;
}


HD_VOID HD_FASTCALL update_r(kmeans_config *config)
{
  HD_SIZE     i;

  for(i = 0; i < config -> num_objs; i++) {
    HD_FLOAT    distance, curr_distance;
    HD_ULONG    cluster, curr_cluster;

    HD_POINTER  obj = config -> objs[i];

    /*
     * Don't try to cluster NULL objects, just add them
     * to the "unclusterable cluster"
     */

    if (!obj) {
      config -> clusters[i] = KMEANS_NULL_CLUSTER;
      continue;
    }

    /**** Initialize with distance to first cluster ****/

    curr_distance = (config -> distance_method)(obj, config -> centers[0]);
    curr_cluster  = 0;

    /**** Check all other cluster centers and find the nearest ****/

    for (cluster = 1; cluster < config -> k; cluster++) {
      distance = (config -> distance_method)(obj, config -> centers[cluster]);
      if (distance < curr_distance) {
        curr_distance = distance;
        curr_cluster  = cluster;
      }
    }

    /**** Store the nearest cluster this object is in ****/

    config -> clusters[i] = curr_cluster;
  } /* End of for (i) */
}


/**** Update the centroids ****/

HD_VOID HD_FASTCALL update_means(kmeans_config *config)
{
  HD_ULONG i;

  for(i = 0; i < config -> k; i++)
    (config -> centroid_method)(config -> objs, config -> clusters, config -> num_objs, i, config -> centers[i]);
}


#ifdef KMEANS_THREADED
HD_LONG HD_CALLBACK update_r_threaded_main(HD_VOID *args)
{
  kmeans_config *   config = (kmeans_config*)args;
  update_r(config);

  return FALSE;
}


HD_VOID HD_FASTCALL update_r_threaded(kmeans_config *config)
{
  HD_ULONG        NumThreadK = config -> ThreadData -> NumThreadK;

  if (NumThreadK <= 1) {
    update_r(config);
  } else {
    HD_ULONG        i;

    kmeans_config * thread_config  = config -> ThreadData -> ConfigVect;
    HD_ULONG        obs_per_thread = config -> num_objs / NumThreadK;

    for(i = 0; i < NumThreadK; i++) {
      thread_config -> objs     = config -> objs + i * obs_per_thread;
      thread_config -> clusters = config -> clusters + i * obs_per_thread;
      thread_config -> num_objs  = obs_per_thread;

      if (i == NumThreadK - 1)
        thread_config -> num_objs += config -> num_objs - NumThreadK * obs_per_thread;

      /* Now we just run the thread, on its subset of the data */

      config -> ThreadData -> Thread[i] = HD_MthCreateThread(update_r_threaded_main, thread_config);
#ifdef WIN32
      HD_MthSetThreadAffinity(config -> ThreadData -> Thread[i], i);
#endif
      ++thread_config;
    } /* End of for (i) */

    /**** Wait the threads ****/

    HD_MthWaitThreads(config -> ThreadData -> Thread, NumThreadK, HD_NULL);

    /**** Close the threads ****/

    for(i = 0; i < NumThreadK; i++)
      HD_MthCloseThread(config -> ThreadData -> Thread[i]);
  }
}


HD_LONG HD_CALLBACK update_means_threaded_main(HD_VOID *arg)
{
  kmeans_config * config = (kmeans_config *)arg;
  HD_ULONG        i;

  do {
    HD_MthMutexOnEx(config -> ThreadData -> update_means_k_mutex);
    i = *config -> ThreadData -> update_means_k;
    ++*config -> ThreadData -> update_means_k;
    HD_MthMutexOffEx(config -> ThreadData -> update_means_k_mutex);

    if (i < config -> k)
      (config -> centroid_method)(config -> objs, config -> clusters, config -> num_objs, i, config -> centers[i]);
  } while (i < config -> k);

  return FALSE;
}


HD_VOID update_means_threaded(kmeans_config *config)
{
  HD_ULONG        NumThreadObj = config -> ThreadData -> NumThreadObj;

  /**** If the problem size is small, don't bother w/ threading ****/

  if (NumThreadObj <= 1) {
    update_means(config);
  } else {
    HD_ULONG      i;

    *config -> ThreadData -> update_means_k = 0;

    /**** Create threads to perform computation  ****/

    for(i = 0; i < NumThreadObj; i++) {
      config -> ThreadData -> Thread[i] = HD_MthCreateThread(update_means_threaded_main, config);
#ifdef WIN32
      HD_MthSetThreadAffinity(config -> ThreadData -> Thread[i], i);
#endif
    } /* End of for (i) */

    /**** Wait the threads ****/

    HD_MthWaitThreads(config -> ThreadData -> Thread, NumThreadObj, HD_NULL);

    /**** Close the threads ****/

    for(i = 0; i < NumThreadObj; i++)
      HD_MthCloseThread(config -> ThreadData -> Thread[i]);
  }
}
#endif



