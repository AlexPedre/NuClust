
/*************************************************
****           VEGA - Database engine         ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_DB_ENGINE_H
#  define  __VG_DB_ENGINE_H

#  include <hdstring.h>

/**** Constants ****/

#  define  VG_DB_DATFILE_NAME           "database.dat"
#  define  VG_DB_DATFILE_VER            "1.0"
#  define  VG_DB_LARGEDB_SDF            10000000
#  define  VG_DB_LARGEDB_SQLITE         1000000
#  define  VG_DB_DEFCOLSIZE             32
#  define  VG_DBSMI_LINESIZE            2048

/**** Column types ****/

#  define  VG_DB_CTYP_UNKNOWN           0   /* Don't change the order ! */
#  define  VG_DB_CTYP_BLOB              1   /* Look DbSqlTableInfo      */
#  define  VG_DB_CTYP_DATE              2
#  define  VG_DB_CTYP_INTEGER           3
#  define  VG_DB_CTYP_REAL              4
#  define  VG_DB_CTYP_VARCHAR           5
#  define  VG_DB_CTYP_TIME              6

/**** User flags ****/

#  define  VG_DB_FLAGS_NONE             0
#  define  VG_DB_FLAGS_FNCGRP           1

/**** Database flags ****/

#  define  VG_DB_FLAG_NONE              0
#  define  VG_DB_FLAG_CR                1
#  define  VG_DB_FLAG_SDFNAMETAG        2
#  define  VG_DB_FLAG_SDFWRITEIDX       4
#  define  VG_DB_FLAG_LARGEDB           8
#  define  VG_DB_FLAG_LARGEDBSYNC      16
#  define  VG_DB_FLAG_READONLY         32
#  define  VG_DB_FLAG_SQL              64
#  define  VG_DB_FLAG_FILTERED        128
#  define  VG_DB_FLAG_RMFILEEXT       256
#  define  VG_DB_FLAG_USEOFFSET       512
#  define  VG_DB_FLAG_SWAP           1024
#  define  VG_DB_FLAG_USECACHE       2048

/**** Get modes ****/

#  define  VG_DB_GET_APPEND             0         /* Don't change the order        */
#  define  VG_DB_GET_REPLACE            1
#  define  VG_DB_GET_WORKSPACE          2

/**** Get flags ****/

#  define  VG_DB_GETFLAG_NONE           0
#  define  VG_DB_GETFLAG_COLBYATM       1
#  define  VG_DB_GETFLAG_ENMENU         2
#  define  VG_DB_GETFLAG_THSAFE         4
#  define  VG_DB_GETFLAG_VERBOSE        8
#  define  VG_DB_GETFLAG_ROWID         16

/**** VG_DbRen() flags ****/

#  define  VG_DB_REN_NONE               0
#  define  VG_DB_REN_NOSORT             1
#  define  VG_DB_REN_QUIET              2

/**** DbOpen() flags ****/

#  define VG_DB_OPENFLAG_NONE           0
#  define VG_DB_OPENFLAG_VERBOSE        1
#  define VG_DB_OPENFLAG_USECACHE       2

/**** Database types ****/

#  define  VG_DB_TYPE_UNK               0         /* Check:                              */
#  define  VG_DB_TYPE_FILE              1         /* DbCreateFormats[] in db_engine.c    */
#  define  VG_DB_TYPE_MOL2              2         /* CB_FormatChange() in dlg_dbopen.cpp */
#  define  VG_DB_TYPE_ODBC              3         /* OnShowEvent() in dlg_dbopen.cpp     */
#  define  VG_DB_TYPE_SDF               4         /* if you want to change the order.    */
#  define  VG_DB_TYPE_SMI               5
#  define  VG_DB_TYPE_SQLITE            6
#  define  VG_DB_TYPE_ZIP               7
#  define  VG_DB_TYPE_IUPAC             8         /* Put here read only Db formats       */
#  define  VG_DB_TYPE_MMD               9


/**** ODBC server types ****/

#  define  VG_ODBC_SRVTYP_GENERIC       0         /* Generic server                */
#  define  VG_ODBC_SRVTYP_ACCESS        1         /* Microsoft Access              */
#  define  VG_ODBC_SRVTYP_FIREBIRD      2         /* Firebird                      */
#  define  VG_ODBC_SRVTYP_MYSQL         3         /* MySQL                         */
#  define  VG_ODBC_SRVTYP_ORACLE        4         /* Oracle                        */
#  define  VG_ODBC_SRVTYP_SQLSERVER     5         /* Microsoft SQL Server          */
#  define  VG_ODBC_SRVTYP_ACCESS2007    6         /* Microsoft Access 2007         */

/**** Database locks ****/

#  define  VG_DB_LOCK_NONE              0         /* Database unlocked             */
#  define  VG_DB_LOCK_FRAGS             1         /* Locked by add frags           */

