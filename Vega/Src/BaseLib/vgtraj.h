
/*************************************************
****         VEGA - Trajectory header         ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __TRAJ
#  define  __TRAJ
#  include  "vgglobdef.h"

#  include "vgformats.h"
#  include "vgmol2.h"

/**** Macros ****/

#  define  AutoDockSeekFrm      VG_PDBSeekFrm
#  define  CarSeekFrm           VG_PDBSeekFrm
#  define  MdlMolSeekFrm        VG_PDBSeekFrm
#  define  Mol2SeekFrm          VG_PDBSeekFrm

#  define  VG_TRJ_RMSD_FRAME    0       /* Don't change the order    */
#  define  VG_TRJ_RMSD_PREVFRM  1
#  define  VG_TRJ_RMSD_FILE     2

/**** File access modes ****/

#  define  VG_TRJ_FACC_READ     0
#  define  VG_TRJ_FACC_WRITE    1
#  define  VG_TRJ_FACC_UPDATE   2

/**** Flags ****/

#  define  VG_TRJ_FLAG_NONE     0

/**** AutoDock flags ****/

#  define  VG_TRJ_FLAG_AD_CONN  1       /* Build the connectivity    */
#  define  VG_TRJ_FLAG_AD_COORD 2       /* Read the coordinates      */

/**** Generic flags ****/

#  define  VG_TRJ_FLAG_BOX      4       /* Read/write the cell box   */

/**** Save trajectory flags ****/

#  define  VG_TRJ_SAVE_NONE     0       /* Don't change the order    */
#  define  VG_TRJ_SAVE_ACTONLY  1
#  define  VG_TRJ_SAVE_SWAPEND  2
#  define  VG_TRJ_SAVE_APPEND   4

/**** IFF coordinate format ****/

#  define  VG_TRJ_IFF_XYZ1      0
#  define  VG_TRJ_IFF_XYZ2      1

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_AmberClose                      _VG_AmberClose
#    define  VG_AmberCreate                     _VG_AmberCreate
#    define  VG_AmberOpen                       _VG_AmberOpen
#    define  VG_AmberReadFrm                    _VG_AmberReadFrm
#    define  VG_AmberSeekFrm                    _VG_AmberSeekFrm
#    define  VG_AmberWriteFrm                   _VG_AmberWriteFrm

#    define  VG_AmberNcClose                    _VG_AmberNcClose
#    define  VG_AmberNcCreate                   _VG_AmberNcCreate
#    define  VG_AmberNcOpen                     _VG_AmberNcOpen
#    define  VG_AmberNcReadFrm                  _VG_AmberNcReadFrm
#    define  VG_AmberNcSeekFrm                  _VG_AmberNcSeekFrm
#    define  VG_AmberNcWriteFrm                 _VG_AmberNcWriteFrm

#    define  VG_AutoDockClose                   _VG_AutoDockClose
#    define  VG_AutoDockOpen                    _VG_AutoDockOpen
#    define  VG_AutoDockReadFrm                 _VG_AutoDockReadFrm

#    define  VG_BioDockChangeDir                _VG_BioDockChangeDir
#    define  VG_BioDockClose                    _VG_BioDockClose
#    define  VG_BioDockGetFileName              _VG_BioDockGetFileName
#    define  VG_BioDockOpen                     _VG_BioDockOpen
#    define  VG_BioDockReadFrm                  _VG_BioDockReadFrm
#    define  VG_BioDockSeekFrm                  _VG_BioDockSeekFrm

#    define  VG_CarClose                        _VG_CarClose
#    define  VG_CarOpen                         _VG_CarOpen
#    define  VG_CarReadFrm                      _VG_CarReadFrm

#    define  VG_CifClose                        _VG_CifClose
#    define  VG_CifOpen                         _VG_CifOpen
#    define  VG_CifReadFrm                      _VG_CifReadFrm
#    define  VG_CifSeekFrm                      _VG_CifSeekFrm

