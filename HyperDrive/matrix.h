
/*******************************************
****    HyperDrive - Matrix routines    ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#include "hdfloat.h"

/**** Local types ****/

typedef struct {
  HD_LONG               DataType;

  HD_FLOAT_INT          Max, Min;
  HD_VP(HD_VECTOR2) *   Vect;
  HD_ULONG              CurPos;
  HD_ULONG              Num;
} HD_VP(HD_INTERINT2);

typedef struct {
  HD_LONG               DataType;

  HD_VP(HD_VECTOR3) *   Vect;
  HD_ULONG              CurPos;
  HD_ULONG              Num;
} HD_VP(HD_INTERINT3);

/**** Local prototypes ****/

static HD_BOOL          HD_FASTCALL HD_MTX_FUNC(Resize)(HD_VP(HD_MTX) Mtx, HD_ULONG Col, HD_ULONG Row);
//static HD_VP(HD_MTX)    HD_FASTCALL HD_MTX_FUNC(HierClustNearest)(HD_VP(HD_MTX) InMtx, HD_ULONG *VectNum);
static HD_LONG          HD_CALLBACK HD_VECT2_FUNC(InterSort)(const HD_VOID *Vect0, const HD_VOID *Vect1);


/**** Clear a generic matrix ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_MTX_FUNC(Clear)(HD_VP(HD_MTX) Mtx)
{
  if (!Mtx) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  HD_MemZero(Mtx -> Data, Mtx -> Col * Mtx -> Row * sizeof(HD_FLOAT_INT));
  GlobErrCode = HD_ERR_NONE;
}


/**** Cofactor of a generic square matrix ****/

HDRIVE_EXTERN HD_BOOL HDRIVE_EXPORT HD_MTX_FUNC(Cofactor)(HD_VP(HD_MTX) Dest, HD_VP(HD_MTX) Src)
{
  HD_FLOAT_INT  Det, Factor;
  HD_VP(HD_MTX) Tmp;
  HD_ULONG      i, j, ii, jj, i1, j1;

  if ((!Dest) || (!Src) || (Src -> Col != Src -> Row)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return FALSE;
  }

  i =  Src -> Col - 1;
  if ((!HD_MTX_FUNC(Resize)(Dest, Src -> Col, Src -> Row)) ||
      ((Tmp = HD_MTX_FUNC(New)(i, i)) == HD_NULL))
    return FALSE;

  Factor = 1.0;
  for(j = 0; j < Src -> Row; ++j) {
    for(i = 0; i < Src -> Col; ++i) {

      /**** Create the adjoint Src_ij ****/

      i1 = 0;
      for(ii = 0; ii < Src -> Row; ++ii) {
        if (ii == i) continue;
        j1 = 0;
        for(jj = 0; jj < Src -> Col; ++jj) {
          if (jj == j) continue;
          HD_MTX_VAL(Tmp, i1, j1) = HD_MTX_VAL(Src, ii, jj);
          ++j1;
        } /* End of for (jj) */
        ++i1;
      } /* End of for (ii) */

      /**** Calculate the determinat ****/

      Det = HD_MTX_FUNC(Determinant)(Tmp);

      /**** Fill in the elements of the cofactor ****/

      HD_MTX_VAL(Dest, i, j) = Factor * Det;
      Factor = - Factor;
    } /* End of for (i) */
  } /* End of for (j) */

  HD_MTX_FUNC(Free)(Tmp);
  GlobErrCode = HD_ERR_NONE;

  return TRUE;
}


/**** Copy a generic matrix  ****/

HDRIVE_EXTERN HD_BOOL HDRIVE_EXPORT HD_MTX_FUNC(Copy)(HD_VP(HD_MTX) Dest, HD_VP(HD_MTX) Src)
{
  if ((!Dest) || (!Src)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return FALSE;
  }

  if (!HD_MTX_FUNC(Resize)(Dest, Src -> Col, Src -> Row)) return FALSE;

  HD_MemCpy(Dest -> Data, Src -> Data, HD_MTX_DATALEN(Src));
  GlobErrCode = HD_ERR_NONE;

  return TRUE;
}


/**** Determinant of a generic matrix ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_MTX_FUNC(Determinant)(HD_VP(HD_MTX) Mtx)
{
  register HD_FLOAT_INT     Det;

  if ((!Mtx) || (Mtx -> Col != Mtx -> Row) || (!Mtx -> Col)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return 0.0;
  }

  switch(Mtx -> Col) {
  case 1:       /* 1x1 */
    Det = *Mtx -> Data;
    break;

  case 2:       /* 2x2 */
    Det = _HDM_Mtx2x2_Determinant((HD_VP(HD_MTX2X2) *)Mtx -> Data);
    break;

  case 3:       /* 3x3 */
    Det = _HDM_Mtx3x3_Determinant((HD_VP(HD_MTX3X3) *)Mtx -> Data);
    break;

  default:      /* NxN - Gaussian elimination */
    {
      register HD_ULONG         i, j, j1, j2;
      register HD_FLOAT_INT     Coeff;

      register HD_FLOAT_INT     Factor = HD_FP(1.0);
      register HD_VP(HD_MTX)    Minor  = HD_MTX_FUNC(New)(Mtx -> Row - 1, Mtx -> Row - 1);

      if (!Minor) return HD_FP(0.0);

      Det = HD_FP(0.0);
      for(j1 = 0; j1 < Mtx -> Col; ++j1) {
        Coeff = HD_MTX_VAL(Mtx, 0, j1);
        if (Coeff) {
          for(i = 1; i < Mtx -> Row; ++i) {
            j2 = 0;
            for(j = 0; j < Mtx -> Col; ++j) {
              if (j == j1) continue;
              HD_MTX_VAL(Minor, i - 1, j2) = HD_MTX_VAL(Mtx, i, j);
              j2++;
            } /* End of for (j) */
          } /* End of for (i) */
          Det += Coeff * Factor * HD_MTX_FUNC(Determinant)(Minor);
        }
        Factor = - Factor;
      } /* End of for (j1) */
      HD_MTX_FUNC(Free)(Minor);
    }
    break;
  } /* End of switch */
  GlobErrCode = HD_ERR_NONE;

  return Det;
}


/**** Dump a matrix ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_MTX_FUNC(Dump)(const char *Fmt, HD_VP(HD_MTX) Mtx)
{
  register HD_FLOAT_INT *Val;
  register HD_ULONG     Col, Row;

  if (!Mtx) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  if ((!Fmt) || (!*Fmt))
#ifdef HD_SINGLE_PRECISION
    Fmt = " %f";
#else
    Fmt = " %lf";
#endif

  Val = Mtx -> Data;
  for(Row = 0; Row < Mtx -> Row; ++Row) {
    for(Col = 0; Col < Mtx -> Col; ++Col) {
      printf(Fmt, *Val++);
    } /* End of for (Col) */
    printf("\n");
  } /* End of for (Row) */

  GlobErrCode = HD_ERR_NONE;
}


/**** Free a generic matrix ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_MTX_FUNC(Free)(HD_VP(HD_MTX) Mtx)
{
  if (!Mtx) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  HD_FreeSafe(Mtx -> Data);
  HD_Free(Mtx);
  GlobErrCode = HD_ERR_NONE;
}


/**** Load the identity matrix ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_MTX_FUNC(Identity)(HD_VP(HD_MTX) Mtx)
{
  register HD_ULONG     i, j;

  if (!Mtx) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  for(i = 0; i < Mtx -> Row; ++i)
    for(j = 0; j < Mtx -> Col; ++j)
      HD_Mtx_Val(Mtx, i, j) = (i == j) ? HD_FP(1.0) : HD_FP(0.0);

  GlobErrCode = HD_ERR_NONE;
}


/**** Insert a column in a generic matrix ****/

HDRIVE_EXTERN HD_BOOL HDRIVE_EXPORT HD_MTX_FUNC(InsertCol)(HD_VP(HD_MTX) Mtx, HD_ULONG ColPos, HD_ULONG ColNum)
{
  HD_FLOAT_INT *        NewData;
  register HD_FLOAT_INT *Dest, *Src;
  register HD_ULONG     c, ColTop, r;

  if ((!Mtx) || (ColPos > Mtx -> Col) || (!ColNum)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return FALSE;
  }

  if ((NewData = (HD_FLOAT_INT *)HD_Malloc(sizeof(HD_FLOAT_INT) * (Mtx -> Col + ColNum) * Mtx -> Row)) == HD_NULL)
    return FALSE;

  Mtx -> Col += ColNum;

  /**** Copy the data ****/

  ColTop = ColPos + ColNum;
  Dest   = NewData;
  Src    = Mtx -> Data;
  for(r = 0; r < Mtx -> Row; ++r) {
    for(c = 0; c < Mtx -> Col; ++c) {
      if ((c >= ColPos) && (c <  ColTop)) *Dest = HD_FP(0.0);
      else *Dest = *Src++;
      ++Dest;
    } /* End of for (c) */
  } /* End of for (r) */

  HD_Free(Mtx -> Data);
  Mtx -> Data = NewData;
  GlobErrCode = HD_ERR_NONE;

  return TRUE;
}


/**** Insert a row in a generic matrix ****/

