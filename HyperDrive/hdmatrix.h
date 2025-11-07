
/*******************************************
****    HyperDrive - Matrix routines    ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#ifndef __HDMATRIX_H
#  define  __HDMATRIX_H

#  ifndef __HDRIVE_H
#    include "hyperdrive.h"
#  endif

/**** HD_Mtx_Join() flags ****/

#  define  HD_MTX_JOIN_BOTTOM           0
#  define  HD_MTX_JOIN_LEFT             1
#  define  HD_MTX_JOIN_RIGHT            2
#  define  HD_MTX_JOIN_TOP              3

/**** Interpolation modes ****/

#  define  HD_VECT_INTER_COSINE         0
#  define  HD_VECT_INTER_CUBIC          1
#  define  HD_VECT_INTER_LINEAR         2

/**** Macros ****/

#  define  HD_Mtx_DataElem(M)           ((M) -> Col * (M) -> Row)
#  define  HD_Mtx_DataLen(M)            ((M) -> Col * (M) -> Row * sizeof(HD_DOUBLE))
#  define  HD_Mtx_Val(M, R, C)          ((M) -> Data[(C) + (M) -> Col * (R)])
#  define  HD_Mtx_Ptr(M, R, C)          ((M) -> Data + (C) + (M) -> Col * (R))

#  define  HD_Mtxf_DataElem(M)          ((M) -> Col * (M) -> Row)
#  define  HD_Mtxf_DataLen(M)           ((M) -> Col * (M) -> Row * sizeof(HD_FLOAT))
#  define  HD_Mtxf_Val(M, R, C)         ((M) -> Data[(C) + (M) -> Col * (R)])
#  define  HD_Mtxf_Ptr(M, R, C)         ((M) -> Data + (C) + (M) -> Col * (R))

#  define  HD_Mtxs_DataElem(M)          ((M) -> Col * (M) -> Row)
#  define  HD_Mtxs_DataLen(M)           ((M) -> Col * (M) -> Row * (M) -> Size)
#  define  HD_Mtxs_Val(M, R, C)         ((M) -> Data[(C) * (M) -> Size + (M) -> Col * (R)] * (M) -> Size)

/**** Error codes ****/

#  define  HD_ERR_MTX_NOTCOMP        1501 /* Matix not compatible               */

/**** 2x2 matrix (double precision) ****/

typedef union __hd_mtx2x2 {
  HD_DOUBLE     Ele[2][2];
  HD_DOUBLE     Raw[4];
} HD_MTX2X2;

/**** 2x2 matrix (single precision) ****/

typedef union __hd_mtx2x2f {
  HD_FLOAT      Ele[2][2];
  HD_FLOAT      Raw[4];
} HD_MTX2X2F;

/**** 3x3 matrix (double precision) ****/

typedef union __hd_mtx3x3 {
  HD_DOUBLE     Ele[3][3];
  HD_DOUBLE     Raw[9];
} HD_MTX3X3;

/**** 3x3 matrix (single precision) ****/

typedef union __hd_mtx3x3f {
  HD_FLOAT      Ele[3][3];
  HD_FLOAT      Raw[9];
} HD_MTX3X3F;

/**** 4x4 matrix (double precision) ****/

typedef union __hd_mtx4x4 {
  HD_DOUBLE     Ele[4][4];
  HD_DOUBLE     Raw[16];
} HD_MTX4X4;

/**** 4x4 matrix (single precision) ****/

typedef union __hd_mtx4x4f {
  HD_FLOAT      Ele[4][4];
  HD_FLOAT      Raw[16];
} HD_MTX4X4F;

/**** Generic matrix (HD_DOUBLE precision) ****/

struct __hd_mtx {
  HD_ULONG      Col, Row;
  HD_DOUBLE *   Data;
};

typedef struct __hd_mtx *       HD_MTX;

/**** Generic matrix (single precision) ****/

struct __hd_mtxf {
  HD_ULONG      Col, Row;
  HD_FLOAT *    Data;
};

typedef struct __hd_mtxf *      HD_MTXF;

/**** Generic matrix (integer) ****/

struct __hd_mtxi {
  HD_ULONG      Col, Row;
  HD_LONG *     Data;
};

typedef struct __hd_mtxi *      HD_MTXI;

/**** Generic matrix (unsigned integer) ****/

struct __hd_mtxui {
  HD_ULONG      Col, Row;
  HD_ULONG *    Data;
};

typedef struct __hd_mtxui *     HD_MTXUI;

/**** Generic matrix (structure) ****/

struct __hd_mtxs {
  HD_ULONG      Col, Row;
  HD_ULONG      Size;
  HD_BYTE *     Data;
};

typedef struct __hd_mtxs *      HD_MTXS;

/**** Vector interpolation context ****/

typedef HD_VOID *               HD_VECTINTER;

/**** Vector 2 (HD_DOUBLE precision) ****/

typedef union __hd_vector2 {
  struct {
    HD_DOUBLE   x, y;
  } Coord;
  HD_DOUBLE     Array[2];
} HD_VECTOR2;

/**** Vector 2 (single precision) ****/

typedef union __hd_vector2f {
  struct {
    HD_FLOAT    x, y;
  } Coord;
  HD_FLOAT      Array[2];
} HD_VECTOR2F;

/**** Vector 3 (HD_DOUBLE precision) ****/

typedef union __hd_vector3 {
  struct {
    HD_DOUBLE   x, y, z;
  } Coord;
  HD_DOUBLE     Array[3];
} HD_VECTOR3;

