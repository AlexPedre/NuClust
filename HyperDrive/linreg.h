
/************************************************
**** HyperDrive - Linear regression routines ****
****   (c) 2004-2025, Alessandro Pedretti    ****
************************************************/


/* http://www.codeproject.com/KB/recipes/LinReg.aspx */

#include "hdfloat.h"

/**** Rsq data ****/

typedef struct {
  HD_FLOAT_INT          Val;
  HD_ULONG              Col;
} HD_VP(HD_RSQ);

/**** Local prototypes ****/

static HD_FLOAT_INT             HD_FASTCALL HD_FP(HD_F2P_)(HD_FLOAT_INT F, HD_LONG Df1, HD_LONG Df2);
static HD_VP(HD_LINREGMOD)      HD_FASTCALL HD_FP(HD_LinRegModNew_)(HD_ULONG YNum, HD_ULONG VarNum, HD_LONG Flags);
static HD_VP(HD_LINREGMOD)      HD_FASTCALL HD_FP(HD_LinRegCalc_)(HD_VP(HD_MTX) X, HD_VP(HD_MTX) Y, HD_LONG Flags);
static HD_LONG                  HD_CALLBACK HD_FP(FcmpRsq)(const HD_VOID *V1, const HD_VOID *V2);
static double                   HD_FASTCALL LJspin(double q, HD_LONG i, HD_LONG j, HD_LONG b);
static HD_LONG                  HD_CALLBACK HD_FP(TH_RsqClac)(HD_VOID *HdtGlobVars);
static HD_LONG                  HD_CALLBACK HD_FP(TH_VifClac)(HD_VOID *HdtGlobVars);


/**** LJspin() ****/

#ifndef HD_SINGLE_PRECISION
static double HD_FASTCALL LJspin(register double q, register HD_LONG i, HD_LONG j, HD_LONG b)
{
  register double      zz = 1.0;
  register double      z  = 1.0;

  while(i <= j) {
    zz  = (zz * q * (double)i) / (double)(i - b);
    z  += zz;
    i  += 2;
  } /* End of while */

  return z;
}
#endif


/**** Calculate P from Fisher's F ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_FP(HD_F2P)(HD_FLOAT_INT F, HD_LONG Df1, HD_LONG Df2)
{
  if ((F < HD_FP(0.0)) || (Df1 < 0) || (Df2 < 0)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_FP(0.0);
  }

  GlobErrCode = HD_ERR_NONE;

  return HD_FP(HD_F2P_)(F, Df1, Df2);
}


/**** Calculate P from Fisher's F (internal) ****/

static HD_FLOAT_INT HD_FASTCALL HD_FP(HD_F2P_)(HD_FLOAT_INT F, HD_LONG Df1, HD_LONG Df2)
{
  double        a, c, Cot, Sat, Tan;
  HD_LONG       j, k;

  double        x = (double)Df2 / ((double)Df1 * F + (double)Df2);

  if ((Df1 % 2) == 0.0)
    return (LJspin(1.0 - x, Df2, Df1 + Df2 - 4, Df2 - 2) * pow(x, (double)Df2 / 2.0));

  if ((Df2 % 2) == 0.0)
    return (1.0 - LJspin(x, Df1, Df1 + Df2 - 4, Df1 - 2) * pow(1.0 - x, (double)Df1 / 2.0));

  Tan = atan(sqrt(((double)Df1 * F) / (double)Df2));
  a   = Tan / HD_PI_2;
  Sat = sin(Tan);
  Cot = cos(Tan);

  if (Df2 >  1) a = a + (Sat * Cot * LJspin(Cot * Cot, 2, Df2 - 3, -1)) / HD_PI_2;
  if (Df1 == 1) return (1.0 - a);

  c = 4.0 * LJspin(Sat * Sat, Df2 + 1, Df1 + Df2 - 4, Df2 - 2) * Sat * pow(Cot, (double)Df2) / HD_PI;

  if (Df2 == 1) return (1.0 - a + c / 2.0);

  j = (Df2 - 1) >> 1;
  for(k = 2; k <= j; ++ k)
    c = (c * (double)k) / ((double)k - 0.5);

  return (1.0 - a + c);
}


/**** Forward selection ****/

