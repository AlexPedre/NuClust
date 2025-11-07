
/*************************************************
****        VEGA - CML loader & saver         ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_CML_H
#  define  __VG_CML_H
#  include <hdmemstream.h>

/**** Constants ****/

#  define  VG_CML_ID_START_SIZE                 512

/**** Bond ****/

typedef struct __vg_cmlbond {
  struct __vg_cmlbond * Next;
  struct __vg_cmlbond * Prev;
  HD_CHAR *             Id[2];
  HD_ATOM *             Atm[2];
  HD_CHAR               Order;
} VG_CML_BOND;

/**** ID ****/

typedef struct {
  HD_CHAR **    Beg;
  HD_ULONG      LastId;
  HD_ULONG      Size;
} VG_CMLIDS;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_CmlLoad                         _VG_CmlLoad
#    define  VG_CmlLoadMem                      _VG_CmlLoadMem
#    define  VG_CmlSave                         _VG_CmlSave
#    define  VG_CmlSave2                        _VG_CmlSave2
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_CmlLoad(VG_CTX *Ctx, FILE *FH, HD_ATOM **LastAtom, HD_ULONG *TotAtm);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_CmlLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, HD_ATOM **LastAtom, HD_ULONG *TotAtm);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_CmlSave(VG_CTX *Ctx, FILE *FH, HD_STRING FileName);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_CmlSave2(VG_CTX *Ctx, FILE *FH, HD_STRING FileName);

#  ifdef __cplusplus
}
#  endif
#endif

