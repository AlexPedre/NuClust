
/*************************************************
****    VEGA - Atom list managment routines   ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_ATOM_H
#  define  __VG_ATOM_H

/*************************************
**** Elements for fast access the ****
****      HD_ATOM structure       ****
*************************************/

#  ifdef LITTLE_ENDIAN
#    define  VG_ELEM_C                    0x0043
#    define  VG_ELEM_H                    0x0048
#    define  VG_ELEM_D                    0x0044
#    define  VG_ELEM_T                    0x0054
#    define  VG_ELEM_O                    0x004f
#    define  VG_ELEM_N                    0x004e
#    define  VG_ELEM_S                    0x0053
#    define  VG_ELEM_P                    0x0050
#    define  VG_ELEM_AS                   0x5341
#    define  VG_ELEM_B                    0x0042
#    define  VG_ELEM_F                    0x0046
#    define  VG_ELEM_CL                   0x6c43
#    define  VG_ELEM_BR                   0x7242
#    define  VG_ELEM_I                    0x0049
#    define  VG_ELEM_LI                   0x494c
#    define  VG_ELEM_NA                   0x414e
#    define  VG_ELEM_K                    0x004b
#    define  VG_ELEM_MG                   0x474d
#    define  VG_ELEM_CA                   0x4143
#    define  VG_ELEM_BA                   0x4142
#    define  VG_ELEM_AL                   0x4c41
#    define  VG_ELEM_ZN                   0x4e5a
#    define  VG_ELEM_PB                   0x4250
#    define  VG_ELEM_BI                   0x4942
#    define  VG_ELEM_HG                   0x4748
#    define  VG_ELEM_CU                   0x5543
#    define  VG_ELEM_AG                   0x4741
#    define  VG_ELEM_XC                   0x6358
#    define  VG_ELEM_DU                   0x5544

/**** Atom names ****/

#    define  VG_ATMNAME_C                 0x00000043
#    define  VG_ATMNAME_CA                0x00004143
#    define  VG_ATMNAME_CB                0x00004243
#    define  VG_ATMNAME_C1                0x00003143
#    define  VG_ATMNAME_C2                0x00003243
#    define  VG_ATMNAME_C3                0x00003343
#    define  VG_ATMNAME_H                 0x00000048
#    define  VG_ATMNAME_HO                0x00004f48
#    define  VG_ATMNAME_N                 0x0000004e
#    define  VG_ATMNAME_NT                0x0000544e
#    define  VG_ATMNAME_O                 0x0000004f
#    define  VG_ATMNAME_O1                0x0000314f
#    define  VG_ATMNAME_OXT               0x0054584f

/**** Residue names ****/

#    define  VG_RES_HOH                   0x00484f48
#  else
#    define  VG_ELEM_C                    0x4300
#    define  VG_ELEM_H                    0x4800
#    define  VG_ELEM_D                    0x4400
#    define  VG_ELEM_T                    0x5400
#    define  VG_ELEM_O                    0x4f00
#    define  VG_ELEM_N                    0x4e00
#    define  VG_ELEM_S                    0x5300
#    define  VG_ELEM_P                    0x5000
#    define  VG_ELEM_AS                   0x4153
#    define  VG_ELEM_B                    0x4200
#    define  VG_ELEM_F                    0x4600
#    define  VG_ELEM_CL                   0x436c
#    define  VG_ELEM_BR                   0x4272
#    define  VG_ELEM_I                    0x4900
#    define  VG_ELEM_LI                   0x4c49
#    define  VG_ELEM_NA                   0x4e41
#    define  VG_ELEM_K                    0x4b00
#    define  VG_ELEM_MG                   0x4d47
#    define  VG_ELEM_CA                   0x4341
#    define  VG_ELEM_BA                   0x4241
#    define  VG_ELEM_AL                   0x414c
#    define  VG_ELEM_ZN                   0x5a4e
#    define  VG_ELEM_PB                   0x5042
#    define  VG_ELEM_BI                   0x4249
#    define  VG_ELEM_HG                   0x4847
#    define  VG_ELEM_CU                   0x4355
#    define  VG_ELEM_AG                   0x4147
#    define  VG_ELEM_XC                   0x5863
#    define  VG_ELEM_DU                   0x4455

/**** Atom names ****/

