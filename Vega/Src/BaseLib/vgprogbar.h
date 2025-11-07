
/*************************************************
****        VEGA - Progress Bar header        ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_PROGBAR_H
#  define  __VG_PROGBAR_H

#  include <hdtypes.h>

#  ifdef VEGA_ZZ
#    include "events.h"
#  endif

/**** Main progress bar commands ****/

#  define  VG_PROGBAR_NONE              0
#  define  VG_PROGBAR_FINISH            1
#  define  VG_PROGBAR_POS               2
#  define  VG_PROGBAR_TEXT              3
#  define  VG_PROGBAR_TEXTID            4

/**** Main progress bar flags ****/

#  define  VG_PROGBAR_FLG_NONE          0
#  define  VG_PROGBAR_FLG_CURSOR        1
#  define  VG_PROGBAR_FLG_ENABORT       2
#  define  VG_PROGBAR_FLG_ENBAR         4
#  define  VG_PROGBAR_FLG_MENU          8
#  define  VG_PROGBAR_FLG_WKSLOCK      16

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_ProgBarFinish                   _VG_ProgBarFinish
#    define  VG_ProgBarInit                     _VG_ProgBarInit
#    define  VG_ProgBarKill                     _VG_ProgBarKill
#    define  VG_ProgBarSetArg                   _VG_ProgBarSetArg
#    define  VG_ProgBarSetPos                   _VG_ProgBarSetPos
#    define  VG_ProgBarSetText                  _VG_ProgBarSetText
#    define  VG_ProgBarSetTextID                _VG_ProgBarSetTextID
#    define  VG_ProgBarSetThread                _VG_ProgBarSetThread
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_VOID VEGA_EXPORT VG_ProgBarFinish(HD_VOID);
VEGA_EXTERN HD_VOID VEGA_EXPORT VG_ProgBarInit(HD_LONG MaxVal, HD_LONG Flags, HD_VOID (VEGA_EXPORT *CallBack)(HD_VOID *), HD_VOID *CallBackArg);
VEGA_EXTERN HD_VOID VEGA_EXPORT VG_ProgBarKill(HD_VOID);
VEGA_EXTERN HD_VOID VEGA_EXPORT VG_ProgBarSetArg(HD_VOID *CallBackArg);
VEGA_EXTERN HD_LONG VEGA_EXPORT VG_ProgBarSetPos(HD_LONG Pos);
VEGA_EXTERN HD_LONG VEGA_EXPORT VG_ProgBarSetText(const HD_CHAR *Str);
VEGA_EXTERN HD_LONG VEGA_EXPORT VG_ProgBarSetTextID(HD_LONG StrID);
VEGA_EXTERN HD_VOID VEGA_EXPORT VG_ProgBarSetThread(HD_THREAD hThread);

#  ifdef __cplusplus
}
#  endif
#endif

