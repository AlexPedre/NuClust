
/*************************************************
****    VEGA - Hyperdrive string utilities    ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_HDSTRUTILS_H
#  define  __VG_HDSTRUTILS_H

#  include <hdstring.h>

/**** FindFuncGroups() flags ****/

#  define  VG_FINDFUNCGRP_NONE          0
#  define  VG_FINDFUNCGRP_ACTIVEONLY    1
#  define  VG_FINDFUNCGRP_SAVEPOT       2

/**** VG_StrGetPrgPath() flags ****/

#  define  VG_PATH_PRGDATADIR           0x100

#  define  VG_PATH_PRGDATA              (0 | VG_PATH_PRGDATADIR)
#  define  VG_PATH_PRG                  1
#  define  VG_PATH_DATA                 (2 | VG_PATH_PRGDATADIR)
#  define  VG_PATH_CLUSTERS             (3 | VG_PATH_PRGDATADIR)
#  define  VG_PATH_COMBIFRAGS           (4 | VG_PATH_PRGDATADIR)
#  define  VG_PATH_CONFIG               (5 | VG_PATH_PRGDATADIR)
#  define  VG_PATH_DEMO                 6
#  define  VG_PATH_EXE32                7
#  define  VG_PATH_EXE64                8
#  define  VG_PATH_JAVA                 9
#  define  VG_PATH_LAYOUTS              (10 | VG_PATH_PRGDATADIR)
#  define  VG_PATH_NAMD                 11
#  define  VG_PATH_ROTAMERS             (12 | VG_PATH_PRGDATADIR)
#  define  VG_PATH_SCRIPTS              (13 | VG_PATH_PRGDATADIR)
#  define  VG_PATH_SHADERS              14
#  define  VG_PATH_SKYBOXES             15
#  define  VG_PATH_SOUNDS               16
#  define  VG_PATH_UPDATE               (17 | VG_PATH_PRGDATADIR)

#  define  VG_PATH_RELEASECACHE         18

#  ifdef WIN32
#    ifdef WIN64
#      define  VG_PATH_EXEDEF           VG_PATH_EXE64
#    else
#      define  VG_PATH_EXEDEF           VG_PATH_EXE32
#    endif
#  endif

#  ifdef linux
#    ifdef __x86_64__
#      define  VG_PATH_EXEDEF           VG_PATH_EXE64
#    else
#      define  VG_PATH_EXEDEF           VG_PATH_EXE32
#    endif
#  endif

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_FindFuncGrp                     _VG_FindFuncGrp
#    define  VG_StrGetJavaDir                   _VG_StrGetJavaDir
#    define  VG_StrGetPrgPath                   _VG_StrGetPrgPath
#    define  VG_StrGetUserName                  _VG_StrGetUserName
#    define  VG_StrIso2Dos                      _VG_StrIso2Dos
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_STRING  VEGA_EXPORT VG_FindFuncGrp(VG_CTX *Ctx, HD_LONG Flags);
VEGA_EXTERN HD_STRING  VEGA_EXPORT VG_StrGetJavaDir(HD_STRING Path);
VEGA_EXTERN HD_STRING  VEGA_EXPORT VG_StrGetPrgPath(HD_STRING Str, HD_LONG What);
VEGA_EXTERN HD_STRING  VEGA_EXPORT VG_StrGetUserName(HD_STRING UserName);
VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_StrIso2Dos(HD_CHAR *Str);

#  ifdef __cplusplus
}
#  endif

#  ifdef __cplusplus
inline HD_VOID         VG_StrGetPrgPath(HDC_String &Str, HD_LONG What) { VG_StrGetPrgPath(Str.Hdstr(), What); }
#  endif
#endif

