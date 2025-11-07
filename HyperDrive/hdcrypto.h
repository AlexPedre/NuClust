
/*******************************************
**** HyperDrive - Cryptography routines ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#ifndef __HDCRYPTO_H
#  define  __HDCRYPTO_H

#  include <hyperdrive.h>

/*
 * TEA Key must be 128 bit long (HD_ULONG [4])
 */

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_EncryptSimple           _HD_EncryptSimple
#    define  HD_TeaGenKey               _HD_TeaGenKey
#    define  HD_XTeaDecrypt             _HD_XTeaDecrypt
#    define  HD_XTeaEncrypt             _HD_XTeaEncrypt
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

/**** Prototypes ****/

HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_EncryptSimple(HD_UBYTE *Data, HD_ULONG Size, HD_UBYTE Key);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_TeaGenKey(HD_ULONG *Key);
HDRIVE_EXTERN HD_VOID *           HDRIVE_EXPORT HD_XTeaDecrypt(HD_VOID *Data, HD_ULONG Size, const HD_VOID *EncData, const HD_ULONG EncSize, const HD_ULONG *Key);
HDRIVE_EXTERN HD_VOID *           HDRIVE_EXPORT HD_XTeaEncrypt(HD_VOID *EncData, HD_ULONG *EncSize, const HD_VOID *Data, const HD_ULONG Size, const HD_ULONG *Key);

#  ifdef __cplusplus
   }
#  endif
#endif
