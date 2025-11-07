
/*************************************************
****       VEGA - Indigo library wrapper      ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_INDIGOLIB_H
#  define  __VG_INDIGOLIB_H

/**** Flags ****/

#  define  VG_INDIGO_NONE                       0
#  define  VG_INDIGO_ACTONLY                    1
#  define  VG_INDIGO_NOHYDROG                   2
#  define  VG_INDIGO_UNDO                       4
#  define  VG_INDIGO_UPDATEVIEW                 8

/**** Fingerprint ASCII encoding VG_IndigoFingerprintStr() ****/

#  define  VG_INDIGO_FPSTRENC_BASE64            0 /* Don't change the order ! */
#  define  VG_INDIGO_FPSTRENC_HEX               1

/**** Fingerprint type VG_IndigoFingerprint()/VG_IndigoFingerprintStr() ****/

#  define  VG_INDIGO_FPTYPE_SIM                 0 /* Don't change the order ! */
#  define  VG_INDIGO_FPTYPE_SUB                 1
#  define  VG_INDIGO_FPTYPE_SEBRES              2
#  define  VG_INDIGO_FPTYPE_SUBTAU              3
#  define  VG_INDIGO_FPTYPE_FULL                4

/**** VG_IndigoSmartsSelect() flags ****/

#  define  VG_INDIGO_SELSMARTS_NONE             0
#  define  VG_INDIGO_SELSMARTS_ACTONLY          1
#  define  VG_INDIGO_SELSMARTS_ADDITIVE         2
#  define  VG_INDIGO_SELSMARTS_COLOR            4
#  define  VG_INDIGO_SELSMARTS_DRAWMODE         8
#  define  VG_INDIGO_SELSMARTS_LABEL           16
#  define  VG_INDIGO_SELSMARTS_SELECT          32

/**** Tautomer generation methods ****/

#  define  VG_INDIGO_TAUMODE_INCHI              0 /* Don't change the order ! */
#  define  VG_INDIGO_TAUMODE_RSMARTS            1

#  if defined(LINUX) || defined(WIN32)
#    ifdef LINUX
#      define  VG_INDIGO_DLL      "libindigo.so"
#      define  VG_INDIGOREND_DLL  "libindigo-renderer.so"
#      define  VG_WINAPI
#    else
#      define  VG_INDIGO_DLL      "indigo.dll"
#      define  VG_INDIGOREND_DLL  "indigo-renderer.dll"

/**** Library function pointers ****/

#      if defined(__BORLANDC__) || defined(__MINGW32__)
#        define  VG_WINAPI        _cdecl
#      else
#        define  VG_WINAPI        WINAPI
#      endif
#    endif

#    ifdef VG_INDIGO_DYNDLL
#      define  VG_INDIGO_EXTERN
#    else
#      ifdef __cplusplus
#        define  VG_INDIGO_EXTERN          extern "C"
#      else
#        define  VG_INDIGO_EXTERN          extern
#      endif
#    endif

/**** Tautomer item ****/

typedef struct __vg_indigo_tauitm {
  struct __vg_indigo_tauitm *   Next;   /* Pointer to next item          */
  struct __vg_indigo_tauitm *   Prev;   /* Pointer to previous item      */
  HD_LONG                       TauObj; /* Tautomer object               */
} VG_INDIGO_TAUITM;


/**** Tautomer iterator context ****/

struct __vg_indigo_tauctx {
  HD_ATOM *             MolInizAtm;     /* First atom of input molecule  */
  HD_ULONG              MolTotAtm;      /* Number of atoms of input      */
  HD_UDLONG             SessionID;      /* Session ID                    */
  HD_LIST *             TauList;        /* Tautomer list                 */
  VG_CTX *              Ctx;            /* VEGA context                  */
  VG_INDIGO_TAUITM *    CurTauItm;      /* Current tautomer item         */
};

typedef struct __vg_indigo_tauctx * VG_INDIGO_TAUCTX;

/**** Indigo ****/

VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoAddAtom)(int, const char *);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoAddBond)(int, int, int);
VG_INDIGO_EXTERN HD_UDLONG      (VG_WINAPI *VG_indigoAllocSessionId)(void);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoAromatize)(int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoBondOrder)(int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoClone)(int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoCountAtoms)(int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoCreateMolecule)(void);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoDearomatize)(int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoFingerprint)(int, const char *);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoDestination)(int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoFoldHydrogens)(int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoFree)(int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoFreeAllObjects)(void);
//VG_INDIGO_EXTERN float *        (VG_WINAPI *VG_indigoGetAcidPkaValue)(int, int, int, int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoGetCharge)(int, int *);
VG_INDIGO_EXTERN const char *   (VG_WINAPI *VG_indigoGetLastError)(void);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoHasNext)(int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoHasZCoord)(int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoIndex)(int);
//VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoIonize)(int item, float, float);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoIterateAtoms)(int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoIterateBonds)(int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoIterateMatches)(int, int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoIterateTautomers)(int, const char *);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoLayout)(int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoLoadMolecule)(int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoLoadSmarts)(int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoLoadSmartsFromString)(const char *);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoMapAtom)(int, int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoNext)(int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoNormalize)(int, const char *);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoReadString)(const char *);
VG_INDIGO_EXTERN void           (VG_WINAPI *VG_indigoReleaseSessionId)(HD_UDLONG);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoSetCharge)(int, int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoSetOption)(const char *, const char *);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoSetOptionColor)(const char *, float, float, float);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoSetOptionInt)(const char *, int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoSetOptionXY)(const char *, int, int);
VG_INDIGO_EXTERN void           (VG_WINAPI *VG_indigoSetSessionId)(HD_UDLONG);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoSetXYZ)(int, float, float, float);
VG_INDIGO_EXTERN float          (VG_WINAPI *VG_indigoSimilarity)(int, int, const char *);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoSource)(int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoSubstructureMatcher)(int, const char *);
VG_INDIGO_EXTERN const char *   (VG_WINAPI *VG_indigoSymbol)(int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoToBuffer)(int, char **, int *);
VG_INDIGO_EXTERN const char *   (VG_WINAPI *VG_indigoToString)(int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoWriteBuffer)(void);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoWriteFile)(const char *);
VG_INDIGO_EXTERN float *        (VG_WINAPI *VG_indigoXYZ)(int atom);

/**** Indigo Renderer ****/

VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoRender)(int, int);
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoRenderReset)(void);
#    ifdef WIN32
VG_INDIGO_EXTERN int            (VG_WINAPI *VG_indigoRenderWriteHDC)(void *, int);
#    endif

/**** Indigo SMILES ****/

VG_INDIGO_EXTERN const char *   (VG_WINAPI *VG_indigoCanonicalSmiles)(int);
VG_INDIGO_EXTERN const char *   (VG_WINAPI *VG_indigoLayeredCode)(int);

#    else

#    define  VG_indigoAddBond                   indigoAddBond
#    define  VG_indigoAllocSessionId            indigoAllocSessionId
#    define  VG_indigoAromatize                 indigoAromatize
#    define  VG_indigoBondOrder                 indigoBondOrder
#    define  VG_indigoClone                     indigoClone
#    define  VG_indigoCountAtoms                indigoCountAtoms
#    define  VG_indigoCreateMolecule            indigoCreateMolecule
#    define  VG_indigoDearomatize               indigoDearomatize
#    define  VG_indigoDestination               indigoDestination
#    define  VG_indigoFingerprint               indigoFingerprint
#    define  VG_indigoFoldHydrogens             indigoFoldHydrogens
#    define  VG_indigoFree                      indigoFree
#    define  VG_indigoFreeAllObjects            indigoFreeAllObjects
//#    define  VG_indigoGetAcidPkaValue           indigoGetAcidPkaValue
#    define  VG_indigoGetCharge                 indigoGetCharge
#    define  VG_indigoGetLastError              indigoGetLastError
#    define  VG_indigoHasNext                   indigoHasNext
#    define  VG_indigoHasZCoord                 indigoHasZCoord
#    define  VG_indigoIndex                     indigoIndex
//#    define  VG_indigoIonize                    indigoIonize
#    define  VG_indigoIterateAtoms              indigoIterateAtoms
#    define  VG_indigoIterateBonds              indigoIterateBonds
#    define  VG_indigoIterateMatches            indigoIterateMatches
#    define  VG_indigoIterateTautomers          indigoIterateTautomers
#    define  VG_indigoLayout                    indigoLayout
#    define  VG_indigoLoadMolecule              indigoLoadMolecule
#    define  VG_indigoLoadSmarts                indigoLoadSmarts
#    define  VG_indigoLoadSmartsFromString      indigoLoadSmartsFromString
#    define  VG_indigoMapAtom                   indigoMapAtom
#    define  VG_indigoNext                      indigoNext
#    define  VG_indigoNormalize                 indigoNormalize
#    define  VG_indigoReadString                indigoReadString
#    define  VG_indigoReleaseSessionId          indigoReleaseSessionId
#    define  VG_indigoSetCharge                 indigoSetCharge
#    define  VG_indigoSetOption                 indigoSetOption
#    define  VG_indigoSetOptionColor            indigoSetOptionColor
#    define  VG_indigoSetOptionInt              indigoSetOptionInt
#    define  VG_indigoSetOptionXY               indigoSetOptionXY
#    define  VG_indigoSetSessionId              indigoSetSessionId
#    define  VG_indigoSetXYZ                    indigoSetXYZ
#    define  VG_indigoSimilarity                indigoSimilarity
#    define  VG_indigoSource                    indigoSource
#    define  VG_indigoSubstructureMatcher       indigoSubstructureMatcher
#    define  VG_indigoSymbol                    indigoSymbol
#    define  VG_indigoToBuffer                  indigoToBuffer
#    define  VG_indigoToString                  indigoToString
#    define  VG_indigoWriteBuffer               indigoWriteBuffer
#    define  VG_indigoWriteFile                 indigoWriteFile
#    define  VG_indigoXYZ                       indigoXYZ

/**** Indigo Renderer ****/

#    define  VG_indigoRender                    indigoRender
#    define  VG_indigoRenderReset               indigoRenderReset
#    define  VG_indigoRenderWriteHDC            indigoRenderWriteHDC

