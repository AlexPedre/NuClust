
/*******************************************
****    HyperDrive - String routines    ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#ifndef __HDSTRING_H
#  define  __HDSTRING_H
#  include <stdarg.h>

#  ifndef AMIGA
#    include <wchar.h>
#  endif

#  ifndef __HDRIVE_H
#    include <hyperdrive.h>
#  endif

#  ifdef __cplusplus
#    include <hdfile.h>
#  endif

/**** Format specifier for printf (not HD_StrPrint !) ****/

#ifdef WIN32
#  ifdef __BORLANDC__
#    ifdef __clang__
#      define  HD_STRFMT_DL     "ll"
#    else
#      define  HD_STRFMT_DL     "L"
#    endif
#  else
#    ifdef __cplusplus
#       define  HD_STRFMT_DL    "ll"
#    else
#       define  HD_STRFMT_DL    "I64"
#    endif
#  endif
#else
#  define  HD_STRFMT_DL         "ll"
#endif

/**** Data types (see HD_StrDataType()) ****/

#  define  HD_STRDT_UNKOWN      0
#  define  HD_STRDT_STRING      1
#  define  HD_STRDT_NUMBER      2

#  define  HD_STRDTF_MASK       0xff
#  define  HD_STRDTF_EXPONENT   0x00000100
#  define  HD_STRDTF_FLOAT      0x00000200
#  define  HD_STRDTF_INTEGER    0x00000400
#  define  HD_STRDTF_SIGNED     0x00000800

/**** HD_StrDirRemove() and HD_StrDirRemoveC() flags ****/

#  define  HD_STRDIRRM_NONE     0

/**** _HD_StrFindEx() flags ****/

#  define HD_STRFINDEX_NONE     0       /* None             */
#  define HD_STRFINDEX_BACK     1       /* Backward         */
#  define HD_STRFINDEX_CI       2       /* Case insensitive */

/**** HD_StrListSort() flags ****/

#  define  HD_STRLISTSORT_NONE  0   /* None             */
#  define  HD_STRLISTSORT_CI    1   /* Case insensitive */
#  define  HD_STRLISTSORT_DESC  2   /* Descending order */

/**** HD_StrXmlEncode() encoding modes ****/

#  define  HD_STRXMLENC_DEC     0
#  define  HD_STRXMLENC_ENTITY  1
#  define  HD_STRXMLENC_HEX     2

/**** Macros ****/

#  define  HD_STRING_SIZE               sizeof(struct __hd_string)
#  define  HD_WSTRING_SIZE              sizeof(struct __hd_wstring)
#  define  HD_StrLeft(D, S, P)          HD_StrSub((D), (S), 0, P)

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_Str2Bool                _HD_Str2Bool
#    define  HD_Str2Double              _HD_Str2Double
#    define  HD_Str2Float               _HD_Str2Float
#    define  HD_Str2Lint                _HD_Str2Lint
#    define  HD_Str2Int                 _HD_Str2Int
#    define  HD_Str2IPV4                _HD_Str2IPV4
#    define  HD_Str2IPV4C               _HD_Str2IPV4C
#    define  HD_Str2MacAddr             _HD_Str2MacAddr
#    define  HD_Str2MacAddrC            _HD_Str2MacAddrC
#    define  HD_Str2ULint               _HD_Str2ULint
#    define  HD_Str2Uint                _HD_Str2Uint
#    define  HD_StrBase64Decode         _HD_StrBase64Decode
#    define  HD_StrBase64DecodeMem      _HD_StrBase64DecodeMem
#    define  HD_StrBase64Encode         _HD_StrBase64Encode
#    define  HD_StrBase64EncodeMem      _HD_StrBase64EncodeMem
#    define  HD_StrCat                  _HD_StrCat
#    define  HD_StrCatC                 _HD_StrCatC
#    define  HD_StrCatCW                _HD_StrCatCW
#    define  HD_StrCatChar              _HD_StrCatChar
#    define  HD_StrCatD                 _HD_StrCatD
#    define  HD_StrCatF                 _HD_StrCatF
#    define  HD_StrCatI                 _HD_StrCatI
#    define  HD_StrCatLI                _HD_StrCatLI
#    define  HD_StrCatUI                _HD_StrCatUI
#    define  HD_StrCatULI               _HD_StrCatULI
#    define  HD_StrCatW                 _HD_StrCatW
#    define  HD_StrChangeExt            _HD_StrChangeExt
#    define  HD_StrChangeExtC           _HD_StrChangeExtC
#    define  HD_StrCmp                  _HD_StrCmp
#    define  HD_StrCmpC                 _HD_StrCmpC
#    define  HD_StriCmp                 _HD_StriCmp
#    define  HD_StriCmpC                _HD_StriCmpC
#    define  HD_StrnCmp                 _HD_StrnCmp
#    define  HD_StrnCmpC                _HD_StrnCmpC
#    define  HD_StrniCmp                _HD_StrniCmp
#    define  HD_StrniCmpC               _HD_StrniCmpC
#    define  HD_StrCountChar            _HD_StrCountChar
#    define  HD_StrCountCharC           _HD_StrCountCharC
#    define  HD_StrCpy                  _HD_StrCpy
#    define  HD_StrCpyC                 _HD_StrCpyC
#    define  HD_StrCpyD                 _HD_StrCpyD
#    define  HD_StrCpyF                 _HD_StrCpyF
#    define  HD_StrCpyI                 _HD_StrCpyI
#    define  HD_StrCpyLI                _HD_StrCpyLI
#    define  HD_StrCpyP                 _HD_StrCpyP
#    define  HD_StrCpyULI               _HD_StrCpyULI
#    define  HD_StrCpyUI                _HD_StrCpyUI
#    define  HD_StrnCpy                 _HD_StrnCpy
#    define  HD_StrnCpyC                _HD_StrnCpyC
#    define  HD_StrDataType             _HD_StrDataType
#    define  HD_StrDataTypeC            _HD_StrDataTypeC
#    define  HD_StrEmpty                _HD_StrEmpty
#    define  HD_StrEscExpand            _HD_StrEscExpand
#    define  HD_StrFileExt              _HD_StrFileExt
#    define  HD_StrFileExtC             _HD_StrFileExtC
#    define  HD_StrFileName             _HD_StrFileName
#    define  HD_StrFilePath             _HD_StrFilePath
#    define  HD_StrFileTemp             _HD_StrFileTemp
#    define  HD_StrFind                 _HD_StrFind
#    define  HD_StrFindC                _HD_StrFindC
#    define  HD_StrFindChar             _HD_StrFindChar
#    define  HD_StrFindEx               _HD_StrFindEx
#    define  HD_StrFindExC              _HD_StrFindExC
#    define  HD_StrFixDecSep            _HD_StrFixDecSep
#    define  HD_StrFixDecSepC           _HD_StrFixDecSepC
#    define  HD_StrFlip                 _HD_StrFlip
#    define  HD_StrFlipC                _HD_StrFlipC
#    define  HD_StrFree                 _HD_StrFree
#    define  HD_StrFromIPV4             _HD_StrFromIPV4
#    define  HD_StrFromMacAddr          _HD_StrFromMacAddr
#    define  HD_StrHex2Mem              _HD_StrHex2Mem
#    define  HD_StrHex2MemC             _HD_StrHex2MemC
#    define  HD_StrHexFromMem           _HD_StrHexFromMem
#    define  HD_StrIsEmpty              _HD_StrIsEmpty
#    define  HD_StrLen                  _HD_StrLen
#    define  HD_StrLines                _HD_StrLines
#    define  HD_StrLinesC               _HD_StrLinesC
#    define  HD_StrLoad                 _HD_StrLoad
#    define  HD_StrLoadC                _HD_StrLoadC
#    define  HD_StrLower                _HD_StrLower
#    define  HD_StrNew                  _HD_StrNew
#    define  HD_StrPathFix              _HD_StrPathFix
#    define  HD_StrPathFixC             _HD_StrPathFixC
#    define  HD_StrPathSimplify         _HD_StrPathSimplify
#    define  HD_StrPrint                _HD_StrPrint
#    define  HD_StrPrintC               _HD_StrPrintC
#    define  HD_StrRemoveChars          _HD_StrRemoveChars
#    define  HD_StrRemoveCharsC         _HD_StrRemoveCharsC
#    define  HD_StrRemoveQuotes         _HD_StrRemoveQuotes
#    define  HD_StrReplace              _HD_StrReplace
#    define  HD_StrReplaceC             _HD_StrReplaceC
#    define  HD_StrReplaceChar          _HD_StrReplaceChar
#    define  HD_StrReplaceCharC         _HD_StrReplaceCharC
#    define  HD_StrSave                 _HD_StrSave
#    define  HD_StrSaveC                _HD_StrSaveC
#    define  HD_StrSetLen               _HD_StrSetLen
#    define  HD_StrStripCr              _HD_StrStripCr
#    define  HD_StrSub                  _HD_StrSub
#    define  HD_StrSubC                 _HD_StrSubC
#    define  HD_StrSubst                _HD_StrSubst
#    define  HD_StrSubstAll             _HD_StrSubstAll
#    define  HD_StrSubstAllC            _HD_StrSubstAllC
#    define  HD_StrSubstC               _HD_StrSubstC
#    define  HD_StrTokC                 _HD_StrTokC
#    define  HD_StrTrim                 _HD_StrTrim
#    define  HD_StrTrimEx               _HD_StrTrimEx
#    define  HD_StrTrimExC              _HD_StrTrimExC
#    define  HD_StrTrimLeft             _HD_StrTrimLeft
#    define  HD_StrTrimLeftEx           _HD_StrTrimLeftEx
#    define  HD_StrTrimLeftExC          _HD_StrTrimLeftExC
#    define  HD_StrTrimRight            _HD_StrTrimRight
#    define  HD_StrTrimRightEx          _HD_StrTrimRightEx
#    define  HD_StrTrimRightExC         _HD_StrTrimRightExC
#    define  HD_StrUpper                _HD_StrUpper
#    define  HD_StrUrlEncode            _HD_StrUrlEncode
#    define  HD_StrVPrint               _HD_StrVPrint
#    define  HD_StrVPrintC              _HD_StrVPrintC
#    define  HD_StrWhichLine            _HD_StrWhichLine
#    define  HD_StrWhichLineC           _HD_StrWhichLineC
#    define  HD_StrWildCmp              _HD_StrWildCmp
#    define  HD_StrWildCmpC             _HD_StrWildCmpC
#    define  HD_StrWildiCmp             _HD_StrWildiCmp
#    define  HD_StrWildiCmpC            _HD_StrWildiCmpC
#    define  HD_StrWord                 _HD_StrWord
#    define  HD_StrWordC                _HD_StrWordC
#    define  HD_StrXmlEncode            _HD_StrXmlEncode