HDRIVE_EXTERN HD_VP(HD_LINREGMOD) HDRIVE_EXPORT HD_FP(HD_LinRegFrwSel)(HD_VP(HD_MTX) X, HD_VP(HD_MTX) Y)
{
  HDT_BEGIN
    HD_VP(HD_RSQ) *     Rsq;
    HD_VP(HD_MTX)       X, Y;
    HD_ULONG            Threads;
  HDT_END

  HD_BOOL               Ret;
  HD_FLOAT_INT          *Dest, *Src;
  HD_ULONG              k, i, j;

  HD_VP(HD_LINREGMOD)   NewModel;

  HD_VP(HD_LINREGMOD)   Model = HD_NULL;
  HD_VP(HD_MTX)         NewX  = HD_NULL;

  HDT_AllocGlobVarsInt();

  if ((!X) || (!Y) || (Y -> Col != 1) || (X -> Row != Y -> Row)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_NULL;
  }

  if ((HDT_GetVar(Rsq) = (HD_VP(HD_RSQ) *)HD_Malloc(sizeof(HD_VP(HD_RSQ)) * X -> Col)) == HD_NULL)
    return HD_NULL;

  /**** Calculate the Rsq for each regressor ****/

  HDT_GetVar(X)       = X;
  HDT_GetVar(Y)       = Y;
  HDT_GetVar(Threads) = HD_MthThreads();

  if (HDT_GetVar(Threads) > X -> Col) HDT_GetVar(Threads) = X -> Col;

  if (MthThreads > 1) {
    Ret = !HD_MthCreateThreads(HDT_GetVar(Threads), HD_FP(TH_RsqClac), &HdtGlobVars, HD_MTH_THREADS_WAIT);
    HDT_FreeGlobVarsInt();
  } else {
    Ret = !HD_FP(TH_RsqClac)(&HdtGlobVars);
  }

  /**** Sort the Rsq ****/

  if (Ret) {
    HD_Qsort(HDT_GetVar(Rsq), X -> Col, sizeof(HD_VP(HD_RSQ)), HD_FP(FcmpRsq));

    for(k = 0; k < X -> Col; ++k) {
      if (!k) {
        if ((NewX = HD_MTX_FUNC(New)(1, X -> Row)) == HD_NULL) return HD_NULL;
        Dest = NewX -> Data;
        Src  = X   -> Data;
        for(i = 0; i < X -> Row; ++i) {
          for(j = 0; j < X -> Col; ++j) {
            if (j != HDT_GetVar(Rsq) -> Col) *Dest++ = *Src;
            ++Src;
          } /* End of for (j) */
        } /* End of for (i) */
      }
      if ((NewModel = HD_FP(HD_LinRegCalc_)(NewX, Y, HD_LINREG_CALC_ALL)) == HD_NULL) {
        HD_FP(HD_LinRegModFree)(Model);
        break;
      }

      HD_FP(HD_LinRegModFree)(Model);
      Model = NewModel;
    } /* End of for (k) */
  }

  HD_Free(HDT_GetVar(Rsq));
  HD_MTX_FUNC(Free)(NewX);

  return Model;
}


/**** Linear regression ****/

HDRIVE_EXTERN HD_VP(HD_LINREGMOD) HDRIVE_EXPORT HD_FP(HD_LinRegCalc)(HD_VP(HD_MTX) X, HD_VP(HD_MTX) Y)
{
  return HD_FP(HD_LinRegCalcEx)(X, Y, HD_LINREG_CALC_ALL);
}


/**** Linear regression (Extended version) ****/

