
/*********************************************
****     HyperDrive - Math functions      ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifndef __HDMATH_H
#  define  __HDMATH_H

#  ifdef __BORLANDC__
#    pragma hdrstop
#  endif

#  ifdef HD_USE_FASTMATH
#    include <fastmath.h>
#   else
#    include <math.h>
#  endif

#  include <hyperdrive.h>

/**** Constant ****/

#  define  HD_1PI                0.3183098861837906715377675267450    /* 1 / PI       */
#  define  HD_1PIF               0.31830989f
#  define  HD_1PI2               0.1591549430918953357688837633725    /* 1 / (2 * PI) */
#  define  HD_1PI2F              0.15915494f

#  define  HD_1SQRT2             0.7071067811865475244008443621049    /* 1 / sqrt(2)  */
#  define  HD_1SQRT2F            0.70710678f
#  define  HD_2PI                0.6366197723675813430755350534901    /* 2 / PI       */
#  define  HD_2PIF               0.63661977f
#  define  HD_2SQRTPI            1.1283791670955125738961589031215    /* 2 / sqrt(PI) */
#  define  HD_2SQRTPIF           1.12837917f
#  define  HD_3PI_2              4.7123889803846898576939650749193    /* 3 * PI / 2   */
#  define  HD_3PI_2F             4.71238898f
#  define  HD_4PI                0.7853981633974483096156608458199    /* 4 / PI       */
#  define  HD_4PIF               0.78539816f
#  define  HD_DEG_TO_RAD         0.0174532925199432957692369076849
#  define  HD_DEG_TO_RADF        0.01745329f
#  define  HD_E                  2.7182818284590452353602874713527    /* e            */
#  define  HD_EF                 2.71828183f
#  define  HD_LN10               2.3025850929940456840179914546844    /* ln(10)       */
#  define  HD_LN10F              2.30258509f
#  define  HD_LN2                0.6931471805599453094172321214582    /* ln(2)        */
#  define  HD_LN2F               0.69314718f
#  define  HD_LOG10E             0.4342944819032518276511289189166    /* log10(e)     */
#  define  HD_LOG10EF            0.43429448f
#  define  HD_LOG2E              1.4426950408889634073599246810019    /* log2(e)      */
#  define  HD_LOG2EF             1.44269504f
#  define  HD_PI                 3.1415926535897932384626433832795    /* PI           */
#  define  HD_PIF                3.14159265f
#  define  HD_PI_2               1.5707963267948966192313216916398    /* PI / 2       */
#  define  HD_PI_2F              1.57079633f
#  define  HD_PI_4               0.7853981633974483096156608458199    /* PI / 4       */
#  define  HD_PI_4F              0.78539816f
#  define  HD_PI2                6.2831853071795864769252867665590    /* 2 * PI       */
#  define  HD_PI2F               6.28318531f
#  define  HD_PI4                12.566370614359172953850573533118    /* 4 * PI       */
#  define  HD_PI4F               12.5663706f
#  define  HD_RAD_TO_DEG         57.295779513082320876798154814105
#  define  HD_RAD_TO_DEGF        57.29577951f
#  define  HD_SQRT2              1.4142135623730950488016887242097    /* sqrt(2)      */
#  define  HD_SQRT2F             1.41421356f
#  define  HD_SQRTPI             1.7724538509055160272981674833411    /* sqrt(PI)     */
#  define  HD_SQRTPIF            1.772453851f

#if 0
#  define  HD_2_PI                      6.2831853071795864769252867665590
#  define  HD_2_PI_F                    6.28318531f
#endif

/**** Double limits ****/

#  define  HD_EPSILON_D           2.2204460492503131E-16              /* Smallest epsilon  */
#  define  HD_MAX_D               1.7976931348623158E+308             /* Max. value        */
#  define  HD_MAX_FACTD           170                                 /* Largest factorial */
#  define  HD_MIN_D               2.2250738585072014E-308             /* Min. value        */

/**** Float limits ****/

