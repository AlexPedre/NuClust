
/*************************************************
****     VEGA - Protein folding analysis      ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_PROTFOLD_H
#  define  __VG_PROTFOLD_H

typedef struct {
  HD_ATOM *     AtmCA;         /* Alpha carbon address   */
  HD_ATOM *     BegRes;        /* Residue first atom     */
  HD_ULONG      Atoms;          /* Residue atoms          */
  HD_LONG       Index;          /* Aminoacid matrix index */
  HD_ULONG      Contacts;       /* Number of contacts     */
  HD_FLOAT      Score;          /* Score value            */
  HD_XYZF       Center;         /* Residue center         */
} VG_PFOLDRES;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_ProtFoldAnalyze                 _VG_ProtFoldAnalyze
#    define  VG_ProtFoldContacts                _VG_ProtFoldContacts
#    define  VG_ProtFoldInit                    _VG_ProtFoldInit
#    define  VG_ProtFoldNR                      _VG_ProtFoldNR
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_ProtFoldAnalyze(VG_CTX *Ctx, HD_ATOM *InizAtm, HD_BOOL ActiveOnly);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_ProtFoldContacts(VG_PFOLDRES *ResMtx);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_ProtFoldInit(VG_CTX *Ctx, VG_PFOLDRES **ResMtx, HD_ATOM *InizAtm, HD_BOOL ActiveOnly);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_ProtFoldNR(HD_FLOAT *ValMtx, HD_ULONG TotRes, HD_ULONG TotStep, HD_ULONG Cut);

#  ifdef __cplusplus
}
#  endif
#endif
