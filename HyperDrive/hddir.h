
/*******************************************
****   HyperDrive - directory routines  ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#ifndef __HDDIR_H
#  define  __HDDIR_H

#  include <hdfile.h>
#  include <hdstring.h>
#  include <hdtime.h>

/**** File attributes ****/

#  define  HD_FILEATTR_ALL              0xffffffff
#  define  HD_FILEATTR_NONE             0
#  define  HD_FILEATTR_DIRECTORY        1
#  define  HD_FILEATTR_EXEC             2
#  define  HD_FILEATTR_FILE             4
#  define  HD_FILEATTR_HIDDEN           8
#  define  HD_FILEATTR_READ            16
#  define  HD_FILEATTR_WRITE           32

/**** Directory structure ****/

struct __hd_dir {
  HD_STRING             FileName;       /* Current file/directory name        */
  HD_STRING             Path;           /* Path of the directory              */
  HD_VOID *             Handle;         /* Handle of the directory            */
  HD_LONG               Attributes;     /* File attributes                    */
  HD_UDLONG             FileSize;       /* File size                          */
  HD_ULONG              FileNum;        /* File number                        */
  HD_TIME               TimeAcc;        /* Last access time                   */
  HD_TIME               TimeChg;        /* Last change time                   */
  HD_TIME               TimeMod;        /* Last modification time             */

  /**** Private data ****/

  HD_ARGS               hPatt;          /* Pattern handle                     */
  HD_LONG               PattNum;        /* Number of patterns                 */

#ifdef HD_USE_DIRENT
  struct dirent *       Ent;            /* ANSI find data                     */
#else
  WIN32_FIND_DATA       FindData;       /* Windows find data                  */
  HD_BOOL               SkipFirst;      /* Skip the first file                */
#endif
};

typedef struct __hd_dir *       HD_DIR;

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_DirClose                _HD_DirClose
#    define  HD_DirCreate               _HD_DirCreate
#    define  HD_DirCreateC              _HD_DirCreateC
#    define  HD_DirCurrent              _HD_DirCurrent
#    define  HD_DirExist                _HD_DirExist
#    define  HD_DirExistC               _HD_DirExistC
#    define  HD_DirFixSep               _HD_DirFixSep
#    define  HD_DirGetCurrent           _HD_DirGetCurrent
#    define  HD_DirLoadC                _HD_DirLoadC
#    define  HD_DirLoad                 _HD_DirLoad
#    define  HD_DirNextFile             _HD_DirNextFile
#    define  HD_DirOpen                 _HD_DirOpen
#    define  HD_DirOpenC                _HD_DirOpenC
#    define  HD_DirPrg                  _HD_DirPrg
#    define  HD_DirRemove               _HD_DirRemove
#    define  HD_DirRemoveC              _HD_DirRemoveC
#    define  HD_DirSetCurrent           _HD_DirSetCurrent
#    define  HD_DirSetCurrentC          _HD_DirSetCurrentC
#    define  HD_DirTemp                 _HD_DirTemp
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_DirClose(HD_DIR hDir);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_DirCreate(HD_STRING DirName);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_DirCreateC(const HD_CHAR *DirName);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT HD_DirCurrent(HD_STRING Str, HD_BOOL AddSep);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_DirExist(HD_STRING DirName);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_DirExistC(const HD_CHAR *DirName);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT HD_DirGetCurrent(HD_STRING Str, HD_BOOL AddSep);
HDRIVE_EXTERN HD_STRLIST        HDRIVE_EXPORT HD_DirLoad(HD_STRING Dir, HD_STRING Pattern, HD_LONG FilterAttr);
HDRIVE_EXTERN HD_STRLIST        HDRIVE_EXPORT HD_DirLoadC(HD_CHAR *Dir, HD_CHAR *Pattern, HD_LONG FilterAttr);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_DirNextFile(HD_DIR hDir);
HDRIVE_EXTERN HD_DIR            HDRIVE_EXPORT HD_DirOpen(HD_STRING Dir);
HDRIVE_EXTERN HD_DIR            HDRIVE_EXPORT HD_DirOpenC(const HD_CHAR *Dir, const HD_CHAR *Pattern);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT HD_DirFixSep(HD_STRING Str, HD_BOOL AddSep);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT HD_DirPrg(HD_STRING Str, HD_BOOL AddSep);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_DirRemove(HD_STRING DirName, HD_LONG Flags);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_DirRemoveC(const HD_CHAR *DirName, HD_LONG Flags);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_DirSetCurrent(HD_STRING Path);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_DirSetCurrentC(const HD_CHAR *Path);
HDRIVE_EXTERN HD_STRING         HDRIVE_EXPORT HD_DirTemp(HD_STRING Str, HD_BOOL AddSep);

