
/*******************************************
****  HyperDrive - Spreadsheet routines ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#ifndef __HDSHEET_H
#  define  __HDSHEET_H

#  include "hdfont.h"
#  include "hdmatrix.h"
#  include "hdstring.h"

/**** Cell flags ****/

#  define  HD_SS_CELL_FLG_NONE                  0
#  define  HD_SS_CELL_FLG_DISABLED              1
#  define  HD_SS_CELL_FLG_FREEUSERDATA          2
#  define  HD_SS_CELL_FLG_LOCK                  4

/**** Data types ****/

#  define  HD_SS_DATA_DOUBLE                    0
#  define  HD_SS_DATA_STRING                    1

/**** File formats ****/

#  define  HD_SS_FFMTF_BINARY                   0x0100
#  define  HD_SS_FFMTF_MASK                     0x00ff

#  define  HD_SS_FFMT_UNK                       0
#  define  HD_SS_FFMT_CSV                       1
#  define  HD_SS_FFMT_ARFF                      2

/**** Range margins ****/

#  define  HD_SS_RANGE_FIRST                    0
#  define  HD_SS_RANGE_LAST                     0xffffffff

/**** Save flags ****/

#  define  HD_SS_SAVE_NONE                      0
#  define  HD_SS_SAVE_NL_CR                     1
#  define  HD_SS_SAVE_NL_LF                     2
#  define  HD_SS_SAVE_ENABLEDCELLS              4
#  define  HD_SS_SAVE_NOSTRING                  8 /* ARFF format only */

#  define  HD_SS_SAVE_NL_CRLF                   (HD_SS_SAVE_NL_CR|HD_SS_SAVE_NL_LF)

/**** Sheet flags ****/

#  define  HD_SS_SHEET_FLG_NONE                 0
#  define  HD_SS_SHEET_FLG_FREEUSERDATA         1
#  define  HD_SS_SHEET_FLG_LOCK                 2
#  define  HD_SS_SHEET_FLG_CACHESYNC            4

/**** Spreadsheet flags ****/

#  define  HD_SS_FLG_NONE                       0
#  define  HD_SS_FLG_FREEUSERDATA               1

/**** HD_SS_Rand() ****/

#  define  HD_SS_ROWCOLTYP_COL                  0
#  define  HD_SS_ROWCOLTYP_ROW                  1

/**** Macros ****/

#  define  HD_SS_CacheCellFindDirty(S, C, R)    (S -> Cache[(C) - S -> CacheLeft + ((R) - S -> CacheTop) * S -> CacheCols])

/**** Data ****/

typedef struct {
  union {
    HD_DOUBLE                   D;              /* Double precision HD_FLOAT      */
    HD_STRING                   S;              /* String                      */
  } Data;
  HD_LONG                       Type;           /* Data type                   */
} HD_SS_DATA;

/**** Cell structure ****/

struct __hd_ss_cell {
  struct __hd_ss_cell *         Next;           /* Pointer to the next element */
  struct __hd_ss_cell *         Prev;           /* Pointer to previous element */
  HD_ULONG                      Col;            /* Column                      */
  HD_ULONG                      Row;            /* Row                         */
  HD_SS_DATA                    Value;          /* Cell value                  */
  HD_LONG                       Flags;          /* Flags                       */

  /**** Display parameters ****/

  HD_FONT                       Font;           /* Text font                   */
  HD_COLOR                      BgColor;        /* Background color            */
  HD_LONG                       Position;       /* Text position               */

  /**** User data ****/

  HD_VOID *                     UserData;       /* Pointer to user data        */
  HD_LONG                       UserTag;        /* User tag value              */
};

typedef struct __hd_ss_cell *           HD_SS_CELL;

/**** Range ****/

typedef struct __hd_ss_range {
  struct __hd_ss_range *        Next;           /* Pointer to the next element */
  struct __hd_ss_range *        Prev;           /* Pointer to previous element */
  HD_ULONG                      Bottom;         /* Bottom corner               */
  HD_ULONG                      Left;           /* Left corner                 */
  HD_ULONG                      Right;          /* Right corner                */
  HD_ULONG                      Top;            /* Top corner                  */
} HD_SS_RANGE;

/**** Selection ****/

struct __hd_ss_select {
  struct __hd_ss_select *       Next;           /* Pointer to the next element */
  struct __hd_ss_select *       Prev;           /* Pointer to previous element */
  HD_SS_CELL                    Cell;           /* Cell pointer                */
};

typedef struct __hd_ss_select *         HD_SS_SELECT;

/**** Sheet ****/

