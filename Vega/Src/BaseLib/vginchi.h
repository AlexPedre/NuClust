
/*************************************************
****       VEGA - InChI loader & saver        ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_INCHI_H
#  define  __VG_INCHI_H

/**** Flags ****/

#  define  VG_INCHIFLG_NONE             0
#  define  VG_INCHIFLG_AUX              1
#  define  VG_INCHIFLG_ERROR            2
#  define  VG_INCHIFLG_WARN             4

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_InchiGetMol                     _VG_InchiGetMol
#    define  VG_InchiGetStr                     _VG_InchiGetStr
#    define  VG_InchiKeyGetFromInchi            _VG_InchiKeyGetFromInchi
#    define  VG_InchiKeyGetStr                  _VG_InchiKeyGetStr
#    define  VG_InchiKeySave                    _VG_InchiKeySave
#    define  VG_InchiLoad                       _VG_InchiLoad
#    define  VG_InchiSave                       _VG_InchiSave
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_InchiGetMol(VG_CTX *Ctx, const HD_CHAR *InchiStr, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_LONG *FrmID);
VEGA_EXTERN HD_CHAR *       VEGA_EXPORT VG_InchiGetStr(VG_CTX *Ctx, HD_LONG Flags);
VEGA_EXTERN HD_CHAR *       VEGA_EXPORT VG_InchiKeyGetFromInchi(HD_CHAR *InchiStr);
VEGA_EXTERN HD_CHAR *       VEGA_EXPORT VG_InchiKeyGetStr(VG_CTX *Ctx, HD_LONG Flags);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_InchiKeySave(VG_CTX *Ctx, FILE *FH, HD_LONG Flags);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_InchiLoad(VG_CTX *Ctx, FILE *FH, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_LONG *FrmID);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_InchiSave(VG_CTX *Ctx, FILE *FH, HD_LONG Flags);

#  ifdef __cplusplus
}
#  endif
#endif