#  ifdef __cplusplus
   }
#  endif


/**** C++ wrapper ****/

#  ifdef __cplusplus

/**** Directory class ****/

class HDC_Dir
{
  public:

        /**** Consructor ****/

        inline HDC_Dir(const HD_CHAR *Dir)
        {
          if ((hDir = HD_DirOpenC(Dir, HD_NULL)) == HD_NULL)
            throw HD_ErrCode();
        }

        inline HDC_Dir(const HD_CHAR *Dir, const HD_CHAR *Pattern)
        {
          if ((hDir = HD_DirOpenC(Dir, Pattern)) == HD_NULL)
            throw HD_ErrCode();
        }

        inline HDC_Dir(const HD_CHAR *Dir, HDC_String Pattern)
        {
          if ((hDir = HD_DirOpenC(Dir, Pattern.Cstr())) == HD_NULL)
            throw HD_ErrCode();
        }

        inline HDC_Dir(HD_STRING Dir, const HD_CHAR *Pattern)
        {
          if ((hDir = HD_DirOpenC(Dir -> Cstr, Pattern)) == HD_NULL)
            throw HD_ErrCode();
        }

        inline HDC_Dir(HD_STRING Dir, HD_STRING Pattern)
        {
          if ((hDir = HD_DirOpenC(Dir -> Cstr, Pattern -> Cstr)) == HD_NULL)
            throw HD_ErrCode();
        }

        inline HDC_Dir(HDC_String Dir)
        {
          if ((hDir = HD_DirOpen(Dir.Hdstr())) == HD_NULL)
            throw HD_ErrCode();
        }

        inline HDC_Dir(HDC_String Dir, const HD_CHAR *Pattern)
        {
          if ((hDir = HD_DirOpenC(Dir.Cstr(), Pattern)) == HD_NULL)
            throw HD_ErrCode();
        }

        inline HDC_Dir(HDC_String Dir, HDC_String &Pattern)
        {
          if ((hDir = HD_DirOpenC(Dir.Cstr(), Pattern.Cstr())) == HD_NULL)
            throw HD_ErrCode();
        }

        /**** Destructor ****/

        inline ~HDC_Dir(void)
        {
          HD_DirClose(hDir);
        }

        /**** Get next file ****/

        inline HD_BOOL NextFile(void)
        {
          return HD_DirNextFile(hDir);
        }

        /**** Properties ****/

        inline HD_BOOL          IsDir(HD_VOID)          { return (hDir -> Attributes & HD_FILEATTR_DIRECTORY); }
        inline HD_BOOL          IsFile(HD_VOID)         { return (hDir -> Attributes & HD_FILEATTR_FILE     ); }
        inline HD_LONG          GetAttributes(HD_VOID)  { return hDir -> Attributes; }
        inline HD_STRING        GetFileName(HD_VOID)    { return hDir -> FileName;   }
        inline HD_ULONG         GetFileNum(HD_VOID)     { return hDir -> FileNum;    }
        inline HD_UDLONG        GetFileSize(HD_VOID)    { return hDir -> FileSize;   }
        inline HD_STRING        GetPath(HD_VOID)        { return hDir -> Path;       }
        inline HD_TIME          GetTimeAcc(HD_VOID)     { return hDir -> TimeAcc;    }
        inline HD_TIME          GetTimeChg(HD_VOID)     { return hDir -> TimeChg;    }
        inline HD_TIME          GetTimeMod(HD_VOID)     { return hDir -> TimeMod;    }

        /**** Private properties ****/

  private:

        HD_DIR                  hDir;
};

/**** Directory list class ****/

class HDC_DirList
{
public:
        HD_STRLIST              DirList;

        /**** Constructor ****/

