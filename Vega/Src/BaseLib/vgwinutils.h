
/*************************************************
****         VEGA - Windows utilities         ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __WINUTILS_H
#  define  __WINUTILS_H

#  include <hyperdrive.h>

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_ConClrLine                      _VG_ConClrLine
#    define  VG_ConGetY                         _VG_ConGetY
#    define  VG_ConSetPos                       _VG_ConSetPos
#    define  VG_WinPrgPath                      _VG_WinPrgPath
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_ConClrLine(HD_VOID);
VEGA_EXTERN HD_LONG         VEGA_EXPORT VG_ConGetY(HD_VOID);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_ConSetPos(HD_LONG x, HD_LONG y);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_WinPrgPath(HD_CHAR *Str);

#  ifdef __cplusplus
}
#  endif

#endif