HDRIVE_EXTERN HD_BOOL HDRIVE_EXPORT HD_MTX_FUNC(InsertRow)(HD_VP(HD_MTX) Mtx, HD_ULONG RowPos, HD_ULONG RowNum)
{
  HD_FLOAT_INT *        NewData;
  register HD_FLOAT_INT *Dest, *Src;
  register HD_ULONG     c, r, RowTop;

  if ((!Mtx) || (RowPos > Mtx -> Row) || (!RowNum)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return FALSE;
  }

  if ((NewData = (HD_FLOAT_INT *)HD_Malloc(sizeof(HD_FLOAT_INT) * Mtx -> Col * (Mtx -> Row + RowNum))) == HD_NULL)
    return FALSE;

  Mtx -> Row += RowNum;

  /**** Copy the data ****/

  Dest   = NewData;
  RowTop = RowPos + RowNum;
  Src    = Mtx -> Data;
  for(r = 0; r < Mtx -> Row; ++r) {
    for(c = 0; c < Mtx -> Col; ++c) {
      if ((r >= RowPos)  && (r < RowTop)) *Dest = HD_FP(0.0);
      else *Dest = *Src++;
      ++Dest;
    } /* End of for (c) */
  } /* End of for (r) */

  HD_Free(Mtx -> Data);
  Mtx -> Data = NewData;
  GlobErrCode = HD_ERR_NONE;

  return TRUE;
}


/**** Inverse of a generic square matrix ****/

HDRIVE_EXTERN HD_BOOL HDRIVE_EXPORT HD_MTX_FUNC(Inverse)(HD_VP(HD_MTX) Inv, HD_VP(HD_MTX) Src)
{
  HD_FLOAT_INT      Det;

  if ((!Inv) || (!Src) || (Src -> Col != Src -> Row)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return FALSE;
  }

  switch(Src -> Col) {
  case 1:
    if ((!*Src -> Data) || (!HD_MTX_FUNC(Resize)(Inv, 1, 1))) return FALSE;
    *Inv -> Data = HD_FP(1.0) / *Src -> Data;
    GlobErrCode = HD_ERR_NONE;
    break;

  case 2:
    return HD_MTX2X2_FUNC(Inverse)((HD_VP(HD_MTX2X2) *)Inv -> Data, (HD_VP(HD_MTX2X2) *)Src -> Data);

  case 3:
    return HD_MTX3X3_FUNC(Inverse)((HD_VP(HD_MTX3X3) *)Inv -> Data, (HD_VP(HD_MTX3X3) *)Src -> Data);

  case 4:
    return HD_MTX4X4_FUNC(Inverse)((HD_VP(HD_MTX4X4) *)Inv -> Data, (HD_VP(HD_MTX4X4) *)Src -> Data);

  default :
    if ((Det = HD_MTX_FUNC(Determinant)(Src)) == HD_FP(0.0))
      return FALSE;

    if (!HD_MTX_FUNC(Cofactor)(Inv, Src)) return FALSE;
    HD_MTX_FUNC(Transpose)(Inv);
    HD_MTX_FUNC(ScalarDiv)(Inv, Det);
  } /* End of switch */

  return TRUE;
}


/**** Join two matrix ****/

HDRIVE_EXTERN HD_BOOL HDRIVE_EXPORT HD_MTX_FUNC(Join)(HD_VP(HD_MTX) Dest, HD_VP(HD_MTX) Src, HD_LONG Position)
{
  HD_FLOAT_INT *        NewData;
  register HD_FLOAT_INT *DestPtr, *NewPtr, *SrcPtr;
  HD_ULONG              Lim;
  register HD_ULONG     c, r;


  if ((!Dest) && (!Src)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return FALSE;
  }

  /**** Check the compatibility ****/

  switch(Position) {
  case HD_MTX_JOIN_BOTTOM:
  case HD_MTX_JOIN_TOP:
    if (Dest -> Col != Src -> Col) {
      GlobErrCode = HD_ERR_MTX_NOTCOMP;
      return FALSE;
    }
    break;

  case HD_MTX_JOIN_LEFT:
  case HD_MTX_JOIN_RIGHT:
    if (Dest -> Row != Src -> Row) {
      GlobErrCode = HD_ERR_MTX_NOTCOMP;
      return FALSE;
    }
    break;

  default:
    GlobErrCode = HD_ERR_ILLPAR;
    return FALSE;
  } /* End of switch */

  /**** Create the new matrix data ****/

  if ((NewData = (HD_FLOAT_INT *)HD_Malloc(sizeof(HD_FLOAT_INT) * (Dest -> Col * Dest -> Row + Src -> Col * Src -> Row))) == HD_NULL)
    return FALSE;

  DestPtr = Dest -> Data;
  NewPtr  = NewData;
  SrcPtr  = Src -> Data;

  /**** Copy the data ****/

  switch(Position) {
  case HD_MTX_JOIN_BOTTOM:
    Lim          = Dest -> Row;
    Dest -> Row += Src -> Row;
    for(r = 0; r < Dest -> Row; ++r) {
      for(c = 0; c < Dest -> Col; ++c) {
        if (r >= Lim) *NewPtr = *SrcPtr++;
        else *NewPtr = *DestPtr++;
        ++NewPtr;
      } /* End of for (c) */
    } /* End of for (r) */
    break;

  case HD_MTX_JOIN_LEFT:
    Lim          = Src -> Col;
    Dest -> Col += Src -> Col;
    for(r = 0; r < Dest -> Row; ++r) {
      for(c = 0; c < Dest -> Col; ++c) {
        if (c < Lim) *NewPtr = *SrcPtr++;
        else *NewPtr = *DestPtr++;
        ++NewPtr;
      } /* End of for (c) */
    } /* End of for (r) */
    break;

  case HD_MTX_JOIN_RIGHT:
    Lim          = Dest -> Col;
    Dest -> Col += Src -> Col;
    for(r = 0; r < Dest -> Row; ++r) {
      for(c = 0; c < Dest -> Col; ++c) {
        if (c >= Lim) *NewPtr = *SrcPtr++;
        else *NewPtr = *DestPtr++;
        ++NewPtr;
      } /* End of for (c) */
    } /* End of for (r) */
    break;

  case HD_MTX_JOIN_TOP:
    Lim          = Src -> Row;
    Dest -> Row += Src -> Row;
    for(r = 0; r < Dest -> Row; ++r) {
      for(c = 0; c < Dest -> Col; ++c) {
        if (r < Lim) *NewPtr = *SrcPtr++;
        else *NewPtr = *DestPtr++;
        ++NewPtr;
      } /* End of for (c) */
    } /* End of for (r) */
    break;

  } /* End of switch */

  HD_Free(Dest -> Data);
  Dest -> Data = NewData;
  GlobErrCode  = HD_ERR_NONE;

  return TRUE;
}


/**** Multiply two generic matrix ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_MTX_FUNC(Mult)(HD_VP(HD_MTX) Res, HD_VP(HD_MTX) Mtx1, HD_VP(HD_MTX) Mtx2)
{
  HD_ULONG      i, j, k;
  HD_FLOAT_INT  e;

  if ((!Res) || (!Mtx1) || (!Mtx2)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  for(i = 0; i < Mtx1 -> Row; i++) {
    for(j = 0; j < Mtx2 -> Col; j++) {
      e = 0;
      for(k = 0; k < Mtx1 -> Col; k++)
        e += HD_Mtx_Val(Mtx1, k, i) * HD_Mtx_Val(Mtx2, j, k);
      HD_Mtx_Val(Res, j, i) = e;
    } /* End of for (j) */
  } /* End of for (i) */

  GlobErrCode = HD_ERR_NONE;
}


/**** Create a generic matrix ****/

HDRIVE_EXTERN HD_VP(HD_MTX) HDRIVE_EXPORT HD_MTX_FUNC(New)(HD_ULONG Col, HD_ULONG Row)
{
  HD_VP(HD_MTX)         Mtx;

  if ((!Col) && (!Row)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_NULL;
  }

  if ((Mtx = (HD_VP(HD_MTX))HD_Malloc(sizeof(HD_FP(struct __hd_mtx)))) == HD_NULL)
    return HD_NULL;

  if ((Mtx -> Data = (HD_FLOAT_INT *)HD_Calloc(sizeof(HD_FLOAT_INT) * Col * Row)) == HD_NULL) {
    HD_Free(Mtx);
    return HD_NULL;
  }

  GlobErrCode = HD_ERR_NONE;
  Mtx -> Col  = Col;
  Mtx -> Row  = Row;

  return Mtx;
}


/**** Generic matrix resize ****/

static HD_BOOL HD_FASTCALL HD_MTX_FUNC(Resize)(HD_VP(HD_MTX) Mtx, HD_ULONG Col, HD_ULONG Row)
{
  HD_FLOAT_INT *    Data;

  if ((Mtx -> Col == Col) && (Mtx -> Row == Row)) return TRUE;

  if ((Data = (HD_FLOAT_INT *)HD_Malloc(sizeof(HD_FLOAT_INT) * Col * Row)) == HD_NULL)
    return FALSE;

  HD_Free(Mtx -> Data);
  Mtx -> Col  = Col;
  Mtx -> Data = Data;
  Mtx -> Row  = Row;

  return TRUE;
}


/**** Scalar division of a generic matrix ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_MTX_FUNC(ScalarDiv)(HD_VP(HD_MTX) Mtx, register HD_FLOAT_INT Val)
{
  register HD_FLOAT_INT *Ptr;
  register HD_ULONG     Len;

  if (!Mtx) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  Len = HD_MTX_DATAEELEM(Mtx);
  Ptr = Mtx -> Data;
  while(Len--) {
    *Ptr /= Val;
    ++Ptr;
  } /* End of while */

  GlobErrCode = HD_ERR_NONE;
}


