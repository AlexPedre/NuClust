
/*********************************************
****  HyperDrive - Floating point macros  ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifdef HD_FP
#  undef HD_FP
#  undef HD_VP
#  undef HD_UP

#  undef HD_FLOAT_INT

#  undef HD_MTX_DATAEELEM
#  undef HD_MTX_DATALEN
#  undef HD_MTX_FUNC
#  undef HD_MTX2X2_FUNC
#  undef HD_MTX3X3_FUNC
#  undef HD_MTX4X4_FUNC
#  undef HD_MTX_VAL

#  undef HD_VECT2_FUNC
#  undef HD_VECT3_FUNC
#  undef HD_VECT4_FUNC
#  undef HD_VECT4_FUNCF
#endif

#ifdef HD_SINGLE_PRECISION
#  define  HD_FP(X)                     X ## f
#  define  HD_UP(X)                     X ## _F
#  define  HD_VP(X)                     X ## F

#  define  HD_FLOAT_INT                 float

#  define  HD_MTX_DATAEELEM             HD_Mtxf_DataElem
#  define  HD_MTX_DATALEN               HD_Mtxf_DataLen
#  define  HD_MTX_FUNC(FUNC)            HD_Mtxf_ ## FUNC
#  define  HD_MTX2X2_FUNC(FUNC)         HD_Mtx2x2f_ ## FUNC
#  define  HD_MTX3X3_FUNC(FUNC)         HD_Mtx3x3f_ ## FUNC
#  define  HD_MTX4X4_FUNC(FUNC)         HD_Mtx4x4f_ ## FUNC
#  define  HD_MTX_VAL                   HD_Mtxf_Val

#  define  HD_VECT2_FUNC(FUNC)          HD_Vect2f_ ## FUNC
#  define  HD_VECT3_FUNC(FUNC)          HD_Vect3f_ ## FUNC
#  define  HD_VECT4_FUNC(FUNC)          HD_Vect4f_ ## FUNC
#  define  HD_VECT4_FUNCF(FUNC)         HD_Vect4f_ ## FUNC ## f

#else

#  define  HD_FP(X)                     X
#  define  HD_UP(X)                     X
#  define  HD_VP(X)                     X
#  define  HD_FLOAT_INT                 double

#  define  HD_MTX_DATAEELEM             HD_Mtx_DataElem
#  define  HD_MTX_DATALEN               HD_Mtx_DataLen
#  define  HD_MTX_FUNC(FUNC)            HD_Mtx_ ## FUNC
#  define  HD_MTX2X2_FUNC(FUNC)         HD_Mtx2x2_ ## FUNC
#  define  HD_MTX3X3_FUNC(FUNC)         HD_Mtx3x3_ ## FUNC
#  define  HD_MTX4X4_FUNC(FUNC)         HD_Mtx4x4_ ## FUNC
#  define  HD_MTX_VAL                   HD_Mtx_Val

#  define  HD_VECT2_FUNC(FUNC)          HD_Vect2_ ## FUNC
#  define  HD_VECT3_FUNC(FUNC)          HD_Vect3_ ## FUNC
#  define  HD_VECT4_FUNC(FUNC)          HD_Vect4_ ## FUNC
#  define  HD_VECT4_FUNCF(FUNC)         HD_Vect4_ ## FUNC
#endif