HDRIVE_EXTERN HD_VP(HD_LINREGMOD) HDRIVE_EXPORT HD_FP(HD_LinRegCalcEx)(HD_VP(HD_MTX) X, HD_VP(HD_MTX) Y, HD_LONG Flags)
{
  HD_VP(HD_LINREGMOD)   Model;

  if ((!X) || (!Y) || (Y -> Col != 1) || (X -> Row != Y -> Row)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_NULL;
  }

  if ((Model = HD_FP(HD_LinRegCalc_)(X, Y, Flags)) == HD_NULL)
    return HD_NULL;

  /**** Check the collinearity ****/

  if ((X -> Col > 1) && (Flags & HD_LINREG_CALC_VIF)) {
    HD_BOOL                     Ret;

    HDT_BEGIN
      HD_VP(HD_LINREGMOD)       Model;
      HD_VP(HD_MTX)             X;
      HD_ULONG                  Threads;
    HDT_END

    HDT_AllocGlobVarsInt();

    HDT_GetVar(Model)   = Model;
    HDT_GetVar(X)       = X;
    HDT_GetVar(Threads) = HD_MthThreads();

    if (HDT_GetVar(Threads) > X -> Col) HDT_GetVar(Threads) = X -> Col;

    if (MthThreads > 1) {
      Ret = !HD_MthCreateThreads(HDT_GetVar(Threads), HD_FP(TH_VifClac), &HdtGlobVars, HD_MTH_THREADS_WAIT);
      HDT_FreeGlobVarsInt();
    } else {
      Ret = !HD_FP(TH_VifClac)(&HdtGlobVars);
    }

    if (!Ret) {
      HD_FP(HD_LinRegModFree)(Model);
      return HD_NULL;
    }
  }

  GlobErrCode = HD_ERR_NONE;

  return Model;
}


/**** Calculate the values of the dependent variable ****/

HDRIVE_EXTERN HD_VP(HD_MTX) HDRIVE_EXPORT HD_FP(HD_LinRegCalcDepVar)(HD_VP(HD_LINREGMOD) Model, HD_VP(HD_MTX) X)
{
  HD_FLOAT_INT              YCalc;
  HD_VP(HD_MTX)         Res;
  HD_ULONG              i, k;

  if ((!Model) || (!X) || (!X -> Row)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_NULL;
  }

  if ((Res = HD_MTX_FUNC(New)(1, X -> Row)) == HD_NULL)
    return HD_NULL;

  for(k = 0; k < X -> Row; ++k) {
    YCalc = *Model -> Coeff;
    for(i = 1; i < Model -> XNum; ++i)
      YCalc += Model -> Coeff[i] * HD_MTX_VAL(X, k, i - 1);
    Res -> Data[k] = YCalc;
  } /* End of for (k) */

  GlobErrCode = HD_ERR_NONE;

  return Res;
}


/**** Linear regression (internal) ****/