        inline HDC_DirList(void)
        {
          DirList     = HD_NULL;
          rDir        = HD_NULL;
          rFilterAttr = 0;
          rPattern    = HD_NULL;
        }

        inline HDC_DirList(const HD_CHAR *Dir, const HD_CHAR *Pattern = HD_NULL, HD_LONG FilterAttr = HD_FILEATTR_ALL)
        {
          DirList = HD_NULL;
          Scan(Dir, Pattern, FilterAttr);
        }

        inline HDC_DirList(HD_STRING Dir, const HD_CHAR *Pattern = HD_NULL, HD_LONG FilterAttr = HD_FILEATTR_ALL)
        {
          DirList = HD_NULL;
          Scan(Dir, Pattern, FilterAttr);
        }

        inline HDC_DirList(HD_STRING Dir, HD_STRING Pattern = HD_NULL, HD_LONG FilterAttr = HD_FILEATTR_ALL)
        {
          DirList = HD_NULL;
          Scan(Dir, Pattern, FilterAttr);
        }

        inline HDC_DirList(HDC_String Dir, HDC_String Pattern, HD_LONG FilterAttr = HD_FILEATTR_ALL)
        {
          DirList = HD_NULL;
          Scan(Dir, Pattern, FilterAttr);
        }

        inline HDC_DirList(HDC_String Dir, HD_STRING Pattern = HD_NULL, HD_LONG FilterAttr = HD_FILEATTR_ALL)
        {
          DirList = HD_NULL;
          Scan(Dir, Pattern, FilterAttr);
        }

        /**** Destructor ****/

        inline ~HDC_DirList(void)
        {
          HD_StrFree(rDir);
          HD_StrFree(rPattern);
          HD_StrListFree(DirList);
        }

        /**** Rescan the directory ****/

        inline HD_VOID Rescan(void)
        {
          if (DirList) HD_StrListFree(DirList);

          if ((DirList = HD_DirLoad(rDir, rPattern, rFilterAttr)) == HD_NULL)
            throw HD_ErrCode();
        }

        /**** Scan the directory ****/

        inline HD_VOID Scan(const HD_CHAR *Dir, const HD_CHAR *Pattern = HD_NULL, HD_LONG FilterAttr = HD_FILEATTR_ALL)
        {
          rDir        = HD_StrCpyC(HD_NULL, Dir);
          rFilterAttr = FilterAttr;
          rPattern    = HD_StrCpyC(HD_NULL, Pattern);

          Rescan();
        }

        inline HD_VOID Scan(HD_STRING Dir, const HD_CHAR *Pattern = HD_NULL, HD_LONG FilterAttr = HD_FILEATTR_ALL)
        {
          rDir        = HD_StrCpy(HD_NULL, Dir);
          rFilterAttr = FilterAttr;
          rPattern    = HD_StrCpyC(HD_NULL, Pattern);

          Rescan();
        }

        inline HD_VOID Scan(HD_STRING Dir, HD_STRING Pattern = HD_NULL, HD_LONG FilterAttr = HD_FILEATTR_ALL)
        {
          rDir        = HD_StrCpy(HD_NULL, Dir);
          rFilterAttr = FilterAttr;
          rPattern    = HD_StrCpy(HD_NULL, Pattern);

          Rescan();
        }

        inline HD_VOID Scan(HDC_String Dir, HDC_String Pattern, HD_LONG FilterAttr = HD_FILEATTR_ALL)
        {
          rDir        = HD_StrCpy(HD_NULL, Dir.Hdstr());
          rFilterAttr = FilterAttr;
          rPattern    = HD_StrCpy(HD_NULL, Pattern.Hdstr());

          Rescan();
        }

        inline HD_VOID Scan(HDC_String Dir, const HD_CHAR *Pattern = HD_NULL, HD_LONG FilterAttr = HD_FILEATTR_ALL)
        {
          rDir        = HD_StrCpy(HD_NULL, Dir.Hdstr());
          rFilterAttr = FilterAttr;
          rPattern    = HD_StrCpyC(HD_NULL, Pattern);

          Rescan();
        }
private:

        /**** Private proprties ****/

        HD_STRING       rDir, rPattern;
        HD_LONG         rFilterAttr;
};

#  endif
#endif
