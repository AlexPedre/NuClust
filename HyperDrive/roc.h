
/*******************************************
****     HyperDrive - ROC routines      ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#include "hdfloat.h"

/**** ROC data structure ****/

typedef struct {
  HD_FLOAT_INT  Act;            /* Activity vector              */
  HD_FLOAT_INT  Ind;            /* Indicator variable vector    */
  HD_FLOAT_INT  Fpr;            /* False positive rate          */
  HD_FLOAT_INT  Tpr;            /* True positive rate           */
  HD_ULONG      Index;          /* Index                        */
  HD_LONG       Exceed;         /* Act exceeed the treshold     */
} HD_VP(HD_ROCDATA);

/**** Local prototypes ****/

static HD_LONG          HD_CALLBACK HD_FP(SortInd)(const HD_VP(HD_ROCDATA) *R0, const HD_VP(HD_ROCDATA) *R1);
static HD_VP(HD_ROCMOD) HD_FASTCALL HD_FP(RocModNew)(HD_ULONG Uvalues);


/**** Free the ROC model ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_FP(HD_RocModFree)(HD_VP(HD_ROCMOD) Model)
{
  if (!Model) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  HD_FreeSafe(Model -> Fpr);
  HD_FreeSafe(Model -> Tpr);
  HD_Free(Model);

  GlobErrCode = HD_ERR_NONE;
}


/**** Allocate a new ROC model ****/

HD_VP(HD_ROCMOD) HD_FASTCALL HD_FP(RocModNew)(HD_ULONG Uvalues)
{
  HD_VP(HD_ROCMOD)      Model;

  if ((Model = (HD_VP(HD_ROCMOD))HD_Calloc(sizeof(struct HD_FP(_hd_rocmod)))) == HD_NULL)
    return HD_NULL;

  if (((Model -> Fpr = (HD_FLOAT_INT *)HD_Malloc(sizeof(HD_FLOAT_INT) * Uvalues)) == HD_NULL) ||
      ((Model -> Tpr = (HD_FLOAT_INT *)HD_Malloc(sizeof(HD_FLOAT_INT) * Uvalues)) == HD_NULL)) {
    HD_FP(HD_RocModFree)(Model);
    return HD_NULL;
  }

  Model -> Uvalues = Uvalues;

  return Model;
}


/**** Calculate the ROC curve ****/

HDRIVE_EXTERN HD_VP(HD_ROCMOD) HDRIVE_EXPORT HD_FP(HD_RocCalc)(HD_VP(HD_MTX) IndMtx, HD_VP(HD_MTX) ActMtx, HD_FLOAT_INT ActTresh)
{
  HD_FLOAT_INT          Tmp;
  HD_VP(HD_ROCDATA) *   Data;
  HD_VP(HD_ROCDATA) *   DataPtr;
  HD_VP(HD_ROCMOD)      Model;
  HD_ULONG              DataLen, j, k;

  HD_ULONG              Fpr, FprSum, Tpr, TprSum;

  if ((!IndMtx) || (!ActMtx) || (IndMtx -> Col != 1) || (ActMtx -> Col != 1) ||
      (IndMtx -> Row != ActMtx -> Row)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_NULL;
  }

  /**** Allocate the data ****/

  DataLen = IndMtx -> Row;
  if ((Data = (HD_VP(HD_ROCDATA) *)HD_Malloc(sizeof(HD_VP(HD_ROCDATA)) * DataLen)) == HD_NULL)
    return HD_NULL;

  TprSum = 0;
  for(k = 0, DataPtr = Data; k < DataLen; ++k, ++DataPtr) {
    Tmp                   = ActMtx -> Data[k];
    j                     = (Tmp > ActTresh);
    DataPtr -> Ind        = IndMtx -> Data[k];
    DataPtr -> Index      = k;

    DataPtr -> Act        = Tmp;
    DataPtr -> Exceed     = j;
    TprSum               += j;
  } /* End of for (k, DataPtr) */
  FprSum = DataLen - TprSum;

  /**** Sort the indicator variable ****/

  HD_QsortP(Data, DataLen, sizeof(HD_VP(HD_ROCDATA)), (HD_SORTCALLBACK)HD_FP(SortInd));

  /**** Calculate FPR and TPR ****/

  Fpr = FprSum;
  Tpr = TprSum;
  for(k = 1, DataPtr = Data; k < DataLen; ++k, ++DataPtr) {
    Fpr -= !DataPtr -> Exceed;
    Tpr -= DataPtr -> Exceed;
    DataPtr -> Fpr = (HD_FLOAT_INT)Fpr / (HD_FLOAT_INT)(FprSum);
    DataPtr -> Tpr = (HD_FLOAT_INT)Tpr / (HD_FLOAT_INT)(TprSum);
  } /* End of for (k, DataPtr) */
  DataPtr -> Fpr = HD_FP(0.0);
  DataPtr -> Tpr = HD_FP(0.0);

  /**** Check for redundant values ****/

  j = 1;
  Tmp = Data -> Ind;
  Data -> Exceed = TRUE;
  for(k = 1, DataPtr = Data + 1; k < DataLen; ++k, ++DataPtr) {
    if (DataPtr -> Ind == Tmp) {
      DataPtr -> Exceed = FALSE;
    } else {
      DataPtr -> Exceed = TRUE;
      Tmp = DataPtr -> Ind;
      ++j;
    }
  } /* End of for (k, DataPtr) */

  /**** Transfer the data ****/

  if ((Model = HD_FP(RocModNew)(j)) == HD_NULL)
    goto Exit;

  j = 0;
  for(k = 0, DataPtr = Data; k < DataLen; ++k, ++DataPtr) {
    if (DataPtr -> Exceed) {
      Model -> Fpr[j] = DataPtr -> Fpr;
      Model -> Tpr[j] = DataPtr -> Tpr;
      ++j;
    }
  } /* End of for (k, DataPtr) */

  /**** Calculate the AUC ****/

  Tmp = HD_FP(0.0);
  --j;
  for(k = 0; k < j; ++k)
    Tmp += (Model -> Tpr[k] + Model -> Tpr[k + 1]) / HD_FP(2.0) * \
           (Model -> Fpr[k] - Model -> Fpr[k + 1]);

  Model -> Auc = Tmp;
  Model -> G1  = HD_FP(2.0) * Tmp - HD_FP(1.0);

Exit:

  GlobErrCode = HD_ERR_NONE;
  HD_Free(Data);


  return Model;
}


/**** Sort callback ****/

static int HD_CALLBACK HD_FP(SortInd)(const HD_VP(HD_ROCDATA) *R0, const HD_VP(HD_ROCDATA) *R1)
{
  if (R0 -> Ind > R1 -> Ind) return 1;
  if (R0 -> Ind < R1 -> Ind) return -1;

  return 0;
}
