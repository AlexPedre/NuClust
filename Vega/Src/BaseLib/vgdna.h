
/****************************************************
**** VEGA - Build DNA/RNA single/double stranded ****
****   Copyright 1996-2025, Alessandro Pedretti  ****
****************************************************/


#ifndef __VG_DNA_H
#  define __VG_DNA_H

/**** Helix types (Don't change the order!) ****/

#  define VG_DNA_ADNA                   0x00000000 /* Right handed A-DNA (Arnott)       */
#  define VG_DNA_ABDNA                  0x00000001 /* Right handed B-DNA (Arnott)       */
#  define VG_DNA_LBDNA                  0x00000002 /* Right handed B-DNA (Langridge)    */
#  define VG_DNA_SBDNA                  0x00000003 /* Left  handed B-DNA (Sasisekharan) */

#  define VG_RNA_ARNA                   0x01000000 /* Right handed A-RNA (Arnott)       */
#  define VG_RNA_APRNA                  0x01000001 /* Right handed A-PRIME RNA (Arnott) */

#  define VG_DNA_MASKID                 0x00ffffff
#  define VG_DNA_MASKTYPE               0xff000000

/**** Flags for DnaBuild() ****/

#  define  VG_DNA_BUILD_NONE            0           /* None                              */
#  define  VG_DNA_BUILD_RESERVED        1           /* Reserved                          */
#  define  VG_DNA_BUILD_ADDHYDROG       2           /* Add the hydrogens                 */
#  define  VG_DNA_BUILD_NORMALIZE       4           /* Normalize the coordinates         */
#  define  VG_DNA_BUILD_CHAIN35         8           /* Build 3' 5' chain                 */
#  define  VG_DNA_BUILD_CHAIN53        16           /* Build 5' 3' chain (*)             */

/**** Flags for DnaCheckSeq() ****/

#  define  VG_DNA_CHECKSEQ_NONE         0           /* None                              */
#  define  VG_DNA_CHECKSEQ_TODNA        1           /* Convert to DNA                    */
#  define  VG_DNA_CHECKSEQ_TORNA        2           /* Convert to RNA                    */

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_DnaBuild                        _VG_DnaBuild
#    define  VG_DnaBuildCmplSeq                 _VG_DnaBuildCmplSeq
#    define  VG_DnaCheckSeq                     _VG_DnaCheckSeq
#    define  VG_DnaId2Type                      _VG_DnaId2Type
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_ATOM *  VEGA_EXPORT VG_DnaBuild(VG_CTX *Ctx, const HD_CHAR *Seq, HD_LONG Type, HD_ATOM **LastAtom, HD_ULONG *TotAtm, HD_LONG Flags);
VEGA_EXTERN HD_STRING  VEGA_EXPORT VG_DnaBuildCmplSeq(const HD_CHAR *Str, HD_LONG Type);
VEGA_EXTERN HD_STRING  VEGA_EXPORT VG_DnaCheckSeq(const HD_CHAR *Seq, HD_LONG Flags);
VEGA_EXTERN HD_LONG    VEGA_EXPORT VG_DnaId2Type(HD_LONG Id);

#  ifdef __cplusplus
}
#  endif
#endif

