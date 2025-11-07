
/************************************************
****     HyperDrive - Satistic functions     ****
****   (c) 2004-2025, Alessandro Pedretti    ****
************************************************/


#include "hdfloat.h"

/**** Local prototypes ****/

static HD_LONG          HD_CALLBACK HD_FP(MedianSortFunc)(const HD_VOID *V1, const HD_VOID *V2);
static HD_FLOAT_INT     HD_FASTCALL HD_FP(Variance)(HD_FLOAT_INT *Vect, HD_ULONG Num);
static HD_FLOAT_INT     HD_FASTCALL HD_FP(VarianceBc)(HD_FLOAT_INT *Vect, HD_ULONG Num);


/**** Kurtosis ****/

/*
 * http://office.microsoft.com/it-it/excel-help/funzione-curtosi-HP010062513.aspx
 */

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_FP(HD_Kurtosis)(HD_FLOAT_INT *Vect, HD_ULONG Num)
{
  HD_FLOAT_INT          Int, Numf, Numf1, Sum, SumSq, Tmp;
  register HD_FLOAT_INT *Ptr;
  register HD_ULONG     k;

  if ((!Vect) || (Num < 4)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_FP(0.0);
  }

  Numf  = (HD_FLOAT_INT)Num;
  Sum   = HD_FP(0.0);
  SumSq = HD_FP(0.0);
  Int   = HD_FP(0.0);

  /**** Mean value ****/

  for(k = 0, Ptr = Vect; k < Num; ++k, ++Ptr)
    Sum += *Ptr;
  Sum /= Numf;

  /**** Unbiased standard deviation ****/

  for(k = 0, Ptr = Vect; k < Num; ++k, ++Ptr) {
    Tmp    = ((double)*Ptr - Sum);
    SumSq += Tmp * Tmp;
  } /* End of for (k, Ptr) */
  SumSq  = sqrt(SumSq / (Numf - HD_FP(1.0)));

  if (SumSq == HD_FP(0.0)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_FP(0.0);
  }

  for(k = 0, Ptr = Vect; k < Num; ++k, ++Ptr) {
    Tmp = (*Ptr - Sum) / SumSq;
    Int += Tmp * Tmp * Tmp * Tmp;
  } /* End of for (k , Ptr) */

  GlobErrCode = HD_ERR_NONE;
  Numf1       = Numf - HD_FP(1.0);
  Tmp = (Numf - HD_FP(2.0)) * (Numf - HD_FP(3.0));

  return ((Numf * (Numf + HD_FP(1.0))) / (Numf1 * Tmp)) * Int -
         ((HD_FP(3.0) * Numf1 * Numf1) / Tmp);
}


/**** Maximum value ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_FP(HD_Max)(HD_FLOAT_INT *Vect, HD_ULONG Num)
{
  register HD_FLOAT_INT Max;
  register HD_ULONG     k;

  if ((!Vect) || (!Num)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_FP(0.0);
  }

  GlobErrCode = HD_ERR_NONE;

  Max  = *Vect;
  ++Vect;
  for(k = 1; k < Num; ++k) {
    if (*Vect > Max) Max = *Vect;
    ++Vect;
  } /* End of for (k) */

  return Max;
}


/**** Aritmetic mean ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_FP(HD_Mean)(HD_FLOAT_INT *Vect, HD_ULONG Num)
{
  register HD_FLOAT_INT Sum;
  register HD_ULONG     k;

  if ((!Vect) || (!Num)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_FP(0.0);
  }

  GlobErrCode = HD_ERR_NONE;

  Sum  = HD_FP(0.0);
  for(k = 0; k < Num; ++k) {
    Sum  += *Vect;
    ++Vect;
  } /* End of for (k) */

  return (HD_FLOAT_INT)(Sum / (HD_FLOAT_INT)Num);
}


/**** Geometric mean ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_FP(HD_MeanGeo)(HD_FLOAT_INT *Vect, HD_ULONG Num)
{
  register HD_FLOAT_INT Prod;
  register HD_ULONG     k;

  if ((!Vect) || (!Num)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_FP(0.0);
  }

  GlobErrCode = HD_ERR_NONE;

  Prod = HD_FP(0.0);
  for(k = 0; k < Num; ++k) {
    Prod *= *Vect;
    ++Vect;
  } /* End of for (k) */

  return (HD_FLOAT_INT)pow(Prod, HD_FP(1.0) /(HD_FLOAT_INT)Num);
}


