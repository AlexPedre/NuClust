/*********************************************
****      HyperDrive - SSE routines       ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#if !defined(__HD_SSE_H) && defined(HD_USE_SSE)
#  define  __HD_SSE_H

#  if defined(__BORLANDC__) && defined(_WIN64)
#    define  eax                rax
#    define  HD_BIN(X)          0b##X
#    define  movd               mov
#  else
#    define  HD_BIN(X)          X##b
#  endif
#endif
