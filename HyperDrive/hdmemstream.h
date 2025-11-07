
/********************************************
**** HyperDrive - Memory stream routines ****
**** (c) 2004-2025, Alessandro Pedretti  ****
********************************************/


#ifndef __HD_MEMSTREAM_H
#  define  __HD_MEMSTREAM_H

#  include <stdarg.h>
#  include <hdstring.h>

/**** File modes ****/

#  define  HD_STREAM_NONE               0
#  define  HD_STREAM_APPEND             1
#  define  HD_STREAM_BINARY             2
#  define  HD_STREAM_KEEPFIRSTBLK       4
#  define  HD_STREAM_OVERWRITE          8
#  define  HD_STREAM_READ              16
#  define  HD_STREAM_WRITE             32

/**** Seek modes ****/

#  define  HD_STREAM_SEEK_CUR           1
#  define  HD_STREAM_SEEK_END           2
#  define  HD_STREAM_SEEK_SET           0

/**** Text files ****/

#  define  HD_STREAM_TXT_AMIGA          0
#  define  HD_STREAM_TXT_UNIX           0
#  define  HD_STREAM_TXT_WINDOWS        1
#  define  HD_STREAM_TXT_MAC            2
#  define  HD_STREAM_TXT_NET            1

#  ifdef MACOS
#    define  HD_STREAM_TXT_DEFAULT      HDSTREAM_TXT_MAC
#  endif

#  ifdef WIN32
#    define  HD_STREAM_TXT_DEFAULT      HD_STREAM_TXT_WINDOWS
#  endif

#  ifndef HD_STREAM_TXT_DEFAULT
#    define  HD_STREAM_TXT_DEFAULT      HD_STREAM_TXT_UNIX
#  endif


/**** Memory block ****/

typedef struct __hd_memblock {
  struct __hd_memblock *        Next;
  struct __hd_memblock *        Prev;
  HD_BYTE *                     Data;           /* Data pointer               */
} HD_MEMBLOCK;

/**** Memory stream handle ****/

struct __hd_memstream {
  HD_LIST *                     BlockList;      /* Block list                 */
  HD_MEMBLOCK *                 BlockCur;       /* Current block              */
  HD_SIZE                       BlockCurPos;    /* Current block position     */
  HD_SIZE                       BlockSize;      /* Block size                 */
  HD_SIZE                       Pos;            /* Stream position            */
  HD_SIZE                       Size;           /* Stream size                */
  HD_LONG                       AccFlags;       /* Stream flags               */
  HD_LONG                       TextMode;       /* Text mode                  */
};

typedef struct __hd_memstream * HD_MEMSTREAM;

/**** Macros ****/

#  define  HD_MEMSTREAM_SIZE    sizeof(struct __hd_memstream)

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_MemStreamClose          _HD_MemStreamClose
#    define  HD_MemStreamGetc           _HD_MemStreamGetc
#    define  HD_MemStreamGets           _HD_MemStreamGets
#    define  HD_MemStreamGetsC          _HD_MemStreamGetsC
#    define  HD_MemStreamOpen           _HD_MemStreamOpen
#    define  HD_MemStreamOpenVect       _HD_MemStreamOpenVect
#    define  HD_MemStreamPrint          _HD_MemStreamPrint
#    define  HD_MemStreamPrintC         _HD_MemStreamPrintC
#    define  HD_MemStreamPuts           _HD_MemStreamPuts
#    define  HD_MemStreamPutsC          _HD_MemStreamPutsC
#    define  HD_MemStreamRead           _HD_MemStreamRead
#    define  HD_MemStreamSeek           _HD_MemStreamSeek
#    define  HD_MemStreamVPrint         _HD_MemStreamVPrint
#    define  HD_MemStreamVPrintC        _HD_MemStreamVPrintC
#    define  HD_MemStreamWrite          _HD_MemStreamWrite
#    define  HD_MemStreamWriteByte      _HD_MemStreamWriteByte
#    define  HD_MemStreamWriteText      _HD_MemStreamWriteText
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT  HD_MemStreamClose(HD_MEMSTREAM Stream);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_MemStreamGetc(HD_MEMSTREAM Stream);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_MemStreamGets(HD_MEMSTREAM Stream, HD_STRING Str);
HDRIVE_EXTERN HD_CHAR *         HDRIVE_EXPORT  HD_MemStreamGetsC(HD_MEMSTREAM Stream, HD_CHAR *Str, HD_LONG Len);
HDRIVE_EXTERN HD_MEMSTREAM      HDRIVE_EXPORT  HD_MemStreamOpen(HD_LONG Flags);
HDRIVE_EXTERN HD_MEMSTREAM      HDRIVE_EXPORT  HD_MemStreamOpenVect(HD_VOID *Vect, HD_SIZE VectSize, HD_LONG Flags);
HDRIVE_EXTERN HD_SIZE           HDRIVE_EXPORTV HDRIVE_USCOREV(HD_MemStreamPrint)(HD_MEMSTREAM Stream, HD_STRING Fmt, ...);
HDRIVE_EXTERN HD_SIZE           HDRIVE_EXPORTV HDRIVE_USCOREV(HD_MemStreamPrintC)(HD_MEMSTREAM Stream, HD_CHAR *Fmt, ...);
HDRIVE_EXTERN HD_SIZE           HDRIVE_EXPORT  HD_MemStreamPuts(HD_MEMSTREAM Stream, HD_STRING Str);
HDRIVE_EXTERN HD_SIZE           HDRIVE_EXPORT  HD_MemStreamPutsC(HD_MEMSTREAM Stream, const HD_CHAR *Str);
HDRIVE_EXTERN HD_SIZE           HDRIVE_EXPORT  HD_MemStreamRead(HD_MEMSTREAM Stream, HD_VOID *Mem, HD_SIZE Len);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_MemStreamSeek(HD_MEMSTREAM Stream, HD_POS Offset, HD_LONG Origin);
HDRIVE_EXTERN HD_SIZE           HDRIVE_EXPORT  HD_MemStreamVPrint(HD_MEMSTREAM Stream, HD_STRING Fmt, va_list ArgList);
HDRIVE_EXTERN HD_SIZE           HDRIVE_EXPORT  HD_MemStreamVPrintC(HD_MEMSTREAM Stream, const HD_CHAR *Fmt, va_list ArgList);
HDRIVE_EXTERN HD_SIZE           HDRIVE_EXPORT  HD_MemStreamWrite(HD_MEMSTREAM Stream, const HD_VOID *Mem, HD_SIZE Len);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_MemStreamWriteByte(HD_MEMSTREAM Stream, HD_BYTE Data);
HDRIVE_EXTERN HD_SIZE           HDRIVE_EXPORT  HD_MemStreamWriteText(HD_MEMSTREAM Stream, const HD_CHAR *Data, HD_SIZE Len);

