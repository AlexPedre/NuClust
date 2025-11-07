
/*********************************************
****  HyperDrive - String argument parser ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifndef __HDARGS_H
#  define  __HDARGS_H

#  include <hyperdrive.h>

/**** Flags ****/

#  define  HD_ARGSFLG_NONE              0       /* None                          */
#  define  HD_ARGSFLG_SINGLESEP         1       /* Single separator without trim */
#  define  HD_ARGSFLG_DECSEPINS         2       /* Decimal separator insensible  */

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_ArgsAlloc               _HD_ArgsAlloc
#    define  HD_ArgsFree                _HD_ArgsFree
#    define  HD_ArgsGetChar             _HD_ArgsGetChar
#    define  HD_ArgsGetCharEx           _HD_ArgsGetCharEx
#    define  HD_ArgsGetDouble           _HD_ArgsGetDouble
#    define  HD_ArgsGetDoubleEx         _HD_ArgsGetDoubleEx
#    define  HD_ArgsGetFloat            _HD_ArgsGetFloat
#    define  HD_ArgsGetFloatEx          _HD_ArgsGetFloatEx
#    define  HD_ArgsGetHexInt           _HD_ArgsGetHexInt
#    define  HD_ArgsGetHexIntEx         _HD_ArgsGetHexIntEx
#    define  HD_ArgsGetInt              _HD_ArgsGetInt
#    define  HD_ArgsGetIntEx            _HD_ArgsGetIntEx
#    define  HD_ArgsGetLongInt          _HD_ArgsGetLongInt
#    define  HD_ArgsGetLongIntEx        _HD_ArgsGetLongIntEx
#    define  HD_ArgsGetDchar            _HD_ArgsGetDchar
#    define  HD_ArgsGetDcharEx          _HD_ArgsGetDcharEx
#    define  HD_ArgsGetQchar            _HD_ArgsGetQchar
#    define  HD_ArgsGetQcharEx          _HD_ArgsGetQcharEx
#    define  HD_ArgsGetOchar            _HD_ArgsGetOchar
#    define  HD_ArgsGetOcharEx          _HD_ArgsGetOcharEx
#    define  HD_ArgsGetUlongInt         _HD_ArgsGetUlongInt
#    define  HD_ArgsGetUlongIntEx       _HD_ArgsGetUlongIntEx
#    define  HD_ArgsGetUint             _HD_ArgsGetUint
#    define  HD_ArgsGetUintEx           _HD_ArgsGetUintEx
#    define  HD_ArgsNum                 _HD_ArgsNum
#    define  HD_ArgsNumEx               _HD_ArgsNumEx
#    define  HD_ArgsParseStr            _HD_ArgsParseStr
#    define  HD_ArgsParseStrEx          _HD_ArgsParseStrEx
#    define  HD_ArgsParseStrQuote       _HD_ArgsParseStrQuote
#    define  HD_ArgsSetFlags            _HD_ArgsSetFlags
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_ARGS             HDRIVE_EXPORT HD_ArgsAlloc(HD_VOID);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_ArgsFree(HD_ARGS hArg);
HDRIVE_EXTERN HD_CHAR *           HDRIVE_EXPORT HD_ArgsGetChar(const HD_LONG ArgNum);
HDRIVE_EXTERN HD_CHAR *           HDRIVE_EXPORT HD_ArgsGetCharEx(HD_ARGS hArgs, const HD_LONG ArgNum);
HDRIVE_EXTERN HD_DOUBLE           HDRIVE_EXPORT HD_ArgsGetDouble(const HD_LONG ArgNum);
HDRIVE_EXTERN HD_DOUBLE           HDRIVE_EXPORT HD_ArgsGetDoubleEx(HD_ARGS hArgs, const HD_LONG ArgNum);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_ArgsGetFloat(const HD_LONG ArgNum);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_ArgsGetFloatEx(HD_ARGS hArgs, const HD_LONG ArgNum);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_ArgsGetHexInt(const HD_LONG ArgNum);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_ArgsGetHexIntEx(HD_ARGS hArgs, const HD_LONG ArgNum);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_ArgsGetInt(const HD_LONG ArgNum);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_ArgsGetIntEx(HD_ARGS hArgs, const HD_LONG ArgNum);
HDRIVE_EXTERN HD_DLONG            HDRIVE_EXPORT HD_ArgsGetLongInt(const HD_LONG ArgNum);
HDRIVE_EXTERN HD_DLONG            HDRIVE_EXPORT HD_ArgsGetLongIntEx(HD_ARGS hArgs, const HD_LONG ArgNum);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_ArgsGetDchar(HD_DCHAR *Dest, const HD_LONG ArgNum);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_ArgsGetDcharEx(HD_ARGS hArgs, HD_DCHAR *Dest, const HD_LONG ArgNum);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_ArgsGetQchar(HD_QCHAR *Dest, const HD_LONG ArgNum);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_ArgsGetQcharEx(HD_ARGS hArgs, HD_QCHAR *Dest, const HD_LONG ArgNum);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_ArgsGetOchar(HD_OCHAR *Dest, const HD_LONG ArgNum);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_ArgsGetOcharEx(HD_ARGS hArgs, HD_OCHAR *Dest, const HD_LONG ArgNum);
HDRIVE_EXTERN HD_UDLONG           HDRIVE_EXPORT HD_ArgsGetUlongInt(const HD_LONG ArgNum);
HDRIVE_EXTERN HD_UDLONG           HDRIVE_EXPORT HD_ArgsGetUlongIntEx(HD_ARGS hArgs, const HD_LONG ArgNum);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_ArgsGetUint(const HD_LONG ArgNum);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_ArgsGetUintEx(HD_ARGS hArgs, const HD_LONG ArgNum);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_ArgsNum(HD_VOID);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_ArgsNumEx(HD_ARGS hArgs);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_ArgsParseStr(const HD_CHAR *Str);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_ArgsParseStrEx(HD_ARGS hArg, const HD_CHAR *Str, const HD_CHAR *FieldSep);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_ArgsParseStrQuote(HD_ARGS hArgs, const HD_CHAR *Str, const HD_CHAR *FieldSep, const HD_CHAR *QuoteChars);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_ArgsSetFlags(HD_ARGS hArgs, HD_LONG Flags);

