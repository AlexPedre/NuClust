
/*********************************************
**** HyperDrive - Run an external program ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifndef __HD_RUN_H
#  define  __HD_RUN_H

#  include <hdfile.h>
#  include <hdstring.h>

/**** Process priorities ****/

#  define  HD_PRI_REALTIME      0       /* +3 */
#  define  HD_PRI_HIGHEST       1       /* +2 */
#  define  HD_PRI_HIGH          2       /* +1 */
#  define  HD_PRI_NORMAL        3       /*  0 */
#  define  HD_PRI_LOW           4       /* -1 */
#  define  HD_PRI_LOWEST        5       /* -2 */

/**** Process flags ****/

#  define  HD_PROCFLG_NONE      0       /* None                                   */
#  define  HD_PROCFLG_DEBUG     1       /* Debug mode to avoid the crash          */
#  define  HD_PROCFLG_NOWIN     2       /* No window                              */
#  define  HD_PROCFLG_PIPERD    4       /* Use pipe for reading                   */
#  define  HD_PROCFLG_PIPEWRT   8       /* Use pipe for writing                   */
#  define  HD_PROCFLG_WAIT      16      /* Wait the end of the process            */
#  define  HD_PROCFLG_BINARY    32      /* Binary data for pipe                   */
#  define  HD_PROCFLG_NOERRWIN  64      /* Prevent to show the error requester    */
                                        /* when an error occurs (Windows only)    */
#  define  HD_PROCFLG_MINWIN   128      /* Minimize/iconize the window            */
#  define  HD_PROCFLG_INHAFTY  256      /* Inherit the processor group & affinity */
#  define  HD_PROCFLG_PIPE     (HD_PROCFLG_PIPERD|HD_PROCFLG_PIPEWRT)

/**** Error codes ****/

#  define  HD_ERR_PROC_ENV      1601    /* Unbalenced enviroment variables        */
#  define  HD_ERR_PROC_NOPIPE   1602    /* Pipe not enabled                       */
#  define  HD_ERR_PROC_NOTRUN   1603    /* Process not running                    */

/**** Run context ****/

struct __hd_proc {
  HD_BOOL       Running;                /* The process is running                 */
  HD_LONG       Flags;                  /* Flags                                  */
  HD_LONG       Priority;               /* Process priority                       */
  HD_LONG       TextMode;               /* Text mode                              */
  HD_LONG       UserData;               /* User data                              */
  HD_STRING     Directory;              /* Default directory                      */
  HD_STRING     FileName;               /* File name to execute with full path    */
  HD_STRING     Param;                  /* Parameters                             */
  HD_STRLIST    Env;                    /* Environment variables                  */
  HD_VOID *     UserPtr;                /* User data pointer                      */

  HD_VOID *     Extra;                  /* Extra data for internal use            */
};

