
/*******************************************
****     HyperDrive - License header    ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#ifndef __HD_LICENSE_H
#  define  __HD_LICENSE_H

#  ifndef __HDRIVE_H
#    include "hyperdrive.h"
#  endif

#  ifndef __HD_TIME_H
#    include "hdtime.h"
#  endif

/**** Constants ****/

#  define  HD_LIC_SIGS                  16
#  define  HD_LIC_MAGIC0                0x3422a1b7
#  define  HD_LIC_MAGIC1                0xfd3304c9

/**** Product key flags ****/

#  define  HD_LIC_PFLAG_UNIV            1
#  define  HD_LIC_PFLAG_LIVECD          2

/**** IFF key data ****/

#  ifdef HD_LITTLE_ENDIAN

#    define  HD_LIC_IFF_FORM            0x4d524f46
#    define  HD_LIC_IFF_AKEY            0x59454b41
#    define  HD_LIC_IFF_CKEY            0x59454b43
#    define  HD_LIC_IFF_LICE            0x4543494c
#    define  HD_LIC_IFF_USER            0x52455355

#  else

#    define  HD_LIC_IFF_FORM            0x464f524d
#    define  HD_LIC_IFF_AKEY            0x414b4559
#    define  HD_LIC_IFF_CKEY            0x434b4559
#    define  HD_LIC_IFF_LICE            0x4c494345
#    define  HD_LIC_IFF_USER            0x55534552

#  endif

/**** Product IDs ****/

#  define  HD_LIC_PID_VEGAZZ            1
#  define  HD_LIC_PID_UNIV              0xff

/**** Operating system IDs ****/

#  define  HD_LIC_OSID_AMIGA            2
#  define  HD_LIC_OSID_LINUX            3
#  define  HD_LIC_OSID_SGI              1
#  define  HD_LIC_OSID_WINDOWS          4
#  define  HD_LIC_OSID_UNKNOWN          99
#  define  HD_LIC_OSID_UNIV             0xff

/**** Default operating system ID ****/

#  ifdef AMIGA
#    define  HD_LIC_DEF_OSID            HD_LIC_OSID_AMIGA
#  else
#    ifdef linux
#      define  HD_LIC_DEF_OSID          HD_LIC_OSID_LINUX
#    else
#      ifdef sgi
#        define  HD_LIC_DEF_OSID        HD_LIC_OSID_SGI
#      else
#        if defined(_WINDOWS) || defined(WINDOWS) || defined(_WIN32) || defined(_WIN32_)
#          define  HD_LIC_DEF_OSID      HD_LIC_OSID_WINDOWS
#        else
#          define  HD_LIC_DEF_OSID      HD_LIC_OSID_UNKNOWN
#        endif
#      endif
#    endif
#  endif

/**** License errors ****/

#  define  HD_ERR_LIC_EXPIRED         5101 /* Expired license                 */
#  define  HD_ERR_LIC_INVACTKEYCRYP   5102 /* Invalid activation key crypt.   */
#  define  HD_ERR_LIC_INVKEYCRC       5103 /* Invalid key CRC                 */
#  define  HD_ERR_LIC_INVKEYHOST      5104 /* Invalid key host                */
#  define  HD_ERR_LIC_INVPRODKEYENC   5105 /* Invalid product key encoding    */
#  define  HD_ERR_LIC_INVPRODKEYSTR   5106 /* Invalid product key string size */
#  define  HD_ERR_LIC_INVSIGN         5107 /* Invalid signature               */
#  define  HD_ERR_LIC_LIVE            5108 /* Live license                    */

#pragma pack(push, 1)

/**** Host ID ****/

typedef union {
  HD_CHAR          C[6];
  struct _HOSTID {
    HD_ULONG    UL;
    HD_UWORD    UW;
  } HID;
} HD_HOSTID;

/**** Activation key ****/

typedef struct {
  HD_ULONG      Crc;                    /* 32 bit CRC                         */
  HD_ULONG      Id;                     /* Key ID                             */
  HD_ULONG      Days;                   /* Expiration time (days)             */
  HD_HOSTID     HostID;                 /* Host ID (48 bit)                   */
  HD_UBYTE      Flags;                  /* Flags                              */
  HD_UBYTE      MinVer;                 /* Min version                        */
  HD_TIMESTRUCT CreationTime;           /* Creation time                      */
  HD_UBYTE      OsID;                   /* Operating system ID                */
  HD_UBYTE      ProductID;              /* Product ID                         */
  HD_UBYTE      SubProductID;           /* Subproduct ID                      */
  HD_UBYTE      Pad[3];                 /* Pad byte                           */
  HD_UBYTE      Signature[HD_LIC_SIGS]; /* Signature                          */
} HD_LICACTKEY;

