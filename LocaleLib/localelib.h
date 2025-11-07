
/*************************************************
****            Locale library V2.0           ****
****               Public header              ****
**** Copyright 2000-2025, Alessandro Pedretti ****
**************************************************/

/*
 * Define LOCALE_DLL to use and compile LOCALE.DLL
 * for Win32.
 */

#ifndef __LOCALE_HDR
#define  __LOCALE_HDR

#include <stdio.h>

/**** Boolean constants ****/

#ifndef FALSE
#  define  FALSE    0
#endif
#ifndef TRUE
#  define  TRUE     1
#endif

#define  LOCALE_DIR   "Catalogs"

/**** Windows specific definitions ****/

#if defined(_WINDOWS) || defined(WINDOWS) || defined(_WIN32) || defined(_WIN32_)
#  ifndef WIN32
#    define WIN32
#  endif

#  ifndef LITTLE_ENDIAN
#    define  LITTLE_ENDIAN
#  endif

#  ifdef LOCALE_DLL
#    include <windows.h>
#    if defined(__MINGW32__) || defined(_MSC_VER)
#      define  LOCEXPORT(func)     func
#      define  LOCEXTERN           __declspec(dllexport)
#    else
#      define  LOCEXPORT(func)     __declspec(dllexport) WINAPI (func)
#    endif
#  endif
#  ifdef LOCALE_DYNDLL
#    define LOCEXPORT(func)     (WINAPI * func)
#    define LOCEXTERN           extern
#  endif

/**** Windows CE ****/

#  ifdef _WIN32_WCE
#    define  strcasecmp         _stricmp
#    define  strncasecmp        _strnicmp
#  else
#    ifndef strcasecmp
#      define  strcasecmp       strcmpi
#    endif
#    ifndef strncasecmp
#      define  strncasecmp      strnicmp
#    endif
#  endif

#  ifndef C_DIRSEP
#    define  C_DIRSEP     "\\"
#  endif

/**** Other operating systems ****/

#else
#  ifndef C_DIRSEP
#    define  C_DIRSEP     "/"
#  endif
#endif

#ifndef LOCEXTERN
#define  LOCEXTERN        extern
#endif

#ifndef LOCEXPORT
#  define  LOCEXPORT
#endif


/**** Error codes ****/

#define  LOCERR_NONE          0         /* No errors                                  */
#define  LOCERR_DOS           1         /* Dos error                                  */
#define  LOCERR_CORRUPT       2         /* Corrupted catalog file                     */
#define  LOCERR_VERSION       3         /* Catalog version incompatible               */
#define  LOCERR_MEMORY        4         /* Not enough memory                          */
#define  LOCERR_ANOTHERAPP    5         /* Catalog of another application             */
#define  LOCERR_LANGUAGE      6         /* Catalog in another language                */
#define  LOCERR_AUTONOTSUP    7         /* Automatic language selection not supported */
#define  LOCERR_AUTOWIN       8         /* Error detecting the system language        */
#define  LOCERR_NOTFOUND      9         /* Catalog file not found                     */
#define  LOCERR_LANGSTR      10         /* Laguage string not found                   */

/**** Internal language IDs ****/

#define  LOC_LID_CATALAN        0
#define  LOC_LID_CROATIAN       1
#define  LOC_LID_CZECH          2
#define  LOC_LID_DANISH         3
#define  LOC_LID_DUTCH          4
#define  LOC_LID_ENGLISH        5
#define  LOC_LID_ESTONIAN       6
#define  LOC_LID_FINNISH        7
#define  LOC_LID_FRENCH         8
#define  LOC_LID_GERMAN         9
#define  LOC_LID_GREEK         10
#define  LOC_LID_HUNGARIAN     11
#define  LOC_LID_ICELANDIC     12
#define  LOC_LID_ITALIAN       13
#define  LOC_LID_JAPANESE      14
#define  LOC_LID_NORWEGIAN     15
#define  LOC_LID_POLISH        16
#define  LOC_LID_PORTUGUESE    17
#define  LOC_LID_RUSSIAN       18
#define  LOC_LID_SERBIAN       19
#define  LOC_LID_SLOVAK        20
#define  LOC_LID_SLOVENIAN     21
#define  LOC_LID_SPANISH       22
#define  LOC_LID_SWEDISH       23
#define  LOC_LID_TURKISH       24

/**** Structure required by LocAmigaVer() command ****/

typedef struct {
  unsigned int  Ver, Rel;
  char          Name[32];
  char          Date[14];
} AMIGAVER;


/**** Function macros for compatibility ****/