static HD_VP(HD_LINREGMOD) HD_FASTCALL HD_FP(HD_LinRegCalc_)(HD_VP(HD_MTX) X, HD_VP(HD_MTX) Y, HD_LONG Flags)
{
  HD_FLOAT_INT          *B, *Dest, *Src;
  HD_FLOAT_INT          Sum;
  HD_VP(HD_LINREGMOD)   Model;
  HD_VP(HD_MTX)         P, X1;
  HD_ULONG              i, j, k;
  HD_ULONG              M;      /* Number of independent variables (XNum) */
  HD_ULONG              N;      /* Number of data points           (YNum) */

  M = X -> Col + 1;
  N = Y -> Row;

  /**** Check the number of degree of freedom ****/

  if (N - M < 1) {
    GlobErrCode = HD_ERR_LINREG_NODATA;
    return HD_NULL;
  }

  Model = HD_FP(HD_LinRegModNew_)(N, M, Flags);
  B     = (HD_FLOAT_INT *)HD_Calloc(sizeof(HD_FLOAT_INT) * M);
  P     = HD_MTX_FUNC(New)(M, M);
  X1    = HD_MTX_FUNC(New)(X -> Col + 1, X -> Row);

  if ((!Model) || (!B) || (!P) || (!X1)) {
    HD_FP(HD_LinRegModFree)(Model);
    return HD_NULL;
  }

  /**** Fill the independent variables matrix ****/

  Dest = X1 -> Data;
  Src  = X  -> Data;
  for(i = 0; i < X1 -> Row; ++i) {
    for(j = 0; j < X1 -> Col; ++j) {
      if (!j) *Dest = HD_FP(1.0);
      else *Dest = *Src++;
      ++Dest;
    } /* End of for (j) */
  } /* End of for (i) */

  /**** Build B and P matrix ****/

  for(i = 0; i < M; ++i) {
    for(j = 0; j < M; ++j) {
      Sum = HD_FP(0.0);
      for(k = 0; k < N; ++k) Sum += HD_MTX_VAL(X1, k, i) * HD_MTX_VAL(X1, k, j);
      HD_MTX_VAL(P, j, i) = Sum;
    } /* End of for (j) */

    Sum = HD_FP(0.0);
    for(k = 0; k < N; ++k) Sum += HD_MTX_VAL(X1, k, i) * Y -> Data[k];
    B[i] = Sum;
  } /* End of for (i) */

  if (HD_MTX_FUNC(SymmetricInverse)(Model -> VarCovar, P)) {
    HD_FLOAT_INT SSQ, YCalc;

    HD_FLOAT_INT TSS  = HD_FP(0.0);  /* Total Sum of Squares */
    HD_FLOAT_INT RSS  = HD_FP(0.0);  /* Residual Sum of Squares */
    HD_FLOAT_INT YBAR = HD_FP(0.0);  /* Average value of Y */

    /**** Get the coefficients ****/

    for(i = 0; i < M; ++i) {
      for(j = 0; j < M; ++j)
        Model -> Coeff[i] += HD_MTX_VAL(Model -> VarCovar, j, i) * B[j];
    } /* End of for (i) */

    /**** Calculate the statistics ****/

    for(k = 0; k < N; ++k)
      YBAR += Y -> Data[k];
    YBAR /= (HD_FLOAT_INT)N;

    /**** Calculate the Y values ****/

    for(k = 0; k < N; ++k) {
      YCalc = HD_FP(0.0);
      for(i = 0; i < Model -> XNum; ++i)
        YCalc += Model -> Coeff[i] * HD_MTX_VAL(X1, k, i);

      /**** Residual = observed - predicted ****/

      SSQ = Y -> Data[k] - YCalc;
      if (Flags & HD_LINREG_CALC_DELTAY) Model -> DeltaY[k] = SSQ;
      if (Flags & HD_LINREG_CALC_Y     ) Model -> YCalc[k]  = YCalc;

      RSS += SSQ * SSQ;
      SSQ  = Y -> Data[k] - YBAR;
      TSS += SSQ * SSQ;
    } /* End of for (k) */

    SSQ             = RSS / (HD_FLOAT_INT)Model -> Ndf;
    Model -> PC     = (RSS * (HD_FLOAT_INT)(N + M - 2)) / (HD_FLOAT_INT)(N - M + 2);
    Model -> Rsq    = HD_FP(1.0) - RSS / TSS;
    Model -> RsqAdj = HD_FP(1.0) - (HD_FP(1.0) - Model -> Rsq) * (N - 1) / (N - M - 2);
    Model -> F      = HD_FP(9999999.0);
    if (Model -> Rsq < HD_FP(0.9999999))
      Model -> F = Model -> Rsq / (HD_FP(1.0) - Model -> Rsq) * (HD_FLOAT_INT)Model -> Ndf / (M - 1);
    Model -> P           = HD_FP(HD_F2P)(Model -> F, M - 1, Model -> Ndf);
    Model -> StdDevCoeff = (HD_FLOAT_INT)sqrt(SSQ);

    /**** Calculate var-covar matrix and std error of coefficients ****/

    if (Flags & HD_LINREG_CALC_VARCOVAR) {
      for(i = 0; i < Model -> XNum; ++i) {
        for(j = 0; j < Model -> XNum; ++j)
          HD_MTX_VAL(Model -> VarCovar, j, i) *= SSQ;
        Model -> StdErrCoeff[i] = (HD_FLOAT_INT)sqrt(HD_MTX_VAL(Model -> VarCovar, i, i));
      } /* End of for (i) */
    } else {
      HD_MTX_FUNC(Free)(Model -> VarCovar);
      Model -> VarCovar = HD_NULL;
    }
  } else {
    HD_FP(HD_LinRegModFree)(Model);
    Model = HD_NULL;
  }
  HD_MTX_FUNC(Free)(X1);
  HD_MTX_FUNC(Free)(P);
  HD_Free(B);

  return Model;
}


/**** Free the linear regression model ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_FP(HD_LinRegModFree)(HD_VP(HD_LINREGMOD) Model)
{
  if (!Model) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  HD_MTX_FUNC(Free)(Model -> VarCovar);
  HD_FreeSafe(Model -> Coeff      );
  HD_FreeSafe(Model -> DeltaY     );
  HD_FreeSafe(Model -> StdErrCoeff);
  HD_FreeSafe(Model -> VIF        );
  HD_FreeSafe(Model -> YCalc      );
  HD_Free(Model);
  GlobErrCode = HD_ERR_NONE;
}


/**** Allocate the linear regression model ****/