#    define  VG_ATMNAME_C                 0x43000000
#    define  VG_ATMNAME_CA                0x43410000
#    define  VG_ATMNAME_CB                0x43420000
#    define  VG_ATMNAME_C1                0x43310000
#    define  VG_ATMNAME_C2                0x43320000
#    define  VG_ATMNAME_C3                0x43330000
#    define  VG_ATMNAME_H                 0x48000000
#    define  VG_ATMNAME_HO                0x484f0000
#    define  VG_ATMNAME_N                 0x4e000000
#    define  VG_ATMNAME_NT                0x4e540000
#    define  VG_ATMNAME_O                 0x4f000000
#    define  VG_ATMNAME_O1                0x4f310000
#    define  VG_ATMNAME_OXT               0x4f585400

/**** Residue names ****/

#    define  VG_RES_HOH                   0x484f4800
#  endif


/**** What argument of GL_SelectByAtm() ****/

#  define  VG_SELBYATM_NONE               0
#  define  VG_SELBYATM_ATOM               1
#  define  VG_SELBYATM_BOND               2
#  define  VG_SELBYATM_RESIDUE            3
#  define  VG_SELBYATM_CHAIN              4
#  define  VG_SELBYATM_SEGMENT            5
#  define  VG_SELBYATM_MOLECULE           6

/**** Undo buffer ****/

typedef struct {
  HD_ULONG          Num;            /* Atom number                 */
  HD_QCHAR          Name;           /* Atom name                   */
  HD_QCHAR          Ring;           /* Ring indicator              */
  HD_QCHAR          ResName;        /* Residue name                */
  HD_QCHAR          ResSeq;         /* Number of residue           */
  HD_FLOAT          x, y, z;        /* X, Y, Z coodinates          */
  HD_FLOAT          Charge;         /* Atomic charge               */
  HD_FLOAT          Fix;            /* Fixing parameter            */
  HD_OCHAR          Pot;            /* Atom type (potential)       */
  HD_DCHAR          Elem;           /* Element                     */
  HD_BYTE           ChainID;        /* Chain indicator             */
  HD_UBYTE          ColorID;        /* Color ID (OpenGL)           */
} VG_PUSH_ATOMO;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_AmmpLoad                        _VG_AmmpLoad
#    define  VG_AllocAtm                        _VG_AllocAtm
#    define  VG_AllocAtmFirst                   _VG_AllocAtmFirst
#    define  VG_Atm2Str                         _VG_Atm2Str
#    define  VG_AtmExclude                      _VG_AtmExclude
#    define  VG_AtmExcludeRm                    _VG_AtmExcludeRm
#    define  VG_AtmIsBackbone                   _VG_AtmIsBackbone
#    define  VG_AtmIsBackboneDNA                _VG_AtmIsBackboneDNA
#    define  VG_AtmIsBackboneProt               _VG_AtmIsBackboneProt
#    define  VG_AtmValence                      _VG_AtmValence

#    define  VG_CentroidAdd                     _VG_CentroidAdd
#    define  VG_CentroidAddAtm                  _VG_CentroidAddAtm
#    define  VG_CentroidFix                     _VG_CentroidFix
#    define  VG_CentroidRemAll                  _VG_CentroidRemAll
#    define  VG_CentroidUpdate                  _VG_CentroidUpdate
#    define  VG_CentroidUpdateAll               _VG_CentroidUpdateAll

#    define  VG_CloneAtms                       _VG_CloneAtms
#    define  VG_DuplicateAtms                   _VG_DuplicateAtms

#    define  VG_FindAtmByNum                    _VG_FindAtmByNum
#    define  VG_FindByAtm                       _VG_FindByAtm
#    define  VG_FindChainByAtm                  _VG_FindChainByAtm
#    define  VG_FindMoleculeByAtm               _VG_FindMoleculeByAtm
#    define  VG_FindMoleculeByID                _VG_FindMoleculeByID
#    define  VG_FindResByAtm                    _VG_FindResByAtm
#    define  VG_FindSegmentByAtm                _VG_FindSegmentByAtm

#    define  VG_FreeAtm                         _VG_FreeAtm
#    define  VG_GetAtmFullName                  _VG_GetAtmFullName
#    define  VG_InsertAtm                       _VG_InsertAtm
#    define  VG_Is2D                            _VG_Is2D
#    define  VG_LinkAtm                         _VG_LinkAtm

