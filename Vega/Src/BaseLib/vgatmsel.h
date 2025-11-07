
/*************************************************
****          VEGA - Atom selection           ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_ATMSEL_H
#  define  __VG_ATMSEL_H

/**** VG_AtmSelBackbone() flags ****/

#  define  VG_ATMSEL_BACKBONE_NONE              0
#  define  VG_ATMSEL_BACKBONE_DNA               1
#  define  VG_ATMSEL_BACKBONE_PROT              2
#  define  VG_ATMSEL_BACKBONE_ALL               (VG_ATMSEL_BACKBONE_DNA|VG_ATMSEL_BACKBONE_PROT)

/**** VG_AtmSelByAtm() flags ****/

#  define  VG_ATMSEL_BYATM_UNSEL                0       /* Unselect the atoms                   */
#  define  VG_ATMSEL_BYATM_SEL                  1       /* Select the atoms                     */
#  define  VG_ATMSEL_BYATM_ADD                  2       /* Additive un/selection                */
#  define  VG_ATMSEL_BYATM_ELEM                 4       /* Consider the elements for similarity */

/**** VG_AtmSelSup() what ****/

#  define VG_ATMSELSUP_NONE                     0       /* None                       */
#  define VG_ATMSELSUP_ATOMS                    1       /* Atoms                      */
#  define VG_ATMSELSUP_CA                       2       /* CA atoms                   */
#  define VG_ATMSELSUP_RESIDUES                 3       /* Residues                   */

/**** Proximity selection modes VG_AtmSelProximity() ****/

#  define  VG_GLSELWHAT_ATOM                    0
#  define  VG_GLSELWHAT_RESIDUE                 1
#  define  VG_GLSELWHAT_CHAIN                   2
#  define  VG_GLSELWHAT_MOLECULE                3

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE

#    define  VG_AtmSel                          _VG_AtmSel
#    define  VG_AtmSelAll                       _VG_AtmSelAll
#    define  VG_AtmSelApolHydrog                _VG_AtmSelApolHydrog
#    define  VG_AtmSelBackboneAll               _VG_AtmSelBackbone
#    define  VG_AtmSelByAtm                     _VG_AtmSelByAtm
#    define  VG_AtmSelByElem                    _VG_AtmSelByElem
#    define  VG_AtmSelConstrained               _VG_AtmSelConstrained
#    define  VG_AtmSelDNA                       _VG_AtmSelDNA
#    define  VG_AtmSelInv                       _VG_AtmSelInv
#    define  VG_AtmSelMatch                     _VG_AtmSelMatch
#    define  VG_AtmSelMatchFormatPattern        _VG_AtmSelMatchFormatPattern
#    define  VG_AtmSelPlane                     _VG_AtmSelPlane
#    define  VG_AtmSelProtein                   _VG_AtmSelProtein
#    define  VG_AtmSelProximity                 _VG_AtmSelProximity
#    define  VG_AtmSelRange                     _VG_AtmSelRange
#    define  VG_AtmSelSup                       _VG_AtmSelSup
#    define  VG_AtmSelWater                     _VG_AtmSelWater
#    define  VG_MolFind                         _VG_MolFind
#    define  VG_ResSel                          _VG_ResSel
#    define  VG_ResSelByAtm                     _VG_ResSelByAtm
#    define  VG_SegFind                         _VG_SegFind