static HD_VP(HD_LINREGMOD) HD_FASTCALL HD_FP(HD_LinRegModNew_)(HD_ULONG YNum, HD_ULONG XNum, HD_LONG Flags)
{
  HD_VP(HD_LINREGMOD)   Model;

  if ((Model = (HD_VP(HD_LINREGMOD))HD_Calloc(sizeof(struct HD_FP(_hd_linregmod)))) != HD_NULL) {
    if (((Flags & HD_LINREG_CALC_DELTAY  ) && ((Model -> DeltaY      = (HD_FLOAT_INT *)HD_Calloc(sizeof(HD_FLOAT_INT) * YNum)) == HD_NULL)) ||
        ((Flags & HD_LINREG_CALC_VARCOVAR) && ((Model -> StdErrCoeff = (HD_FLOAT_INT *)HD_Calloc(sizeof(HD_FLOAT_INT) * XNum)) == HD_NULL)) ||
        ((Flags & HD_LINREG_CALC_VIF     ) && ((Model -> VIF         = (HD_FLOAT_INT *)HD_Calloc(sizeof(HD_FLOAT_INT) * XNum)) == HD_NULL)) ||
        ((Flags & HD_LINREG_CALC_Y       ) && ((Model -> YCalc       = (HD_FLOAT_INT *)HD_Calloc(sizeof(HD_FLOAT_INT) * YNum)) == HD_NULL)) ||
        ((Model -> Coeff       = (HD_FLOAT_INT *)HD_Calloc(sizeof(HD_FLOAT_INT) * XNum)) == HD_NULL) ||
        ((Model -> VarCovar    = HD_MTX_FUNC(New)(XNum, XNum)) == HD_NULL)) {
      HD_FP(HD_LinRegModFree)(Model);
      return HD_NULL;
    }

    Model -> Ndf   = YNum - XNum;
    Model -> XNum  = XNum;
    Model -> YNum  = YNum;
    GlobErrCode    = HD_ERR_NONE;
  }

  return Model;
}


/**** Evaluate the residual errors of a test set ****/

HDRIVE_EXTERN HD_VP(HD_MTX) HDRIVE_EXPORT HD_FP(HD_LinRegResidual)(HD_VP(HD_LINREGMOD) Model, HD_VP(HD_MTX) X, HD_VP(HD_MTX) Y)
{
  HD_FLOAT_INT          YCalc;
  HD_VP(HD_MTX)         Res;
  HD_ULONG              i, k;

  if ((!Model) || (!X) || (!Y) || (Y -> Col != 1) || (X -> Row != Y -> Row)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_NULL;
  }

  if ((Res = HD_MTX_FUNC(New)(1, X -> Row)) == HD_NULL)
    return HD_NULL;

  for(k = 0; k < X -> Row; ++k) {
    YCalc = *Model -> Coeff;
    for(i = 1; i < Model -> XNum; ++i)
      YCalc += Model -> Coeff[i] * HD_MTX_VAL(X, k, i - 1);
    Res -> Data[k] = Y -> Data[k] - YCalc;
  } /* End of for (k) */

  GlobErrCode = HD_ERR_NONE;

  return Res;
}


/**** Callback to sort the Rsq ****/

static HD_LONG HD_CALLBACK HD_FP(FcmpRsq)(const HD_VOID *V1, const HD_VOID *V2)
{
  if (((HD_VP(HD_RSQ) *)V1) -> Val > ((HD_VP(HD_RSQ) *)V2) -> Val) return 1;
  else if (((HD_VP(HD_RSQ) *)V1) -> Val < ((HD_VP(HD_RSQ) *)V2) -> Val) return -1;

  return 0;
}


/**** Calculate the Rsq of each regressor ****/

