
/*****************************************************
****  HyperDrive - Atom Type Description Language ****
****      (c) 2004-2025, Alessandro Pedretti     ****
****************************************************/


#ifndef __HDATDL_H
#  define  __HDATDL_H

#  include "hdstring.h"

/**** Aromaticity flags ****/

#  define  HD_ATDL_AROM_DONTCHECK       0
#  define  HD_ATDL_AROM_CHECK           1
#  define  HD_ATDL_AROM_NO              2

/**** Operators ****/

#  define  HD_ATDLOP_AND                1
#  define  HD_ATDLOP_EQUAL              2
#  define  HD_ATDLOP_NOT                4
#  define  HD_ATDLOP_OR                 8

/**** _HD_AtdlLoad() flags ****/

#  define  HD_ATDL_LOADFLG_NONE         0
#  define  HD_ATDL_LOADFLG_USECACHE     1
#  define  HD_ATDL_LOADFLG_CHECKCHANGE  2

/**** Ring flags ****/

#  define  HD_ATDL_RING_DONTCHECK       0
#  define  HD_ATDL_RING_NO              2
#  define  HD_ATDL_RING_MIN             3
#  define  HD_ATDL_RING_MAX             7
#  define  HD_ATDL_RING_ANY             9

/**** ATDL errors ****/

#  define  HD_ERR_ATDL_ATTOOLONG      901 /* Atom type too long               */
#  define  HD_ERR_ATDL_DESCTOOLONG    902 /* Description too long             */
#  define  HD_ERR_ATDL_EMPTY          903 /* Empty expression                 */
#  define  HD_ERR_ATDL_ILLAROM        904 /* Illegal aromaticity indicator    */
#  define  HD_ERR_ATDL_ILLNUM         905 /* Illegal number of arguments      */
#  define  HD_ERR_ATDL_ILLRING        906 /* Illegal ring indicator           */
#  define  HD_ERR_ATDL_ILLSOST        907 /* Illegal number of substituent    */
#  define  HD_ERR_ATDL_INVELEM        908 /* Invalid element                  */
#  define  HD_ERR_ATDL_OPINV          909 /* Invalid operator                 */
#  define  HD_ERR_ATDL_OPMULTIPLE     910 /* Multiple operators               */
#  define  HD_ERR_ATDL_OPREQUIRED     911 /* Operator required                */
#  define  HD_ERR_ATDL_SUBDESCTOOLONG 912 /* Sub-description too long         */
#  define  HD_ERR_ATDL_UNBPAR         913 /* Unbalanced parentesis            */
#  define  HD_ERR_ATDL_UNKFORMAT      914 /* Unknown ATDL file format         */

/**** ATDL sub-descriptor ****/

typedef struct {
  union {
    HD_WORD     S;
    HD_CHAR     C[2];
    HD_LONG     L;
  } Val;                                /* Value                              */
  HD_LONG       Op;                     /* Operator                           */
} HD_ATDL_SUBDESC;

/**** ATDL descriptor ****/

typedef struct {
  HD_ATDL_SUBDESC *     Atom;           /* Element                            */
  HD_ATDL_SUBDESC *     NSost;          /* Number of substituents             */
  HD_ATDL_SUBDESC *     Ring;           /* Type of ring                       */
  HD_ATDL_SUBDESC *     Arom;           /* The ring is aromatic ?             */
  HD_LONG               NSub;           /* Sublevel number                    */
} HD_ATDL_DESC;

/**** ATDL atom type ****/

typedef struct __atdl_type {
  struct __atdl_type *  Next;
  struct __atdl_type *  Prev;
  HD_OCHAR              Type;           /* Atom type                          */
  HD_ATDL_DESC *        InizFFArgs;     /* Description                        */
  HD_LONG               TotArgs;        /* Number of arguments                */
} HD_ATDL_TYPE;

/**** ATDL handle ****/

typedef struct __atdl {
  struct __atdl *       Next;
  struct __atdl *       Prev;
  HD_STRING             Name;           /* Potential name                     */
  HD_STRING             FileName;       /* File name                          */
  HD_LONG               Version;        /* Version                            */
  HD_LONG               Revision;       /* Revision                           */
  long                  LastMod;        /* Time of the last modification      */
  HD_LIST *             AtTypes;        /* Atom types                         */
} HD_ATDL;

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_AtdlAssign              _HD_AtdlAssign
#    define  HD_AtdlChkAtm              _HD_AtdlChkAtm
#    define  HD_AtdlFree                _HD_AtdlFree
#    define  HD_AtdlGetLine             _HD_AtdlGetLine
#    define  HD_AtdlLoad                _HD_AtdlLoad
#    define  HD_AtdlMatch               _HD_AtdlMatch
#    define  HD_FFChk                   _HD_FFChk
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_AtdlAssign(HD_ATDL *Atdl, HD_ATOM *Atm, HD_ULONG TotAtm, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_AtdlChkAtm(HD_ATOM *Atm, HD_ATDL_DESC *FFArg, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_AtdlFree(HD_ATDL *Atdl);
HDRIVE_EXTERN HD_ULONG          HDRIVE_EXPORT HD_AtdlGetLine(HD_VOID);
HDRIVE_EXTERN HD_ATDL *         HDRIVE_EXPORT HD_AtdlLoad(const HD_CHAR *FileName, HD_LONG Flags);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT HD_AtdlMatch(HD_UBYTE *MatchMtx, HD_ATOM *Atm, HD_ATDL_DESC *FFStart, HD_ATDL_DESC *FFEnd, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_FFChk(HD_ATOM *InizAtm, HD_BOOL ActiveOnly);

#  ifdef __cplusplus
   }
#  endif
#endif

