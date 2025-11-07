
/*******************************************
****  HyperDrive - Statistic functions  ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/

#ifndef __HD_STATS_H
#  define  __HD_STATS_H

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_Kurtosis                _HD_Kurtosis
#    define  HD_Kurtosisf               _HD_Kurtosisf
#    define  HD_Max                     _HD_Max
#    define  HD_Maxf                    _HD_Maxf
#    define  HD_Mean                    _HD_Mean
#    define  HD_Meanf                   _HD_Meanf
#    define  HD_MeanGeo                 _HD_MeanGeo
#    define  HD_MeanGeof                _HD_MeanGeof
#    define  HD_MeanHarm                _HD_MeanHarm
#    define  HD_MeanHarmf               _HD_MeanHarmf
#    define  HD_MeanQuad                _HD_MeanQuad
#    define  HD_MeanQuadf               _HD_MeanQuadf
#    define  HD_Median                  _HD_Median
#    define  HD_Medianf                 _HD_Medianf
#    define  HD_Min                     _HD_Min
#    define  HD_Minf                    _HD_Minf
#    define  HD_Range                   _HD_Range
#    define  HD_Rangef                  _HD_Rangef
#    define  HD_Skewness                _HD_Skewness
#    define  HD_Skewnessf               _HD_Skewnessf
#    define  HD_StdDev                  _HD_StdDev
#    define  HD_StdDevBC                _HD_StdDevBC
#    define  HD_StdDevf                 _HD_StdDevf
#    define  HD_StdDevBcf               _HD_StdDevfBcf
#    define  HD_Variance                _HD_Variance
#    define  HD_VarianceBc              _HD_VarianceBc
#    define  HD_Variancef               _HD_Variancef
#    define  HD_VarianceBcf             _HD_VarianceBcf
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

/**** Kurtosis and skewness ****/

HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_Kurtosis(HD_DOUBLE *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_Kurtosisf(HD_FLOAT *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_Skewness(HD_DOUBLE *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_Skewnessf(HD_FLOAT *Vect, HD_ULONG Num);

/**** Normal, geometric, Harmonic and quadratic means ****/

HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_Mean(HD_DOUBLE *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_Meanf(HD_FLOAT *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_MeanGeo(HD_DOUBLE *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_MeanGeof(HD_FLOAT *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_MeanHarm(HD_DOUBLE *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_MeanHarmf(HD_FLOAT *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_MeanQuad(HD_DOUBLE *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_MeanQuadf(HD_FLOAT *Vect, HD_ULONG Num);

/**** Median ****/

HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_Median(HD_DOUBLE *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_Medianf(HD_FLOAT *Vect, HD_ULONG Num);

/**** Return the min. and max. values of a vector ****/

HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_Max(HD_DOUBLE *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_Maxf(HD_FLOAT *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_Min(HD_DOUBLE *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_Minf(HD_FLOAT *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Range(HD_DOUBLE *Min, HD_DOUBLE *Max, HD_DOUBLE *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Rangef(HD_FLOAT *Min, HD_FLOAT *Max, HD_FLOAT *Vect, HD_ULONG Num);

/**** Standard deviation ****/

HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_StdDev(HD_DOUBLE *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_StdDevBc(HD_DOUBLE *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_StdDevf(HD_FLOAT *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_StdDevBcf(HD_FLOAT *Vect, HD_ULONG Num);

/**** Variance ****/

HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_Variance(HD_DOUBLE *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_VarianceBc(HD_DOUBLE *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_Variancef(HD_FLOAT *Vect, HD_ULONG Num);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_VarianceBcf(HD_FLOAT *Vect, HD_ULONG Num);

#  ifdef __cplusplus
   }
#  endif
#endif

