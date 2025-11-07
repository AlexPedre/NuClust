
/*************************************************
****            Locale library V1.2           ****
****       Language localization library      ****
**** Copyright 2000-2025, Alessandro Pedretti ****
**************************************************/

/*
  The following routines use the AmigaOS Locale Technology to translate the
  strings in any language using a specific catalog file in standard IFF format.
  Each locale file must be stored in a sub-directory with the lower-case language
  name of the Locale directory.
  The AmigaOS Locale Technology is copyrighted by Amiga Inc.
*/


#ifdef WIN32
#  include <windows.h>
#endif

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <malloc.h>
#include <errno.h>

#ifdef __BORLANDC__
#  pragma hdrstop
#endif

#include "iff.h"
#include "localelib.h"
#include "tables.h"

#ifdef __GNUC__
#  define  LOC_INLINE               __inline__
#else
#  define  LOC_INLINE               static __inline
#endif

/**** Definitions ****/

typedef struct {
  char *                Begin;          /* Data starting pointer */
  char *                CatEnd;         /* Catalog end           */
  char **               FastIndex;      /* Fast index            */
  unsigned int          HiIndex;        /* Upper index           */
  unsigned int          LowIndex;       /* Lower index           */
  unsigned int          Size;           /* Data size             */
} LOC_INFO;

/**** Global variables ****/

static int              LocGlobalErr;

/**** Local variables ****/

static int              LocMinVer;
static const char *     StrUnk = "unknown";

/**** Local prototypes ****/

static FILE *   OpenIff(char *, unsigned int);
static int      ReadIffHdr(FILE *, IFFHDR *, unsigned int);
static void     SafeFree(void *Mem);

#ifdef LITTLE_ENDIAN
LOC_INLINE void Swap(void *);
#endif


/**** Decode a standard AmigaOS version string ****/

LOCEXTERN void LOCEXPORT(LocAmigaVer)(register char *Str, AMIGAVER *Ver)
{
  *Ver -> Name = 0;
  *Ver -> Date = 0;
  Ver -> Ver   = 0;
  Ver -> Rel   = 0;

  if (!strncmp(Str, "$VER", 4)) {
    Str += 5;
    while((*Str) && (*Str == ' ')) ++Str;
    sscanf(Str, "%31s %d.%d (%13s ", Ver -> Name, &Ver -> Ver,
           &Ver -> Rel, Ver -> Date);
    Ver -> Date[strlen(Ver -> Date) - 1] = 0;
  }
}


/**** Close the catalog ****/

LOCEXTERN void LOCEXPORT(LocCloseCat)(void *LocInfo)
{
  if (LocInfo) {
    SafeFree(((LOC_INFO *)LocInfo) -> Begin    );
    SafeFree(((LOC_INFO *)LocInfo) -> FastIndex);
    free(LocInfo);
  }
  LocGlobalErr = LOCERR_NONE;
}


/**** Create & use the fast index ****/

LOCEXTERN int LOCEXPORT(LocCreateFastIndex)(void *LocInfo)
{
  char                 **Idx, *Ptr;
  unsigned int         Hi, Id, Len, Low;

  char *               CatEnd = ((LOC_INFO *)LocInfo) -> CatEnd;

  Ptr = ((LOC_INFO *)LocInfo) -> Begin;
  Hi  = *(unsigned int *)Ptr;
  Low = Hi;

  while(Ptr != CatEnd) {
    Id = *(unsigned int *)Ptr;
    if (Id > Hi ) Hi  = Id;
    if (Id < Low) Low = Id;
    Len = *(unsigned int *)(Ptr + 4);
    if (Len & 3) Len += 4 - (Len & 3);
    Ptr = Ptr + Len + 8;
  } /* End of while */

  if ((Idx = (char **)calloc(Hi - Low + 1, sizeof(char *))) == NULL) {
    LocGlobalErr = LOCERR_MEMORY;
    return FALSE;
  }

  /**** Create the index ****/

  Ptr = ((LOC_INFO *)LocInfo) -> Begin;
  while(Ptr != CatEnd) {
    Idx[*(unsigned int *)Ptr - Low] = Ptr + 8;

    Len = *(unsigned int *)(Ptr + 4);
    if (Len & 3) Len += 4 - (Len & 3);
    Ptr = Ptr + Len + 8;
  } /* End of while */

  ((LOC_INFO *)LocInfo) -> HiIndex   = Hi;
  ((LOC_INFO *)LocInfo) -> LowIndex  = Low;
  ((LOC_INFO *)LocInfo) -> FastIndex = Idx;
  LocGlobalErr                       = LOCERR_NONE;

  return TRUE;
}


