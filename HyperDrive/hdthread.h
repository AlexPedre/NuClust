
/*********************************************
****  HyperDrive - Multithreading header  ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifndef __HDTHREAD_H
#  define  __HDTHREAD_H

#  ifndef __HDRIVE_H
#    include <hyperdrive.h>
#  endif

/**** Amiga definitions ****/

#  ifdef AMIGA
#    define  HD_MTH_AMIGA
#    define  HD_MTH_MAX_CPU        1
#  endif

/**** Linux definitions ****/

#  ifdef linux
#    define  HD_MTH_LINUX
#    define  HD_MTH_PTHREAD
#    define  HD_MTH_MAX_CPU        256
#    define  HD_MTH_PSEMAPHORE
#  endif

/**** SGI definitions ****/

#  ifdef sgi
#    define  HD_MTH_SGI
#    define  HD_MTH_MAX_CPU        256
#    define  HD_MTH_PSEMAPHORE
#  endif

/**** Sun definitions ****/

#  ifdef _sun
#    define  HD_MTH_SUN
#    define  HD_MTH_PTHREAD
#    define  HD_MTH_MAX_CPU        256
#    define  HD_MTH_PSEMAPHORE
#  endif

/**** Windows definitions ****/

#  if defined(__WIN32__) || defined(WIN32)
#    define  HD_MTH_WIN32
#    define  HD_MTH_MAX_CPU        256
#    define  HD_MTH_THREAD         int WINAPI
#    define  HD_MTH_USE_CRITICALSECTION
#  else
#    define  HD_MTH_THREAD         int
#  endif

#  ifndef HD_MTH_MAX_CPU
#    define  HD_MTH_MAX_CPU        1
#  endif

#  define  HDT_THREADVARNEW
#  define  HDT_BEGIN               typedef struct { \
                                     HD_ULONG  ThreadID; \
                                     HD_MUTEX  ThreadMutex;
#  define  HDT_END                 } HDT_GLOBVARS;
#  define  HDT_AllocGlobVars(X)    HDT_GLOBVARS HdtGlobVars; \
                                   HdtGlobVars.ThreadID    = 0; \
                                   HdtGlobVars.ThreadMutex = (HD_MthThreads() > 1) ? HD_MthCreateMutexEx() : NULL

#  define  HDT_AllocGvForce(X)     HDT_GLOBVARS HdtGlobVars; \
                                   HdtGlobVars.ThreadID    = 0; \
                                   HdtGlobVars.ThreadMutex = HD_MthCreateMutexEx()

#  define  HDT_FreeGlobVars(X)     if (HD_MthThreads() > 1) HD_MthCloseMutexEx(HdtGlobVars.ThreadMutex)

#  define  HDT_FreeGvForce(X)      HD_MthCloseMutexEx(HdtGlobVars.ThreadMutex)

#  define  HDT_GetVar(X)           HdtGlobVars.X

#  define  HDT_GetVarTh(X)         ((HDT_GLOBVARS *)HdtGlobVars) -> X

#  define  HDT_GetVarThEx(X, Y)    if (MthThreads > 1) \
                                     HD_MthMutexOnEx(((HDT_GLOBVARS *)HdtGlobVars) -> ThreadMutex); \
                                     X = ((HDT_GLOBVARS *)HdtGlobVars) -> Y; \
                                     HD_MthMutexOffEx(((HDT_GLOBVARS *)HdtGlobVars) -> ThreadMutex); \
                                   } else X = ((HDT_GLOBVARS *)HdtGlobVars) -> Y

#  define  HDT_SetVar(X, Y)        HdtGlobVars.X = Y

#  define  HDT_SetVarThEx(X, Y)    if (MthThreads > 1) \
                                     HD_MthMutexOnEx(((HDT_GLOBVARS *)HdtGlobVars) -> ThreadMutex); \
                                     HdtGlobVars.Y = X; \
                                     HD_MthMutexOffEx(((HDT_GLOBVARS *)HdtGlobVars) -> ThreadMutex); \
                                   } else HdtGlobVars.Y = X

#  define  HDT_AddVarTh(X, Y)      ((HDT_GLOBVARS *)HdtGlobVars) -> X += Y

#  define  HDT_AddVarThEx(X, Y)    if (MthThreads > 1) { \
                                     HD_MthMutexOnEx(((HDT_GLOBVARS *)HdtGlobVars) -> ThreadMutex); \
                                     ((HDT_GLOBVARS *)HdtGlobVars) -> X += Y; \
                                     HD_MthMutexOff(((HDT_GLOBVARS *)HdtGlobVars) -> ThreadMutex); \
                                   } else ((HDT_GLOBVARS *)HdtGlobVars) -> X += Y;

#  define  HDT_DecVarTh(X)         --(((HDT_GLOBVARS *)HdtGlobVars) -> X)

#  define  HDT_IncVarTh(X)         ++(((HDT_GLOBVARS *)HdtGlobVars) -> X)

#  define  HDT_ObtainThID(X)        HD_ULONG  MthThreads = HD_MthThreads(); \
                                    if (MthThreads > 1) { \
                                     HD_MthMutexOnEx(((HDT_GLOBVARS *)HdtGlobVars) -> ThreadMutex); \
                                     X = ++((HDT_GLOBVARS *)HdtGlobVars) -> ThreadID; \
                                     HD_MthMutexOffEx(((HDT_GLOBVARS *)HdtGlobVars) -> ThreadMutex); \
                                   } else X = 1