#    define  VG_CsrClose                        _VG_CsrClose
#    define  VG_CsrOpen                         _VG_CsrOpen
#    define  VG_CsrReadFrm                      _VG_CsrReadFrm
#    define  VG_CsrSeekFrm                      _VG_CsrSeekFrm

#    define  VG_DCDClose                        _VG_DCDClose
#    define  VG_DCDLoadCsv                      _VG_DCDLoadCsv
#    define  VG_DCDLoadEne                      _VG_DCDLoadEne
#    define  VG_DCDLoadNamdOut                  _VG_DCDLoadNamdOut
#    define  VG_DCDOpen                         _VG_DCDOpen
#    define  VG_DCDReadFrm                      _VG_DCDReadFrm
#    define  VG_DCDSeekFrm                      _VG_DCDSeekFrm
#    define  VG_DCDWriteFrm                     _VG_DCDWriteFrm
#    define  VG_DCDWriteHeader                  _VG_DCDWriteHeader

#    define  VG_EscherClose                     _VG_EscherClose
#    define  VG_EscherOpen                      _VG_EscherOpen
#    define  VG_EscherReadFrm                   _VG_EscherReadFrm
#    define  VG_EscherSeekFrm                   _VG_EscherSeekFrm

#    define  VG_GrammClose                      _VG_GrammClose
#    define  VG_GrammOpen                       _VG_GrammOpen
#    define  VG_GrammReadFrm                    _VG_GrammReadFrm
#    define  VG_GrammSeekFrm                    _VG_GrammSeekFrm

#    define  VG_IFFClose                        _VG_IFFClose
#    define  VG_IFFOpen                         _VG_IFFOpen
#    define  VG_IFFReadFrm                      _VG_IFFReadFrm
#    define  VG_IFFSeekFrm                      _VG_IFFSeekFrm
#    define  VG_IFFWriteFrm                     _VG_IFFWriteFrm

#    define  VG_MdlMolClose                     _VG_MdlMolClose
#    define  VG_MdlMolOpen                      _VG_MdlMolOpen
#    define  VG_MdlMolReadFrm                   _VG_MdlMolReadFrm

#    define  VG_Mol2Close                       _VG_Mol2Close
#    define  VG_Mol2InitWrite                   _VG_Mol2InitWrite
#    define  VG_Mol2Open                        _VG_Mol2Open
#    define  VG_Mol2ReadFrm                     _VG_Mol2ReadFrm
#    define  VG_Mol2WriteFrm                    _VG_Mol2WriteFrm
#    define  VG_Mol2WriteHeader                 _VG_Mol2WriteHeader

#    define  VG_OpenPlot                        _VG_OpenPlot

#    define  VG_TrjAnalyzer                     _VG_TrjAnalyzer
#    define  VG_TrjCalc                         _VG_TrjCalc
#    define  VG_TrjCalcEne                      _VG_TrjCalcEne
#    define  VG_TrjClose                        _VG_TrjClose
#    define  VG_TrjFindFormat                   _VG_TrjFindFormat
#    define  VG_TrjInterFree                    _VG_TrjInterFree
#    define  VG_TrjInterInit                    _VG_TrjInterInit
#    define  VG_TrjMemLoad                      _VG_TrjMemLoad
#    define  VG_TrjOpen                         _VG_TrjOpen
#    define  VG_TrjParser                       _VG_TrjParser
#    define  VG_TrjPlotSave                     _VG_TrjPlotSave
#    define  VG_TrjReadFrm                      _VG_TrjReadFrm
#    define  VG_TrjSave                         _VG_TrjSave
#    define  VG_TrjSeekFrm                      _VG_TrjSeekFrm
#    define  VG_TrjWriteFrm                     _VG_TrjWriteFrm

#    define  VG_TrrClose                        _VG_TrrClose
#    define  VG_TrrOpen                         _VG_TrrOpen
#    define  VG_TrrReadFrm                      _VG_TrrReadFrm
#    define  VG_TrrSeekFrm                      _VG_TrrSeekFrm
#    define  VG_TrrWriteFrm                     _VG_TrrWriteFrm