/**** Scalar multiplication of a generic matrix ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_MTX_FUNC(ScalarMult)(HD_VP(HD_MTX) Mtx, register HD_FLOAT_INT Val)
{
  register HD_FLOAT_INT *Ptr;
  register HD_ULONG     Len;

  if (!Mtx) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  Len = HD_MTX_DATAEELEM(Mtx);
  Ptr = Mtx -> Data;
  while(Len--) {
    *Ptr *= Val;
    ++Ptr;
  } /* End of while */

  GlobErrCode = HD_ERR_NONE;
}


/**** Scalar subtraction of a generic matrix ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_MTX_FUNC(ScalarSub)(HD_VP(HD_MTX) Mtx, register HD_FLOAT_INT Val)
{
  register HD_FLOAT_INT *Ptr;
  register HD_ULONG     Len;

  if (!Mtx) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  if (!Val) return;
  Len = HD_MTX_DATAEELEM(Mtx);
  Ptr = Mtx -> Data;
  while(Len--) {
    *Ptr -= Val;
    ++Ptr;
  } /* End of while */

  GlobErrCode = HD_ERR_NONE;
}


/**** Scalar sum of a generic matrix ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_MTX_FUNC(ScalarSum)(HD_VP(HD_MTX) Mtx, register HD_FLOAT_INT Val)
{
  register HD_FLOAT_INT *Ptr;
  register HD_ULONG     Len;

  if (!Mtx) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  if (!Val) return;
  Len = HD_MTX_DATAEELEM(Mtx);
  Ptr = Mtx -> Data;
  while(Len--) {
    *Ptr += Val;
    ++Ptr;
  } /* End of while */

  GlobErrCode = HD_ERR_NONE;
}


/**** Inverse of a generic symmetric matrix ****/

HDRIVE_EXTERN HD_BOOL HDRIVE_EXPORT HD_MTX_FUNC(SymmetricInverse)(HD_VP(HD_MTX) Inv, HD_VP(HD_MTX) Src)
{
  HD_FLOAT_INT  Ab, Big;
  HD_FLOAT_INT  *Q, *R, *T;
  HD_ULONG      j, k, l, m, n;

  if ((!Inv) || (!Src) || (Src -> Col != Src -> Row)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return FALSE;
  }

  n = Src -> Col;
  if (!HD_MTX_FUNC(Copy)(Inv, Src)) return FALSE;

  k = n * sizeof(HD_FLOAT_INT);
  if ((T = (HD_FLOAT_INT *)HD_Malloc(k)) != HD_NULL) {
    if ((Q = (HD_FLOAT_INT *)HD_Malloc(k)) != HD_NULL) {
      if ((R = (HD_FLOAT_INT *)HD_Malloc(k)) != HD_NULL) {
        for(m = 0; m < n; ++m) R[m] = HD_FP(1.0);

        k = 0;
        for(m = 0; m < n; ++m) {
          Big = HD_FP(0.0);
          for(l = 0; l < n; ++l) {
            Ab = fabs(HD_MTX_VAL(Inv, l, l));
            if ((Ab > Big) && (R[l] != HD_FP(0.0))) {
              Big = Ab;
              k   = l;
            }
          } /* End of for (l) */

          if (Big == HD_FP(0.0)) return FALSE;

          R[k] = HD_FP(0.0);
          Q[k] = HD_FP(1.0) / HD_MTX_VAL(Inv, k, k);
          T[k] = HD_FP(1.0);
          HD_MTX_VAL(Inv, k, k) = HD_FP(0.0);
          if (k) {
            for(l = 0; l < k; ++l) {
              T[l] = HD_MTX_VAL(Inv, k, l);

              if (R[l] == HD_FP(0.0)) Q[l] = HD_MTX_VAL(Inv, k, l) * Q[k];
              else Q[l] = -HD_MTX_VAL(Inv, k, l) * Q[k];
              HD_MTX_VAL(Inv, k, l) = HD_FP(0.0);
            } /* End of for (l) */
          }

          if ((k + 1) < n) {
            for(l = k + 1; l < n; ++l) {
              if (R[l] != 0.0) T[l] = HD_MTX_VAL(Inv, l, k);
              else T[l] = -HD_MTX_VAL(Inv, l, k);
              Q[l] = -HD_MTX_VAL(Inv, l, k) * Q[k];
              HD_MTX_VAL(Inv, l, k) = HD_FP(0.0);
            } /* End of for (l) */
          }

          for(l = 0; l < n; ++l)
            for(k = l; k < n; ++k)
              HD_MTX_VAL(Inv, k, l) += T[l] * Q[k];
        } /* End of for (m) */

        m = n;
        l = n - 1;
        for(k = 1; k < n; ++k) {
          --m;
          --l;
          for(j = 0; j <= l; ++j) HD_MTX_VAL(Inv, j, m) = HD_MTX_VAL(Inv, m, j);
        } /* End of for (k) */
        HD_Free(R);
      }
      HD_Free(Q);
    }
    HD_Free(T);
  }
  GlobErrCode = HD_ERR_NONE;

  return TRUE;
}


/**** Transpose a generic square matrix ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_MTX_FUNC(Transpose)(HD_VP(HD_MTX) Mtx)
{
  register HD_FLOAT_INT Tmp;
  register HD_ULONG     i, j;

  if ((!Mtx) || (Mtx -> Col != Mtx -> Row)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  for(i = 1; i < Mtx -> Row; ++i) {
    for(j = 0; j < i; ++j) {
      Tmp                   = HD_MTX_VAL(Mtx, i, j);
      HD_MTX_VAL(Mtx, i, j) = HD_MTX_VAL(Mtx, j, i);
      HD_MTX_VAL(Mtx, j, i) = Tmp;
    } /* End of for (j) */
  } /* End of for (i) */

  GlobErrCode = HD_ERR_NONE;
}


/**** Clear a 2x2 matrix ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_MTX2X2_FUNC(Clear)(register HD_VP(HD_MTX2X2) *Mtx)
{
  if (!Mtx) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  Mtx -> Raw[0] = HD_FP(0.0);
  Mtx -> Raw[1] = HD_FP(0.0);
  Mtx -> Raw[2] = HD_FP(0.0);
  Mtx -> Raw[3] = HD_FP(0.0);
  GlobErrCode   = HD_ERR_NONE;
}


/**** Copy a 2x2 matrix ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_MTX2X2_FUNC(Copy)(register HD_VP(HD_MTX2X2) *Dest, register HD_VP(HD_MTX2X2) *Src)
{
  if ((!Dest) || (!Src)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  Dest -> Raw[0] = Src -> Raw[0];
  Dest -> Raw[1] = Src -> Raw[1];
  Dest -> Raw[2] = Src -> Raw[2];
  Dest -> Raw[3] = Src -> Raw[3];
  GlobErrCode    = HD_ERR_NONE;
}


/**** Determinant of a 2x2 matrix ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_MTX2X2_FUNC(Determinant)(register HD_VP(HD_MTX2X2) *Mtx)
{
  if (!Mtx) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_FP(0.0);
  }

  GlobErrCode = HD_ERR_NONE;

  return _HDM_Mtx2x2_Determinant(Mtx);
}


/**** 2x2 matrix inverse ****/

HDRIVE_EXTERN HD_BOOL HDRIVE_EXPORT HD_MTX2X2_FUNC(Inverse)(HD_VP(HD_MTX2X2) *Inv, HD_VP(HD_MTX2X2) *Mtx)
{
  register HD_FLOAT_INT     Det;

  if (!Mtx) {
    GlobErrCode = HD_ERR_ILLPAR;
    return FALSE;
  }

  if ((Det =_HDM_Mtx2x2_Determinant(Mtx)) == HD_FP(0.0)) return FALSE;

  Inv -> Raw[0] = Mtx -> Raw[3] /  Det;
  Inv -> Raw[1] = Mtx -> Raw[1] / -Det;
  Inv -> Raw[2] = Mtx -> Raw[2] / -Det;
  Inv -> Raw[3] = Mtx -> Raw[0] /  Det;

  GlobErrCode  = HD_ERR_NONE;

  return TRUE;
}


