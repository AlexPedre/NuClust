
/********************************************
****      HyperDrive - Regex header      ****
**** (c) 2004-2025, Alessandro Pedretti  ****
********************************************/


#ifndef __HD_REGEX_H
#  define  __HD_REGEX_H

#  include "hyperdrive.h"

/**** HD_RegComp() cFlags ****/

#  define  HD_REG_NONE                      0
#  define  HD_REG_EXTENDED                  1
#  define  HD_REG_ICASE                     (HD_REG_EXTENDED << 1)
#  define  HD_REG_NEWLINE                   (HD_REG_ICASE    << 1)
#  define  HD_REG_NOSUB                     (HD_REG_NEWLINE  << 1)

/**** HD_RegExec() eFlags ****/

#  define  HD_REG_NOTBOL                    1
#  define  HD_REG_NOTEOL                    (1 << 1)

/**** Errors ****/

#  define  HD_ERR_REG_NOERROR               0    /* Success                                      */
#  define  HD_ERR_REG_NOMATCH               1901 /* Didn't find a match (for regexec)            */
#  define  HD_ERR_REG_BADPAT                1902 /* Invalid pattern                              */
#  define  HD_ERR_REG_ECOLLATE              1903 /* Not implemented                              */
#  define  HD_ERR_REG_ECTYPE                1904 /* Invalid character class name                 */
#  define  HD_ERR_REG_EESCAPE               1905 /* Trailing backslash                           */
#  define  HD_ERR_REG_ESUBREG               1906 /* Invalid back reference                       */
#  define  HD_ERR_REG_EBRACK                1907 /* Unmatched left bracket                       */
#  define  HD_ERR_REG_EPAREN                1908 /* Parenthesis imbalance                        */
#  define  HD_ERR_REG_EBRACE                1909 /* Unmatched \{                                 */
#  define  HD_ERR_REG_BADBR                 1910 /* Invalid contents of \{\}                     */
#  define  HD_ERR_REG_ERANGE                1911 /* Invalid range end                            */
#  define  HD_ERR_REG_ESPACE                1912 /* Ran out of memory                            */
#  define  HD_ERR_REG_BADRPT                1913 /* No preceding re for repetition op            */
#  define  HD_ERR_REG_EEND                  1914 /* Premature end                                */
#  define  HD_ERR_REG_ESIZE                 1915 /* Compiled pattern bigger than 2^16 bytes      */
#  define  HD_ERR_REG_ERPAREN               1916 /* Unmatched ) or \); not returned from regcomp */

#  define HD_REGS_UNALLOCATED               0
#  define HD_REGS_REALLOCATE                1
#  define HD_REGS_FIXED                     2

/**** Types ****/

typedef unsigned long int   HD_REG_SYNTAX;
typedef char *              HD_RE_TRANSLATE_TYPE;
typedef int                 HD_REG_ERRCODE;

typedef struct {
  HD_LONG           rm_so;
  HD_LONG           rm_eo;
} HD_REGMATCH;

/**** Regex context ****/

typedef struct
{
  HD_UCHAR *            buffer;
  unsigned long int     allocated;
  unsigned long int     used;
  HD_REG_SYNTAX         syntax;
  HD_CHAR *             fastmap;
  HD_RE_TRANSLATE_TYPE  translate;
  HD_SIZE               re_nsub;
  HD_ULONG              can_be_null : 1;
  HD_ULONG              regs_allocated : 2;
  HD_ULONG              fastmap_accurate : 1;
  HD_ULONG              no_sub : 1;
  HD_ULONG              not_bol : 1;
  HD_ULONG              not_eol : 1;
  HD_ULONG              newline_anchor : 1;
} HD_REGEX;

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_RegComp                 _HD_RegComp
#    define  HD_RegError                _HD_RegError
#    define  HD_RegExec                 _HD_RegExec
#    define  HD_RegFree                 _HD_RegFree
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT HD_RegComp(HD_REGEX *Preg, const HD_CHAR *Pattern, HD_LONG cFlags);
HDRIVE_EXTERN HD_SIZE           HDRIVE_EXPORT HD_RegError(HD_LONG ErrCode, HD_CHAR *ErrBuf, HD_SIZE ErrBufSize);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT HD_RegExec(const HD_REGEX *Preg, const HD_CHAR *String,
                                                         HD_SIZE Nmatch, HD_REGMATCH Pmatch[], HD_LONG eFlags);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_RegFree(HD_REGEX *Preg);

#  ifdef __cplusplus
   }
#  endif
#endif