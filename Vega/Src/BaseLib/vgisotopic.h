
/*************************************************
****  VEGA - Isotopic distribution calculator ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/

#ifndef __VG_ISOTOPIC_H
#  define  __VG_ISOTOPIC_H

#  include <hdisotopic.h>
#  include <hdstring.h>

/**** Constants ****/

#  define  VG_ISO_MAXPEAKS              50      /* Max. number of peaks isotopic distrib.    */
#  define  VG_ISO_THRESHPERC          0.01      /* Probability threshold                     */

/**** VG_IsotopicCalc() flags ****/

#  define  VG_ISOCALC_FORMULA           0
#  define  VG_ISOCALC_MOLECULE          1

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_IsotopicCalc                    _VG_IsotopicCalc
#    define  VG_IsotopicFree                    _VG_IsotopicFree
#    define  VG_IsoPeaksToStr                   _VG_IsoPeaksToStr
#    define  VG_MonoIsotopicCalc                _VG_MonoIsotopicCalc
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

VEGA_EXTERN HD_LIST *       VEGA_EXPORT VG_IsotopicCalc(HD_VOID *What, HD_DOUBLE Charge, HD_LONG Flags);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_IsotopicFree(HD_VOID);
VEGA_EXTERN HD_STRING       VEGA_EXPORT VG_IsoPeaksToStr(HD_LIST *PeakList);
VEGA_EXTERN HD_DOUBLE       VEGA_EXPORT VG_MonoIsotopicCalc(HD_VOID *What, HD_LONG Flags);

#  ifdef __cplusplus
   }
#  endif


#endif
