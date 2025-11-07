
/*************************************************
****            VEGA - PDB header            ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_PDB_H
#  define  __VG_PDB_H
#  include <hdmemstream.h>

#  include "vgtraj.h"

/**** Types ****/

typedef struct {
  HD_ULONG      NumConect;
  HD_ULONG      NumRec;
  HD_ULONG      NumRem;
  HD_ULONG      NumTer;
} VG_PDBNUM;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_PDBAllocLoadTable               _VG_PDBAllocLoadTable
#    define  VG_PDBOpen                         _VG_PDBOpen
#    define  VG_PDBQTSave                       _VG_PDBQTSave
#    define  VG_PDBReadFrm                      _VG_PDBReadFrm
#    define  VG_PDBSave                         _VG_PDBSave
#    define  VG_PDBSeekFrm                      _VG_PDBSeekFrm
#    define  VG_PDBWriteAtm                     _VG_PDBWriteAtm
#    define  VG_PDBWriteFooter                  _VG_PDBWriteFooter
#    define  VG_PDBWriteFrm                     _VG_PDBWriteFrm
#    define  VG_PDBWriteHeader                  _VG_PDBWriteHeader
#    define  VG_PDBClose                        _VG_PDBClose
#    define  VG_PDBSaveReset                    _VG_PDBSaveReset
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_ATOM **   VEGA_EXPORT VG_PDBAllocLoadTable(HD_ATOM *Atm, HD_ULONG MaxSerial);
VEGA_EXTERN HD_BOOL      VEGA_EXPORT VG_PDBOpen(const HD_CHAR *FileName, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL      VEGA_EXPORT VG_PDBQTSave(VG_CTX *Ctx, FILE *FH, HD_LONG SubFormat);
VEGA_EXTERN HD_BOOL      VEGA_EXPORT VG_PDBReadFrm(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL      VEGA_EXPORT VG_PDBSave(VG_CTX *Ctx, FILE *FH, HD_LONG Type);
VEGA_EXTERN HD_BOOL      VEGA_EXPORT VG_PDBSeekFrm(VG_TRJINFO *Info, HD_LONG Frames, HD_LONG Mode);
VEGA_EXTERN HD_BOOL      VEGA_EXPORT VG_PDBWriteAtm(VG_CTX *Ctx, VG_PDBNUM *PdbNum, FILE *FH, HD_ATOM *Atm, HD_WORD Type);
VEGA_EXTERN HD_BOOL      VEGA_EXPORT VG_PDBWriteFooter(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL      VEGA_EXPORT VG_PDBWriteFrm(VG_CTX *Ctx, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL      VEGA_EXPORT VG_PDBWriteHeader(VG_TRJINFO *Info);
VEGA_EXTERN HD_VOID      VEGA_EXPORT VG_PDBClose(VG_TRJINFO *Info);
VEGA_EXTERN VG_PDBNUM *  VEGA_EXPORT VG_PDBSaveReset(HD_ULONG StartRec);

#  ifdef __cplusplus
}
#  endif
#endif
