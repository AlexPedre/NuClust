
/*************************************************
****           VEGA - Loader module           ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_LOADER_H
#  define  __VG_LOADER_H

#  include <hdmemstream.h>

#  include "vgformats.h"
#  include "vgiff.h"
#  include "vgligen.h"
#  include "vgmdlmol.h"
#  include "vgmemio.h"
#  include "vgpdb.h"

/**** Loader() flags ****/

#  define  VG_LOADER_NONE           0
#  define  VG_LOADER_NODLGTRJANA    1

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_AlchemyLoad                     _VG_AlchemyLoad
#    define  VG_AlchemyLoadMem                  _VG_AlchemyLoadMem
#    define  VG_CarLoad                         _VG_CarLoad
#    define  VG_CarLoadMem                      _VG_CarLoadMem
#    define  VG_CdxLoad                         _VG_CdxLoad
#    define  VG_CdxLoadMem                      _VG_CdxLoadMem
#    define  VG_Chem3dLoad                      _VG_Chem3dLoad
#    define  VG_Chem3dLoadMem                   _VG_Chem3dLoadMem
#    define  VG_ChemSolLoad                     _VG_ChemSolLoad
#    define  VG_ChemSolLoadMem                  _VG_ChemSolLoadMem
#    define  VG_CifLoad                         _VG_CifLoad
#    define  VG_CifLoadMem                      _VG_CifLoadMem
#    define  VG_CRDLoad                         _VG_CRDLoad
#    define  VG_CRDLoadMem                      _VG_CRDLoadMem
#    define  VG_CrtLoad                         _VG_CrtLoad
#    define  VG_CrtLoadMem                      _VG_CrtLoadMem
#    define  VG_CSSRLoad                        _VG_CSSRLoad
#    define  VG_CSSRLoadMem                     _VG_CSSRLoadMem
#    define  VG_EmpireCarLoad                   _VG_EmpireCarLoad
#    define  VG_EmpireCarLoadMem                _VG_EmpireCarLoadMem
#    define  VG_GamessLoad                      _VG_GamessLoad
#    define  VG_GamessLoadMem                   _VG_GamessLoadMem
#    define  VG_GamessOutLoad                   _VG_GamessOutLoad
#    define  VG_GamessOutLoadMem                _VG_GamessOutLoadMem
#    define  VG_GaussCarInLoad                  _VG_GaussCarInLoad
#    define  VG_GaussCarInLoadMem               _VG_GaussCarInLoadMem
#    define  VG_GaussOutLoad                    _VG_GaussOutLoad
#    define  VG_GaussOutLoadMem                 _VG_GaussOutLoadMem
#    define  VG_GromosLoad                      _VG_GromosLoad
#    define  VG_GromosLoadMem                   _VG_GromosLoadMem
#    define  VG_HINLoad                         _VG_HINLoad
#    define  VG_HINLoadMem                      _VG_HINLoadMem
#    define  VG_Loader                          _VG_Loader
#    define  VG_LoaderMem                       _VG_LoaderMem
#    define  VG_MoPacArcLoad                    _VG_MoPacArcLoad
#    define  VG_MoPacArcLoadMem                 _VG_MoPacArcLoadMem
#    define  VG_MoPacCarLoad                    _VG_MoPacCarLoad
#    define  VG_MoPacCarLoadMem                 _VG_MoPacCarLoadMem
#    define  VG_MoPacZmatLoad                   _VG_MoPacZmatLoad
#    define  VG_MoPacZmatLoadMem                _VG_MoPacZmatLoadMem
#    define  VG_MsfLoad                         _VG_MsfLoad
#    define  VG_MsfLoadMem                      _VG_MsfLoadMem
#    define  VG_NamdBinCheck                    _VG_NamdBinCheck
#    define  VG_NamdBinCheckMem                 _VG_NamdBinCheckMem
#    define  VG_NamdBinLoad                     _VG_NamdBinLoad
#    define  VG_NamdBinLoadMem                  _VG_NamdBinLoadMem
#    define  VG_PDBLoad                         _VG_PDBLoad
#    define  VG_PDBLoadMem                      _VG_PDBLoadMem
#    define  VG_PDBQTLoad                       _VG_PDBQTLoad
#    define  VG_PDBQTLoadMem                    _VG_PDBQTLoadMem
#    define  VG_PqrXmlLoad                      _VG_PqrXmlLoad
#    define  VG_PqrXmlLoadMem                   _VG_PqrXmlLoadMem
#    define  VG_PsfLoad                         _VG_PsfLoad
#    define  VG_PsfLoadMem                      _VG_PsfLoadMem
#    define  VG_TinkerXyzLoad                   _VG_TinkerXyzLoad
#    define  VG_TinkerXyzLoadMem                _VG_TinkerXyzLoadMem
#    define  VG_XyzLoad                         _VG_XyzLoad
#    define  VG_XyzLoadMem                      _VG_XyzLoadMem
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_AlchemyLoad(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_AlchemyLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_CarLoad(VG_CTX *Ctx, FILE *CARIN, VG_RECORD *CarLin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_BOOL *IsArc);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_CarLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *CarLin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_BOOL *IsArc);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_CdxLoad(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_CdxLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_Chem3dLoad(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_Chem3dLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_ChemSolLoad(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_ChemSolLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_CifLoad(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_LONG *FrmID, HD_BOOL *IsMulti);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_CifLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_LONG *FrmID, HD_BOOL *IsMulti);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_CRDLoad(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_CRDLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_CrtLoad(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_CrtLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_CSSRLoad(VG_CTX *Ctx, FILE *CSSRIN, VG_RECORD *CSSRLin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_UWORD SubForm);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_CSSRLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *CSSRLin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_UWORD SubForm);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_EmpireCarLoad(VG_CTX *Ctx, FILE *ARCIN, VG_RECORD *ARCLin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_EmpireCarLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *ARCLin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_GamessLoad(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_GamessLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_GamessOutLoad(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_GamessOutLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_GaussCarInLoad(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_BOOL NonStd);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_GaussCarInLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_BOOL NonStd);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_GaussOutLoad(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_GaussOutLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_GromosLoad(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_GromosLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_HINLoad(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_HINLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_Loader(VG_CTX *Ctx, const HD_CHAR *MolFile, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_LIST **Srf, HD_LONG *FormatID, HD_UWORD *FormatTrj, HD_ULONG NMol, HD_LONG Flags);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_LoaderMem(VG_CTX *Ctx, const HD_VOID *MemPtr, HD_ULONG Size, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_LIST **Srf, HD_LONG *FormatID, HD_UWORD *FormatTrj, HD_ULONG NMol, HD_LONG Flags);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_MoPacArcLoad(VG_CTX *Ctx, FILE *ARCIN, VG_RECORD *ARCLin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_MoPacArcLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *ARCLin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_MoPacCarLoad(VG_CTX *Ctx, FILE *ARCIN, VG_RECORD *ARCLin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_MoPacCarLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *ARCLin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_MoPacZmatLoad(VG_CTX *Ctx, FILE *ARCIN, VG_RECORD *ARCLin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_MoPacZmatLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *ARCLin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_MsfLoad(VG_CTX *Ctx, FILE *FH, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_MsfLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_NamdBinCheck(FILE *FH, HD_BOOL *SwapEndian);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_NamdBinCheckMem(HD_MEMSTREAM hStream, HD_BOOL *SwapEndian);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_NamdBinLoad(VG_CTX *Ctx, FILE *FH, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_NamdBinLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, HD_ATOM **LastAtom, HD_ULONG *TotAtom);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_PDBLoad(VG_CTX *Ctx, FILE *PDBIN, VG_RECORD *PDBLin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_LONG *FormatID, HD_BOOL *IsMulti);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_PDBLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *PDBLin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_LONG *FormatID, HD_BOOL *IsMulti);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_PDBQTLoad(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, VG_ATMSEL **InizSelect, VG_ATMSEL **LastSelect, HD_BOOL *IsMulti);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_PDBQTLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, VG_ATMSEL **InizSelect, VG_ATMSEL **LastSelect, HD_BOOL *IsMulti);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_PqrXmlLoad(VG_CTX *Ctx, FILE *FH, HD_ATOM **LastAtom, HD_ULONG *TotAtm);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_PqrXmlLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, HD_ATOM **LastAtom, HD_ULONG *TotAtm);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_PsfLoad(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_PsfLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_TinkerXyzLoad(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_TinkerXyzLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_XyzLoad(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_XyzLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);

#  ifdef __cplusplus
}
#  endif
#endif

