
/*******************************************
****    HyperDrive - Base64 routines    ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#ifndef __HD_BASE64_H
#  define  __HD_BASE64_H

#  include <hyperdrive.h>

/**** HD_Base64EncodeFile() and HD_Base64EncodeMem() flags */

#  define  HD_B64ENC_DEFAULT            0
#  define  HD_B64ENC_LF                 1
#  define  HD_B64ENC_CR                 2

#  define  HD_B64ENC_CRLF               (HD_B64ENC_LF | HD_B64ENC_CR)

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_Base64DecodeFile        _HD_Base64DecodeFile
#    define  HD_Base64DecodeMem         _HD_Base64DecodeMem
#    define  HD_Base64EncodeFile        _HD_Base64EncodeFile
#    define  HD_Base64EncodeMem         _HD_Base64EncodeMem
#endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

/**** Base64 encoding/decoding ****/

HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_Base64DecodeFile(const HD_CHAR *InFileName, const HD_CHAR *OutFileName);
HDRIVE_EXTERN HD_VOID *           HDRIVE_EXPORT HD_Base64DecodeMem(HD_LONG *MemDecSize, const HD_CHAR *StrEnc, HD_ULONG StrEncLen);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_Base64EncodeFile(const HD_CHAR *InFileName, const HD_CHAR *OutFileName, HD_LONG LineSize, HD_LONG Flags);
HDRIVE_EXTERN HD_CHAR *           HDRIVE_EXPORT HD_Base64EncodeMem(HD_ULONG *MemEncSize, HD_VOID *MemDec, HD_ULONG MemDecSize, HD_ULONG LineSize, HD_LONG Flags);

#  ifdef __cplusplus
   }
#  endif
#endif
