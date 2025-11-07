
/*************************************************
****        VEGA - Solvate a molecule         ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/



#ifndef __VG_SOLVATE_H

/**** Shape types for solvatation ****/

#  define  VG_SOL_SHAPE_BOX             0
#  define  VG_SOL_SHAPE_SPHERE          1
#  define  VG_SOL_SHAPE_LAYER           2
#  define  VG_SOL_SHAPE_BOXLAYER        3

/**** VG_Solvate() flags ****/

#  define  VG_SOL_FLAG_NONE             0
#  define  VG_SOL_FLAG_CONNCALC         1
#  define  VG_SOL_FLAG_DONTPRECUT       2
#  define  VG_SOL_FLAG_KEEPCLUSTER      4

/**** Structures ****/

typedef struct {
  HD_FLOAT         Gx, Gy, Gz;             /* Coordinates of geometric center */
  HD_FLOAT         MaxX, MaxY, MaxZ;       /* Molecule size                   */
} VG_SOLMOLINFO;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_Solvate                         _VG_Solvate
#    define  VG_SolvateFile                     _VG_SolvateFile
#    define  VG_SolvatePreCut                   _VG_SolvatePreCut
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_Solvate(VG_CTX *Ctx, VG_CTX *SolCtx, HD_LONG SolShape, HD_XYZF *Center, HD_XYZF *Box, HD_FLOAT Overlap, HD_LONG Flags);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_SolvateFile(VG_CTX *Ctx, const HD_CHAR *ShellFile, HD_LONG SolShape, HD_XYZF *Center, HD_XYZF *Box, HD_FLOAT Overlap);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_SolvatePreCut(VG_CTX *SolCtx, HD_LONG SolShape, HD_XYZF *Box, VG_SOLMOLINFO *MolInfo);

#  ifdef __cplusplus
}
#  endif
#endif