/**** Vector 3 (single precision) ****/

typedef union __hd_vector3f {
  struct {
    HD_FLOAT    x, y, z;
    HD_FLOAT    Dummy;                                  /* To be SSE safe */
  } Coord;
  HD_FLOAT      Array[4];
} HD_VECTOR3F;

/**** Vector 4 (HD_DOUBLE precision) ****/

typedef union __hd_vector4 {
  struct {
    HD_DOUBLE   x, y, z, w;
  } Coord;
  HD_DOUBLE     Array[4];
} HD_VECTOR4;

/**** Vector 4 (single precision) ****/

typedef union __hd_vector4f {
  struct {
    HD_FLOAT    x, y, z, w;
  } Coord;
  HD_FLOAT      Array[4];
} HD_VECTOR4F;

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_Mtx_Clear               _HD_Mtx_Clear
#    define  HD_Mtx_Cofactor            _HD_Mtx_Cofactor
#    define  HD_Mtx_Copy                _HD_Mtx_Copy
#    define  HD_Mtx_Determinant         _HD_Mtx_Determinant
#    define  HD_Mtx_Dump                _HD_Mtx_Dump
#    define  HD_Mtx_Free                _HD_Mtx_Free
#    define  HD_Mtx_Identity            _HD_Mtx_Identity
#    define  HD_Mtx_InsertCol           _HD_Mtx_InsertCol
#    define  HD_Mtx_InsertRow           _HD_Mtx_InsertRow
#    define  HD_Mtx_Inverse             _HD_Mtx_Inverse
#    define  HD_Mtx_Join                _HD_Mtx_Join
#    define  HD_Mtx_Mult                _HD_Mtx_Mult
#    define  HD_Mtx_New                 _HD_Mtx_New
#    define  HD_Mtx_Ols                 _HD_Mtx_Ols
#    define  HD_Mtx_ScalarDiv           _HD_Mtx_ScalarDiv
#    define  HD_Mtx_ScalarMult          _HD_Mtx_ScalarMult
#    define  HD_Mtx_ScalarSub           _HD_Mtx_ScalarSub
#    define  HD_Mtx_ScalarSum           _HD_Mtx_ScalarSum
#    define  HD_Mtx_SymmetricInverse    _HD_Mtx_SymmetricInverse
#    define  HD_Mtx_Transpose           _HD_Mtx_Transpose

#    define  HD_Mtxf_Clear              _HD_Mtxf_Clear
#    define  HD_Mtxf_Cofactor           _HD_Mtxf_Cofactor
#    define  HD_Mtxf_Copy               _HD_Mtxf_Copy
#    define  HD_Mtxf_Determinant        _HD_Mtxf_Determinant
#    define  HD_Mtxf_Dump               _HD_Mtxf_Dump
#    define  HD_Mtxf_Free               _HD_Mtxf_Free
#    define  HD_Mtxf_Identity           _HD_Mtxf_Identity
#    define  HD_Mtxf_InsertCol          _HD_Mtxf_InsertCol
#    define  HD_Mtxf_InsertRow          _HD_Mtxf_InsertRow
#    define  HD_Mtxf_Inverse            _HD_Mtxf_Inverse
#    define  HD_Mtxf_Join               _HD_Mtxf_Join
#    define  HD_Mtxf_Mult               _HD_Mtxf_Mult
#    define  HD_Mtxf_New                _HD_Mtxf_New
#    define  HD_Mtxf_Ols                _HD_Mtxf_Ols
#    define  HD_Mtxf_ScalarDiv          _HD_Mtxf_ScalarDiv
#    define  HD_Mtxf_ScalarMult         _HD_Mtxf_ScalarMult
#    define  HD_Mtxf_ScalarSub          _HD_Mtxf_ScalarSub
#    define  HD_Mtxf_ScalarSum          _HD_Mtxf_ScalarSum
#    define  HD_Mtxf_SymmetricInverse   _HD_Mtxf_SymmetricInverse
#    define  HD_Mtxf_Transpose          _HD_Mtxf_Transpose

#    define  HD_Mtxi_Free               _HD_Mtxi_Free
#    define  HD_Mtxi_New                _HD_Mtxi_New

#    define  HD_Mtxs_Free               _HD_Mtxs_Free
#    define  HD_Mtxs_New                _HD_Mtxs_New

#    define  HD_Mtxui_Free              _HD_Mtxui_Free
#    define  HD_Mtxui_New               _HD_Mtxui_New

#    define  HD_Mtx2x2_Clear            _HD_Mtx2x2_Clear
#    define  HD_Mtx2x2_Copy             _HD_Mtx2x2_Copy
#    define  HD_Mtx2x2_Determinant      _HD_Mtx2x2_Determinant
#    define  HD_Mtx2x2_Inverse          _HD_Mtx2x2_Inverse

#    define  HD_Mtx2x2f_Clear           _HD_Mtx2x2f_Clear
#    define  HD_Mtx2x2f_Copy            _HD_Mtx2x2f_Copy
#    define  HD_Mtx2x2f_Determinant     _HD_Mtx2x2f_Determinant
#    define  HD_Mtx2x2f_Inverse         _HD_Mtx2x2f_Inverse