#    define  HD_StrListAdd              _HD_StrListAdd
#    define  HD_StrListAddBin           _HD_StrListAddBin
#    define  HD_StrListAddC             _HD_StrListAddC
#    define  HD_StrListAddP             _HD_StrListAddP
#    define  HD_StrListFree             _HD_StrListFree
#    define  HD_StrListJoin             _HD_StrListJoin
#    define  HD_StrListNew              _HD_StrListNew
#    define  HD_StrListRemove           _HD_StrListRemove
#    define  HD_StrListSort             _HD_StrListSort

#    ifndef AMIGA
#      define  HD_StrCatCW              _HD_StrCatCW
#      define  HD_StrCatW               _HD_StrCatW
#      define  HD_StrCpyCW              _HD_StrCpyCW
#      define  HD_StrCpyW               _HD_StrCpyW
#      define  HD_StrWcsToMbs           _HD_StrWcsToMbs

#      define  HD_WStrCat               _HD_WStrCat
#      define  HD_WStrCatC              _HD_WStrCatC
#      define  HD_WStrCatCW             _HD_WStrCatCW
#      define  HD_WStrCatW              _HD_WStrCatW
#      define  HD_WStrCmp               _HD_WStrCmp
#      define  HD_WStrCmpC              _HD_WStrCmpC
#      define  HD_WStrCmpCW             _HD_WStrCmpCW
#      define  HD_WStriCmp              _HD_WStriCmp
#      define  HD_WStriCmpCW            _HD_WStriCmpCW
#      define  HD_WStrnCmp              _HD_WStrnCmp
#      define  HD_WStrnCmpCW            _HD_WStrnCmpCW
#      define  HD_WStrniCmp             _HD_WStrniCmp
#      define  HD_WStrniCmpCW           _HD_WStrniCmpCW
#      define  HD_WStrCountChar         _HD_WStrCountChar
#      define  HD_WStrCountCharCW       _HD_WStrCountCharCW
#      define  HD_WStrCpy               _HD_WStrCpy
#      define  HD_WStrCpyC              _HD_WStrCpyC
#      define  HD_WStrCpyCW             _HD_WStrCpyCW
#      define  HD_WStrCpyPW             _HD_WStrCpyPW
#      define  HD_WStrCpyW              _HD_WStrCpyW
#      define  HD_WStrEmpty             _HD_WStrEmpty
#      define  HD_WStrEscExpand         _HD_WStrEscExpand
#      define  HD_WStrFindChar          _HD_WStrFindChar
#      define  HD_WStrFixDecSep         _HD_WStrFixDecSep
#      define  HD_WStrFixDecSepCW       _HD_WStrFixDecSepCW
#      define  HD_WStrFlip              _HD_WStrFlip
#      define  HD_WStrFlipCW            _HD_WStrFlipCW
#      define  HD_WStrFree              _HD_WStrFree
#      define  HD_WStrHex2Mem           _HD_WStrHex2Mem
#      define  HD_WStrHex2MemCW         _HD_WStrHex2MemCW
#      define  HD_WStrHexFromMem        _HD_WStrHexFromMem
#      define  HD_WStrIsEmpty           _HD_WStrIsEmpty
#      define  HD_WStrLen               _HD_WStrLen
#      define  HD_WStrNew               _HD_WStrNew
#      define  HD_WStrPathFixC          _HD_WStrPathFixC
#      define  HD_WStrPathFix           _HD_WStrPathFix
#      define  HD_WStrPathSimplify      _HD_WStrPathSimplify
#      define  HD_WStrRemoveChars       _HD_WStrRemoveChars
#      define  HD_WStrRemoveCharsCW     _HD_WStrRemoveCharsCW
#      define  HD_WStrRemoveQuotes      _HD_WStrRemoveQuotes
#      define  HD_WStrReplaceChar       _HD_WStrReplaceChar
#      define  HD_WStrReplaceCharCW     _HD_WStrReplaceCharCW
#      define  HD_WStrSetLen            _HD_WStrSetLen
#      define  HD_WStrStripCr           _HD_WStrStripCr
#      define  HD_WStrTrim              _HD_WStrTrim
#      define  HD_WStrTrimEx            _HD_WStrTrimEx
#      define  HD_WStrTrimExCW          _HD_WStrTrimExCW
#      define  HD_WStrTrimLeft          _HD_WStrTrimLeft
#      define  HD_WStrTrimLeftEx        _HD_WStrTrimLeftEx
#      define  HD_WStrTrimLeftExCW      _HD_WStrTrimLeftExCW
#      define  HD_WStrTrimRight         _HD_WStrTrimRight
#      define  HD_WStrTrimRightEx       _HD_WStrTrimRightEx
#      define  HD_WStrTrimRightExCW     _HD_WStrTrimRightExCW
#      define  HD_WStrWildCmp           _HD_WStrWildCmp
#      define  HD_WStrWildCmpCW         _HD_WStrWildCmpCW
#      define  HD_WStrWildiCmp          _HD_WStrWildiCmp
#      define  HD_WStrWildiCmpCW        _HD_WStrWildiCmpCW

#      define  HD_WStrListAdd           _HD_WStrListAdd
#      define  HD_WStrListAddBin        _HD_WStrListAddBin
#      define  HD_WStrListAddC          _HD_WStrListAddC
#      define  HD_WStrListAddCW         _HD_WStrListAddCW
#      define  HD_WStrListAddPW         _HD_WStrListAddPW
#      define  HD_WStrListAddW          _HD_WStrListAddW
#      define  HD_WStrListFree          _HD_WStrListFree
#      define  HD_WStrListJoin          _HD_WStrListJoin
#      define  HD_WStrListNew           _HD_WStrListNew
#      define  HD_WStrListRemove        _HD_WStrListRemove
#      define  HD_WStrListSort          _HD_WStrListSort
#    endif
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_Str2Bool(HD_STRING Str);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT  HD_Str2Double(HD_STRING Str);
HDRIVE_EXTERN HD_FLOAT          HDRIVE_EXPORT  HD_Str2Float(HD_STRING Str);
HDRIVE_EXTERN HD_DLONG          HDRIVE_EXPORT  HD_Str2Lint(HD_STRING Str);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_Str2Int(HD_STRING Str);
HDRIVE_EXTERN HD_ULONG          HDRIVE_EXPORT  HD_Str2IPV4(HD_STRING Str);
HDRIVE_EXTERN HD_ULONG          HDRIVE_EXPORT  HD_Str2IPV4C(const HD_CHAR *Str);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_Str2MacAddr(HD_MACADDR *Mac, HD_STRING Str, HD_STRING Sep);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_Str2MacAddrC(HD_MACADDR *Mac, const HD_CHAR *Str, const HD_CHAR *Sep);
HDRIVE_EXTERN HD_UDLONG         HDRIVE_EXPORT  HD_Str2ULint(HD_STRING Str);
HDRIVE_EXTERN HD_ULONG          HDRIVE_EXPORT  HD_Str2Uint(HD_STRING Str);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrBase64Decode(HD_STRING Dest, HD_STRING Src);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrBase64Encode(HD_STRING Dest, HD_STRING Src);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrBase64DecodeMem(HD_STRING Dest, HD_VOID *MemPtr, HD_ULONG MemSize);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrBase64EncodeMem(HD_STRING Dest, HD_VOID *MemPtr, HD_ULONG MemSize);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCat(HD_STRING Dest, const HD_STRING Src);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCatC(HD_STRING Dest, const HD_CHAR *Src);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCatChar(HD_STRING Str, HD_CHAR C);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCatD(HD_STRING Dest, HD_DOUBLE Src);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCatF(HD_STRING Dest, HD_FLOAT Src);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCatI(HD_STRING Dest, HD_LONG Src);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCatLI(HD_STRING Dest, HD_DLONG Src);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCatUI(HD_STRING Dest, HD_ULONG Src);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCatULI(HD_STRING Dest, HD_UDLONG Src);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrChangeExt(HD_STRING Str, const HD_STRING Ext);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrChangeExtC(HD_STRING Str, const HD_CHAR *Ext);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrCmp(HD_STRING Str1, HD_STRING Str2);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrCmpC(HD_STRING Str1, const HD_CHAR *Str2);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StriCmp(HD_STRING Str1, HD_STRING Str2);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StriCmpC(HD_STRING Str1, const HD_CHAR *Str2);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrnCmp(HD_STRING Str1, HD_STRING Str2, HD_ULONG Num);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrnCmpC(HD_STRING Str1, const HD_CHAR *Str2, HD_ULONG Num);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrnCpy(HD_STRING Dest, HD_STRING Src, HD_LONG Len);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrnCpyC(HD_STRING Str, const HD_CHAR *Cstr, HD_LONG Len);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrniCmp(HD_STRING Str1, HD_STRING Str2, HD_ULONG Num);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrniCmpC(HD_STRING Str1, const HD_CHAR *Str2, HD_ULONG Num);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrCountChar(HD_STRING Str, HD_CHAR C);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrCountCharC(const HD_CHAR *Str, HD_CHAR C);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCpy(HD_STRING Dest, const HD_STRING Src);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCpyC(HD_STRING Str, const HD_CHAR *Cstr);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCpyD(HD_STRING Dest, HD_DOUBLE Src);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCpyF(HD_STRING Dest, HD_FLOAT Src);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCpyI(HD_STRING Dest, HD_LONG Src);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCpyLI(HD_STRING Dest, HD_DLONG Src);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCpyP(HD_STRING Dest, const HD_CHAR *PascalSrc);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCpyUI(HD_STRING Dest, HD_ULONG Src);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCpyULI(HD_STRING Dest, HD_UDLONG);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrDataType(HD_STRING Str);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrDataTypeC(const HD_CHAR *Str);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrEmpty(HD_STRING Str);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT  HD_StrEscExpand(HD_STRING Str);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrFileExt(HD_STRING Ext, const HD_STRING FileName);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrFileExtC(HD_STRING Ext, const HD_CHAR *FileName);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrFileName(HD_STRING Str);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrFilePath(HD_STRING Str);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrFileTemp(HD_STRING Str);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrFind(HD_STRING Str, HD_STRING ToFind, HD_LONG Start);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrFindC(HD_STRING Str, const HD_CHAR *ToFind, HD_LONG Start);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrFindChar(HD_STRING Str, HD_CHAR C, HD_LONG Start);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrFindEx(HD_STRING Str, HD_STRING ToFind, HD_LONG Start, HD_LONG Flags);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrFindExC(HD_STRING Str, const HD_CHAR *ToFind, HD_LONG Start, HD_LONG Flags);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrFixDecSep(HD_STRING Str);
HDRIVE_EXTERN HD_CHAR *         HDRIVE_EXPORT  HD_StrFixDecSepC(HD_CHAR *Str);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrFlip(HD_STRING Str);
HDRIVE_EXTERN HD_CHAR *         HDRIVE_EXPORT  HD_StrFlipC(HD_CHAR *Str);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT  HD_StrFree(HD_STRING Str);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrFromIPV4(HD_STRING Str, HD_ULONG Ip);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrFromMacAddr(HD_STRING Str, HD_MACADDR *Mac, HD_CHAR Sep);
HDRIVE_EXTERN HD_ULONG          HDRIVE_EXPORT  HD_StrHex2Mem(HD_VOID *Dest, HD_ULONG Len, HD_STRING Src);
HDRIVE_EXTERN HD_ULONG          HDRIVE_EXPORT  HD_StrHex2MemC(HD_VOID *Dest, HD_ULONG Len, const HD_CHAR *Src);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrHexFromMem(HD_STRING Dest, const HD_VOID *Src, HD_ULONG Len);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_StrIsEmpty(HD_STRING Str);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrLen(HD_STRING Str);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrLines(HD_STRING Str);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrLinesC(HD_CHAR *Str);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrLoad(HD_STRING FileName);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrLoadC(const HD_CHAR *FileName);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT  HD_StrLower(HD_STRING Str);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrNew(HD_VOID);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT  HD_StrPathFix(HD_STRING Str, HD_CHAR NewDirSep);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT  HD_StrPathFixC(HD_CHAR *Str, HD_CHAR NewDirSep);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_StrPathSimplify(HD_STRING Str, HD_CHAR DirSep);

HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORTV HDRIVE_USCOREV(HD_StrPrint)(HD_STRING Str, HD_STRING Fmt, ...);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORTV HDRIVE_USCOREV(HD_StrPrintC)(HD_STRING Str, const HD_CHAR *Fmt, ...);

HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrRemoveChars(HD_STRING Str, HD_STRING CharVect);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrRemoveCharsC(HD_STRING Str, const HD_CHAR *CharVect);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT  HD_StrRemoveQuotes(HD_STRING Str, HD_CHAR Quote);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrReplace(HD_STRING Dest, HD_STRING NewSubStr, HD_LONG Start, HD_LONG Size);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrReplaceC(HD_STRING Dest, const HD_CHAR *NewSubStr, HD_LONG Start, HD_LONG Size);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrReplaceChar(HD_STRING Str, HD_CHAR OldC, HD_CHAR NewC);
HDRIVE_EXTERN HD_CHAR *         HDRIVE_EXPORT  HD_StrReplaceCharC(HD_CHAR *Str, HD_CHAR OldC, HD_CHAR NewC);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_StrSave(HD_STRING FileName, HD_STRING Str);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_StrSaveC(const HD_CHAR *FileName, HD_STRING Str);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrSetLen(HD_STRING Str, HD_LONG NewLen);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrStripCr(HD_STRING Str);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrSub(HD_STRING Dest, HD_STRING Src, HD_LONG Start, HD_LONG Size);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrSubC(HD_STRING Dest, const HD_CHAR *Src, HD_LONG Start, HD_LONG Size);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_StrSubst(HD_STRING Str, HD_STRING OldSubStr, HD_STRING NewSubStr);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrSubstAll(HD_STRING Str, HD_STRING OldSubStr, HD_STRING NewSubStr);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrSubstAllC(HD_STRING Str, const HD_CHAR *OldSubStr, const HD_CHAR *NewSubStr);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_StrSubstC(HD_STRING Str, const HD_CHAR *OldSubStr, const HD_CHAR *NewSubStr);
HDRIVE_EXTERN HD_CHAR *         HDRIVE_EXPORT  HD_StrTokC(HD_CHAR *Str, const HD_CHAR *Delim, HD_CHAR **Last);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrTrim(HD_STRING Str);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrTrimEx(HD_STRING Str, HD_STRING TrimCh);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrTrimExC(HD_STRING Str, const HD_CHAR *TrimCh);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrTrimLeft(HD_STRING Str);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrTrimLeftEx(HD_STRING Str, HD_STRING TrimCh);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrTrimLeftExC(HD_STRING Str, const HD_CHAR *TrimCh);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrTrimRight(HD_STRING Str);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrTrimRightEx(HD_STRING Str, HD_STRING TrimCh);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrTrimRightExC(HD_STRING Str, const HD_CHAR *TrimCh);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT  HD_StrUpper(HD_STRING Str);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_StrUrlEncode(HD_STRING Str);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrVPrint(HD_STRING Str, HD_STRING Fmt, va_list ArgList);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrVPrintC(HD_STRING Str, const HD_CHAR *Fmt, va_list ArgList);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrWhichLine(HD_STRING Str, HD_LONG Index);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrWhichLineC(HD_CHAR *Str, HD_LONG Index);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_StrWildCmp(const HD_STRING Str, const HD_STRING WildStr);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_StrWildCmpC(const HD_CHAR *Str, const HD_CHAR *WildStr);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_StrWildiCmp(const HD_STRING Str, const HD_STRING WildStr);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_StrWildiCmpC(const HD_CHAR *Str, const HD_CHAR *WildStr);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrWord(HD_STRING Dest, HD_STRING Src, HD_LONG Index);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrWordC(HD_STRING Dest, const HD_CHAR *Src, HD_LONG Index);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_StrXmlEncode(HD_STRING Str, HD_LONG Mode);

HDRIVE_EXTERN HD_STRITEM        HDRIVE_EXPORT  HD_StrListAdd(HD_STRLIST StrList, const HD_STRING Str);
HDRIVE_EXTERN HD_STRITEM        HDRIVE_EXPORT  HD_StrListAddBin(HD_STRLIST StrList, const HD_BYTE *Data, HD_ULONG DataLen);
HDRIVE_EXTERN HD_STRITEM        HDRIVE_EXPORT  HD_StrListAddC(HD_STRLIST StrList, const HD_CHAR *Str);
HDRIVE_EXTERN HD_STRITEM        HDRIVE_EXPORT  HD_StrListAddP(HD_STRLIST StrList, const HD_CHAR *PascalStr);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT  HD_StrListFree(HD_STRLIST StrList);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_StrListJoin(HD_STRLIST DestList, HD_STRLIST SrcList);
HDRIVE_EXTERN HD_STRLIST        HDRIVE_EXPORT  HD_StrListNew(HD_VOID);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT  HD_StrListRemove(HD_STRLIST StrList, HD_STRITEM Item);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT  HD_StrListSort(HD_STRLIST StrList, HD_LONG Flags);

#    ifndef AMIGA

HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCatCW(HD_STRING Dest, const HD_WCHAR *Src);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCatW(HD_STRING Dest, const HD_WSTRING Src);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCpyCW(HD_STRING Dest, const HD_WCHAR *Src);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT  HD_StrCpyW(HD_STRING Dest, const HD_WSTRING Src);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_StrWcsToMbs(HD_CHAR *Dest, const HD_WCHAR *Src, HD_LONG MaxLen);

HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrCat(HD_WSTRING Dest, const HD_STRING Src);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrCatC(HD_WSTRING Dest, const HD_CHAR *Src);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrCatCW(HD_WSTRING Dest, const HD_WCHAR *Src);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrCatW(HD_WSTRING Dest, const HD_WSTRING Src);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_WStrCmp(HD_WSTRING Str1, HD_WSTRING Str2);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_WStrCmpC(HD_WSTRING Str1, const HD_CHAR *Str2);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_WStrCmpCW(HD_WSTRING Str1, const HD_WCHAR *Str2);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_WStriCmp(HD_WSTRING Str1, HD_WSTRING Str2);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_WStriCmpCW(HD_WSTRING Str1, const HD_WCHAR *Str2);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_WStrnCmp(HD_WSTRING Str1, HD_WSTRING Str2, HD_ULONG Num);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_WStrnCmpCW(HD_WSTRING Str1, const HD_WCHAR *Str2, HD_ULONG Num);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_WStrniCmp(HD_WSTRING Str1, HD_WSTRING Str2, HD_ULONG Num);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_WStrniCmpCW(HD_WSTRING Str1, const HD_WCHAR *Str2, HD_ULONG Num);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrCpy(HD_WSTRING Dest, const HD_STRING Src);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrCpyC(HD_WSTRING Dest, const HD_CHAR *Src);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrCpyCW(HD_WSTRING Dest, const HD_WCHAR *Src);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrCpyPW(HD_WSTRING Dest, const HD_WCHAR *PascalSrc);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrCpyW(HD_WSTRING Dest, const HD_WSTRING Src);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_WStrCountChar(HD_WSTRING Str, HD_WCHAR C);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_WStrCountCharCW(const HD_WCHAR *Str, HD_WCHAR C);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrEmpty(HD_WSTRING Str);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT  HD_WStrEscExpand(HD_WSTRING Str);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_WStrFindChar(const HD_WSTRING Str, HD_WCHAR C, HD_LONG Start);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrFixDecSep(HD_WSTRING Str);
HDRIVE_EXTERN HD_WCHAR *        HDRIVE_EXPORT  HD_WStrFixDecSepCW(HD_WCHAR *Str);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrFlip(HD_WSTRING Str);
HDRIVE_EXTERN HD_WCHAR *        HDRIVE_EXPORT  HD_WStrFlipCW(HD_WCHAR *Str);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT  HD_WStrFree(HD_WSTRING Str);
HDRIVE_EXTERN HD_ULONG          HDRIVE_EXPORT  HD_WStrHex2Mem(HD_VOID *Dest, HD_ULONG Len, HD_WSTRING Src);
HDRIVE_EXTERN HD_ULONG          HDRIVE_EXPORT  HD_WStrHex2MemCW(HD_VOID *Dest, HD_ULONG Len, const HD_WCHAR *Src);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrHexFromMem(HD_WSTRING Dest, const HD_VOID *Src, HD_ULONG Len);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_WStrIsEmpty(const HD_WSTRING Str);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_WStrLen(const HD_WSTRING Str);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrNew(HD_VOID);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT  HD_WStrPathFix(HD_WSTRING Str, HD_WCHAR NewDirSep);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT  HD_WStrPathFixC(HD_WCHAR *Str, HD_WCHAR NewDirSep);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_WStrPathSimplify(HD_WSTRING Str, HD_WCHAR DirSep);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_WStrRemoveChars(HD_WSTRING Str, const HD_WSTRING CharVect);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_WStrRemoveCharsCW(HD_WSTRING Str, const HD_WCHAR *CharVect);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT  HD_WStrRemoveQuotes(HD_WSTRING Str, HD_WCHAR Quote);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrReplaceChar(HD_WSTRING Str, HD_WCHAR OldC, HD_WCHAR NewC);
HDRIVE_EXTERN HD_WCHAR *        HDRIVE_EXPORT  HD_WStrReplaceCharCW(HD_WCHAR *Str, HD_WCHAR OldC, HD_WCHAR NewC);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrSetLen(HD_WSTRING Str, HD_LONG NewLen);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT  HD_WStrStripCr(HD_WSTRING Str);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrTrim(HD_WSTRING Str);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrTrimEx(HD_WSTRING Str, HD_WSTRING TrimCh);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrTrimExCW(HD_WSTRING Str, const HD_WCHAR *TrimCh);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrTrimLeft(HD_WSTRING Str);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrTrimLeftEx(HD_WSTRING Str, HD_WSTRING TrimCh);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrTrimLeftExCW(HD_WSTRING Str, const HD_WCHAR *TrimCh);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrTrimRight(HD_WSTRING Str);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrTrimRightEx(HD_WSTRING Str, HD_WSTRING TrimCh);
HDRIVE_EXTERN HD_WSTRING        HDRIVE_EXPORT  HD_WStrTrimRightExCW(HD_WSTRING Str, const HD_WCHAR *TrimCh);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_WStrWildCmp(const HD_WSTRING Str, const HD_WSTRING WildStr);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_WStrWildCmpCW(const HD_WCHAR *Str, const HD_WCHAR *WildStr);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_WStrWildiCmp(const HD_WSTRING Str, const HD_WSTRING WildStr);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_WStrWildiCmpCW(const HD_WCHAR *Str, const HD_WCHAR *WildStr);

