
/*************************************************
****          VEGA - un/packing header        ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


/* Universal data de/compressor engine for VEGA */

#ifndef  __VG_PK_DEF_H
#  define  __VG_PK_DEF_H

#  include "hdtypes.h"

/**** Packing formats ****/

#  define  VG_PK_NONE              0             /* None              */
#  define  VG_PK_BZ2               1             /* BZip2             */
#  define  VG_PK_GZ                2             /* GZip              */
#  define  VG_PK_Z                 3             /* Z Compress        */
#  define  VG_PK_PP                4             /* PowerPacker       */

/**** Packer headres in little-endian format ****/

#  define  VG_PK_HDR_BZIP2         0x425A6830    /* Bzip2 1-9         */
#  define  VG_PK_HDR_COMPRESS      0x1F9D0000    /* Unix Z compress   */
#  define  VG_PK_HDR_GZIP          0x1F8B0000    /* GZip magic number */
#  define  VG_PK_HDR_POWERPACKER   0x50503230    /* PP20              */
#  define  VG_PK_HDR_XPK           0x58504B46    /* XPKF              */

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_ChkPackerName                   _VG_ChkPackerName
#    define  VG_BZ2_DepackFile                  _VG_BZ2_DepackFile
#    define  VG_BZ2_PackFile                    _VG_BZ2_PackFile
#    define  VG_GZ_DepackFile                   _VG_GZ_DepackFile
#    define  VG_GZ_PackFile                     _VG_GZ_PackFile
#    define  VG_PP_DepackFile                   _VG_PP_DepackFile
#    define  VG_PP_PackFile                     _VG_PP_PackFile
#    define  VG_Z_DepackFile                    _VG_Z_DepackFile
#    define  VG_Z_PackFile                      _VG_Z_PackFile
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_LONG         VEGA_EXPORT VG_ChkPackerName(const HD_CHAR *Packer, HD_BOOL Verbose);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_BZ2_DepackFile(const HD_CHAR *Src, const HD_CHAR *Dest);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_BZ2_PackFile(const HD_CHAR *Src, const HD_CHAR *Dest);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_GZ_DepackFile(const HD_CHAR *Src, const HD_CHAR *Dest);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_GZ_PackFile(const HD_CHAR *Src, const HD_CHAR *Dest);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_PP_DepackFile(const HD_CHAR *Src, const HD_CHAR *Dest);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_PP_PackFile(const HD_CHAR *Src, const HD_CHAR *Dest);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_Z_DepackFile(const HD_CHAR *Src, const HD_CHAR *Dest);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_Z_PackFile(const HD_CHAR *Src, const HD_CHAR *Dest);

#  ifdef __cplusplus
}
#  endif
#endif
