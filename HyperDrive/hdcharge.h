
/******************************************
****     HyperDrive - Atomic charges    ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#ifndef __HDCHARGE_H
#  define  __HDCHARGE_H

#  include "hdmatrix.h"
#  include "hdstring.h"

/**** EQeq methods ****/

#  define  HD_EQEQ_METHOD_NONPERIODIC       0     /* Non peridic                      */
#  define  HD_EQEQ_METHOD_PERIODIC          1     /* Periodic                         */
#  define  HD_EQEQ_METHOD_PERIODICEWALD     2     /* Periodic with ewald sum          */

/**** Charge errors ****/

#  define  HD_ERR_GAST_UNKFORMAT            1101  /* Unknown Gasteiger file format    */
#  define  HD_ERR_EQEQ_CHARGEZERO           1102  /* The total charge mus be zero     */
#  define  HD_ERR_EQEQ_LOADCHGCENT          1103  /* Error loading charge centers     */
#  define  HD_ERR_EQEQ_LOADIONDAT           1104  /* Error loading ionization data    */
#  define  HD_ERR_EQEQ_NOTRUNNING           1105  /* Calculation not running          */
#  define  HD_ERR_EQEQ_UNKFORMAT            1106  /* Unknown data file format         */

/**** HD_GastCharge() / HD_GastLoad flags ****/

#  define  HD_GAST_FLAG_NONE                0     /* None                             */
#  define  HD_GAST_FLAG_ACTIVEONLY          1     /* Active atoms only                */
#  define  HD_GAST_FLAG_CHECKCHANGE         2     /* Check if the template is changed */
#  define  HD_GAST_FLAG_USECACHE            4     /* Use the template cache           */

/**** EQeq K-space component for cache ****/

typedef struct {
  HD_FLOAT        a;
  HD_FLOAT        Rlv0, Rlv1, Rlv2;
} HD_EQEQ_KSPACE;

/**** EQeq orbital component for cache ****/

typedef struct {
  HD_FLOAT        Erf, OneRab, Rab, RabSq;
  HD_FLOAT        V0, V1, V2;
} HD_EQEQ_ORBITAL;

/**** Cache data ****/

typedef struct {
  HD_LONG           mK, mR;
  HD_FLOAT          AlphaStar;
  HD_FLOAT          Eta;
  HD_EQEQ_KSPACE *  Beta;
  HD_EQEQ_ORBITAL * Orbital;
} HD_EQEQ_CACHE;

/**** EQeq context ****/

typedef struct {

  /**** User parameters ****/

  HD_FLOAT        Eta;                    /* Ewald splitting parameter                                          */
  HD_FLOAT        K;                      /* Physical constant: the vacuum permittivity 1/(4pi*epsi) [units of Angstroms * electron volts] */
  HD_FLOAT        Lambda;                 /* Coulomb scaling parameter                                          */
  HD_FLOAT        Qtot;                   /* Total charge                                                       */
  HD_FLOAT        hI0;                    /* Default value used in paper                                        */
  HD_FLOAT        hI1;                    /* This is the empirically mesaured 1st ionization energy of hydrogen */
  HD_LONG         ChargePrecision;        /* Number of digits to use for point charges                          */
  HD_LONG         Method;                 /* Method                                                             */
  HD_LONG         mK;                     /* Number of unit cells to consider in per. calc. ("frequency space") */
  HD_LONG         mR;                     /* Number of unit cells to consider in per. calc. ("real space")      */

  /**** Errors ****/

  HD_ATOM *       ErrAtm;                 /* Atom with error                                                    */
  HD_LONG         ErrArg;                 /* Error argument number                                              */
  HD_ULONG        ErrLine;                /* Error line number                                                  */

  /**** Internal data (Don't edit it) ****/

  HD_BOOL         Abort;                  /* TRUE to abort the calculation                                      */
  HD_BOOL         Running;                /* TRUE if the calculation is running                                 */
  HD_EQEQ_CACHE * Cache;                  /* Cache data                                                         */
  HD_FLOAT *      J;                      /* Atom "hardness"                                                    */
  HD_FLOAT *      X;                      /* Atom electronegativity                                             */
  HD_FLOAT        LambdaHalfK;            /* Lambda * (K / 2.0)                                                 */
  HD_FLOAT        TwoEtaSqrtPi;           /* 2.0 / (Eta * HD_SQRTPI)                                            */
  HD_FLOAT        UnitCellVolume;         /* Unit cell volume                                                   */
  HD_LIST *       IonizationData;         /* Ionization data list                                               */
  HD_LONG         IonizationLastMod;      /* Time of the last modification of ionization file                   */
  HD_STRING       IonizationFileName;     /* Ionization file name                                               */
  HD_VECTOR3F     aV, bV, cV;             /* Real-space vectors                                                 */
  HD_VECTOR3F     hV, jV, kV;             /* Reciprocal-lattice vectors                                         */
} HD_EQEQCTX;