/**** fprintf replacement with iso2dos character conversion ****/

LOCEXTERN int LOCEXPORT(LocDosPrintf)(FILE *FH, const char *Str, ...)
{
  char          Buf[1024];
  va_list       vl;
  int           Ret;

  va_start(vl, Str);
  vsprintf(Buf, Str, vl);
  LocGlobalErr = LOCERR_NONE;
  LocIso2Dos(Buf, FALSE);
  Ret = fprintf(FH, "%s", Buf);
  va_end(vl);

  return Ret;
}


/**** Convert the ISO-Latin-1 character set into MS-DOS format ****/

LOCEXTERN void LOCEXPORT(LocIso2Dos)(register char *Str, short Back)
{
  register KNOWN_PAIRS     *Pair;

  while(*Str) {
    if ((unsigned char)*Str > (unsigned char)127) {
      for(Pair = KnownPairs; Pair -> Dos; ++Pair) {
        if (Back) {
          if (*Str == Pair -> Dos) {
            *Str = Pair -> Iso;
            break;
          }
        } else {
          if (*Str == Pair -> Iso) {
            *Str = Pair -> Dos;
            break;
          }
       }
      } /* End of pair loop */
    }
    ++Str;
  } /* End of string loop */

  LocGlobalErr = LOCERR_NONE;
}


/**** Translate a catalog string                 ****/
/**** compatible with AmigaOS GetCatalogString() ****/

LOCEXTERN const char * LOCEXPORT(LocGetCatStr)(void *LocInfo, register unsigned int Id, const char *BuiltIn)
{
  register char *               CatEnd;
  register char *               Ptr;
  register unsigned int         Len;

  if (((LOC_INFO *)LocInfo) -> FastIndex) {
    if ((Id <= ((LOC_INFO *)LocInfo) -> HiIndex) &&
        (Id >= ((LOC_INFO *)LocInfo) -> LowIndex))
      BuiltIn = ((LOC_INFO *)LocInfo) -> FastIndex[Id - ((LOC_INFO *)LocInfo) -> LowIndex];
  } else {
    CatEnd = ((LOC_INFO *)LocInfo) -> CatEnd;
    Ptr    = ((LOC_INFO *)LocInfo) -> Begin;
    while(Ptr != CatEnd) {
      if (Id == *(unsigned int *)Ptr) {
        BuiltIn = Ptr + 8;
        break;
      }
      Len = *(unsigned int *)(Ptr + 4);
      if (Len & 3) Len += 4 - (Len & 3);
      Ptr = Ptr + Len + 8;
    }
  } /* Ene of while */

  LocGlobalErr = LOCERR_NONE;

  return BuiltIn;
}


/****       Open a catalog file      ****/
/**** (only for non-AmigaOS systems) ****/

