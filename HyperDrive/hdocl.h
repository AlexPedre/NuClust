
/*******************************************
****    HyperDrive - OpenCL routines    ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#ifndef __HDOCL_H
#  define  __HDOCL_H

#  if defined(LINUX) || defined(WIN32)
#    include <CL/cl.h>
#    include "hdstring.h"

/**** Error codes ****/

#    define  HD_ERR_OCL_COMQUEUE     1701 /* Can't initialize the command queue */
#    define  HD_ERR_OCL_CONTEXT      1702 /* Can't create the OpenCL context    */
#    define  HD_ERR_OCL_DEVDETECT    1703 /* Can't detect the devices           */
#    define  HD_ERR_OCL_DEVINFO      1704 /* Can't obtain the device info       */
#    define  HD_ERR_OCL_ENQUEUE      1705 /* Can't enqueue the kernel           */
#    define  HD_ERR_OCL_KERARG       1706 /* Can't add the argument to kernel   */
#    define  HD_ERR_OCL_KERARGSYNC   1707 /* Can't sync the argument            */
#    define  HD_ERR_OCL_KERNEL       1708 /* Can't create the kernel            */
#    define  HD_ERR_OCL_KERSETARG    1709 /* Can't set the kernel argument      */
#    define  HD_ERR_OCL_PLATFORMS    1710 /* Palatforms error                   */
#    define  HD_ERR_OCL_PRGBUILD     1711 /* Can't build the program            */
#    define  HD_ERR_OCL_PRGLOAD      1712 /* Can't load the program             */
#    define  HD_ERR_OCL_PRGSAVE      1713 /* Can't save the program             */
#    define  HD_ERR_OCL_WAIT         1714 /* Can't wait the event               */

/**** HD_OclKernelArgAdd() flags ****/

#     define  HD_OCL_ARG_READ           1  /* Readable by kernel                */
#     define  HD_OCL_ARG_SYNC           2  /* Sync data                         */
#     define  HD_OCL_ARG_WRITE          4  /* Writeable by kernel               */

/**** HD_OclContextCreate() device types ****/

#     define  HD_OCL_CTX_NONE           0  /* Disable the OpenCL code           */
#     define  HD_OCL_CTX_AUTO           1  /* Automatic device detection        */
#     define  HD_OCL_CTX_DEFAULT        2  /* Default                           */
#     define  HD_OCL_CTX_ACCEL          3  /* Accelerator                       */
#     define  HD_OCL_CTX_GPU            4  /* GPU                               */
#     define  HD_OCL_CTX_CPU            5  /* CPU (it must be the last chance)  */

/**** HD_OclKernelRun() flags ****/

#    define  HD_OCL_KRUN_NONE           0 /* Nothing                            */
#    define  HD_OCL_KRUN_WAIT           1 /* Wait the end of the execution      */

/**** HD_OclProgramCreate() flags ****/

#    define  HD_OCL_PRGC_BIN            0 /* Create program from binary         */
#    define  HD_OCL_PRGC_SRC            1 /* Create program from source         */

/**** Kernel status flags ****/

#    define  HD_OCL_KSTAT_NONE          0 /* None                               */
#    define  HD_OCL_KSTAT_RUN           1 /* Run                                */

/**** Memory alligned malloc ****/

#    define  HD_OclCalloc(Size)         HD_CallocMA((Size), 16)
#    define  HD_OclMalloc(Size)         HD_MallocMA((Size), 16)
#    define  HD_OclFree(Ptr)            HD_FreeMA(Ptr)


/**** HyperDrive OpenCL context ****/

struct __hd_ocl_context {
  cl_context                    hContext;       /* OpenCL context            */
  cl_device_id *                Devices;        /* Device vector             */
  cl_command_queue              CommandQueue;   /* Command queue             */
  cl_platform_id *              Platforms;      /* Platform vector           */
  cl_uint                       PlatformsNum;   /* Number of platforms       */
  HD_STRING                     BuildLog;       /* Build log                 */
  size_t                        DevicesSize;    /* Device vector size        */
  cl_uint                       MaxDim;         /* Max work dimensions       */
  cl_uint *                     MaxLocalThread; /* Max local thread          */
  HD_LONG                       DeviceType;     /* Device type               */
  HD_LONG                       UserData;       /* User data                 */
  HD_VOID *                     UserPtr;        /* User pointer              */
};

typedef struct __hd_ocl_context *       HD_OCL_CONTEXT;

/**** HyperDrive OpenCL program ****/

struct __hd_ocl_program {
  HD_OCL_CONTEXT                Context;        /* HyperDrive OpenCL context */
  cl_program                    hProgram;       /* Program handle            */
  HD_LONG                       UserData;       /* User data                 */
  HD_VOID *                     UserPtr;        /* User pointer              */
};

