
/**************************************************
****               VEGA - Globvar              ****
****  Definitions of variables and prototypes  ****
****  Copyright 1996-2025, Alessandro Pedretti ****
**************************************************/


#ifndef __GLOBVAR
#  define  __GLOBVAR
#  include <hyperdrive.h>

/**** RemoveH() flags ****/

#  define  VG_RMH_FLG_NONE      0
#  define  VG_RMH_FLG_ACTONLY   1
#  define  VG_RMH_FLG_APOLAR    2

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VegaSet                            _VegaSet
#    define  VegaStderr                         _VegaStderr
#    define  VegaStdin                          _VegaStdin
#    define  VegaStdout                         _VegaStdout

#    define  VG_AddIons                         _VG_AddIons
#    define  VG_AddPackExt                      _VG_AddPackExt
#    define  VG_AlchemySave                     _VG_AlchemySave
#    define  VG_Alloca                          _VG_Alloca
#    define  VG_AssignChirality                 _VG_AssignChirality
#    define  VG_AssignGeomEz                    _VG_AssignGeomEz
#    define  VG_Atoin                           _VG_Atoin
#    define  VG_AtmChargeFormal                 _VG_AtmChargeFormal
#    define  VG_AtmName2Elem                    _VG_AtmName2Elem
#    define  VG_AtmTrans                        _VG_AtmTrans
#    define  VG_CarSave                         _VG_CarSave
#    define  VG_CatClose                        _VG_CatClose
#    define  VG_CatErr                          _VG_CatErr
#    define  VG_CatErrAsync                     _VG_CatErrAsync
#    define  VG_CatErrNoGlobErr                 _VG_CatErrNoGlobErr
#    define  VG_CatInit                         _VG_CatInit
#    define  VG_CatPrintf                       _VG_CatPrintf
#    define  VG_CatPrintfDs                     _VG_CatPrintfDs
#    define  VG_Char2Int                        _VG_Char2Int
#    define  VG_ChangeExt                       _VG_ChangeExt
#    define  VG_Charge                          _VG_Charge
#    define  VG_ChargeBySeq                     _VG_ChargeBySeq
#    define  VG_ChargeMol                       _VG_ChargeMol
#    define  VG_ChargeTem                       _VG_ChargeTem
#    define  VG_ChemSolSave                     _VG_ChemSolSave
#    define  VG_ChkArgType                      _VG_ChkArgType
#    define  VG_CifSave                         _VG_CifSave
#    define  VG_CloseAll                        _VG_CloseAll
#    define  VG_CloseAllMol                     _VG_CloseAllMol
#    define  VG_ConnClear                       _VG_ConnClear
#    define  VG_CparFree                        _VG_CparFree
#    define  VG_CparFreeAll                     _VG_CparFreeAll
#    define  VG_CparLoad                        _VG_CparLoad
#    define  VG_CpmdXyzSave                     _VG_CpmdXyzSave
#    define  VG_CrossProd                       _VG_CrossProd
#    define  VG_CRDSave                         _VG_CRDSave
#    define  VG_CrtSave                         _VG_CrtSave
#    define  VG_CSSRSave                        _VG_CSSRSave
#    define  VG_Dchar2Str                       _VG_Dchar2Str
#    define  VG_Det2x2                          _VG_Det2x2
#    define  VG_DosPrintf                       _VG_DosPrintf
#    define  VG_Dot                             _VG_Dot
#    define  VG_Errore                          _VG_Errore
#    define  VG_Fgets                           _VG_Fgets
#    define  VG_FileLength                      _VG_FileLength
#    define  VG_FileNameCpy                     _VG_FileNameCpy
#    define  VG_FindRes                         _VG_FindRes
#    define  VG_FindResPtr                      _VG_FindResPtr
#    define  VG_Floor                           _VG_Floor
#    define  VG_Floorf                          _VG_Floorf
#    define  VG_ForStrCpy                       _VG_ForStrCpy
#    define  VG_GaussCarInSave                  _VG_GaussCarInSave
#    define  VG_GamessSave                      _VG_GamessSave
#    define  VG_Gasteiger                       _VG_Gasteiger
#    define  VG_GetFileName                     _VG_GetFileName
#    define  VG_GetFilePath                     _VG_GetFilePath
#    define  VG_GetStr                          _VG_GetStr
#    define  VG_GromosSave                      _VG_GromosSave
#    define  VG_HyperDriveFree                  _VG_HyperDriveFree
#    define  VG_HyperDriveInit                  _VG_HyperDriveInit
#    define  VG_InfoSave                        _VG_InfoSave
#    define  VG_IncrementVect                   _VG_IncrementVect
#    define  VG_IsFloat                         _VG_IsFloat
#    define  VG_IsInt                           _VG_IsInt
#    define  VG_Itoa                            _VG_Itoa
#    define  VG_LoadPrefs                       _VG_LoadPrefs
#    define  VG_Lower                           _VG_Lower
#    define  VG_Magnitude                       _VG_Magnitude

