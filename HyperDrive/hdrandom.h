
/*********************************************
**** HyperDrive - Random number generator ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifndef __HD_RANDOM_H
#  define  __HD_RANDOM_H

#  ifndef __HDRIVE_H
#    include "hyperdrive.h"
#  endif

/**** Constants ****/

#  define  HD_RAND_MAX32            0x7fff
#  define  HD_RAND_MAX64            0x7FFFFFFF

/**** Random number generators ****/

#  define  HD_RNDGEN_INTERNAL       0   /* Stdlib CRT implementation                               */
#  define  HD_RNDGEN_DEVICE         1   /* Device service                                          */
#  define  HD_RNDGEN_KISS           2
#  define  HD_RNDGEN_LCG_BSD        3   /* Linear congruential generator (LCG) BSD version         */
#  define  HD_RNDGEN_LCG_EMB        4   /* Linear congruential generator (LCG) Embracadero version */
#  define  HD_RNDGEN_LCG_MS         5   /* Linear congruential generator (LCG) Microsoft version   */
#  define  HD_RNDGEN_LFSR113        6   /* Pierre L'Ecuyer's LFSR113                               */

#  define  HD_RNDGEN_ANSIC          HD_RNDGEN_LCG_BSD
#  define  HD_RNDGEN_EMBARCADERO    HD_RNDGEN_LCG_EMB

#  define  HD_RNDGEN_64BIT          0x100
#  define  HD_RNDGEN_RANDOMIZE      0x200

#  define  HD_RNDGEN_DEFAULT        HD_RNDGEN_LCG_BSD
#  define  HD_RNDGEN_LAST           HD_RNDGEN_LCG_MS

/**** Flags for HD_RandStr() functions ****/

#  define HD_RANDSTR_UPPER_CASE_LETTERS     0x00000001  /* from  65 to  90         */
#  define HD_RANDSTR_LOWER_CASE_LETTERS     0x00000002  /* from  97 to 122         */
#  define HD_RANDSTR_NUMBERS                0x00000004  /* from  48 to  57         */
#  define HD_RANDSTR_SYMBOLS_1              0x00000008  /* from  32 to  47         */
#  define HD_RANDSTR_SYMBOLS_2              0x00000010  /* from  58 to  64         */
#  define HD_RANDSTR_SYMBOLS_3              0x00000020  /* from  91 to  96         */
#  define HD_RANDSTR_SYMBOLS_4              0x00000040  /* from 123 to 126         */
#  define HD_RANDSTR_NON_PRINTABLE          0x00000080  /* from   1 to  31 and 127 */
#  define HD_RANDSTR_EXTENDED_ASCII         0x00000100  /* from 128 to 255         */

#  define HD_RANDSTR_ALL_PRINTABLE          (HD_RANDSTR_UPPER_CASE_LETTERS|HD_RANDSTR_LOWER_CASE_LETTERS| \
                                             HD_RANDSTR_NUMBERS|HD_RANDSTR_SYMBOLS_1|HD_RANDSTR_SYMBOLS_2| \
                                             HD_RANDSTR_SYMBOLS_3|HD_RANDSTR_SYMBOLS_4|HD_RANDSTR_EXTENDED_ASCII)
#  define HD_RANDSTR_ASCII_PRINTABLE        (HD_RANDSTR_UPPER_CASE_LETTERS|HD_RANDSTR_LOWER_CASE_LETTERS| \
                                             HD_RANDSTR_NUMBERS|HD_RANDSTR_SYMBOLS_1|HD_RANDSTR_SYMBOLS_2| \
                                             HD_RANDSTR_SYMBOLS_3|HD_RANDSTR_SYMBOLS_4)

/**** Errors ****/

#  define  HD_ERR_RAND_DEVINIT              1801 /* Device initialization                    */
#  define  HD_ERR_RAND_NO64                 1802 /* 64 bit random generator not available    */

/**** Types ****/