/**** Gasteiger parameter handle ****/

typedef struct _hd_gasteiger {
  struct _hd_gasteiger *        Next;
  struct _hd_gasteiger *        Prev;
  HD_LONG                       LastMod;        /* Time of the last modification      */
  HD_LIST *                     Param;          /* Parameters                         */
  HD_STRING                     FileName;       /* File name                          */
} HD_GASTEIGER;

/**** Gasteiger parameters ****/

typedef struct _hd_gastpar {
  struct _hd_gastpar *          Next;
  struct _hd_gastpar *          Prev;
  HD_OCHAR                      AtmType;        /* Atom type                          */
  HD_FLOAT                      a;
  HD_FLOAT                      b;
  HD_FLOAT                      c;
  HD_FLOAT                      d;              /* a + b + c                          */
  HD_FLOAT                      Charge;         /* Formal charge                      */
} HD_GASTPAR;

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#  define  HD_ChargeChk                 _HD_ChargeChk
#  define  HD_ChargeRound               _HD_ChargeRound
#  define  HD_ChargeTotal               _HD_ChargeTotal
#  define  HD_Dipole                    _HD_Dipole

#  define  HD_EqeqCharge                _HD_EqeqCharge
#  define  HD_EqeqFree                  _HD_EqeqFree
#  define  HD_EqeqLoadChargeCenters     _HD_EqeqLoadChargeCenters
#  define  HD_EqeqLoadData              _HD_EqeqLoadData
#  define  HD_EqeqLoadIonizationData    _HD_EqeqLoadIonizationData
#  define  HD_EqeqNew                   _HD_EqeqNew

#  define  HD_GastCharge                _HD_GastCharge
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_ChargeChk(HD_FLOAT *TotCharge, HD_ATOM *Atm, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_ChargeRound(HD_ATOM *InizAtm, HD_ULONG Digits, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_ChargeTotal(HD_LONG *TotCharge, HD_ATOM *Atm, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Dipole(HD_FLOAT *Dipole, HD_FLOAT *Vector, HD_ATOM *Atm, HD_LONG Flags);

HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_EqeqCharge(HD_EQEQCTX *Ctx, HD_ATOM *InizAtm, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_EqeqFree(HD_EQEQCTX *Ctx);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_EqeqLoadChargeCenters(HD_EQEQCTX *Ctx, const HD_CHAR *FileName);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_EqeqLoadData(HD_EQEQCTX *Ctx, const HD_CHAR *FileName);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_EqeqLoadIonizationData(HD_EQEQCTX *Ctx, const HD_CHAR *FileName);
HDRIVE_EXTERN HD_EQEQCTX *      HDRIVE_EXPORT HD_EqeqNew(HD_VOID);

HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_GastCharge(const HD_CHAR *Template, HD_ATOM *InizAtm, HD_ULONG TotAtm, HD_LONG Flags, HD_ATOMCALLBACK GastHook);

#  ifdef __cplusplus
   }
#  endif
#endif
