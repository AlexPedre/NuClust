
/*******************************************
****     HyperDrive - Cpu detection     ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#ifndef _MYCPU_H
#  define  _MYCPU_H

#  include "hdcpu.h"

/**** Intel/AMD x86 CPU ****/

#  ifdef WIN64
#    define  MYCPU_TYPE               "AMD64"
#    define  HD_FEAT_CODE_CUR         HD_FEAT_CODE_64
#    define  HD_FEAT_CPU_CUR          HD_FEAT_CPU_AMDK8
#    define  HD_FEAT_CPU_CURSTR       "AMD64"
#    define  HD_FEAT_CURSTR           HD_FEAT_CPU_CURSTR
#    define  HD_FEAT_SIMD_CUR         HD_FEAT_SIMD_SSE
#  else
#  if (defined(__WIN32__) && defined(__BORLANDC__))
#    ifdef _M_IX86
#      if _M_IX86 == 300
#        define  MYCPU_TYPE                             "Intel 386"
#        define  HD_FEAT_CODE_CUR                       HD_FEAT_CODE_32
#        define  HD_FEAT_CPU_CUR                        HD_FEAT_CPU_I386
#        define  HD_FEAT_CPU_CURSTR                     "386"
#        define  HD_FEAT_CURSTR                         HD_FEAT_CPU_CURSTR
#        define  HD_FEAT_SIMD_CUR                       HD_FEAT_SIMD_NONE
#      else
#        if _M_IX86 == 400
#          define  MYCPU_TYPE                           "Intel 486"
#          define  HD_FEAT_CODE_CUR                     HD_FEAT_CODE_32
#          define  HD_FEAT_CPU_CUR                      HD_FEAT_CPU_I486
#          define  HD_FEAT_CPU_CURSTR                   "486"
#          define  HD_FEAT_CURSTR                       HD_FEAT_CPU_CURSTR
#          define  HD_FEAT_SIMD_CUR                     HD_FEAT_SIMD_NONE
#        else
#          if _M_IX86 == 500
#            define  MYCPU_TYPE                         "Intel Pentium"
#            define  HD_FEAT_CODE_CUR                   HD_FEAT_CODE_32
#            define  HD_FEAT_CPU_CUR                    HD_FEAT_CPU_I586
#            define  HD_FEAT_CPU_CURSTR                 "586"
#            define  HD_FEAT_CURSTR                     HD_FEAT_CPU_CURSTR
#            define  HD_FEAT_SIMD_CUR                   HD_FEAT_SIMD_NONE
#          else
#            if _M_IX86 == 600
#              define  MYCPU_TYPE                       "Intel Pentium Pro"
#              define  HD_FEAT_CODE_CUR                 HD_FEAT_CODE_32
#              define  HD_FEAT_CPU_CUR                  HD_FEAT_CPU_I686
#              define  HD_FEAT_CPU_CURSTR               "686"
#              define  HD_FEAT_CURSTR                   HD_FEAT_CPU_CURSTR
#              define  HD_FEAT_SIMD_CUR                 HD_FEAT_SIMD_NONE
#            endif
#          endif
#        endif
#      endif
#    endif
#  else
#    if (defined WIN32 || defined _WIN32 || defined _WINDOWS || defined WINDOWS || defined(LINUX))
#      ifdef __tune_pentium__
#        define  MYCPU_TYPE                           "Intel Pentium"
#        define  HD_FEAT_CODE_CUR                     HD_FEAT_CODE_32
#        define  HD_FEAT_CPU_CUR                      HD_FEAT_CPU_I586
#        define  HD_FEAT_CPU_CURSTR                   "586"
#        define  HD_FEAT_CURSTR                       HD_FEAT_CPU_CURSTR
#        define  HD_FEAT_SIMD_CUR                     HD_FEAT_SIMD_NONE
#      else
#        ifdef __tune_pentiumpro__
#          ifdef __tune_pentium3__
#            define MYCPU_TYPE                        "Intel Pentium 3"
#            define  HD_FEAT_CODE_CUR                 HD_FEAT_CODE_32
#            define  HD_FEAT_CPU_CUR                  HD_FEAT_CPU_IP3
#            define  HD_FEAT_CPU_CURSTR               "Pentium III"
#            define  HD_FEAT_CURSTR                   HD_FEAT_CPU_CURSTR ", SSE"
#            define  HD_FEAT_SIMD_CUR                 HD_FEAT_SIMD_SSE
#          else
#            define MYCPU_TYPE                        "Intel Pentium Pro"
#            define  HD_FEAT_CODE_CUR                 HD_FEAT_CODE_32
#            define  HD_FEAT_CPU_CUR                  HD_FEAT_CPU_I686
#            define  HD_FEAT_CPU_CURSTR               "686"
#            define  HD_FEAT_CURSTR                   HD_FEAT_CPU_CURSTR
#            define  HD_FEAT_SIMD_CUR                 HD_FEAT_SIMD_NONE
#          endif
#        else
#          ifdef __tune_pentium4__
#            define MYCPU_TYPE                        "Intel Pentium 4"
#            define  HD_FEAT_CODE_CUR                 HD_FEAT_CODE_32
#            define  HD_FEAT_CPU_CUR                  HD_FEAT_CPU_IP4
#            define  HD_FEAT_CPU_CURSTR               "Pentium IV"
#            define  HD_FEAT_CURSTR                   HD_FEAT_CPU_CURSTR ", SSE"
#            define  HD_FEAT_SIMD_CUR                 HD_FEAT_SIMD_SSE
#          else
#            ifdef __tune_k6__
#              define  MYCPU_TYPE                     "AMD K6"
#              define  HD_FEAT_CODE_CUR               HD_FEAT_CODE_32
#              define  HD_FEAT_CPU_CUR                HD_FEAT_CPU_AMDK6
#              define  HD_FEAT_CPU_CURSTR             "K6"
#              define  HD_FEAT_CURSTR                 HD_FEAT_CPU_CURSTR
#              define  HD_FEAT_SIMD_CUR               HD_FEAT_SIMD_NONE
#            else
#             ifdef __tune_athlon_sse__
#                define   MYCPU_TYPE                  "AMD Athlon 4/XP/MP"
#                define  HD_FEAT_CODE_CUR             HD_FEAT_CODE_32
#                define  HD_FEAT_CPU_CUR              HD_FEAT_CPU_AMDK7XP
#                define  HD_FEAT_CPU_CURSTR           "Athlon XP"
#                define  HD_FEAT_CURSTR               HD_FEAT_CPU_CURSTR ", SSE"
#                define  HD_FEAT_SIMD_CUR             HD_FEAT_SIMD_SSE
#              else
#                ifdef __tune_athlon__
#                  define  MYCPU_TYPE                 "AMD Athlon/Duron"
#                  define  HD_FEAT_CODE_CUR           HD_FEAT_CODE_32
#                  define  HD_FEAT_CPU_CUR            HD_FEAT_CPU_AMDK7
#                  define  HD_FEAT_CPU_CURSTR         "Athlon"
#                  define  HD_FEAT_CURSTR             HD_FEAT_CPU_CURSTR
#                  define  HD_FEAT_SIMD_CUR           HD_FEAT_SIMD_NONE
#                else
#                  ifdef __tune_k8__
#                    define  MYCPU_TYPE               "AMD Opteron/Athlon 64"
#                    define  HD_FEAT_CODE_CUR         HD_FEAT_CODE_32
#                    define  HD_FEAT_CPU_CUR          HD_FEAT_CPU_AMDK8
#                    define  HD_FEAT_CPU_CURSTR       "Athlon 64"
#                    define  HD_FEAT_CURSTR           HD_FEAT_CPU_CURSTR ", SSE"
#                    define  HD_FEAT_SIMD_CUR         HD_FEAT_SIMD_SSE
#                  else
#                    ifdef __tune_core2__
#                      define  MYCPU_TYPE             "Intel Core 2"
#                      define  HD_FEAT_CODE_CUR       HD_FEAT_CODE_32
#                      define  HD_FEAT_CPU_CUR        HD_FEAT_CPU_ICORE2
#                      define  HD_FEAT_CPU_CURSTR     "Core 2"
#                      define  HD_FEAT_CURSTR         HD_FEAT_CPU_CURSTR ", SSE"
#                      define  HD_FEAT_SIMD_CUR       HD_FEAT_SIMD_SSE
#                    else
#                      if defined(LINUX64) && !defined(__ARM_ARCH)
#                        define  MYCPU_TYPE           "AMD64"
#                        define  HD_FEAT_CODE_CUR     HD_FEAT_CODE_64
#                        define  HD_FEAT_CPU_CUR      HD_FEAT_CPU_AMDK8
#                        define  HD_FEAT_CPU_CURSTR   "AMD64"
#                        define  HD_FEAT_CURSTR       HD_FEAT_CPU_CURSTR ", SSE"
#                        define  HD_FEAT_SIMD_CUR     HD_FEAT_SIMD_SSE
#                      endif
#                    endif
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
#  endif

