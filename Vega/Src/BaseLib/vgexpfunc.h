
/*************************************************
****  VEGA - Exported functions for plug-ins  ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_EXPFUNC_H
#  define  __VG_EXPFUNC_H

#  ifdef WIN32
#    define  VG_EXPORT                  WINAPI
#    define  VG_EXTERN                  __declspec(dllexport)
#  else
#    define  VG_EXPORT
#    define  VG_EXTERN
#  endif

/**** VG_LoadFromMem() flags ****/

#  define  VG_LOADMEM_NONE              0
#  define  VG_LOADMEM_SILENT            1

/**** GL_PickWinActivate() pick flags ****/

#  define  VG_PICKFLG_NONE              0
#  define  VG_PICKFLG_ATOM              1
#  define  VG_PICKFLG_BOND              2
#  define  VG_PICKFLG_HIGHLIGHT         4

/**** GL_PickEx() picked object ****/

#  define  VG_PICKOBJ_NONE              0
#  define  VG_PICKOBJ_ATOM              1
#  define  VG_PICKOBJ_BOND              2

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_DbrdDefault                     _VG_DbrdDefault
#    define  VG_DbSqlGetRawMol                  _VG_DbSqlGetRawMol
#    define  VG_LoadFromMem                     _VG_LoadFromMem
#    define  GL_PickWinActivate                 _GL_PickWinActivate
#    define  GL_PickWinRemove                   _GL_PickWinRemove
#  endif

/**** Types ****/

#  ifdef WIN32
typedef HD_BYTE *       (VEGA_EXPORT *VGF_DBGETRAWMOL)(HD_ULONG, HD_UDLONG, HD_ULONG *);
typedef HD_BOOL         (VEGA_EXPORT *VGF_LOADFROMMEM)(HD_VOID *, HD_ULONG, HD_LONG);
#  endif

#  ifdef VCL_H
typedef HD_VOID         (VEGA_EXPORT *VGF_GLPICKWINACTIVATE)(TForm *Form, HD_VOID (*Call)(struct _VG_GL_PREFS *, HD_ATOM **, HD_LONG), HD_LONG Flags);
typedef HD_VOID         (VEGA_EXPORT *VGF_GLPICKWINREMOVE)(TForm *Form);
#  endif

/**** Exported functions ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_BYTE *     VEGA_EXPORT VG_DbSqlGetRawMol(HD_ULONG DbHandle, HD_UDLONG RowID, HD_ULONG *Len);
VEGA_EXTERN HD_BOOL       VEGA_EXPORT VG_LoadFromMem(VG_CTX *Ctx, HD_VOID *MemPtr, HD_ULONG Size, HD_LONG Flags);

#  ifdef VCL_H
VEGA_EXTERN HD_VOID       VEGA_EXPORT GL_PickWinActivate(TForm *Form, HD_VOID (*Call)(struct _VG_GL_PREFS *, HD_ATOM **, HD_LONG), HD_LONG Flags);
VEGA_EXTERN HD_VOID       VEGA_EXPORT GL_PickWinRemove(TForm *Form);
#  endif

#  ifdef __cplusplus
}
#  endif
#endif

