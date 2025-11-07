
/*********************************************
****   HyperDrive - Parallel quick sort   ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifndef __HD_PQSORT_H
#  define  __HD_PQSORT_H

/**** Constants ****/

#  define   SLICE_THRESH          4096    /* Thread elements treshold         */
#  define   THR_PER_LWP           8       /* Threads for each split           */

/**** Macros ****/

#  define   SUB(a, n)      ((HD_VOID *) (((unsigned char *) (a)) + ((n) * width)))

/**** Sort structure ****/

typedef struct {
  HD_VOID *                sa_base;
  HD_LONG               sa_nel;
  HD_ULONG              sa_width;
  HD_SORTCALLBACK       sa_compar;
} HD_SORT_ARGS;

/**** Local variables ****/

static HD_ULONG         threads_avail;
#endif

/**** Four byte swap ****/

#ifdef HD_SORT_DATA_4
#  define HD_FP(X)      X ## 4

#define SWAP(a, i, j, width) \
{ \
  unsigned long ul; \
\
  if (SUB(a, i) == pivot) \
    pivot = SUB(a, j); \
  else if (SUB(a, j) == pivot) \
    pivot = SUB(a, i); \
\
  ul = *((unsigned long *) SUB(a, i)); \
  *((unsigned long *) SUB(a, i)) = *((unsigned long *) SUB(a, j)); \
  *((unsigned long *) SUB(a, j)) = ul; \
}
#  undef HD_SORT_DATA_4
#endif

/**** Generic swap ****/

#ifdef HD_SORT_DATA_GENERIC
#  define HD_FP(X)      X

#define SWAP(a, i, j, width) \
{ \
  unsigned int          n; \
  unsigned char         uc; \
 \
  if (SUB(a, i) == pivot) \
    pivot = SUB(a, j); \
  else if (SUB(a, j) == pivot) \
    pivot = SUB(a, i); \
 \
  for(n = 0; n < width; n++) { \
    uc = ((unsigned char *) SUB(a, i))[n]; \
    ((unsigned char *) SUB(a, i))[n] = ((unsigned char *) SUB(a, j))[n]; \
    ((unsigned char *) SUB(a, j))[n] = uc; \
  } \
}
#  undef HD_SORT_DATA_GENERIC
#endif


/**** Parallel quicksort helper ****/

