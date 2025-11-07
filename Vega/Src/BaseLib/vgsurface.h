
/*************************************************
****         VEGA - Molecular surface         ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __HD_SURFACE_H
#  define  __HD_SURFACE_H

#  include <hyperdrive.h>
#  include "vgwrkspace.h"

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_PopSrfAtt                       _VG_PopSrfAtt
#    define  VG_PopSrfColors                    _VG_PopSrfColors
#    define  VG_PushSurfAtt                     _VG_PushSurfAtt
#    define  VG_PushSurfColors                  _VG_PushSurfColors
#    define  VG_SrfArea                         _VG_SrfArea
#    define  VG_SrfCalc                         _VG_SrfCalc
#    define  VG_SrfClone                        _VG_SrfClone
#    define  VG_SrfCsvLoad                      _VG_SrfCsvLoad
#    define  VG_SrfCsvSave                      _VG_SrfCsvSave
#    define  VG_SrfInsightLoad                  _VG_SrfInsightLoad
#    define  VG_SrfInsightSave                  _VG_SrfInsightSave
#    define  VG_SrfLiGenBinCheck                _VG_SrfLiGenBinCheck
#    define  VG_SrfLiGenGridBinLoad             _VG_SrfLiGenGridBinLoad
#    define  VG_SrfLiGenGridLoad                _VG_SrfLiGenGridLoad
#    define  VG_SrfLiGenPharmBinLoad            _VG_SrfLiGenPharmBinLoad
#    define  VG_SrfLiGenPharmLoad               _VG_SrfLiGenPharmLoad
#    define  VG_SrfName                         _VG_SrfName
#    define  VG_SrfQuantaLoad                   _VG_SrfQuantaLoad
#    define  VG_SrfQuantaSave                   _VG_SrfQuantaSave
#    define  VG_SrfPrintProg                    _VG_SrfPrintProg
#    define  VG_SrfSave                         _VG_SrfSave
#    define  VG_SrfSortByAtm                    _VG_SrfSortByAtm
#    define  VG_SrfRawSave                      _VG_SrfRawSave
#    define  VG_SrfVrmlSave                     _VG_SrfVrmlSave
#    define  VG_Surface                         _VG_Surface

#    define  VG_SrfListActivateAll              _VG_SrfListActivateAll
#    define  VG_SrfListAdd                      _VG_SrfListAdd
#    define  VG_SrfListEnable                   _VG_SrfListEnable
#    define  VG_SrfListGetNum                   _VG_SrfListGetNum
#    define  VG_SrfListRemove                   _VG_SrfListRemove
#    define  VG_SrfListRemoveAll                _VG_SrfListRemoveAll
#    define  VG_SrfListRemoveAllForce           _VG_SrfListRemoveAllForce
#    define  VG_SrfListRemoveToEnd              _VG_SrfListRemoveToEnd
#    define  VG_SrfListSetName                  _VG_SrfListSetName
#    define  VG_SrfListClone                    _VG_SrfListClone
#    define  VG_SrfListCount                    _VG_SrfListCount
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_VOID                 VEGA_EXPORT VG_PopSrfAtt(VG_CTX *Ctx, VG_UNDO_SRFATT *SrfAttMtx);
VEGA_EXTERN HD_VOID                 VEGA_EXPORT VG_PopSrfColors(VG_CTX *Ctx, HD_UBYTE *ColMtx);
VEGA_EXTERN VG_UNDO_SRFATT *        VEGA_EXPORT VG_PushSurfAtt(VG_CTX *Ctx);
VEGA_EXTERN HD_UBYTE *              VEGA_EXPORT VG_PushSurfColors(VG_CTX *Ctx);
VEGA_EXTERN HD_FLOAT                VEGA_EXPORT VG_SrfArea(HD_FLOAT *PolArea, HD_FLOAT *Volume, HD_FLOAT *Mlp, HD_ATOM **AtmTab, HD_ULONG TotAtm,
                                                           HD_ULONG Points, HD_FLOAT ProRad, HD_FLOAT *Contrib, HD_ULONG Flags);
VEGA_EXTERN HD_SURFACE *            VEGA_EXPORT VG_SrfCalc(VG_CTX *Ctx, HD_UBYTE Type, HD_SURFACE ***BegFaces, HD_ULONG *TotFaces,
                                                           HD_SURFACE **LastDot, HD_ULONG *TotDot, HD_FLOAT **BegNorm,
                                                           HD_ULONG Points, HD_FLOAT MeshSize, HD_FLOAT ProRad, HD_UWORD Form,
                                                           HD_FLOAT *Contrib, HD_ULONG Flags);
VEGA_EXTERN HD_SURFACE *            VEGA_EXPORT VG_SrfClone(HD_SURFACE **LastDot, HD_SURFACE *Dot);
VEGA_EXTERN HD_SRFINFO *            VEGA_EXPORT VG_SrfCsvLoad(FILE *FH);
VEGA_EXTERN HD_BOOL                 VEGA_EXPORT VG_SrfCsvSave(VG_CTX *Ctx, FILE *FH, HD_SURFACE *Dot, HD_ULONG TotDot);
VEGA_EXTERN HD_SRFINFO *            VEGA_EXPORT VG_SrfInsightLoad(VG_CTX *Ctx, FILE *FH);
VEGA_EXTERN HD_BOOL                 VEGA_EXPORT VG_SrfInsightSave(VG_CTX *Ctx, FILE *FH, HD_STRING File, HD_SRFINFO *SrfInfo);
VEGA_EXTERN HD_LONG                 VEGA_EXPORT VG_SrfLiGenBinCheck(FILE *FH);
VEGA_EXTERN HD_SRFINFO *            VEGA_EXPORT VG_SrfLiGenGridBinLoad(VG_CTX *Ctx, FILE *FH);
VEGA_EXTERN HD_SRFINFO *            VEGA_EXPORT VG_SrfLiGenGridLoad(VG_CTX *Ctx, FILE *FH);
VEGA_EXTERN HD_SRFINFO *            VEGA_EXPORT VG_SrfLiGenPharmBinLoad(VG_CTX *Ctx, FILE *FH);
VEGA_EXTERN HD_SRFINFO *            VEGA_EXPORT VG_SrfLiGenPharmLoad(VG_CTX *Ctx, FILE *FH);
VEGA_EXTERN HD_VOID                 VEGA_EXPORT VG_SrfName(const HD_CHAR *Src, HD_CHAR *Dest);
VEGA_EXTERN HD_SRFINFO *            VEGA_EXPORT VG_SrfQuantaLoad(VG_CTX *Ctx, FILE *FH);
VEGA_EXTERN HD_BOOL                 VEGA_EXPORT VG_SrfQuantaSave(VG_CTX *Ctx, FILE *FH, HD_STRING File, HD_SRFINFO *SrfInfo);
VEGA_EXTERN HD_VOID                 VEGA_EXPORT VG_SrfPrintProg(HD_UWORD Form);
VEGA_EXTERN HD_BOOL                 VEGA_EXPORT VG_SrfSave(VG_CTX *Ctx, FILE *FH, HD_STRING File, HD_SRFINFO *SrfInfo, HD_LONG Format);
VEGA_EXTERN HD_SURFACE **           VEGA_EXPORT VG_SrfSortByAtm(HD_SURFACE *InizSrf, HD_ULONG TotDot);
VEGA_EXTERN HD_BOOL                 VEGA_EXPORT VG_SrfRawSave(FILE *FH, HD_SRFINFO *SrfInfo);
VEGA_EXTERN HD_BOOL                 VEGA_EXPORT VG_SrfVrmlSave(FILE *FH, HD_SURFACE *Dot, HD_BOOL Solid);
VEGA_EXTERN HD_BOOL                 VEGA_EXPORT VG_Surface(VG_CTX *Ctx, FILE *FH, HD_STRING File, HD_ULONG Points, HD_FLOAT ProRad, HD_LONG Format, HD_FLOAT *Contrib);

/**** VG_Surface list management ****/