LOCEXTERN void * LOCEXPORT(LocOpenCat)(const char *CatalogName, const char *Path, const char *Language,
                                       unsigned int MinVer, const char *BuiltIn)
{
  AMIGAVER              Ver;
  char                  CatalogPath[512];
  FILE *                FH;
  IFFHDR                Hdr;

#ifdef LITTLE_ENDIAN
  char *                Ptr;
  unsigned int          Len;
#endif

  LOC_INFO *     LocInfo = NULL;
  short          Ret      = TRUE;
  unsigned short Chk      = 0;

  if (strcasecmp(Language, BuiltIn)) {

    /**** Set the path and file name ****/

    strcpy(CatalogPath, Path);
#ifdef WIN32
    if (Path[strlen(Path) - 1] != '\\')
#else
    if (Path[strlen(Path) - 1] != '/')
#endif
      strcat(CatalogPath, C_DIRSEP);
    strcat(CatalogPath, LOCALE_DIR C_DIRSEP);
/*
    MessageBox(NULL, CatalogPath, "Locale", MB_OK);
*/
    if (!strcmp(Language, "auto")) {
#ifdef WIN32
      if ((Language = LocGetLangStr()) == NULL) {
        LocGlobalErr = LOCERR_AUTOWIN;
        return NULL;
      }
#else
      LocGlobalErr = LOCERR_AUTONOTSUP;
      return NULL;
#endif
    }
    strcat(CatalogPath, Language);
    strcat(CatalogPath, C_DIRSEP);
    strcat(CatalogPath, CatalogName);

    /**** Read the IFF file ****/

    if ((FH = OpenIff(CatalogPath, IFF_CTLG)) != NULL) {
      while((Ret) && (ReadIffHdr(FH, &Hdr, 0))) {
        switch(Hdr.ID) {

          case IFF_CTLG_FVER:  /* Version chunk */
            if ((Hdr.Size <= sizeof(CatalogPath)) &&
                (fread(CatalogPath, Hdr.Size, 1, FH) == 1)) {
              LocAmigaVer(CatalogPath, &Ver);
              if (!strcasecmp(CatalogName, Ver.Name)) {
                if (Ver.Ver < MinVer) {
                  LocGlobalErr = LOCERR_VERSION;
                  LocMinVer    = MinVer;
                  Ret          = FALSE;
                } else ++Chk;
              } else {
                LocGlobalErr = LOCERR_ANOTHERAPP;
                Ret = FALSE;
              }
            } else {
              LocGlobalErr = LOCERR_CORRUPT;
              Ret          = FALSE;
            }
            break;

          case IFF_CTLG_LANG:  /* Language chunk */
            if ((Hdr.Size <= sizeof(CatalogPath)) &&
                (fread(CatalogPath, Hdr.Size, 1, FH) == 1)) {
              if (strcasecmp(CatalogPath, Language)) {
                LocGlobalErr = LOCERR_LANGUAGE;
                Ret          = FALSE;
              } else ++Chk;
            } else {
              LocGlobalErr = LOCERR_CORRUPT;
              Ret          = FALSE;
            }
            break;

          case IFF_CTLG_STRS:  /* String chunk */
            if (((LocInfo = (LOC_INFO *)malloc(sizeof(LOC_INFO))) != NULL) &&
                ((LocInfo -> Begin = (char *)malloc(Hdr.Size)) != NULL)) {
              LocInfo -> FastIndex = NULL;
              LocInfo -> LowIndex  = 0;
              LocInfo -> HiIndex   = 0;
              if (fread(LocInfo -> Begin, Hdr.Size, 1, FH) == 1) {
                LocInfo -> Size   = Hdr.Size;
                LocInfo -> CatEnd = LocInfo -> Begin + LocInfo -> Size;

                /**** Set the endian (if needed) ****/

#ifdef LITTLE_ENDIAN
                Ptr = LocInfo -> Begin;
                while(Ptr != LocInfo -> CatEnd) {
                  Swap(Ptr);
                  Swap(Ptr + 4);
                  Len = *(unsigned int *)(Ptr + 4);
                  if (Len & 3) Len += 4 - (Len & 3);
                  Ptr += 8 + Len;
                } /* End of while */
#endif
                ++Chk;
              } else {
                LocGlobalErr = LOCERR_CORRUPT;
                Ret          = FALSE;
                free(LocInfo -> Begin);
                free(LocInfo);
                LocInfo = NULL;
              }
            } else LocGlobalErr = LOCERR_MEMORY;
            break;

          default:            /* Skip the unknown chunk */
            fseek(FH, Hdr.Size, SEEK_CUR);
        } /* End of switch */
      }
      if ((Chk != 3) && (LocInfo)) {
        free(LocInfo -> Begin);
        free(LocInfo);
        LocInfo = NULL;
      }
      fclose(FH);
    } else LocGlobalErr = LOCERR_NOTFOUND;
  } else LocGlobalErr = LOCERR_NONE;

  return (void *)LocInfo;
}


/**** Copy a string ISO-Latin-1 into another MS-DOS string ****/

LOCEXTERN void LOCEXPORT(LocStrCpy)(register char *Dest, register const char *Src)
{
  register KNOWN_PAIRS     *Pair;

  while(*Src) {
    if ((unsigned char)*Src > (unsigned char)127) {
      for(Pair = KnownPairs; Pair -> Dos; ++Pair) {
        if (*Src == Pair -> Iso) {
          *Dest = Pair -> Dos;
          break;
        }
      } /* End of pair loop */
      if (!Pair -> Dos) *Dest = *Src;
    } else *Dest = *Src;
    ++Src;
    ++Dest;
  } /* End of string loop */
  *Dest = 0;

  LocGlobalErr = LOCERR_NONE;
}


/**** Open an IFF file for read ****/
/**** and eventually check it   ****/

FILE *OpenIff(char *Name, unsigned int Comp)
{
  FILE           *FH;
  IFFHDR         Hdr;

  LocGlobalErr = LOCERR_NONE;

  if ((FH = fopen(Name, "rb")) != NULL) {
    if (ReadIffHdr(FH, &Hdr, IFF_FORM)) {
      if (fread(&Hdr, sizeof(unsigned int), 1, FH) == 1) {

#ifdef LITTLE_ENDIAN
        Swap(&Hdr.ID);
#endif

        if (Comp != Hdr.ID) {
          LocGlobalErr = LOCERR_CORRUPT;
          fclose(FH);
          FH = NULL;
        }
      } else {
        LocGlobalErr = LOCERR_DOS;
        fclose(FH);
        FH = NULL;
      }
    }
  }

  return FH;
}


