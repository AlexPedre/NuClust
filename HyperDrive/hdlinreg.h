
/*******************************************
****   HyperDrive - Linear regression   ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#ifndef __HD_LINREG_H
#  define  __HD_LINREG_H

#  include "hdmatrix.h"

/**** Flags for HD_LinRegCalcEx() and HD_LinRegCalcExf() ****/

#  define  HD_LINREG_CALC_NONE          0
#  define  HD_LINREG_CALC_DELTAY        1
#  define  HD_LINREG_CALC_VARCOVAR      2
#  define  HD_LINREG_CALC_VIF           4
#  define  HD_LINREG_CALC_Y             8

#  define  HD_LINREG_CALC_ALL           0xffffffff

/**** Linear regression model (double precision) ****/

struct _hd_linregmod {
  HD_DOUBLE     F;              /* Fisher F statistic for regression  */
  HD_DOUBLE     P;              /* Probability                        */
  HD_DOUBLE     PC;             /* Amemiya's prediction criterion     */
  HD_DOUBLE     Rsq;            /* Multiple correlation coefficient   */
  HD_DOUBLE     RsqAdj;         /* Adjusted Rsq                       */
  HD_DOUBLE     StdDevCoeff;    /* Standard deviation of errors       */
  HD_DOUBLE *   Coeff;          /* Coefficients                       */
  HD_DOUBLE *   DeltaY;         /* Residual (Y - YCalc)               */
  HD_DOUBLE *   StdErrCoeff;    /* Standard error of coefficients     */
  HD_DOUBLE *   VIF;            /* Variance Inflaction Factor         */
  HD_DOUBLE *   YCalc;          /* Calculated Y values                */
  HD_MTX        VarCovar;       /* Var-covar matrix                   */
  HD_LONG       Ndf;            /* Number of degrees of freedom       */
  HD_ULONG      XNum;           /* Number of regressors               */
  HD_ULONG      YNum;           /* Number of Y values                 */
};

typedef struct  _hd_linregmod *         HD_LINREGMOD;

/**** Linear regression model (single precision) ****/

struct _hd_linregmodf {
  HD_FLOAT      F;              /* Fisher F statistic for regression  */
  HD_FLOAT      P;              /* Probability                        */
  HD_FLOAT      PC;             /* Amemiya Prediction Criterion       */
  HD_FLOAT      Rsq;            /* Multiple correlation coefficient   */
  HD_FLOAT      RsqAdj;         /* Adjusted Rsq                       */
  HD_FLOAT      StdDevCoeff;    /* Standard deviation of errors       */
  HD_FLOAT *    Coeff;          /* Coefficients                       */
  HD_FLOAT *    DeltaY;         /* Y differerences (Y - YCalc)        */
  HD_FLOAT *    StdErrCoeff;    /* Standard error of coefficients     */
  HD_FLOAT *    VIF;            /* Variance Inflaction Factor         */
  HD_FLOAT *    YCalc;          /* Calculated Y values                */
  HD_MTXF       VarCovar;       /* Var-covar matrix                   */
  HD_LONG       Ndf;            /* Number of degrees of freedom       */
  HD_ULONG      XNum;           /* Number of regressors               */
  HD_ULONG      YNum;           /* Number of Y values                 */
};

typedef struct  _hd_linregmodf *         HD_LINREGMODF;

/**** Linear regression errors ****/

#  define  HD_ERR_LINREG_NODATA         1401

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_F2P                     _HD_F2P
#    define  HD_F2Pf                    _HD_F2Pf
#    define  HD_LinRegCalc              _HD_LinRegCalc
#    define  HD_LinRegCalcDepVar        _HD_LinRegCalcDepVar
#    define  HD_LinRegCalcDepVarf       _HD_LinRegCalcDepVarf
#    define  HD_LinRegCalcEx            _HD_LinRegCalcEx
#    define  HD_LinRegCalcExf           _HD_LinRegCalcExf
#    define  HD_LinRegCalcf             _HD_LinRegCalcf
#    define  HD_LinRegModFree           _HD_LinRegModFree
#    define  HD_LinRegModFreef          _HD_LinRegModFreef
#    define  HD_LinRegResidual          _HD_LinRegResidual
#    define  HD_LinRegResidualf         _HD_LinRegResidualf
#    define  HD_Rsq2F                   _HD_Rsq2F
#    define  HD_Rsq2Ff                  _HD_Rsq2Ff
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

/**** Calculate P from Fisher's F ****/

HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_F2P(HD_DOUBLE F, HD_LONG Df1, HD_LONG Df2);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_F2Pf(HD_FLOAT F, HD_LONG Df1, HD_LONG Df2);

/**** Perform multiple linear regression ****/

HDRIVE_EXTERN HD_LINREGMOD      HDRIVE_EXPORT HD_LinRegCalc(HD_MTX X, HD_MTX Y);
HDRIVE_EXTERN HD_LINREGMOD      HDRIVE_EXPORT HD_LinRegCalcEx(HD_MTX X, HD_MTX Y, HD_LONG Flags);
HDRIVE_EXTERN HD_LINREGMODF     HDRIVE_EXPORT HD_LinRegCalcExf(HD_MTXF X, HD_MTXF Y, HD_LONG Flags);
HDRIVE_EXTERN HD_LINREGMODF     HDRIVE_EXPORT HD_LinRegCalcf(HD_MTXF X, HD_MTXF Y);

/**** Calculate the values of the dependent variable ****/

HDRIVE_EXTERN HD_MTX            HDRIVE_EXPORT HD_LinRegCalcDepVar(HD_LINREGMOD Model, HD_MTX X);
HDRIVE_EXTERN HD_MTXF           HDRIVE_EXPORT HD_LinRegCalcDepVarf(HD_LINREGMODF Model, HD_MTXF X);

/**** Free the model calculated by HD_LinRegCalc() functions ****/

HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_LinRegModFree(HD_LINREGMOD Model);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_LinRegModFreef(HD_LINREGMODF Model);

/**** Evaluate the residual errors of a test set ****/

HDRIVE_EXTERN HD_MTX            HDRIVE_EXPORT HD_LinRegResidual(HD_LINREGMOD Model, HD_MTX X, HD_MTX Y);
HDRIVE_EXTERN HD_MTXF           HDRIVE_EXPORT HD_LinRegResidualf(HD_LINREGMODF Model, HD_MTXF X, HD_MTXF Y);

/**** Calculate Fisher's F from R^2 ****/

/* Rsq = R^2
 * n   = number of observations
 * k   = number of regressors
 */

HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_Rsq2F(HD_DOUBLE Rsq, HD_LONG n, HD_LONG k);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_Rsq2Ff(HD_FLOAT Rsq, HD_LONG n, HD_LONG k);

#  ifdef __cplusplus
   }
#  endif
#endif
