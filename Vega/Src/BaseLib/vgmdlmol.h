
/*************************************************
****      VEGA - MDL Mol loader & saver       ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_MDLMOL_H
#  define  __VG_MDLMOL_H
#  include <hdmemstream.h>

/**** V2000 charges ****/

#  define  VG_MDLCHG_ZERO           0     /*  0              */
#  define  VG_MDLCHG_P3             1     /* +3              */
#  define  VG_MDLCHG_P2             2     /* +2              */
#  define  VG_MDLCHG_P1             3     /* +1              */
#  define  VG_MDLCHG_RAD            4     /* Doublet radical */
#  define  VG_MDLCHG_N1             5     /* -1              */
#  define  VG_MDLCHG_N2             6     /* -2              */
#  define  VG_MDLCHG_N3             7     /* -3              */

/**** Saver flags ****/

#  define  VG_MDLFLG_NONE           0
#  define  VG_MDLFLG_DBEND          1
#  define  VG_MDLFLG_DBNAME         2
#  define  VG_MDLFLG_CRLF           4
#  define  VG_MDLFLG_LF             8
#  define  VG_MDLFLG_V3000         16

/**** V3000 loader tags ****/

#  define  VG_MDL3_LM_ATOM          0
#  define  VG_MDL3_LM_BOND          1
#  define  VG_MDL3_LM_CTAB          2
#  define  VG_MDL3_LM_NONE          3

/**** Tags ****/

extern const HD_CHAR *  MdlTag_AXXAMCODE;
extern const HD_CHAR *  MdlTag_DBNAME;
extern const HD_CHAR *  MdlTag_DBEND;
extern const HD_CHAR *  MdlTag_DRUGBANK;
extern const HD_CHAR *  MdlTag_PUBCHEMSYN;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_MdlMolLoad                      _VG_MdlMolLoad
#    define  VG_MdlMolLoadMem                   _VG_MdlMolLoadMem
#    define  VG_MdlMol3Load                     _VG_MdlMol3Load
#    define  VG_MdlMol3LoadMem                  _VG_MdlMol3LoadMem
#    define  VG_MdlMolSave                      _VG_MdlMolSave
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_MdlMolLoad(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_BOOL *IsMulti);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_MdlMolLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Line, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_BOOL *IsMulti);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_MdlMol3Load(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *       VEGA_EXPORT VG_MdlMol3LoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_MdlMolSave(VG_CTX *Ctx, FILE *FH, HD_STRING FileName, HD_LONG Flags);

#  ifdef __cplusplus
}
#  endif
#endif