struct __hd_ss_sheet {
  struct __hd_ss_sheet *        Next;           /* Pointer to the next element */
  struct __hd_ss_sheet *        Prev;           /* Pointer to previous element */
  HD_LIST *                     Cells;          /* Cell list                   */
  HD_FONT                       CellFont;       /* Cell font                   */
  HD_STRING                     Title;          /* Sheet title                 */
  HD_LONG                       Flags;          /* Sheet flags                 */

  /**** User data ****/

  HD_VOID *                     UserData;       /* Pointer to user data        */
  HD_LONG                       UserTag;        /* User tag value              */

  /**** Internal use ****/

  HD_SS_CELL                    LaCell;         /* Last accessed cell         */

  /**** Cache data ****/

  HD_SS_CELL *                  Cache;          /* Cache pointer              */
  HD_ULONG                      CacheBottom;    /* Cache bottom corner        */
  HD_ULONG                      CacheCols;      /* Cache columns              */
  HD_ULONG                      CacheLeft;      /* Cache left corner          */
  HD_ULONG                      CacheRight;     /* Cache right corner         */
  HD_ULONG                      CacheTop;       /* Cache top corner           */
  HD_ULONG                      CacheRows;      /* Cache rows                 */
};

typedef struct __hd_ss_sheet *          HD_SS_SHEET;

/**** Spreadsheet ****/

struct __hd_spreadsheet {
  HD_FONT                       CellFont;       /* Cell font                   */
  HD_LIST *                     Sheets;         /* List of sheets              */
  HD_SS_SHEET                   SheetCur;       /* Current sheet               */
  HD_STRING                     FileName;       /* File name                   */
  HD_STRING                     Title;          /* Spreadsheet title           */
  HD_LONG                       Flags;          /* Workspace flags             */
  HD_LONG                       FileFormat;     /* File format                 */

  /**** User data ****/

  HD_VOID *                     UserData;       /* Pointer to user data        */
  HD_LONG                       UserTag;        /* User tag value              */
};

typedef struct __hd_spreadsheet *       HD_SPREADSHEET;

/**** I/O functions ****/

typedef struct {
  HD_VOID       (HD_CALLBACK *Close)(HD_FILE Handle);
  HD_FILE       (HD_CALLBACK *Open)(const HD_CHAR *FileName, const HD_CHAR *Mode);
  int           (HD_CALLBACK *Print)(HD_FILE Handle, const HD_CHAR *Format, ...);
  unsigned int  (HD_CALLBACK *Read)(HD_FILE Handle, HD_VOID *Ptr, unsigned int Size);
  int           (HD_CALLBACK *Seek64)(HD_FILE Handle, HD_DLONG Offset, int Whence);
  HD_DLONG      (HD_CALLBACK *Tell64)(HD_FILE Handle);
  unsigned int  (HD_CALLBACK *Write)(HD_FILE Handle, HD_VOID *Ptr, unsigned int Size);
} HD_SS_FUNC;

/**** Macros ****/

