
/*************************************************
****       VEGA - TCP/IP file utilities       ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_TCPIO_H
#  define  __VG_TCPIO_H

#  include <hdsocket.h>
#  include <stdio.h>

/**** Download types ****/

#  define  VG_DLT_FILE          0       /* Don't change the order */
#  define  VG_DLT_HTTP          1
#  define  VG_DLT_UNKNOWN       2

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_TcpClose                        _VG_TcpClose
#    define  VG_TcpCloseAll                     _VG_TcpCloseAll
#    define  VG_TcpFindUrlType                  _VG_TcpFindUrlType
#    define  VG_TcpOpen                         _VG_TcpOpen
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_TcpClose(FILE *hFile);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_TcpCloseAll(HD_VOID);
VEGA_EXTERN HD_LONG         VEGA_EXPORT VG_TcpFindUrlType(const HD_CHAR *Url);
VEGA_EXTERN FILE *          VEGA_EXPORT VG_TcpOpen(const HD_CHAR *Url, HD_HTTPCLIENT_GET CallBack);

#  ifdef __cplusplus
   }
#  endif
#endif