/**** Get the internal language ID ****/

LOCEXTERN int LOCEXPORT(LocGetLangID)(const char *LangStr)
{
  register int  k;

  if ((LangStr) && (*LangStr)) {
    LocGlobalErr = LOCERR_NONE;
    for(k = 0; LangTab[k].ID; ++k)
     if (!strcasecmp(LangTab[k].LangStr, LangStr)) return k;
  }

  LocGlobalErr = LOCERR_LANGSTR;

  return -1;
}


/************************************
**** Specific Win32 soubroutines ****
************************************/


/**** Get the default system language ****/

#ifdef WIN32
LOCEXTERN const char * LOCEXPORT(LocGetLangStr)(void)
{
  LANGID                Lang;
  register LANGTAB *    k;

  if ((Lang = (LANGID)(GetSystemDefaultLangID() & 0x3ff)) != 0) {
    for(k = (LANGTAB *)LangTab; (k -> ID) && (k -> ID != Lang); ++k);
    if (k) {
      LocGlobalErr = LOCERR_NONE;
      return k -> LangStr;
    }
  }
  LocGlobalErr = LOCERR_LANGSTR;

  return NULL;
}
#endif


/**** Get the language string by internal ID ****/

LOCEXTERN const char * LOCEXPORT(LocGetLangStrByID)(int LangID)
{
  if ((LangID < 0) || (LangID >= (int)(sizeof(LangTab) / sizeof(LANGTAB)))) {
    LocGlobalErr = LOCERR_LANGSTR;
    return StrUnk;
  }

  LocGlobalErr = LOCERR_NONE;
  return LangTab[LangID].LangStr;
}


/**** Read an IFF header and eventually check it with ****/
/**** the Comp value                                  ****/

static int ReadIffHdr(FILE *FH, IFFHDR *Hdr, unsigned int Comp)
{
  /**** Strip the padding byte ****/

  if (!feof(FH)) {
    if (ftell(FH) & 1) fgetc(FH);
    if (fread(Hdr, sizeof(IFFHDR), 1, FH) == 1) {

#ifdef LITTLE_ENDIAN
      Swap(&Hdr -> ID);
      Swap(&Hdr -> Size);
#endif
      if ((!Comp) || (Comp == Hdr -> ID)) return TRUE;
    }
  }

  return FALSE;
}

/**** Change the endian ****/

#ifdef LITTLE_ENDIAN
LOC_INLINE void Swap(register void *Val)
{
  register char    T;

  T                = ((char *)Val)[0];
  ((char *)Val)[0] = ((char *)Val)[3];
  ((char *)Val)[3] = T;
  T                = ((char *)Val)[1];
  ((char *)Val)[1] = ((char *)Val)[2];
  ((char *)Val)[2] = T;
}
#endif


/**** Get the error code ****/

LOCEXTERN int LOCEXPORT(LocGetErr)(void)
{
  return LocGlobalErr;
}


/**** Get the error message ****/

LOCEXTERN void LOCEXPORT(LocGetErrStr)(char *Buf, int Size)
{
  char          *Str, MyBuf[256];

  Str = MyBuf;
  --Size;

  switch(LocGlobalErr) {
  case LOCERR_NONE:
    Str = "None";
    break;

  case LOCERR_DOS:
    Str = strerror(errno);
    break;

  case LOCERR_CORRUPT:
    Str = "Corrupted catalog file";
    break;

  case LOCERR_VERSION:
    sprintf(MyBuf, "The catalog version %d.0 or better is required", LocMinVer);
    break;

  case LOCERR_MEMORY:
    Str = "Out of memory";
    break;

  case LOCERR_ANOTHERAPP:
    Str = "Catalog of another application";
    break;

  case LOCERR_LANGUAGE:
    Str = "The catalog has a wrong language";
    break;

  case LOCERR_AUTONOTSUP:
    Str = "The automatic language detection isn't supported";
    break;

  case LOCERR_AUTOWIN:
    Str = "Can't detect the default language";
    break;

  case LOCERR_NOTFOUND:
    Str = "Catalog file not found";
    break;

  default:
    Str = "Unknown";
  }
  strncpy(Buf, Str, Size);
}


/**** Safe free ****/

static void SafeFree(void *Mem)
{
  if (Mem) free(Mem);
}

