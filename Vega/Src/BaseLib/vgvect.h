
/*************************************************
****          VEGA - Vector routines          ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_VECT_H
#  define  __VG_VECT_H

/**** Macros ****/

#  define  VG_XyzScalar(V, S)             (V).x *= (S); \
                                          (V).y *= (S); \
                                          (V).z *= (S);
#  define  VG_XyzSum(S, V1, V2)           (S).x = (V1).x + (V2).x; \
                                          (S).y = (V1).y + (V2).y; \
                                          (S).z = (V1).z + (V2).z;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_XyzCrossProd                    _VG_XyzCrossProd
#    define  VG_XyzMagnitude                    _VG_XyzMagnitude
#    define  VG_XyzNormalize                    _VG_XyzNormalize
#    define  VG_XyzRotZ                         _VG_XyzRotZ
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_XyzCrossProd(HD_XYZF *Normal, HD_XYZF *Vect1, HD_XYZF *Vect2);
VEGA_EXTERN HD_FLOAT        VEGA_EXPORT VG_XyzMagnitude(HD_XYZF *V0);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_XyzNormalize(HD_XYZF *V0);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_XyzRotZ(HD_XYZF *V, HD_FLOAT Rot);

#  ifdef __cplusplus
}
#  endif
#endif

