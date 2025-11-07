
/*********************************************
****         HyperDrive library           ****
****           Private header             ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifndef __HDPRIVATE_H
#  define  __HDPRIVATE_H

#  ifdef __WIN32__
#    include <float.h>
#  endif

#  include "hdstring.h"

/**** 64 bit macros ****/

#  ifdef __GNUC__
#    if __GNUC__ < 5
#      define  HD_USE_WINCOMP
#      define  HD_USE_INLINEEXTERN
#    endif

#    define  MakeInt64(X)       X ## LL
#  else
#    ifdef __BORLANDC__
#      define  MakeInt64(X)     X ## i64
#    else
#      define  MakeInt64(X)     X
#    endif
#  endif

#  ifdef WIN32
#    ifdef __BORLANDC__
#      define  _HD_FpuPop()             _control87(FpuControl, 0xfffff)
#      define  _HD_FpuPush()            HD_ULONG FpuControl = _control87(0, 0)
#      define  _HD_FpuSinglePrec()      _control87(PC_24, MCW_PC)
#    else
#      define  _HD_FpuPop()             _controlfp(FpuControl, 0xfffff)
#      define  _HD_FpuPush()            HD_ULONG FpuControl = _controlfp(0, 0)
#      define  _HD_FpuSinglePrec()      _controlfp(_PC_24, _MCW_PC)
#    endif
#    define  HD_OSSL_DYNLOAD
#    define  HD_OSSLAPI                 _cdecl
#  else
#    define  HD_USE_DIRENT

#    define  _HD_FpuPop()
#    define  _HD_FpuPush()
#    define  _HD_FpuSinglePrec()
#  endif

#  ifdef LINUX
#    define  HD_OSSL_DYNLOAD
#    define  HD_OSSLAPI
#  endif

/**** Macros ****/

#  define  StrIsEmpty(X)                ((!(X)) || ((X) -> Len == 0))
#  define  StrIsEmptyC(X)               ((!(X)) || (!*(X)))
#  define  StrIsNum(X)                  (((X) >= '0') && ((X) <= '9'))
#  define  StrIsOct(X)                  (((X) >= '0') && ((X) <= '7'))

#ifdef HD_LITTLE_ENDIAN
#  define  HD_HI_LONG(X)                *(1 + (HD_LONG *)&X)
#  define  HD_LO_LONG(X)                *(HD_LONG *)&X
#else
#  define  HD_HI_LONG(X)                *(HD_LONG *)&X
#  define  HD_LO_LONG(X)                *(1 + (HD_LONG *)&X)
#endif

#  ifndef _MM_SHUFFLE
#    define  _MM_SHUFFLE(z, y, x, w)    ((z << 6) | (y << 4) | (x << 2) | w)
#  endif

#  define  HDT_AllocGlobVarsInt(X)      HDT_GLOBVARS HdtGlobVars; \
                                        HdtGlobVars.ThreadID = 0; \
                                        HdtGlobVars.ThreadMutex = (MthThreads > 1) ? HD_MthCreateMutexEx() : NULL

#  define  HDT_FreeGlobVarsInt(X)       if (MthThreads > 1) HD_MthCloseMutexEx(HdtGlobVars.ThreadMutex)

#  define  HDT_ObtainThIDInt(X)         if (MthThreads > 1) { \
                                          HD_MthMutexOnEx(((HDT_GLOBVARS *)HdtGlobVars) -> ThreadMutex); \
                                          X = ++((HDT_GLOBVARS *)HdtGlobVars) -> ThreadID; \
                                          HD_MthMutexOffEx(((HDT_GLOBVARS *)HdtGlobVars) -> ThreadMutex); \
                                        } else X = 1

/**** Constants ****/

#  define  HD_CIP_MAXBOND               8
#  define  HD_ONE_OVER_SQRT3            0.577350269f
#  define  HD_SQRT_TWO_THIRDS           0.816496581f
#  define  HD_SQRT_INT64_MAX            MakeInt64(3037000499)   /* sqrt(2^63) */
#  define  HD_SQRT_INT32_MAX            46340                   /* sqrt(2^31) */

/**** Argument parser ****/