#  ifdef __cplusplus
   }
#  endif

/**** C++ wrapper ****/

#  ifdef __cplusplus

/**** MemoryStream class ****/

class HDC_MemStream
{
  public:

        /**** Methods ****/

        inline                          HDC_MemStream(HD_LONG Flags)            { hMem = HD_MemStreamOpen(Flags); }
        inline                          HDC_MemStream(HD_STRING Str, HD_LONG Flags)
                                                                                { hMem = HD_MemStreamOpenVect(Str -> Cstr, Str -> Len, Flags); }
        inline                          HDC_MemStream(HDC_String &Str, HD_LONG Flags)
                                                                                { hMem = HD_MemStreamOpenVect(Str.Cstr(), Str.Len(), Flags); }
        inline                          HDC_MemStream(HD_VOID *Vect, HD_SIZE VectSize, HD_LONG Flags)
                                                                                { hMem = HD_MemStreamOpenVect(Vect, VectSize, Flags); }
        inline                          ~HDC_MemStream(HD_VOID)                 { HD_MemStreamClose(hMem); }
        inline HD_LONG                  Getc(HD_VOID)                           { return HD_MemStreamGetc(hMem); }
        inline HD_BOOL                  Gets(HD_STRING Str)                     { HD_MemStreamGets(hMem, Str); return !HD_StrIsEmpty(Str); }
        inline HD_CHAR *                Gets(HD_CHAR *Str, HD_LONG Len)         { return HD_MemStreamGetsC(hMem, Str, Len); }
        inline HD_BOOL                  Gets(HDC_String &Str)                   { HD_MemStreamGets(hMem, Str.Hdstr()); return !Str.IsEmpty(); }
               HD_VOID                  Print(const HD_CHAR *Fmt, ...)          { va_list Ap;
                                                                                  va_start(Ap, Fmt);
                                                                                  HD_MemStreamVPrintC(hMem, Fmt, Ap);
                                                                                  va_end(Ap);
                                                                                }
               HD_VOID                  Print(const HD_STRING Fmt, ...)         { va_list Ap;
                                                                                  va_start(Ap, Fmt);
                                                                                  HD_MemStreamVPrint(hMem, Fmt, Ap);
                                                                                  va_end(Ap);
                                                                                }
        inline HD_SIZE                  Puts(const HD_CHAR *Str)                { return HD_MemStreamPutsC(hMem, Str); }
        inline HD_SIZE                  Puts(HD_STRING Str)                     { return HD_MemStreamPuts(hMem, Str); }
        inline HD_SIZE                  Puts(HDC_String &Str)                   { return HD_MemStreamPuts(hMem, Str.Hdstr()); }
        inline HD_SIZE                  Read(HD_VOID *Mem, HD_SIZE Len)         { return HD_MemStreamRead(hMem, Mem, Len); }
        inline HD_BOOL                  Seek(HD_POS Offset, HD_LONG Origin)     { return HD_MemStreamSeek(hMem, Offset, Origin); }
        inline HD_SIZE                  Size(HD_VOID)                           { return hMem -> Size; }
        inline HD_SIZE                  Write(const HD_VOID *Mem, HD_SIZE Len)  { return HD_MemStreamWrite(hMem, Mem, Len); }
        inline HD_BOOL                  WriteByte(HD_BYTE Byte)                 { return HD_MemStreamWriteByte(hMem, Byte); }
        inline HD_SIZE                  WriteText(const HD_CHAR *Str, HD_SIZE Len)
                                                                                { return HD_MemStreamWriteText(hMem, Str, Len); }
        /**** VCL methods ****/

#    ifdef VCL_H
        inline                          HDC_MemStream(AnsiString &Str, HD_LONG Flags)
                                                                                { hMem = HD_MemStreamOpenVect(Str.c_str(), Str.Length(), Flags); }

        inline HD_BOOL                  Gets(AnsiString &Str)                   { return (HD_MemStreamGetsC(hMem, Str.c_str(), Str.Length()) != HD_NULL); }
               HD_VOID                  Print(AnsiString &Fmt, ...)             { va_list Ap;
                                                                                  va_start(Ap, Fmt);
                                                                                  HD_MemStreamVPrintC(hMem, Fmt.c_str(), Ap);
                                                                                  va_end(Ap);
                                                                                }
        inline HD_SIZE                  Puts(AnsiString &Str)                   { return HD_MemStreamPutsC(hMem, Str.c_str()); }
#    endif

        /**** Private properties ****/

  private:

        HD_MEMSTREAM                    hMem;
};

#  endif
#endif