/**** Harmonic mean ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_FP(HD_MeanHarm)(HD_FLOAT_INT *Vect, HD_ULONG Num)
{
  register HD_FLOAT_INT RecSum;
  register HD_ULONG     k;

  if ((!Vect) || (!Num)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_FP(0.0);
  }

  GlobErrCode = HD_ERR_NONE;

  RecSum = HD_FP(0.0);
  for(k = 0; k < Num; ++k) {
    RecSum += HD_FP(1.0) / *Vect;
    ++Vect;
  } /* End of for (k) */

  return (HD_FLOAT_INT)Num / RecSum;
}


/**** Quadratic mean ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_FP(HD_MeanQuad)(HD_FLOAT_INT *Vect, HD_ULONG Num)
{
  register HD_FLOAT_INT SqSum;
  register HD_ULONG     k;

  if ((!Vect) || (!Num)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_FP(0.0);
  }

  GlobErrCode = HD_ERR_NONE;

  SqSum = HD_FP(0.0);
  for(k = 0; k < Num; ++k) {
    SqSum += *Vect * *Vect;
    ++Vect;
  } /* End of for (k) */

  return (HD_FLOAT_INT)sqrt(SqSum / (HD_FLOAT_INT)Num);
}


/**** Median ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_FP(HD_Median)(HD_FLOAT_INT *Vect, HD_ULONG Num)
{
  HD_FLOAT_INT *    VectSort;
  HD_FLOAT_INT      Median;

  if ((!Vect) || (!Num)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_FP(0.0);
  }

  GlobErrCode = HD_ERR_NONE;

  if (Num == 1) return *Vect;
  if (Num == 2) return (Vect[0] + Vect[1]) / HD_FP(2.0);

  if ((VectSort = (HD_FLOAT_INT *)HD_Malloc(sizeof(HD_FLOAT_INT) * Num)) == HD_NULL)
    return HD_FP(0.0);

  HD_MemCpy(VectSort, Vect, sizeof(HD_FLOAT_INT) * Num);
  HD_Qsort(VectSort, Num, sizeof(HD_FLOAT_INT),  HD_FP(MedianSortFunc));

  if (Num % 2) Median = VectSort[Num >> 1];
  else {
    Num >>= 1;
    Median =  (VectSort[Num] + VectSort[Num + 1]) / HD_FP(2.0);
  }

  HD_Free(VectSort);

  return Median;
}


/**** Median sort function ****/

static HD_LONG HD_CALLBACK HD_FP(MedianSortFunc)(const HD_VOID *V1, const HD_VOID *V2)
{
  double  Val1 = *(double *)V1;
  double  Val2 = *(double *)V2;

  if (Val1 > Val2) return -1;
  if (Val1 < Val2) return 1;

  return 0;
}


/**** Minimum value ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_FP(HD_Min)(HD_FLOAT_INT *Vect, HD_ULONG Num)
{
  register HD_FLOAT_INT Min;
  register HD_ULONG     k;

  if ((!Vect) || (!Num)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_FP(0.0);
  }

  GlobErrCode = HD_ERR_NONE;

  Min  = *Vect;
  ++Vect;
  for(k = 1; k < Num; ++k) {
    if (*Vect > Min) Min = *Vect;
    ++Vect;
  } /* End of for (k) */

  return Min;
}


/**** Range ****/

HDRIVE_EXTERN HD_BOOL HDRIVE_EXPORT HD_FP(HD_Range)(HD_FLOAT_INT *Min, HD_FLOAT_INT *Max, HD_FLOAT_INT *Vect, HD_ULONG Num)
{
  register HD_FLOAT_INT MinVal, MaxVal;
  register HD_ULONG     k;

  if ((!Vect) || (!Num)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return FALSE;
  }

  GlobErrCode = HD_ERR_NONE;

  MinVal = MaxVal = Vect[0];
  for(k = 0; k < Num; ++k) {
    if (*Vect < MinVal) MinVal = *Vect;
    else if (*Vect > MaxVal) MaxVal = *Vect;
    ++Vect;
  } /* End of for (k) */

  *Min = MinVal;
  *Max = MaxVal;

  return TRUE;
}


/**** Calculate the skewness ****/