#    define  HD_Mtx3x3_BuildVect        _HD_Mtx3x3_BuildVect
#    define  HD_Mtx3x3_Clear            _HD_Mtx3x3_Clear
#    define  HD_Mtx3x3_Copy             _HD_Mtx3x3_Copy
#    define  HD_Mtx3x3_Determinant      _HD_Mtx3x3_Determinant
#    define  HD_Mtx3x3_Inverse          _HD_Mtx3x3_Inverse

#    define  HD_Mtx3x3f_BuildVect       _HD_Mtx3x3f_BuildVect
#    define  HD_Mtx3x3f_Clear           _HD_Mtx3x3f_Clear
#    define  HD_Mtx3x3f_Copy            _HD_Mtx3x3f_Copy
#    define  HD_Mtx3x3f_Determinant     _HD_Mtx3x3f_Determinant
#    define  HD_Mtx3x3f_Inverse         _HD_Mtx3x3f_Inverse

#    define  HD_Mtx4x4_Clear            _HD_Mtx4x4_Clear
#    define  HD_Mtx4x4_Copy             _HD_Mtx4x4_Copy
#    define  HD_Mtx4x4_Identity         _HD_Mtx4x4_Identity
#    define  HD_Mtx4x4_Inverse          _HD_Mtx4x4_Inverse
#    define  HD_Mtx4x4_Mult             _HD_Mtx4x4_Mult

#    define  HD_Mtx4x4f_Clear           _HD_Mtx4x4f_Clear
#    define  HD_Mtx4x4f_Copy            _HD_Mtx4x4f_Copy
#    define  HD_Mtx4x4f_Identity        _HD_Mtx4x4f_Identity
#    define  HD_Mtx4x4f_Inverse         _HD_Mtx4x4f_Inverse
#    define  HD_Mtx4x4f_Mult            _HD_Mtx4x4f_Mult

#    define HD_Vect2_InterFree          _HD_Vect2_InterFree
#    define HD_Vect2_InterGet           _HD_Vect2_InterGet
#    define HD_Vect2_InterNew           _HD_Vect2_InterNew

#    define  HD_Vect3_Angle             _HD_Vect3_Angle
#    define  HD_Vect3_CrossProd         _HD_Vect3_CrossProd
#    define  HD_Vect3_Diff              _HD_Vect3_Diff
#    define  HD_Vect3_Dist              _HD_Vect3_Dist
#    define  HD_Vect3_DotProd           _HD_Vect3_DotProd
#    define  HD_Vect3_Magnitude         _HD_Vect3_Magnitude
#    define  HD_Vect3_Mult              _HD_Vect3_Mult
#    define  HD_Vect3_Norm              _HD_Vect3_Norm
#    define  HD_Vect3_RotX              _HD_Vect3_RotX
#    define  HD_Vect3_RotY              _HD_Vect3_RotY
#    define  HD_Vect3_RotZ              _HD_Vect3_RotZ
#    define  HD_Vect3_SetAtm            _HD_Vect3_SetAtm
#    define  HD_Vect3_SqDist            _HD_Vect3_SqDist
#    define  HD_Vect3_Sum               _HD_Vect3_Sum
#    define  HD_Vect3_Volume            _HD_Vect3_Volume

#    define HD_Vect2f_InterFree         _HD_Vect2f_InterFree
#    define HD_Vect2f_InterGet          _HD_Vect2f_InterGet
#    define HD_Vect2f_InterNew          _HD_Vect2f_InterNew

#    define  HD_Vect3f_Angle            _HD_Vect3f_Angle
#    define  HD_Vect3f_CrossProd        _HD_Vect3f_CrossProd
#    define  HD_Vect3f_Diff             _HD_Vect3f_Diff
#    define  HD_Vect3f_Dist             _HD_Vect3f_Dist
#    define  HD_Vect3f_DotProd          _HD_Vect3f_DotProd
#    define  HD_Vect3f_Magnitude        _HD_Vect3f_Magnitude
#    define  HD_Vect3f_Mult             _HD_Vect3f_Mult
#    define  HD_Vect3f_Norm             _HD_Vect3f_Norm
#    define  HD_Vect3f_RotX             _HD_Vect3f_RotX
#    define  HD_Vect3f_RotY             _HD_Vect3f_RotY
#    define  HD_Vect3f_RotZ             _HD_Vect3f_RotZ
#    define  HD_Vect3f_SetAtm           _HD_Vect3f_SetAtm
#    define  HD_Vect3f_SqDist           _HD_Vect3f_SqDist
#    define  HD_Vect3f_Sum              _HD_Vect3f_Sum
#    define  HD_Vect3f_Volume           _HD_Vect3f_Volume

#    define  HD_Vect4_MultMtx4x4        _HD_Vect4_MultMtx4x4

#    define  HD_Vect4f_MultMtx4x4f      _HD_Vect4f_MultMtx4x4f
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx_Clear(HD_MTX Mtx);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtx_Cofactor(HD_MTX Dest, HD_MTX Src);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtx_Copy(HD_MTX Dest, HD_MTX Src);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_Mtx_Determinant(HD_MTX Mtx);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx_Dump(const char *Fmt, HD_MTX Mtx);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx_Free(HD_MTX Mtx);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx_Identity(HD_MTX Mtx);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtx_InsertCol(HD_MTX Mtx, HD_ULONG ColPos, HD_ULONG ColNum);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtx_InsertRow(HD_MTX Mtx, HD_ULONG RowPos, HD_ULONG RowNum);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtx_Inverse(HD_MTX Inv, HD_MTX Src);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtx_Join(HD_MTX Dest, HD_MTX Src, HD_LONG Position);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx_Mult(HD_MTX Res, HD_MTX Mtx1, HD_MTX Mtx2);
HDRIVE_EXTERN HD_MTX            HDRIVE_EXPORT HD_Mtx_New(HD_ULONG Col, HD_ULONG Row);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtx_Ols(HD_DOUBLE *M, HD_DOUBLE *B, HD_DOUBLE *R, HD_MTX X, HD_MTX Y);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx_ScalarDiv(HD_MTX Mtx, HD_DOUBLE Val);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx_ScalarMult(HD_MTX Mtx, HD_DOUBLE Val);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx_ScalarSub(HD_MTX Mtx, HD_DOUBLE Val);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx_ScalarSum(HD_MTX Mtx, HD_DOUBLE Val);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtx_SymmetricInverse(HD_MTX Inv, HD_MTX Src);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx_Transpose(HD_MTX Mtx);

HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtxf_Clear(HD_MTXF Mtx);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtxf_Cofactor(HD_MTXF Dest, HD_MTXF Src);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtxf_Copy(HD_MTXF Dest, HD_MTXF Src);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_Mtxf_Determinant(HD_MTXF Mtx);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtxf_Dump(const char *Fmt, HD_MTXF Mtx);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtxf_Free(HD_MTXF Mtx);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtxf_Identity(HD_MTXF Mtx);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtxf_InsertCol(HD_MTXF Mtx, HD_ULONG ColPos, HD_ULONG ColNum);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtxf_InsertRow(HD_MTXF Mtx, HD_ULONG RowPos, HD_ULONG RowNum);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtxf_Inverse(HD_MTXF Inv, HD_MTXF Src);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtxf_Join(HD_MTXF Dest, HD_MTXF Src, HD_LONG Position);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtxf_Mult(HD_MTXF Res, HD_MTXF Mtx1, HD_MTXF Mtx2);
HDRIVE_EXTERN HD_MTXF           HDRIVE_EXPORT HD_Mtxf_New(HD_ULONG Col, HD_ULONG Row);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtxf_Ols(HD_FLOAT *M, HD_FLOAT *B, HD_FLOAT *R, HD_MTXF X, HD_MTXF Y);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtxf_ScalarDiv(HD_MTXF Mtx, HD_FLOAT Val);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtxf_ScalarMult(HD_MTXF Mtx, HD_FLOAT Val);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtxf_ScalarSub(HD_MTXF Mtx, HD_FLOAT Val);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtxf_ScalarSum(HD_MTXF Mtx, HD_FLOAT Val);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtxf_SymmetricInverse(HD_MTXF Inv, HD_MTXF Src);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtxf_Transpose(HD_MTXF Mtx);

HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtxi_Free(HD_MTXI Mtx);
HDRIVE_EXTERN HD_MTXI           HDRIVE_EXPORT HD_Mtxi_New(HD_ULONG Col, HD_ULONG Row);

HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtxs_Free(HD_MTXS Mtx);
HDRIVE_EXTERN HD_MTXS           HDRIVE_EXPORT HD_Mtxs_New(HD_ULONG Col, HD_ULONG Row, HD_ULONG SIze);

HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtxui_Free(HD_MTXUI Mtx);
HDRIVE_EXTERN HD_MTXUI          HDRIVE_EXPORT HD_Mtxui_New(HD_ULONG Col, HD_ULONG Row);

HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx2x2_Clear(HD_MTX2X2 *Mtx);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx2x2_Copy(HD_MTX2X2 *Dest, HD_MTX2X2 *Src);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_Mtx2x2_Determinant(HD_MTX2X2 *Mtx);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtx2x2_Inverse(HD_MTX2X2 *Inv, HD_MTX2X2 *Mtx);

HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx2x2f_Clear(HD_MTX2X2F *Mtx);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx2x2f_Copy(HD_MTX2X2F *Dest, HD_MTX2X2F *Src);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_Mtx2x2f_Determinant(HD_MTX2X2F *Mtx);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtx2x2f_Inverse(HD_MTX2X2F *Inv, HD_MTX2X2F *Mtx);

HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx3x3_BuildVect(HD_MTX3X3 *Dest, HD_VECTOR3 *Row0, HD_VECTOR3 *Row1, HD_VECTOR3 *Row2);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx3x3_Clear(HD_MTX3X3 *Mtx);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx3x3_Copy(HD_MTX3X3 *Dest, HD_MTX3X3 *Src);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_Mtx3x3_Determinant(HD_MTX3X3 *Mtx);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtx3x3_Inverse(HD_MTX3X3 *Inv, HD_MTX3X3 *Mtx);

HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx3x3f_BuildVect(HD_MTX3X3F *Dest, HD_VECTOR3F *Row0, HD_VECTOR3F *Row1, HD_VECTOR3F *Row2);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx3x3f_Clear(HD_MTX3X3F *Mtx);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx3x3f_Copy(HD_MTX3X3F *Dest, HD_MTX3X3F *Src);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_Mtx3x3f_Determinant(HD_MTX3X3F *Mtx);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtx3x3f_Inverse(HD_MTX3X3F *Inv, HD_MTX3X3F *Mtx);

HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx4x4_Clear(HD_MTX4X4 *Mtx);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx4x4_Copy(HD_MTX4X4 *Dest, HD_MTX4X4 *Src);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx4x4_Identity(HD_MTX4X4 *Mtx);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtx4x4_Inverse(HD_MTX4X4 *Inv, HD_MTX4X4 *Mtx);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx4x4_Mult(HD_MTX4X4 *Res, HD_MTX4X4 *Mtx1, HD_MTX4X4 *Mtx2);

HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx4x4f_Clear(HD_MTX4X4F *Mtx);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx4x4f_Copy(HD_MTX4X4F *Dest, HD_MTX4X4F *Src);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx4x4f_Identity(HD_MTX4X4F *Mtx);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Mtx4x4f_Inverse(HD_MTX4X4F *Inv, HD_MTX4X4F *Mtx);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Mtx4x4f_Mult(HD_MTX4X4F *Res, HD_MTX4X4F *Mtx1, HD_MTX4X4F *Mtx2);

HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect2_InterFree(HD_VECTINTER Ctx);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Vect2_InterGet(HD_VECTINTER Ctx, HD_DOUBLE *Val, HD_DOUBLE X, HD_LONG Type);
HDRIVE_EXTERN HD_VECTINTER      HDRIVE_EXPORT HD_Vect2_InterNew(HD_VECTOR2 *Vect0, HD_ULONG Num);

HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_Vect3_Angle(HD_VECTOR3 *Vect0, HD_VECTOR3 *Vect1);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect3_CrossProd(HD_VECTOR3 *Res, HD_VECTOR3 *Vect0, HD_VECTOR3 *Vect1);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect3_Diff(HD_VECTOR3 *Res, HD_VECTOR3 *Vect0, HD_VECTOR3 *Vect1);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_Vect3_Dist(HD_VECTOR3 *Vect0, HD_VECTOR3 *Vect1);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_Vect3_DotProd(HD_VECTOR3 *Vect0, HD_VECTOR3 *Vect1);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_Vect3_Magnitude(HD_VECTOR3 *Vect0);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect3_Mult(HD_VECTOR3 *Vect0, HD_DOUBLE Const);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect3_Norm(HD_VECTOR3 *Vect0);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect3_RotX(HD_VECTOR3 *Vect0, HD_DOUBLE Rot);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect3_RotY(HD_VECTOR3 *Vect0, HD_DOUBLE Rot);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect3_RotZ(HD_VECTOR3 *Vect0, HD_DOUBLE Rot);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect3_SetAtm(HD_VECTOR3 *Dest, HD_ATOM *Src);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_Vect3_SqDist(HD_VECTOR3 *Vect0, HD_VECTOR3 *Vect1);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect3_Sum(HD_VECTOR3 *Res, HD_VECTOR3 *Vect0, HD_VECTOR3 *Vect1);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_Vect3_Volume(HD_VECTOR3 *Vect0, HD_VECTOR3 *Vect1, HD_VECTOR3 *Vect2, HD_VECTOR3 *Vect3);

HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect2f_InterFree(HD_VECTINTER Ctx);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Vect2f_InterGet(HD_VECTINTER Ctx, HD_FLOAT *Val, HD_FLOAT X, HD_LONG Type);
HDRIVE_EXTERN HD_VECTINTER      HDRIVE_EXPORT HD_Vect2f_InterNew(HD_VECTOR2F *Vect0, HD_ULONG Num);

HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_Vect3f_Angle(HD_VECTOR3F *Vect0, HD_VECTOR3F *Vect1);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect3f_CrossProd(HD_VECTOR3F *Res, HD_VECTOR3F *Vect0, HD_VECTOR3F *Vect1);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect3f_Diff(HD_VECTOR3F *Res, HD_VECTOR3F *Vect0, HD_VECTOR3F *Vect1);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_Vect3f_Dist(HD_VECTOR3F *Vect0, HD_VECTOR3F *Vect1);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_Vect3f_DotProd(HD_VECTOR3F *Vect0, HD_VECTOR3F *Vect1);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_Vect3f_Magnitude(HD_VECTOR3F *Vect0);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect3f_Mult(HD_VECTOR3F *Vect0, HD_FLOAT Const);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect3f_Norm(HD_VECTOR3F *Vect0);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect3f_RotX(HD_VECTOR3F *Vect0, HD_FLOAT Rot);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect3f_RotY(HD_VECTOR3F *Vect0, HD_FLOAT Rot);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect3f_RotZ(HD_VECTOR3F *Vect0, HD_FLOAT Rot);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect3f_SetAtm(HD_VECTOR3F *Dest, HD_ATOM *Src);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_Vect3f_SqDist(HD_VECTOR3F *Vect0, HD_VECTOR3F *Vect1);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect3f_Sum(HD_VECTOR3F *Res, HD_VECTOR3F *Vect0, HD_VECTOR3F *Vect1);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_Vect3f_Volume(HD_VECTOR3F *Vect0, HD_VECTOR3F *Vect1, HD_VECTOR3F *Vect2, HD_VECTOR3F *Vect3);

HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect4_MultMtx4x4(HD_VECTOR4 *Res, HD_VECTOR4 *Vect, HD_MTX4X4 *Mtx);

HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Vect4f_MultMtx4x4f(HD_VECTOR4F *Res, HD_VECTOR4F *Vect, HD_MTX4X4F *Mtx);

#  ifdef __cplusplus
   }
#  endif


/**** C++ wrapper ****/

#  ifdef __cplusplus

/**** Vector 3 class (HD_DOUBLE precision) ****/