#    define  VG_MoPacChgCalc                    _VG_MoPacChgCalc
#    define  VG_MoPacChkMMOK                    _VG_MoPacChkMMOK
#    define  VG_MoPacSave                       _VG_MoPacSave
#    define  VG_MoPacSaveXYZ                    _VG_MoPacSaveXYZ

#    define  VG_MsfWrite                        _VG_MsfWrite
#    define  VG_MyClose                         _VG_MyClose
#    define  VG_MyCloseAll                      _VG_MyCloseAll
#    define  VG_NamdBinSave                     _VG_NamdBinSave
#    define  VG_Normalize                       _VG_Normalize
#    define  VG_NormAngle                       _VG_NormAngle
#    define  VG_NormAnglef                      _VG_NormAnglef
#    define  VG_Ochar2Str                       _VG_Ochar2Str
#    define  VG_Ovality                         _VG_Ovality

#    define  VG_PkGetFileName                   _VG_PkGetFileName
#    define  VG_PkOpen                          _VG_PkOpen
#    define  VG_PkReOpen                        _VG_PkReOpen

#    define  VG_PlaneAngle                      _VG_PlaneAngle
#    define  VG_PlaneAngAtm                     _VG_PlaneAngAtm
#    define  VG_PlaneCof                        _VG_PlaneCof
#    define  VG_PlaneDistf                      _VG_PlaneDistf

#    define  VG_PqrXmlSave                      _VG_PqrXmlSave

#    define  VG_PrintAtmErr                     _VG_PrintAtmErr
#    define  VG_PrintDosErr                     _VG_PrintDosErr
#    define  VG_PrintLoad                       _VG_PrintLoad
#    define  VG_PrintProg                       _VG_PrintProg
#    define  VG_PrintWarn                       _VG_PrintWarn

#    define  VG_PsfSave                         _VG_PsfSave
#    define  VG_Qchar2Str                       _VG_Qchar2Str

#    define  VG_RemoveAtm                       _VG_RemoveAtm
#    define  VG_RemoveH                         _VG_RemoveH
#    define  VG_RemoveRes                       _VG_RemoveRes
#    define  VG_RenameRes                       _VG_RenameRes
#    define  VG_RemoveWat                       _VG_RemoveWat

#    define  VG_RenRes                          _VG_RenRes
#    define  VG_SafeFclose                      _VG_SafeFclose
#    define  VG_Saver                           _VG_Saver
#    define  VG_SetGlobErr                      _VG_SetGlobErr
#    define  VG_SetTypeRes                      _VG_SetTypeRes
#    define  VG_SpilloRbsSave                   _VG_SpilloRbsSave
#    define  VG_Str2Dchar                       _VG_Str2Dchar
#    define  VG_Str2Ochar                       _VG_Str2Ochar
#    define  VG_Str2Qchar                       _VG_Str2Qchar
#    define  VG_StrExist                        _VG_StrExist
#    define  VG_SubArg                          _VG_SubArg
#    define  VG_SybFldCalc                      _VG_SybFldCalc
#    define  VG_SybRgnLoad                      _VG_SybRgnLoad

#    define  VG_Swap                            _VG_Swap
#    define  VG_Swap64                          _VG_Swap64
#    define  VG_SwapD                           _VG_SwapD
#    define  VG_SwapI                           _VG_SwapI
#    define  VG_SwapS                           _VG_SwapS
#    define  VG_SwapW                           _VG_SwapW
#    define  VG_SwapWrite                       _VG_SwapWrite

#    define  VG_Torsion                         _VG_Torsion
#    define  VG_Upper                           _VG_Upper
#    define  VG_VegaGetString                   _VG_VegaGetString
#    define  VG_VrmlSave                        _VG_VrmlSave
#    define  VG_VrmlCpkSave                     _VG_VrmlCpkSave
#    define  VG_VrmlSolSave                     _VG_VrmlSolSave
#    define  VG_Wildncmp                        _VG_Wildncmp
#    define  VG_Words                           _VG_Words
#    define  VG_XyzSave                         _VG_XyzSave

