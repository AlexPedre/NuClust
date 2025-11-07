
/*************************************************
****            VEGA - ODBC helper            ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_ODBC_H
#  define  __VG_ODBC_H
#  include <sql.h>
#  include <sqlext.h>
#  include <hdstring.h>

/**** ODBC connection flags ****/

#  define  VG_ODBC_CONNF_NONE           0
#  define  VG_ODBC_CONNF_CONNECTED      1

/**** VG_OdbcExec() flags ****/

#  define  VG_ODBC_EXEC_NONE            0       /* None                       */
#  define  VG_ODBC_EXEC_KEEP            1       /* Keep the statement         */

/**** VG_OdbcInsertRow() flags ****/

#  define  VG_ODBC_INSFLG_NONE          0       /* None                       */
#  define  VG_ODBC_INSFLG_DATETIME      1       /* Insert date & time         */

/**** ODBC context structure ****/

struct __vg_odbc {
  HD_STRING     ErrStr;                 /* Error message                 */
  HD_STRING     PriKeyName;             /* Default primary key name      */
  HD_STRING     BlobType;               /* Blob data type                */
  HDBC          hDBC;                   /* Handle to database connection */
  HSTMT         hStmt;                  /* Statement handle              */
  HD_LONG       Flags;                  /* Flags                         */
  HD_LONG       ServerType;             /* Server type                   */
  HD_CHAR       QuoteCl;                /* Closing quote                 */
  HD_CHAR       QuoteOp;                /* Opening quote                 */
};

typedef struct __vg_odbc *      VG_ODBC;

#  if defined(LINUX) || defined(WIN32)
#    ifdef LINUX
#      define  VG_ODBC_DLL              "libodbc.so"
#      define  WINAPI
#    else
#      define  VG_ODBC_DLL              "odbc32.dll"
#    endif

#    ifdef VG_ODBC_DYNDLL
#      define  VG_ODBC_EXTERN
#    else
#      ifdef __cplusplus
#        define  VG_ODBC_EXTERN         extern "C"
#      else
#        define  VG_ODBC_EXTERN         extern
#      endif
#    endif

VG_ODBC_EXTERN SQLRETURN        (WINAPI *VG_SQLAllocHandle)(SQLSMALLINT HandleType, SQLHANDLE InputHandle, SQLHANDLE *OutputHandlePtr);
VG_ODBC_EXTERN SQLRETURN        (WINAPI *VG_SQLBindCol)(SQLHSTMT StatementHandle, SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
                                                        SQLPOINTER TargetValuePtr, SQLLEN BufferLength, SQLLEN *StrLen_or_Ind);
VG_ODBC_EXTERN SQLRETURN        (WINAPI *VG_SQLBindParameter)(SQLHSTMT StatementHandle, SQLUSMALLINT ParameterNumber, SQLSMALLINT InputOutputType,
                                                              SQLSMALLINT ValueType, SQLSMALLINT ParameterType, SQLULEN ColumnSize,
                                                              SQLSMALLINT DecimalDigits, SQLPOINTER ParameterValuePtr, SQLLEN BufferLength,
                                                              SQLLEN *StrLen_or_IndPtr);
VG_ODBC_EXTERN SQLRETURN        (WINAPI *VG_SQLColAttribute)(SQLHSTMT StatementHandle, SQLUSMALLINT ColumnNumber, SQLUSMALLINT FieldIdentifier,
                                                             SQLPOINTER CharacterAttributePtr, SQLSMALLINT BufferLength, SQLSMALLINT *StringLengthPtr,
                                                             SQLLEN *NumericAttributePtr);
VG_ODBC_EXTERN SQLRETURN        (WINAPI *VG_SQLDisconnect)(SQLHDBC ConnectionHandle);
VG_ODBC_EXTERN SQLRETURN        (WINAPI *VG_SQLDriverConnect)(SQLHDBC ConnectionHandle, SQLHWND WindowHandle, SQLCHAR *InConnectionString,
                                                              SQLSMALLINT StringLength1, SQLCHAR *OutConnectionString, SQLSMALLINT BufferLength,
                                                              SQLSMALLINT *StringLength2Ptr, SQLUSMALLINT DriverCompletion);