class HDC_Vector3
{
  public:
        inline HD_DOUBLE        Angle(HD_VECTOR3 *V1) { return HD_Vect3_Angle(&Vect, V1); }
        inline HD_DOUBLE        Angle(HDC_Vector3 &V1) { return HD_Vect3_Angle(&Vect, &V1.Vect); }
        inline HD_VOID          CrossProd(HD_VECTOR3 *V1, HD_VECTOR3 *V2) { HD_Vect3_CrossProd(&Vect, V1, V2); }
        inline HD_VOID          CrossProd(HDC_Vector3 &V1, HDC_Vector3 &V2) { HD_Vect3_CrossProd(&Vect, &V1.Vect, &V2.Vect); }
        inline HD_VOID          Diff(HD_VECTOR3 *V1, HD_VECTOR3 *V2) { HD_Vect3_Diff(&Vect, V1, V2); }
        inline HD_VOID          Diff(HDC_Vector3 &V1, HDC_Vector3 &V2) { HD_Vect3_Diff(&Vect, &V1.Vect, &V2.Vect); }
        inline HD_DOUBLE        Dist(HD_VECTOR3 *V1) { return HD_Vect3_Dist(&Vect, V1); }
        inline HD_DOUBLE        Dist(HDC_Vector3 &V1) { return HD_Vect3_Dist(&Vect, &V1.Vect); }
        inline HD_DOUBLE        DotProd(HD_VECTOR3 *V1) { return HD_Vect3_DotProd(&Vect, V1); }
        inline HD_DOUBLE        DotProd(HDC_Vector3 &V1) { return HD_Vect3_DotProd(&Vect, &V1.Vect); }
        inline HD_DOUBLE        Magnitude(HD_VOID) { return HD_Vect3_Magnitude(&Vect); }
        inline HD_VOID          Mult(HD_DOUBLE Const) { return HD_Vect3_Mult(&Vect, Const); }
        inline HD_VOID          Norm(HD_VOID) { HD_Vect3_Norm(&Vect); }
        inline HD_VOID          RotX(HD_DOUBLE Rot) { HD_Vect3_RotX(&Vect, Rot); }
        inline HD_VOID          RotY(HD_DOUBLE Rot) { HD_Vect3_RotY(&Vect, Rot); }
        inline HD_VOID          RotZ(HD_DOUBLE Rot) { HD_Vect3_RotZ(&Vect, Rot); }
        inline HD_VOID          Set(HD_ATOM *Atm) { HD_Vect3_SetAtm(&Vect, Atm); }
        inline HD_DOUBLE        SqDist(HD_VECTOR3 *V1) { return HD_Vect3_SqDist(&Vect, V1); }
        inline HD_DOUBLE        SqDist(HDC_Vector3 &V1) { return HD_Vect3_SqDist(&Vect, &V1.Vect); }
        inline HD_VOID          Sum(HD_VECTOR3 *V1, HD_VECTOR3 *V2) { HD_Vect3_Sum(&Vect, V1, V2); }
        inline HD_VOID          Sum(HDC_Vector3 &V1, HDC_Vector3 &V2) { HD_Vect3_Sum(&Vect, &V1.Vect, &V2.Vect); }

        /**** Operators ****/