#    define  VG_ShowLastErr                     _VG_ShowLastErr
#    define  VG_AddProcAddresses                _VG_AddProcAddresses
#    define  VG_GetProcAddresses                _VG_GetProcAddresses
#    define  VG_SafeFreeLibrary                 _VG_SafeFreeLibrary
#  endif

/**** Global variables ****/

extern const    HD_CHAR *    VegaFopenR;
extern const    HD_CHAR *    VegaFopenRB;
extern const    HD_CHAR *    VegaFopenRBP;
extern const    HD_CHAR *    VegaFopenW;
extern const    HD_CHAR *    VegaFopenWB;
extern const    HD_CHAR *    VegaFopenWBP;
extern const    HD_CHAR *    VegaFopenA;
extern const    HD_CHAR *    VegaFieldSep;
extern const    HD_CHAR *    VegaPackExt[];
extern const    HD_CHAR *    VegaVrmlHdr;
extern const    HD_CHAR *    VegaHeader;
extern const    HD_CHAR *    VegaShapeType[];
extern          VG_PREFS     VegaPrefs;

VEGA_EXTERNVAR  VG_SETTINGS  VegaSet;
VEGA_EXTERNVAR  VG_FILE      VegaStderr;
VEGA_EXTERNVAR  VG_FILE      VegaStdin;
VEGA_EXTERNVAR  VG_FILE      VegaStdout;

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_AddIons(VG_CTX *Ctx, HD_ATOM *InizAtm, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_CHAR *Elem, HD_FLOAT Charge, HD_ULONG N_ions, HD_FLOAT excl_atom_rad, HD_FLOAT excl_ion_rad, HD_FLOAT delta, HD_FLOAT border_width);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_AddPackExt(HD_STRING FileName, HD_LONG PackMode);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_AlchemySave(VG_CTX *Ctx, FILE *FH);
VEGA_EXTERN HD_VOID *       VEGA_EXPORT  VG_Alloca(HD_ULONG Mem);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT  VG_AssignChirality(VG_CTX *Ctx);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT  VG_AssignGeomEz(VG_CTX *Ctx);
VEGA_EXTERN HD_LONG         VEGA_EXPORT  VG_Atoin(HD_CHAR *Str, HD_LONG Start, HD_LONG Len);
VEGA_EXTERN HD_FLOAT        VEGA_EXPORT  VG_AtmChargeFormal(HD_ATOM *Atm);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_AtmName2Elem(HD_ATOM *Atm);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_AtmTrans(HD_ATOM *InizAtm, HD_ULONG TotAtm, VG_TRJPAR *TrjPar);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_CarSave(VG_CTX *Ctx, FILE *FH, HD_LONG SubFormat);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_CatClose(HD_VOID);
VEGA_EXTERN HD_BOOL         VEGA_EXPORTA VG_CatErr(HD_ULONG, ...);
VEGA_EXTERN HD_BOOL         VEGA_EXPORTA VG_CatErrAsync(HD_ULONG, ...);
VEGA_EXTERN HD_BOOL         VEGA_EXPORTA VG_CatErrNoGlobErr(HD_ULONG, ...);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_CatInit(const HD_CHAR *Language, HD_BOOL Quiet);
VEGA_EXTERN HD_LONG         VEGA_EXPORTA VG_CatPrintf(FILE *FH, HD_ULONG Str, ...);
VEGA_EXTERN HD_LONG         VEGA_EXPORTA VG_CatPrintfDs(VG_CTX *Ctx, FILE *FH, HD_ULONG Str, ...);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT  VG_Char2Int(const HD_CHAR *Str, HD_ULONG k);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_ChangeExt(HD_CHAR *Str, const HD_CHAR *NewExt, HD_CHAR *OldExt);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_Charge(VG_CTX * Ctx, const HD_CHAR *Template, HD_LONG Type, HD_BOOL ActiveOnly);
VEGA_EXTERN HD_LONG         VEGA_EXPORT  VG_ChargeBySeq(HD_ATOM *Atm);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_ChargeMol(VG_CTX * Ctx, const HD_CHAR *Template, HD_LONG Type, HD_BOOL ActiveOnly);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_ChargeTem(VG_CTX * Ctx, const HD_CHAR *, HD_ATOM *, HD_ULONG, HD_BOOL);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_ChemSolSave(VG_CTX * Ctx, FILE *FH, HD_STRING FileName);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_ChkArgType(const HD_CHAR *Str, HD_ULONG Len, HD_UBYTE Type);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_CifSave(VG_CTX * Ctx, FILE *FH, HD_STRING FileName, HD_LONG SubFormat);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_CloseAll(HD_VOID);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_CloseAllMol(VG_CTX *Ctx);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_ConnClear(HD_ATOM *Atm, HD_BOOL ActiveOnly);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_CparFree(VG_CPARAM * CharmmPar);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_CparFreeAll(HD_VOID);
VEGA_EXTERN VG_CPARAM *     VEGA_EXPORT  VG_CparLoad(const HD_CHAR *ParName);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_CpmdXyzSave(VG_CTX *Ctx, FILE *FH);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_CrossProd(HD_XYZ *vect1, HD_XYZ *vect2, HD_XYZ *normal);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_CRDSave(VG_CTX *Ctx, FILE *FH);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_CrtSave(VG_CTX *Ctx, FILE *FH, HD_STRING FileName);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_CSSRSave(VG_CTX *Ctx, FILE *FH, HD_LONG Form);
VEGA_EXTERN HD_CHAR *       VEGA_EXPORT  VG_Dchar2Str(HD_CHAR *Str, const HD_DCHAR *Dchar);
VEGA_EXTERN HD_FLOAT        VEGA_EXPORT  VG_Det2x2(HD_FLOAT, HD_FLOAT, HD_FLOAT, HD_FLOAT);
VEGA_EXTERN HD_LONG         VEGA_EXPORTA VG_DosPrintf(FILE *, const HD_CHAR *, ...);
VEGA_EXTERN HD_DOUBLE       VEGA_EXPORT  VG_Dot(HD_XYZ *vect1, HD_XYZ *vect2);
VEGA_EXTERN HD_BOOL         VEGA_EXPORTA VG_Errore(const HD_CHAR *, ...);
VEGA_EXTERN HD_CHAR *       VEGA_EXPORT  VG_Fgets(HD_CHAR *s, int n, FILE *dev);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT  VG_FileLength(FILE *FH);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_FileNameCpy(HD_CHAR *Dest, const HD_CHAR *Src);
VEGA_EXTERN HD_LONG         VEGA_EXPORT  VG_FindRes(HD_ATOM *InizAtm, HD_ULONG TotAtm);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT  VG_FindResPtr(HD_ATOM *Atm, HD_ATOM **ResPtr, HD_LONG NomeRes, HD_LONG NRes);
VEGA_EXTERN HD_LONG         VEGA_EXPORT  VG_Floor(HD_DOUBLE Val);
VEGA_EXTERN HD_LONG         VEGA_EXPORT  VG_Floorf(HD_FLOAT Val);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_ForStrCpy(HD_CHAR *Dest, const HD_CHAR *Src, HD_ULONG Len);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_GaussCarInSave(VG_CTX *Ctx, FILE *FH, HD_STRING FileName);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_GamessSave(VG_CTX *Ctx, FILE *FH, HD_STRING FileName);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_Gasteiger(HD_CHAR *, HD_ATOM *, HD_ULONG, HD_BOOL);
VEGA_EXTERN const HD_CHAR * VEGA_EXPORT  VG_GetFileName(const HD_CHAR *);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_GetFilePath(HD_CHAR *);
VEGA_EXTERN const HD_CHAR * VEGA_EXPORT  VG_GetStr(HD_ULONG);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_GromosSave(VG_CTX *Ctx, FILE *FH, HD_FLOAT Scale);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_HyperDriveFree(HD_VOID);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_HyperDriveInit(HD_VOID);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_InfoSave(VG_CTX *Ctx, FILE *FH, HD_ULONG MaxAtmInfo, HD_ULONG SasPoints, HD_FLOAT SasProbeRad);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_IncrementVect(HD_BYTE *Vect, HD_ULONG Len);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_IsFloat(const HD_CHAR *Str, const HD_CHAR FloatDecSep);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_IsInt(const HD_CHAR *Str);
VEGA_EXTERN HD_CHAR *       VEGA_EXPORT  VG_Itoa(HD_LONG Value, HD_CHAR *Str, HD_LONG Radix);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_LoadPrefs(VG_PREFS *Prefs, const HD_CHAR *FileName);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_Lower(HD_CHAR *Str);
VEGA_EXTERN HD_DOUBLE       VEGA_EXPORT  VG_Magnitude(HD_XYZ *vect1);