#  ifdef __cplusplus
   }
#  endif

/**** C++ wrapper ****/

#  ifdef __cplusplus
#    include <hdstring.h>

/**** Argument parser class ****/

class HDC_Args
{
  public:

        /**** Properties ****/

        HD_LONG                         UserData;
        HD_VOID *                       UserPtr;

        /**** Methods ****/

        inline                          HDC_Args(HD_VOID)                       { hArgs = HD_ArgsAlloc(); }
        inline                          HDC_Args(HD_LONG Flags)                 { hArgs = HD_ArgsAlloc(); if (hArgs) HD_ArgsSetFlags(hArgs, Flags); }
        inline                          ~HDC_Args(HD_VOID)                      { HD_ArgsFree(hArgs); }

        inline HD_LONG                  Count(HD_VOID)                          { return HD_ArgsNumEx(hArgs); }
        inline HD_CHAR *                GetChar(const HD_LONG ArgNum)           { return HD_ArgsGetCharEx(hArgs, ArgNum); }
        inline HD_DOUBLE                GetDouble(const HD_LONG ArgNum)         { return HD_ArgsGetDoubleEx(hArgs, ArgNum); }
        inline HD_FLOAT                 GetFloat(const HD_LONG ArgNum)          { return HD_ArgsGetFloatEx(hArgs, ArgNum); }
        inline HD_LONG                  GetHexInt(const HD_LONG ArgNum)         { return HD_ArgsGetHexIntEx(hArgs, ArgNum); }
        inline HD_LONG                  GetInt(const HD_LONG ArgNum)            { return HD_ArgsGetIntEx(hArgs, ArgNum); }
        inline HD_DLONG                 GetLong(const HD_LONG ArgNum)           { return HD_ArgsGetLongIntEx(hArgs, ArgNum); }
        inline HD_VOID                  GetDchar(HD_DCHAR *Dest, const HD_LONG ArgNum)
                                                                                { return HD_ArgsGetDcharEx(hArgs, Dest, ArgNum); }
        inline HD_VOID                  GetDchar(HD_DCHAR &Dest, const HD_LONG ArgNum)
                                                                                { return HD_ArgsGetDcharEx(hArgs, &Dest, ArgNum); }
        inline HD_VOID                  GetQchar(HD_QCHAR *Dest, const HD_LONG ArgNum)
                                                                                { return HD_ArgsGetQcharEx(hArgs, Dest, ArgNum); }
        inline HD_VOID                  GetQchar(HD_QCHAR &Dest, const HD_LONG ArgNum)
                                                                                { return HD_ArgsGetQcharEx(hArgs, &Dest, ArgNum); }
        inline HD_VOID                  GetOchar(HD_OCHAR *Dest, const HD_LONG ArgNum)
                                                                                { return HD_ArgsGetOcharEx(hArgs, Dest, ArgNum); }
        inline HD_VOID                  GetOchar(HD_OCHAR &Dest, const HD_LONG ArgNum)
                                                                                { return HD_ArgsGetOcharEx(hArgs, &Dest, ArgNum); }
        inline HD_UDLONG                GetUlong(const HD_LONG ArgNum)          { return HD_ArgsGetUlongIntEx(hArgs, ArgNum); }
        inline HD_ULONG                 GetUint(const HD_LONG ArgNum)           { return HD_ArgsGetUintEx(hArgs, ArgNum); }
        inline HD_LONG                  Parse(const HD_CHAR *Str)               { return HD_ArgsParseStrEx(hArgs, (HD_CHAR *)Str, HD_NULL); }
        inline HD_LONG                  Parse(const HD_CHAR *Str, const HD_CHAR *FieldSep)
                                                                                { return HD_ArgsParseStrEx(hArgs, (HD_CHAR *)Str, FieldSep); }
        inline HD_LONG                  Parse(HD_STRING Str)                    { return HD_ArgsParseStrEx(hArgs, Str -> Cstr, HD_NULL); }
        inline HD_LONG                  Parse(HD_STRING Str, const HD_CHAR *FieldSep)
                                                                                { return HD_ArgsParseStrEx(hArgs, Str -> Cstr, FieldSep); }
        inline HD_LONG                  Parse(HD_STRING Str, HD_STRING FieldSep)
                                                                                { return HD_ArgsParseStrEx(hArgs, Str -> Cstr, FieldSep -> Cstr); }

