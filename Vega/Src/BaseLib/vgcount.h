
/*************************************************
****            VEGA - Count header           ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_COUNT_H
#  define  __VG_COUNT_H

#  include "vgatom.h"

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_CountActiveAtms                 _VG_CountActiveAtms
#    define  VG_CountAminoAcids                 _VG_CountAminoAcids
#    define  VG_CountBndFreeOx                  _VG_CountBndFreeOx
#    define  VG_CountBndHeavyAtms               _VG_CountBndHeavyAtms
#    define  VG_CountBndHyd                     _VG_CountBndHyd
#    define  VG_CountChain                      _VG_CountChain
#    define  VG_CountChiral                     _VG_CountChiral
#    define  VG_CountGeomEz                     _VG_CountGeomEz
#    define  VG_CountWat                        _VG_CountWat
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_CountActiveAtms(HD_ATOM *Atm);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_CountAminoAcids(HD_ATOM *Atm, HD_LONG *AaNum, HD_ULONG *AaNumTot,
                                                           HD_FLOAT *AaMass, HD_FLOAT *AaMassTot, HD_BOOL ActiveOnly);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_CountBndFreeOx(HD_ATOM *Atm);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_CountBndHeavyAtms(HD_ATOM *Atm);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_CountBndHyd(HD_ATOM *Atm);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_CountChain(HD_ATOM *Atm);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_CountChiral(HD_ATOM *Atm);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_CountGeomEz(HD_ATOM *Atm);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_CountWat(HD_ATOM *Atm);

#  ifdef __cplusplus
}
#  endif
#endif