VEGA_EXTERN HD_FLOAT        VEGA_EXPORT  VG_MoPacChgCalc(HD_ATOM *Atm);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_MoPacChkMMOK(HD_ATOM *Atm);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_MoPacSave(VG_CTX *Ctx, FILE *OUTFH, HD_STRING OutfileName, HD_CHAR *OutputKeywords);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_MoPacSaveXYZ(VG_CTX *Ctx, FILE *OUTFH, HD_STRING OutfileName, const HD_CHAR *OutputKeywords, HD_LONG Flags);

VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_MsfWrite(VG_CTX *Ctx, FILE *FH);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_MyClose(FILE *FH);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_MyCloseAll(HD_VOID);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_NamdBinSave(VG_CTX *Ctx, FILE *FH, HD_BOOL Swap);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_Normalize(HD_ATOM *InizAtm, HD_LIST *SrfList);
VEGA_EXTERN HD_DOUBLE       VEGA_EXPORT  VG_NormAngle(HD_DOUBLE Val);
VEGA_EXTERN HD_FLOAT        VEGA_EXPORT  VG_NormAnglef(HD_FLOAT Val);
VEGA_EXTERN HD_CHAR *       VEGA_EXPORT  VG_Ochar2Str(HD_CHAR *Str, const HD_OCHAR *Ochar);
VEGA_EXTERN HD_FLOAT        VEGA_EXPORT  VG_Ovality(HD_FLOAT Area, HD_FLOAT Volume);