/**** Amiga Motorola CPU ****/

#  ifdef AMIGA
#    ifdef   mc68020
#      define  MYCPU_TYPE                   "68020/68881"
#      define  HD_FEAT_CPU_CUR              HD_FEAT_CPU_MC020881
#      define  HD_FEAT_CPU_CURSTR           "MC68020/68881"
#    else
#      ifdef   mc68030
#        define  MYCPU_TYPE                 "68030/68881"
#        define  HD_FEAT_CPU_CUR            HD_FEAT_CPU_MC030881
#        define  HD_FEAT_CPU_CURSTR         "MC68030/68881"
#      else
#        ifdef   mc68040
#          define  MYCPU_TYPE               "68040"
#          define  HD_FEAT_CPU_CUR          HD_FEAT_CPU_MC040
#          define  HD_FEAT_CPU_CURSTR       "MC68040"
#        else
#          define  HD_FEAT_CPU_CUR          HD_FEAT_CPU_MC000
#          define  HD_FEAT_CPU_CURSTR       "MC68000"
#        endif
#      endif
#    endif

#    define  HD_FEAT_CODE_CUR           HD_FEAT_CODE_32
#    define  HD_FEAT_CURSTR             HD_FEAT_CPU_CURSTR
#    define  HD_FEAT_SIMD_CUR           HD_FEAT_SIMD_NONE
#  endif

