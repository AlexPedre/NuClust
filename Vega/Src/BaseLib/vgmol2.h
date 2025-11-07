
/*************************************************
****            VEGA - Mol2 header            ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_MOL2_H
#  define  __VG_MOL2_H
#  include <hdmemstream.h>

/**** Saver flags ****/

#  define  VG_MOL2FLG_NONE              0
#  define  VG_MOL2FLG_ACTIVEONLY        1
#  define  VG_MOL2FLG_CRLF              2
#  define  VG_MOL2FLG_LF                4
#  define  VG_MOL2FLG_REMARKS           8

/**** Constants ****/

#  define  VG_TRIPOS_TAG_ATOM           0
#  define  VG_TRIPOS_TAG_BOND           1
#  define  VG_TRIPOS_TAG_MOLECULE       2
#  define  VG_TRIPOS_TAG_SUBSTR         3
#  define  VG_TRIPOS_TAG_UNK            4

#  define  VG_TRIPOS_FIELDLEN           256
#  define  VG_TRIPOS_TEMPLATE           "TRIPOS"

/**** Flags for AssignTriposFF() ****/

#  define  VG_TRIPOS_FLG_NONE           0
#  define  VG_TRIPOS_FLG_CHKFF          1
#  define  VG_TRIPOS_FLG_PROG           2
#  define  VG_TRIPOS_FLG_ACTONLY        4

#  ifdef LITTLE_ENDIAN
#    define  VG_TRIPOS_ATM_CA           0x00004143
#    define  VG_TRIPOS_FF_C2            MakeInt64(0x0000000000322e43)
#    define  VG_TRIPOS_FF_Nam           MakeInt64(0x000000006d612e4e)
#    define  VG_TRIPOS_FF_Oco2          MakeInt64(0x000000326f632e4f)
#  else
#    define  VG_TRIPOS_ATM_CA           0x43410000
#    define  VG_TRIPOS_FF_C2            MakeInt64(0x432e320000000000)
#    define  VG_TRIPOS_FF_Nam           MakeInt64(0x4e2e616d00000000)
#    define  VG_TRIPOS_FF_Oco2          MakeInt64(0x4f2e636f32000000)
#  endif

/**** Global variables ****/

extern const HD_CHAR *     Mol2Tags[];

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_AssignTriposFF                  _VG_AssignTriposFF
#    define  VG_Mol2Load                        _VG_Mol2Load
#    define  VG_Mol2LoadMem                     _VG_Mol2LoadMem
#    define  VG_Mol2Save                        _VG_Mol2Save
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_BOOL      VEGA_EXPORT VG_AssignTriposFF(VG_CTX *Ctx, const HD_CHAR *, HD_LONG);
VEGA_EXTERN HD_ATOM *    VEGA_EXPORT VG_Mol2Load(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_BOOL *IsMulti);
VEGA_EXTERN HD_ATOM *    VEGA_EXPORT VG_Mol2LoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_BOOL *IsMulti);
VEGA_EXTERN HD_BOOL      VEGA_EXPORT VG_Mol2Save(VG_CTX *Ctx, FILE *FH, HD_STRING FileName, HD_LONG Flags);

#  ifdef __cplusplus
}
#  endif
#endif
