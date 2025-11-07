
/*********************************************
****     HyperDrive - Inline functions    ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifndef __HDINLINE_H
#  define  __HDINLINE_H

#  include "hyperdrive.h"
#  include "hdprivate.h"
#  include "hdmath.h"

//#  if defined(__BORLANDC__) || (defined(WIN32) && (__GNUC__ > 4))
#  if defined(__BORLANDC__)
#    define HD_INLINEEXTERN       static
#  else
#    ifdef HD_USE_INLINEEXTERN
#      define HD_INLINEEXTERN     extern
#    else
#      define HD_INLINEEXTERN
#    endif
#  endif


/**** Measure the distance between two atoms (double precision) ****/

HD_INLINEEXTERN HD_INLINE HD_DOUBLE AtmDist(register HD_ATOM *Atm1, register HD_ATOM *Atm2)
{
  register HD_FLOAT     Dist, Tmp;

  Dist  = Atm1 -> x - Atm2 -> x;
  Dist *= Dist;
  Tmp   = Atm1 -> y - Atm2 -> y;
  Dist += HD_Quad(Tmp);
  Tmp   = Atm1 -> z - Atm2 -> z;
  Dist += HD_Quad(Tmp);

  return sqrt(Dist);
}


/**** Measure the distance between two atoms (single precision) ****/

HD_INLINEEXTERN HD_INLINE HD_FLOAT AtmDistf(register HD_ATOM *Atm1, register HD_ATOM *Atm2)
{
  register HD_FLOAT     Dist, Tmp;

  Dist  = Atm1 -> x - Atm2 -> x;
  Dist *= Dist;
  Tmp   = Atm1 -> y - Atm2 -> y;
  Dist += HD_Quad(Tmp);
  Tmp   = Atm1 -> z - Atm2 -> z;
  Dist += HD_Quad(Tmp);

  return (HD_FLOAT)sqrt(Dist);
}


/**** Measure the square distance between two atoms ****/

HD_INLINEEXTERN HD_INLINE HD_FLOAT AtmQuadDistf(register HD_ATOM *Atm1, register HD_ATOM *Atm2)
{
  register HD_FLOAT     Dist, Tmp;

  Dist  = Atm1 -> x - Atm2 -> x;
  Dist *= Dist;
  Tmp   = Atm1 -> y - Atm2 -> y;
  Dist += HD_Quad(Tmp);
  Tmp   = Atm1 -> z - Atm2 -> z;
  Dist += HD_Quad(Tmp);

  return Dist;
}


/**** Calculate the mass center of water molecule ****/

HD_INLINEEXTERN HD_INLINE void CalcBarWat(register HD_XYZF *Vect, register HD_ATOM **Atm)
{
  register HD_FLOAT      Ms;
  register HD_ULONG      k;

  Vect -> x = Vect -> y = Vect -> z = 0.0f;

  for(k = 0; (k < 3) && (*Atm); ++k) {
#ifdef HD_LITTLE_ENDIAN
    if (((HD_ATOM *)*Atm) -> Elem.S == 0x48)
#else
    if (((HD_ATOM *)*Atm) -> Elem.S == 0x4800)
#endif
      Ms = 1.0f;
    else Ms = 16.0f;

    Vect -> x += ((HD_ATOM *)*Atm) -> x * Ms;
    Vect -> y += ((HD_ATOM *)*Atm) -> y * Ms;
    Vect -> z += ((HD_ATOM *)*Atm) -> z * Ms;

    *Atm = ((HD_ATOM *)*Atm) -> Ptr;
  }
  Vect -> x /= 18.0f;
  Vect -> y /= 18.0f;
  Vect -> z /= 18.0f;
}


/**** Measures the cosine of bond angle ****/

HD_INLINEEXTERN HD_INLINE HD_FLOAT CosBondAnglef(HD_ATOM *a, HD_ATOM *b, HD_ATOM *c)
{
#ifdef HD_USE_SSE
  register HD_FLOAT     Val = SseDistance(&a -> x, &b -> x) * SseDistance(&b -> x, &c -> x);
#else
  register HD_FLOAT     Val = AtmDistf(a, b) * AtmDistf(b, c);
#endif

  if (Val) {
    Val = ((a -> x - b -> x) * (c -> x - b -> x) + (a -> y - b -> y) * (c -> y - b -> y) +
           (a -> z - b -> z) * (c -> z - b -> z)) / Val;
    return (Val > 1.0f ? 1.0f : Val < -1.0f ? -1.0f : Val);
  }

  return 1.0f;
}


/**** Fast cosine (single precision) ****/