        inline HD_LONG                  Parse(HDC_String &Str)                  { return HD_ArgsParseStrEx(hArgs, Str.Cstr(), HD_NULL); }
        inline HD_LONG                  Parse(HDC_String &Str, const HD_CHAR *FieldSep)
                                                                                { return HD_ArgsParseStrEx(hArgs, Str.Cstr(), FieldSep); }
        inline HD_LONG                  Parse(HDC_String &Str, HDC_String &FieldSep)
                                                                                { return HD_ArgsParseStrEx(hArgs, Str.Cstr(), FieldSep.Cstr()); }
        inline HD_LONG                  ParseQuote(const HD_CHAR *Str)          { return HD_ArgsParseStrQuote(hArgs, Str, HD_NULL, HD_NULL); }
        inline HD_LONG                  ParseQuote(const HD_CHAR *Str, const HD_CHAR *FieldSep)
                                                                                { return HD_ArgsParseStrQuote(hArgs, Str, FieldSep, HD_NULL); }
        inline HD_LONG                  ParseQuote(const HD_CHAR *Str, const HD_CHAR *FieldSep, const HD_CHAR *Quotes)
                                                                                { return HD_ArgsParseStrQuote(hArgs, Str, FieldSep, Quotes); }
        inline HD_LONG                  ParseQuote(HD_STRING Str)              { return HD_ArgsParseStrQuote(hArgs, Str -> Cstr, HD_NULL, HD_NULL); }
        inline HD_LONG                  ParseQuote(HD_STRING Str, const HD_CHAR *FieldSep)
                                                                                { return HD_ArgsParseStrQuote(hArgs, Str -> Cstr, FieldSep, HD_NULL); }
        inline HD_LONG                  ParseQuote(HD_STRING Str, const HD_CHAR *FieldSep, const HD_CHAR *Quotes)
                                                                                { return HD_ArgsParseStrQuote(hArgs, Str -> Cstr, FieldSep, Quotes); }
        inline HD_LONG                  ParseQuote(HDC_String &Str)             { return HD_ArgsParseStrQuote(hArgs, Str.Cstr(), HD_NULL, HD_NULL); }
        inline HD_LONG                  ParseQuote(HDC_String &Str, const HD_CHAR *FieldSep)
                                                                                { return HD_ArgsParseStrQuote(hArgs, Str.Cstr(), FieldSep, HD_NULL); }
        inline HD_LONG                  ParseQuote(HDC_String &Str, const HD_CHAR *FieldSep, const HD_CHAR *Quotes)
                                                                                { return HD_ArgsParseStrQuote(hArgs, Str.Cstr(), FieldSep, Quotes); }
        inline HD_LONG                  SetFlags(HD_LONG Flags)                 { return HD_ArgsSetFlags(hArgs, Flags); }

        /**** Operators ****/

        inline HD_CHAR *                operator [] (const HD_LONG ArgNum)      { return HD_ArgsGetCharEx(hArgs, ArgNum); }

        /**** Private properties ****/

  private:

        HD_ARGS                 hArgs;
};
#  endif
#endif
