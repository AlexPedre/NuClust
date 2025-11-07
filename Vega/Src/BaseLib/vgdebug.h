
/*************************************************
****         VEGA ZZ - Debug header           ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_DEBUG_H
#  define  __VG_DEBUG_H

/**** Debug enabled ****/

#  ifdef VG_DEBUG
#    include <stdio.h>
#    include <stdarg.h>
#    include <time.h>

#    define  VGDB_OUTFILE         "debug.log"
#    define  VGDB_End             VGDB_Close();
#    define  VGDB_Out             VGDB_Print
#    define  VGDB_Out2            VGDB_Print
#    define  VGDB_Out3            VGDB_Print

#    ifdef VG_DEBUG_MAIN
#      ifdef __cplusplus
#        define  VGDB_EXTERN      extern "C"
#      else
#        define  VGDB_EXTERN
#      endif

/**** Global variables ****/

FILE    *VgdbFH = NULL;


/**** Write a log line ****/

VEGA_EXTERN HD_VOID VEGA_EXPORTA VGDB_Print(const HD_CHAR *Fmt, ...)
{
  static time_t         StartTime;
  time_t                CurTime;
  va_list               vl;

  if (!VgdbFH) {
    if ((VgdbFH = fopen(VGDB_OUTFILE, VegaFopenW)) == NULL) return;
    else time(&StartTime);
  }

  time(&CurTime);
  fprintf(VgdbFH, "> %4d: ", CurTime - StartTime);
  va_start(vl, Fmt);
  vfprintf(VgdbFH, Fmt, vl);
  va_end(vl);
  fprintf(VgdbFH, "\n");
}


/**** Close the log file ****/

VGDB_EXTERN HD_VOID VEGA_EXPORT VGDB_Close(HD_VOID)
{
  if (VgdbFH) fclose(VgdbFH);
}

#    else

/**** Global variables ****/

extern FILE     *VgdbFH;

/**** Prototypes ****/

#      ifdef __cplusplus
extern "C" {
#      endif

VEGA_EXTERN HD_VOID VEGA_EXPORTA VGDB_Print(const HD_CHAR *, ...);
VEGA_EXTERN HD_VOID VEGA_EXPORT  VGDB_Close(HD_VOID);

#      ifdef __cplusplus
}
#      endif
#    endif
#  else
#    define  VGDB_End
#    define  VGDB_Out(a)
#    define  VGDB_Out2(a, b)
#    define  VGDB_Out3(a, b, c)
#  endif
#endif