#    define  VG_PopActiveAtm                    _VG_PopActiveAtm
#    define  VG_PopAtmSeq                       _VG_PopAtmSeq
#    define  VG_PopAtom                         _VG_PopAtom
#    define  VG_PopBndOrd                       _VG_PopBndOrd
#    define  VG_PopChainID                      _VG_PopChainID
#    define  VG_PopCharges                      _VG_PopCharges
#    define  VG_PopChiral                       _VG_PopChiral
#    define  VG_PopConnect                      _VG_PopConnect
#    define  VG_PopCoord                        _VG_PopCoord
#    define  VG_PopDrawMode                     _VG_PopDrawMode
#    define  VG_PopElem                         _VG_PopElem
#    define  VG_PopFix                          _VG_PopFix
#    define  VG_PopFlags                        _VG_PopFlags
#    define  VG_PopFlagsOo                      _VG_PopFlagsOo
#    define  VG_PopLabel                        _VG_PopLabel
#    define  VG_PopName                         _VG_PopName
#    define  VG_PopNSost                        _VG_PopNSost
#    define  VG_PopResName                      _VG_PopResName
#    define  VG_PopResSeq                       _VG_PopResSeq

#    define  VG_PushActiveAtm                   _VG_PushActiveAtm
#    define  VG_PushAtmSeq                      _VG_PushAtmSeq
#    define  VG_PushAtom                        _VG_PushAtom
#    define  VG_PushBndOrd                      _VG_PushBndOrd
#    define  VG_PushChainID                     _VG_PushChainID
#    define  VG_PushCharges                     _VG_PushCharges
#    define  VG_PushChiral                      _VG_PushChiral
#    define  VG_PushConnect                     _VG_PushConnect
#    define  VG_PushCoord                       _VG_PushCoord
#    define  VG_PushDrawMode                    _VG_PushDrawMode
#    define  VG_PushElem                        _VG_PushElem
#    define  VG_PushFix                         _VG_PushFix
#    define  VG_PushFlags                       _VG_PushFlags
#    define  VG_PushFlagsOo                     _VG_PushFlagsOo
#    define  VG_PushLabel                       _VG_PushLabel
#    define  VG_PushName                        _VG_PushName
#    define  VG_PushNSost                       _VG_PushNSost
#    define  VG_PushResName                     _VG_PushResName
#    define  VG_PushResSeq                      _VG_PushResSeq