/**** VG_DbInfo() IDs ****/

enum {
  VG_DB_INFO_CURMOLNAME,              /* Don't change the order */
  VG_DB_INFO_FILEEXT,
  VG_DB_INFO_FILENAME,
  VG_DB_INFO_FORMAT,
  VG_DB_INFO_MOLECULES,
  VG_DB_INFO_MOLFLAGS,
  VG_DB_INFO_MOLFORMAT,
  VG_DB_INFO_QUOTECL,
  VG_DB_INFO_QUOTEOP,
  VG_DB_INFO_ISSQL,
  VG_DB_INFO_CURID
};

/**** Molecule flags ****/

#  define  VG_DB_MOLFLAG_NONE           0               /* Nothing                                   */
#  define  VG_DB_MOLFLAG_64BIT          1               /* 64 bit format                             */
#  define  VG_DB_MOLFLAG_BIGENDIAN      2               /* Big endian format                         */
#  define  VG_DB_MOLFLAG_CONN           4               /* Write the connectivity                    */
#  define  VG_DB_MOLFLAG_FIX            8               /* Write the constraints                     */
#  define  VG_DB_MOLFLAG_VERBOSE        0xffffffff      /* Verbose flag                              */

/**** Put flags ****/

#  define  VG_DB_PUTFLAG_NONE           0               /* None                                      */
#  define  VG_DB_PUTFLAG_UPDATE         1               /* Update                                    */
#  define  VG_DB_PUTFLAG_VERBOSE        2               /* Verbose                                   */
#  define  VG_DB_PUTFLAG_STOREONLY      4               /* Don't calculate the properties (only SQL) */

/**** Types ****/

#  define  VG_MOLLIST_FLAG_NONE         0               /* None                                      */
#  define  VG_MOLLIST_FLAG_RENAMED      1               /* Entry renamed                             */


/**** Cache item ****/

typedef struct __Vg_DbCacheList {
  struct __Vg_DbCacheList *   Next;                     /* Pointer to next item      */
  struct __Vg_DbCacheList *   Prev;                     /* Pointer to previuos item  */
  HD_ATOM *                   BegAtm;                   /* Pointer of the first atom */
  HD_ATOM *                   LastAtm;                  /* Pointer to the last atom  */
  HD_DLONG                    Offset;                   /* Database offset           */
  HD_LONG                     FormatID;                 /* Format ID                 */
  HD_ULONG                    TotalAtm;                 /* Number of atoms           */
} VG_DBCACHELIST;


/**** List of molecules ****/

typedef struct __Vg_DbMolList {
  struct __Vg_DbMolList *Next;                          /* Pointer to next item      */
  struct __Vg_DbMolList *Prev;                          /* Pointer to previuos item  */
  HD_DLONG              Offset;                         /* Database offset           */
  HD_STRING             Name;                           /* Molecule name             */
  HD_BYTE               Flag;                           /* Record flags              */
} VG_DBMOLLIST;

/**** List of list of molecules ****/

typedef struct __Vg_DbSelList {
  struct __Vg_DbSelList *Next;                          /* Pointer to next item      */
  struct __Vg_DbSelList *Prev;                          /* Pointer to previuos item  */
  HD_LIST *             MolList;                        /* Molecule list             */

  HD_LONG               VclCurMol;                      /* Used to retrive the VCL   */
  VG_DBMOLLIST *        VclCurMolPtr;                   /* data                      */
} VG_DBSELLIST;

/**** Database context ****/

typedef struct __VgDbInfo {
  struct __VgDbInfo *   Next;                           /* Pointer to next item      */
  struct __VgDbInfo *   Prev;                           /* Pointer to previuos item  */
  HD_STRING             FileName;                       /* Database file name        */
  HD_STRING             CurMolName;                     /* Last managed molecule     */
  HD_VOID *             Handle;                         /* Database handle           */
  HD_VOID *             GlobalInfo;                     /* Global info (zip)         */
  HD_ULONG              Id;                             /* Identification number     */
  HD_UWORD              OdbcServer;                     /* ODBC server type          */
  HD_UWORD              Type;                           /* Database format           */
  HD_LONG               Flags;                          /* Database flags            */
  VG_FILEFORMAT *       MolFormat;                      /* Default molecule format   */
  HD_LONG               MolFlags;                       /* Default molecule flags    */

  VG_DBSELLIST *        CurList;                        /* Current selection         */
  HD_LIST *             SelList;                        /* List of selections        */
  HD_LIST *             Cache;                          /* Cache list                */

  VG_DBMOLLIST *        CurMol;                         /* Current molecule          */
  HD_ULONG              TotMol;                         /* Molecules in the database */
  HD_WORD               Lock;                           /* Lock mode                 */
  HD_UWORD              MolPack;                        /* Compression mode          */

  HD_CHAR               QuoteCl;                        /* Closing quote             */
  HD_CHAR               QuoteOp;                        /* Opening quote             */
} VG_DBINFO;