static HD_LONG HD_CALLBACK HD_FP(TH_RsqClac)(HD_VOID *HdtGlobVars)
{
  HDT_BEGIN
    HD_VP(HD_RSQ) *     Rsq;
    HD_VP(HD_MTX)       X, Y;
    HD_ULONG            Threads;
  HDT_END

  HD_VP(HD_MTX)         RsqX;
  HD_VP(HD_LINREGMOD)   Model;
  HD_FLOAT_INT              *DestX, *Src;
  HD_ULONG              i, j, k, ThreadID;

  HDT_ObtainThIDInt(ThreadID);

  /**** Allocate the X matrix ****/

  if ((RsqX = HD_MTX_FUNC(New)(1, HDT_GetVarTh(X) -> Row)) == HD_NULL)
    return TRUE;

  for(k = ThreadID - 1; k < HDT_GetVarTh(X) -> Col; k += HDT_GetVarTh(Threads)) {
    DestX = RsqX            -> Data;
    Src   = HDT_GetVarTh(X) -> Data;
    for(i = 0; i < HDT_GetVarTh(X) -> Row; ++i) {
      for(j = 0; j < HDT_GetVarTh(X) -> Col; ++j) {
        if (j == k) *DestX++ = *Src;
        ++Src;
      } /* End of for (j) */
    } /* End of for (i) */

    if ((Model = HD_FP(HD_LinRegCalc_)(RsqX, HDT_GetVarTh(Y), HD_LINREG_CALC_NONE)) == HD_NULL)
      return FALSE;

    HDT_GetVarTh(Rsq)[k].Val = Model -> Rsq;
    HD_FP(HD_LinRegModFree)(Model);
  } /* End of for (k) */
  HD_MTX_FUNC(Free)(RsqX);

  return FALSE;
}


/**** VIF calculation thread ****/

static HD_LONG HD_CALLBACK HD_FP(TH_VifClac)(HD_VOID *HdtGlobVars)
{
  HDT_BEGIN
    HD_VP(HD_LINREGMOD) Model;
    HD_VP(HD_MTX)       X;
    HD_ULONG            Threads;
  HDT_END

  HD_VP(HD_MTX)         VifX, VifY;
  HD_VP(HD_LINREGMOD)   VifModel;
  HD_FLOAT_INT          *DestX, *DestY, *Src;
  HD_ULONG              i, j, k, ThreadID;

  HDT_ObtainThIDInt(ThreadID);

  /**** Allocate the X matrix ****/

  if ((VifX = HD_MTX_FUNC(New)(HDT_GetVarTh(X) -> Col - 1, HDT_GetVarTh(X) -> Row)) == HD_NULL)
    return TRUE;

  /**** Allocate the Y matrix ****/

  if ((VifY = HD_MTX_FUNC(New)(1, HDT_GetVarTh(X) -> Row)) == HD_NULL) {
    HD_MTX_FUNC(Free)(VifX);
    return TRUE;
  }

  for(k = ThreadID - 1; k < HDT_GetVarTh(X) -> Col; k += HDT_GetVarTh(Threads)) {
    DestX = VifX            -> Data;
    DestY = VifY            -> Data;
    Src   = HDT_GetVarTh(X) -> Data;
    for(i = 0; i < HDT_GetVarTh(X) -> Row; ++i) {
      for(j = 0; j < HDT_GetVarTh(X) -> Col; ++j) {
        if (j != k) *DestX++ = *Src;
        else *DestY++ = *Src;
        ++Src;
      } /* End of for (j) */
    } /* End of for (i) */

    if ((VifModel = HD_FP(HD_LinRegCalc_)(VifX, VifY, HD_LINREG_CALC_NONE)) == HD_NULL)
      return FALSE;

    HDT_GetVarTh(Model) -> VIF[k + 1]    = HD_FP(1.0) / (HD_FP(1.0) - VifModel -> Rsq);
    HD_FP(HD_LinRegModFree)(VifModel);
  } /* End of for (k) */
  HD_MTX_FUNC(Free)(VifX);
  HD_MTX_FUNC(Free)(VifY);

  return FALSE;
}


/**** Calculate Fisher's F from R^2 ****/

/* Rsq = R^2
 * n   = number of observations
 * k   = number of regressors
 */

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_FP(HD_Rsq2F)(HD_FLOAT_INT Rsq, HD_LONG n, HD_LONG k)
{
  if ((Rsq < HD_FP(0.0)) || (n < 0) || (k < 0)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_FP(0.0);
  }

  GlobErrCode = HD_ERR_NONE;

  if (((n - k - 1) > 0) && Rsq < HD_FP(1.0))
    return (Rsq / (HD_FLOAT_INT)k) / (((HD_FP(1.0) - Rsq)) / (HD_FLOAT_INT)(n - k - 1));

  return HD_FP(9999999.0);
}