VEGA_EXTERN HD_CHAR *       VEGA_EXPORT  VG_PkGetFileName(FILE *FH);
VEGA_EXTERN FILE *          VEGA_EXPORT  VG_PkOpen(const HD_CHAR *FileName, const HD_CHAR *Mode, HD_UWORD PackMode, HD_BOOL Verbose);
VEGA_EXTERN FILE *          VEGA_EXPORT  VG_PkReOpen(FILE *, HD_CHAR *);

VEGA_EXTERN HD_FLOAT        VEGA_EXPORT  VG_PlaneAngle(VG_PLANE *, VG_PLANE *);
VEGA_EXTERN HD_FLOAT        VEGA_EXPORT  VG_PlaneAngAtm(HD_ATOM **);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_PlaneCof(VG_PLANE *, HD_ATOM *, HD_ATOM *, HD_ATOM *);
VEGA_EXTERN HD_FLOAT        VEGA_EXPORT  VG_PlaneDistf(HD_ATOM *, HD_ATOM *, HD_ATOM *, HD_ATOM *);

VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_PqrXmlSave(VG_CTX *Ctx, FILE *FH, HD_STRING FileName);

VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_PrintAtmErr(const HD_CHAR *Err, HD_ATOM *Atm, HD_BOOL Force);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_PrintDosErr(HD_VOID);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_PrintLoad(HD_ULONG Msg, HD_ULONG NMol);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_PrintProg(HD_ULONG Msg);
VEGA_EXTERN HD_VOID         VEGA_EXPORTA VG_PrintWarn(HD_ULONG Msg, ...);

VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_PsfSave(VG_CTX *Ctx, FILE *FH, HD_LONG Type, const HD_CHAR *ForceField, const HD_CHAR *ParMisFile);
VEGA_EXTERN HD_CHAR *       VEGA_EXPORT  VG_Qchar2Str(HD_CHAR *Str, HD_QCHAR *Qchar);

VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_RemoveAtm(VG_CTX *Ctx, HD_ATOM **Atm, HD_ATOM **PrecAtm, HD_ATOM **InizAtm);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT  VG_RemoveH(VG_CTX *Ctx, HD_ATOM **InizAtm, HD_ULONG *TotAtm, HD_LONG Flags);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_RemoveRes(VG_CTX *Ctx, HD_ATOM **Atm, HD_ATOM **PrecAtm, HD_ATOM **InizAtm, HD_ULONG *TotAtm);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT  VG_RenameRes(HD_ATOM *Atm, HD_LONG Res);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT  VG_RemoveWat(VG_CTX *Ctx, HD_ATOM **InizAtm, HD_ULONG *TotAtm);

VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_RenRes(VG_CTX *Ctx, HD_ATOM *Atm, HD_ULONG ResSeq, HD_UBYTE ChainID, HD_BOOL ActOnly);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_SafeFclose(FILE **FH);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_Saver(VG_CTX *Ctx, const HD_CHAR *File, VG_FILEFORMAT *Form, HD_UWORD PackMode, HD_BOOL Quiet);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_SetGlobErr(HD_ULONG);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_SetTypeRes(HD_QCHAR *Res, HD_UBYTE Car);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_SpilloRbsSave(VG_CTX *Ctx, FILE *FH);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_Str2Dchar(HD_DCHAR *Res, const HD_CHAR *Str);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_Str2Ochar(HD_OCHAR *Res, const HD_CHAR *Str);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_Str2Qchar(HD_QCHAR *, HD_CHAR *);
VEGA_EXTERN HD_CHAR *       VEGA_EXPORT  VG_StrExist(const HD_CHAR *Str);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_SubArg(HD_CHAR **, HD_WORD, HD_BOOL);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_SybFldCalc(VG_CTX *Ctx, FILE *FH);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_SybRgnLoad(FILE *FH, VG_RECORD *Lin, VG_SPACEREG *Reg);

VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_Swap(HD_VOID *);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_Swap64(HD_VOID *);
VEGA_EXTERN HD_DOUBLE       VEGA_EXPORT  VG_SwapD(HD_DOUBLE);
VEGA_EXTERN HD_LONG         VEGA_EXPORT  VG_SwapI(HD_LONG);
VEGA_EXTERN HD_WORD         VEGA_EXPORT  VG_SwapS(HD_WORD Val);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_SwapW(HD_VOID *);
VEGA_EXTERN HD_LONG         VEGA_EXPORT  VG_SwapWrite(FILE *FH, const HD_VOID *Val);

VEGA_EXTERN HD_DOUBLE       VEGA_EXPORT  VG_Torsion(HD_ATOM *a, HD_ATOM *b, HD_ATOM *c, HD_ATOM *d);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_Upper(HD_CHAR *Str);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_VegaGetString(HD_CHAR *Prompt, HD_CHAR *Str, HD_UWORD Len);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_VrmlSave(VG_CTX *Ctx, FILE *FH);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_VrmlCpkSave(VG_CTX *Ctx, FILE *FH);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_VrmlSolSave(VG_CTX *Ctx, FILE *FH);
VEGA_EXTERN HD_LONG         VEGA_EXPORT  VG_Wildncmp(const HD_CHAR *Wild, const HD_CHAR *String, HD_LONG Len);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT  VG_Words(const HD_CHAR *Str);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT  VG_XyzSave(VG_CTX *Ctx, FILE *FH);

/**** Special prototypes for Win32 ****/

#    ifdef WIN32
HD_BOOL                     HD_FASTCALL  LocaleInit(HD_VOID);
HD_BOOL                     HD_FASTCALL  PluginCall(HD_ULONG Num, const HD_CHAR *Name, HD_UWORD Mode, HD_VOID *Arg);
HD_VOID                     HD_FASTCALL  PluginFree(HD_VOID);
HD_ULONG                    HD_FASTCALL  PluginLoad(HD_VOID);
HD_VOID                     HD_FASTCALL  PluginMenuCall(HD_ULONG MenuItem);
HD_VOID                     HD_FASTCALL  PluginMenuChange(HD_ULONG Com);
HD_VOID                     HD_FASTCALL  PluginSendMessageAll(HD_LONG Msg, HD_LONG Par1, HD_LONG Par2);
HD_VOID                     HD_FASTCALL  PluginSetReturnStr(HD_VOID);
HD_VOID                     HD_FASTCALL  ResetGlobErr(HD_VOID);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_ShowLastErr(HD_VOID);
HD_BOOL                     HD_FASTCALL  WinErr(HD_VOID);
#    endif

/**** Special prototypes for Linux and Win32 ****/

#    if defined(LINUX) || defined(WIN32)

/**** Flags for VG_GetProcAddresses() ****/

#    define  VG_GETPROC_NONE            0
#    define  VG_GETPROC_VERBOSE         1
#    define  VG_GETPROC_LIBSDIR         2

VEGA_EXTERN HD_BOOL         VEGA_EXPORTA VG_AddProcAddresses(HD_VOID *hLibrary, ...);
VEGA_EXTERN HD_BOOL         VEGA_EXPORTA VG_GetProcAddresses(HD_VOID **hLibrary, const HD_CHAR *lpszLibrary, HD_LONG Flags, ...);
VEGA_EXTERN HD_VOID         VEGA_EXPORT  VG_SafeFreeLibrary(HD_VOID *);

#    endif

#  ifdef __cplusplus
}
#  endif
#endif

