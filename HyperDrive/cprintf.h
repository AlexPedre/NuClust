
/**********************************************
****           printf routines             ****
****  (c) 2006-2025, Alessandro Pedretti   ****
**********************************************/

/*
 * Based on the original printf() source code
 */

#ifndef __PRINTF_H
#  define  __PRINTF_H

#  include <stdarg.h>

/**** Types ****/

typedef char                            vint8;
typedef unsigned char                   vuint8;
typedef short                           vint16;
typedef unsigned short                  vuint16;
typedef int                             vint32;
typedef unsigned int                    vuint32;

#  ifdef __BORLANDC__
typedef __int64                         vint64;
typedef unsigned __int64                vuint64;
#  else
typedef long long                       vint64;
typedef unsigned long long              vuint64;
#  endif

typedef float                           vfloat32;
typedef double                          vfloat64;
typedef long double                     vfloat128;

/**** Prototypes ****/

char *          VgIntPrintf(void *(*xRealloc)(void *, int), int useInternal, char *zInitBuf, int nInitBuf, const char *zFormat, va_list ap);

/*
 * xRealloc             Routine to realloc memory. May be NULL
 * useInternal          Use internal %-conversions if true
 * zInitBuf,            Initially write here, before mallocing
 * nInitBuf             Size of zInitBuf[]
 * zFormat              Format string
 * ap                   Arguments
 */

HD_CHAR *       VgMPrintf(const HD_CHAR *zFormat, ...);
HD_CHAR *       VgSnPrintf(HD_LONG n, HD_CHAR *zBuf, const HD_CHAR *zFormat, ...);
HD_CHAR *       VgVmPrintf(const HD_CHAR *zFormat, va_list ap);

#endif
