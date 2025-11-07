
/*************************************************
****   VEGA - Add side chains to aa backbone  ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_ADDCHAINS_H
#  define  __VG_ADDCHAINS_H

/**************************************
**** Atom names for fast access to ****
****     the HD_ATOM structure     ****
**************************************/


#ifdef LITTLE_ENDIAN
#  define VG_ATMNAME_HA                 0x00004148
#  define VG_ATMNAME_C                  0x00000043
#  define VG_ATMNAME_CA                 0x00004143
#  define VG_ATMNAME_CB                 0x00004243
#  define VG_ATMNAME_CD                 0x00004443
#  define VG_ATMNAME_N                  0x0000004e
#  define VG_ATMNAME_O                  0x0000004f
#  define VG_ATMNAME_P                  0x00000050
#else
#  define VG_ATMNAME_HA                 0x48410000
#  define VG_ATMNAME_C                  0x43000000
#  define VG_ATMNAME_CA                 0x43410000
#  define VG_ATMNAME_CB                 0x43420000
#  define VG_ATMNAME_CD                 0x43440000
#  define VG_ATMNAME_N                  0x4e000000
#  define VG_ATMNAME_O                  0x4f000000
#  define VG_ATMNAME_P                  0x50000000
#endif

/**** Flags for AddChainsAA() ****/

#  define  VG_ADDCHAINS_NONE            0
#  define  VG_ADDCHAINS_ACTIVEONLY      1
#  define  VG_ADDCHAINS_SHOWPROG        2

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_AddChainsAA                     _VG_AddChainsAA
#    define  VG_ChkAaChirality                  _VG_ChkAaChirality
#    define  VG_ChkPeptBond                     _VG_ChkPeptBond
#    define  VG_ChkResSeq                       _VG_ChkResSeq
#    define  VG_ChkRingIntersect                _VG_ChkRingIntersect
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_LONG         VEGA_EXPORT VG_AddChainsAA(VG_CTX *Ctx, HD_ATOM **InizAtm, HD_ATOM **LastAtom, HD_ULONG *TotAtm, HD_LONG Flags);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_ChkAaChirality(HD_ATOM *InizAtm);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_ChkPeptBond(HD_ATOM *InizAtm);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_ChkResSeq(HD_ATOM *Atm);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_ChkRingIntersect(HD_ATOM *InizAtm, HD_ULONG TotAtm);

#  ifdef __cplusplus
}
#  endif
#endif

