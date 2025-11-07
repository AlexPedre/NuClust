
/*************************************************
****            VEGA - LiGen loader           ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_LIGEN_H
#  define  __VG_LIGEN_H

#  include <hdmemstream.h>

/**** LiGen file types ****/

#  define VG_LIGENFTYP_UNK          0
#  define VG_LIGENFTYP_BIN_GRID     1
#  define VG_LIGENFTYP_BIN_PHARM    2
#  define VG_LIGENFTYP_BIN_POCKET   3

/**** Pharmacophore point types ****/

#  define VG_LIGEN_PHARMTYP_HBACC   'A'
#  define VG_LIGEN_PHARMTYP_HBDON   'D'
#  define VG_LIGEN_PHARMTYP_HYDRO   'H'

/**** Pocket point types ****/

#  define VG_LIGEN_POCKERTYP_EXCL   'E'
#  define VG_LIGEN_POCKERTYP_HBDON  'D'
#  define VG_LIGEN_POCKERTYP_HBACC  'A'
#  define VG_LIGEN_POCKERTYP_HYDRO  'H'
#  define VG_LIGEN_POCKERTYP_REC    'X'
#  define VG_LIGEN_POCKERTYP_SOLV   'S'
#  define VG_LIGEN_POCKERTYP_VACANT 'V'

/**** Grid binary header ****/

typedef struct {
  HD_LONG       MinX, MaxX;
  HD_LONG       MinY, MaxY;
  HD_LONG       MinZ, MaxZ;
  HD_ULONG      Points;
  HD_LONG       Ndelt;
} VG_LIGENGRIDHDR;

/**** Pharmacophore header ****/

typedef struct {
  HD_ULONG      PtNum;
} VG_LIGENPHARMHDR;

/**** Pharmacophore binary record ****/

typedef struct {
  HD_BYTE       Type;
  HD_FLOAT      Coor[3];
  HD_FLOAT      Score;
  HD_LONG       Neib;
} VG_LIGENPHARMPT;

/**** Pocket binary record ****/

typedef struct {
  HD_ULONG      Num;
  HD_LONG       Id;
  HD_CHAR       SType[6];
  HD_DOUBLE     Pos[3];
  HD_DOUBLE     Rvdw;
  HD_DOUBLE     Logp;
  HD_CHAR       HB[3];
  HD_DOUBLE     Root[3];
  HD_CHAR       Name[6];
  HD_CHAR       ResidueName[4];
  HD_CHAR       xType[10];
} VG_LIGENPKTATM;

/**** Pocket header ****/

typedef struct {
  HD_ULONG      AtmNum;
} VG_LIGENPKTHDR;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_IsotopicCalc                    _VG_IsotopicCalc
#    define  VG_LiGenBinCheck                   _VG_LiGenBinCheck
#    define  VG_LiGenBinCheckMem                _VG_LiGenBinCheckMem
#    define  VG_LiGenPocketBinLoad              _VG_LiGenPocketBinLoad
#    define  VG_LiGenPocketBinLoadMem           _VG_LiGenPocketBinLoadMem
#    define  VG_LiGenPocketLoad                 _VG_LiGenPocketLoad
#    define  VG_LiGenPocketLoadMem              _VG_LiGenPocketLoadMem
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_LiGenBinCheck(VG_CTX *Ctx, FILE *FH);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_LiGenBinCheckMem(VG_CTX *Ctx, HD_MEMSTREAM hStream);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_LiGenPocketBinLoad(VG_CTX *Ctx, FILE *FH, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_LiGenPocketBinLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_LiGenPocketLoad(VG_CTX *Ctx, FILE *FH, VG_RECORD *Line, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_LiGenPocketLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Line, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);

#  ifdef __cplusplus
}
#  endif
#endif

