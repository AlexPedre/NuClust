
/*************************************************
****            VEGA - LogP header            ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __LOGP_H
#  define  __LOGP_H

/**** Constants ****/

#  define  VG_LOGP_FIELDLEN       256

/**** LogP calculation modes ****/

#  define  VG_LOGP_BROTO          0       /* Don't change the order */
#  define  VG_LOGP_CRIPPEN        1
#  define  VG_MR_CRIPPEN          2
#  define  VG_LOGP_VIRTUAL        3

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_HlbDavies                       _VG_HlbDavies
#    define  VG_HlbGriffin                      _VG_HlbGriffin
#    define  VG_HlbPSA                          _VG_HlbPSA

#    define  VG_LogPCalc                        _VG_LogPCalc
#    define  VG_LogPFreeCache                   _VG_LogPFreeCache
#    define  VG_LogPGet                         _VG_LogPGet
#    define  VG_LogPInit                        _VG_LogPInit
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_HlbDavies(VG_CTX *Ctx, HD_FLOAT *HLB, HD_BOOL ActiveOnly);
VEGA_EXTERN HD_FLOAT        VEGA_EXPORT VG_HlbGriffin(VG_CTX *Ctx, HD_BOOL ActiveOnly);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_HlbPSA(VG_CTX *Ctx, HD_FLOAT *HLB, HD_BOOL ActiveOnly);

VEGA_EXTERN HD_FLOAT        VEGA_EXPORT VG_LogPCalc(VG_CTX *Ctx, HD_FLOAT *Lipole, HD_FLOAT *Contrib, HD_ULONG Flags);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_LogPFreeCache(HD_VOID);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_LogPGet(VG_CTX *Ctx, HD_FLOAT *LogP, HD_FLOAT *Lipole, HD_LONG Mode);
VEGA_EXTERN HD_FLOAT *      VEGA_EXPORT VG_LogPInit(VG_CTX *Ctx, HD_FLOAT *Contrib, HD_ULONG Mode, HD_BOOL ActiveOnly, HD_BOOL Quiet);

#  ifdef __cplusplus
}
#  endif
#endif
