
/*************************************************
****         VEGA - Ionize a molecule         ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_IONIZE_H
#  define  __VG_IONIZE_H

/**** Ionization methods ****/

#  define  VG_IONIZE_METHOD_FAST        0   /* Don't change the order ! */

/**** Ionization flags ****/

#  define  VG_IONIZE_FLAG_NONE          0   /* Don't change the order ! */
#  define  VG_IONIZE_FLAG_ACTIVEONLY    1
#  define  VG_IONIZE_FLAG_HPOSENDRES    2
#  define  VG_IONIZE_FLAG_IUPACNAMES    4
#  define  VG_IONIZE_FLAG_QUIET         8

/**** Special atom types ****/

#  ifdef LITTLE_ENDIAN
#    define  VG_PKSIMPLE_FF_N3amip      MakeInt64(0x00002b696d61334e)
#    define  VG_PKSIMPLE_FF_Namarp      MakeInt64(0x00002b72616d614e)
#    define  VG_PKSIMPLE_FF_Nguap       MakeInt64(0x0000002b6175674e)
#  else
#    define  VG_PKSIMPLE_FF_N3amip      MakeInt64(0x4e33616d692b0000)
#    define  VG_PKSIMPLE_FF_Namarp      MakeInt64(0x4e616d61722b0000)
#    define  VG_PKSIMPLE_FF_Nguap       MakeInt64(0x4e6775612b000000)
#  endif

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_Ionize                          _VG_Ionize
#    define  VG_IonizeParmFree                  _VG_IonizeParmFree
#    define  VG_IonizeFast                      _VG_IonizeFast
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_Ionize(VG_CTX *Ctx, HD_ULONG *Changes, HD_LONG Method, HD_FLOAT pH, HD_FLOAT pHTol, HD_LONG Flags);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_IonizeParmFree(HD_VOID);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_IonizeFast(VG_CTX *Ctx, HD_ULONG *Changes, HD_FLOAT pH, HD_FLOAT pHTol, HD_LONG Flags);

#  ifdef __cplusplus
}
#  endif

#endif
