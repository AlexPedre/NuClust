
/*************************************************
**** VEGA - Ligand - receptor score functions ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_SCORE_H
#  define  __VG_SCORE_H

#  define  VG_SCORE_VERSION             "1.0"

/**** Score flags ****/

#  define  VG_SCORE_FLG_NONE            0
#  define  VG_SCORE_FLG_PUSHPOT         1
#  define  VG_SCORE_FLG_DISABLED        2

/**** Scores types ****/

#  define  VG_SCORE_BROTO               0
#  define  VG_SCORE_BROTO2              1
#  define  VG_SCORE_BROTO3              2
#  define  VG_SCORE_BROTOF              3
#  define  VG_SCORE_CHARMM              4
#  define  VG_SCORE_CHARMM22            5
#  define  VG_SCORE_CHARMM36            6
#  define  VG_SCORE_CONTACTS            7
#  define  VG_SCORE_CVFF                8
#  define  VG_SCORE_ELECT               9
#  define  VG_SCORE_ELECTDD            10

#  define  VG_SCORE_TOT                11

#  define  VG_SCORE_CONTDIST            2.5f /* Contact distance              */

/**** Interaction energy ****/

typedef struct {
  HD_ATOM *             InizRes;        /* Pointer to first residue atom      */
  HD_FLOAT              Ene;            /* Energy                             */
  HD_ULONG              Mol;            /* Molecule number                    */
} VG_INTENE;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_ScoreAlloc                      _VG_ScoreAlloc
#    define  VG_ScoreCalc                       _VG_ScoreCalc
#    define  VG_ScoreFind                       _VG_ScoreFind
#    define  VG_ScoreFree                       _VG_ScoreFree
#    define  VG_ScoreInit                       _VG_ScoreInit
#    define  VG_ScoreResEneSort                 _VG_ScoreResEneSort
#    define  VG_ScoreSave                       _VG_ScoreSave
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_ScoreAlloc(VG_CTX *Ctx);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_ScoreCalc(VG_CTX *Ctx, HD_ULONG NumLig,
                                                     HD_FLOAT Diel, HD_FLOAT Cutoff, HD_FLOAT ContDist, HD_BOOL ActiveOnly, HD_BOOL Quiet);
VEGA_EXTERN HD_LONG         VEGA_EXPORT VG_ScoreFind(const HD_CHAR *Name);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_ScoreFree(VG_SCORE_DATA *Data);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_ScoreInit(VG_CTX *Ctx);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_ScoreResEneSort(VG_INTENE *ResEne, HD_ULONG TotRes);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_ScoreSave(VG_CTX *Ctx, FILE *FH);

#  ifdef __cplusplus
}
#  endif
#endif
