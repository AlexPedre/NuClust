
/*******************************************
****      HyperDrive - MD5 routines     ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#ifndef __HD_MD5_H
#  define  __HD_MD5_H

#  include <hyperdrive.h>

/**** MD5 context ****/

typedef void *  HD_MD5CTX;

/**** MD5 checksum ****/

typedef union {
  HD_UBYTE      UB[16];
  HD_UDLONG     UDL[2];
  HD_ULONG      UL[4];
} HD_MD5;

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_StrToMd5                _HD_StrToMd5
#    define  HD_StrToMd5C               _HD_StrToMd5C
#    define  HD_Md5Append               _HD_Md5Append
#    define  HD_Md5Finish               _HD_Md5Finish
#    define  HD_Md5File                 _HD_Md5File
#    define  HD_Md5FileC                _HD_Md5FileC
#    define  HD_Md5Free                 _HD_Md5Free
#    define  HD_Md5Init                 _HD_Md5Init
#    define  HD_Md5Mem                  _HD_Md5Mem
#    define  HD_Md5Reset                _HD_Md5Reset
#    define  HD_Md5Str                  _HD_Md5Str
#    define  HD_Md5StrC                 _HD_Md5StrC
#    define  HD_Md5StrCW                _HD_Md5StrCW
#    define  HD_Md5ToStr                _HD_Md5ToStr
#    define  HD_Md5ToStrC               _HD_Md5ToStrC
#    define  HD_Md5WStr                 _HD_Md5WStr
#endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Md5Append(HD_MD5CTX hMd5, HD_VOID *DataBlock, HD_LONG Len);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Md5Finish(HD_MD5CTX hMd5, HD_MD5 *Md5);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Md5File(HD_MD5 *Md5, HD_STRING FileName);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Md5FileC(HD_MD5 *Md5, const HD_CHAR *FileName);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Md5Free(HD_MD5CTX hMd5);
HDRIVE_EXTERN HD_MD5CTX         HDRIVE_EXPORT HD_Md5Init(HD_VOID);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Md5Mem(HD_MD5 *Md5, const HD_VOID *Mem, HD_ULONG Len);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_Md5Reset(HD_MD5CTX hMd5);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Md5Str(HD_MD5 *Md5, HD_STRING Str);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Md5StrC(HD_MD5 *Md5, const HD_CHAR *Str);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT HD_Md5ToStr(HD_STRING Str, HD_MD5 *Md5);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Md5ToStrC(HD_CHAR *Str, HD_MD5 *Md5);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_StrToMd5(HD_MD5 *Md5, HD_STRING Str);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_StrToMd5C(HD_MD5 *Md5, HD_CHAR *Str);

#  ifndef AMIGA
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Md5StrCW(HD_MD5 *Md5, const HD_WCHAR *Str);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Md5WStr(HD_MD5 *Md5, HD_WSTRING Str);
#  endif

#  ifdef __cplusplus
   }
#  endif
#endif