#  define  HDT_ObtainThIdEx(X, N)  if (N > 1) { \
                                     HD_MthMutexOnEx(((HDT_GLOBVARS *)HdtGlobVars) -> ThreadMutex); \
                                     X = ++((HDT_GLOBVARS *)HdtGlobVars) -> ThreadID; \
                                     HD_MthMutexOffEx(((HDT_GLOBVARS *)HdtGlobVars) -> ThreadMutex); \
                                   } else X = 1
/**** C++ classes ****/

#  ifdef __cplusplus

/**** Barrier ****/

class HDC_Barrier
{
  public:

        inline HDC_Barrier(HD_LONG Count) {
          IntBarrier = HD_MthCreateBarrierEx(Count);
          IntCount   = Count;
        }

        inline ~HDC_Barrier(HD_VOID) {
          HD_MthCloseBarrierEx(IntBarrier);
        }

        inline HD_VOID Reset(HD_VOID) {
          HD_MthCloseBarrierEx(IntBarrier);
          IntBarrier = HD_MthCreateBarrierEx(IntCount);
        }

        inline HD_VOID Wait(HD_VOID) {
          HD_MthWaitBarrierEx(IntBarrier);
        }

  private:

        HD_BARRIER              IntBarrier;
        HD_LONG                 IntCount;
};

/**** Event ****/

class HDC_Event
{
  public:

        inline HDC_Event(HD_BOOL InitState = false, HD_BOOL Auto = false) {
          IntEvent = HD_MthCreateEventEx(InitState, Auto);
        }

        inline ~HDC_Event(HD_VOID) {
          HD_MthCloseEventEx(IntEvent);
        }

        inline HD_VOID Reset(HD_VOID) {
          HD_MthResetEventEx(IntEvent);
        }

        inline HD_VOID Set(HD_VOID) {
          HD_MthSetEventEx(IntEvent);
        }

        inline HD_VOID Wait(HD_VOID) {
          HD_MthWaitEventEx(IntEvent);
        }

  private:

        HD_EVENT                IntEvent;
};

/**** Mutex ****/

class HDC_Mutex
{
  public:

        inline HDC_Mutex(HD_VOID) {
          IntMutex = HD_MthCreateMutexEx();
        }

        inline ~HDC_Mutex(HD_VOID) {
          HD_MthCloseMutexEx(IntMutex);
        }

        inline HD_VOID Off(HD_VOID) {
          HD_MthMutexOffEx(IntMutex);
        }

        inline HD_VOID On(HD_VOID) {
          HD_MthMutexOnEx(IntMutex);
        }

  private:

        HD_MUTEX                IntMutex;
};

/**** Semaphore ****/

class HDC_Semaphore
{
  public:

        inline HDC_Semaphore(HD_LONG MaxCount) {
          IntSemaphore = HD_MthCreateSemaphoreEx(MaxCount);
        }

        inline ~HDC_Semaphore(HD_VOID) {
          HD_MthCloseSemaphoreEx(IntSemaphore);
        }

        inline HD_VOID Release(HD_VOID) {
          HD_MthReleaseSemaphoreEx(IntSemaphore);
        }

        inline HD_VOID Wait(HD_VOID) {
          HD_MthWaitSemaphoreEx(IntSemaphore);
        }

  private:

        HD_SEMAPHORE            IntSemaphore;
};

/**** Single thread ****/

class HDC_Thread
{
  public:

        inline HDC_Thread(HD_CALLBACKFUNC Func, HD_VOID *Arg) {
          IntThread = HD_MthCreateThread(Func, Arg);
        }

        inline ~HDC_Thread(HD_VOID) {
          HD_MthCloseThread(IntThread);
        }

        inline HD_VOID Wait(HD_VOID) {
          HD_MthWaitThread(IntThread);
        }

  private:

        HD_THREAD               IntThread;
};


/**** Multiple thread ****/

class HDC_Threads
{
  public:

        /**** Properties ****/

        HD_LONG                 ThreadCount; /* Don't move it ! */
        HD_LONG                 ThreadNum;
        HD_VOID *               ThreadArg;

        /**** Methods ****/

        inline HDC_Threads(HD_LONG HD_CALLBACK (*CallFunc)(HD_VOID *), HD_VOID *Arg) {
          Func        = CallFunc;
          ThreadArg   = Arg;
          ThreadCount = 0;
          ThreadNum   = HD_MthThreads();
          ThreadMutex = (ThreadNum > 1) ? HD_MthCreateMutexEx() : NULL;
        }

        inline ~HDC_Threads(HD_VOID) {
          HD_MthCloseMutexEx(ThreadMutex);
        }

        /**** Get the thread ID ****/

        inline HD_LONG GetThreadID(HD_VOID) {
          HD_LONG   ThreadID = 1;

          if (ThreadNum > 1) {
            HD_MthMutexOnEx(ThreadMutex);
            ThreadID = ++ThreadCount;
            HD_MthMutexOffEx(ThreadMutex);
          }

          return ThreadID;
        }

        /**** Run the threads ****/

        inline HD_LONG Run(HD_VOID) {
          return HD_MthCreateThreads(ThreadNum, Func, this, HD_MTH_THREADS_WAIT);
        }

        inline HD_LONG Run(HD_LONG Flags) {
          return HD_MthCreateThreads(ThreadNum, Func, this, Flags);
        }

  private:
        HD_LONG HD_CALLBACK     (*Func)(HD_VOID *);
        HD_MUTEX                ThreadMutex;
};
#  endif
#endif

