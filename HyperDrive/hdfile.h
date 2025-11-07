
/*******************************************
****     HyperDrive - File routines     ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#ifndef __HDFILE_H
#  define  __HDFILE_H

#  include <hyperdrive.h>

/**** Text file mode ****/

#  define  HD_TXT_AMIGA         0
#  define  HD_TXT_UNIX          0
#  define  HD_TXT_WINDOWS       1
#  define  HD_TXT_MAC           2
#  define  HD_TXT_NET           1

#  ifdef MACOS
#    define  HD_TXT_DEFAULT     HD_TXT_MAC
#  endif

#  ifdef WIN32
#    define  HD_TXT_DEFAULT     HD_TXT_WINDOWS
#  endif

#  ifndef HD_TXT_DEFAULT
#    define  HD_TXT_DEFAULT     HD_TXT_UNIX
#  endif

/**** HD_DirRemove() and HD_FileRemove() flags ****/

#  define  HD_REMOVE_NONE       0
#  define  HD_REMOVE_UNDO       1       /* Undo enable (move to recycle bin )                 */
#  define  HD_REMOVE_IFEMPTY    2       /* Remove only empty directory (HD_DirRemove())       */
#  define  HD_REMOVE_RECURSIVE  4       /* Remove recursively (HD_DirRemove() only)           */

/* HD_REMOVE_EMPTY and HD_REMOVE_RECURSIVE can be combined */

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_FileCopy                _HD_FileCopy
#    define  HD_FileCopyC               _HD_FileCopyC
#    define  HD_FileExist               _HD_FileExist
#    define  HD_FileExistC              _HD_FileExistC
#    define  HD_FileExistCW             _HD_FileExistCW
#    define  HD_FileExistW              _HD_FileExistW
#    define  HD_FileIsSame              _HD_FileIsSame
#    define  HD_FileIsSameC             _HD_FileIsSameC
#    define  HD_FileMove                _HD_FileMove
#    define  HD_FileMoveC               _HD_FileMoveC
#    define  HD_FileRemove              _HD_FileRemove
#    define  HD_FileRemoveC             _HD_FileRemoveC
#    define  HD_FileSize                _HD_FileSize
#    define  HD_FileSizeC               _HD_FileSizeC
#    define  HD_GetCurrentDir           _HD_GetCurrentDir
#    define  HD_GetFileName             _HD_GetFileName
#    define  HD_GetTmpDir               _HD_GetTmpDir
#    define  HD_GetTmpFileName          _HD_GetTmpFileName
#    define  HD_SetCurrentDir           _HD_SetCurrentDir
#    define  HD_TranslatePath           _HD_TranslatePath
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_FileCopy(HD_STRING Dest, HD_STRING Src);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_FileCopyC(const HD_CHAR *Dest, const HD_CHAR *Src);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_FileExist(HD_STRING FileName);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_FileExistC(const HD_CHAR *FileName);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_FileExistCW(const HD_WCHAR *FileName);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_FileExistW(HD_WSTRING FileName);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_FileIsSame(HD_STRING File1, HD_STRING File2);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_FileIsSameC(const HD_CHAR *File1, const HD_CHAR *File2);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_FileMove(HD_STRING OldFileName, HD_STRING NewFileName);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_FileMoveC(const HD_CHAR *OldFileName, const HD_CHAR *NewFileName);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_FileRemove(HD_STRING FileName, HD_LONG Flags);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_FileRemoveC(const HD_CHAR *FileName, HD_LONG Flags);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_FileSize(HD_STRING FileName);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_FileSizeC(const HD_CHAR *FileName);
HDRIVE_EXTERN HD_CHAR *           HDRIVE_EXPORT HD_GetCurrentDir(HD_VOID);
HDRIVE_EXTERN HD_CHAR *           HDRIVE_EXPORT HD_GetFileName(HD_CHAR *Str);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_GetTmpDir(HD_CHAR *Str, HD_LONG Size);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_GetTmpFileName(HD_CHAR *Str);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_SetCurrentDir(const HD_CHAR *Path);
HDRIVE_EXTERN HD_CHAR *           HDRIVE_EXPORT HD_TranslatePath(HD_CHAR *Path);

#  ifdef __cplusplus
   }
#  endif
#endif