/**** Build the 3x3 matrix from 3 vector3 ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_MTX3X3_FUNC(BuildVect)(register HD_VP(HD_MTX3X3) *Dest, register HD_VP(HD_VECTOR3) *Row0,
                                                           register HD_VP(HD_VECTOR3) *Row1, register HD_VP(HD_VECTOR3) *Row2)
{
  if ((!Dest) || (!Row0) || (!Row1) || (!Row2)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  Dest -> Ele[0][0] = Row0 -> Coord.x;
  Dest -> Ele[0][1] = Row0 -> Coord.y;
  Dest -> Ele[0][2] = Row0 -> Coord.z;
  Dest -> Ele[1][0] = Row1 -> Coord.x;
  Dest -> Ele[1][1] = Row1 -> Coord.y;
  Dest -> Ele[1][2] = Row1 -> Coord.z;
  Dest -> Ele[2][0] = Row2 -> Coord.x;
  Dest -> Ele[2][1] = Row2 -> Coord.y;
  Dest -> Ele[2][2] = Row2 -> Coord.z;

  GlobErrCode       = HD_ERR_NONE;
}


/**** Clear a 3x3 matrix ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_MTX3X3_FUNC(Clear)(register HD_VP(HD_MTX3X3) *Mtx)
{
  if (!Mtx) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  Mtx -> Raw[0] = HD_FP(0.0);
  Mtx -> Raw[1] = HD_FP(0.0);
  Mtx -> Raw[2] = HD_FP(0.0);
  Mtx -> Raw[3] = HD_FP(0.0);
  Mtx -> Raw[4] = HD_FP(0.0);
  Mtx -> Raw[5] = HD_FP(0.0);
  Mtx -> Raw[6] = HD_FP(0.0);
  Mtx -> Raw[7] = HD_FP(0.0);
  Mtx -> Raw[8] = HD_FP(0.0);

  GlobErrCode   = HD_ERR_NONE;
}


/**** Copy the 3x3 matrix ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_MTX3X3_FUNC(Copy)(register HD_VP(HD_MTX3X3) *Dest, register HD_VP(HD_MTX3X3) *Src)
{
  if ((!Dest) || (!Src)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  Dest -> Raw[0] = Src -> Raw[0];
  Dest -> Raw[1] = Src -> Raw[1];
  Dest -> Raw[2] = Src -> Raw[2];
  Dest -> Raw[3] = Src -> Raw[3];
  Dest -> Raw[4] = Src -> Raw[4];
  Dest -> Raw[5] = Src -> Raw[5];
  Dest -> Raw[6] = Src -> Raw[6];
  Dest -> Raw[7] = Src -> Raw[7];
  Dest -> Raw[8] = Src -> Raw[8];
  GlobErrCode    = HD_ERR_NONE;
}


/**** Determinant of a 3x3 matrix ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_MTX3X3_FUNC(Determinant)(register HD_VP(HD_MTX3X3) *Mtx)
{
  if (!Mtx) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_FP(0.0);
  }

  GlobErrCode = HD_ERR_NONE;
  return _HDM_Mtx3x3_Determinant(Mtx);
}


/**** 3x3 matrix inverse ****/

HDRIVE_EXTERN HD_BOOL HDRIVE_EXPORT HD_MTX3X3_FUNC(Inverse)(HD_VP(HD_MTX3X3) *Inv, HD_VP(HD_MTX3X3) *Mtx)
{
  register HD_FLOAT_INT     Det;

  if ((!Inv) || (!Mtx)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return FALSE;
  }

  if ((Det =_HDM_Mtx3x3_Determinant(Mtx)) == HD_FP(0.0)) return FALSE;

  Det              = HD_FP(1.0) / Det;

  Inv -> Ele[0][0] = (Mtx -> Ele[1][1] * Mtx -> Ele[2][2] - Mtx -> Ele[1][2] * Mtx -> Ele[2][1]) * Det;
  Inv -> Ele[1][0] = (Mtx -> Ele[1][2] * Mtx -> Ele[2][0] - Mtx -> Ele[1][0] * Mtx -> Ele[2][2]) * Det;
  Inv -> Ele[2][0] = (Mtx -> Ele[1][0] * Mtx -> Ele[2][1] - Mtx -> Ele[1][1] * Mtx -> Ele[2][0]) * Det;
  Inv -> Ele[0][1] = (Mtx -> Ele[2][1] * Mtx -> Ele[0][2] - Mtx -> Ele[2][2] * Mtx -> Ele[0][1]) * Det;
  Inv -> Ele[1][1] = (Mtx -> Ele[2][2] * Mtx -> Ele[0][0] - Mtx -> Ele[2][0] * Mtx -> Ele[0][2]) * Det;
  Inv -> Ele[2][1] = (Mtx -> Ele[2][0] * Mtx -> Ele[0][1] - Mtx -> Ele[2][1] * Mtx -> Ele[0][0]) * Det;
  Inv -> Ele[0][2] = (Mtx -> Ele[0][1] * Mtx -> Ele[1][2] - Mtx -> Ele[0][2] * Mtx -> Ele[1][1]) * Det;
  Inv -> Ele[1][2] = (Mtx -> Ele[0][2] * Mtx -> Ele[1][0] - Mtx -> Ele[0][0] * Mtx -> Ele[1][2]) * Det;
  Inv -> Ele[2][2] = (Mtx -> Ele[0][0] * Mtx -> Ele[1][1] - Mtx -> Ele[0][1] * Mtx -> Ele[1][0]) * Det;

  GlobErrCode      = HD_ERR_NONE;

  return TRUE;
}


/**** Clear a 4x4 matrix ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_MTX4X4_FUNC(Clear)(register HD_VP(HD_MTX4X4) *Mtx)
{
  if (!Mtx) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  Mtx -> Raw[ 0] = HD_FP(0.0);
  Mtx -> Raw[ 1] = HD_FP(0.0);
  Mtx -> Raw[ 2] = HD_FP(0.0);
  Mtx -> Raw[ 3] = HD_FP(0.0);
  Mtx -> Raw[ 4] = HD_FP(0.0);
  Mtx -> Raw[ 5] = HD_FP(0.0);
  Mtx -> Raw[ 6] = HD_FP(0.0);
  Mtx -> Raw[ 7] = HD_FP(0.0);
  Mtx -> Raw[ 8] = HD_FP(0.0);
  Mtx -> Raw[ 9] = HD_FP(0.0);
  Mtx -> Raw[10] = HD_FP(0.0);
  Mtx -> Raw[11] = HD_FP(0.0);
  Mtx -> Raw[12] = HD_FP(0.0);
  Mtx -> Raw[13] = HD_FP(0.0);
  Mtx -> Raw[14] = HD_FP(0.0);
  Mtx -> Raw[15] = HD_FP(0.0);

  GlobErrCode    = HD_ERR_NONE;
}


/**** Copy a 4x4 matrix ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_MTX4X4_FUNC(Copy)(register HD_VP(HD_MTX4X4) *Dest, register HD_VP(HD_MTX4X4) *Src)
{
  if ((!Dest) || (!Src)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  Dest -> Raw[ 0] = Src -> Raw[ 0];
  Dest -> Raw[ 1] = Src -> Raw[ 1];
  Dest -> Raw[ 2] = Src -> Raw[ 2];
  Dest -> Raw[ 3] = Src -> Raw[ 3];
  Dest -> Raw[ 4] = Src -> Raw[ 4];
  Dest -> Raw[ 5] = Src -> Raw[ 5];
  Dest -> Raw[ 6] = Src -> Raw[ 6];
  Dest -> Raw[ 7] = Src -> Raw[ 7];
  Dest -> Raw[ 8] = Src -> Raw[ 8];
  Dest -> Raw[ 9] = Src -> Raw[ 9];
  Dest -> Raw[10] = Src -> Raw[10];
  Dest -> Raw[11] = Src -> Raw[11];
  Dest -> Raw[12] = Src -> Raw[12];
  Dest -> Raw[13] = Src -> Raw[13];
  Dest -> Raw[14] = Src -> Raw[14];
  Dest -> Raw[15] = Src -> Raw[15];

  GlobErrCode     = HD_ERR_NONE;
}


/**** Load the identity matrix ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_MTX4X4_FUNC(Identity)(register HD_VP(HD_MTX4X4) *Mtx)
{
  if (!Mtx) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  GlobErrCode = HD_ERR_NONE;
  _HDM_Mtx4x4_Identity(Mtx);
}


/**** 4x4 matrix inverse ****/

