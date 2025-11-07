
/*************************************************
****       VEGA - Bond managment header       ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_BOND_H
#  define  __VG_BOND_H


#  include <hdmatrix.h>

/**** Constants ****/

#  define  VG_BOND_FIELDLEN           256
#  define  VG_BOND_ROTPRECISION       1.0e-7f
#  define  VG_BOND_TEMPLATE           "BOND.tem"

/**** Angles ****/

#  define  VG_ANGLE_SP                  180.0f
#  define  VG_ANGLE_SP2                 120.0f
#  define  VG_ANGLE_SP3                 109.5f
#  define  VG_ANGLE_WATER               105.0f

/**** See ChkBndOrderEx() ****/

#  define  VG_BNDCHECK_NONE             0
#  define  VG_BNDCHECK_FIRST            1
#  define  VG_BNDCHECK_AMMP             2
#  define  VG_BNDCHECK_HIGHLIGHT        4

/**** See HbondCalc() ****/

#  define  VG_HBCALCFLG_NONE            0
#  define  VG_HBCALCFLG_ACTIVEONLY      1
#  define  VG_HBCALCFLG_LBLDIST         2
#  define  VG_HBCALCFLG_LBLENE          4
#  define  VG_HBCALCFLG_SHOW            8

/**** Generator item ****/

typedef struct __vg_gen_item {
  struct __vg_gen_item *    Next;           /* Pointer to next item          */
  struct __vg_gen_item *    Prev;           /* Pointer to previous item      */
  HD_ATOM *                 InizAtm;        /* First atom                    */
  HD_ULONG                  TotAtm;         /* Number of atoms               */
} VG_GEN_ITEM;

/**** Generator context ****/

struct __vg_gen_ctx {
  HD_LIST *                 MolList;        /* Stereoisomer list             */
  VG_GEN_ITEM *             CurItm;         /* Current item                  */
};

typedef struct __vg_gen_ctx * VG_GEN_CTX;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_AtmSetGeoSp                     _VG_AtmSetGeoSp
#    define  VG_AtmSetGeoSp2                    _VG_AtmSetGeoSp2
#    define  VG_AtmSetGeoSp3                    _VG_AtmSetGeoSp3

#    define  VG_BndAngle                        _VG_BndAngle
#    define  VG_BndAngleRel                     _VG_BndAngleRel
#    define  VG_BndApplyRotMat                  _VG_BndApplyRotMat
#    define  VG_BndAssignTypes                  _VG_BndAssignTypes
#    define  VG_BndChange                       _VG_BndChange
#    define  VG_BndChangeAll                    _VG_BndChangeAll
#    define  VG_BndChangeSingle                 _VG_BndChangeSingle
#    define  VG_BndCheck                        _VG_BndCheck
#    define  VG_BndDelete                       _VG_BndDelete
#    define  VG_BndDeleteAll                    _VG_BndDeleteAll
#    define  VG_BndChkOrder                     _VG_BndChkOrder
#    define  VG_BndChkLen                       _VG_BndChkLen
#    define  VG_BndCheckTypes                   _VG_BndCheckTypes
#    define  VG_BndFindConnAtms                 _VG_BndFindConnAtms
#    define  VG_BndGetRotMat                    _VG_BndGetRotMat
#    define  VG_BndGetLength                    _VG_BndGetLength
#    define  VG_BndIntersect                    _VG_BndIntersect
#    define  VG_BndInvert                       _VG_BndInvert
#    define  VG_BndIsAnti                       _VG_BndIsAnti
#    define  VG_BndLength                       _VG_BndLength
#    define  VG_BndMake                         _VG_BndMake
#    define  VG_BndMakeFirst                    _VG_BndMakeFirst
#    define  VG_BndNormal                       _VG_BndNormal
#    define  VG_BndPeptFix                      _VG_BndPeptFix
#    define  VG_BndRotate                       _VG_BndRotate
#    define  VG_BndSwap                         _VG_BndSwap
#    define  VG_BndUnlink                       _VG_BndUnlink
#    define  VG_BndUnlinkAll                    _VG_BndUnlinkAll

#    define  VG_ChiralityFix                    _VG_ChiralityFix
#    define  VG_ChiralityInvert                 _VG_ChiralityInvert
#    define  VG_ChkBndOrderEx                   _VG_ChkBndOrderEx

#    define  VG_GenFree                         _VG_GenFree
#    define  VG_GenGet                          _VG_GenGet
#    define  VG_GenGetNext                      _VG_GenGetNext
#    define  VG_GenGetPrev                      _VG_GenGetPrev
#    define  VG_GeoGenNew                       _VG_GeoGenNew
#    define  VG_GeomEzFix                       _VG_GeomEzFix
#    define  VG_HbondCalc                       _VG_HbondCalc
#    define  VG_StereoGenNew                    _VG_StereoGenNew
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_AtmSetGeoSp(HD_ATOM *, HD_ATOM *, HD_FLOAT);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_AtmSetGeoSp2(HD_ATOM *, HD_ATOM *, HD_FLOAT);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_AtmSetGeoSp3(HD_ATOM *, HD_ATOM *, HD_FLOAT);

VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_BndAngle(HD_ATOM *InizAtm, HD_ATOM *Atm1, HD_ATOM *Atm2, HD_ATOM *Atm3, HD_FLOAT NewAngle, HD_BYTE *MoveMtx);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_BndAngleRel(HD_ATOM *InizAtm, HD_ATOM *Atm1, HD_ATOM *Atm2, HD_ATOM *Atm3, HD_FLOAT Delta, HD_BYTE *MoveMtx, HD_VECTOR3F *Normal);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_BndApplyRotMat(HD_ATOM *, HD_FLOAT *, HD_ATOM *, HD_BYTE *);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_BndAssignTypes(VG_CTX *Ctx, HD_BOOL ActiveOnly, HD_BOOL Verbose);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_BndChange(HD_ATOM *, HD_ATOM *, HD_UBYTE);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_BndChangeAll(HD_ATOM *Atm, HD_UBYTE Type, HD_BOOL ActiveOnly);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_BndChangeSingle(HD_ATOM *, HD_ATOM *, HD_UBYTE);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_BndCheck(HD_ATOM *Atm1, HD_ATOM *Atm2, HD_UBYTE *Type);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_BndDelete(HD_ATOM *, HD_ATOM *);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_BndDeleteAll(HD_ATOM *Atm, HD_BOOL ActiveOnly);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_BndChkOrder(HD_ATOM *Atm);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_BndChkLen(HD_ATOM *InizAtm, HD_ULONG TotAtm);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_BndCheckTypes(HD_ATOM *Atm, HD_BOOL ActiveOnly);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_BndFindConnAtms(HD_BYTE *, HD_ATOM *, HD_ULONG *);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_BndGetRotMat(HD_FLOAT mat[9], HD_FLOAT angle, HD_FLOAT x, HD_FLOAT y, HD_FLOAT z);
VEGA_EXTERN HD_FLOAT        VEGA_EXPORT VG_BndGetLength(HD_UWORD, HD_UWORD);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_BndIntersect(HD_XYZF *p1, HD_XYZF *p2, HD_XYZF *pa, HD_XYZF *pb, HD_XYZF *pc);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_BndInvert(HD_ATOM *InizAtm, HD_ULONG TotAtm, HD_ATOM *Atm1, HD_ATOM *Atm2);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_BndIsAnti(HD_ATOM *a, HD_ATOM *b, HD_ATOM *c, HD_ATOM *d);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_BndLength(HD_ATOM *InizAtm, HD_ATOM *Atm1, HD_ATOM *Atm2, HD_FLOAT Len, HD_BYTE *ConMtx);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_BndMake(HD_ATOM *Atm1, HD_ATOM *Atm2, HD_UBYTE Type);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_BndMakeFirst(HD_ATOM *Atm1, HD_ATOM *Atm2, HD_UBYTE Type);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_BndNormal(HD_VECTOR3F *Normal, HD_ATOM *Atm1, HD_ATOM *Atm2, HD_ATOM *Atm3);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_BndPeptFix(HD_ATOM *InizAtm, HD_ULONG TotAtm);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_BndRotate(HD_ATOM *InizAtm, HD_ATOM *Atm1, HD_ATOM *Atm2, HD_FLOAT dtor, HD_BYTE *ConMtx);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_BndSwap(HD_ATOM *InizAtm, HD_ULONG TotAtm, HD_ATOM *Atm1, HD_ATOM *Atm2, HD_ATOM *Atm3);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_BndUnlink(HD_ATOM *, HD_ATOM *);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_BndUnlinkAll(HD_ATOM *);

VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_ChiralityFix(HD_ATOM *InizAtm, HD_ULONG TotAtm);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_ChiralityInvert(HD_ATOM *Atm, HD_ATOM *InizAtm, HD_ULONG TotAtm);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_ChkBndOrderEx(HD_ATOM *InizAtm, HD_LONG Flags);

VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_GenFree(VG_GEN_CTX hGeo);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_GenGet(VG_GEN_CTX hGeo, HD_ATOM **LastAtomo, HD_ULONG *TotAtomo);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_GenGetNext(VG_GEN_CTX hGeo, HD_ATOM **LastAtomo, HD_ULONG *TotAtomo);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_GenGetPrev(VG_GEN_CTX hGeo, HD_ATOM **LastAtomo, HD_ULONG *TotAtomo);
VEGA_EXTERN VG_GEN_CTX      VEGA_EXPORT VG_GeoGenNew(HD_ATOM *InizAtm, HD_ULONG TotAtm);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_GeomEzFix(HD_ATOM *InizAtm, HD_ULONG TotAtm);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_HbondCalc(VG_CTX *Ctx, const HD_CHAR *FileName, HD_LONG FileFormat, HD_FLOAT *Energy, HD_ULONG *NumAcc, HD_ULONG *NumDon, HD_ULONG *NumHB, HD_LONG HbAcc, HD_LONG HbDon, HD_LONG Flags);
VEGA_EXTERN VG_GEN_CTX      VEGA_EXPORT VG_StereoGenNew(HD_ATOM *InizAtm, HD_ULONG TotAtm);

#  ifdef __cplusplus
}
#  endif
#endif