#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_ULONG      VEGA_EXPORT VG_AtmSel(HD_ATOM *Atm, HD_CHAR *Sel, HD_UBYTE Val, HD_BOOL Add, HD_UBYTE *DrawMode, HD_UBYTE *ColorID);
VEGA_EXTERN HD_ULONG      VEGA_EXPORT VG_AtmSelAll(HD_ATOM *Atm, HD_BOOL Val);
VEGA_EXTERN HD_ULONG      VEGA_EXPORT VG_AtmSelApolHydrog(HD_ATOM *Atm, HD_UBYTE Val, HD_BOOL Add);
VEGA_EXTERN HD_ULONG      VEGA_EXPORT VG_AtmSelBackbone(HD_ATOM *Atm, HD_LONG What, HD_UBYTE Val, HD_BOOL ActOnly);
VEGA_EXTERN HD_ULONG      VEGA_EXPORT VG_AtmSelByAtm(VG_CTX *Ctx, HD_ATOM *SelAtm, HD_LONG What, HD_LONG Flags);
VEGA_EXTERN HD_ULONG      VEGA_EXPORT VG_AtmSelByElem(HD_ATOM *Atm, HD_UWORD Elem, HD_UBYTE Val, HD_BOOL Add);
VEGA_EXTERN HD_VOID       VEGA_EXPORT VG_AtmSelConstrained(HD_ATOM *Atm, HD_FLOAT Val);
VEGA_EXTERN HD_ULONG      VEGA_EXPORT VG_AtmSelDNA(HD_ATOM *InizAtm, HD_BOOL Add, HD_UBYTE *DrawMode, HD_UBYTE *ColorID);
VEGA_EXTERN HD_VOID       VEGA_EXPORT VG_AtmSelInv(HD_ATOM *Atm);
VEGA_EXTERN HD_BOOL       VEGA_EXPORT VG_AtmSelMatch(HD_ATOM *Atm, HD_CHAR **MyArg, HD_ULONG NumArgs, HD_CHAR *NMol);
VEGA_EXTERN HD_ULONG      VEGA_EXPORT VG_AtmSelMatchFormatPattern(HD_ULONG *AtmNum, HD_CHAR **MyArg, HD_CHAR *Ptr);
VEGA_EXTERN HD_ULONG      VEGA_EXPORT VG_AtmSelPlane(HD_ATOM *InizAtm, HD_LONG Plane, HD_FLOAT SliceThick, HD_FLOAT SlicePos, HD_UBYTE Val, HD_UWORD What, HD_BOOL Add, HD_UBYTE *DrawMode, HD_UBYTE *ColorID);
VEGA_EXTERN HD_ULONG      VEGA_EXPORT VG_AtmSelProtein(HD_ATOM *InizAtm, HD_BOOL Add, HD_UBYTE *DrawMode, HD_UBYTE *ColorID);
VEGA_EXTERN HD_ULONG      VEGA_EXPORT VG_AtmSelProximity(HD_ATOM *InizAtm, HD_CHAR *Sel, HD_FLOAT Rad, HD_UBYTE Val, HD_UWORD What, HD_BOOL Add, HD_UBYTE *DrawMode, HD_UBYTE *ColorID);
VEGA_EXTERN HD_ULONG      VEGA_EXPORT VG_AtmSelRange(HD_ATOM *Atm, HD_UWORD Mode, HD_ULONG Start, HD_ULONG End, HD_UBYTE Val, HD_BOOL Add, HD_UBYTE *DrawMode, HD_UBYTE *ColorID);
VEGA_EXTERN HD_ULONG      VEGA_EXPORT VG_AtmSelSup(VG_CTX *Ctx, HD_LONG What, HD_BOOL Val);
VEGA_EXTERN HD_ULONG      VEGA_EXPORT VG_AtmSelWater(HD_ATOM *Atm, HD_UBYTE Val, HD_BOOL Add);
VEGA_EXTERN HD_ULONG      VEGA_EXPORT VG_MolFind(VG_CTX *Ctx);
VEGA_EXTERN HD_ULONG      VEGA_EXPORT VG_ResSel(HD_ATOM *BegRes, HD_BOOL Val, HD_UBYTE *DrawMode, HD_UBYTE *ColorID);
VEGA_EXTERN HD_VOID       VEGA_EXPORT VG_ResSelByAtm(HD_ATOM *ResAtm, HD_BOOL Val);
VEGA_EXTERN HD_ULONG      VEGA_EXPORT VG_SegFind(VG_CTX *Ctx);

#  ifdef __cplusplus
}
#  endif
#endif