#    define  VG_XtcClose                        _VG_XtcClose
#    define  VG_XtcCreate                       _VG_XtcCreate
#    define  VG_XtcLoadLog                      _VG_XtcLoadLog
#    define  VG_XtcOpen                         _VG_XtcOpen
#    define  VG_XtcReadFrm                      _VG_XtcReadFrm
#    define  VG_XtcSeekFrm                      _VG_XtcSeekFrm
#    define  VG_XtcWriteFrm                     _VG_XtcWriteFrm
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif
VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_AmberClose(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_AmberCreate(const HD_CHAR *FileName, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_AmberOpen(const HD_CHAR *FileName, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_AmberReadFrm(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_AmberSeekFrm(VG_TRJINFO *Info, HD_LONG Frames, HD_LONG Mode);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_AmberWriteFrm(VG_TRJINFO *Info);

VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_AmberNcClose(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_AmberNcCreate(const HD_CHAR *FileName, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_AmberNcOpen(const HD_CHAR *FileName, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_AmberNcReadFrm(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_AmberNcSeekFrm(VG_TRJINFO *Info, HD_LONG Frames, HD_LONG Mode);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_AmberNcWriteFrm(VG_TRJINFO *Info);

VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_AutoDockClose(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_AutoDockOpen(VG_CTX *Ctx, const HD_CHAR *FileName, VG_TRJINFO *Info, HD_BOOL Conn);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_AutoDockReadFrm(VG_CTX *Ctx, VG_TRJINFO *Info);

VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_BioDockChangeDir(const HD_CHAR *FileName);
VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_BioDockClose(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_BioDockGetFileName(HD_CHAR *Dest, const HD_CHAR *Src);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_BioDockOpen(VG_CTX *Ctx, const HD_CHAR *FileName, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_BioDockReadFrm(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_BioDockSeekFrm(VG_TRJINFO *Info, HD_LONG Frames, HD_LONG Mode);

VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_CarClose(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_CarOpen(VG_CTX *Ctx,const HD_CHAR *FileName, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_CarReadFrm(VG_TRJINFO *Info);

VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_CifClose(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_CifOpen(const HD_CHAR *FileName, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_CifReadFrm(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_CifSeekFrm(VG_TRJINFO *Info, HD_LONG Frames, HD_LONG Mode);

VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_CsrClose(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_CsrOpen(const HD_CHAR *FileName, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_CsrReadFrm(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_CsrSeekFrm(VG_TRJINFO *Info, HD_LONG Frames, HD_LONG Mode);

VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_DCDClose(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_DCDLoadCsv(FILE *FH, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_DCDLoadEne(FILE *FH, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_DCDLoadNamdOut(FILE *FH, VG_TRJINFO *Info, HD_BOOL Inter);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_DCDOpen(const HD_CHAR *FileName, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_DCDReadFrm(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_DCDSeekFrm(VG_TRJINFO *Info, HD_LONG Frames, HD_LONG Mode);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_DCDWriteFrm(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_DCDWriteHeader(VG_TRJINFO *Info);

VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_EscherClose(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_EscherOpen(VG_CTX *Ctx, const HD_CHAR *FileName, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_EscherReadFrm(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_EscherSeekFrm(VG_TRJINFO *Info, HD_LONG Frames, HD_LONG Mode);

VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_GrammClose(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_GrammOpen(VG_CTX *Ctx, const HD_CHAR *FileName, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_GrammReadFrm(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_GrammSeekFrm(VG_TRJINFO *Info, HD_LONG Frames, HD_LONG Mode);

VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_IFFClose(VG_TRJINFO *);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_IFFOpen(const HD_CHAR *, VG_TRJINFO *);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_IFFReadFrm(VG_TRJINFO *);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_IFFSeekFrm(VG_TRJINFO *, HD_LONG, HD_LONG);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_IFFWriteFrm(VG_TRJINFO *);

VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_MdlMolClose(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_MdlMolOpen(VG_CTX *Ctx, const HD_CHAR *FileName, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_MdlMolReadFrm(VG_TRJINFO *Info);

VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_Mol2Close(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_Mol2InitWrite(VG_CTX *Ctx, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_Mol2Open(VG_CTX *Ctx, const HD_CHAR *FileName, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_Mol2ReadFrm(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_Mol2WriteFrm(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_Mol2WriteHeader(VG_TRJINFO *Info);

VEGA_EXTERN FILE *     VEGA_EXPORT VG_OpenPlot(const HD_CHAR *FileName, HD_UWORD *Format);

VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_TrjAnalyzer(VG_CTX *Ctx, HD_CHAR *InFileName, HD_CHAR *OutFileName, VG_FILEFORMAT *OutFormat, HD_UWORD PackMode, HD_ATOM *InizAtm, HD_ULONG MolAtm, VG_TRJPAR *Par);
VEGA_EXTERN HD_FLOAT * VEGA_EXPORT VG_TrjCalc(VG_CTX *Ctx, VG_TRJINFO *Info, VG_TRJPAR *Par, HD_ATOM *InizAtm, HD_ULONG MolAtm);
VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_TrjCalcEne(VG_TRJINFO *Info);
VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_TrjClose(VG_TRJINFO *Info);
VEGA_EXTERN HD_UWORD   VEGA_EXPORT VG_TrjFindFormat(const HD_CHAR *FileName);
VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_TrjInterFree(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_TrjInterInit(VG_TRJINFO *Info, HD_ULONG InterRatio, HD_ULONG InterOrder);
VEGA_EXTERN HD_FLOAT * VEGA_EXPORT VG_TrjMemLoad(VG_CTX *Ctx, HD_ULONG *OutFrames, HD_ULONG *OutAtoms, HD_ULONG Start, HD_ULONG End, HD_ULONG Skip, HD_BOOL ActiveOnly);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_TrjOpen(VG_CTX *Ctx, const HD_CHAR *FileName, HD_ATOM *InizAtm, HD_ATOM **LastAtom, VG_TRJINFO *Info, HD_UWORD Format, HD_LONG AccessMode, HD_FLOAT Precision, HD_BOOL Conn);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_TrjParser(VG_TRJPAR *TrjPar);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_TrjPlotSave(VG_CTX *Ctx, const HD_CHAR *FileName, HD_ULONG Format, HD_FLOAT *Data, HD_ULONG Tot);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_TrjReadFrm(VG_CTX *Ctx, VG_TRJINFO *Info, HD_ULONG Frame);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_TrjSave(VG_CTX *Ctx, HD_CHAR *FileName, HD_FLOAT *InizMem, HD_LONG Format, HD_ULONG Start, HD_ULONG End, HD_ULONG Skip, HD_LONG Flags, HD_FLOAT Precision);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_TrjSeekFrm(VG_TRJINFO *Info, HD_LONG Frames, HD_LONG Mode);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_TrjWriteFrm(VG_CTX *Ctx, VG_TRJINFO *Info);

VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_TrrClose(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_TrrOpen(const HD_CHAR *FileName, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_TrrReadFrm(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_TrrSeekFrm(VG_TRJINFO *Info, HD_LONG Frames, HD_LONG Mode);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_TrrWriteFrm(VG_TRJINFO *Info);

VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_XtcClose(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_XtcCreate(const HD_CHAR *FileName, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_XtcLoadLog(FILE *FH, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_XtcOpen(const HD_CHAR *FileName, VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_XtcReadFrm(VG_TRJINFO *Info);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_XtcSeekFrm(VG_TRJINFO *Info, HD_LONG Frames, HD_LONG Mode);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_XtcWriteFrm(VG_TRJINFO *Info);

#  ifdef __cplusplus
}
#  endif
#endif

