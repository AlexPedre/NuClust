
/*************************************************
****            VEGA - Stat macros            ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_STAT_H
#  define  __VG_STAT_H
#  include <sys/stat.h>

#  ifdef __BORLANDC__
#    define  _stati64s          stati64
#    define  _strupr            strupr
#  else
#    ifndef _stati64
#      define  _stati64         stat
#    endif

#    if defined(__GNUC__) && defined(WIN64)
#      define  _stati64s        _stati64
#    else
#      define  _stati64s        stat
#    endif
#  endif

#  ifdef S_ISDIR
#    undef S_ISDIR
#  endif

#  define  S_ISDIR(m)           (((m) & S_IFMT) == S_IFDIR)
#endif
