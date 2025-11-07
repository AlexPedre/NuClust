
/*********************************************
****       HyperDrive - IFF/RIFF I/O      ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifndef __HDIFF_H
#  define  __HDIFF_H

#  ifndef __HDRIVE_H
#    include "hyperdrive.h"
#  endif

/**** Flags for HD_IffCreate() ****/

#define  HD_IFF_NONE                    0  /* None                            */
#define  HD_IFF_64BIT                   1  /* Use 64 bit chunks               */
#define  HD_IFF_APPEND                  2  /* Append the complete new file    */
#define  HD_IFF_LITTLEENDIAN            4  /* Little endian numeric format    */
#define  HD_IFF_READ                    8  /* Create handle for read          */
#define  HD_IFF_WRITE                  16  /* Create file for write           */

/**** Chunks ****/

#  ifdef HD_LITTLE_ENDIAN
#    define  HD_IFF_CHUNK_64BT      0x54423436
#    define  HD_IFF_CHUNK_64BTFORM  MakeInt64(0x4d524f4654423436)
#    define  HD_IFF_CHUNK_64BTRIFF  MakeInt64(0x4646495254423436)
#    define  HD_IFF_CHUNK_FORM      0x4d524f46
#    define  HD_IFF_CHUNK_RIFF      0x46464952

#    define  HD_IffMakeChunk(a, b, c, d)        (a | (b << 8) | (c << 16) | (d << 24))
#  else
#    define  HD_IFF_CHUNK_64BT      0x36344254
#    define  HD_IFF_CHUNK_64BTFORM  MakeInt64(0x36344254464f524d)
#    define  HD_IFF_CHUNK_64BTRIFF  MakeInt64(0x3634425452494646)
#    define  HD_IFF_CHUNK_FORM      0x464f524d
#    define  HD_IFF_CHUNK_RIFF      0x52494646

#    define  HD_IffMakeChunk(a, b, c, d)        (d | (c << 8) | (b << 16) | (a << 24))
#  endif

/**** IFF handle ****/

typedef void *          HD_IFF;

/**** I/O functions ****/

typedef struct {
  HD_VOID       (HD_CALLBACK *Close)(HD_VOID *Handle);
  HD_VOID *     (HD_CALLBACK *Open)(const HD_CHAR *FileName, const HD_CHAR *Mode);
  HD_ULONG      (HD_CALLBACK *Read)(HD_VOID *Handle, HD_VOID *Ptr, HD_ULONG Size);
  HD_LONG       (HD_CALLBACK *Seek64)(HD_VOID *Handle, HD_DLONG Offset, HD_LONG Whence);
  HD_DLONG      (HD_CALLBACK *Tell64)(HD_VOID *Handle);
  HD_ULONG      (HD_CALLBACK *Write)(HD_VOID *Handle, HD_VOID *Ptr, HD_ULONG Size);
} HD_IFFFUNC;

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_IffClose                _HD_IffClose
#    define  HD_IffCreate               _HD_IffCreate
#    define  HD_IffCreateEx             _HD_IffCreateEx
#    define  HD_IffRead                 _HD_IffRead
#    define  HD_IffReadChunk            _HD_IffReadChunk
#    define  HD_IffSeek                 _HD_IffSeek
#    define  HD_IffSetIO                _HD_IffSetIO
#    define  HD_IffTell                 _HD_IffTell
#    define  HD_IffWriteChunk           _HD_IffWriteChunk
#    define  HD_IffWrite                _HD_IffWrite
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_IffClose(HD_IFF Iff);
HDRIVE_EXTERN HD_IFF            HDRIVE_EXPORT HD_IffCreate(const HD_CHAR *FileName, const HD_CHAR *Format, HD_LONG Flags);
HDRIVE_EXTERN HD_IFF            HDRIVE_EXPORT HD_IffCreateEx(const HD_CHAR *FileName, const HD_CHAR *Format, HD_LONG Flags, HD_IFFFUNC *FuncList);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_IffRead(HD_IFF hIff, HD_VOID *Array, HD_ULONG ArrayLen, HD_ULONG Size);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_IffReadChunk(HD_IFF hIff, HD_OCHAR *ChunkName, HD_UDLONG *ChunkSize);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_IffSeek(HD_IFF hIff, HD_DLONG Offset, HD_LONG Whence);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_IffSetIO(HD_IFFFUNC *FuncList);
HDRIVE_EXTERN HD_DLONG          HDRIVE_EXPORT HD_IffTell(HD_IFF hIff);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_IffWrite(HD_IFF hIff, HD_VOID *Array, HD_ULONG ArrayLen, HD_ULONG Size);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_IffWriteChunk(HD_IFF hIff, const HD_CHAR *ChunkName, HD_UDLONG ChunkSize);

#  ifdef __cplusplus
   }
#  endif
#endif