#define  Dos2Iso(STR)           LocIso2Dos((STR), 1)
#define  Iso2Dos(STR)           LocIso2Dos((STR), 0)
#define  StrCpyDos              LocStrCpy


/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

LOCEXTERN void          LOCEXPORT(LocAmigaVer)(char *, AMIGAVER *);
/*
 * void LocAmigaVer(char *Ptr, AMIGAVER *Ver)
 *
 * It returns the name, the date, the version and the release of an AmigaDOS file,
 * loaded in memory at the Ptr location.
 * These informations are returned in Ver structure pointer.
 */

LOCEXTERN int           LOCEXPORT(LocCreateFastIndex)(void *);
/*
 * int LocCreateFastIndex(void *LocInfo)
 *
 * Create and use the fast index. This is useful for very large catalogs. If
 * the function fails, FALSE is returned.
 */

LOCEXTERN void          LOCEXPORT(LocCloseCat)(void *);
/*
 * void LocCloseCat(void *Cat)
 *
 * It closes a catalog, deallocanting the memory and the resources. Cat is the catalog
 * pointer.
 */

LOCEXTERN int           LOCEXPORT(LocDosPrintf)(FILE *, const char *, ...);
/*
 * int LocDosPrintf(FILE *FH, const char *AnsiStr, ...)
 *
 * This function replaces the standard fprintf and adds the capability to change
 * the character set from ANSI/ISO into Ms-Dos. It returns the number of
 * charaters printed out, or -1 if an error occurs.
 */

LOCEXTERN void          LOCEXPORT(LocIso2Dos)(char *, short);
/*
 * void LocIso2Dos(char *Str, short Back)
 *
 * It converts the string Str from ANSI/ISO into Ms-Dos (Back = FALSE) format, or
 * from Ms-Dos into ANSI/ISO (Back = TRUE).
 */

LOCEXTERN const char *  LOCEXPORT(LocGetCatStr)(void *, unsigned int, const char *);
/*
 * const char * LocGetCatStr(void *Cat, unsigned int StrID, const char *BuiltIn)
 *
 * It translates a string indicating the catalog (Cat pointer, opened with
 * LocOpenCat()), the string identification number (StrID) and the string array
 * BuiltIn that contains all strings in built-in language.
 * The returned value is the pointer to the translated string.
 */

LOCEXTERN int           LOCEXPORT(LocGetErr)(void);
/*
 * int LocGetErr(void)
 *
 * This function returns the error code if a function of locale library fails. If
 * no error, it returns LOCERR_NONE (0). See the error codes section.
 */

LOCEXTERN void          LOCEXPORT(LocGetErrStr)(char *, int);
/*
 * void LocGetErrStr(char *Buffer, int Size)
 *
 * It returns the complete error message in the Buffer string with Size
 * dimension.
 */

LOCEXTERN int           LOCEXPORT(LocGetLangID)(const char *);
/*
 * int LocGetLangID(const char *LangStr)
 *
 * Return the internal language ID by submitting its string. If it fails,
 * -1 is returned.
 */

LOCEXTERN const char *  LOCEXPORT(LocGetLangStrByID)(int);
/*
 * const char * LocGetLangStrByID(int LangID)
 *
 * Return the language string by internal language ID. If it fails,
 * "unknown" is returned.
 */

LOCEXTERN void  *       LOCEXPORT(LocOpenCat)(const char *, const char *, const char *, unsigned int, const char *);
/*
 * void *LocOpenCat(const char *CatName, const char *CatDir, const char *Lang, unsigned int Ver, const char *BuiltIn)
 *
 * This function opens and loads into the memory the catalog file with CatName
 * name, placed in CatDir directory, with Lang language and with Ver version.
 * If Lang is "auto", the automatic detection of the system language is enabled.
 * This function isn't available with all operating systems. If isn't possible,
 * the LOCERR_AUTONOTSUP error code is reported.
 * BuiltIn is the name of the built-in language (e.g. "english").
 * It returns the memory pointer to manage the catalog.
 */

LOCEXTERN void          LOCEXPORT(LocStrCpy)(char *, const char *);
/*
 * void LocStrCpy(char *Dest, const char *Src)
 *
 * strcpy() replacement with ANSI/ISO into Ms-Dos charater set conversion.
 */


/**** Specific Win32 functions ****/

#  ifdef WIN32
LOCEXTERN const char  * LOCEXPORT(LocGetLangStr)(void);
/*
 * const char *LocGetLangStr(void)
 *
 * Return the string pointer of the current system language. See the include
 * tables.h.
 */
#  endif

#  ifdef __cplusplus
   }
#  endif
#endif
