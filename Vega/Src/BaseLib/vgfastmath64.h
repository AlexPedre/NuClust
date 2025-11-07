
/*************************************************
****      VEGA - Fast Math for Clang 64       ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_FASTMAT64_H
#  define  __VG_FASTMAT64_H

#  if defined(__BORLANDC__) && !defined(VG_NO_FASTMATH64)
#    if defined(__clang__) && defined(_WIN64)
#      include <math.h>

#      ifdef __cplusplus
#        include <System.Math.hpp>

#        define acos    ArcCos
#        define acosf   ArcCos
#        define asin    ArcSin
#        define asinf   ArcSin
#        define atan2   ArcTan2
#        define atan2f  ArcTan2
#        define cos     Cos
#        define cosf    Cos
#        define sin     Sin
#        define sinf    Sin
#        define tan     Tan
#        define tanf    Tan
#      else
#        define acos    FastAcos
#        define asin    FastAcos
#        define atan2   FastAtan2
#        define cos     FastCos
#        define sin     FastSin
#        define tan     FastTan
#      endif

/**** Prototypes ****/

#      ifdef __cplusplus
extern "C" {
#      endif

double        __fastcall FastAcos(double x);
float         __fastcall FastAcosf(float x);
double        __fastcall FastAsin(double x);
float         __fastcall FastAsinf(float x);
double        __fastcall FastAtan2(double y, double x);
float         __fastcall FastAtan2f(float y, float x);
double        __fastcall FastCos(double x);
float         __fastcall FastCosf(float x);
double        __fastcall FastSin(double x);
float         __fastcall FastSinf(float x);
double        __fastcall FastTan(double x);
float         __fastcall FastTanf(float x);

#      ifdef __cplusplus
}
#      endif
#    else
#      include <fastmath.h>

#      define acosf   acos
#      define asinf   asin
#      define atan2f  atan2
#      define cosf    cos
#      define sinf    sin
#      define tanf    tan
#    endif
#  else
#    include <math.h>
#  endif
#endif

