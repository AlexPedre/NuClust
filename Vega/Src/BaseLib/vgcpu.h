
/*************************************************
****            VEGA - Cpu detection          ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_CPU_H
#  define  __VG_CPU_H

/**** Intel/AMD x86 CPU ****/

#  if (defined(__WIN32__) && defined(__BORLANDC__))
#    ifdef _M_IX86
#      if _M_IX86 == 300
#        define  MYCPU_TYPE               "Intel 386"
#      else
#        if _M_IX86 == 400
#          define  MYCPU_TYPE             "Intel 486"
#        else
#          if _M_IX86 == 500
#            define  MYCPU_TYPE           "Intel Pentium"
#          else
#            if _M_IX86 == 600
#              define  MYCPU_TYPE         "Intel Pentium Pro"
#            endif
#          endif
#        endif
#      endif
#    endif
#  else
#    if (defined WIN32 || defined _WIN32 || defined _WINDOWS || defined WINDOWS || defined(linux))
#      ifdef __tune_pentium__
#        define MYCPU_TYPE                "Intel Pentium"
#      else
#        ifdef __tune_pentiumpro__
#          define MYCPU_TYPE              "Intel Pentium Pro"
#        else
#          ifdef __tune_pentium3__
#            define MYCPU_TYPE            "Intel Pentium 3"
#          else
#            ifdef __tune_pentium4__
#              define MYCPU_TYPE          "Intel Pentium 4"
#            else
#              ifdef __tune_k6__
#                define MYCPU_TYPE        "AMD K6"
#              else
#               ifdef __tune_athlon_sse__
#                  define MYCPU_TYPE      "AMD Athlon 4/XP/MP"
#                else
#                  ifdef __tune_athlon__
#                    define MYCPU_TYPE    "AMD Athlon/Duron"
#                  endif
#                endif
#              endif
#            endif
#          endif
#        endif
#      endif
#    endif
#    ifdef SSE
#      define MYCPU_OPTIM                 " SSE"
#    endif
#  endif

/**** Amiga Motorola CPU ****/

#  ifdef AMIGA
#    ifdef   mc68020
#      define  MYCPU_TYPE                 "68020/68881"
#    endif
#    ifdef   mc68030
#      define  MYCPU_TYPE                 "68030/68881"
#    endif
#    ifdef   mc68040
#      define  MYCPU_TYPE                 "68040"
#    endif
#  endif

/**** ARM ****/

#  ifdef __arm__
#    define  MYCPU_TYPE                   "ARM"
#  endif

/**** Silicon Graphics ****/

#  ifdef sgi
#    define  MYCPU_TYPE                   "R4000"
#  endif

/**** Generic CPU ****/

#  ifndef MYCPU_TYPE
#    define  MYCPU_TYPE
#  endif

#  ifndef MYCPU_OPTIM
#    define MYCPU_OPTIM
#  endif

#  ifdef WIN64
#    define  MYCPU                        "AMD64"
#  else
#    define  MYCPU                        MYCPU_TYPE MYCPU_OPTIM
#  endif

#endif