HDRIVE_EXTERN HD_BOOL HDRIVE_EXPORT HD_MTX4X4_FUNC(Inverse)(HD_VP(HD_MTX4X4) *Inv, HD_VP(HD_MTX4X4) *Mtx)
{
  HD_FLOAT_INT      Det;

  if ((!Inv) || (!Mtx)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return FALSE;
  }

  Inv -> Raw[0 ] =  Mtx -> Raw[5 ] * Mtx -> Raw[10] * Mtx -> Raw[15] -
                    Mtx -> Raw[5 ] * Mtx -> Raw[11] * Mtx -> Raw[14] -
                    Mtx -> Raw[9 ] * Mtx -> Raw[6 ] * Mtx -> Raw[15] +
                    Mtx -> Raw[9 ] * Mtx -> Raw[7 ] * Mtx -> Raw[14] +
                    Mtx -> Raw[13] * Mtx -> Raw[6 ] * Mtx -> Raw[11] -
                    Mtx -> Raw[13] * Mtx -> Raw[7 ] * Mtx -> Raw[10];

  Inv -> Raw[4 ] = -Mtx -> Raw[4 ] * Mtx -> Raw[10] * Mtx -> Raw[15] +
                    Mtx -> Raw[4 ] * Mtx -> Raw[11] * Mtx -> Raw[14] +
                    Mtx -> Raw[8 ] * Mtx -> Raw[6 ] * Mtx -> Raw[15] -
                    Mtx -> Raw[8 ] * Mtx -> Raw[7 ] * Mtx -> Raw[14] -
                    Mtx -> Raw[12] * Mtx -> Raw[6 ] * Mtx -> Raw[11] +
                    Mtx -> Raw[12] * Mtx -> Raw[7 ] * Mtx -> Raw[10];

  Inv -> Raw[8 ] =  Mtx -> Raw[4 ] * Mtx -> Raw[9 ] * Mtx -> Raw[15] -
                    Mtx -> Raw[4 ] * Mtx -> Raw[11] * Mtx -> Raw[13] -
                    Mtx -> Raw[8 ] * Mtx -> Raw[5 ] * Mtx -> Raw[15] +
                    Mtx -> Raw[8 ] * Mtx -> Raw[7 ] * Mtx -> Raw[13] +
                    Mtx -> Raw[12] * Mtx -> Raw[5 ] * Mtx -> Raw[11] -
                    Mtx -> Raw[12] * Mtx -> Raw[7 ] * Mtx -> Raw[9 ];

  Inv -> Raw[12] = -Mtx -> Raw[4 ] * Mtx -> Raw[9 ] * Mtx -> Raw[14] +
                    Mtx -> Raw[4 ] * Mtx -> Raw[10] * Mtx -> Raw[13] +
                    Mtx -> Raw[8 ] * Mtx -> Raw[5 ] * Mtx -> Raw[14] -
                    Mtx -> Raw[8 ] * Mtx -> Raw[6 ] * Mtx -> Raw[13] -
                    Mtx -> Raw[12] * Mtx -> Raw[5 ] * Mtx -> Raw[10] +
                    Mtx -> Raw[12] * Mtx -> Raw[6 ] * Mtx -> Raw[9 ];

  Inv -> Raw[1 ] = -Mtx -> Raw[1 ] * Mtx -> Raw[10] * Mtx -> Raw[15] +
                    Mtx -> Raw[1 ] * Mtx -> Raw[11] * Mtx -> Raw[14] +
                    Mtx -> Raw[9 ] * Mtx -> Raw[2 ] * Mtx -> Raw[15] -
                    Mtx -> Raw[9 ] * Mtx -> Raw[3 ] * Mtx -> Raw[14] -
                    Mtx -> Raw[13] * Mtx -> Raw[2 ] * Mtx -> Raw[11] +
                    Mtx -> Raw[13] * Mtx -> Raw[3 ] * Mtx -> Raw[10];

  Inv -> Raw[5 ] =  Mtx -> Raw[0 ] * Mtx -> Raw[10] * Mtx -> Raw[15] -
                    Mtx -> Raw[0 ] * Mtx -> Raw[11] * Mtx -> Raw[14] -
                    Mtx -> Raw[8 ] * Mtx -> Raw[2 ] * Mtx -> Raw[15] +
                    Mtx -> Raw[8 ] * Mtx -> Raw[3 ] * Mtx -> Raw[14] +
                    Mtx -> Raw[12] * Mtx -> Raw[2 ] * Mtx -> Raw[11] -
                    Mtx -> Raw[12] * Mtx -> Raw[3 ] * Mtx -> Raw[10];

  Inv -> Raw[9 ] = -Mtx -> Raw[0 ] * Mtx -> Raw[9 ] * Mtx -> Raw[15] +
                    Mtx -> Raw[0 ] * Mtx -> Raw[11] * Mtx -> Raw[13] +
                    Mtx -> Raw[8 ] * Mtx -> Raw[1 ] * Mtx -> Raw[15] -
                    Mtx -> Raw[8 ] * Mtx -> Raw[3 ] * Mtx -> Raw[13] -
                    Mtx -> Raw[12] * Mtx -> Raw[1 ] * Mtx -> Raw[11] +
                    Mtx -> Raw[12] * Mtx -> Raw[3 ] * Mtx -> Raw[9 ];

  Inv -> Raw[13] =  Mtx -> Raw[0 ] * Mtx -> Raw[9 ] * Mtx -> Raw[14] -
                    Mtx -> Raw[0 ] * Mtx -> Raw[10] * Mtx -> Raw[13] -
                    Mtx -> Raw[8 ] * Mtx -> Raw[1 ] * Mtx -> Raw[14] +
                    Mtx -> Raw[8 ] * Mtx -> Raw[2 ] * Mtx -> Raw[13] +
                    Mtx -> Raw[12] * Mtx -> Raw[1 ] * Mtx -> Raw[10] -
                    Mtx -> Raw[12] * Mtx -> Raw[2 ] * Mtx -> Raw[9 ];

  Inv -> Raw[2 ] =  Mtx -> Raw[1 ] * Mtx -> Raw[6 ] * Mtx -> Raw[15] -
                    Mtx -> Raw[1 ] * Mtx -> Raw[7 ] * Mtx -> Raw[14] -
                    Mtx -> Raw[5 ] * Mtx -> Raw[2 ] * Mtx -> Raw[15] +
                    Mtx -> Raw[5 ] * Mtx -> Raw[3 ] * Mtx -> Raw[14] +
                    Mtx -> Raw[13] * Mtx -> Raw[2 ] * Mtx -> Raw[7 ] -
                    Mtx -> Raw[13] * Mtx -> Raw[3 ] * Mtx -> Raw[6 ];

  Inv -> Raw[6 ] = -Mtx -> Raw[0 ] * Mtx -> Raw[6 ] * Mtx -> Raw[15] +
                    Mtx -> Raw[0 ] * Mtx -> Raw[7 ] * Mtx -> Raw[14] +
                    Mtx -> Raw[4 ] * Mtx -> Raw[2 ] * Mtx -> Raw[15] -
                    Mtx -> Raw[4 ] * Mtx -> Raw[3 ] * Mtx -> Raw[14] -
                    Mtx -> Raw[12] * Mtx -> Raw[2 ] * Mtx -> Raw[7 ] +
                    Mtx -> Raw[12] * Mtx -> Raw[3 ] * Mtx -> Raw[6 ];

  Inv -> Raw[10] =  Mtx -> Raw[0 ] * Mtx -> Raw[5 ] * Mtx -> Raw[15] -
                    Mtx -> Raw[0 ] * Mtx -> Raw[7 ] * Mtx -> Raw[13] -
                    Mtx -> Raw[4 ] * Mtx -> Raw[1 ] * Mtx -> Raw[15] +
                    Mtx -> Raw[4 ] * Mtx -> Raw[3 ] * Mtx -> Raw[13] +
                    Mtx -> Raw[12] * Mtx -> Raw[1 ] * Mtx -> Raw[7 ] -
                    Mtx -> Raw[12] * Mtx -> Raw[3 ] * Mtx -> Raw[5 ];

  Inv -> Raw[14] = -Mtx -> Raw[0 ] * Mtx -> Raw[5 ] * Mtx -> Raw[14] +
                    Mtx -> Raw[0 ] * Mtx -> Raw[6 ] * Mtx -> Raw[13] +
                    Mtx -> Raw[4 ] * Mtx -> Raw[1 ] * Mtx -> Raw[14] -
                    Mtx -> Raw[4 ] * Mtx -> Raw[2 ] * Mtx -> Raw[13] -
                    Mtx -> Raw[12] * Mtx -> Raw[1 ] * Mtx -> Raw[6 ] +
                    Mtx -> Raw[12] * Mtx -> Raw[2 ] * Mtx -> Raw[5 ];

  Inv -> Raw[3 ] = -Mtx -> Raw[1 ] * Mtx -> Raw[6 ] * Mtx -> Raw[11] +
                    Mtx -> Raw[1 ] * Mtx -> Raw[7 ] * Mtx -> Raw[10] +
                    Mtx -> Raw[5 ] * Mtx -> Raw[2 ] * Mtx -> Raw[11] -
                    Mtx -> Raw[5 ] * Mtx -> Raw[3 ] * Mtx -> Raw[10] -
                    Mtx -> Raw[9 ] * Mtx -> Raw[2 ] * Mtx -> Raw[7 ] +
                    Mtx -> Raw[9 ] * Mtx -> Raw[3 ] * Mtx -> Raw[6 ];

  Inv -> Raw[7 ] =  Mtx -> Raw[0 ] * Mtx -> Raw[6 ] * Mtx -> Raw[11] -
                    Mtx -> Raw[0 ] * Mtx -> Raw[7 ] * Mtx -> Raw[10] -
                    Mtx -> Raw[4 ] * Mtx -> Raw[2 ] * Mtx -> Raw[11] +
                    Mtx -> Raw[4 ] * Mtx -> Raw[3 ] * Mtx -> Raw[10] +
                    Mtx -> Raw[8 ] * Mtx -> Raw[2 ] * Mtx -> Raw[7 ] -
                    Mtx -> Raw[8 ] * Mtx -> Raw[3 ] * Mtx -> Raw[6 ];

  Inv -> Raw[11] = -Mtx -> Raw[0 ] * Mtx -> Raw[5 ] * Mtx -> Raw[11] +
                    Mtx -> Raw[0 ] * Mtx -> Raw[7 ] * Mtx -> Raw[9 ] +
                    Mtx -> Raw[4 ] * Mtx -> Raw[1 ] * Mtx -> Raw[11] -
                    Mtx -> Raw[4 ] * Mtx -> Raw[3 ] * Mtx -> Raw[9 ] -
                    Mtx -> Raw[8 ] * Mtx -> Raw[1 ] * Mtx -> Raw[7 ] +
                    Mtx -> Raw[8 ] * Mtx -> Raw[3 ] * Mtx -> Raw[5 ];

  Inv -> Raw[15] =  Mtx -> Raw[0 ] * Mtx -> Raw[5 ] * Mtx -> Raw[10] -
                    Mtx -> Raw[0 ] * Mtx -> Raw[6 ] * Mtx -> Raw[9 ] -
                    Mtx -> Raw[4 ] * Mtx -> Raw[1 ] * Mtx -> Raw[10] +
                    Mtx -> Raw[4 ] * Mtx -> Raw[2 ] * Mtx -> Raw[9 ] +
                    Mtx -> Raw[8 ] * Mtx -> Raw[1 ] * Mtx -> Raw[6 ] -
                    Mtx -> Raw[8 ] * Mtx -> Raw[2 ] * Mtx -> Raw[5 ];

  Det = Mtx -> Raw[0 ] * Inv -> Raw[0 ] + Mtx -> Raw[1 ] * Inv -> Raw[4 ] +
        Mtx -> Raw[2 ] * Inv -> Raw[8 ] + Mtx -> Raw[3 ] * Inv -> Raw[12];

  if (!Det) return FALSE;

  Det = HD_FP(1.0) / Det;

  Inv -> Raw[0 ] *= Det;
  Inv -> Raw[1 ] *= Det;
  Inv -> Raw[2 ] *= Det;
  Inv -> Raw[3 ] *= Det;
  Inv -> Raw[4 ] *= Det;
  Inv -> Raw[5 ] *= Det;
  Inv -> Raw[6 ] *= Det;
  Inv -> Raw[7 ] *= Det;
  Inv -> Raw[8 ] *= Det;
  Inv -> Raw[9 ] *= Det;
  Inv -> Raw[10] *= Det;
  Inv -> Raw[11] *= Det;
  Inv -> Raw[12] *= Det;
  Inv -> Raw[13] *= Det;
  Inv -> Raw[14] *= Det;
  Inv -> Raw[15] *= Det;

  GlobErrCode = HD_ERR_NONE;

  return TRUE;
}


