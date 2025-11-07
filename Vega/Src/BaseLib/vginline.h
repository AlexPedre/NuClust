
/*************************************************
****         VEGA - Inline functions          ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_INLINE_H
#  define  __VG_INLINE_H

#include "vgfastmath64.h"


/**** Fast HD_FLOAT absolute value ****/

#  ifdef __BORLANDC__
static VG_INLINE HD_FLOAT HD_FASTCALL INL_fabsf(HD_FLOAT f)
{
  HD_LONG       i = ((*(int *)&f) & 0x7fffffff);

  return (*(HD_FLOAT *)&i);
}
#  else
#    define  INL_fabsf      fabsf
#  endif


/**** Check if a HD_FLOAT is NaN ****/

static VG_INLINE HD_BOOL INL_IsNanf(HD_FLOAT n)
{
  return (n != n);
}


/**** Check if a double is NaN ****/

static VG_INLINE HD_BOOL INL_IsNan(HD_DOUBLE n)
{
  return (n != n);
}


/**** Integer power of 2 ****/

static VG_INLINE HD_LONG HD_FASTCALL INL_Pow2i(HD_ULONG Exp)
{
  return (1 << Exp);
}


/**** Integer power of 10 ****/

static VG_INLINE HD_FLOAT HD_FASTCALL INL_Pow10f(HD_LONG p)
{
  register HD_FLOAT        Val = 1.0f;

  while(p--) Val *= 10.0f;

  return Val;
}


/**** Integer power ****/

static VG_INLINE HD_LONG HD_FASTCALL INL_Powi(HD_LONG Base, HD_ULONG Exp)
{
  if (!Exp) return 1;

  while(--Exp) Base *= Base;

  return Base;
}


/**** Square distance ****/

static VG_INLINE HD_FLOAT HD_FASTCALL INL_SquareDist(HD_ATOM *Atm1, HD_ATOM *Atm2)
{
  HD_FLOAT        R, T;

  R  = Atm1 -> x - Atm2 -> x;
  R *= R;
  T  = Atm1 -> y - Atm2 -> y;
  R += T * T;
  T  = Atm1 -> z - Atm2 -> z;

  return (R + T * T);
}


/**** Change the endian ****/

static VG_INLINE HD_VOID HD_FASTCALL INL_Swap(HD_VOID *Val)
{
  HD_UBYTE    T;

  T = ((HD_UBYTE *)Val)[0];
  ((HD_UBYTE *)Val)[0] = ((HD_UBYTE *)Val)[3];
  ((HD_UBYTE *)Val)[3] = T;
  T = ((HD_UBYTE *)Val)[1];
  ((HD_UBYTE *)Val)[1] = ((HD_UBYTE *)Val)[2];
  ((HD_UBYTE *)Val)[2] = T;
}


/**** Vectorial cross product ****/

static VG_INLINE HD_VOID HD_FASTCALL INL_XyzCrossProd(HD_XYZF *Normal, HD_XYZF *Vect1, HD_XYZF *Vect2)
{
  Normal -> x = Vect1 -> y * Vect2 -> z - Vect2 -> y * Vect1 -> z;
  Normal -> y = Vect2 -> x * Vect1 -> z - Vect1 -> x * Vect2 -> z;
  Normal -> z = Vect1 -> x * Vect2 -> y - Vect2 -> x * Vect1 -> y;
}


/**** Normalize the single precision vector ****/

static VG_INLINE HD_VOID HD_FASTCALL ILN_XyzNormalize(HD_XYZF *V0)
{
  HD_FLOAT        Mag = V0 -> x * V0 -> x + V0 -> y * V0 -> y +
                        V0 -> z * V0 -> z;

  if (!Mag) return;

  Mag = (HD_FLOAT)SQR(1.0f / Mag);
  V0 -> x *= Mag;
  V0 -> y *= Mag;
  V0 -> z *= Mag;
}
#endif