VG_ODBC_EXTERN SQLRETURN        (WINAPI *VG_SQLExecDirect)(SQLHSTMT StatementHandle, SQLCHAR *StatementText, SQLINTEGER TextLength);
VG_ODBC_EXTERN SQLRETURN        (WINAPI *VG_SQLExecute)(SQLHSTMT StatementHandle);
VG_ODBC_EXTERN SQLRETURN        (WINAPI *VG_SQLFetch)(SQLHSTMT StatementHandle);
VG_ODBC_EXTERN SQLRETURN        (WINAPI *VG_SQLFreeHandle)(SQLSMALLINT HandleType, SQLHANDLE Handle);
VG_ODBC_EXTERN SQLRETURN        (WINAPI *VG_SQLFreeStmt)(SQLHSTMT StatementHandle, SQLUSMALLINT Option);
VG_ODBC_EXTERN SQLRETURN        (WINAPI *VG_SQLGetDiagRec)(SQLSMALLINT HandleType, SQLHANDLE Handle, SQLSMALLINT RecNumber, SQLCHAR * SQLState,
                                                           SQLINTEGER *NativeErrorPtr, SQLCHAR *MessageText, SQLSMALLINT BufferLength,
                                                           SQLSMALLINT *TextLengthPtr);
VG_ODBC_EXTERN SQLRETURN        (WINAPI *VG_SQLGetInfo)(SQLHDBC ConnectionHandle, SQLUSMALLINT InfoType, SQLPOINTER InfoValuePtr, SQLSMALLINT  BufferLength,
                                                        SQLSMALLINT * StringLengthPtr);
VG_ODBC_EXTERN SQLRETURN        (WINAPI *VG_SQLNumResultCols)(SQLHSTMT StatementHandle, SQLSMALLINT *ColumnCountPtr);
VG_ODBC_EXTERN SQLRETURN        (WINAPI *VG_SQLPrepare)(SQLHSTMT StatementHandle, SQLCHAR *StatementText, SQLINTEGER TextLength);
VG_ODBC_EXTERN SQLRETURN        (WINAPI *VG_SQLSetConnectAttr)(SQLHDBC ConnectionHandle, SQLINTEGER Attribute, SQLPOINTER ValuePtr, SQLINTEGER StringLength);
VG_ODBC_EXTERN SQLRETURN        (WINAPI *VG_SQLSetEnvAttr)(SQLHENV EnvironmentHandle, SQLINTEGER Attribute, SQLPOINTER ValuePtr, SQLINTEGER StringLength);
VG_ODBC_EXTERN SQLRETURN        (WINAPI *VG_SQLSetStmtAttr)(SQLHSTMT StatementHandle, SQLINTEGER Attribute, SQLPOINTER ValuePtr, SQLINTEGER StringLength);



#  else

#    define  VG_SQLAllocHandle                  SQLAllocHandle
#    define  VG_SQLBindCol                      SQLBindCol
#    define  VG_SQLBindParameter                SQLBindParameter
#    define  VG_SQLColAttribute                 SQLColAttribute
#    define  VG_SQLDisconnect                   SQLDisconnect
#    define  VG_SQLDriverConnect                SQLDriverConnect
#    define  VG_SQLExecDirect                   SQLExecDirect
#    define  VG_SQLExecute                      SQLExecute
#    define  VG_SQLFetch                        SQLFetch
#    define  VG_SQLFreeHandle                   SQLFreeHandle
#    define  VG_SQLFreeStmt                     SQLFreeStmt
#    define  VG_SQLGetDiagRec                   SQLGetDiagRec
#    define  VG_SQLGetInfo                      SQLGetInfo
#    define  VG_SQLNumResultCols                SQLNumResultCols
#    define  VG_SQLPrepare                      SQLPrepare
#    define  VG_SQLSetConnectAttr               SQLSetConnectAttr
#    define  VG_SQLSetEnvAttr                   SQLSetEnvAttr
#    define  VG_SQLSetStmtAttr                  SQLSetStmtAttr