/**** Structure to fetch the data ****/

typedef struct {
  HD_CHAR *             Data;                           /* Data                      */
  HD_LONG               Type;                           /* Data type                 */
} VG_DBEXPORTDATA;

/**** Database formats ****/

typedef struct {
  HD_CHAR *             Name;                           /* Database format name      */
  HD_CHAR *             Extension;                      /* Database file extension   */
  HD_UWORD              Type;                           /* Database type             */
  HD_UWORD              OdbcServer;                     /* Odbc server               */
} VG_DBFORMAT;

/**** Table structure ****/

typedef struct __vg_db_tabcol {
  struct __vg_db_tabcol *       Next;                   /* Pointer to next element    */
  struct __vg_db_tabcol *       Prev;                   /* Pointer to previous elem.  */
  HD_STRING                     Name;                   /* Column name                */
  HD_LONG                       Flags;                  /* Flags                      */
  HD_LONG                       Len;                    /* Field lenght               */
  HD_LONG                       Type;                   /* Column type                */
} VG_DBTABCOL;

/**** Global variables ****/

extern const VG_DBFORMAT        DbCreateFormats[];      /* To change it, see db_engine.c */

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_DbClose                         _VG_DbClose
#    define  VG_DbCloseAll                      _VG_DbCloseAll
#    define  VG_DbDatRead                       _VG_DbDatRead

#    define  VG_DbFileClose                     _VG_DbFileClose
#    define  VG_DbFileGet                       _VG_DbFileGet
#    define  VG_DbFileMolListRead               _VG_DbFileMolListRead
#    define  VG_DbFileOpen                      _VG_DbFileOpen

#    define  VG_DbCacheGet                      _VG_DbCacheGet
#    define  VG_DbGet                           _VG_DbGet
#    define  VG_DbGetFormatByName               _VG_DbGetFormatByName
#    define  VG_DbGetRaw                        _VG_DbGetRaw
#    define  VG_DbGetRawRid                     _VG_DbGetRawRid
#    define  VG_DbIndexCreate                   _VG_DbIndexCreate
#    define  VG_DbIndexRead                     _VG_DbIndexRead
#    define  VG_DbInfoFromId                    _VG_DbInfoFromId
#    define  VG_DbLength                        _VG_DbLength
#    define  VG_DbMolListAdd                    _VG_DbMolListAdd
#    define  VG_DbMolListChk                    _VG_DbMolListChk
#    define  VG_DbMolListClear                  _VG_DbMolListClear
#    define  VG_DbMolListGet                    _VG_DbMolListGet
#    define  VG_DbMolListGetRowID               _VG_DbMolListGetRowID
#    define  VG_DbMolListRead                   _VG_DbMolListRead
#    define  VG_DbSelListClearAll               _VG_DbSelListClearAll
#    define  VG_MolListSort                     _VG_MolListSort
#    define  VG_MolListSortAll                  _VG_MolListSortAll
#    define  VG_DbOpen                          _VG_DbOpen

#    define  VG_DbIupacClose                    _VG_DbIupacClose
#    define  VG_DbIupacGet                      _VG_DbIupacGet
#    define  VG_DbIupacGetSmi                   _VG_DbIupacGetSmi
#    define  VG_DbIupacMolListRead              _VG_DbIupacMolListRead
#    define  VG_DbIupacOpen                     _VG_DbIupacOpen

#    define  VG_DbMmdClose                      _VG_DbMmdClose
#    define  VG_DbMmdGet                        _VG_DbMmdGet
#    define  VG_DbMmdMolListRead                _VG_DbMmdMolListRead
#    define  VG_DbMmdOpen                       _VG_DbMmdOpen

#    define  VG_DbMol2Close                     _VG_DbMol2Close
#    define  VG_DbMol2Get                       _VG_DbMol2Get
#    define  VG_DbMol2MolListRead               _VG_DbMol2MolListRead
#    define  VG_DbMol2Open                      _VG_DbMol2Open
#    define  VG_DbMol2Ren                       _VG_DbMol2Ren

#    define  VG_DbOdbcClose                     _VG_DbOdbcClose
#    define  VG_DbOdbcExec                      _VG_DbOdbcExec
#    define  VG_DbOdbcGetID                     _VG_DbOdbcGetID
#    define  VG_DbOdbcGetRaw                    _VG_DbOdbcGetRaw
#    define  VG_DbOdbcGetSmiles                 _VG_DbOdbcGetSmiles
#    define  VG_DbOdbcMolListRead               _VG_DbOdbcMolListRead
#    define  VG_DbOdbcOpen                      _VG_DbOdbcOpen