typedef struct __hd_proc * HD_PROC;

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_ProcFree                _HD_ProcFree
#    define  HD_ProcNew                 _HD_ProcNew
#    define  HD_ProcPipeGetChar         _HD_ProcPipeGetChar
#    define  HD_ProcPipeGets            _HD_ProcPipeGets
#    define  HD_ProcPipeGetsC           _HD_ProcPipeGetsC
#    define  HD_ProcPipePutChar         _HD_ProcPipePutChar
#    define  HD_ProcPipePuts            _HD_ProcPipePuts
#    define  HD_ProcPipePutsC           _HD_ProcPipePutsC
#    define  HD_ProcPipeReadBin         _HD_ProcPipeReadBin
#    define  HD_ProcPipeWriteBin        _HD_ProcPipeWriteBin
#    define  HD_ProcPipeWriteC          _HD_ProcPipeWriteC
#    define  HD_ProcRun                 _HD_ProcRun
#    define  HD_ProcRunC                _HD_ProcRunC
#    define  HD_ProcRunEx               _HD_ProcRunEx
#    define  HD_ProcRunning             _HD_ProcRunning
#    define  HD_ProcSetEnv              _HD_ProcSetEnv
#    define  HD_ProcSetEnvC             _HD_ProcSetEnvC
#    define  HD_ProcSetPri              _HD_ProcSetPri
#    define  HD_ProcTerm                _HD_ProcTerm
#    define  HD_ProcWait                _HD_ProcWait
#    define  HD_ProcWaitStart           _HD_ProcWaitStart
#endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_ProcFree(HD_PROC hProc);
HDRIVE_EXTERN HD_PROC           HDRIVE_EXPORT HD_ProcNew(HD_VOID);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT HD_ProcPipeGetChar(HD_PROC hProc);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT HD_ProcPipeGets(HD_PROC hProc, HD_STRING Str);
HDRIVE_EXTERN HD_CHAR *         HDRIVE_EXPORT HD_ProcPipeGetsC(HD_PROC hProc, HD_CHAR *Str, HD_ULONG Len);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_ProcPipePutChar(HD_PROC hProc, HD_LONG Char);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_ProcPipePuts(HD_PROC hProc, HD_STRING Str);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_ProcPipePutsC(HD_PROC hProc, const HD_CHAR *Str);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_ProcPipeReadBin(HD_PROC hProc, HD_VOID *Mem, HD_ULONG MemSize, HD_ULONG *RdBytes);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_ProcPipeWriteBin(HD_PROC hProc, const HD_VOID *Mem, HD_ULONG MemSize);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_ProcPipeWriteC(HD_PROC hProc, const HD_CHAR *Str);
HDRIVE_EXTERN HD_PROC           HDRIVE_EXPORT HD_ProcRun(HD_STRING FileName, HD_STRING Param, HD_STRING Directory, HD_LONG Flags);
HDRIVE_EXTERN HD_PROC           HDRIVE_EXPORT HD_ProcRunC(const HD_CHAR *FileName, const HD_CHAR *Param, const HD_CHAR *Directory, HD_LONG Flags);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_ProcRunEx(HD_PROC hProc);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_ProcRunning(HD_PROC hProc);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_ProcSetEnv(HD_PROC hProc, HD_STRING Var, HD_STRING Value);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_ProcSetEnvC(HD_PROC hProc, const HD_CHAR *Var, const HD_CHAR *Value);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_ProcSetPri(HD_PROC hProc, HD_LONG Priority);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_ProcTerm(HD_PROC hProc);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_ProcWait(HD_PROC hProc);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_ProcWaitStart(HD_PROC hProc);

#  ifdef __cplusplus
   }
#  endif

/**** C++ wrapper ****/

#  ifdef __cplusplus

/**** Directory class ****/

class HDC_Proc
{
  public:
        /**** Consructor ****/

        inline HDC_Proc(HD_VOID)
        {
          if ((hProc = HD_ProcNew()) == HD_NULL)
            throw HD_ErrCode();
        }