typedef HD_VOID *       HD_RANDOM;

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_RandAlloc               _HD_RandAlloc
#    define  HD_RandD                   _HD_RandD
#    define  HD_RandF                   _HD_RandF
#    define  HD_RandFree                _HD_RandFree
#    define  HD_RandI                   _HD_RandI
#    define  HD_RandInit                _HD_RandInit
#    define  HD_RandMaxD                _HD_RandMaxD
#    define  HD_RandMaxF                _HD_RandMaxF
#    define  HD_RandMaxI                _HD_RandMaxI
#    define  HD_RandRangeD              _HD_RandRangeD
#    define  HD_RandRangeF              _HD_RandRangeF
#    define  HD_RandRangeI              _HD_RandRangeI
#    define  HD_RandStr                 _HD_RandStr
#    define  HD_RandStrC                _HD_RandStrC
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_RANDOM         HDRIVE_EXPORT HD_RandAlloc(HD_LONG RndGen);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_RandD(HD_RANDOM hRnd);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_RandF(HD_RANDOM hRnd);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_RandFree(HD_RANDOM hRnd);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT HD_RandI(HD_RANDOM hRnd);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_RandInit(HD_RANDOM hRnd, HD_UDLONG Seed);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_RandMaxD(HD_RANDOM hRnd, HD_DOUBLE Max);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_RandMaxF(HD_RANDOM hRnd, HD_FLOAT Max);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT HD_RandMaxI(HD_RANDOM hRnd, HD_LONG Max);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_RandRangeD(HD_RANDOM hRnd, HD_DOUBLE Min, HD_DOUBLE Max);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT HD_RandRangeF(HD_RANDOM hRnd, HD_FLOAT Min, HD_FLOAT Max);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT HD_RandRangeI(HD_RANDOM hRnd, HD_LONG Min, HD_LONG Max);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT HD_RandStr(HD_RANDOM hRnd, HD_STRING Str, HD_LONG Len, HD_LONG Flags);
HDRIVE_EXTERN HD_CHAR *         HDRIVE_EXPORT HD_RandStrC(HD_RANDOM hRnd, HD_CHAR *Str, HD_LONG Len, HD_LONG Flags);

#  ifdef __cplusplus
   }
#  endif

/**** C++ wrapper ****/

#  ifdef __cplusplus

/**** Random number generator class ****/

class HDC_Random
{
  public:
        /**** Methods ****/

        inline                  HDC_Random(HD_LONG RndGen)                 { hRnd = HD_RandAlloc(RndGen); }
        inline                  ~HDC_Random(HD_VOID)                       { HD_RandFree(hRnd); }
        inline HD_VOID          Init(HD_UDLONG Seed)                       { HD_RandInit(hRnd, Seed); }
        inline HD_DOUBLE        RandD(HD_VOID)                             { return HD_RandD(hRnd); }
        inline HD_FLOAT         RandF(HD_VOID)                             { return HD_RandF(hRnd); }
        inline HD_LONG          RandI(HD_VOID)                             { return HD_RandI(hRnd); }
        inline HD_DOUBLE        RandMaxD(HD_DOUBLE Max)                    { return HD_RandMaxD(hRnd, Max); }
        inline HD_FLOAT         RandMaxF(HD_FLOAT Max)                     { return HD_RandMaxF(hRnd, Max); }
        inline HD_LONG          RandMaxI(HD_LONG Max)                      { return HD_RandMaxI(hRnd, Max); }
        inline HD_DOUBLE        RandRangeD(HD_DOUBLE Min, HD_DOUBLE Max)   { return HD_RandRangeD(hRnd, Min, Max); }
        inline HD_FLOAT         RandRangeF(HD_FLOAT Min, HD_FLOAT Max)     { return HD_RandRangeF(hRnd, Min, Max); }
        inline HD_LONG          RandRangeI(HD_LONG Min, HD_LONG Max)       { return HD_RandRangeI(hRnd, Min, Max); }
        inline HD_STRING        RandStr(HD_STRING Str, HD_LONG Len, HD_LONG Flags)
                                                                           { return HD_RandStr(hRnd, Str, Len, Flags); }
        inline HD_CHAR *        RandStrC(HD_CHAR *Str, HD_LONG Len, HD_LONG Flags)
                                                                           { return HD_RandStrC(hRnd, Str, Len, Flags); }

        /**** Private properties ****/

  private:
        HD_RANDOM               hRnd;
};

#  endif
#endif