/**** Multiply two 4x4 matrix ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_MTX4X4_FUNC(Mult)(register HD_VP(HD_MTX4X4) *Res, register HD_VP(HD_MTX4X4) *Mtx1,
                                                         register HD_VP(HD_MTX4X4) *Mtx2)
{
  /**** Unrolled loops for maximum performances ****/

  Res -> Ele[0][0] = Mtx1 -> Ele[0][0] * Mtx2 -> Ele[0][0] + Mtx1 -> Ele[0][1] * Mtx2 -> Ele[1][0] +
                     Mtx1 -> Ele[0][2] * Mtx2 -> Ele[2][0] + Mtx1 -> Ele[0][3] * Mtx2 -> Ele[3][0];
  Res -> Ele[0][1] = Mtx1 -> Ele[0][0] * Mtx2 -> Ele[0][1] + Mtx1 -> Ele[0][1] * Mtx2 -> Ele[1][1] +
                     Mtx1 -> Ele[0][2] * Mtx2 -> Ele[2][1] + Mtx1 -> Ele[0][3] * Mtx2 -> Ele[3][1];
  Res -> Ele[0][2] = Mtx1 -> Ele[0][0] * Mtx2 -> Ele[0][2] + Mtx1 -> Ele[0][1] * Mtx2 -> Ele[1][2] +
                     Mtx1 -> Ele[0][2] * Mtx2 -> Ele[2][2] + Mtx1 -> Ele[0][3] * Mtx2 -> Ele[3][2];
  Res -> Ele[0][3] = Mtx1 -> Ele[0][0] * Mtx2 -> Ele[0][3] + Mtx1 -> Ele[0][1] * Mtx2 -> Ele[1][3] +
                     Mtx1 -> Ele[0][2] * Mtx2 -> Ele[2][3] + Mtx1 -> Ele[0][3] * Mtx2 -> Ele[3][3];

  Res -> Ele[1][0] = Mtx1 -> Ele[1][0] * Mtx2 -> Ele[0][0] + Mtx1 -> Ele[1][1] * Mtx2 -> Ele[1][0] +
                     Mtx1 -> Ele[1][2] * Mtx2 -> Ele[2][0] + Mtx1 -> Ele[1][3] * Mtx2 -> Ele[3][0];
  Res -> Ele[1][1] = Mtx1 -> Ele[1][0] * Mtx2 -> Ele[0][1] + Mtx1 -> Ele[1][1] * Mtx2 -> Ele[1][1] +
                     Mtx1 -> Ele[1][2] * Mtx2 -> Ele[2][1] + Mtx1 -> Ele[1][3] * Mtx2 -> Ele[3][1];
  Res -> Ele[1][2] = Mtx1 -> Ele[1][0] * Mtx2 -> Ele[0][2] + Mtx1 -> Ele[1][1] * Mtx2 -> Ele[1][2] +
                     Mtx1 -> Ele[1][2] * Mtx2 -> Ele[2][2] + Mtx1 -> Ele[1][3] * Mtx2 -> Ele[3][2];
  Res -> Ele[1][3] = Mtx1 -> Ele[1][0] * Mtx2 -> Ele[0][3] + Mtx1 -> Ele[1][1] * Mtx2 -> Ele[1][3] +
                     Mtx1 -> Ele[1][2] * Mtx2 -> Ele[2][3] + Mtx1 -> Ele[1][3] * Mtx2 -> Ele[3][3];

  Res -> Ele[2][0] = Mtx1 -> Ele[2][0] * Mtx2 -> Ele[0][0] + Mtx1 -> Ele[2][1] * Mtx2 -> Ele[1][0] +
                     Mtx1 -> Ele[2][2] * Mtx2 -> Ele[2][0] + Mtx1 -> Ele[2][3] * Mtx2 -> Ele[3][0];
  Res -> Ele[2][1] = Mtx1 -> Ele[2][0] * Mtx2 -> Ele[0][1] + Mtx1 -> Ele[2][1] * Mtx2 -> Ele[1][1] +
                     Mtx1 -> Ele[2][2] * Mtx2 -> Ele[2][1] + Mtx1 -> Ele[2][3] * Mtx2 -> Ele[3][1];
  Res -> Ele[2][2] = Mtx1 -> Ele[2][0] * Mtx2 -> Ele[0][2] + Mtx1 -> Ele[2][1] * Mtx2 -> Ele[1][2] +
                     Mtx1 -> Ele[2][2] * Mtx2 -> Ele[2][2] + Mtx1 -> Ele[2][3] * Mtx2 -> Ele[3][2];
  Res -> Ele[2][3] = Mtx1 -> Ele[2][0] * Mtx2 -> Ele[0][3] + Mtx1 -> Ele[2][1] * Mtx2 -> Ele[1][3] +
                     Mtx1 -> Ele[2][2] * Mtx2 -> Ele[2][3] + Mtx1 -> Ele[2][3] * Mtx2 -> Ele[3][3];

  Res -> Ele[3][0] = Mtx1 -> Ele[3][0] * Mtx2 -> Ele[0][0] + Mtx1 -> Ele[3][1] * Mtx2 -> Ele[1][0] +
                     Mtx1 -> Ele[3][2] * Mtx2 -> Ele[2][0] + Mtx1 -> Ele[3][3] * Mtx2 -> Ele[3][0];
  Res -> Ele[3][1] = Mtx1 -> Ele[3][0] * Mtx2 -> Ele[0][1] + Mtx1 -> Ele[3][1] * Mtx2 -> Ele[1][1] +
                     Mtx1 -> Ele[3][2] * Mtx2 -> Ele[2][1] + Mtx1 -> Ele[3][3] * Mtx2 -> Ele[3][1];
  Res -> Ele[3][2] = Mtx1 -> Ele[3][0] * Mtx2 -> Ele[0][2] + Mtx1 -> Ele[3][1] * Mtx2 -> Ele[1][2] +
                     Mtx1 -> Ele[3][2] * Mtx2 -> Ele[2][2] + Mtx1 -> Ele[3][3] * Mtx2 -> Ele[3][2];
  Res -> Ele[3][3] = Mtx1 -> Ele[3][0] * Mtx2 -> Ele[0][3] + Mtx1 -> Ele[3][1] * Mtx2 -> Ele[1][3] +
                     Mtx1 -> Ele[3][2] * Mtx2 -> Ele[2][3] + Mtx1 -> Ele[3][3] * Mtx2 -> Ele[3][3];
}


/**** Free the 2D interpolation context ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_VECT2_FUNC(InterFree)(HD_VECTINTER Ctx)
{
  if (!Ctx) return;
  HD_FreeSafe(((HD_VP(HD_INTERINT2) *)Ctx) -> Vect);
  HD_Free(Ctx);
}


/**** Get the value ****/

HDRIVE_EXTERN HD_BOOL HDRIVE_EXPORT HD_VECT2_FUNC(InterGet)(HD_VECTINTER Ctx, HD_FLOAT_INT *Val, HD_FLOAT_INT X, HD_LONG Type)
{
  HD_VP(HD_VECTOR2) *           Vect;
  HD_FLOAT_INT                      a0, a1, a2, a3, Mu, Mu2;
  HD_FLOAT_INT                      y0, y3;
  HD_ULONG                      k, Idx1, Idx2;

  HD_VP(HD_INTERINT2) *         hCtx = (HD_VP(HD_INTERINT2) *)Ctx;

  if ((!hCtx) || (!Val) || (X > hCtx -> Max) || (X < hCtx -> Min)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return FALSE;
  }
  Vect = hCtx -> Vect;

  if (X > Vect[hCtx -> CurPos].Coord.x) {
    for(k = hCtx -> CurPos; (k < hCtx -> Num) && (X > Vect[k].Coord.x); ++k);
    Idx1 = k - 1;
    Idx2 = k;

  } else {
    for(k = hCtx -> CurPos; (k) && (X < Vect[k].Coord.x); --k);
    Idx1 = k;
    Idx2 = k + 1;
  }

  Mu = (X - Vect[Idx1].Coord.x) / (Vect[Idx2].Coord.x - Vect[Idx1].Coord.x);

  switch(Type) {
  case HD_VECT_INTER_COSINE:
    Mu2  = (HD_FP(1.0) - cos(Mu * M_PI)) / HD_FP(2.0);
    *Val = Vect[Idx1].Coord.y * (HD_FP(1.0) - Mu2) + Vect[Idx2].Coord.y * Mu2;
    break;

  case HD_VECT_INTER_CUBIC:
    y0  = (Idx1 == 0) ? HD_FP(0.0) : Vect[Idx1 - 1].Coord.y;
    y3  = (Idx1 == (hCtx -> Num - 1)) ? HD_FP(0.0) : Vect[Idx1 + 1].Coord.y;
    Mu2   = Mu * Mu;
    a0   = y3 - Vect[Idx2].Coord.y - y0 + Vect[Idx1].Coord.y;
    a1   = y0 - Vect[Idx1].Coord.y - a0;
    a2   = Vect[Idx2].Coord.y - y0;
    a3   = Vect[Idx1].Coord.y;
    *Val = a0 * Mu * Mu2 + a1 * Mu2 + a2 * Mu + a3;
    break;

  case HD_VECT_INTER_LINEAR:
    *Val = Vect[Idx1].Coord.y * (HD_FP(1.0) - Mu) + Vect[Idx2].Coord.y * Mu;
    break;
  }

  return TRUE;
}