#  define  HD_EPSILON_F           1.19209290E-07f                     /* Smallest epsilon  */
#  define  HD_MAX_F               3.40282346E+38f                     /* Max. value        */
#  define  HD_MAX_FACTF           33                                  /* Largest factorial */
#  define  HD_MIN_F               1.17549435E-38f                     /* Min. value        */

/**** long double limits ****/

#  ifdef HD_CPUARCH_X86
#    define  HD_EPSILON_LD        1.084202172485504434e-019l          /* Smallest epsilon  */
#    define  HD_MAX_LD            1.1897314953572316e+4932l           /* Max. value        */
#    define  HD_MAX_FACTLD        1754                                /* Largest factorial */
#    define  HD_MIN_LD            3.36210314311209350626e-4932l       /* Min. value        */
#  else
#    define  HD_EPSILON_LD        2.2204460492503131E-16              /* Smallest epsilon  */
#    define  HD_MAX_LD            2.2250738585072014E+308             /* Max. value        */
#    define  HD_MAX_FACTLD        170                                 /* Largest factorial */
#    define  HD_MIN_LD            2.2250738585072014E-308             /* Min. value        */
#  endif

/**** Other limits ****/

#  define  HD_MAX_FACTI           11    /* The largest factorial for a 32 bit integer */
#  define  HD_MAX_FACTLI          20    /* The largest factorial for a 64 bit integer */
#  define  HD_MIN_FACT            0     /* The smallest factorial                     */

/**** Macros ****/

