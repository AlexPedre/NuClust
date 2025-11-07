
/*************************************************
****        VEGA - Memory I/O routines        ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/

#ifndef __VG_MEMIO_H
#  define  __VG_MEMIO_H

/**** Types ****/

typedef HD_CHAR *       (VEGA_EXPORT *VIO_FGETS)(HD_CHAR *, HD_LONG, FILE *);
typedef HD_ULONG        (VEGA_EXPORT *VIO_FREAD)(HD_VOID *, HD_ULONG, HD_ULONG, FILE *);
typedef HD_LONG         (VEGA_EXPORT *VIO_FSEEK)(FILE *, HD_LONG, HD_LONG);
typedef HD_LONG         (VEGA_EXPORT *VIO_FSEEKO64)(FILE *, HD_DLONG, HD_LONG);
typedef HD_LONG         (VEGA_EXPORT *VIO_FTELL)(FILE *);
typedef HD_DLONG        (VEGA_EXPORT *VIO_FTELLO64)(FILE *);
typedef HD_ULONG        (VEGA_EXPORT *VIO_FWRITE)(const HD_VOID *, HD_ULONG, HD_ULONG, FILE *);

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_FgetsMem                        _VG_FgetsMem
#    define  VG_ForRead                         _VG_ForRead
#    define  VG_ForSeek                         _VG_ForSeek
#    define  VG_ForWrite                        _VG_ForWrite
#    define  VG_Fread                           _VG_Fread
#    define  VG_FreadMem                        _VG_FreadMem
#    define  VG_Fseek                           _VG_Fseek
#    define  VG_FseekMem                        _VG_FseekMem
#    define  VG_Fseeko64                        _VG_Fseeko64
#    define  VG_Fseeko64Mem                     _VG_Fseeko64Mem
#    define  VG_Ftell                           _VG_Ftell
#    define  VG_FtellMem                        _VG_FtellMem
#    define  VG_Ftello64                        _VG_Ftello64
#    define  VG_Ftello64Mem                     _VG_Ftello64Mem
#    define  VG_Fwrite                          _VG_Fwrite
#    define  VG_FwriteMem                       _VG_FwriteMem
#    define  VG_SkipLines                       _VG_SkipLines
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_CHAR *       VEGA_EXPORT VG_FgetsMem(HD_CHAR *Str, HD_LONG StrLen, FILE *FH);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_ForRead(FILE *FH, HD_VOID *Ptr, HD_ULONG Len, VIO_FREAD MyRead, VIO_FSEEK MySeek);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_ForSeek(FILE *FH, HD_ULONG Rec, HD_BOOL SwapEndian, VIO_FREAD MyRead, VIO_FSEEK MySeek);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_ForWrite(FILE *FH, const HD_VOID *Num, HD_ULONG Size, VIO_FWRITE MyWrite);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_Fread(HD_VOID *Ptr, HD_ULONG Size, HD_ULONG NElem, FILE *FH);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_FreadMem(HD_VOID *Ptr, HD_ULONG Size, HD_ULONG NElem, FILE *FH);
VEGA_EXTERN HD_LONG         VEGA_EXPORT VG_Fseek(FILE *FH, HD_LONG Offset, HD_LONG Mode);
VEGA_EXTERN HD_LONG         VEGA_EXPORT VG_FseekMem(FILE *FH, HD_LONG Offset, HD_LONG Mode);
VEGA_EXTERN HD_LONG         VEGA_EXPORT VG_Fseeko64(FILE *FH, HD_DLONG Offset, HD_LONG Mode);
VEGA_EXTERN HD_LONG         VEGA_EXPORT VG_Fseeko64Mem(FILE *FH, HD_DLONG Offset, HD_LONG Mode);
VEGA_EXTERN HD_LONG         VEGA_EXPORT VG_Ftell(FILE *FH);
VEGA_EXTERN HD_LONG         VEGA_EXPORT VG_FtellMem(FILE *FH);
VEGA_EXTERN HD_DLONG        VEGA_EXPORT VG_Ftello64(FILE *FH);
VEGA_EXTERN HD_DLONG        VEGA_EXPORT VG_Ftello64Mem(FILE *FH);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_Fwrite(const HD_VOID *Ptr, HD_ULONG Size, HD_ULONG NElem, FILE *FH);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_FwriteMem(const HD_VOID *Ptr, HD_ULONG Size, HD_ULONG NElem, FILE *FH);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_SkipLines(FILE *FH, HD_CHAR *Buf, HD_ULONG BufLen, HD_ULONG Lines, VIO_FGETS MyGets);

#  ifdef __cplusplus
}
#  endif
#endif