typedef struct {
  HD_CHAR **    Args;                   /* Argument pointers                  */
  HD_CHAR *     Buf;                    /* Buffer                             */
  HD_LONG       ArgsSize;               /* Argument size                      */
  HD_LONG       BufSize;                /* Buffer size                        */
  HD_LONG       TotArgs;                /* Number of arguments                */
  HD_LONG       Flags;                  /* Flags                              */
} HD_ARGS_PRIVATE;

/**** CIP rule ****/

typedef struct {
  HD_ATOM *     Atm;                            /* Atom pointer        */
  HD_ULONG      Index;                          /* Atom index          */
  HD_ULONG      IndexNbr[HD_CIP_MAXBOND];       /* Neighbor atom index */
} HD_CIP_PAIR;

typedef struct {
  HD_ATOM *     Atm;                            /* Atom pointer        */
  HD_ULONG      Index;                          /* Atom index          */
} HD_CIP_PAIR_S;

/**** Global variables ****/

#  ifdef  HDRIVE_GLOBVAR

const HD_CHAR *                 HdFieldSep         = " \t\n\r";
HD_ARGS_PRIVATE *               ArgsCache          = HD_NULL;
HD_LIST *                       AtdlCache          = HD_NULL;
HD_LIST *                       GastCache          = HD_NULL;
HD_LIST *                       StreamCache        = HD_NULL;
HD_ULONG                        GlobErrCode        = HD_ERR_NONE;
HD_ULONG                        MthCpuCores        = 1;
HD_ULONG                        MthLogicalCPUs     = 1;
HD_ULONG                        MthNumaNodes       = 1;
HD_ULONG                        MthSockets         = 1;
HD_ULONG                        MthThreads         = 1;
HD_ULONG                        MthThreadsBak      = 1;


#    ifdef WIN64
HD_LONG *                       MthActiveProcessor = HD_NULL;
HD_LONG                         MthProcessorGroups = 1;
#    endif
#  else

extern const HD_CHAR *          HdFieldSep;
extern HD_CHAR                  DecSep[];
extern HD_WCHAR                 DecSepW[];
extern HD_ARGS_PRIVATE *        ArgsCache;
extern HD_LIST *                AtdlCache;
extern HD_LIST *                GastCache;
extern HD_LIST *                StreamCache;
extern HD_ULONG                 GlobErrCode, MthCpuCores;
extern HD_ULONG                 MthLogicalCPUs, MthNumaNodes, MthSockets, MthThreads, MthThreadsBak;

#    ifdef WIN64
extern HD_LONG *                MthActiveProcessor;
extern HD_LONG                  MthProcessorGroups;
#    endif
#  endif

/**** Prototypes ****/