/*
 * http://en.wikipedia.org/wiki/Skewness
 * http://office.microsoft.com/en-us/excel-help/skew-HP005209261.aspx
 */

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_FP(HD_Skewness)(HD_FLOAT_INT *Vect, HD_ULONG Num)
{
  HD_FLOAT_INT          Int, Numf, Sum, SumSq, Tmp;
  register HD_FLOAT_INT *Ptr;
  register HD_ULONG     k;

  if ((!Vect) || (Num < 4)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_FP(0.0);
  }

  Numf  = (HD_FLOAT_INT)Num;
  Sum   = HD_FP(0.0);
  SumSq = HD_FP(0.0);
  Int   = HD_FP(0.0);

  /**** Mean value ****/

  for(k = 0, Ptr = Vect; k < Num; ++k, ++Ptr)
    Sum += *Ptr;
  Sum /= Numf;

  /**** Unbiased standard deviation ****/

  for(k = 0, Ptr = Vect; k < Num; ++k, ++Ptr) {
    Tmp    = ((double)*Ptr - Sum);
    SumSq += Tmp * Tmp;
  } /* End of for (k, Ptr) */
  SumSq  = sqrt(SumSq / (Numf - HD_FP(1.0)));

  if (SumSq == HD_FP(0.0)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_FP(0.0);
  }

  for(k = 0, Ptr = Vect; k < Num; ++k, ++Ptr) {
    Tmp  = (*Ptr - Sum) / SumSq;
    Int += Tmp * Tmp * Tmp;
  } /* End of for (k , Ptr) */

  GlobErrCode = HD_ERR_NONE;


  return (Numf / ((Numf - 1.0) * (Numf - 2.0))) * Int;
}


/**** Standard deviation ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_FP(HD_StdDev)(HD_FLOAT_INT *Vect, HD_ULONG Num)
{
  HD_FLOAT_INT    Var;

  if ((!Vect) || (!Num)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_FP(0.0);
  }

  GlobErrCode = HD_ERR_NONE;
  Var         = HD_FP(Variance)(Vect, Num);

  if (Var < HD_FP(0.0)) return HD_FP(0.0);

  return (HD_FLOAT_INT)sqrt(Var);
}


/**** Standard deviation with Bessel's correction ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_FP(HD_StdDevBc)(HD_FLOAT_INT *Vect, HD_ULONG Num)
{
  if ((!Vect) || (!Num)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_FP(0.0);
  }

  GlobErrCode = HD_ERR_NONE;

  return (HD_FLOAT_INT)sqrt(HD_FP(VarianceBc)(Vect, Num));
}


/**** Variance ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_FP(HD_Variance)(HD_FLOAT_INT *Vect, HD_ULONG Num)
{
  if ((!Vect) || (!Num)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_FP(0.0);
  }

  GlobErrCode = HD_ERR_NONE;

  return HD_FP(Variance)(Vect, Num);
}


/**** Variance with Bessel's correction ****/

HDRIVE_EXTERN HD_FLOAT_INT HDRIVE_EXPORT HD_FP(HD_VarianceBc)(HD_FLOAT_INT *Vect, HD_ULONG Num)
{
  if ((!Vect) || (!Num)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_FP(0.0);
  }

  GlobErrCode = HD_ERR_NONE;

  return HD_FP(VarianceBc)(Vect, Num);
}


/**** Variance (internal) ****/

static HD_FLOAT_INT HD_FASTCALL HD_FP(Variance)(HD_FLOAT_INT *Vect, HD_ULONG Num)
{
  register HD_FLOAT_INT NumF, Sum, Sum2;
  register HD_ULONG     k;

  Sum  = HD_FP(0.0);
  Sum2 = HD_FP(0.0);
  for(k = 0; k < Num; ++k) {
    Sum  += *Vect;
    Sum2 += *Vect * *Vect;
    ++Vect;
  } /* End of for (k) */

  NumF  = (HD_FLOAT_INT)Num;
  Sum  /= NumF;

  return (Sum2 / NumF - Sum * Sum);
}


/**** Variance with Bessel's correction (internal) ****/

static HD_FLOAT_INT HD_FASTCALL HD_FP(VarianceBc)(HD_FLOAT_INT *Vect, HD_ULONG Num)
{
  register HD_FLOAT_INT Tmp;
  register HD_ULONG     k;

  register HD_FLOAT_INT     NumF  = (HD_FLOAT_INT)Num;
  register HD_FLOAT_INT     Sum   = HD_FP(0.0);
  register HD_FLOAT_INT     Sum2  = HD_FP(0.0);

  for(k = 0; k < Num; ++k) Sum += Vect[k];
  Sum /= NumF;

  for(k = 0; k < Num; ++k) {
    Tmp   = Vect[k] - Sum;
    Sum2 += Tmp * Tmp;
  } /* End of for (k) */

  return (Sum2 / (NumF - HD_FP(1.0)));
}