#  define  HD_SS_CELL_SIZE      sizeof(struct __hd_ss_cell)
#  define  HD_SS_SELECT_SIZE    sizeof(struct __hd_ss_select)
#  define  HD_SS_SHEET_SIZE     sizeof(struct __hd_ss_sheet)
#  define  HD_SPREADSHEET_SIZE  sizeof(struct __hd_spreadsheet)
#  define  HD_RANGE_COLS(R)     ((R).Right     - (R).Left    + 1)
#  define  HD_RANGE_COLSP(R)    ((R) -> Right  - (R) -> Left + 1)
#  define  HD_RANGE_ROWS(R)     ((R).Bottom    - (R).Top     + 1)
#  define  HD_RANGE_ROWSP(R)    ((R) -> Bottom - (R) -> Top  + 1)

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_SS_CacheBuild           _HD_SS_CacheBuild
#    define  HD_SS_CacheCellFind        _HD_SS_CacheCellFind
#    define  HD_SS_CellCoordCmp         _HD_SS_CellCoordCmp
#    define  HD_SS_CellCopy             _HD_SS_CellCopy
#    define  HD_SS_CellFind             _HD_SS_CellFind
#    define  HD_SS_CellGetChar          _HD_SS_CellGetChar
#    define  HD_SS_CellGetDouble        _HD_SS_CellGetDouble
#    define  HD_SS_CellGetStr           _HD_SS_CellGetStr
#    define  HD_SS_CellLock             _HD_SS_CellLock
#    define  HD_SS_CellMove             _HD_SS_CellMove
#    define  HD_SS_CellRemove           _HD_SS_CellRemove
#    define  HD_SS_CellSelect           _HD_SS_CellSelect
#    define  HD_SS_CellSetChar          _HD_SS_CellSetChar
#    define  HD_SS_CellSetDouble        _HD_SS_CellSetDouble
#    define  HD_SS_CellSetStr           _HD_SS_CellSetStr
#    define  HD_SS_ColNum2Str           _HD_SS_ColNum2Str
#    define  HD_SS_ColNum2StrC          _HD_SS_ColNum2StrC
#    define  HD_SS_ColRemove            _HD_SS_ColRemove
#    define  HD_SS_ColsRemove           _HD_SS_ColsRemove
#    define  HD_SS_CoordCmp             _HD_SS_CoordCmp
#    define  HD_SS_FontGet              _HD_SS_FontGet
#    define  HD_SS_Free                 _HD_SS_Free
#    define  HD_SS_Load                 _HD_SS_Load
#    define  HD_SS_New                  _HD_SS_New
#    define  HD_SS_Rand                 _HD_SS_Rand
#    define  HD_SS_Range2Mtx            _HD_SS_Range2Mtx
#    define  HD_SS_Range2Mtxf           _HD_SS_Range2Mtxf
#    define  HD_SS_RangeGet             _HD_SS_RangeGet
#    define  HD_SS_RangeTrim            _HD_SS_RangeTrim
#    define  HD_SS_Ranges2Mtx           _HD_SS_Ranges2Mtx
#    define  HD_SS_Ranges2Mtxf          _HD_SS_Ranges2Mtxf
#    define  HD_SS_RangesTrim           _HD_SS_RangesTrim
#    define  HD_SS_RowRemove            _HD_SS_RowRemove
#    define  HD_SS_RowsRemove           _HD_SS_RowsRemove
#    define  HD_SS_Save                 _HD_SS_Save
#    define  HD_SS_SheetAdd             _HD_SS_SheetAdd
#    define  HD_SS_SheetMove            _HD_SS_SheetMove
#    define  HD_SS_SheetRemove          _HD_SS_SheetRemove
#    define  HD_SS_StrC2ColNum          _HD_SS_StrC2ColNum
#    define  HD_SS_Str2ColNum           _HD_SS_Str2ColNum
#    define  HD_SS_StrC2Range           _HD_SS_StrC2Range
#    define  HD_SS_StrC2Ranges          _HD_SS_StrC2Ranges

