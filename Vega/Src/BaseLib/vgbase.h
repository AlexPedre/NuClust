
/*************************************************
****          VEGA RTL - Main header           ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_VEGABASE_H
#  define  __VG_VEGABASE_H

#  ifdef __TINYC__
#    define  VG_USE_LEADING_UNDERSCORE
#    define  VEGABASE_DLL

#    pragma link "vegabase"
#  endif

#  include "vgglobdef.h"
#  include "vgglobvar.h"
#  include "vgglobstr.h"

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_CtxCreate                       _VG_CtxCreate
#    define  VG_CtxFree                         _VG_CtxFree
#    define  VG_Free                            _VG_Free
#    define  VG_FreeScript                      _VG_FreeScript
#    define  VG_Init                            _VG_Init
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN VG_CTX *        VEGA_EXPORT VG_CtxCreate(HD_VOID);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_CtxFree(VG_CTX *Ctx);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_Free(HD_VOID);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_FreeScript(HD_VOID);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_Init(const HD_CHAR *Language);

#  ifdef __cplusplus
}
#  endif
#endif