static HD_LONG HD_CALLBACK HD_FP(QuickSortP)(HD_VOID *arg)
{
  HD_SORT_ARGS          sort_args[2];
  register HD_LONG      i, j;
  HD_LONG               z;
  HD_VOID *             t;
  HD_VOID *             b[3];

  HD_SORT_ARGS *        sargs        = (HD_SORT_ARGS *)arg;
  HD_THREAD             tid          = HD_NULL;
  register HD_VOID *    a            = sargs -> sa_base;
  HD_LONG               n            = sargs -> sa_nel;
  HD_ULONG              thread_count = 0;
  HD_ULONG              width        = sargs -> sa_width;
  HD_SORTCALLBACK       compar       = sargs -> sa_compar;
  HD_VOID *             pivot        = HD_NULL;

  /**** Find the pivot point ****/

  switch(n) {
  case 0:
  case 1:
    return 0;
  case 2:
    if ((*compar)(SUB(a, 0), SUB(a, 1)) > 0) {
      SWAP(a, 0, 1, width);
    }
    return 0;
  case 3:
    /* three sort */
    if ((*compar)(SUB(a, 0), SUB(a, 1)) > 0) {
      SWAP(a, 0, 1, width);
    }
    /* the first two are now ordered, now order the second two */
    if ((*compar)(SUB(a, 2), SUB(a, 1)) < 0) {
      SWAP(a, 2, 1, width);
    }
    /* should the second be moved to the first? */
    if ((*compar)(SUB(a, 1), SUB(a, 0)) < 0) {
      SWAP(a, 1, 0, width);
    }
    return 0;
  default:
    if (n > 3) {
      b[0] = SUB(a, 0);
      b[1] = SUB(a, n / 2);
      b[2] = SUB(a, n - 1);
      /* three sort */
      if ((*compar)(b[0], b[1]) > 0) {
        t = b[0];
        b[0] = b[1];
        b[1] = t;
      }
      /* the first two are now ordered, now order the second two */
      if ((*compar)(b[2], b[1]) < 0) {
        t = b[1];
        b[1] = b[2];
        b[2] = t;
      }
      /* should the second be moved to the first? */
      if ((*compar)(b[1], b[0]) < 0) {
        t = b[0];
        b[0] = b[1];
        b[1] = t;
      }
      if ((*compar)(b[0], b[2]) != 0) {
        if ((*compar)(b[0], b[1]) < 0) pivot = b[1];
        else pivot = b[2];
      }
    }
    break;
  }
  if (pivot == 0)
    for(i=1; i<n; i++) {
      if ((z = (*compar)(SUB(a, 0), SUB(a, i))) != 0) {
        pivot = (z > 0) ? SUB(a, 0) : SUB(a, i);
        break;
      }
    }
  if (!pivot) return 0;

  /**** Sort ****/

  i = 0;
  j = n - 1;
  while(i <= j) {
    while((*compar)(SUB(a, i), pivot) <  0) ++i;
    while((*compar)(SUB(a, j), pivot) >= 0) --j;
    if (i < j) {
      SWAP(a, i, j, width);
      ++i;
      --j;
    }
  } /* End of while */

  /**** Sort the sides judiciously ****/

  switch(i) {
  case 0:
  case 1:
    break;
  case 2:
    if ((*compar)(SUB(a, 0), SUB(a, 1)) > 0) {
      SWAP(a, 0, 1, width);
    }
    break;
  case 3:
    /* three sort */
    if ((*compar)(SUB(a, 0), SUB(a, 1)) > 0) {
      SWAP(a, 0, 1, width);
    }
    /* the first two are now ordered, now order the second two */
    if ((*compar)(SUB(a, 2), SUB(a, 1)) < 0) {
      SWAP(a, 2, 1, width);
    }
    /* should the second be moved to the first? */
    if ((*compar)(SUB(a, 1), SUB(a, 0)) < 0) {
      SWAP(a, 1, 0, width);
    }
    break;

  default:
    sort_args[0].sa_base   = a;
    sort_args[0].sa_nel    = i;
    sort_args[0].sa_width  = width;
    sort_args[0].sa_compar = compar;

    /**** Create a new thread ****/

    if ((threads_avail > 0) && (i > SLICE_THRESH)) {
      threads_avail--;
      tid = HD_MthCreateThread(HD_FP(QuickSortP), &sort_args[0]);
      thread_count = 1;
    } else HD_FP(QuickSortP)(&sort_args[0]);
    break;
  }

  j = n - i;
  switch(j) {
  case 1:
    break;

  case 2:
    if ((*compar)(SUB(a, i), SUB(a, i + 1)) > 0) {
      SWAP(a, i, i + 1, width);
    }
    break;

  case 3:
    /* three sort */
    if ((*compar)(SUB(a, i), SUB(a, i + 1)) > 0) {
      SWAP(a, i, i + 1, width);
    }
    /* the first two are now ordered, now order the second two */
    if ((*compar)(SUB(a, i + 2), SUB(a, i + 1)) < 0) {
      SWAP(a, i + 2, i + 1, width);
    }
    /* should the second be moved to the first? */
    if ((*compar)(SUB(a, i + 1), SUB(a, i)) < 0) {
      SWAP(a, i + 1, i, width);
    }
    break;

  default:
    sort_args[1].sa_base          = SUB(a, i);
    sort_args[1].sa_nel           = j;
    sort_args[1].sa_width         = width;
    sort_args[1].sa_compar        = compar;
    if ((thread_count == 0) && (threads_avail > 0) && (i > SLICE_THRESH)) {
      threads_avail--;
      tid = HD_MthCreateThread(HD_FP(QuickSortP), &sort_args[1]);
      thread_count = 1;
    } else HD_FP(QuickSortP)(&sort_args[1]);
    break;
  } /* End of switch */

  if (thread_count) {
    HD_MthWaitThread(tid);
    HD_MthCloseThread(tid);
    threads_avail++;
  }

  return 0;
}

#undef HD_FP
#undef SWAP