/**** Product key ****/

typedef struct {
  HD_UBYTE      CrypyKey;               /* Cryptation key                     */
  HD_UBYTE      OsID;                   /* Operating system ID                */
  HD_UBYTE      ProductID;              /* Product ID                         */
  HD_UBYTE      Flags;                  /* Flags                              */
  HD_HOSTID     HostID;                 /* Host ID (48 bit)                   */
  HD_UWORD      Crc;                    /* 16 bit key CRC                     */
} HD_LICPRODKEY;

#pragma pack(pop)

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_GetHostID               _HD_GetHostID
#    define  HD_LicActCheck             _HD_LicActCheck
#    define  HD_LicActCheckEx           _HD_LicActCheckEx
#    define  HD_LicActKeyLoad           _HD_LicActKeyLoad
#    define  HD_LicActKeyNew            _HD_LicActKeyNew
#    define  HD_LicActKeyToIff          _HD_LicActKeyToIff
#    define  HD_LicGetHostCrc           _HD_LicGetHostCrc
#    define  HD_LicProdKeyCheck         _HD_LicProdKeyCheck
#    define  HD_LicProdKeyCrypt         _HD_LicProdKeyCrypt
#    define  HD_LicProdKeyDecode        _HD_LicProdKeyDecode
#    define  HD_LicProdKeyNew           _HD_LicProdKeyNew
#    define  HD_LicProdKeyToStr         _HD_LicProdKeyToStr
#    define  HD_LicStrToProdKey         _HD_LicStrToProdKey
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_BOOL         HDRIVE_EXPORT HD_CompareHostID(HD_HOSTID *H1, HD_HOSTID *H2);
HDRIVE_EXTERN HD_VOID         HDRIVE_EXPORT HD_GetHostID(HD_HOSTID *HostID);
HDRIVE_EXTERN HD_BOOL         HDRIVE_EXPORT HD_LicActCheck(HD_LICACTKEY *ActKey, HD_ULONG SignCrc);
HDRIVE_EXTERN HD_BOOL         HDRIVE_EXPORT HD_LicActCheckEx(HD_LICACTKEY *ActKey, HD_ULONG SignCrc, HD_HOSTID *HostID);
HDRIVE_EXTERN HD_LICACTKEY *  HDRIVE_EXPORT HD_LicActKeyLoad(HD_CHAR *FileName, HD_LICPRODKEY *ProdKey, HD_LICPRODKEY *ProdKeyUniv, HD_UBYTE **UserData, HD_ULONG *UserDataSize);
HDRIVE_EXTERN HD_LICACTKEY *  HDRIVE_EXPORT HD_LicActKeyNew(HD_LICPRODKEY *ProdKey, HD_ULONG Id, HD_ULONG Days, HD_ULONG CurTime, HD_UBYTE Flags, HD_UBYTE SubProductID, const HD_UBYTE *Signature);
HDRIVE_EXTERN HD_VOID *       HDRIVE_EXPORT HD_LicActKeyToIff(HD_ULONG *Size, HD_LICACTKEY *ActKey, HD_LICPRODKEY *ProdKey, HD_CHAR *Msg);
HDRIVE_EXTERN HD_UWORD        HDRIVE_EXPORT HD_LicGetHostCrc(HD_VOID);
HDRIVE_EXTERN HD_BOOL         HDRIVE_EXPORT HD_LicProdKeyCheck(HD_LICPRODKEY *ProdKey);
HDRIVE_EXTERN HD_BOOL         HDRIVE_EXPORT HD_LicProdKeyCrypt(HD_LICPRODKEY *ProdKey);
HDRIVE_EXTERN HD_BOOL         HDRIVE_EXPORT HD_LicProdKeyDecode(HD_LICPRODKEY *ProdKey);
HDRIVE_EXTERN HD_LICPRODKEY * HDRIVE_EXPORT HD_LicProdKeyNew(HD_UBYTE OsID, HD_UBYTE ProductID, HD_UBYTE Flags);
HDRIVE_EXTERN HD_CHAR *       HDRIVE_EXPORT HD_LicProdKeyToStr(HD_LICPRODKEY *ProdKey);
HDRIVE_EXTERN HD_LICPRODKEY * HDRIVE_EXPORT HD_LicStrToProdKey(const HD_CHAR *Str);

#  ifdef __cplusplus
   }
#  endif
#endif