HDRIVE_EXTERN HD_WSTRITEM       HDRIVE_EXPORT  HD_WStrListAdd(HD_WSTRLIST StrList, const HD_STRING Str);
HDRIVE_EXTERN HD_WSTRITEM       HDRIVE_EXPORT  HD_WStrListAddBin(HD_WSTRLIST StrList, const HD_WORD *Data, HD_ULONG DataLen);
HDRIVE_EXTERN HD_WSTRITEM       HDRIVE_EXPORT  HD_WStrListAddC(HD_WSTRLIST StrList, const HD_CHAR *Str);
HDRIVE_EXTERN HD_WSTRITEM       HDRIVE_EXPORT  HD_WStrListAddCW(HD_WSTRLIST StrList, const HD_WCHAR *Str);
HDRIVE_EXTERN HD_WSTRITEM       HDRIVE_EXPORT  HD_WStrListAddPW(HD_WSTRLIST StrList, const HD_WCHAR *PascalStr);
HDRIVE_EXTERN HD_WSTRITEM       HDRIVE_EXPORT  HD_WStrListAddW(HD_WSTRLIST StrList, const HD_WSTRING Str);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT  HD_WStrListFree(HD_WSTRLIST StrList);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT  HD_WStrListJoin(HD_WSTRLIST DestList, HD_WSTRLIST SrcList);
HDRIVE_EXTERN HD_WSTRLIST       HDRIVE_EXPORT  HD_WStrListNew(HD_VOID);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT  HD_WStrListRemove(HD_WSTRLIST StrList, HD_WSTRITEM Item);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT  HD_WStrListSort(HD_WSTRLIST StrList, HD_LONG Flags);

#    endif
#  ifdef __cplusplus
   }
#  endif

/**** C++ wrapper ****/

#  ifdef __cplusplus
#    include <hdlist.h>

/**** String class ****/

class HDC_WString;

class HDC_String
{
  public:

        friend class            HDC_WString;

        /**** Methods ****/