typedef struct __hd_ocl_program *       HD_OCL_PROGRAM;

/**** Kernel argument ****/

struct __hd_ocl_kerarg {
  struct __hd_ocl_kerarg *      Next;           /* Pointer to next item      */
  struct __hd_ocl_kerarg *      Prev;           /* Pointer to next item      */
  cl_mem                        hMem;           /* Memory handle             */
  cl_uint                       Index;          /* Argument Index            */
  size_t                        Items;          /* Number of variable items  */
  size_t                        Size;           /* Variable size             */
  HD_LONG                       Flags;          /* Memory flags              */
  HD_LONG                       UserData;       /* User data                 */
  HD_VOID *                     MemPtr;         /* Memory pointer            */
  HD_VOID *                     UserPtr;        /* User pointer              */
};

typedef struct __hd_ocl_kerarg *        HD_OCL_KERARG;

/**** HyperDrive OpenCL kernel ****/

struct __hd_ocl_kernel {
  cl_event                      hRunEvent;      /* Run event handle          */
  cl_kernel                     hKernel;        /* Kernel handle             */
  HD_LIST *                     ArgList;        /* Argument list             */
  HD_OCL_PROGRAM                Program;        /* Program handle            */
  HD_STRING                     Name;           /* Kernel name               */
  HD_ULONG                      Status;         /* Kernel status             */
  HD_LONG                       UserData;       /* User data                 */
  HD_VOID *                     UserPtr;        /* User pointer              */
};

typedef struct __hd_ocl_kernel *        HD_OCL_KERNEL;

/**** Add leading underscores to exported functions ****/

#    ifdef HD_USE_LEADING_UNDERSCORE
#      define  HD_OclContextCreate      _HD_OclContextCreate
#      define  HD_OclContextFree        _HD_OclContextFree
#      define  HD_OclDeviceSet          _HD_OclDeviceSet
#      define  HD_OclKernelArgAdd       _HD_OclKernelArgAdd
#      define  HD_OclKernelArgSync      _HD_OclKernelArgSync
#      define  HD_OclKernelCreate       _HD_OclKernelCreate
#      define  HD_OclKernelFree         _HD_OclKernelFree
#      define  HD_OclKernelRun          _HD_OclKernelRun
#      define  HD_OclKernelWait         _HD_OclKernelWait
#      define  HD_OclProgramCreate      _HD_OclProgramCreate
#      define  HD_OclProgramFree        _HD_OclProgramFree
#      define  HD_OclProgramSave        _HD_OclProgramSave
#      define  HD_OclSetCacheDir        _HD_OclSetCacheDir
#      define  HD_OclSetCacheDirC       _HD_OclSetCacheDirC
#      define  HD_OclTest               _HD_OclTest
#    endif

/**** Prototypes ****/

#    ifdef __cplusplus
extern "C" {
#    endif

HDRIVE_EXTERN HD_OCL_CONTEXT    HDRIVE_EXPORT HD_OclContextCreate(HD_LONG DeviceType);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_OclContextFree(HD_OCL_CONTEXT Ctx);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_OclDeviceSet(HD_LONG DeviceType);
HDRIVE_EXTERN HD_OCL_KERARG     HDRIVE_EXPORT HD_OclKernelArgAdd(HD_OCL_KERNEL Kernel, HD_VOID *Ptr, size_t Items, size_t Size, HD_LONG Flags);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_OclKernelArgSync(HD_OCL_KERNEL Kernel);
HDRIVE_EXTERN HD_OCL_KERNEL     HDRIVE_EXPORT HD_OclKernelCreate(HD_OCL_PROGRAM Program, const HD_CHAR *KernelName);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_OclKernelFree(HD_OCL_KERNEL Kernel);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_OclKernelRun(HD_OCL_KERNEL Kernel, size_t GlobalThreads, HD_LONG Flags);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_OclKernelWait(HD_OCL_KERNEL Kernel);
HDRIVE_EXTERN HD_OCL_PROGRAM    HDRIVE_EXPORT HD_OclProgramCreate(HD_OCL_CONTEXT Ctx, const HD_CHAR *Code, HD_ULONG Len, const HD_CHAR *BuildOptions, HD_LONG Flags);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_OclProgramFree(HD_OCL_PROGRAM Prg);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_OclProgramSave(const HD_CHAR *FileName, HD_OCL_PROGRAM Prg);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_OclSetCacheDir(HD_STRING CacheDir);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_OclSetCacheDirC(const HD_CHAR *CacheDir);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_OclTest(HD_STRING *DeviceName);

#    ifdef __cplusplus
     }
#    endif
#  endif
#endif

