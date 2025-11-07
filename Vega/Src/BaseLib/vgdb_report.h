
/*************************************************
****         VEGA - Database reports          ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_DBRD_H
#  define  __VG_DBRD_H

#  include <hdstring.h>

/**** Report description flags ****/

#  define  VG_DBRDF_NONE                0

/**** Report description ****/

struct __vg_dbrd {
  HD_CHAR               DecimalSep;             /* Decimal separator          */
  HD_STRING             Author;                 /* Author name                */
  HD_STRING             Description;            /* Description                */
  HD_STRING             FileName;               /* Report file name           */
  HD_STRING             FileReqDefExt;          /* File requester default ext */
  HD_STRING             FileReqFilter;          /* File requester title       */
  HD_STRING             FileReqTitle;           /* File requester title       */
  HD_STRING             Title;                  /* Report name                */
  HD_STRING             Version;                /* Report version             */
  HD_STRING             OutFileName;            /* Output file name           */
  HD_LONG               Flags;                  /* Flags                      */
};

typedef struct __vg_dbrd *      VG_DBRD;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_DbrdDefault                     _VG_DbrdDefault
#    define  VG_DbrdFree                        _VG_DbrdFree
#    define  VG_DbrdGetDir                      _VG_DbrdGetDir
#    define  VG_DbrdLoad                        _VG_DbrdLoad
#    define  VG_DbrdNew                         _VG_DbrdNew
#    define  VG_DbrSave                         _VG_DbrSave
#    define  VG_DbrSaveAsync                    _VG_DbrSaveAsync
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_DbrdDefault(VG_DBRD Dbrd);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_DbrdFree(VG_DBRD Dbrd);
VEGA_EXTERN HD_STRING       VEGA_EXPORT VG_DbrdGetDir(HD_STRING Path);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_DbrdLoad(VG_DBRD *Dbrd, HD_CHAR *FileName);
VEGA_EXTERN VG_DBRD         VEGA_EXPORT VG_DbrdNew(HD_VOID);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_DbrSave(VG_DBRD Dbrd, VG_DBINFO *hDb);

#    ifdef VEGA_ZZ
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_DbrSaveAsync(VG_DBRD Dbrd, VG_DBINFO *hDb, HD_VOID (VEGA_EXPORT *CallBack)(HD_VOID *), HD_VOID *CallBackArg);
#    endif

#  ifdef __cplusplus
}
#  endif
#endif