        inline HD_CHAR *    GetParam(HD_VOID) { return hProc -> Param -> Cstr; }
        inline HD_LONG      PipeGetc(HD_VOID) { return HD_ProcPipeGetChar(hProc); }
        inline HD_CHAR *    PipeGets(HD_CHAR *Str, HD_ULONG Len) { return HD_ProcPipeGetsC(hProc, Str, Len); }
        inline HD_STRING    PipeGets(HD_STRING Str) { return HD_ProcPipeGets(hProc, Str); }
        inline HDC_String * PipeGets(HDC_String &Str) { HD_ProcPipeGets(hProc, Str.Hdstr()); return &Str; }
        inline HD_VOID      PipePutc(HD_LONG Char) { if (!HD_ProcPipePutChar(hProc, Char)) throw HD_ErrCode(); }
        inline HD_VOID      PipePuts(const HD_CHAR *Str) { if (!HD_ProcPipePutsC(hProc, Str)) throw HD_ErrCode(); }
        inline HD_VOID      PipePuts(HD_STRING Str) { if (!HD_ProcPipePuts(hProc, Str)) throw HD_ErrCode(); }
        inline HD_VOID      PipePuts(HDC_String Str) { if (!HD_ProcPipePuts(hProc, Str.Hdstr())) throw HD_ErrCode(); }
        inline HD_ULONG     PipeRead(HD_VOID *Mem, HD_ULONG MemSize) { HD_ULONG RdBytes = 0; HD_ProcPipeReadBin(hProc, Mem, MemSize, &RdBytes); return RdBytes; }
        inline HD_VOID      PipeWrite(HD_VOID *Mem, HD_ULONG MemSize) { if (!HD_ProcPipeWriteBin(hProc, Mem, MemSize)) throw HD_ErrCode(); }
        inline HD_VOID      SetDir(const HD_CHAR *Dir) { HD_StrCpyC(hProc -> Directory, Dir); }
        inline HD_VOID      SetDir(HD_STRING Dir    ) { HD_StrCpy(hProc -> Directory, Dir); }
        inline HD_VOID      SetDir(HDC_String Dir   ) { HD_StrCpy(hProc -> Directory, Dir.Hdstr()); }
        inline HD_VOID      SetEnv(const HD_CHAR *Var, const HD_CHAR *Value) { if (!HD_ProcSetEnvC(hProc, Var, Value)) throw HD_ErrCode(); }
        inline HD_VOID      SetEnv(HD_STRING      Var, HD_STRING      Value) { if (!HD_ProcSetEnv(hProc, Var, Value)) throw HD_ErrCode(); }
        inline HD_VOID      SetEnv(const HD_CHAR *Var, HD_STRING      Value) { if (!HD_ProcSetEnvC(hProc, Var, Value -> Cstr)) throw HD_ErrCode(); }
        inline HD_VOID      SetEnv(const HD_CHAR *Var, HDC_String     Value) { if (!HD_ProcSetEnvC(hProc, Var, Value.Cstr())) throw HD_ErrCode(); }
        inline HD_VOID      SetEnv(HDC_String     Var, HDC_String     Value) { if (!HD_ProcSetEnv(hProc, Var.Hdstr(), Value.Hdstr())) throw HD_ErrCode(); }
        inline HD_VOID      SetFile(const HD_CHAR *File) { HD_StrCpyC(hProc -> FileName, File); }
        inline HD_VOID      SetFile(HD_STRING File    ) { HD_StrCpy(hProc -> FileName, File); }
        inline HD_VOID      SetFile(HDC_String File   ) { HD_StrCpy(hProc -> FileName, File.Hdstr()); }
        inline HD_VOID      SetFlags(HD_LONG Flags) { hProc -> Flags = Flags; }
        inline HD_VOID      SetParam(const HD_CHAR *Prm) { HD_StrCpyC(hProc -> Param, Prm); }
        inline HD_VOID      SetParam(HD_STRING Prm     ) { HD_StrCpy(hProc -> Param, Prm); }
        inline HD_VOID      SetParam(HDC_String Prm    ) { HD_StrCpy(hProc -> Param, Prm.Hdstr()); }
        inline HD_VOID      SetPriority(HD_LONG Priority) { HD_ProcSetPri(hProc, Priority); }
        inline HD_VOID      SetTextMode(HD_LONG Mode) { hProc -> TextMode = Mode; }
        inline HD_BOOL      Term(HD_VOID) { return HD_ProcTerm(hProc); }
        inline HD_VOID      Run(HD_VOID) { if (!HD_ProcRunEx(hProc)) throw HD_ErrCode(); }

        inline HD_VOID Run(HD_LONG Flags)
        {
          hProc -> Flags = Flags;
          if (!HD_ProcRunEx(hProc)) throw HD_ErrCode();
        }

        inline HD_VOID      Wait(HD_VOID) { HD_ProcWait(hProc); }
        inline HD_VOID      WaitStart(HD_VOID) { HD_ProcWaitStart(hProc); }

        /**** Destructor ****/

        inline ~HDC_Proc(HD_VOID)
        {
          HD_ProcFree(hProc);
        }

        /**** Private properties ****/

        inline HD_LONG          GetFlags(HD_VOID) { return hProc -> Flags; }
        inline HD_LONG          GetTextMode(HD_VOID) { return hProc -> TextMode; }
        inline HD_BOOL          IsRunning(HD_VOID) { return HD_ProcRunning(hProc); }

  private:
        HD_PROC                 hProc;
};
#  endif
#endif