#  endif

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_AssignTriposFF                  _VG_AssignTriposFF
#    define  VG_Odbc2VegaType                   _VG_Odbc2VegaType
#    define  VG_OdbcAlterColumn                 _VG_OdbcAlterColumn
#    define  VG_OdbcBlobGetID                   _VG_OdbcBlobGetID
#    define  VG_OdbcBlobPutID                   _VG_OdbcBlobPutID
#    define  VG_OdbcClose                       _VG_OdbcClose
#    define  VG_OdbcCreateIndex                 _VG_OdbcCreateIndex
#    define  VG_OdbcCreateTable                 _VG_OdbcCreateTable
#    define  VG_OdbcDeleteRow                   _VG_OdbcDeleteRow
#    define  VG_OdbcExec                        _VG_OdbcExec
#    define  VG_OdbcFree                        _VG_OdbcFree
#    define  VG_OdbcFindLastId                  _VG_OdbcFindLastId
#    define  VG_OdbcInsertRow                   _VG_OdbcInsertRow
#    define  VG_OdbcOpen                        _VG_OdbcOpen
#    define  VG_OdbcOpenAccess                  _VG_OdbcOpenAccess
#    define  VG_OdbcOpenDSN                     _VG_OdbcOpenDSN
#    define  VG_OdbcTableExist                  _VG_OdbcTableExist
#    define  VG_OdbcTableInfo                   _VG_OdbcTableInfo
#    define  VG_OdbcUpdateRow                   _VG_OdbcUpdateRow
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_LONG         VEGA_EXPORT  VG_Odbc2VegaType(SQLLEN Type);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_OdbcAlterColumn(VG_ODBC hOdbc, const HD_CHAR *Table, const HD_CHAR *Column, HD_CHAR *DefStr);
VEGA_EXTERN HD_BYTE *       VEGA_EXPORT  VG_OdbcBlobGetID(VG_ODBC hOdbc, const HD_CHAR *Table, const HD_CHAR *Column, HD_UDLONG Id, HD_ULONG *DataLen, HD_BOOL UnPack);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_OdbcBlobPutID(VG_ODBC hOdbc, const HD_CHAR *Table, const HD_CHAR *Column, HD_UDLONG Id, HD_CHAR *Data, int DataLen, HD_LONG Pack);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_OdbcClose(VG_ODBC hOdbc);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_OdbcCreateIndex(VG_ODBC hOdbc, HD_CHAR *Table, HD_CHAR *Field);
VEGA_EXTERN HD_BOOL         VEGA_EXPORTA VG_OdbcCreateTable(VG_ODBC hOdbc, const HD_CHAR *Table, const HD_CHAR *PrimaryKey, ...);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_OdbcDeleteRow(VG_ODBC hOdbc, const HD_CHAR *Table, HD_UDLONG Id);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_OdbcExec(VG_ODBC hOdbc, const HD_CHAR *SqlStr, HD_LONG Flags);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_OdbcFree(HD_VOID);
VEGA_EXTERN HD_UDLONG       VEGA_EXPORT  VG_OdbcFindLastId(VG_ODBC hOdbc, const HD_CHAR *Table);
VEGA_EXTERN HD_BOOL         VEGA_EXPORTA VG_OdbcInsertRow(VG_ODBC hOdbc, const HD_CHAR *Table, HD_LONG Flags, ...);
VEGA_EXTERN VG_ODBC         VEGA_EXPORT  VG_OdbcOpen(const HD_CHAR *DsnStr);
VEGA_EXTERN VG_ODBC         VEGA_EXPORT  VG_OdbcOpenAccess(const HD_CHAR *FileName, HD_LONG OdbcServer);
VEGA_EXTERN VG_ODBC         VEGA_EXPORT  VG_OdbcOpenDSN(const HD_CHAR *DsnFileName);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_OdbcTableExist(VG_ODBC hOdbc, const HD_CHAR *Table);
VEGA_EXTERN HD_LIST *       VEGA_EXPORT  VG_OdbcTableInfo(VG_ODBC hOdbc, const HD_CHAR *Table);
VEGA_EXTERN HD_BOOL         VEGA_EXPORTA VG_OdbcUpdateRow(VG_ODBC hOdbc, const HD_CHAR *Table, HD_UDLONG Id, ...);

#  ifdef __cplusplus
}
#  endif
#endif

