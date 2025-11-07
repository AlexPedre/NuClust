
/*************************************************
****      VEGA - Smiles loader & saver        ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_SMILES_H
#  define  __VG_SMILES_H

#  include "hdstring.h"

/**** Flags ****/

#  define  VG_SMISFLG_NONE              0
#  define  VG_SMISFLG_CHKATMNUM         1
#  define  VG_SMISFLG_ERROR             2
#  define  VG_SMISFLG_LAYERED           4

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_MdlMolSaveStr                   _VG_MdlMolSaveStr
#    define  VG_SmilesGetStr                    _VG_SmilesGetStr
#    define  VG_SmilesPut                       _VG_SmilesPut
#    define  VG_SmilesSave                      _VG_SmilesSave
#    define  VG_SmilesValidate                  _VG_SmilesValidate
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_STRING       VEGA_EXPORT VG_MdlMolSaveStr(HD_ATOM *InizAtm, HD_ULONG TotAtm);
VEGA_EXTERN HD_STRING       VEGA_EXPORT VG_SmilesGetStr(HD_ATOM *InizAtm, HD_ULONG TotAtm, HD_LONG Flags);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_SmilesPut(VG_CTX *Ctx, HD_CHAR *Line, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_SmilesSave(VG_CTX *Ctx, FILE *FH, HD_LONG Flags);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_SmilesValidate(HD_CHAR *Line);

#  ifdef __cplusplus
}
#  endif
#endif
