
/*************************************************
****       VEGA - Fasta loader & saver        ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_FASTA_H
#  define  __VG_FASTA_H

#  include <hdseq.h>
#  include <hdlist.h>

/**** Flags to build a peptide ****/

#  define  VG_FASTA_BUILD_NONE          0       /* None                                     */
#  define  VG_FASTA_BUILD_ADDCHAINS     1       /* Add the side chains                      */
#  define  VG_FASTA_BUILD_ADDHYDROG     2       /* Add the hydrogens                        */
#  define  VG_FASTA_BUILD_NORMALIZE     4       /* Normalize the coordinates                */
#  define  VG_FASTA_BUILD_THREECHAR     8       /* Three character residue names            */

/**** N-Term capping ****/

#  define  VG_FASTA_NTERM_NONE          0       /* None/hydrogen (Don't change the order !) */
#  define  VG_FASTA_NTERM_NH3           1       /* NH3+                                     */
#  define  VG_FASTA_NTERM_NHCOH         2       /* NHC(=O)H                                 */
#  define  VG_FASTA_NTERM_NHCOCH3       3       /* NHC(=O)CH3                               */

#  define  VG_FASTA_NTERM_DEFAULT       VG_FASTA_NTERM_NH3

/**** C-Term capping ****/

#  define  VG_FASTA_CTERM_NONE          0       /* None/hydrogen (Don't change the order !)  */
#  define  VG_FASTA_CTERM_O             1       /* O-                                        */
#  define  VG_FASTA_CTERM_OH            2       /* OH                                        */
#  define  VG_FASTA_CTERM_OME           3       /* OCH3                                      */
#  define  VG_FASTA_CTERM_OET           4       /* OC2H5                                     */
#  define  VG_FASTA_CTERM_NH2           5       /* NH2                                       */

#  define  VG_FASTA_CTERM_DEFAULT       VG_FASTA_CTERM_O

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_FastaBuildStr                   _VG_FastaBuildStr
#    define  VG_FastaLoad                       _VG_FastaLoad
#    define  VG_FastaSave                       _VG_FastaSave
#    define  VG_GetSequence                     _VG_GetSequence
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_ATOM *  VEGA_EXPORT VG_FastaBuildStr(VG_CTX *Ctx, const HD_CHAR *Str, HD_ATOM **LastAtom, HD_ULONG *TotAtomi,
                                                    HD_FLOAT Phi, HD_FLOAT Psi, HD_FLOAT Omega, const HD_CHAR *SecStructPattern,
                                                    HD_LONG SecStructFlags, HD_LONG NTermCap, HD_LONG CTermCap, HD_LONG Flags);
VEGA_EXTERN HD_ATOM *  VEGA_EXPORT VG_FastaLoad(VG_CTX *Ctx, const HD_CHAR *FileName, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_FastaSave(VG_CTX *Ctx, FILE *FH, HD_STRING FileName);
VEGA_EXTERN HD_CHAR *  VEGA_EXPORT VG_GetSequence(HD_ATOM *Atm);

#  ifdef __cplusplus
}
#  endif
#endif

