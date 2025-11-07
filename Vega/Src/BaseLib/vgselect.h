
/*************************************************
****             VEGA - Selection             ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_SELECT_H
#  define  __VG_SELECT_H

/**** Selection type ****/

#  ifdef VEGA_ZZ
#    define  VG_DLGSELTYP_DIST          0
#    define  VG_DLGSELTYP_BOND          1
#    define  VG_DLGSELTYP_ANGLE         2
#    define  VG_DLGSELTYP_TORSION       3
#    define  VG_DLGSELTYP_PLANG         4
#    define  VG_DLGSELTYP_MULTI         5
#  endif

/**** Selection types ****/

typedef struct {
  HD_CHAR *     DefName;        /* Default selection name         */
  HD_CHAR *     TagName;        /* Tag name                       */
  HD_CHAR       CharId;         /* Character identificator        */
  HD_WORD       Id;             /* Identification code            */
  HD_WORD       Atoms;          /* Atoms needed for the selection */
  HD_ULONG      MeasMode;       /* Measure mode                   */
  HD_UWORD      Group;          /* 3D object group                */
  HD_UWORD      LblType;        /* Label type                     */
} VG_SELTYPE;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_MatchAtm                        _VG_MatchAtm
#    define  VG_MatchFormatPattern              _VG_MatchFormatPattern
#    define  VG_SelAdd                          _VG_SelAdd
#    define  VG_SelAtmAdd                       _VG_SelAtmAdd
#    define  VG_SelAtmChk                       _VG_SelAtmChk
#    define  VG_SelAtmRemAll                    _VG_SelAtmRemAll
#    define  VG_SelClearAll                     _VG_SelClearAll
#    define  VG_SelClone                        _VG_SelClone
#    define  VG_SelOpen                         _VG_SelOpen
#    define  VG_SelRemByAtm                     _VG_SelRemByAtm
#    define  VG_SelRemAll                       _VG_SelRemAll
#    define  VG_SelRetPtr                       _VG_SelRetPtr
#    define  VG_SelSave                         _VG_SelSave
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_BOOL       VEGA_EXPORT VG_MatchAtm(HD_ATOM *Atm, HD_CHAR **MyArg, HD_ULONG NumArgs, HD_CHAR *NMol);
VEGA_EXTERN HD_ULONG      VEGA_EXPORT VG_MatchFormatPattern(HD_ULONG *AtmNum, HD_CHAR **MyArg, HD_CHAR *Ptr);

/**** Selection list ****/

VEGA_EXTERN VG_ATMSEL *   VEGA_EXPORT VG_SelAdd(VG_CTX *Ctx, const HD_CHAR *Name, HD_WORD Type, HD_FLOAT Base, HD_ULONG Steps, HD_FLOAT Window);
VEGA_EXTERN HD_BOOL       VEGA_EXPORT VG_SelAtmAdd(VG_CTX *Ctx, VG_ATMSEL *Sel, HD_ATOM *PickedAtm, HD_ULONG NMol);
VEGA_EXTERN HD_BOOL       VEGA_EXPORT VG_SelAtmChk(VG_CTX *Ctx, VG_ATMLST *Sel);
VEGA_EXTERN HD_VOID       VEGA_EXPORT VG_SelAtmRemAll(VG_ATMSEL *Sel);
VEGA_EXTERN HD_VOID       VEGA_EXPORT VG_SelClearAll(HD_VOID);
VEGA_EXTERN VG_ATMSEL *   VEGA_EXPORT VG_SelClone(VG_ATMSEL **LastSelDest, VG_ATMSEL *BegSelSrc, HD_ATOM *InizAtm, HD_ULONG TotAtm);
VEGA_EXTERN HD_BOOL       VEGA_EXPORT VG_SelOpen(VG_CTX *Ctx, const HD_CHAR *FileName);
VEGA_EXTERN HD_BOOL       VEGA_EXPORT VG_SelRemByAtm(HD_ATOM *Atm);
VEGA_EXTERN HD_VOID       VEGA_EXPORT VG_SelRemAll(VG_ATMSEL **BegSelz, VG_ATMSEL **LastSelz);
VEGA_EXTERN VG_ATMSEL *   VEGA_EXPORT VG_SelRetPtr(VG_CTX *Ctx, HD_WORD Index, HD_UBYTE *Types);
VEGA_EXTERN HD_BOOL       VEGA_EXPORT VG_SelSave(const HD_CHAR *FileName);

#  ifdef __cplusplus
}
#  endif
#endif

