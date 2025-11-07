
/*************************************************
****      VEGA - Molecule superimposition     ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_OVERLAY_H
#  define  __VG_OVERLAY_H

/**** Types ****/

typedef struct {
  HD_ULONG      rows;
  HD_ULONG      cols;
  HD_FLOAT *    element;
} VG_MATRIX;

/**** Constants ****/

#  define  VG_OVER_BEGSELSIZE                    10
#  define  VG_OVER_TOLERANCE                     0.000000175
#  define  VG_OVER_MAXITERS                      100000
#  define  VG_OVER_MONCOL                        0x00ffffff

/**** Selection directions ****/

#  define  VG_OVER_SELDIR_NONE                  0
#  define  VG_OVER_SELDIR_ASC                   1
#  define  VG_OVER_SELDIR_DESC                  2
#  define  VG_OVER_SELDIR_BOTH                  (VG_OVER_SELDIR_ASC | VG_OVER_SELDIR_DESC)

/**** RMSD calculation modes ****/

#  define VG_RMSD_MODE_ALN                      0 /* Alignment without hydrogens */
#  define VG_RMSD_MODE_ALN_H                    1 /* Alignment with hydrogens    */
#  define VG_RMSD_MODE_HUNGARIAN                2 /* Hungarian without hydrogens */
#  define VG_RMSD_MODE_HUNGARIAN_H              3 /* Hungarian with hydrogens    */
#  define VG_RMSD_MODE_NORMAL                   4 /* Normal without hydrogens    */
#  define VG_RMSD_MODE_NORMAL_H                 5 /* Normal with hydrogens       */

/**** Macros ****/

#  define  VG_MatrixElementPtr(mat, i, j)       (((mat) -> element) + ((j) * (mat) -> rows) + (i))
#  define  VG_MatrixSetElement(mat, i, j, val)  (*(VG_MatrixElementPtr(mat, i, j)) = (val))
#  define  VG_MatrixGetElement(mat, i, j)       (*(VG_MatrixElementPtr(mat, i, j)))

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_CalcRmsd                        _VG_CalcRmsd
#    define  VG_CalcSuperposMtx                 _VG_CalcSuperposMtx
#    define  VG_CalcSuperposRms                 _VG_CalcSuperposRms
#    define  VG_MatrixAlloc                     _VG_MatrixAlloc
#    define  VG_MatrixForget                    _VG_MatrixForget
#    define  VG_MatrixMakeUnit                  _VG_MatrixMakeUnit
#    define  VG_MatrixMult                      _VG_MatrixMult
#    define  VG_SuperimposeMol                  _VG_SuperimposeMol
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_BOOL     VEGA_EXPORT VG_CalcRmsd(HD_FLOAT *Rms, HD_ATOM **AtmX, HD_ATOM **AtmY, HD_LONG Method, HD_ULONG *CipVect, HD_BOOL ActOnly);
VEGA_EXTERN HD_BOOL     VEGA_EXPORT VG_CalcSuperposMtx(HD_ULONG Natoms,  HD_ATOM **BegXMol, HD_ATOM **BegYMol,
                                                       VG_MATRIX *Spos, HD_XYZF *cgx, HD_XYZF *cgy, HD_BOOL Hydrog,
                                                       HD_BOOL ActOnly);
VEGA_EXTERN HD_FLOAT    VEGA_EXPORT VG_CalcSuperposRms(HD_ULONG Natoms,  HD_ATOM **XMol, HD_ATOM **YMol);
VEGA_EXTERN HD_BOOL     VEGA_EXPORT VG_MatrixAlloc(VG_MATRIX *m, HD_LONG rows, HD_LONG cols);
VEGA_EXTERN HD_VOID     VEGA_EXPORT VG_MatrixForget(VG_MATRIX *);
VEGA_EXTERN VG_MATRIX * VEGA_EXPORT VG_MatrixMakeUnit(VG_MATRIX *);
VEGA_EXTERN VG_MATRIX * VEGA_EXPORT VG_MatrixMult(VG_MATRIX *, VG_MATRIX *, VG_MATRIX *);
VEGA_EXTERN HD_BOOL     VEGA_EXPORT VG_SuperimposeMol(VG_CTX *Ctx, HD_ULONG Natoms, HD_ATOM **BegXMol, HD_ATOM **BegYMol, HD_ULONG MolY, VG_MATRIX *Spos);

#  ifdef __cplusplus
}
#  endif
#endif