HD_INLINEEXTERN HD_INLINE HD_FLOAT FastCosf(register HD_FLOAT Angle)
{
#ifdef __BORLANDC__
  Angle = Angle - floor(Angle * HD_1PI2F) * HD_PI2;
#else
  Angle = Angle - floorf(Angle * HD_1PI2F) * HD_PI2;
#endif
  Angle = (Angle > 0.0f) ? Angle : -Angle;

  if (Angle < HD_PI_2F) {
    Angle *= Angle;
    return (0.99940307f + Angle * (-0.49558072f + 0.03679168f * Angle));
  }

  if (Angle < HD_PIF) {
    Angle  = HD_PIF - Angle;
    Angle *= Angle;
    return -(0.99940307f + Angle * (-0.49558072f + 0.03679168f * Angle));
  }

  if (Angle < HD_3PI_2F) {
    Angle  = Angle - HD_PIF;
    Angle *= Angle;
    return -(0.99940307f + Angle * (-0.49558072f + 0.03679168f * Angle));
  }

  Angle  = HD_PI2F - Angle;
  Angle *= Angle;

  return (0.99940307f + Angle * (-0.49558072f + 0.03679168f * Angle));
}


/**** Fast integer power (double precision) ****/

HD_INLINEEXTERN HD_INLINE HD_DOUBLE FastPow(register HD_DOUBLE x, register HD_LONG n)
{
  register HD_DOUBLE    aux = 1.0;

  if (n < 0) {
    n  = -n;
    x  = 1.0 / x;
  }

  while(n > 0) {
    if (n & 1) {
      aux *= x;
      if (n == 1) return aux;
    }
    x *= x;
    n = n >> 1;
  } /* End of while */

  return aux;
}


/**** Fast integer power (single precision) ****/

HD_INLINEEXTERN HD_INLINE HD_FLOAT FastPowf(register HD_FLOAT x, register HD_LONG n)
{
  register HD_FLOAT     aux = 1.0f;

  if (n < 0) {
    n  = -n;
    x  = 1.0f / x;
  }

  while(n > 0) {
    if (n & 1) {
      aux *= x;
      if (n == 1) return aux;
    }
    x *= x;
    n  = n >> 1;
  } /* End of while */

  return aux;
}


/**** Fast integer power (long double precision) ****/

HD_INLINEEXTERN HD_INLINE HD_LONGDOUBLE FastPowld(register HD_LONGDOUBLE x, register HD_LONG n)
{
  register HD_LONGDOUBLE    aux = 1.0l;

  if (n < 0) {
    n  = -n;
    x  = 1.0l / x;
  }

  while(n > 0) {
    if (n & 1) {
      aux *= x;
      if (n == 1) return aux;
    }
    x *= x;
    n = n >> 1;
  } /* End of while */

  return aux;
}


/**** Fast integer power (integer) ****/

HD_INLINEEXTERN HD_INLINE HD_LONG FastPowi(register HD_LONG x, register HD_LONG n)
{
  register HD_LONG      Result;

  if ((n <  0) || (!x)) return 0;
  if ((x == 1) || (!n)) return 1;

  Result = 1;

  if (n & 1) Result *= x;
  n >>= 1;

  while(n) {
    if (x > HD_SQRT_INT32_MAX) return 0;
    x *= x;
    if (n & 1) Result *= x;
    n >>= 1;
  } /* End of while */

  return Result;
}


/**** Fast integer power (double integer) ****/

HD_INLINEEXTERN HD_INLINE HD_DLONG FastPowli(register HD_DLONG x, register HD_LONG n)
{
  register HD_DLONG     Result;

  if ((n <  MakeInt64(0)) || (!x)) return MakeInt64(0);
  if ((x == MakeInt64(1)) || (!n)) return MakeInt64(1);

  Result = MakeInt64(1);

  if (n & 1) Result *= x;
  n >>= 1;

  while(n) {
    if (x > HD_SQRT_INT64_MAX) return MakeInt64(0);
    x *= x;
    if (n & 1) Result *= x;
    n >>= 1;
  } /* End of while */

  return Result;
}


/**** Integer base 10 logarithm ****/

HD_INLINEEXTERN HD_INLINE HD_LONG ilog10(register int x)
{
  register HD_LONG      i;

  register HD_LONG      p = 1;

  for (i = -1; i <= 8; i++) {
   if (x < p) return i;
   p = (p << 3) + p + p;
  } /* End of for (i) */

  return i;
}


/**** Round a HD_FLOAT converting it to integer ****/

HD_INLINEEXTERN HD_INLINE HD_LONG Roundf(HD_FLOAT Val)
{
  HD_LONG       Res = (int)Val;

  if ((Val - (HD_FLOAT)Res) > 0.5f) ++Res;

  return Res;
}

#  undef extern
#endif