/**** Initialize the context for 2D interpolation ****/

HDRIVE_EXTERN HD_VECTINTER HDRIVE_EXPORT HD_VECT2_FUNC(InterNew)(HD_VP(HD_VECTOR2) *Vect0, HD_ULONG Num)
{
  HD_VP(HD_INTERINT2) *         Ctx;

  if ((!Vect0) || (Num < 4)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_NULL;
  }

  if ((Ctx = HD_Calloc(sizeof(HD_VP(HD_INTERINT2)))) != HD_NULL) {
    HD_ULONG    k;

    if ((Ctx -> Vect = HD_Malloc(Num * sizeof(HD_VP(HD_VECTOR2)))) == HD_NULL) {
      HD_Free(Ctx);
      return HD_NULL;
    }

    /**** Copy the vector array ****/

    for(k = 0; k < Num; ++k)
      Ctx -> Vect[k] = Vect0[k];

    HD_QsortP(Ctx -> Vect, Num, sizeof(HD_VP(HD_VECTOR2)), HD_VECT2_FUNC(InterSort));

    Ctx -> Max = Ctx -> Vect[Num - 1].Coord.x;
    Ctx -> Min = Ctx -> Vect[0].Coord.x;
    Ctx -> Num = Num;

    GlobErrCode = HD_ERR_NONE;
  }

  return Ctx;
}


/**** Sort the vector array for interpolation ****/

static HD_LONG HD_CALLBACK HD_VECT2_FUNC(InterSort)(const HD_VOID *Vect0, const HD_VOID *Vect1)
{
  HD_FLOAT_INT      Diff = ((HD_VP(HD_VECTOR2) *)Vect0) -> Coord.x - ((HD_VP(HD_VECTOR2) *)Vect1) -> Coord.x;

  if (Diff > HD_FP(0.0)) return 1;
  if (Diff < HD_FP(0.0)) return -1;

  return 0;
}


/**** Angle between two vectors ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_VECT3_FUNC(Angle)(register HD_VP(HD_VECTOR3) *Vect0, register HD_VP(HD_VECTOR3) *Vect1)
{
  register HD_FLOAT_INT     Dp = _HDM_Vect3_DotProd(Vect0, Vect1) /
                             (_HDM_Vect3_Magnitude(Vect0) * _HDM_Vect3_Magnitude(Vect1));

  if (Dp < HD_FP(-0.999999)) Dp = HD_FP(-0.9999999);
  else if (Dp > HD_FP(0.9999999)) Dp = HD_FP(0.9999999);

  return (HD_VP(HD_RAD_TO_DEG) * (HD_FLOAT_INT)acos(Dp));
}


/**** Cross product ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_VECT3_FUNC(CrossProd)(register HD_VP(HD_VECTOR3) *Res, register HD_VP(HD_VECTOR3) *Vect0, register HD_VP(HD_VECTOR3) *Vect1)
{
  _HDM_Vect3_CrossProd(Res, Vect0, Vect1);
}


/**** Vector difference Res = Vect0 - Vect1 ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_VECT3_FUNC(Diff)(register HD_VP(HD_VECTOR3) *Res, register HD_VP(HD_VECTOR3) *Vect0, register HD_VP(HD_VECTOR3) *Vect1)
{
  _HDM_Vect3_Diff(Res, Vect0, Vect1);
}


/**** Distance between two vectors ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_VECT3_FUNC(Dist)(register HD_VP(HD_VECTOR3) *Vect0, register HD_VP(HD_VECTOR3) *Vect1)
{
  register HD_FLOAT_INT     Dx, Dy, Dz;

  /**** Superscalar ****/

  Dx  = Vect0 -> Coord.x - Vect1 -> Coord.x;
  Dy  = Vect0 -> Coord.y - Vect1 -> Coord.y;
  Dz  = Vect0 -> Coord.z - Vect1 -> Coord.z;

  return (HD_FLOAT_INT)sqrt((double)(Dx * Dx + Dy * Dy + Dz * Dz));
}


/**** Dot product ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_VECT3_FUNC(DotProd)(register HD_VP(HD_VECTOR3) *Vect0, register HD_VP(HD_VECTOR3) *Vect1)
{
  return _HDM_Vect3_DotProd(Vect0, Vect1);
}


/**** Magnitude ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_VECT3_FUNC(Magnitude)(register HD_VP(HD_VECTOR3) *Vect0)
{
  return _HDM_Vect3_Magnitude(Vect0);
}


/**** Multiply a vector 3 by a constant ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_VECT3_FUNC(Mult)(register HD_VP(HD_VECTOR3) *Vect0, register HD_FLOAT_INT Const)
{
  _HDM_Vect3_Mult(Vect0, Const);
}


/**** Normalize a vector 3 ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_VECT3_FUNC(Norm)(register HD_VP(HD_VECTOR3) *Vect0)
{
#if defined(HD_USE_SSE) && defined(HD_SINGLE_PRECISION)
  if ((!Vect0 -> Coord.x) && (!Vect0 -> Coord.y) && (!Vect0 -> Coord.z)) {
    Vect0 -> Coord.x = HD_FP(0.0);
    Vect0 -> Coord.y = HD_FP(0.0);
    Vect0 -> Coord.z = HD_FP(0.0);
    return;
  }

  Vect0 -> Array[3] = 0.0f;
  SseVectNorm(Vect0 -> Array);

#else
  register HD_FLOAT_INT Len = Vect0 -> Coord.x * Vect0 -> Coord.x +
                              Vect0 -> Coord.y * Vect0 -> Coord.y +
                              Vect0 -> Coord.z * Vect0 -> Coord.z;

  if (Len > HD_FP(0.0)) {
    Len = (HD_FLOAT_INT)sqrt((double)Len);
    Vect0 -> Coord.x /= Len;
    Vect0 -> Coord.y /= Len;
    Vect0 -> Coord.z /= Len;
  } else {
    Vect0 -> Coord.x = HD_FP(0.0);
    Vect0 -> Coord.y = HD_FP(0.0);
    Vect0 -> Coord.z = HD_FP(0.0);
  }
#endif
}


/**** Rotate a vector around the X axis ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_VECT3_FUNC(RotX)(register HD_VP(HD_VECTOR3) *Vect0, HD_FLOAT_INT Rot)
{
  register HD_FLOAT_INT     CosAx, SinAx, T;

  Rot   *= HD_VP(HD_DEG_TO_RAD);
  CosAx  = (HD_FLOAT_INT)cos(Rot);
  SinAx  = (HD_FLOAT_INT)sin(Rot);

  T                 = Vect0 -> Coord.z * CosAx - Vect0 -> Coord.y * SinAx;
  Vect0 -> Coord.y  = Vect0 -> Coord.z * SinAx + Vect0 -> Coord.y * CosAx;
  Vect0 -> Coord.z  = T;
}


/**** Rotate a vector around the Y axis ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_VECT3_FUNC(RotY)(register HD_VP(HD_VECTOR3) *Vect0, HD_FLOAT_INT Rot)
{
  register HD_FLOAT_INT     CosAy, SinAy, T;

  Rot   *= HD_VP(HD_DEG_TO_RAD);
  CosAy  = (HD_FLOAT_INT)cos(Rot);
  SinAy  = (HD_FLOAT_INT)sin(Rot);

  T                 = Vect0 -> Coord.x * SinAy + Vect0 -> Coord.z * CosAy;
  Vect0 -> Coord.z  = Vect0 -> Coord.x * CosAy - Vect0 -> Coord.z * SinAy;
  Vect0 -> Coord.z  = T;
}


/**** Rotate a vector around the Z axis ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_VECT3_FUNC(RotZ)(register HD_VP(HD_VECTOR3) *Vect0, HD_FLOAT_INT Rot)
{
  register HD_FLOAT_INT     CosAz, SinAz, T;

  Rot   *= HD_VP(HD_DEG_TO_RAD);
  CosAz  = (HD_FLOAT_INT)cos(Rot);
  SinAz  = (HD_FLOAT_INT)sin(Rot);

  T                 = Vect0 -> Coord.x * CosAz - Vect0 -> Coord.y * SinAz;
  Vect0 -> Coord.y  = Vect0 -> Coord.x * SinAz + Vect0 -> Coord.y * CosAz;
  Vect0 -> Coord.x  = T;
}


/**** Set vector from HD_ATOM ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_VECT3_FUNC(SetAtm)(register HD_VP(HD_VECTOR3) *Dest, register HD_ATOM *Src)
{
  Dest -> Coord.x = (HD_FLOAT_INT)Src -> x;
  Dest -> Coord.y = (HD_FLOAT_INT)Src -> y;
  Dest -> Coord.z = (HD_FLOAT_INT)Src -> z;
}


/**** Square distance ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_VECT3_FUNC(SqDist)(register HD_VP(HD_VECTOR3) *Vect0, register HD_VP(HD_VECTOR3) *Vect1)
{
  register HD_FLOAT_INT     Dx, Dy, Dz;

  /**** Superscalar ****/

  Dx  = Vect0 -> Coord.x - Vect1 -> Coord.x;
  Dy  = Vect0 -> Coord.y - Vect1 -> Coord.y;
  Dz  = Vect0 -> Coord.z - Vect1 -> Coord.z;

  return (Dx * Dx + Dy * Dy + Dz * Dz);
}


