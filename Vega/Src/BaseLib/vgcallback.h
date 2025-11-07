
/*************************************************
****          VEGA - Callback header          ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __CALLBACK_H
#  define  __CALLBACK_H

#  ifndef __HDRIVE_H
#    include <hyperdrive.h>
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

HD_VOID HD_CALLBACK  VG_PrintAtmErrRadHook(HD_ATOM *);

#  ifdef __cplusplus
}
#  endif
#endif
