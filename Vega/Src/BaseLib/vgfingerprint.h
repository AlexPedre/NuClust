
/*************************************************
****           VEGA - Fingerprint             ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_FINGERPRINT
#  define  __VG_FINGERPRINT

/**** Fingerprint ASCII encoding VG_IndigoFingerprintStr() ****/

#  define  VG_FPSTRENC_BASE64           0 /* Don't change the order ! */
#  define  VG_FPSTRENC_HEX              1

/**** Fingerprint similarity methods ****/

#  define  VG_FPSIMMET_EUCLIDSUB        0 /* Don't change the order */
#  define  VG_FPSIMMET_TANIMOTO         1
#  define  VG_FPSIMMET_TVERSKY          2

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_Fp2Str                          _VG_Fp2Str
#    define  VG_FpAlloc                         _VG_FpAlloc
#    define  VG_FpFree                          _VG_FpFree
#    define  VG_FpFromChar                      _VG_FpFromChar
#    define  VG_FpFromIndigo                    _VG_FpFromIndigo
#    define  VG_FpFromVega                      _VG_FpFromVega
#    define  VG_FpSimilarity                    _VG_FpSimilarity
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_STRING       VEGA_EXPORT VG_Fp2Str(HD_STRING Str, const VG_FINGERPRINT Fp, HD_LONG Encoding);
VEGA_EXTERN VG_FINGERPRINT  VEGA_EXPORT VG_FpAlloc(HD_ULONG Len);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_FpFree(VG_FINGERPRINT Fp);
VEGA_EXTERN VG_FINGERPRINT  VEGA_EXPORT VG_FpFromChar(const HD_CHAR *FpStr, HD_LONG Encoding);
VEGA_EXTERN VG_FINGERPRINT  VEGA_EXPORT VG_FpFromIndigo(HD_LONG Ifp);
VEGA_EXTERN VG_FINGERPRINT  VEGA_EXPORT VG_FpFromVega(HD_ATOM *InizAtm, HD_LONG Type);
VEGA_EXTERN HD_FLOAT        VEGA_EXPORT VG_FpSimilarity(VG_FINGERPRINT Fp1, VG_FINGERPRINT Fp2, HD_LONG Method, HD_FLOAT Alpha, HD_FLOAT Beta);

#  ifdef __cplusplus
}
#  endif
#endif