/**** Vector sum Res = Vect0 + Vect1 ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_VECT3_FUNC(Sum)(register HD_VP(HD_VECTOR3) *Res, register HD_VP(HD_VECTOR3) *Vect0,
                                                       register HD_VP(HD_VECTOR3) *Vect1)
{
  _HDM_Vect3_Sum(Res, Vect0, Vect1);
}


/**** Calculate the signed volume given 4 vertex ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_VECT3_FUNC(Volume)(HD_VP(HD_VECTOR3) *Vect0, HD_VP(HD_VECTOR3) *Vect1,
                                                           HD_VP(HD_VECTOR3) *Vect2, HD_VP(HD_VECTOR3) *Vect3)
{
  HD_VP(HD_MTX3X3)      Mtx;

  _HDM_Vect3_Diff((HD_VP(HD_VECTOR3) *)Mtx.Ele[0], Vect1, Vect0);
  _HDM_Vect3_Diff((HD_VP(HD_VECTOR3) *)Mtx.Ele[1], Vect2, Vect0);
  _HDM_Vect3_Diff((HD_VP(HD_VECTOR3) *)Mtx.Ele[2], Vect3, Vect0);

  return HD_MTX3X3_FUNC(Determinant)(&Mtx);
}



/**** Multiply a vector 4 by a 4x4 matrix ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_VECT4_FUNCF(MultMtx4x4)(register HD_VP(HD_VECTOR4) *Res, register HD_VP(HD_VECTOR4) *Vect,
                                                   HD_VP(HD_MTX4X4) *Mtx)
{
  Res -> Array[0] = Vect -> Array[0] * Mtx -> Ele[0][0] + Vect -> Array[1] * Mtx -> Ele[1][0] + Vect -> Array[2] * Mtx -> Ele[2][0] + Vect -> Array[3] * Mtx -> Ele[3][0];
  Res -> Array[1] = Vect -> Array[0] * Mtx -> Ele[0][1] + Vect -> Array[1] * Mtx -> Ele[1][1] + Vect -> Array[2] * Mtx -> Ele[2][1] + Vect -> Array[3] * Mtx -> Ele[3][1];
  Res -> Array[2] = Vect -> Array[0] * Mtx -> Ele[0][2] + Vect -> Array[1] * Mtx -> Ele[1][2] + Vect -> Array[2] * Mtx -> Ele[2][2] + Vect -> Array[3] * Mtx -> Ele[3][2];
  Res -> Array[3] = Vect -> Array[0] * Mtx -> Ele[0][3] + Vect -> Array[1] * Mtx -> Ele[1][3] + Vect -> Array[2] * Mtx -> Ele[2][3] + Vect -> Array[3] * Mtx -> Ele[3][3];
}



/**** Ordinary Least Squares ****/

HDRIVE_EXTERN HD_BOOL HDRIVE_EXPORT HD_MTX_FUNC(Ols)(HD_FLOAT_INT *M, HD_FLOAT_INT *B, HD_FLOAT_INT *R, HD_VP(HD_MTX) X, HD_VP(HD_MTX) Y)
{
  HD_FLOAT_INT  nf, SumX, SumX2, SumXY, SumY, SumY2, Tmp;
  HD_ULONG      k, n;

  if ((!X) || (!Y) || (X -> Col != 1) || (Y -> Col != 1) ||
      (X -> Row != Y -> Row) || (!X -> Row) || ((!M) && (!B))) {
    GlobErrCode = HD_ERR_ILLPAR;
    return FALSE;
  }

  /**** Evaluate the mean values ****/

  n     =  X -> Row;
  SumX  = HD_FP(0.0);
  SumX2 = HD_FP(0.0);
  SumXY = HD_FP(0.0);
  SumY  = HD_FP(0.0);
  SumY2 = HD_FP(0.0);
  for(k = 0; k < n; ++k) {
    Tmp    =  X -> Data[k];
    SumX  += Tmp;
    SumX2 += Tmp * Tmp;
    SumXY += Tmp * Y -> Data[k];
    Tmp    = Y -> Data[k];
    SumY  += Tmp;
    SumY2 += Tmp * Tmp;
  } /* End of for (k) */

  nf = (HD_FLOAT_INT)n;
  if ((Tmp = nf * SumX2 - SumX * SumX) == HD_FP(0.0)) {
    if (M) *M = HD_FP(0.0);
    if (B) *B = HD_FP(0.0);
    if (R) *R = HD_FP(0.0);

    GlobErrCode = HD_ERR_NOTAVAILABLE;

    return FALSE;
  }

  if (M) *M = (nf   * SumXY - SumX * SumY ) / Tmp;
  if (B) *B = (SumY * SumX2 - SumX * SumXY) / Tmp;
  if (R) *R = (SumXY - SumX * SumY / nf) /
              (HD_FLOAT_INT)sqrt((SumX2 - SumX * SumX / nf) *
              (SumY2 - SumY * SumY / nf));

  GlobErrCode = HD_ERR_NONE;

  return TRUE;
}

#if 0
/**** Hierarchical clustering  ****/

HDRIVE_EXTERN HD_VP(HD_MTX) HDRIVE_EXPORT HD_MTX_FUNC(HierClust)(HD_VP(HD_MTX) Mtx, HD_ULONG ClustNum, HD_LONG Flags)
{
  HD_ULONG          k;
  HD_ULONG *        VectNum;

  HD_VP(HD_MTX)     InMtx, OutMtx;

  if ((!Mtx) || (Mtx -> Col != Mtx -> Row) ||
      (ClustNum < 2) || (ClustNum >= Mtx -> Col)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_NULL;
  }

  if ((VectNum = (HD_ULONG *)HD_Malloc(Mtx -> Col * sizeof(HD_ULONG))) == HD_NULL)
    return HD_NULL;

  for(k = 0; k < Mtx -> Col; ++k) VectNum[k] = 1;

  InMtx = Mtx;
  for(k = ClustNum; k < Mtx -> Col; ++k) {
    if ((OutMtx = HD_MTX_FUNC(HierClustNearest)(InMtx, VectNum)) == HD_NULL)
      goto ExitErr;
    InMtx = OutMtx;
  } /* End of for (k) */

  GlobErrCode = HD_ERR_NONE;

ExitErr:

  if (InMtx != Mtx) HD_MTX_FUNC(Free)(InMtx);
  HD_Free(VectNum);

  return OutMtx;
}


/**** Find the nearest value ****/

static HD_VP(HD_MTX) HD_FASTCALL HD_MTX_FUNC(HierClustNearest)(HD_VP(HD_MTX) InMtx, HD_ULONG *VectNum)
{
  HD_FLOAT_INT      MinVal, Val;
  HD_VP(HD_MTX)     OutMtx;
  HD_ULONG          r, c, MinC, MinR, OutC, OutR;

  if ((OutMtx = HD_MTX_FUNC(New)(InMtx -> Row - 1, InMtx -> Col - 1)) == HD_NULL)
    return HD_NULL;

  MinR   = 0;
  MinC   = 1;
  MinVal = HD_Mtx_Val(InMtx, 0, 1);

  /**** Find the nearest ****/

  for(r = 0; r < InMtx -> Row; ++r) {
    for(c = r + 1; c < InMtx -> Col; ++c) {
      Val = HD_Mtx_Val(InMtx, r, c) ;
      if (Val < MinVal) {
        MinVal = Val;
        MinR   = r;
        MinC   = c;
      }
    } /* End of for (c) */
  } /* End of for (r) */

  VectNum[MinR] += VectNum[MinC];
  for(c = MinC + 1; c < InMtx -> Col; ++c)
    VectNum[c - 1] = VectNum[c];

  /**** Clusterize the nearest ****/

  OutR = 0;
  for(r = 0; r < InMtx -> Row; ++r) {
    if (r == MinC) continue;
    OutC = r;
    for(c = OutC; c < InMtx -> Col; ++c) {
      if (c == MinC) continue;
      Val = HD_Mtx_Val(InMtx, r, c);

      if (c == MinR) {
        if (Val > HD_Mtx_Val(InMtx, r, MinC)) Val = HD_Mtx_Val(InMtx, r, MinC);
      } else if (r == MinR) {
        if (Val > HD_Mtx_Val(InMtx, MinC, c)) Val = HD_Mtx_Val(InMtx, MinC, c);
      }

      HD_Mtx_Val(OutMtx, OutR, OutC) = Val;
      HD_Mtx_Val(OutMtx, OutC, OutR) = Val;
      ++OutC;
    } /* End of for (c) */
    ++OutR;
  } /* End of for (r) */

  return OutMtx;
}
#endif