#    define  VG_RemoveAtmMatch                  _VG_RemoveAtmMatch
#    define  VG_RemoveByAtm                     _VG_RemoveByAtm
#    define  VG_RemoveCounterIons               _VG_RemoveCounterIons
#    define  VG_RemoveSingleAtm                 _VG_RemoveSingleAtm
#    define  VG_RemoveVisAtm                    _VG_RemoveVisAtm
#    define  VG_RenAtm                          _VG_RenAtm
#    define  VG_Res2Str                         _VG_Res2Str
#    define  VG_SetAtmName                      _VG_SetAtmName
#    define  VG_SortAtmByRes                    _VG_SortAtmByRes
#    define  VG_UnlinkAtm                       _VG_UnlinkAtm
#    define  VG_WaterExclude                    _VG_WaterExclude
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_AllocAtm(VG_CTX *Ctx, HD_ATOM **InizAtm, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_AllocAtmFirst(HD_ATOM **InizAtm, HD_ULONG *TotAtomi, HD_BOOL Renumber);
VEGA_EXTERN HD_CHAR *       VEGA_EXPORT VG_Atm2Str(VG_CTX *Ctx, HD_CHAR *Dest, HD_ATOM *Atm);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_AtmExclude(HD_ATOM *Atm);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_AtmExcludeRm(HD_ATOM *Atm);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_AtmIsBackbone(HD_ATOM *Atm);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_AtmIsBackboneDNA(HD_ATOM *Atm);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_AtmIsBackboneProt(HD_ATOM *Atm);
VEGA_EXTERN HD_LONG         VEGA_EXPORT VG_AtmValence(HD_ATOM *Atm);

VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_CentroidAdd(VG_CTX *Ctx, HD_ATOM *ParentAtm, HD_BOOL Fix);
VEGA_EXTERN HD_LONG         VEGA_EXPORT VG_CentroidAddAtm(HD_ATOM *Ctr, HD_ATOM *Atm);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_CentroidFix(HD_ATOM *Atm);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_CentroidRemAll(VG_CTX *Ctx, HD_ATOM **InizAtm, HD_ULONG *TotAtm);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_CentroidUpdate(HD_ATOM *Atm);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_CentroidUpdateAll(HD_ATOM *Atm);

VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_CloneAtms(HD_ATOM **LastAtomo, HD_ATOM *Src, HD_ULONG TotAtm);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_DuplicateAtms(VG_CTX *Ctx, HD_ATOM *Src, HD_ULONG TotAtm);

VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_FindAtmByNum(VG_CTX *Ctx, HD_ULONG Num);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_FindByAtm(VG_CTX *Ctx, HD_ATOM **LstAtm, HD_ULONG *NumAtm, HD_ATOM *SelAtm, HD_LONG What);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_FindChainByAtm(VG_CTX *Ctx, HD_ATOM *ChainAtm, HD_ATOM **LstAtm, HD_ULONG *ChainLen);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_FindMoleculeByAtm(VG_CTX *Ctx, HD_ATOM *MolAtm, HD_ATOM **LstAtm, HD_ULONG *MolLen);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_FindMoleculeByID(VG_CTX * Ctx, HD_ULONG Id, HD_ATOM **LstAtm, HD_ULONG *MolLen);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_FindResByAtm(VG_CTX *Ctx, HD_ATOM *ResAtm, HD_ATOM **LstAtm, HD_ULONG *ResLen);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_FindSegmentByAtm(VG_CTX *Ctx, HD_ATOM *SegAtm, HD_ATOM **LstAtm, HD_ULONG *SegLen);

VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_FreeAtm(HD_ATOM *Atm);
VEGA_EXTERN HD_CHAR *       VEGA_EXPORT VG_GetAtmFullName(VG_CTX *Ctx, HD_CHAR *Dest, HD_ATOM *Atm);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_InsertAtm(HD_ATOM *PrecAtm, HD_ULONG *TotAtomi, HD_ATOM **LastAtom);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_Is2D(HD_ATOM *Atm, HD_BOOL HevAtmOnly);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_LinkAtm(HD_ATOM *Atm, HD_ATOM *PrevAtm, HD_ATOM **InizAtm, HD_ULONG *TotAtm, HD_ATOM **LastAtm);

VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_PopActiveAtm(HD_ATOM *Atm, HD_UBYTE *PtrMtx);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_PopAtmSeq(HD_ATOM **First, HD_ATOM **Last, HD_ULONG TotAtm, HD_ATOM **AtmSeq);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_PopAtom(HD_ATOM *Atm, VG_PUSH_ATOMO *AtmBuf);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_PopBndOrd(HD_ATOM *Atm, HD_UBYTE *BndOrdMtx);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_PopChainID(HD_ATOM *Atm, HD_BYTE *ChainIDMtx);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_PopCharges(HD_ATOM *Atm, HD_FLOAT *ChargeMtx);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_PopChiral(HD_ATOM *Atm, HD_BYTE *ChiralMtx);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_PopConnect(HD_ATOM *Atm, HD_ULONG TotAtm, HD_ULONG *ConnectMtx);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_PopCoord(HD_ATOM *Atm, HD_FLOAT *CoordMtx);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_PopDrawMode(HD_ATOM *Atm, HD_UBYTE *DrawMtx);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_PopElem(HD_ATOM *Atm, HD_WORD *ElemMtx);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_PopFix(HD_ATOM *Atm, HD_FLOAT *FixMtx);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_PopFlags(HD_ATOM *Atm, HD_LONG *FlagsMtx);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_PopFlagsOo(HD_VOID *Ctx, HD_LONG Mask);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_PopLabel(HD_ATOM *Atm, HD_UBYTE *LabelMtx);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_PopName(HD_ATOM *Atm, HD_LONG *NameMtx);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_PopNSost(HD_ATOM *Atm, HD_UBYTE *NSostMtx);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_PopResName(HD_ATOM *Atm, HD_LONG *ResNameMtx);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_PopResSeq(HD_ATOM *Atm, HD_LONG *ResSeqMtx);

VEGA_EXTERN HD_UBYTE *      VEGA_EXPORT VG_PushActiveAtm(HD_ATOM *, HD_ULONG);
VEGA_EXTERN HD_ATOM **      VEGA_EXPORT VG_PushAtmSeq(HD_ATOM *Atm, HD_ULONG TotAtm);
VEGA_EXTERN VG_PUSH_ATOMO * VEGA_EXPORT VG_PushAtom(HD_ATOM *Atm);
VEGA_EXTERN HD_UBYTE *      VEGA_EXPORT VG_PushBndOrd(HD_ATOM *Atm, HD_ULONG BndNum);
VEGA_EXTERN HD_BYTE *       VEGA_EXPORT VG_PushChainID(HD_ATOM *Atm, HD_ULONG TotAtm);
VEGA_EXTERN HD_FLOAT *      VEGA_EXPORT VG_PushCharges(HD_ATOM *Atm, HD_ULONG TotAtm);
VEGA_EXTERN HD_BYTE *       VEGA_EXPORT VG_PushChiral(HD_ATOM *Atm, HD_ULONG TotAtm);
VEGA_EXTERN HD_ULONG *      VEGA_EXPORT VG_PushConnect(HD_ATOM *Atm, HD_ULONG BndNum);
VEGA_EXTERN HD_FLOAT *      VEGA_EXPORT VG_PushCoord(HD_ATOM *Atm, HD_ULONG TotAtm);
VEGA_EXTERN HD_UBYTE *      VEGA_EXPORT VG_PushDrawMode(HD_ATOM *Atm, HD_ULONG TotAtm);
VEGA_EXTERN HD_WORD *       VEGA_EXPORT VG_PushElem(HD_ATOM *Atm, HD_ULONG TotAtm);
VEGA_EXTERN HD_FLOAT *      VEGA_EXPORT VG_PushFix(HD_ATOM *Atm, HD_ULONG TotAtm);
VEGA_EXTERN HD_LONG *       VEGA_EXPORT VG_PushFlags(HD_ATOM *Atm, HD_ULONG TotAtm);
VEGA_EXTERN HD_VOID *       VEGA_EXPORT VG_PushFlagsOo(HD_ATOM *Atm, HD_ULONG TotAtm);
VEGA_EXTERN HD_UBYTE *      VEGA_EXPORT VG_PushLabel(HD_ATOM *Atm, HD_ULONG TotAtm);
VEGA_EXTERN HD_LONG *       VEGA_EXPORT VG_PushName(HD_ATOM *Atm, HD_ULONG TotAtm);
VEGA_EXTERN HD_UBYTE *      VEGA_EXPORT VG_PushNSost(HD_ATOM *Atm, HD_ULONG TotAtm);
VEGA_EXTERN HD_LONG *       VEGA_EXPORT VG_PushResName(HD_ATOM *Atm, HD_ULONG TotAtm);
VEGA_EXTERN HD_LONG *       VEGA_EXPORT VG_PushResSeq(HD_ATOM *Atm, HD_ULONG TotAtm);

VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_RemoveAtmMatch(VG_CTX *Ctx, const HD_CHAR *Sel);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_RemoveByAtm(VG_CTX *Ctx, HD_ATOM *SelAtm, HD_LONG What);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_RemoveCounterIons(VG_CTX *Ctx, HD_BOOL ActiveOnly);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_RemoveSingleAtm(VG_CTX *Ctx, HD_ATOM *PickedAtm, HD_ATOM **InizAtm, HD_ULONG *TotAtm, HD_BOOL RenAtms);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_RemoveVisAtm(VG_CTX *Ctx, HD_BOOL Active);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_RenAtm(HD_ATOM *Atm, HD_ULONG StartNum);
VEGA_EXTERN HD_CHAR *       VEGA_EXPORT VG_Res2Str(VG_CTX *Ctx, HD_CHAR *Dest, HD_ATOM *Atm);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_SetAtmName(VG_CTX *Ctx, HD_ATOM *Atm);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_SortAtmByRes(HD_ATOM **First, HD_ATOM **Last, HD_ULONG TotAtm);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_UnlinkAtm(HD_ATOM *Atm, HD_ATOM **InizAtm, HD_ULONG *TotAtm, HD_ATOM **LastAtm);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_WaterExclude(HD_ATOM *Atm);

#  ifdef __cplusplus
}
#  endif
#endif