        inline                  HDC_String(HD_VOID)                     { IntStr = HD_StrNew(); }
        inline                  HDC_String(const HD_DOUBLE Num)         { IntStr = HD_StrCpyD(HD_NULL, Num); }
        inline                  HDC_String(const HD_FLOAT Num)          { IntStr = HD_StrCpyF(HD_NULL, Num); }
        inline                  HDC_String(const HD_CHAR *Str)          { IntStr = HD_StrCpyC(HD_NULL, (HD_CHAR *)Str); }
        inline                  HDC_String(const HD_DLONG Num)          { IntStr = HD_StrCpyLI(HD_NULL, Num); }
        inline                  HDC_String(const HD_LONG Num)           { IntStr = HD_StrCpyI(HD_NULL, Num); }
        inline                  HDC_String(const HD_UDLONG Num)         { IntStr = HD_StrCpyULI(HD_NULL, Num); }
        inline                  HDC_String(const HD_ULONG Num)          { IntStr = HD_StrCpyUI(HD_NULL, Num); }
        inline                  HDC_String(const HD_STRING Str)         { IntStr = HD_StrCpy(HD_NULL, Str); }
        inline                  HDC_String(const HD_WCHAR *Str)         { IntStr = HD_StrCpyCW(HD_NULL, Str); }
        inline                  HDC_String(const HDC_String &Str)       { IntStr = HD_StrCpy(HD_NULL, Str.IntStr); }
        inline                  ~HDC_String(HD_VOID)                    { HD_StrFree(IntStr); }
        inline HDC_String       Base64Decode(HD_VOID)                   { HDC_String NewStr; HD_StrBase64Decode(NewStr.IntStr, IntStr); return NewStr; }
        inline HD_BOOL          Base64Decode(HD_VOID *Mem, HD_ULONG Size)
                                                                        { return HD_StrBase64DecodeMem(IntStr, Mem, Size) != HD_NULL; }
        inline HDC_String       Base64Encode(HD_VOID)                   { HDC_String NewStr; HD_StrBase64Encode(NewStr.IntStr, IntStr); return NewStr; }
        inline HD_BOOL          Base64Encode(HD_VOID *Mem, HD_ULONG Size)
                                                                        { return HD_StrBase64EncodeMem(IntStr, Mem, Size) != HD_NULL; }
        inline HD_VOID          Cat(HD_CHAR C)                          { HD_StrCatChar(IntStr, C); }
        inline HD_VOID          Cat(HD_CHAR *Str)                       { HD_StrCatC(IntStr, Str); }
        inline HD_VOID          Cat(HD_DOUBLE Num)                         { HD_StrCatD(IntStr, Num); }
        inline HD_VOID          Cat(HD_FLOAT Num)                          { HD_StrCatF(IntStr, Num); }
        inline HD_VOID          Cat(HD_STRING Str)                      { HD_StrCat(IntStr, Str); }
        inline HD_VOID          Cat(HDC_String &Str)                    { HD_StrCat(IntStr, Str.IntStr); }
        inline HD_VOID          Cat(HD_LONG Num)                        { HD_StrCatI(IntStr, Num); }
        inline HD_VOID          Cat(HD_ULONG Num)                       { HD_StrCatUI(IntStr, Num); }
        inline HD_VOID          ChangeExt(const HD_CHAR *Ext)           { HD_StrChangeExtC(IntStr, Ext); }
        inline HD_VOID          ChangeExt(HD_STRING Ext)                { HD_StrChangeExt(IntStr, Ext); }
        inline HD_VOID          ChangeExt(HDC_String &Ext)              { HD_StrChangeExt(IntStr, Ext.IntStr); }
        inline HD_LONG          Compare(const HD_CHAR *Str)             { return HD_StrCmpC(IntStr, Str) ; }
        inline HD_LONG          Compare(const HD_CHAR *Str, HD_LONG n)  { return HD_StrnCmpC(IntStr, Str, n); }
        inline HD_LONG          Compare(HD_STRING Str)                  { return HD_StrCmp(IntStr, Str); }
        inline HD_LONG          Compare(HD_STRING Str, HD_LONG n)       { return HD_StrnCmp(IntStr, Str, n); }
        inline HD_LONG          Compare(HDC_String &Str)                { return HD_StrCmp(IntStr, Str.IntStr); }
        inline HD_LONG          Compare(HDC_String &Str, HD_LONG n)     { return HD_StrnCmp(IntStr, Str.IntStr, n); }
        inline HD_LONG          CompareIC(const HD_CHAR *Str)           { return HD_StriCmpC(IntStr, Str); }
        inline HD_LONG          CompareIC(const HD_CHAR *Str, HD_LONG n)
                                                                        { return HD_StrniCmpC(IntStr, Str, n); }
        inline HD_LONG          CompareIC(HD_STRING Str)                { return HD_StriCmp(IntStr, Str); }
        inline HD_LONG          CompareIC(HD_STRING Str, HD_LONG n)     { return HD_StrniCmp(IntStr, Str, n); }
        inline HD_LONG          CompareIC(HDC_String &Str)              { return HD_StriCmp(IntStr, Str.IntStr); }
        inline HD_LONG          CompareIC(HDC_String &Str, HD_LONG n)   { return HD_StrniCmp(IntStr, Str.IntStr, n); }
        inline HD_VOID          Copy(HD_CHAR *Str, HD_LONG Len)         { HD_StrnCpyC(IntStr, Str, Len); }
        inline HD_VOID          Copy(HD_STRING Str, HD_LONG Len)        { HD_StrnCpy(IntStr, Str, Len); }
        inline HD_VOID          Copy(HDC_String &Str, HD_LONG Len)      { HD_StrnCpy(IntStr, Str.IntStr, Len); }
        inline HD_LONG          Count(HD_CHAR C)                        { return HD_StrCountChar(IntStr, C); }
        inline HD_LONG          DataType(HD_VOID)                       { return HD_StrDataType(IntStr); }
        inline HD_VOID          Empty(HD_VOID)                          { HD_StrEmpty(IntStr); }
        inline HD_VOID          EscExpand(HD_VOID)                      { HD_StrEscExpand(IntStr); }
        inline HD_BOOL          FileExist(HD_VOID)                      { return HD_FileExist(IntStr); }
        inline HDC_String       FileExt(HD_VOID)                        { HDC_String NewStr; HD_StrFileExt(NewStr.IntStr, IntStr); return NewStr; }
        inline HDC_String       FileName(HD_VOID)                       { HDC_String NewStr(IntStr); HD_StrFileName(NewStr.IntStr); return NewStr; }
        inline HD_BOOL          FileIsSame(const HD_CHAR *FileName)     { return HD_FileIsSameC(IntStr -> Cstr, FileName); }
        inline HD_BOOL          FileIsSame(HD_STRING FileName)          { return HD_FileIsSame(IntStr, FileName); }
        inline HD_BOOL          FileIsSame(HDC_String &FileName)        { return HD_FileIsSame(IntStr, FileName.IntStr); }
        inline HD_BOOL          FileMove(const HD_CHAR *NewName)        { return HD_FileMoveC(IntStr -> Cstr, NewName); }
        inline HD_BOOL          FileMove(HD_STRING NewName)             { return HD_FileMove(IntStr, NewName); }
        inline HD_BOOL          FileMove(HDC_String &NewName)           { return HD_FileMove(IntStr, NewName.IntStr); }
        inline HDC_String       FilePath(HD_VOID)                       { HDC_String NewStr(IntStr); HD_StrFilePath(NewStr.IntStr); return NewStr; }
        inline HD_BOOL          FileRemove(HD_LONG Flags)               { return HD_FileRemove(IntStr, Flags); }
        inline HD_BOOL          FileRemove(HD_VOID)                     { return HD_FileRemove(IntStr, HD_REMOVE_NONE); }
        inline HD_ULONG         FileSize(HD_VOID)                       { return HD_FileSize(IntStr); }
        inline HD_VOID          FileTemp(HD_VOID)                       { HD_StrFileTemp(IntStr); }
        inline HD_LONG          Find(HD_CHAR ToFind)                    { return HD_StrFindChar(IntStr, ToFind, 0); }
        inline HD_LONG          Find(HD_CHAR ToFind, HD_LONG Start)     { return HD_StrFindChar(IntStr, ToFind, Start); }
        inline HD_LONG          Find(const HD_CHAR *ToFind)             { return HD_StrFindC(IntStr, ToFind, 0); }
        inline HD_LONG          Find(const HD_CHAR *ToFind, HD_LONG Start) { return HD_StrFindC(IntStr, ToFind, Start); }
        inline HD_LONG          Find(const HD_CHAR *ToFind, HD_LONG Start,
                                     HD_LONG Flags)                     { return HD_StrFindExC(IntStr, ToFind, Start, Flags); }
        inline HD_LONG          Find(HD_STRING ToFind)                  { return HD_StrFind(IntStr, ToFind, 0); }
        inline HD_LONG          Find(HD_STRING ToFind, HD_LONG Start)   { return HD_StrFind(IntStr, ToFind, Start); }
        inline HD_LONG          Find(HD_STRING ToFind, HD_LONG Start,
                                     HD_LONG Flags)                     { return HD_StrFindEx(IntStr, ToFind, Start, Flags); }
        inline HD_LONG          Find(HDC_String &ToFind)                { return HD_StrFind(IntStr, ToFind.IntStr, 0); }
        inline HD_LONG          Find(HDC_String &ToFind, HD_LONG Start) { return HD_StrFind(IntStr, ToFind.IntStr, Start); }
        inline HD_LONG          Find(HDC_String &ToFind, HD_LONG Start,
                                     HD_LONG Flags)                     { return HD_StrFindEx(IntStr, ToFind.IntStr, Start, Flags); }
        inline HD_CHAR          FirstChar(HD_VOID)                      { return (IntStr -> Cstr == HD_NULL) ? 0 : IntStr -> Cstr[0]; }
        inline HD_BOOL          FirstCharEq(HD_CHAR C)                  { return ((IntStr -> Cstr != HD_NULL) && (IntStr -> Cstr[0] == C)); }
        inline HD_VOID          FixDecSep(HD_VOID)                      { HD_StrFixDecSep(IntStr); }
        inline HD_VOID          Flip(HD_VOID)                           { HD_StrFlip(IntStr); }
        inline HD_VOID          HexFromMem(const HD_VOID *Src, HD_ULONG Len)
                                                                        { HD_StrHexFromMem(IntStr, Src, Len); }
        inline HD_ULONG         Hex2Mem(HD_VOID *Dest, HD_ULONG Len)    { return HD_StrHex2Mem(Dest, Len, IntStr); }
        inline HD_CHAR          LastChar(HD_VOID)                       { return (IntStr -> Cstr == HD_NULL) ? 0 : IntStr -> Cstr[IntStr -> Len - 1]; }
        inline HD_BOOL          LastCharEq(HD_CHAR C)                   { return ((IntStr -> Cstr != HD_NULL) && (IntStr -> Cstr[IntStr -> Len - 1] == C)); }
        inline HD_LONG          Lines(HD_VOID)                          { return HD_StrLines(IntStr); }
        inline HD_VOID          Load(const HD_CHAR *FileName)           { HD_STRING NewStr = HD_StrLoadC(FileName);
                                                                          if (!NewStr) throw HD_ErrCode();
                                                                          HD_StrFree(IntStr);
                                                                          IntStr = NewStr;
                                                                        }
        inline HD_VOID          Load(HD_STRING FileName)                { Load(FileName -> Cstr); }
        inline HD_VOID          Load(HDC_String &FileName)              { Load(FileName.IntStr -> Cstr); }
        inline HD_VOID          Lower(HD_VOID)                          { HD_StrLower(IntStr); }
        inline HD_VOID          PathFix(HD_VOID)                        { HD_StrPathFix(IntStr, HD_DIRSEP_AUTOC); }
        inline HD_VOID          PathFix(HD_CHAR NewSep)                 { HD_StrPathFix(IntStr, NewSep); }
        inline HD_BOOL          PathSimplify(HD_VOID)                   { return HD_StrPathSimplify(IntStr, 0); }
        inline HD_BOOL          PathSimplify(HD_CHAR Sep)               { return HD_StrPathSimplify(IntStr, Sep); }
               HD_VOID          Print(const HD_CHAR *Fmt, ...)          { va_list Ap; va_start(Ap, Fmt); HD_StrVPrintC(IntStr, Fmt, Ap); va_end(Ap); }
               HD_VOID          Print(HD_STRING Fmt, ...)               { va_list Ap; va_start(Ap, Fmt); HD_StrVPrint(IntStr, Fmt, Ap); va_end(Ap); }
               HD_VOID          Print(HDC_String &Fmt, ...)             { va_list Ap; va_start(Ap, Fmt); HD_StrVPrint(IntStr, Fmt.IntStr, Ap); va_end(Ap); }
        inline HD_LONG          RemoveChars(const HD_CHAR *CharVect)    { return HD_StrRemoveCharsC(IntStr, CharVect); }
        inline HD_LONG          RemoveChars(const HD_STRING CharVect)   { return HD_StrRemoveChars(IntStr, CharVect); }
        inline HD_VOID          RemoveExt(HD_VOID)                      { HD_StrChangeExtC(IntStr, HD_NULL); }
        inline HD_VOID          Replace(const HD_CHAR *NewSubStr, HD_LONG Start, HD_LONG Size)
                                                                        { HD_StrReplaceC(IntStr, NewSubStr, Start, Size); }
        inline HD_VOID          Replace(HD_STRING NewSubStr, HD_LONG Start, HD_LONG Size)
                                                                        { HD_StrReplace(IntStr, NewSubStr, Start, Size); }
        inline HD_VOID          Replace(HDC_String &NewSubStr, HD_LONG Start, HD_LONG Size)
                                                                        { HD_StrReplace(IntStr, NewSubStr.IntStr, Start, Size); }
        inline HD_VOID          ReplaceChar(const HD_CHAR OldC, const HD_CHAR NewC)
                                                                        { HD_StrReplaceChar(IntStr, OldC, NewC); }
        inline HD_VOID          Save(const HD_CHAR *FileName)           { if (!HD_StrSaveC(FileName, IntStr)) throw HD_ErrCode(); }
        inline HD_VOID          Save(HD_STRING FileName)                { if (!HD_StrSave(FileName, IntStr)) throw HD_ErrCode(); }
        inline HD_VOID          Save(HDC_String &FileName)              { if (!HD_StrSave(FileName.IntStr, IntStr)) throw HD_ErrCode(); }
        inline HD_VOID          SetLen(HD_LONG NewLen)                  { HD_StrSetLen(IntStr, NewLen); }
        inline HD_LONG          StripCR(HD_VOID)                        { return HD_StrStripCr(IntStr); }
        inline HDC_String       Sub(HD_LONG Start, HD_LONG Size)        { HDC_String NewStr; HD_StrSub(NewStr.IntStr, IntStr, Start, Size); return NewStr; }
        inline HD_BOOL          Subst(const HD_CHAR *OldSubStr, const HD_CHAR *NewSubStr)
                                                                        { return HD_StrSubstC(IntStr, OldSubStr, NewSubStr); }
        inline HD_BOOL          Subst(HD_STRING OldSubStr, HD_STRING NewSubStr)
                                                                        { return HD_StrSubst(IntStr, OldSubStr, NewSubStr); }
        inline HD_LONG          SubstAll(const HD_CHAR *OldSubStr, const HD_CHAR *NewSubStr)
                                                                        { return HD_StrSubstAllC(IntStr, OldSubStr, NewSubStr); }
        inline HD_LONG          SubstAll(const HD_CHAR *OldSubStr, HDC_String &NewSubStr)
                                                                        { return HD_StrSubstAllC(IntStr, OldSubStr, NewSubStr.Cstr()); }
        inline HD_LONG          SubstAll(HD_STRING OldSubStr, HD_STRING NewSubStr)
                                                                        { return HD_StrSubstAll(IntStr, OldSubStr, NewSubStr); }
        inline HD_BOOL          ToBool(HD_VOID)                         { return HD_Str2Bool(IntStr); }
        inline HD_DOUBLE        ToDouble(HD_VOID)                       { return HD_Str2Double(IntStr); }
        inline HD_FLOAT         ToFloat(HD_VOID)                        { return HD_Str2Float(IntStr); }
        inline HD_DLONG         ToLInt(HD_VOID)                         { return HD_Str2Lint(IntStr); }
        inline HD_LONG          ToInt(HD_VOID)                          { return HD_Str2Int(IntStr); }
        inline HD_UDLONG        ToULInt(HD_VOID)                        { return HD_Str2ULint(IntStr); }
        inline HD_ULONG         ToUint(HD_VOID)                         { return HD_Str2Uint(IntStr); }
        inline HD_VOID          Trim(HD_VOID)                           { HD_StrTrim(IntStr); }
        inline HD_VOID          Trim(const HD_CHAR *TrimCh)             { HD_StrTrimExC(IntStr, TrimCh); }
        inline HD_VOID          Trim(HD_STRING TrimCh)                  { HD_StrTrimEx(IntStr, TrimCh); }
        inline HD_VOID          TrimLeft(HD_VOID)                       { HD_StrTrimLeft(IntStr); }
        inline HD_VOID          TrimLeft(const HD_CHAR *TrimCh)         { HD_StrTrimLeftExC(IntStr, TrimCh); }
        inline HD_VOID          TrimLeft(HD_STRING TrimCh)              { HD_StrTrimLeftEx(IntStr, TrimCh); }
        inline HD_VOID          TrimRight(HD_VOID)                      { HD_StrTrimRight(IntStr); }
        inline HD_VOID          TrimRight(const HD_CHAR *TrimCh)        { HD_StrTrimRightExC(IntStr, TrimCh); }
        inline HD_VOID          TrimRight(HD_STRING TrimCh)             { HD_StrTrimRightEx(IntStr, TrimCh); }
        inline HD_VOID          Upper(HD_VOID)                          { HD_StrUpper(IntStr); }
        inline HD_VOID          UrlEncode(HD_VOID)                      { HD_StrUrlEncode(IntStr); }
        inline HD_VOID          VPrint(const HD_CHAR *Fmt, va_list ArgList)
                                                                        { HD_StrVPrintC(IntStr, Fmt, ArgList); }
        inline HD_VOID          VPrint(HD_STRING Fmt, va_list ArgList)  { HD_StrVPrint(IntStr, Fmt, ArgList); }
        inline HD_VOID          VPrint(HDC_String &Fmt, va_list ArgList){ HD_StrVPrint(IntStr, Fmt.IntStr, ArgList); }
        inline HD_LONG          WhichLine(HD_LONG Index)                { return HD_StrWhichLine(IntStr, Index); }
        inline HD_BOOL          WildCmp(const HD_CHAR *WildStr)         { return HD_StrWildCmpC(IntStr -> Cstr, WildStr); }
        inline HD_BOOL          WildCmp(const HD_STRING WildStr)        { return HD_StrWildCmp(IntStr, WildStr); }
        inline HD_BOOL          WildCmp(HDC_String &WildStr)            { return HD_StrWildCmp(IntStr, WildStr.IntStr); }
        inline HD_BOOL          WildiCmp(const HD_CHAR *WildStr)        { return HD_StrWildiCmpC(IntStr -> Cstr, WildStr); }
        inline HD_BOOL          WildiCmp(const HD_STRING WildStr)       { return HD_StrWildiCmp(IntStr, WildStr); }
        inline HD_BOOL          WildiCmp(HDC_String &WildStr)           { return HD_StrWildiCmp(IntStr, WildStr.IntStr); }
        inline HDC_String       Word(HD_LONG Index)                     { HDC_String NewStr; HD_StrWord(NewStr.IntStr, IntStr, Index); return NewStr; }
        inline HD_LONG          XmlEncode(HD_LONG Mode)                 { return HD_StrXmlEncode(IntStr, Mode); }