        inline HD_VOID          operator =  (HD_ATOM *Atm) { Vect.Coord.x = (HD_DOUBLE)Atm -> x;
                                                           Vect.Coord.y = (HD_DOUBLE)Atm -> y;
                                                           Vect.Coord.z = (HD_DOUBLE)Atm -> z; }
        inline HD_VOID          operator =  (HD_VECTOR3 *V1) { Vect.Coord.x = V1 -> Coord.x;
                                                               Vect.Coord.y = V1 -> Coord.y;
                                                               Vect.Coord.z = V1 -> Coord.z; }
        inline HD_VOID          operator =  (HDC_Vector3 &V1) { Vect.Coord.x = V1.Vect.Coord.x;
                                                                Vect.Coord.y = V1.Vect.Coord.y;
                                                                Vect.Coord.z = V1.Vect.Coord.z; }
        inline HD_VOID          operator =  (HD_VECTOR3F *V1) { Vect.Coord.x = (HD_DOUBLE)V1 -> Coord.x;
                                                                Vect.Coord.y = (HD_DOUBLE)V1 -> Coord.y;
                                                                Vect.Coord.z = (HD_DOUBLE)V1 -> Coord.z; }
               HDC_Vector3      operator +  (const HD_VECTOR3 *V1) { HDC_Vector3 NewVect;
                                                                     NewVect.Vect.Coord.x = Vect.Coord.x + V1 -> Coord.x;
                                                                     NewVect.Vect.Coord.y = Vect.Coord.y + V1 -> Coord.y;
                                                                     NewVect.Vect.Coord.z = Vect.Coord.z + V1 -> Coord.z;
                                                                     return NewVect; }
               HDC_Vector3      operator +  (const HDC_Vector3 &V1) { HDC_Vector3 NewVect;
                                                                      NewVect.Vect.Coord.x = Vect.Coord.x + V1.Vect.Coord.x;
                                                                      NewVect.Vect.Coord.y = Vect.Coord.y + V1.Vect.Coord.y;
                                                                      NewVect.Vect.Coord.z = Vect.Coord.z + V1.Vect.Coord.z;
                                                                      return NewVect; }
               HDC_Vector3      operator -  (const HD_VECTOR3 *V1) { HDC_Vector3 NewVect;
                                                                     NewVect.Vect.Coord.x = Vect.Coord.x - V1 -> Coord.x;
                                                                     NewVect.Vect.Coord.y = Vect.Coord.y - V1 -> Coord.y;
                                                                     NewVect.Vect.Coord.z = Vect.Coord.z - V1 -> Coord.z;
                                                                     return NewVect; }
               HDC_Vector3      operator -  (const HDC_Vector3 &V1) { HDC_Vector3 NewVect;
                                                                      NewVect.Vect.Coord.x = Vect.Coord.x - V1.Vect.Coord.x;
                                                                      NewVect.Vect.Coord.y = Vect.Coord.y - V1.Vect.Coord.y;
                                                                      NewVect.Vect.Coord.z = Vect.Coord.z - V1.Vect.Coord.z;
                                                                      return NewVect; }
               HDC_Vector3      operator *  (const HD_VECTOR3 *V1) { HDC_Vector3 NewVect;
                                                                     NewVect.Vect.Coord.x = Vect.Coord.x * V1 -> Coord.x;
                                                                     NewVect.Vect.Coord.y = Vect.Coord.y * V1 -> Coord.y;
                                                                     NewVect.Vect.Coord.z = Vect.Coord.z * V1 -> Coord.z;
                                                                     return NewVect; }
               HDC_Vector3      operator *  (const HDC_Vector3 &V1) { HDC_Vector3 NewVect;
                                                                      NewVect.Vect.Coord.x = Vect.Coord.x * V1.Vect.Coord.x;
                                                                      NewVect.Vect.Coord.y = Vect.Coord.y * V1.Vect.Coord.y;
                                                                      NewVect.Vect.Coord.z = Vect.Coord.z * V1.Vect.Coord.z;
                                                                      return NewVect; }
               HDC_Vector3      operator /  (const HD_VECTOR3 *V1) { HDC_Vector3 NewVect;
                                                                     NewVect.Vect.Coord.x = Vect.Coord.x / V1 -> Coord.x;
                                                                     NewVect.Vect.Coord.y = Vect.Coord.y / V1 -> Coord.y;
                                                                     NewVect.Vect.Coord.z = Vect.Coord.z / V1 -> Coord.z;
                                                                     return NewVect; }
               HDC_Vector3      operator /  (const HDC_Vector3 &V1) { HDC_Vector3 NewVect;
                                                                      NewVect.Vect.Coord.x = Vect.Coord.x / V1.Vect.Coord.x;
                                                                      NewVect.Vect.Coord.y = Vect.Coord.y / V1.Vect.Coord.y;
                                                                      NewVect.Vect.Coord.z = Vect.Coord.z / V1.Vect.Coord.z;
                                                                      return NewVect; }
        /**** Private properties ****/

  private:
        HD_VECTOR3              Vect;
};


/**** Vector 3 class (single precision) ****/

class HDC_Vector3f
{
  public:
        inline HD_FLOAT         Angle(HD_VECTOR3F *V1) { return HD_Vect3f_Angle(&Vect, V1); }
        inline HD_FLOAT         Angle(HDC_Vector3f &V1) { return HD_Vect3f_Angle(&Vect, &V1.Vect); }
        inline HD_VOID          CrossProd(HD_VECTOR3F *V1, HD_VECTOR3F *V2) { HD_Vect3f_CrossProd(&Vect, V1, V2); }
        inline HD_VOID          CrossProd(HDC_Vector3f &V1, HDC_Vector3f &V2) { HD_Vect3f_CrossProd(&Vect, &V1.Vect, &V2.Vect); }
        inline HD_VOID          Diff(HD_VECTOR3F *V1, HD_VECTOR3F *V2) { HD_Vect3f_Diff(&Vect, V1, V2); }
        inline HD_VOID          Diff(HDC_Vector3f &V1, HDC_Vector3f &V2) { HD_Vect3f_Diff(&Vect, &V1.Vect, &V2.Vect); }
        inline HD_FLOAT         Dist(HD_VECTOR3F *V1) { return HD_Vect3f_Dist(&Vect, V1); }
        inline HD_FLOAT         Dist(HDC_Vector3f &V1) { return HD_Vect3f_Dist(&Vect, &V1.Vect); }
        inline HD_FLOAT         DotProd(HD_VECTOR3F *V1) { return HD_Vect3f_DotProd(&Vect, V1); }
        inline HD_FLOAT         DotProd(HDC_Vector3f &V1) { return HD_Vect3f_DotProd(&Vect, &V1.Vect); }
        inline HD_FLOAT         Magnitude(HD_VOID) { return HD_Vect3f_Magnitude(&Vect); }
        inline HD_VOID          Mult(HD_FLOAT Const) { return HD_Vect3f_Mult(&Vect, Const); }
        inline HD_VOID          Norm(HD_VOID) { HD_Vect3f_Norm(&Vect); }
        inline HD_VOID          RotX(HD_FLOAT Rot) { HD_Vect3f_RotX(&Vect, Rot); }
        inline HD_VOID          RotY(HD_FLOAT Rot) { HD_Vect3f_RotY(&Vect, Rot); }
        inline HD_VOID          RotZ(HD_FLOAT Rot) { HD_Vect3f_RotZ(&Vect, Rot); }
        inline HD_VOID          Set(HD_ATOM *Atm) { HD_Vect3f_SetAtm(&Vect, Atm); }
        inline HD_FLOAT         SqDist(HD_VECTOR3F *V1) { return HD_Vect3f_SqDist(&Vect, V1); }
        inline HD_FLOAT         SqDist(HDC_Vector3f &V1) { return HD_Vect3f_SqDist(&Vect, &V1.Vect); }
        inline HD_VOID          Sum(HD_VECTOR3F *V1, HD_VECTOR3F *V2) { HD_Vect3f_Sum(&Vect, V1, V2); }
        inline HD_VOID          Sum(HDC_Vector3f &V1, HDC_Vector3f &V2) { HD_Vect3f_Sum(&Vect, &V1.Vect, &V2.Vect); }

