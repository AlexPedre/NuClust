
/*******************************************
****         HyperDrive - ROC           ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#ifndef __HD_ROC_H
#  define  __HD_ROC_H

#  include "hdmatrix.h"

/**** ROC model (double precision) ****/

struct _hd_rocmod {
  HD_DOUBLE     Auc;            /* Area under curve                  */
  HD_DOUBLE     G1;             /* Gini coefficient                  */
  HD_DOUBLE *   Fpr;            /* False positive rate               */
  HD_DOUBLE *   Tpr;            /* True positive rate                */
  HD_ULONG      Uvalues;        /* Number of unique values           */
};

typedef struct  _hd_rocmod *    HD_ROCMOD;

/**** ROC model (single precision) ****/

struct _hd_rocmodf {
  HD_FLOAT      Auc;            /* Area under curve                  */
  HD_FLOAT      G1;             /* Gini coefficient                  */
  HD_FLOAT *    Fpr;            /* False positive rate               */
  HD_FLOAT *    Tpr;            /* True positive rate                */
  HD_ULONG      Uvalues;        /* Number of unique values           */
};

typedef struct  _hd_rocmodf *   HD_ROCMODF;

/**** Linear regression errors ****/

#  define  HD_ERR_LINREG_NODATA         1401

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_RocCalc                 _HD_RocCalc
#    define  HD_RocCalcf                _HD_RocCalcf
#    define  HD_RocModFree              _HD_RocModFree
#    define  HD_RocModFreef             _HD_RocModFreef
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_ROCMOD         HDRIVE_EXPORT HD_RocCalc(HD_MTX IndMtx, HD_MTX ActMtx, HD_DOUBLE ActTresh);
HDRIVE_EXTERN HD_ROCMODF        HDRIVE_EXPORT HD_RocCalcf(HD_MTXF IndMtx, HD_MTXF ActMtx, HD_FLOAT ActTresh);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_RocModFree(HD_ROCMOD Model);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_RocModFreef(HD_ROCMODF Model);

#  ifdef __cplusplus
   }
#  endif
#endif