VEGA_EXTERN HD_VOID                 VEGA_EXPORT VG_SrfListActivateAll(VG_CTX *Ctx, HD_LONG Mode);
VEGA_EXTERN HD_SRFINFO *            VEGA_EXPORT VG_SrfListAdd(VG_CTX *Ctx);
VEGA_EXTERN HD_VOID                 VEGA_EXPORT VG_SrfListEnable(VG_CTX *Ctx, HD_BOOL En);
VEGA_EXTERN HD_ULONG                VEGA_EXPORT VG_SrfListGetNum(VG_CTX *Ctx, HD_SRFINFO *Srf);
VEGA_EXTERN HD_VOID                 VEGA_EXPORT VG_SrfListRemove(VG_CTX *Ctx, HD_SRFINFO *SrfInfo, HD_ULONG Idx);
VEGA_EXTERN HD_ULONG                VEGA_EXPORT VG_SrfListRemoveAll(VG_CTX *Ctx, HD_SRFINFO **InfoCur);
VEGA_EXTERN HD_ULONG                VEGA_EXPORT VG_SrfListRemoveAllForce(HD_LIST **List, HD_SRFINFO **InfoCur);
VEGA_EXTERN HD_VOID                 VEGA_EXPORT VG_SrfListRemoveToEnd(VG_CTX *Ctx, HD_SRFINFO *SrfInfo, HD_ULONG Idx);
VEGA_EXTERN HD_VOID                 VEGA_EXPORT VG_SrfListSetName(VG_CTX *Ctx, HD_SRFINFO *Srf, const HD_CHAR *Name);
VEGA_EXTERN HD_LIST *               VEGA_EXPORT VG_SrfListClone(VG_CTX *Ctx);
VEGA_EXTERN HD_ULONG                VEGA_EXPORT VG_SrfListCount(HD_LIST *List);

#  ifdef __cplusplus
}
#  endif
#endif