        /**** VCL methods ****/

#    ifdef VCL_H
        inline                  HDC_String(const AnsiString &Str)       { IntStr = HD_StrCpyC(HD_NULL, Str.c_str()); }
        inline                  HDC_String(const UnicodeString &Str)    { IntStr = HD_StrCpyCW(HD_NULL, Str.c_str()); }

        inline HD_VOID          Cat(AnsiString &Str)                    { HD_StrCatC(IntStr, Str.c_str()); }
        inline HD_VOID          ChangeExt(AnsiString &Ext)              { HD_StrChangeExtC(IntStr, Ext.c_str()); }
        inline HD_VOID          Copy(AnsiString &Str, HD_LONG Len)          { HD_StrnCpyC(IntStr, Str.c_str(), Len); }
        inline HD_LONG          Find(AnsiString &ToFind, HD_LONG Start) { return HD_StrFindC(IntStr, ToFind.c_str(), Start); }
               HD_VOID          Load(AnsiString &FileName)              { Load(FileName.c_str()); }
               HD_VOID          Print(AnsiString &Fmt, ...)             { va_list Ap; va_start(Ap, Fmt); HD_StrVPrintC(IntStr, Fmt.c_str(), Ap); va_end(Ap); }
        inline HD_VOID          Replace(AnsiString &NewSubStr, HD_LONG Start, HD_LONG Size)
                                                                        { HD_StrReplaceC(IntStr, NewSubStr.c_str(), Start, Size); }
               HD_VOID          Save(AnsiString &FileName)              { if (!HD_StrSaveC(FileName.c_str(), IntStr)) throw HD_ErrCode(); }
        inline HD_VOID          VPrint(AnsiString &Fmt, va_list ArgList){ HD_StrVPrintC(IntStr, Fmt.c_str(), ArgList); }
        inline HD_BOOL          WildCmp(AnsiString &WildStr)            { return HD_StrWildCmpC(IntStr -> Cstr, WildStr.c_str()); }
        inline HD_BOOL          WildiCmp(AnsiString &WildStr)           { return HD_StrWildiCmpC(IntStr -> Cstr, WildStr.c_str()); }
#    endif

        /**** Properties ****/

        inline HD_CHAR *        Cstr(HD_VOID)                           { return IntStr -> Cstr; }
        inline HD_STRING        Hdstr(HD_VOID)                          { return IntStr; }
        inline HD_BOOL          IsEmpty(HD_VOID)                        { return HD_StrIsEmpty(IntStr); }
        inline HD_LONG          Len(HD_VOID)                            { return IntStr -> Len; }

        /**** Operators ****/

        inline HD_CHAR          operator [] (const HD_LONG N       )    { return IntStr -> Cstr[N]; }
               HDC_String       operator +  (const HD_CHAR *Str    )    { HDC_String NewStr(IntStr); HD_StrCatC(NewStr.IntStr, (HD_CHAR *)Str); return NewStr; }
               HDC_String       operator +  (const HD_DOUBLE Num   )    { HDC_String NewStr(IntStr); HD_StrCatD(NewStr.IntStr, Num); return NewStr; }
               HDC_String       operator +  (const HD_FLOAT Num    )    { HDC_String NewStr(IntStr); HD_StrCatF(NewStr.IntStr, Num); return NewStr; }
               HDC_String       operator +  (const HD_DLONG Num    )    { HDC_String NewStr(IntStr); HD_StrCatLI(NewStr.IntStr, Num); return NewStr; }
               HDC_String       operator +  (const HD_LONG Num     )    { HDC_String NewStr(IntStr); HD_StrCatI(NewStr.IntStr, Num); return NewStr; }
               HDC_String       operator +  (const HD_UDLONG Num   )    { HDC_String NewStr(IntStr); HD_StrCatULI(NewStr.IntStr, Num); return NewStr; }
               HDC_String       operator +  (const HD_ULONG Num    )    { HDC_String NewStr(IntStr); HD_StrCatUI(NewStr.IntStr, Num); return NewStr; }
               HDC_String       operator +  (const HD_STRING Str   )    { HDC_String NewStr(IntStr); HD_StrCat(NewStr.IntStr, (HD_STRING)Str); return NewStr; }
               HDC_String       operator +  (const HDC_String &Str )    { HDC_String NewStr(IntStr); HD_StrCat(NewStr.IntStr, Str.IntStr); return NewStr; }
        inline HD_VOID          operator =  (const HD_CHAR *Str    )    { HD_StrCpyC(IntStr, (HD_CHAR *)Str); }
        inline HD_VOID          operator =  (const HD_STRING Str   )    { HD_StrCpy(IntStr, Str); }
        inline HD_VOID          operator =  (const HD_WCHAR *Str   )    { HD_StrCpyCW(IntStr, Str); }
        inline HD_VOID          operator =  (const HD_WSTRING Str  )    { HD_StrCpyW(IntStr, Str); }
        inline HD_VOID          operator =  (const HDC_String &Str )    { HD_StrCpy(IntStr, Str.IntStr); }
        inline HD_VOID          operator =  (const HDC_String *Str )    { HD_StrCpy(IntStr, Str -> IntStr); }
        inline HD_VOID          operator =  (const HD_DLONG Num    )    { HD_StrCpyLI(IntStr, Num); }
        inline HD_VOID          operator =  (const HD_LONG Num     )    { HD_StrCpyI(IntStr, Num); }
        inline HD_VOID          operator =  (const HD_UDLONG Num   )    { HD_StrCpyULI(IntStr, Num); }
        inline HD_VOID          operator =  (const HD_ULONG Num    )    { HD_StrCpyUI(IntStr, Num); }
        inline HD_VOID          operator += (const HD_CHAR *Str    )    { HD_StrCatC(IntStr, Str); }
        inline HD_VOID          operator += (const HD_CHAR Char    )    { HD_StrCatChar(IntStr, Char); }
        inline HD_VOID          operator += (const HD_STRING Str   )    { HD_StrCat(IntStr, Str); }
        inline HD_VOID          operator += (const HDC_String &Str )    { HD_StrCat(IntStr, Str.IntStr); }
        inline HD_VOID          operator += (const HDC_String *Str )    { HD_StrCat(IntStr, Str -> IntStr); }
        inline HD_VOID          operator += (const HD_DOUBLE Num   )    { HD_StrCatD(IntStr, Num); }
        inline HD_VOID          operator += (const HD_FLOAT Num    )    { HD_StrCatF(IntStr, Num); }
        inline HD_VOID          operator += (const HD_DLONG Num    )    { HD_StrCatLI(IntStr, Num); }
        inline HD_VOID          operator += (const HD_LONG Num     )    { HD_StrCatI(IntStr, Num); }
        inline HD_VOID          operator += (const HD_UDLONG Num   )    { HD_StrCatULI(IntStr, Num); }
        inline HD_VOID          operator += (const HD_ULONG Num    )    { HD_StrCatUI(IntStr, Num); }
        inline HD_BOOL          operator == (const HD_CHAR *Str    )    { return (HD_StrCmpC(IntStr, Str) == 0); }
        inline HD_BOOL          operator == (const HD_STRING Str   )    { return (HD_StrCmp(IntStr, Str) == 0); }
        inline HD_BOOL          operator == (const HDC_String &Str )    { return (HD_StrCmp(IntStr, Str.IntStr) == 0); }
        inline HD_BOOL          operator != (const HD_CHAR *Str    )    { return (HD_StrCmpC(IntStr, Str) != 0); }
        inline HD_BOOL          operator != (const HD_STRING Str   )    { return (HD_StrCmp(IntStr, Str) != 0); }
        inline HD_BOOL          operator != (const HDC_String &Str )    { return (HD_StrCmp(IntStr, Str.IntStr) != 0); }
        inline HD_BOOL          operator >  (const HD_CHAR *Str    )    { return (HD_StrCmpC(IntStr, Str) > 0); }
        inline HD_BOOL          operator >  (const HD_STRING Str   )    { return (HD_StrCmp(IntStr, Str) > 0); }
        inline HD_BOOL          operator >  (const HDC_String &Str )    { return (HD_StrCmp(IntStr, Str.IntStr) > 0); }
        inline HD_BOOL          operator <  (const HD_CHAR *Str    )    { return (HD_StrCmpC(IntStr, Str) < 0); }
        inline HD_BOOL          operator <  (const HD_STRING Str   )    { return (HD_StrCmp(IntStr, Str) < 0); }
        inline HD_BOOL          operator <  (const HDC_String &Str )    { return (HD_StrCmp(IntStr, Str.IntStr) < 0); }

