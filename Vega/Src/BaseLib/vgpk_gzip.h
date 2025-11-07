
/*************************************************
****         VEGA - Interface to zlib         ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __PK_GZIP_H
#  define  __PK_GZIP_H

#  include "../Zlib/zlib.h"

/**** Create context flags ****/

#define  PKM_FLG_NONE           0
#define  PKM_FLG_KEEPOUTBUF     1

/**** Memory compression context ****/

typedef struct {
  int                   m_transparent;
  int                   Flags;
  int                   ModePack;
  int                   UseFastMem;
  char *                InBuf;
  int                   m_pos;
  int                   m_z_eof;
  int                   m_z_err;
  int                   t_nLevel;
  int                   t_nStrategy;
  char *                OutBuf;
  size_t                OutLen;
  size_t                InLen;
  unsigned char *       m_inbuf;
  unsigned char *       m_outbuf;
  unsigned int          m_crc;
  unsigned int          m_CurrentBufferSize;
  unsigned int          t_nBufferLength;
  z_stream              m_zstream;
} PK_MEMGZIP;

#if defined(LINUX) || defined(WIN32)
#  ifdef LINUX
#    define  VGZ_WINAPI
#  else
#    define  VGZ_WINAPI      WINAPI
#  endif

/**** Library function pointers ****/

extern uLong           (VGZ_WINAPI *VG_crc32)(uLong, const Bytef *, uInt);
extern int             (VGZ_WINAPI *VG_deflate)(z_streamp, int);
extern int             (VGZ_WINAPI *VG_deflateEnd)(z_streamp);
extern int             (VGZ_WINAPI *VG_deflateInit2_)(z_streamp, int, int, int, int, int, const char *, int);
extern int             (VGZ_WINAPI *VG_inflate)(z_streamp, int);
extern int             (VGZ_WINAPI *VG_inflateEnd)(z_streamp);
extern int             (VGZ_WINAPI *VG_inflateInit2_)(z_streamp, int, const char *, int);
extern int             (VGZ_WINAPI *VG_inflateReset)(z_streamp);
extern int             (VGZ_WINAPI *VG_gzclose)(gzFile);
extern const char *    (VGZ_WINAPI *VG_gzerror)(gzFile, int *);
extern char *          (VGZ_WINAPI *VG_gzgets)(gzFile, char *, int);
extern gzFile          (VGZ_WINAPI *VG_gzopen)(const char *, const char *);
extern int             (VGZ_WINAPI *VG_gzread)(gzFile, voidp, unsigned);
extern int             (VGZ_WINAPI *VG_gzwrite)(gzFile, const voidp, unsigned);

#else

#  define  VG_gzinit(X)
#  define  VG_crc32             crc32
#  define  VG_deflate           deflate
#  define  VG_deflateEnd        deflateEnd
#  define  VG_deflateInit2_     deflateInit2_
#  define  VG_inflate           inflate
#  define  VG_inflateEnd        inflateEnd
#  define  VG_inflateInit2_     inflateInit2_
#  define  VG_inflateReset      inflateReset
#  define  VG_gzclose           gzclose
#  define  VG_gzerror           gzerror
#  define  VG_gzgets            gzgets
#  define  VG_gzopen            gzopen
#  define  VG_gzread            gzread
#  define  VG_gzwrite           gzwrite

#endif

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_GZM_CreateContext               _VG_GZM_CreateContext
#    define  VG_GZM_DestroyContext              _VG_GZM_DestroyContext
#    define  VG_GZM_Pack                        _VG_GZM_Pack
#    define  VG_GZM_UnPack                      _VG_GZM_UnPack
#    define  VG_GzInit                          _VG_GzInit
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN PK_MEMGZIP *    VEGA_EXPORT VG_GZM_CreateContext(HD_CHAR *Data, HD_LONG Len, HD_LONG Flags);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_GZM_DestroyContext(PK_MEMGZIP *Ctx);
VEGA_EXTERN HD_LONG         VEGA_EXPORT VG_GZM_Pack(PK_MEMGZIP *Ctx);
VEGA_EXTERN HD_LONG         VEGA_EXPORT VG_GZM_UnPack(PK_MEMGZIP *Ctx);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_GzInit(HD_VOID);

#  ifdef __cplusplus
}
#  endif
#endif