#    define  VG_DbSqlExec                       _VG_DbSqlExec
#    define  VG_DbSqlExecFast                   _VG_DbSqlExecFast
#    define  VG_DbSqlGet                        _VG_DbSqlGet
#    define  VG_DbSqlGetSmiles                  _VG_DbSqlGetSmiles

#    define  VG_DbSdfClose                      _VG_DbSdfClose
#    define  VG_DbSdfGet                        _VG_DbSdfGet
#    define  VG_DbSdfGetMol                     _VG_DbSdfGetMol
#    define  VG_DbSdfGetRaw                     _VG_DbSdfGetRaw
#    define  VG_DbSdfMolListRead                _VG_DbSdfMolListRead
#    define  VG_DbSdfOpen                       _VG_DbSdfOpen
#    define  VG_DbSdfReadLine                   _VG_DbSdfReadLine

#    define  VG_DbSmiClose                      _VG_DbSmiClose
#    define  VG_DbSmiGet                        _VG_DbSmiGet
#    define  VG_DbSmiGetSmi                     _VG_DbSmiGetSmi
#    define  VG_DbSmiMolListRead                _VG_DbSmiMolListRead
#    define  VG_DbSmiOpen                       _VG_DbSmiOpen

#    define  VG_DbSQLiteClose                   _VG_DbSQLiteClose
#    define  VG_DbSQLiteExec                    _VG_DbSQLiteExec
#    define  VG_DbSQLiteGetRaw                  _VG_DbSQLiteGetRaw
#    define  VG_DbSQLiteGetRowID                _VG_DbSQLiteGetRowID
#    define  VG_DbSQLiteGetSmiles               _VG_DbSQLiteGetSmiles
#    define  VG_DbSQLiteOpen                    _VG_DbSQLiteOpen
#    define  VG_DbSQLiteMolListRead             _VG_DbSQLiteMolListRead

#    define  VG_DbZipClose                      _VG_DbZipClose
#    define  VG_DbZipGet                        _VG_DbZipGet
#    define  VG_DbZipMolListRead                _VG_DbZipMolListRead
#    define  VG_DbZipOpen                       _VG_DbZipOpen

#    define  VG_DbCopyFinal                     _VG_DbCopyFinal
#    define  VG_DbCopyHead                      _VG_DbCopyHead
#    define  VG_DbCopyTail                      _VG_DbCopyTail
#    define  VG_DbDatCreate                     _VG_DbDatCreate

#    define  VG_DbFileCreate                    _VG_DbFileCreate
#    define  VG_DbFilePut                       _VG_DbFilePut
#    define  VG_DbFileRemove                    _VG_DbFileRemove
#    define  VG_DbFileRen                       _VG_DbFileRen

#    define  VG_DbCreate                        _VG_DbCreate
#    define  VG_DbInfo                          _VG_DbInfo
#    define  VG_DbMolListRemove                 _VG_DbMolListRemove
#    define  VG_DbPut                           _VG_DbPut
#    define  VG_DbRemove                        _VG_DbRemove
#    define  VG_DbRen                           _VG_DbRen
#    define  VG_DbSync                          _VG_DbSync

#    define  VG_DbIupacPut                      _VG_DbIupacPut
#    define  VG_DbIupacRemove                   _VG_DbIupacRemove
#    define  VG_DbIupacRen                      _VG_DbIupacRen

#    define  VG_DbMol2Create                    _VG_DbMol2Create
#    define  VG_DbMol2Put                       _VG_DbMol2Put
#    define  VG_DbMol2Remove                    _VG_DbMol2Remove
#    define  VG_DbMol2Sync                      _VG_DbMol2Sync

#    define  VG_DbOdbcMolListReadEx             _VG_DbOdbcMolListReadEx
#    define  VG_DbOdbcCreate                    _VG_DbOdbcCreate
#    define  VG_DbOdbcRemove                    _VG_DbOdbcRemove

#    define  VG_DbSdfCopy                       _VG_DbSdfCopy
#    define  VG_DbSdfCreate                     _VG_DbSdfCreate
#    define  VG_DbSdfPut                        _VG_DbSdfPut
#    define  VG_DbSdfPutLine                    _VG_DbSdfPutLine
#    define  VG_DbSdfRemove                     _VG_DbSdfRemove
#    define  VG_DbSdfRen                        _VG_DbSdfRen
#    define  VG_DbSdfReOffset                   _VG_DbSdfReOffset
#    define  VG_DbSdfSync                       _VG_DbSdfSync

#    define  VG_DbSmiCreate                     _VG_DbSmiCreate
#    define  VG_DbSmiPut                        _VG_DbSmiPut
#    define  VG_DbSmiRemove                     _VG_DbSmiRemove
#    define  VG_DbSmiRen                        _VG_DbSmiRen

#    define  VG_DbSQLiteCreate                  _VG_DbSQLiteCreate
#    define  VG_DbSQLiteMolListReadEx           _VG_DbSQLiteMolListReadEx
#    define  VG_DbSQLiteRemove                  _VG_DbSQLiteRemove