        /**** VCL operators ****/

#    ifdef VCL_H
               HDC_String       operator +  (const AnsiString &Str   )  { HDC_String NewStr(IntStr); HD_StrCatC(NewStr.IntStr, Str.c_str()); return NewStr; }
               HDC_String       operator +  (const AnsiString *Str   )  { HDC_String NewStr(IntStr); HD_StrCatC(NewStr.IntStr, Str -> c_str()); return NewStr; }
               HDC_String       operator +  (const HD_WSTRING Str    )  { HDC_String NewStr(IntStr); HD_StrCatW(NewStr.IntStr, Str); return NewStr; }
        inline HDC_String       operator +  (HDC_WString &Str        );
        inline HDC_String       operator +  (HDC_WString *Str        );
               HDC_String       operator +  (const UnicodeString &Str)  { HDC_String NewStr(IntStr); HD_StrCatCW(NewStr.IntStr, Str.c_str()); return NewStr; }
               HDC_String       operator +  (const UnicodeString *Str)  { HDC_String NewStr(IntStr); HD_StrCatCW(NewStr.IntStr, Str -> c_str()); return NewStr; }
        inline HD_VOID          operator =  (const AnsiString &Str   )  { HD_StrCpyC(IntStr, Str.c_str()); }
        inline HD_VOID          operator =  (const AnsiString *Str   )  { HD_StrCpyC(IntStr, Str -> c_str()); }
        inline HD_VOID          operator =  (const UnicodeString &Str)  { HD_StrCpyCW(IntStr, Str.c_str()); }
        inline HD_VOID          operator =  (const UnicodeString *Str)  { HD_StrCpyCW(IntStr, Str -> c_str()); }
        inline HD_VOID          operator += (const AnsiString &Str   )  { HD_StrCatC(IntStr, Str.c_str()); }
        inline HD_VOID          operator += (const AnsiString *Str   )  { HD_StrCatC(IntStr, Str -> c_str()); }
        inline HD_VOID          operator += (const UnicodeString &Str)  { HD_StrCatCW(IntStr, Str.c_str()); }
        inline HD_VOID          operator += (const UnicodeString *Str)  { HD_StrCatCW(IntStr, Str -> c_str()); }
        inline HD_BOOL          operator == (const AnsiString &Str   )  { return (HD_StrCmpC(IntStr, Str.c_str()) == 0); }
        inline HD_BOOL          operator != (const AnsiString &Str   )  { return (HD_StrCmpC(IntStr, Str.c_str()) != 0); }
        inline HD_BOOL          operator >  (const AnsiString &Str   )  { return (HD_StrCmpC(IntStr, Str.c_str()) > 0); }
        inline HD_BOOL          operator <  (const AnsiString &Str   )  { return (HD_StrCmpC(IntStr, Str.c_str()) < 0); }
#    endif

        /**** Private properties ****/

  private:
//        friend                  HDC_WString;

        HD_STRING               IntStr;
};

/**** String list class ****/

class HDC_StringList
{
  public:

        /**** Methods ****/

        inline                  HDC_StringList(HD_VOID)                 { IntStrList = HD_StrListNew(); }
        inline                  ~HDC_StringList(HD_VOID)                { HD_StrListFree(IntStrList); }
        inline HD_STRITEM       Add(const HD_BYTE *Data, HD_ULONG DataLen)
                                                                        { return HD_StrListAddBin(IntStrList, Data, DataLen); }
        inline HD_STRITEM       Add(const HD_CHAR *Str)                 { return HD_StrListAddC(IntStrList, Str); }
        inline HD_STRITEM       AddP(const HD_CHAR *Str)                { return HD_StrListAddP(IntStrList, Str); }
        inline HD_STRITEM       Add(const HD_STRING Str)                { return HD_StrListAdd(IntStrList, Str); }
        inline HD_STRITEM       Add(HDC_String &Str)                    { return HD_StrListAdd(IntStrList, Str.Hdstr()); }
        inline HD_VOID          Empty(HD_VOID)                          { if (IntStrList -> Num != 0) { HD_StrListFree(IntStrList); IntStrList = HD_StrListNew(); }}
        inline HD_BOOL          Join(HD_STRLIST SrcList)                { return HD_StrListJoin(IntStrList, SrcList); }
        inline HD_BOOL          Join(HDC_StringList &SrcList)           { return HD_StrListJoin(IntStrList, SrcList.IntStrList); }
        inline HD_VOID          Remove(HD_STRITEM Item)                 { HD_StrListRemove(IntStrList, Item); }
        inline HD_VOID          Sort(HD_VOID)                           { HD_StrListSort(IntStrList, HD_STRLISTSORT_NONE); }
        inline HD_VOID          Sort(HD_LONG Flags)                     { HD_StrListSort(IntStrList, Flags); }

        /**** Properties ****/

        inline HD_ULONG         Count(HD_VOID)                          { return IntStrList -> Num; }
        inline HD_STRITEM       First(HD_VOID)                          { return IntStrList -> Beg; }
        inline HD_BOOL          IsEmpty(HD_VOID)                        { return (IntStrList -> Num == 0); }
        inline HD_STRITEM       Last(HD_VOID)                           { return IntStrList -> Last; }

        /**** Operators ****/

        inline HD_STRITEM       operator [] (const HD_LONG N      )     { return (HD_STRITEM)HD_ListGet((HD_LIST *)IntStrList, N); }
        inline HD_VOID          operator += (HDC_StringList &StrL )     { HD_ListMerge((HD_LIST *)IntStrList, (HD_LIST *)StrL.IntStrList); }

#    ifdef VCL_H
        inline HD_STRITEM       Add(AnsiString &Str)                    { return HD_StrListAddC(IntStrList, Str.c_str()); }
#    endif

        /**** Private properties ****/

  private:
        HD_STRLIST              IntStrList;
};

/**** Wide string class ****/

class HDC_WString
{
  public:

        /**** Methods ****/

        inline                  HDC_WString(HD_VOID)                    { IntStr = HD_WStrNew(); }
        inline                  HDC_WString(const HD_CHAR *Str)         { IntStr = HD_WStrCpyC(HD_NULL, Str); }
        inline                  HDC_WString(const HD_WCHAR *Str)        { IntStr = HD_WStrCpyCW(HD_NULL, Str); }
        inline                  HDC_WString(const HD_STRING Str)        { IntStr = HD_WStrCpy(HD_NULL, Str); }
        inline                  HDC_WString(const HD_WSTRING Str)       { IntStr = HD_WStrCpyW(HD_NULL, Str); }
        inline                  HDC_WString(const HDC_String &Str)      { IntStr = HD_WStrCpy(HD_NULL, Str.IntStr); }
        inline                  HDC_WString(const HDC_WString &Str)     { IntStr = HD_WStrCpyW(HD_NULL, Str.IntStr); }
        inline                  ~HDC_WString(HD_VOID)                   { HD_WStrFree(IntStr); }
        inline HD_VOID          Cat(HD_CHAR *Str)                       { HD_WStrCatC(IntStr, Str); }
        inline HD_VOID          Cat(HD_WCHAR *Str)                      { HD_WStrCatCW(IntStr, Str); }
        inline HD_VOID          Cat(HD_STRING Str)                      { HD_WStrCat(IntStr, Str); }
        inline HD_VOID          Cat(HD_WSTRING Str)                     { HD_WStrCatW(IntStr, Str); }
        inline HD_VOID          Cat(HDC_String &Str)                    { HD_WStrCat(IntStr, Str.Hdstr()); }
        inline HD_VOID          Cat(HDC_WString &Str)                   { HD_WStrCatW(IntStr, Str.IntStr); }
        inline HD_LONG          Count(HD_WCHAR C)                       { return HD_WStrCountChar(IntStr, C); }
        inline HD_VOID          EscExpand(HD_VOID)                      { HD_WStrEscExpand(IntStr); }
        inline HD_VOID          FixDecSep(HD_VOID)                      { HD_WStrFixDecSep(IntStr); }
        inline HD_VOID          Flip(HD_VOID)                           { HD_WStrFlip(IntStr); }
        inline HD_VOID          HexFromMem(const HD_VOID *Src, HD_ULONG Len)
                                                                        { HD_WStrHexFromMem(IntStr, Src, Len); }
        inline HD_ULONG         Hex2Mem(HD_VOID *Dest, HD_ULONG Len)    { return HD_WStrHex2Mem(Dest, Len, IntStr); }
        inline HD_VOID          PathFix(HD_VOID)                        { HD_WStrPathFix(IntStr, HD_DIRSEP_AUTOC); }
        inline HD_VOID          PathFix(HD_WCHAR NewSep)                { HD_WStrPathFix(IntStr, NewSep); }
        inline HD_BOOL          PathSimplify(HD_VOID)                   { return HD_WStrPathSimplify(IntStr, 0); }
        inline HD_BOOL          PathSimplify(HD_CHAR Sep)               { return HD_WStrPathSimplify(IntStr, Sep); }
        inline HD_BOOL          PathSimplify(HD_WCHAR Sep)              { return HD_WStrPathSimplify(IntStr, Sep); }
        inline HD_LONG          RemoveChars(const HD_WCHAR *CharVect)   { return HD_WStrRemoveCharsCW(IntStr, CharVect); }
        inline HD_LONG          RemoveChars(const HD_WSTRING CharVect)  { return HD_WStrRemoveChars(IntStr, CharVect); }
        inline HD_VOID          ReplaceChar(const HD_WCHAR OldC, const HD_WCHAR NewC)
                                                                        { HD_WStrReplaceChar(IntStr, OldC, NewC); }
        inline HD_VOID          SetLen(HD_LONG NewLen)                  { HD_WStrSetLen(IntStr, NewLen); }
        inline HD_LONG          StripCR(HD_VOID)                        { return HD_WStrStripCr(IntStr); }
        inline HD_VOID          Trim(HD_VOID)                           { HD_WStrTrim(IntStr); }
        inline HD_VOID          Trim(const HD_WCHAR *TrimCh)            { HD_WStrTrimExCW(IntStr, TrimCh); }
        inline HD_VOID          Trim(HD_WSTRING TrimCh)                 { HD_WStrTrimEx(IntStr, TrimCh); }
        inline HD_VOID          TrimLeft(HD_VOID)                       { HD_WStrTrimLeft(IntStr); }
        inline HD_VOID          TrimLeft(const HD_WCHAR *TrimCh)        { HD_WStrTrimLeftExCW(IntStr, TrimCh); }
        inline HD_VOID          TrimLeft(HD_WSTRING TrimCh)             { HD_WStrTrimLeftEx(IntStr, TrimCh); }
        inline HD_VOID          TrimRight(HD_VOID)                      { HD_WStrTrimRight(IntStr); }
        inline HD_VOID          TrimRight(const HD_WCHAR *TrimCh)       { HD_WStrTrimRightExCW(IntStr, TrimCh); }
        inline HD_VOID          TrimRight(HD_WSTRING TrimCh)            { HD_WStrTrimRightEx(IntStr, TrimCh); }
        inline HD_BOOL          WildCmp(const HD_WCHAR *WildStr)        { return HD_WStrWildCmpCW(IntStr -> Wstr, WildStr); }
        inline HD_BOOL          WildCmp(const HD_WSTRING WildStr)       { return HD_WStrWildCmp(IntStr, WildStr); }
        inline HD_BOOL          WildCmp(HDC_WString &WildStr)           { return HD_WStrWildCmp(IntStr, WildStr.IntStr); }
        inline HD_BOOL          WildiCmp(const HD_WCHAR *WildStr)       { return HD_WStrWildiCmpCW(IntStr -> Wstr, WildStr); }
        inline HD_BOOL          WildiCmp(const HD_WSTRING WildStr)      { return HD_WStrWildiCmp(IntStr, WildStr); }
        inline HD_BOOL          WildiCmp(HDC_WString &WildStr)          { return HD_WStrWildiCmp(IntStr, WildStr.IntStr); }