/**** Silicon Graphics ****/

#  ifdef sgi
#    define  MYCPU_TYPE                  "R4000"
#  endif

#  if defined(__arm__) || defined(__ARM_ARCH)
#    ifdef __aarch64__
#      define  MYCPU_TYPE               "ARM64"
#      define  HD_FEAT_CPU_CUR          HD_FEAT_CPU_ARM
#      define  HD_FEAT_CPU_CURSTR       "ARM64"
#      define  HD_FEAT_CODE_CUR         HD_FEAT_CODE_64
#    else
#      define  MYCPU_TYPE               "ARM"
#      define  HD_FEAT_CPU_CUR          HD_FEAT_CPU_ARM
#      define  HD_FEAT_CPU_CURSTR       "ARM"
#      define  HD_FEAT_CODE_CUR         HD_FEAT_CODE_32
#    endif

#    define  HD_FEAT_CURSTR             HD_FEAT_CPU_CURSTR
#    define  HD_FEAT_SIMD_CUR           HD_FEAT_SIMD_NONE
#  endif

/**** Generic CPU ****/

#  ifndef MYCPU_TYPE
#    define  MYCPU_TYPE
#  endif

#  ifndef MYCPU_OPTIM
#    define MYCPU_OPTIM
#  endif

#  define MYCPU                             MYCPU_TYPE MYCPU_OPTIM
#endif