#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_SS_CacheBuild(HD_SS_SHEET Sheet);
HDRIVE_EXTERN HD_SS_CELL        HDRIVE_EXPORT HD_SS_CacheCellFind(HD_SS_SHEET Sheet, HD_ULONG Col, HD_ULONG Row);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT HD_SS_CellCoordCmp(HD_SS_CELL Cell1, HD_SS_CELL Cell2);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_SS_CellCopy(HD_SS_SHEET DestSheet, HD_ULONG DestCol, HD_ULONG DestRow, HD_SS_SHEET SrcSheet, HD_SS_RANGE *SrcRange);
HDRIVE_EXTERN HD_SS_CELL        HDRIVE_EXPORT HD_SS_CellFind(HD_SS_SHEET Sheet, HD_ULONG Col, HD_ULONG Row);
HDRIVE_EXTERN const HD_CHAR *   HDRIVE_EXPORT HD_SS_CellGetChar(HD_SS_SHEET Sheet, HD_ULONG Col, HD_ULONG Row);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_SS_CellGetDouble(HD_SS_SHEET Sheet, HD_ULONG Col, HD_ULONG Row);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT HD_SS_CellGetStr(HD_SS_SHEET Sheet, HD_ULONG Col, HD_ULONG Row);
HDRIVE_EXTERN HD_SS_CELL        HDRIVE_EXPORT HD_SS_CellLock(HD_SS_SHEET Sheet, HD_ULONG Col, HD_ULONG Row);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_SS_CellMove(HD_SS_SHEET DestSheet, HD_ULONG DestCol, HD_ULONG DestRow, HD_SS_SHEET SrcSheet, HD_SS_RANGE *SrcRange);
HDRIVE_EXTERN HD_ULONG          HDRIVE_EXPORT HD_SS_CellRemove(HD_SS_SHEET Sheet, HD_SS_RANGE *Range);
HDRIVE_EXTERN HD_LIST *         HDRIVE_EXPORT HD_SS_CellSelect(HD_LIST *SelList, HD_SS_SHEET Sheet, HD_SS_RANGE *Range);
HDRIVE_EXTERN HD_SS_CELL        HDRIVE_EXPORT HD_SS_CellSetChar(HD_SS_SHEET Sheet, HD_ULONG Col, HD_ULONG Row, const HD_CHAR *Val);
HDRIVE_EXTERN HD_SS_CELL        HDRIVE_EXPORT HD_SS_CellSetDouble(HD_SS_SHEET Sheet, HD_ULONG Col, HD_ULONG Row, HD_DOUBLE Val);
HDRIVE_EXTERN HD_SS_CELL        HDRIVE_EXPORT HD_SS_CellSetStr(HD_SS_SHEET Sheet, HD_ULONG Col, HD_ULONG Row, HD_STRING Val);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_SS_ColNum2Str(HD_STRING Str, HD_ULONG Col);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_SS_ColNum2StrC(HD_CHAR *Str, HD_ULONG StrSize, HD_ULONG Col);
HDRIVE_EXTERN HD_ULONG          HDRIVE_EXPORT HD_SS_ColRemove(HD_SS_SHEET Sheet, HD_ULONG Col);
HDRIVE_EXTERN HD_ULONG          HDRIVE_EXPORT HD_SS_ColsRemove(HD_SS_SHEET Sheet, HD_ULONG FirstCol, HD_ULONG LastCol);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT HD_SS_CoordCmp(HD_ULONG Col1, HD_ULONG Row1, HD_ULONG Col2, HD_ULONG Row2);
HDRIVE_EXTERN HD_FONT           HDRIVE_EXPORT HD_SS_FontGet(HD_SPREADSHEET Ss, HD_SS_SHEET Sheet, HD_SS_CELL Cell);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_SS_Free(HD_SPREADSHEET Ss);
HDRIVE_EXTERN HD_SPREADSHEET    HDRIVE_EXPORT HD_SS_Load(const HD_CHAR *FileName, HD_LONG Flags);
HDRIVE_EXTERN HD_SPREADSHEET    HDRIVE_EXPORT HD_SS_New(HD_ULONG NumSheets);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_SS_Rand(HD_SS_SHEET Sheet, HD_SS_RANGE *Range, HD_LONG What);
HDRIVE_EXTERN HD_MTX            HDRIVE_EXPORT HD_SS_Range2Mtx(HD_SS_SHEET Sheet, HD_SS_RANGE *Range);
HDRIVE_EXTERN HD_MTXF           HDRIVE_EXPORT HD_SS_Range2Mtxf(HD_SS_SHEET Sheet, HD_SS_RANGE *Range);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_SS_RangeGet(HD_SS_SHEET Sheet, HD_SS_RANGE *Range);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_SS_RangeTrim(HD_SS_SHEET Sheet, HD_SS_RANGE *Range);
HDRIVE_EXTERN HD_MTX            HDRIVE_EXPORT HD_SS_Ranges2Mtx(HD_SS_SHEET Sheet, HD_LIST *RangeList);
HDRIVE_EXTERN HD_MTXF           HDRIVE_EXPORT HD_SS_Ranges2Mtxf(HD_SS_SHEET Sheet, HD_LIST *RangeList);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_SS_RangesTrim(HD_SS_SHEET Sheet, HD_LIST *RangeList);
HDRIVE_EXTERN HD_ULONG          HDRIVE_EXPORT HD_SS_RowRemove(HD_SS_SHEET Sheet, HD_ULONG Row);
HDRIVE_EXTERN HD_ULONG          HDRIVE_EXPORT HD_SS_RowsRemove(HD_SS_SHEET Sheet, HD_ULONG FirstRow, HD_ULONG LastRow);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_SS_Save(const HD_CHAR *FileName, HD_SPREADSHEET Ss, HD_SS_SHEET Sheet, HD_LONG Format, HD_LONG Flags);
HDRIVE_EXTERN HD_SS_SHEET       HDRIVE_EXPORT HD_SS_SheetAdd(HD_SPREADSHEET Ss);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_SS_SheetMove(HD_SPREADSHEET Ss, HD_SS_SHEET Sheet, HD_ULONG Pos);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_SS_SheetRemove(HD_SPREADSHEET Ss, HD_SS_SHEET Sheet);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_SS_Str2ColNum(HD_ULONG *Col, HD_STRING Str);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_SS_StrC2ColNum(HD_ULONG *Col, HD_CHAR *Str);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_SS_StrC2Range(HD_SS_RANGE *Range, HD_CHAR *Str);
HDRIVE_EXTERN HD_LIST *         HDRIVE_EXPORT HD_SS_StrC2Ranges(HD_CHAR *Str);

#  ifdef __cplusplus
   }
#  endif
#endif