        /**** Operators ****/

        inline HD_VOID          operator =  (HD_ATOM *Atm) { Vect.Coord.x = Atm -> x;
                                                           Vect.Coord.y = Atm -> y;
                                                           Vect.Coord.z = Atm -> z; }
        inline HD_VOID          operator =  (HD_VECTOR3F *V1) { Vect.Coord.x = V1 -> Coord.x;
                                                                Vect.Coord.y = V1 -> Coord.y;
                                                                Vect.Coord.z = V1 -> Coord.z; }
        inline HD_VOID          operator =  (HDC_Vector3f &V1) { Vect.Coord.x = V1.Vect.Coord.x;
                                                                 Vect.Coord.y = V1.Vect.Coord.y;
                                                                 Vect.Coord.z = V1.Vect.Coord.z; }
        inline HD_VOID          operator =  (HD_VECTOR3 *V1) { Vect.Coord.x = (HD_FLOAT)V1 -> Coord.x;
                                                               Vect.Coord.y = (HD_FLOAT)V1 -> Coord.y;
                                                               Vect.Coord.z = (HD_FLOAT)V1 -> Coord.z; }
               HDC_Vector3f     operator +  (const HD_VECTOR3F *V1) { HDC_Vector3f NewVect;
                                                                      NewVect.Vect.Coord.x = Vect.Coord.x + V1 -> Coord.x;
                                                                      NewVect.Vect.Coord.y = Vect.Coord.y + V1 -> Coord.y;
                                                                      NewVect.Vect.Coord.z = Vect.Coord.z + V1 -> Coord.z;
                                                                      return NewVect; }
               HDC_Vector3f     operator +  (const HDC_Vector3f &V1) { HDC_Vector3f NewVect;
                                                                       NewVect.Vect.Coord.x = Vect.Coord.x + V1.Vect.Coord.x;
                                                                       NewVect.Vect.Coord.y = Vect.Coord.y + V1.Vect.Coord.y;
                                                                       NewVect.Vect.Coord.z = Vect.Coord.z + V1.Vect.Coord.z;
                                                                       return NewVect; }
               HDC_Vector3f     operator -  (const HD_VECTOR3F *V1) { HDC_Vector3f NewVect;
                                                                      NewVect.Vect.Coord.x = Vect.Coord.x - V1 -> Coord.x;
                                                                      NewVect.Vect.Coord.y = Vect.Coord.y - V1 -> Coord.y;
                                                                      NewVect.Vect.Coord.z = Vect.Coord.z - V1 -> Coord.z;
                                                                      return NewVect; }
               HDC_Vector3f     operator -  (const HDC_Vector3f &V1) { HDC_Vector3f NewVect;
                                                                       NewVect.Vect.Coord.x = Vect.Coord.x - V1.Vect.Coord.x;
                                                                       NewVect.Vect.Coord.y = Vect.Coord.y - V1.Vect.Coord.y;
                                                                       NewVect.Vect.Coord.z = Vect.Coord.z - V1.Vect.Coord.z;
                                                                       return NewVect; }
               HDC_Vector3f     operator *  (const HD_VECTOR3F *V1) { HDC_Vector3f NewVect;
                                                                      NewVect.Vect.Coord.x = Vect.Coord.x * V1 -> Coord.x;
                                                                      NewVect.Vect.Coord.y = Vect.Coord.y * V1 -> Coord.y;
                                                                      NewVect.Vect.Coord.z = Vect.Coord.z * V1 -> Coord.z;
                                                                      return NewVect; }
               HDC_Vector3f     operator *  (const HDC_Vector3f &V1) { HDC_Vector3f NewVect;
                                                                       NewVect.Vect.Coord.x = Vect.Coord.x * V1.Vect.Coord.x;
                                                                       NewVect.Vect.Coord.y = Vect.Coord.y * V1.Vect.Coord.y;
                                                                       NewVect.Vect.Coord.z = Vect.Coord.z * V1.Vect.Coord.z;
                                                                       return NewVect; }
               HDC_Vector3f     operator /  (const HD_VECTOR3F *V1) { HDC_Vector3f NewVect;
                                                                      NewVect.Vect.Coord.x = Vect.Coord.x / V1 -> Coord.x;
                                                                      NewVect.Vect.Coord.y = Vect.Coord.y / V1 -> Coord.y;
                                                                      NewVect.Vect.Coord.z = Vect.Coord.z / V1 -> Coord.z;
                                                                      return NewVect; }
               HDC_Vector3f     operator /  (const HDC_Vector3f &V1) { HDC_Vector3f NewVect;
                                                                       NewVect.Vect.Coord.x = Vect.Coord.x / V1.Vect.Coord.x;
                                                                       NewVect.Vect.Coord.y = Vect.Coord.y / V1.Vect.Coord.y;
                                                                       NewVect.Vect.Coord.z = Vect.Coord.z / V1.Vect.Coord.z;
                                                                       return NewVect; }

        /**** Private properties ****/

  private:
        HD_VECTOR3F             Vect;
};


#  endif
#endif