HD_VOID                 HD_FASTCALL  HD_ChargeRoundInt(HD_ATOM *InizAtm, HD_ULONG Digits, HD_BOOL ActiveOnly);
HD_ULONG                HD_FASTCALL  HD_CountAtmInt(HD_ATOM *Atm, HD_BOOL ActiveOnly);
HD_BOOL                              HD_GetProcAddresses(HD_VOID **hLibrary, const HD_CHAR *lpszLibrary, ... );
HD_VOID                 HD_FASTCALL  HD_AtdlCacheFree(HD_VOID);
HD_VOID                 HD_FASTCALL  HD_AtmsCalcGeoCentInt(HD_ATOM *Atm, HD_XYZF *Vect, HD_BOOL Active);
HD_LONG                 HD_FASTCALL  HD_CountBndHydrogInt(HD_ATOM *Atm);
HD_VOID                 HD_FASTCALL  HD_GastCacheFree(HD_VOID);
HD_BOOL                 HD_FASTCALL  HD_IoInit(HD_VOID);
HD_VOID                 HD_FASTCALL  HD_Upper(HD_CHAR *Str);
HD_ULONG                HD_FASTCALL  CipClassCount(HD_CIP_PAIR *Vp, HD_ULONG TotPairs);
HD_VOID                 HD_FASTCALL  CipCreateNewClassVector(HD_CIP_PAIR *Vp1, HD_CIP_PAIR *Vp2, HD_CIP_PAIR_S *Vp3, HD_ULONG *ActAtm, HD_ULONG TotPairs);
HD_BOOL                 HD_FASTCALL  Crc32File(HD_ULONG *Crc32, const HD_CHAR *FileName);
HD_BOOL                 HD_FASTCALL  Crc64File(HD_UDLONG *Crc64, const HD_CHAR *FileName);
HD_LONG                 HD_FASTCALL  GetSysPriority(HD_LONG HdPriority);
HD_CHAR *               HD_FASTCALL  MyItoa(HD_LONG Value, HD_CHAR *Str, HD_LONG Radix);
HD_BOOL                 HD_FASTCALL  ShellDeleteC(const HD_CHAR *FileName, HD_BOOL Undo, HD_BOOL NoRec);
HD_VOID                 HD_FASTCALL  SrfCopyVal(HD_SURFACE *Srf, HD_FLOAT *Val);
const HD_CHAR *         HD_FASTCALL  Strnistr(const HD_CHAR *In, const HD_CHAR *Str, size_t StrLen);
const HD_CHAR *         HD_FASTCALL  StrnistrRev(const HD_CHAR *In, size_t InLen, const HD_CHAR *Str, size_t StrLen);
const HD_CHAR *         HD_FASTCALL  Strnstr(const HD_CHAR *In, const HD_CHAR *Str, size_t StrLen);
const HD_CHAR *         HD_FASTCALL  StrnstrRev(const HD_CHAR *In, size_t InLen, const HD_CHAR *Str, size_t StrLen);
HD_STRING                            StrPrintC(HD_STRING Str, const HD_CHAR *Fmt, ...);
HD_VOID                 HD_FASTCALL  TcpIpFree(HD_VOID);
HD_BOOL                 HD_FASTCALL  TcpIpInit(HD_VOID);

#ifndef AMIGA
HD_BOOL                 HD_FASTCALL  StrWide2Char(HD_CHAR *Dest, const HD_WCHAR *Src, HD_LONG MaxLen);
#endif

#  ifdef LINUX
HD_STRING               HD_FASTCALL  UTF16to8(HD_STRING Dest, const HD_WCHAR *Src);
#  endif

#  ifdef WIN32
HD_LONG                 HD_FASTCALL GetLogicalCPUs(HD_VOID);
#  endif

#  ifdef HDRIVE_OPENCL
HD_VOID                 HD_FASTCALL  OclFree(HD_VOID);
HD_BOOL                 HD_FASTCALL  OclInit(HD_VOID);
#  endif

#  ifdef HD_USE_SSE
HD_VOID                 HD_FASTCALL  SseCrossProd(HD_FLOAT *Res, HD_FLOAT *V0, HD_FLOAT *V1);
HD_FLOAT                HD_FASTCALL  SseDistance(HD_FLOAT *V0, HD_FLOAT *V1);
HD_FLOAT                HD_FASTCALL  SseDistanceRec(HD_FLOAT *V0, HD_FLOAT *V1);
HD_FLOAT                HD_FASTCALL  SseDistanceSq(HD_FLOAT *V0, HD_FLOAT *V1);
HD_FLOAT                HD_FASTCALL  SseVectLen(HD_FLOAT *V0);
HD_VOID                 HD_FASTCALL  SseVectNorm(HD_FLOAT *V0);
#  endif

#  ifdef HD_USE_SSL
#    ifdef __HDSOCKET_H
#      ifdef HD_OSSL_DYNLOAD

extern __owur int      (HD_OSSLAPI *HD_SSL_read)(SSL *, void *, int);
extern __owur int      (HD_OSSLAPI *HD_SSL_write)(SSL *, const void *, int);

#      else

#        define  HD_SSL_read              SSL_read
#        define  HD_SSL_write             SSL_write

#      endif

HD_VOID                 HD_FASTCALL  OpenSSLSocketFree(HD_SOCKET Skt);

#    endif

HD_BOOL                 HD_FASTCALL  OpenSSLInit(HD_VOID);
HD_VOID                 HD_FASTCALL  OpenSSLFree(HD_VOID);


#  endif

#endif