#    define  VG_indigoCanonicalSmiles           indigoCanonicalSmiles
#    define  VG_indigoLayeredCode               indigoLayeredCode
#  endif

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_IndigoCheckSmiles               _VG_IndigoCheckSmiles
#    define  VG_IndigoConvert2D                 _VG_IndigoConvert2D
#    define  VG_IndigoErr                       _VG_IndigoErr
#    define  VG_IndigoFingerprint               _VG_IndigoFingerprint
#    define  VG_IndigoFingerprintStr            _VG_IndigoFingerprintStr
#    define  VG_IndigoFreeMol                   _VG_IndigoFreeMol
#    define  VG_IndigoInit                      _VG_IndigoInit
#    define  VG_IndigoMolFromVega               _VG_IndigoMolFromVega
#    define  VG_IndigoMolToVegaCoord            _VG_IndigoMolToVegaCoord
#    define  VG_IndigoSmartsSelect              _VG_IndigoSmartsSelect
#    define  VG_IndigoSmilesFixH                _VG_IndigoSmilesFixH
#    define  VG_IndigoSmilesPut                 _VG_IndigoSmilesPut
#    define  VG_IndigoSmilesValidate            _VG_IndigoSmilesValidate
#    define  VG_IndigoTauFree                   _VG_IndigoTauFree
#    define  VG_IndigoTauGet                    _VG_IndigoTauGet
#    define  VG_IndigoTauGetNext                _VG_IndigoTauGetNext
#    define  VG_IndigoTauNew                    _VG_IndigoTauNew
#    define  VG_IndigoTauGetPrev                _VG_IndigoTauGetPrev
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_BOOL                 VEGA_EXPORT VG_IndigoCheckSmiles(const HD_CHAR *Smi);
VEGA_EXTERN HD_BOOL                 VEGA_EXPORT VG_IndigoConvert2D(HD_ATOM *InizAtm, HD_LONG Flags);
VEGA_EXTERN HD_VOID                 VEGA_EXPORT VG_IndigoErr(HD_VOID);
VEGA_EXTERN HD_LONG                 VEGA_EXPORT VG_IndigoFingerprint(HD_ATOM *InizAtm, HD_LONG Type);
VEGA_EXTERN HD_STRING               VEGA_EXPORT VG_IndigoFingerprintStr(HD_ATOM *InizAtm, HD_LONG Type, HD_LONG Encoding);
VEGA_EXTERN HD_VOID                 VEGA_EXPORT VG_IndigoFreeMol(HD_LONG hMol, HD_LONG *hAtmVect);
VEGA_EXTERN HD_BOOL                 VEGA_EXPORT VG_IndigoInit(HD_VOID);
VEGA_EXTERN HD_LONG                 VEGA_EXPORT VG_IndigoMolFromVega(HD_LONG **hAtms, HD_ULONG *NumAtm, HD_ATOM *InizAtm, HD_LONG Flags);
VEGA_EXTERN HD_VOID                 VEGA_EXPORT VG_IndigoMolToVegaCoord(HD_ATOM *InizAtm, HD_LONG hMol, HD_LONG *hAtms, HD_LONG Flags);
VEGA_EXTERN HD_ULONG                VEGA_EXPORT VG_IndigoSmartsSelect(HD_ATOM *InizAtm, const HD_CHAR *SmartsStr, HD_UBYTE ColorID, HD_UBYTE DrawMode, HD_UBYTE Label, HD_BOOL Select, HD_LONG Flags);
VEGA_EXTERN HD_STRING               VEGA_EXPORT VG_IndigoSmilesFixH(const HD_CHAR *Line);
VEGA_EXTERN HD_ATOM *               VEGA_EXPORT VG_IndigoSmilesPut(VG_CTX *Ctx, HD_CHAR *Line, HD_ATOM **LastAtomo, HD_ULONG *TotAtomo);
VEGA_EXTERN HD_BOOL                 VEGA_EXPORT VG_IndigoSmilesValidate(const HD_CHAR *Line);
VEGA_EXTERN HD_VOID                 VEGA_EXPORT VG_IndigoTauFree(VG_INDIGO_TAUCTX hTau);
VEGA_EXTERN HD_ATOM *               VEGA_EXPORT VG_IndigoTauGet(VG_INDIGO_TAUCTX hTau, HD_ATOM **LastAtomo, HD_ULONG *TotAtomo);
VEGA_EXTERN HD_ATOM *               VEGA_EXPORT VG_IndigoTauGetNext(VG_INDIGO_TAUCTX hTau, HD_ATOM **LastAtomo, HD_ULONG *TotAtomo);
VEGA_EXTERN VG_INDIGO_TAUCTX        VEGA_EXPORT VG_IndigoTauNew(VG_CTX *Ctx, HD_LONG Mode);
VEGA_EXTERN HD_ATOM *               VEGA_EXPORT VG_IndigoTauGetPrev(VG_INDIGO_TAUCTX hTau, HD_ATOM **LastAtomo, HD_ULONG *TotAtomo);

#  ifdef __cplusplus
}
#  endif
#endif

