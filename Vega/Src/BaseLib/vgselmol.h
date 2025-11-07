
/*************************************************
****      VEGA - Molecule selector header     ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __SELMOL
#  define  __SELMOL

#  include <hdmatrix.h>

/**** See VG_MolDelete() ****/

#  define  VG_MOLDEL_MOLECULE           0
#  define  VG_MOLDEL_SEGMENT            1

/**** Definitions ****/

typedef struct __VG_MOLLIST {
  struct __VG_MOLLIST * Ptr;           /* Pointer to the next list element     */
  HD_ULONG              Num;           /* Number of the molecule               */
  HD_ULONG              TotRes;        /* Number of residues                   */
  HD_ATOM *             Begin;         /* Starting atom                        */
  HD_ATOM *             End;           /* Ending atom                          */
} VG_MOLLIST;

typedef struct __VG_RESLIST {
  struct __VG_RESLIST * Next;          /* Pointer to the next list element     */
  struct __VG_RESLIST * Prev;          /* Pointer to the previous list element */
  HD_ULONG              NMol;          /* Number of the molecule               */
  HD_ATOM *             Begin;         /* Starting atom                        */
  HD_ATOM *             End;           /* Ending atom                          */
  HD_ULONG              TotAtm;        /* Number of atoms                      */
} VG_RESLIST;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_MolListFindMol                  _VG_MolListFindMol
#    define  VG_MolListGet                      _VG_MolListGet
#    define  VG_ResListBuild                    _VG_ResListBuild

#    define  VG_MolDelete                       _VG_MolDelete
#    define  VG_MolElemCrc                      _VG_MolElemCrc
#    define  VG_MolFindByAtm                    _VG_MolFindByAtm
#    define  VG_MolListAtm2List                 _VG_MolListAtm2List
#    define  VG_MolListBuild                    _VG_MolListBuild
#    define  VG_MolListFree                     _VG_MolListFree
#    define  VG_MolListRemAtm                   _VG_MolListRemAtm
#    define  VG_MolRotate                       _VG_MolRotate
#    define  VG_MolTranslate                    _VG_MolTranslate
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_MolListFindMol(VG_CTX *Ctx, HD_ATOM * Atm);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_MolListGet(VG_CTX *Ctx, HD_ULONG MolNum, HD_ATOM **FirstAtom, HD_ATOM **LastAtom);
VEGA_EXTERN HD_LIST *       VEGA_EXPORT VG_ResListBuild(HD_ATOM *Atm);

VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_MolDelete(VG_CTX * Ctx, HD_ATOM *Atm, HD_ULONG MolID, HD_LONG What);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_MolElemCrc(HD_ATOM *Atm, HD_BOOL ActiveOnly);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_MolFindByAtm(VG_CTX *Ctx, HD_ATOM *MolAtm, HD_ATOM **LstAtm, HD_ULONG *MolLen);
VEGA_EXTERN VG_MOLLIST *    VEGA_EXPORT VG_MolListAtm2List(VG_MOLLIST *, HD_ULONG);
VEGA_EXTERN VG_MOLLIST *    VEGA_EXPORT VG_MolListBuild(HD_ATOM *, HD_LONG);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_MolListFree(VG_MOLLIST **);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_MolListRemAtm(VG_CTX *Ctx, HD_ATOM *InizAtm, HD_ULONG Start, HD_ULONG End);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_MolRotate(HD_ATOM *Atm, HD_DOUBLE Ax, HD_DOUBLE Ay, HD_DOUBLE Az, HD_XYZF *RotCenter, HD_MTX4X4F *WorldMat, HD_LONG Mode);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_MolTranslate(HD_ATOM *Atm, HD_FLOAT Dx, HD_FLOAT Dy, HD_FLOAT Dz, HD_XYZF *RotCenter, HD_MTX4X4F *WorldMat, HD_LONG Mode);

#  ifdef __cplusplus
}
#  endif
#endif