#  define  HD_ISPOWOF2(X)         ((X) && !((X) & ((X) - 1)))
#  define  HD_LOG(BASE, NUM)      (log10((N)) / log10((BASE)))
#  define  HD_DEG2RAD(X)          ((X) * 0.017453292519943295769236907684886)
#  define  HD_DEG2RADF(X)         ((X) * 0.01745329f)
#  define  HD_MAX(a,b)            (((a) > (b)) ? (a) : (b))
#  define  HD_RAD2DEG(X)          ((X) * 57.2957795130823208767981548141050)
#  define  HD_RAD2DEGF(X)         ((X) * 57.29577951f)
#  define  HD_DOUBLEISINT(X)      (fabs(HD_RintD(X) - (X)) <= 0.00001)
#  define  HD_FLOATISINT(X)       (fabs(HD_RintF(X) - (X)) <= 0.00001f)

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#  define  HD_CombiD                    _HD_CombiD
#  define  HD_CombiF                    _HD_CombiF
#  define  HD_CombiI                    _HD_CombiI
#  define  HD_CombiLD                   _HD_CombiLD
#  define  HD_CombiLI                   _HD_CombiLI
#  define  HD_ControlFP                 _HD_ControlFP
#  define  HD_Erf                       _HD_Erf
#  define  HD_Erfc                      _HD_Erfc
#  define  HD_Erfcf                     _HD_Erfcf
#  define  HD_Erff                      _HD_Erff
#  define  HD_FactD                     _HD_FactD
#  define  HD_FactF                     _HD_FactF
#  define  HD_FactI                     _HD_FactI
#  define  HD_FactLD                    _HD_FactLD
#  define  HD_FactLI                    _HD_FactLI
#  define  HD_FastAtoF                  _HD_FastAtoF
#  define  HD_FastCosf                  _HD_FastCosf
#  define  HD_FastSinf                  _HD_FastSinf
#  define  HD_IpowD                     _HD_IpowD
#  define  HD_IpowF                     _HD_IpowF
#  define  HD_IpowI                     _HD_IpowI
#  define  HD_IpowLD                    _HD_IpowLD
#  define  HD_IsInfD                    _HD_IsInfD
#  define  HD_IsInfF                    _HD_IsInfF
#  define  HD_NearPow2UI                _HD_NearPow2UI
#  define  HD_NextPow2UI                _HD_NextPow2UI
#  define  HD_IpowLI                    _HD_IpowLI
#  define  HD_PermD                     _HD_PermD
#  define  HD_PermF                     _HD_PermF
#  define  HD_PermI                     _HD_PermI
#  define  HD_PermL                     _HD_PermL
#  define  HD_PermLD                    _HD_PermLD
#  define  HD_PermLI                    _HD_PermLI
#  define  HD_PrevPow2UI                _HD_PrevPow2UI
#  define  HD_RintD                     _HD_RintD
#  define  HD_RintF                     _HD_RintF
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_DOUBLE           HDRIVE_EXPORT HD_CombiD(HD_LONG Elem, HD_LONG Groups, HD_BOOL Repeat);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_CombiF(HD_LONG Elem, HD_LONG Groups, HD_BOOL Repeat);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_CombiI(HD_LONG Elem, HD_LONG Groups, HD_BOOL Repeat);
HDRIVE_EXTERN HD_LONGDOUBLE       HDRIVE_EXPORT HD_CombiLD(HD_LONG Elem, HD_LONG Groups, HD_BOOL Repeat);
HDRIVE_EXTERN HD_DLONG            HDRIVE_EXPORT HD_CombiLI(HD_LONG Elem, HD_LONG Groups, HD_BOOL Repeat);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_ControlFP(HD_ULONG NewControl, HD_ULONG Mask);
HDRIVE_EXTERN HD_DOUBLE           HDRIVE_EXPORT HD_Erf(HD_DOUBLE x);
HDRIVE_EXTERN HD_DOUBLE           HDRIVE_EXPORT HD_Erfc(HD_DOUBLE x);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_Erfcf(HD_FLOAT x);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_Erff(HD_FLOAT x);
HDRIVE_EXTERN HD_DOUBLE           HDRIVE_EXPORT HD_FactD(HD_LONG x);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_FactF(HD_LONG x);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_FactI(HD_LONG x);
HDRIVE_EXTERN HD_LONGDOUBLE       HDRIVE_EXPORT HD_FactLD(HD_LONG x);
HDRIVE_EXTERN HD_DLONG            HDRIVE_EXPORT HD_FactLI(HD_LONG x);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_FastAtoF(const HD_CHAR *c);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_FastCosf(HD_FLOAT Angle);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_FastSinf(HD_FLOAT Angle);
HDRIVE_EXTERN HD_DOUBLE           HDRIVE_EXPORT HD_IpowD(HD_DOUBLE x, HD_LONG n);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_IpowF(HD_FLOAT x, HD_LONG n);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_IpowI(HD_LONG x, HD_LONG n);
HDRIVE_EXTERN HD_LONGDOUBLE       HDRIVE_EXPORT HD_IpowLD(HD_LONGDOUBLE x, HD_LONG n);
HDRIVE_EXTERN HD_DLONG            HDRIVE_EXPORT HD_IpowLI(HD_DLONG x, HD_LONG n);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_IsInfD(HD_DOUBLE Num);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_IsInfF(HD_FLOAT Num);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_NearPow2UI(HD_ULONG n);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_NextPow2UI(HD_ULONG n);
HDRIVE_EXTERN HD_DOUBLE           HDRIVE_EXPORT HD_PermD(HD_LONG Elem, HD_LONG Groups, HD_BOOL Repeat);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_PermF(HD_LONG Elem, HD_LONG Groups, HD_BOOL Repeat);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_PermI(HD_LONG Elem, HD_LONG Groups, HD_BOOL Repeat);
HDRIVE_EXTERN HD_LONGDOUBLE       HDRIVE_EXPORT HD_PermLD(HD_LONG Elem, HD_LONG Groups, HD_BOOL Repeat);
HDRIVE_EXTERN HD_DLONG            HDRIVE_EXPORT HD_PermLI(HD_LONG Elem, HD_LONG Groups, HD_BOOL Repeat);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_PrevPow2UI(HD_ULONG n);
HDRIVE_EXTERN HD_DOUBLE           HDRIVE_EXPORT HD_RintD(HD_DOUBLE x);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_RintF(HD_FLOAT x);

#  ifdef __cplusplus
   }
#  endif
#endif
