
/*************************************************
****           VEGA - Ion arrangment          ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_ION_H
#  define  __VG_ION_H

#ifdef VEGA_ZZ

typedef struct {
  HD_ATOM *     InizAtm;
  HD_ATOM **    LastAtom;
  HD_ULONG *    TotAtomi;
  HD_CHAR *     Elem;
  HD_FLOAT      Charge;
  HD_ULONG      N_ions;
  HD_FLOAT      excl_atom_rad;
  HD_FLOAT      excl_ion_rad;
  HD_FLOAT      delta;
  HD_FLOAT      border_width;
} VG_IONPARAM;


/**** Prototypes ****/

#  ifdef VEGA_ZZ
#    ifdef __cplusplus
extern "C" {
#    endif

HD_LONG     HD_CALLBACK VG_RunAddIons(VG_IONPARAM *IParam);
HD_VOID     HD_FASTCALL VG_RunAddIonsCallBack(HD_VOID *Arg);

#    ifdef __cplusplus
}
#    endif
#  endif
#endif

#endif