        /**** Properties ****/

        inline HD_WCHAR *       Wstr(HD_VOID)                           { return IntStr -> Wstr; }
        inline HD_WSTRING       Hdwstr(HD_VOID)                         { return IntStr; }
        inline HD_BOOL          IsEmpty(HD_VOID)                        { return (bool)HD_WStrIsEmpty(IntStr); }
        inline HD_LONG          Len(HD_VOID)                            { return IntStr -> Len; }

        /**** Operators ****/

        inline HD_VOID          operator =  (const HD_CHAR *Str    )    { HD_WStrCpyC(IntStr, (HD_CHAR *)Str); }
        inline HD_VOID          operator =  (const HD_WCHAR *Str   )    { HD_WStrCpyCW(IntStr, Str); }
        inline HD_VOID          operator =  (const HD_STRING Str   )    { HD_WStrCpy(IntStr, Str); }
        inline HD_VOID          operator =  (HDC_String &Str       )    { HD_WStrCpy(IntStr, Str.Hdstr()); }
        inline HD_VOID          operator =  (HDC_String *Str       )    { HD_WStrCpy(IntStr, Str -> Hdstr()); }
        inline HD_VOID          operator =  (const HDC_WString &Str)    { HD_WStrCpyW(IntStr, Str.IntStr); }
        inline HD_VOID          operator =  (const HDC_WString *Str)    { HD_WStrCpyW(IntStr, Str -> IntStr); }
        inline HD_VOID          operator += (const HD_CHAR *Str    )    { HD_WStrCatC(IntStr, Str); }
        inline HD_VOID          operator += (const HD_WCHAR *Str   )    { HD_WStrCatCW(IntStr, Str); }
               HDC_WString      operator +  (const HD_CHAR *Str    )    { HDC_WString NewStr(IntStr); HD_WStrCatC(NewStr.IntStr, Str); return NewStr; }
               HDC_WString      operator +  (const HD_WCHAR *Str   )    { HDC_WString NewStr(IntStr); HD_WStrCatCW(NewStr.IntStr, Str); return NewStr; }
        inline HD_BOOL          operator == (const HD_CHAR *Str    )    { return (HD_WStrCmpC(IntStr, (HD_CHAR *)Str) == 0); }
        inline HD_BOOL          operator == (const HD_WCHAR *Str   )    { return (HD_WStrCmpCW(IntStr, Str) == 0); }
        inline HD_BOOL          operator == (const HD_STRING Str   )    { return (HD_WStrCmpC(IntStr, Str -> Cstr) == 0); }
        inline HD_BOOL          operator == (HDC_String &Str       )    { return (HD_WStrCmpC(IntStr, Str.Cstr()) == 0); }
        inline HD_BOOL          operator == (const HDC_WString &Str)    { return (HD_WStrCmp(IntStr, Str.IntStr) == 0); }
        inline HD_BOOL          operator != (const HD_CHAR *Str    )    { return (HD_WStrCmpC(IntStr, (HD_CHAR *)Str) != 0); }
        inline HD_BOOL          operator != (const HD_WCHAR *Str   )    { return (HD_WStrCmpCW(IntStr, Str) != 0); }
        inline HD_BOOL          operator != (const HD_STRING Str   )    { return (HD_WStrCmpC(IntStr, Str -> Cstr) != 0); }
        inline HD_BOOL          operator != (HDC_String &Str       )    { return (HD_WStrCmpC(IntStr, Str.Cstr()) != 0); }
        inline HD_BOOL          operator != (const HDC_WString &Str)    { return (HD_WStrCmp(IntStr, Str.IntStr) != 0); }

        /**** VCL operators ****/

#    ifdef VCL_H
               HDC_WString      operator +  (const AnsiString &Str)     { HDC_WString NewStr(IntStr); HD_WStrCatC(NewStr.IntStr, Str.c_str()); return NewStr; }
               HDC_WString      operator +  (const AnsiString *Str)     { HDC_WString NewStr(IntStr); HD_WStrCatC(NewStr.IntStr, Str -> c_str()); return NewStr; }
               HDC_WString      operator +  (const UnicodeString &Str)  { HDC_WString NewStr(IntStr); HD_WStrCatCW(NewStr.IntStr, Str.w_str()); return NewStr; }
               HDC_WString      operator +  (const UnicodeString *Str)  { HDC_WString NewStr(IntStr); HD_WStrCatCW(NewStr.IntStr, Str -> w_str()); return NewStr; }
        inline HD_VOID          operator =  (const AnsiString &Str)     { HD_WStrCpyC(IntStr, Str.c_str()); }
        inline HD_VOID          operator =  (const AnsiString *Str)     { HD_WStrCpyC(IntStr, Str -> c_str()); }
        inline HD_VOID          operator =  (const UnicodeString &Str)  { HD_WStrCpyCW(IntStr, Str.w_str()); }
        inline HD_VOID          operator =  (const UnicodeString *Str)  { HD_WStrCpyCW(IntStr, Str -> w_str()); }
        inline HD_VOID          operator += (const AnsiString &Str)     { HD_WStrCatC(IntStr, Str.c_str()); }
        inline HD_VOID          operator += (const AnsiString *Str)     { HD_WStrCatC(IntStr, Str -> c_str()); }
        inline HD_VOID          operator += (const UnicodeString &Str)  { HD_WStrCatCW(IntStr, Str.w_str()); }
        inline HD_VOID          operator += (const UnicodeString *Str)  { HD_WStrCatCW(IntStr, Str -> w_str()); }
        inline HD_BOOL          operator == (const AnsiString &Str)     { return (HD_WStrCmpC(IntStr, Str.c_str()) == 0); }
        inline HD_BOOL          operator == (const UnicodeString &Str)  { return (HD_WStrCmpCW(IntStr, Str.w_str()) == 0); }
        inline HD_BOOL          operator != (const AnsiString &Str)     { return (HD_WStrCmpC(IntStr, Str.c_str()) != 0); }
        inline HD_BOOL          operator != (const UnicodeString &Str)  { return (HD_WStrCmpCW(IntStr, Str.w_str()) != 0); }
        inline HD_BOOL          operator >  (const AnsiString &Str)     { return (HD_WStrCmpC(IntStr, Str.c_str()) > 0); }
        inline HD_BOOL          operator >  (const UnicodeString &Str)  { return (HD_WStrCmpCW(IntStr, Str.w_str()) > 0); }
        inline HD_BOOL          operator <  (const AnsiString &Str)     { return (HD_WStrCmpC(IntStr, Str.c_str()) < 0); }
        inline HD_BOOL          operator <  (const UnicodeString &Str)  { return (HD_WStrCmpCW(IntStr, Str.w_str()) < 0); }
#    endif

        /**** Private properties ****/

  private:
        HD_WSTRING              IntStr;
};

#    ifdef VCL_H
//        inline HDC_String       HDC_String::operator +  (HDC_WString &Str )    { HDC_String NewStr(IntStr); HD_StrCatW(NewStr.IntStr, Str.Hdwstr()); return NewStr; }
//        inline HDC_String       HDC_String::operator +  (HDC_WString *Str )    { HDC_String NewStr(IntStr); HD_StrCatW(NewStr.IntStr, Str -> Hdwstr()); return NewStr; }
#    endif


/**** Wide string list class ****/

class HDC_WStringList
{
  public:

        /**** Methods ****/

        inline                  HDC_WStringList(HD_VOID)                 { IntStrList = HD_WStrListNew(); }
        inline                  ~HDC_WStringList(HD_VOID)                { HD_WStrListFree(IntStrList); }
        inline HD_WSTRITEM      Add(const HD_WORD *Data, HD_ULONG DataLen)
                                                                        { return HD_WStrListAddBin(IntStrList, Data, DataLen); }
        inline HD_WSTRITEM      Add(const HD_CHAR *Str)                 { return HD_WStrListAddC(IntStrList, Str); }
        inline HD_WSTRITEM      AddP(const HD_WCHAR *Str)               { return HD_WStrListAddPW(IntStrList, Str); }
        inline HD_WSTRITEM      Add(const HD_STRING Str)                { return HD_WStrListAdd(IntStrList, Str); }
        inline HD_WSTRITEM      Add(const HD_WSTRING Str)               { return HD_WStrListAddW(IntStrList, Str); }
        inline HD_WSTRITEM      Add(HDC_String &Str)                    { return HD_WStrListAdd(IntStrList, Str.Hdstr()); }
        inline HD_WSTRITEM      Add(HDC_WString &Str)                   { return HD_WStrListAddW(IntStrList, Str.Hdwstr()); }
        inline HD_VOID          Empty(HD_VOID)                          { if (IntStrList -> Num != 0) { HD_WStrListFree(IntStrList); IntStrList = HD_WStrListNew(); }}
        inline HD_BOOL          Join(HD_WSTRLIST SrcList)               { return HD_WStrListJoin(IntStrList, SrcList); }
        inline HD_BOOL          Join(HDC_WStringList &SrcList)          { return HD_WStrListJoin(IntStrList, SrcList.IntStrList); }
        inline HD_VOID          Remove(HD_WSTRITEM Item)                { HD_WStrListRemove(IntStrList, Item); }
        inline HD_VOID          Sort(HD_VOID)                           { HD_WStrListSort(IntStrList, HD_STRLISTSORT_NONE); }
        inline HD_VOID          Sort(HD_LONG Flags)                     { HD_WStrListSort(IntStrList, Flags); }

        /**** Properties ****/

        inline HD_ULONG         Count(HD_VOID)                          { return IntStrList -> Num; }
        inline HD_WSTRITEM      First(HD_VOID)                          { return IntStrList -> Beg; }
        inline HD_BOOL          IsEmpty(HD_VOID)                        { return (IntStrList -> Num == 0); }
        inline HD_WSTRITEM      Last(HD_VOID)                           { return IntStrList -> Last; }

        /**** Operators ****/

        inline HD_WSTRITEM      operator [] (const HD_LONG N      )     { return (HD_WSTRITEM)HD_ListGet((HD_LIST *)IntStrList, N); }
        inline HD_VOID          operator += (HDC_WStringList &StrL)     { HD_ListMerge((HD_LIST *)IntStrList, (HD_LIST *)StrL.IntStrList); }

#    ifdef VCL_H
        inline HD_WSTRITEM      Add(AnsiString &Str)                    { return HD_WStrListAddC(IntStrList, Str.c_str()); }
        inline HD_WSTRITEM      Add(UnicodeString &Str)                 { return HD_WStrListAddCW(IntStrList, Str.w_str()); }
#    endif

        /**** Private properties ****/

  private:
        HD_WSTRLIST             IntStrList;
};

#  endif
#endif

