
/*************************************************
****    VEGA - Matrix functions for OpenGL    ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef  __GL_MATRIX
#  define  __GL_MATRIX

#  include <hdmatrix.h>

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  GL_Mat4RotXYZ                      _GL_Mat4RotXYZ
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_VOID VEGA_EXPORT     GL_Mat4RotXYZ(HD_LONG a, HD_LONG b, HD_LONG c, HD_DOUBLE Theta, HD_MTX4X4F *A);

#  ifdef __cplusplus
}
#  endif
#endif
