
/*************************************************
****          VEGA - SQLite helper            ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_SQLITE_H
#  define  __VG_SQLITE_H

#  include <sqlite3.h>
#  include <hdstring.h>

#  if defined(WIN32) && !defined(__TINYC__)
#    define  VG_SQLITE_CALL               _cdecl
typedef int (_cdecl *SQLITE_CALLBACK)(HD_VOID *Param, int ColCount, HD_CHAR **Cols, HD_CHAR **ColNames);
#  else
#    define  VG_SQLITE_CALL
typedef int (*SQLITE_CALLBACK)(HD_VOID *Param, int ColCount, HD_CHAR **Cols, HD_CHAR **ColNames);
#  endif

/**** SQLite context ****/

typedef struct {
  HD_MUTEX              hMutex;                 /* Thread safe mutex          */
  HD_STRING             ErrStr;                 /* Error message              */
  HD_STRING             PriKeyName;             /* Primary key ID             */
  sqlite3 *             Db;                     /* Database handle            */
} VG_SQLITE;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_SQLiteBlobGet                   _VG_SQLiteBlobGet
#    define  VG_SQLiteBlobPutID                 _VG_SQLiteBlobPutID
#    define  VG_SQLiteClose                     _VG_SQLiteClose
#    define  VG_SQLiteDeleteRow                 _VG_SQLiteDeleteRow
#    define  VG_SQLiteDeleteRowAll              _VG_SQLiteDeleteRowAl
#    define  VG_SQLiteExec                      _VG_SQLiteExec
#    define  VG_SQLiteFindId                    _VG_SQLiteFindId
#    define  VG_SQLiteFindLastId                _VG_SQLiteFindLastId
#    define  VG_SQLiteFindRowId                 _VG_SQLiteFindRowId
#    define  VG_SQLiteInsertRow                 _VG_SQLiteInsertRow
#    define  VG_SQLiteOpen                      _VG_SQLiteOpen
#    define  VG_SQLiteTableExist                _VG_SQLiteTableExist
#    define  VG_SQLiteUpdateRow                 _VG_SQLiteUpdateRow
#    define  VG_SQLiteSetProgress               _VG_SQLiteSetProgress
#    define  VG_SQLiteTableInfo                 _VG_SQLiteTableInfo
#    define  VG_SQLiteTurbo                     _VG_SQLiteTurbo
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_BYTE *       VEGA_EXPORT  VG_SQLiteBlobGet(VG_SQLITE *Ctx, const HD_CHAR *Database, const HD_CHAR *Table, const HD_CHAR *Column, HD_UDLONG Row, HD_ULONG *DataLen, HD_BOOL UnPack);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_SQLiteBlobPutID(VG_SQLITE *Ctx, const HD_CHAR *Database, const HD_CHAR *Table, const HD_CHAR *Column, HD_UDLONG Id, HD_CHAR *Data, int DataLen, HD_BOOL Pack);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_SQLiteClose(VG_SQLITE *Ctx);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_SQLiteDeleteRow(VG_SQLITE *Ctx, const HD_CHAR *Database, const HD_CHAR *Table, HD_UDLONG Id);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_SQLiteDeleteRowAll(VG_SQLITE *Ctx, const HD_CHAR *Table);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_SQLiteExec(VG_SQLITE *Ctx, const HD_CHAR *SqlStr, SQLITE_CALLBACK CallBack, HD_VOID *CallBackArg);
VEGA_EXTERN HD_UDLONG       VEGA_EXPORT  VG_SQLiteFindId(VG_SQLITE *Ctx, const HD_CHAR *Table, HD_UDLONG RowId);
VEGA_EXTERN HD_UDLONG       VEGA_EXPORT  VG_SQLiteFindLastId(VG_SQLITE *Ctx, const HD_CHAR *Table);
VEGA_EXTERN HD_UDLONG       VEGA_EXPORT  VG_SQLiteFindRowId(VG_SQLITE *Ctx, const HD_CHAR *Database, const HD_CHAR *Table, HD_UDLONG Id);
VEGA_EXTERN HD_BOOL         VEGA_EXPORTA VG_SQLiteInsertRow(VG_SQLITE *Ctx, const HD_CHAR *Table, ...);
VEGA_EXTERN VG_SQLITE *     VEGA_EXPORT  VG_SQLiteOpen(const HD_CHAR *FileName);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_SQLiteTableExist(VG_SQLITE *Ctx, const HD_CHAR *Table);
VEGA_EXTERN HD_BOOL         VEGA_EXPORTA VG_SQLiteUpdateRow(VG_SQLITE *Ctx, const HD_CHAR *Table, HD_UDLONG Id, ...);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_SQLiteSetProgress(VG_SQLITE *Ctx, HD_LONG (*CallBack)(HD_VOID*), HD_VOID *Arg);
VEGA_EXTERN HD_LIST *       VEGA_EXPORT  VG_SQLiteTableInfo(VG_SQLITE *Ctx, const HD_CHAR *Table);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_SQLiteTurbo(VG_SQLITE *Ctx, HD_BOOL Enable);

#  ifdef __cplusplus
}
#  endif
#endif