#    define  VG_DbSqlColumnAdd                  _VG_DbSqlColumnAdd
#    define  VG_DbSqlColumnCopy                 _VG_DbSqlColumnCopy
#    define  VG_DbSqlColumnDrop                 _VG_DbSqlColumnDrop
#    define  VG_DbSqlColumnRename               _VG_DbSqlColumnRename
#    define  VG_DbSqlMolListReadEx              _VG_DbSqlMolListReadEx
#    define  VG_DbSqlPut                        _VG_DbSqlPut
#    define  VG_DbSqlRen                        _VG_DbSqlRen

#    define  VG_DbZipCreate                     _VG_DbZipCreate
#    define  VG_DbZipPut                        _VG_DbZipPut
#    define  VG_DbZipRemove                     _VG_DbZipRemove

#    define  VG_SqlTableInfo                    _VG_SqlTableInfo
#    define  VG_SqlTableInfoFree                _VG_SqlTableInfoFree
#    define  VG_SqlUpdateRow                    _VG_SqlUpdateRow

#    define  VG_StrFixSqlQuotes                 _VG_StrFixSqlQuotes
#    define  VG_StrFixSqlQuotesC                _VG_StrFixSqlQuotesC
#endif

/**** Prototypes  ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbClose(VG_DBINFO *Dbh, HD_BOOL FreeAll, HD_BOOL Force);
VEGA_EXTERN HD_VOID             VEGA_EXPORT  VG_DbCloseAll(HD_LIST **Lh, HD_BOOL Force);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbDatRead(const HD_CHAR *FileName, VG_DBINFO *Dbh);

VEGA_EXTERN HD_VOID             VEGA_EXPORT  VG_DbFileClose(VG_DBINFO *Dbh);
VEGA_EXTERN HD_ATOM *           VEGA_EXPORT  VG_DbFileGet(VG_CTX *Ctx, VG_DBINFO *Dbh, HD_CHAR *MolName, HD_ATOM **LastAtomo, HD_ULONG *TotAtomo, HD_LONG *FormatID);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbFileMolListRead(VG_DBINFO *Dbh);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbFileOpen(VG_DBINFO *);

VEGA_EXTERN HD_ATOM *           VEGA_EXPORT  VG_DbCacheGet(VG_DBINFO *Dbh, HD_DLONG Offset, HD_ATOM **LastAtm, HD_ULONG *TotalAtm, HD_LONG *FormatID);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbGet(VG_CTX *Ctx, VG_DBINFO *Dbh, HD_CHAR *MolName, HD_UDLONG Idx, VG_DBMOLLIST *File, HD_LONG Mode, HD_LONG Flags);
VEGA_EXTERN const VG_DBFORMAT * VEGA_EXPORT  VG_DbGetFormatByName(const HD_CHAR *FormatName);
VEGA_EXTERN HD_ATOM *           VEGA_EXPORT  VG_DbGetRaw(VG_CTX *Ctx, VG_DBINFO *Dbh, HD_CHAR **MolName, HD_ULONG Idx, VG_DBMOLLIST *File, HD_ATOM **LastAtomo, HD_ULONG *TotAtomo, HD_LONG *FormatID);
VEGA_EXTERN HD_ATOM *           VEGA_EXPORT  VG_DbGetRawRid(VG_CTX *Ctx, VG_DBINFO *Dbh, HD_CHAR **MolName, HD_UDLONG RowID, HD_ATOM **LastAtomo, HD_ULONG *TotAtomo, HD_LONG *FormatID);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbIndexCreate(HD_CHAR *FileName, VG_DBINFO *Dbh);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbIndexRead(const HD_CHAR *FileName, VG_DBINFO *Dbh);
VEGA_EXTERN VG_DBINFO *         VEGA_EXPORT  VG_DbInfoFromId(HD_ULONG);
VEGA_EXTERN HD_UDLONG           VEGA_EXPORT  VG_DbLength(VG_DBINFO *Dbh);
VEGA_EXTERN VG_DBMOLLIST *      VEGA_EXPORT  VG_DbMolListAdd(VG_DBINFO *, HD_CHAR *);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbMolListChk(VG_DBINFO *, HD_CHAR *);
VEGA_EXTERN HD_VOID             VEGA_EXPORT  VG_DbMolListClear(HD_LIST *MolList);
VEGA_EXTERN VG_DBMOLLIST *      VEGA_EXPORT  VG_DbMolListGet(VG_DBINFO *, HD_CHAR *, HD_ULONG);
VEGA_EXTERN VG_DBMOLLIST *      VEGA_EXPORT  VG_DbMolListGetRowID(VG_DBINFO *Dbh, HD_UDLONG RowID);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbMolListRead(VG_DBINFO *Dbh);
VEGA_EXTERN HD_VOID             VEGA_EXPORT  VG_DbSelListClearAll(VG_DBINFO *Dbh);
VEGA_EXTERN HD_VOID             VEGA_EXPORT  VG_MolListSort(VG_DBINFO *Dbh);
VEGA_EXTERN HD_VOID             VEGA_EXPORT  VG_MolListSortAll(VG_DBINFO *Dbh);
VEGA_EXTERN VG_DBINFO *         VEGA_EXPORT  VG_DbOpen(const HD_CHAR *FileName, HD_LONG OpenFlags);

VEGA_EXTERN HD_VOID             VEGA_EXPORT  VG_DbIupacClose(VG_DBINFO *Dbh);
VEGA_EXTERN HD_ATOM *           VEGA_EXPORT  VG_DbIupacGet(VG_CTX *Ctx, VG_DBINFO *Dbh, HD_CHAR *MolName, HD_ATOM **LastAtomo, HD_ULONG *TotAtomo, VG_DBMOLLIST *Ptr);
VEGA_EXTERN HD_STRING           VEGA_EXPORT  VG_DbIupacGetSmi(VG_DBINFO *Dbh, VG_DBMOLLIST *Ptr);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbIupacMolListRead(VG_DBINFO *Dbh);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbIupacOpen(VG_DBINFO *Dbh);

VEGA_EXTERN HD_VOID             VEGA_EXPORT  VG_DbMmdClose(VG_DBINFO *Dbh);
VEGA_EXTERN HD_ATOM *           VEGA_EXPORT  VG_DbMmdGet(VG_CTX *Ctx, VG_DBINFO *Dbh, HD_CHAR *MolName, HD_ATOM **LastAtomo, HD_ULONG *TotAtomo, VG_DBMOLLIST *Ptr);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbMmdMolListRead(VG_DBINFO *Dbh);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbMmdOpen(VG_DBINFO *Dbh);

VEGA_EXTERN HD_VOID             VEGA_EXPORT  VG_DbMol2Close(VG_DBINFO *Dbh);
VEGA_EXTERN HD_ATOM *           VEGA_EXPORT  VG_DbMol2Get(VG_CTX *Ctx, VG_DBINFO *Dbh, HD_CHAR *MolName, HD_ATOM **LastAtomo, HD_ULONG *TotAtomo, VG_DBMOLLIST *Ptr);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbMol2MolListRead(VG_DBINFO *Dbh);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbMol2Open(VG_DBINFO *Dbh);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbMol2Ren(VG_DBINFO *Dbh, VG_DBMOLLIST *Itm, HD_CHAR *NewName);

VEGA_EXTERN HD_VOID             VEGA_EXPORT  VG_DbOdbcClose(VG_DBINFO *Dbh);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbOdbcExec(VG_DBINFO *Dbh, HD_STRING *Result, const HD_CHAR *SqlStr);
VEGA_EXTERN HD_ATOM *           VEGA_EXPORT  VG_DbOdbcGetID(VG_CTX *Ctx, VG_DBINFO *Dbh, HD_UDLONG Id, HD_ATOM **LastAtomo, HD_ULONG *TotAtomo);
VEGA_EXTERN HD_BYTE *           VEGA_EXPORT  VG_DbOdbcGetRaw(VG_DBINFO *Dbh, HD_UDLONG RowID, HD_ULONG *DataLen);
VEGA_EXTERN HD_STRING           VEGA_EXPORT  VG_DbOdbcGetSmiles(VG_DBINFO *Dbh, HD_UDLONG Id);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbOdbcMolListRead(VG_DBINFO *Dbh);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbOdbcOpen(VG_DBINFO *Dbh, HD_LONG OdbcServer);

VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSqlExec(VG_DBINFO *Dbh, HD_STRING *Result, const HD_CHAR *SqlStr);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSqlExecFast(VG_DBINFO *Dbh, const HD_CHAR *SqlStr);
VEGA_EXTERN HD_ATOM *           VEGA_EXPORT  VG_DbSqlGet(VG_CTX *Ctx, VG_DBINFO *Dbh, HD_CHAR *MolName, HD_ATOM **LastAtomo, HD_ULONG *TotAtomo, VG_DBMOLLIST *Ptr);
VEGA_EXTERN HD_STRING           VEGA_EXPORT  VG_DbSqlGetSmiles(VG_DBINFO *Dbh, HD_UDLONG Id);

VEGA_EXTERN HD_VOID             VEGA_EXPORT  VG_DbSdfClose(VG_DBINFO *);
VEGA_EXTERN HD_ATOM *           VEGA_EXPORT  VG_DbSdfGet(VG_CTX *Ctx, VG_DBINFO *Dbh, HD_CHAR *MolName, HD_ATOM **LastAtomo, HD_ULONG *TotAtomo, VG_DBMOLLIST *Ptr);
VEGA_EXTERN HD_STRING           VEGA_EXPORT  VG_DbSdfGetMol(VG_DBINFO *Dbh, VG_DBMOLLIST *Ptr);
VEGA_EXTERN HD_BYTE *           VEGA_EXPORT  VG_DbSdfGetRaw(VG_DBINFO *Dbh, VG_DBMOLLIST *Ptr, HD_ULONG *MolLen);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSdfMolListRead(VG_DBINFO *);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSdfOpen(VG_DBINFO *);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSdfReadLine(HD_CHAR *, VG_DBINFO *);

VEGA_EXTERN HD_VOID             VEGA_EXPORT  VG_DbSmiClose(VG_DBINFO *Dbh);
VEGA_EXTERN HD_ATOM *           VEGA_EXPORT  VG_DbSmiGet(VG_CTX *Ctx, VG_DBINFO *Dbh, HD_CHAR *MolName, HD_ATOM **LastAtomo, HD_ULONG *TotAtomo, VG_DBMOLLIST *Ptr);
VEGA_EXTERN HD_STRING           VEGA_EXPORT  VG_DbSmiGetSmi(VG_DBINFO *Dbh, VG_DBMOLLIST *Ptr);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSmiMolListRead(VG_DBINFO *Dbh);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSmiOpen(VG_DBINFO *Dbh);

VEGA_EXTERN HD_VOID             VEGA_EXPORT  VG_DbSQLiteClose(VG_DBINFO *Dbh);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSQLiteExec(VG_DBINFO *Dbh, HD_STRING *Result, const HD_CHAR *SqlStr);
VEGA_EXTERN HD_BYTE *           VEGA_EXPORT  VG_DbSQLiteGetRaw(VG_DBINFO *Dbh, HD_UDLONG RowId, HD_ULONG *DataLen);
VEGA_EXTERN HD_ATOM *           VEGA_EXPORT  VG_DbSQLiteGetRowID(VG_CTX *Ctx, VG_DBINFO *Dbh, HD_UDLONG RowId, HD_ATOM **LastAtomo, HD_ULONG *TotAtomo);
VEGA_EXTERN HD_STRING           VEGA_EXPORT  VG_DbSQLiteGetSmiles(VG_DBINFO *Dbh, HD_UDLONG Id);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSQLiteOpen(VG_DBINFO *Dbh);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSQLiteMolListRead(VG_DBINFO *Dbh);

VEGA_EXTERN HD_VOID             VEGA_EXPORT  VG_DbZipClose(VG_DBINFO *Dbh);
VEGA_EXTERN HD_ATOM *           VEGA_EXPORT  VG_DbZipGet(VG_CTX *Ctx, VG_DBINFO *Dbh, HD_CHAR *MolName, HD_ATOM **LastAtomo, HD_ULONG *TotAtomo, HD_LONG *FormatID);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbZipMolListRead(VG_DBINFO *Dbh);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbZipOpen(VG_DBINFO *Dbh);

/**** Write functions ****/

VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbCopyFinal(FILE *DH, VG_DBINFO *Dbh, HD_STRING FileName, VG_DBMOLLIST *Itm, HD_DLONG Delta);
VEGA_EXTERN FILE *              VEGA_EXPORT  VG_DbCopyHead(VG_DBINFO *Dbh, VG_DBMOLLIST *Itm, HD_STRING *FileName);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbCopyTail(FILE *DH, VG_DBINFO *Dbh, HD_DLONG *DeltPtr);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbDatCreate(const HD_CHAR *FileName, VG_DBINFO *Dbh);

VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbFileCreate(VG_DBINFO *Dbh);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbFilePut(VG_CTX *Ctx, VG_DBINFO *Dbh, HD_STRING MolName);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbFileRemove(VG_DBINFO *Dbh, VG_DBMOLLIST *Itm);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbFileRen(VG_DBINFO *Dbh, VG_DBMOLLIST *Itm, const HD_CHAR *NewName);

VEGA_EXTERN VG_DBINFO *         VEGA_EXPORT  VG_DbCreate(const HD_CHAR *FileName, HD_LONG Type, HD_LONG OdbcServer, VG_FILEFORMAT *MolFormat, HD_UWORD MolPack, HD_LONG MolFlags);
VEGA_EXTERN HD_VOID             VEGA_EXPORT  VG_DbInfo(VG_DBINFO *, HD_ULONG);
VEGA_EXTERN HD_VOID             VEGA_EXPORT  VG_DbMolListRemove(VG_DBINFO *, VG_DBMOLLIST *);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbPut(VG_CTX *Ctx, VG_DBINFO *Dbh, HD_STRING MolName, VG_DBMOLLIST **NewItm, HD_LONG Flags);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbRemove(VG_DBINFO *, VG_DBMOLLIST *);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbRen(VG_DBINFO *Dbh, VG_DBMOLLIST *Itm, HD_CHAR *NewName, HD_LONG Flags);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSync(VG_DBINFO *);

VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbIupacPut(VG_DBINFO *Dbh, HD_STRING MolName, HD_UDLONG *Offset, HD_BOOL Update);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbIupacRemove(VG_DBINFO *Dbh, VG_DBMOLLIST *Itm);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbIupacRen(VG_DBINFO *Dbh, VG_DBMOLLIST *Itm, const HD_CHAR *NewName);

VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbMol2Create(VG_DBINFO *Dbh);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbMol2Put(VG_CTX *Ctx, VG_DBINFO *Dbh, HD_STRING MolName, HD_UDLONG *Offset, HD_BOOL Update);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbMol2Remove(VG_DBINFO *Dbh, VG_DBMOLLIST *Itm);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbMol2Sync(VG_DBINFO *Dbh);

VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbOdbcMolListReadEx(VG_DBINFO *Dbh, HD_CHAR *Sql);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbOdbcCreate(VG_DBINFO *Dbh, HD_LONG ServerType);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbOdbcRemove(VG_DBINFO *Dbh, VG_DBMOLLIST *Itm);
VEGA_EXTERN
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSdfCopy(FILE *, FILE *, HD_DLONG, HD_DLONG);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSdfCreate(VG_DBINFO *);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSdfPut(VG_CTX *Ctx, VG_DBINFO *Dbh, HD_STRING MolName, HD_UDLONG *Offset, HD_BOOL Update);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSdfPutLine(FILE *, HD_CHAR *, HD_BOOL, HD_ULONG *);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSdfRemove(VG_DBINFO *, VG_DBMOLLIST *);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSdfRen(VG_DBINFO *, VG_DBMOLLIST *, HD_CHAR *);
VEGA_EXTERN HD_VOID             VEGA_EXPORT  VG_DbSdfReOffset(VG_DBMOLLIST *, HD_DLONG, HD_DLONG);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSdfSync(VG_DBINFO *Dbh);

VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSmiCreate(VG_DBINFO *Dbh);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSmiPut(VG_CTX *Ctx, VG_DBINFO *Dbh, HD_STRING MolName, HD_UDLONG *Offset, HD_BOOL Update);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSmiRemove(VG_DBINFO *Dbh, VG_DBMOLLIST *Itm);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSmiRen(VG_DBINFO *Dbh, VG_DBMOLLIST *Itm, const HD_CHAR *NewName);

VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSQLiteCreate(VG_DBINFO *Dbh);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSQLiteMolListReadEx(VG_DBINFO *Dbh, HD_CHAR *Sql);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSQLiteRemove(VG_DBINFO *Dbh, VG_DBMOLLIST *Itm);

VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSqlColumnAdd(VG_DBINFO *Dbh, const HD_CHAR *Table, const HD_CHAR *ColName, const HD_CHAR *SqlType);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSqlColumnCopy(VG_DBINFO *Dbh, const HD_CHAR *Table, const HD_CHAR *DestName, const HD_CHAR *SrcName);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSqlColumnDrop(VG_DBINFO *Dbh, const HD_CHAR *Table, const HD_CHAR *ColName);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSqlColumnRename(VG_DBINFO *Dbh, const HD_CHAR *Table, const HD_CHAR *OldName, const HD_CHAR *NewName);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSqlMolListReadEx(VG_DBINFO *Dbh, HD_CHAR *Sql);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSqlPut(VG_CTX *Ctx, VG_DBINFO *Dbh, HD_STRING Name, HD_UDLONG *Offset, HD_LONG Flags);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbSqlRen(VG_DBINFO *Dbh, VG_DBMOLLIST *Itm, HD_CHAR *NewName);

VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbZipCreate(VG_DBINFO *Dbh);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbZipPut(VG_CTX *Ctx, VG_DBINFO *Dbh, HD_STRING MolName);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT  VG_DbZipRemove(VG_DBINFO *Dbh, VG_DBMOLLIST *Itm);

VEGA_EXTERN HD_LIST *           VEGA_EXPORT  VG_SqlTableInfo(VG_DBINFO *Dbh, const HD_CHAR *Table);
VEGA_EXTERN HD_VOID             VEGA_EXPORT  VG_SqlTableInfoFree(HD_LIST *ColList);
VEGA_EXTERN HD_BOOL             VEGA_EXPORTA VG_SqlUpdateRow(VG_DBINFO *Dbh, const HD_CHAR *Table, HD_UDLONG Id, ...);

VEGA_EXTERN HD_STRING         VEGA_EXPORT  VG_StrFixSqlQuotes(HD_STRING Str);
VEGA_EXTERN HD_STRING         VEGA_EXPORT  VG_StrFixSqlQuotesC(const HD_CHAR *Str);

#  ifdef __cplusplus
}
#  endif
#endif

