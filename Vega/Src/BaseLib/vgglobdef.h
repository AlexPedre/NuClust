
/*************************************************
****         VEGA - Global definitions        ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef  __VG_GLOBDEF_H
#  define  __VG_GLOBDEF_H

#  include <stdio.h>
#  include <hdatom.h>
#  include <hdcpu.h>
#  include <hdmm.h>

#  include "vgversion.h"

#  define  VEGA_FF_UNIV_FILE    "UNIV.tem"

/**** MOPAC preference flags ****/

#  define  VG_MOPAC_CALCHG      32000
#  define  VG_MOPAC_NOMMOK      0
#  define  VG_MOPAC_MMOK        1
#  define  VG_MOPAC_MMOKAUTO    2

/**** Math macros ****/

#  if defined (__cplusplus) && defined(__BORLANDC__) && (__BORLANDC__ > 0x550)
#    define min(x,y)            ((x)<(y)?(x):(y))
#    define max(x,y)            ((x)>(y)?(x):(y))
#  endif

#  define  SQR                  sqrt
#  define  vgCube(X)            ((X) * (X) * (X))
#  define  Quad(X)              ((X) * (X))
#  define  QuadDist(A,B)        (Quad((A) -> x - (B) -> x) +  \
                                 Quad((A) -> y - (B) -> y) +  \
                                 Quad((A) -> z - (B) -> z))
#  define  vgDistance(A,B)      (SQR(QuadDist((A), (B))))
#  define  VG_QUOTE_(x)         #x
#  define  VG_QUOTE(x)          VG_QUOTE_(x)

/**** Math constants ****/

#  define  VG_MAXTRJATM         12          /* Max number of atom in trajectory analysis */
#  define  RETURNSTR_SIZE       4096        /* Size of the return string                 */
#  define  SRFNAMELEN           100         /* Max lenght of surface name                */
#  define  VG_CONNTOL           20.0        /* Default connectivity tolerance            */
#  define  VG_INFINITE          ((HD_FLOAT)3.4e+38)
#  define  VG_LINELEN           256         /* I/O line buffer length I/O                */
#  define  VG_MAX_PATH          256         /* Max path length                           */
#  define  VG_SCORE_MAXENE      3           /* Max energies for score calculation        */

/**** Type of molecule ****/

#  define  MOL_UNK              0          /* Unknown      */
#  define  MOL_PROT             1          /* Protein      */
#  define  MOL_NUCAC            2          /* Nucleic acid */

/**** Type of charge template ****/

#  define  CHARGE_FORMAL        0
#  define  CHARGE_FRAG          1
#  define  CHARGE_GAST          2

/**** Options for VG_SubArg subroutine ****/

#  define  SUBA_NOCHK           0
#  define  SUBA_TOUP            1
#  define  SUBA_POSFLOAT        2
#  define  SUBA_POSINT          3

/**** Error modes ****/

#  define  VG_ERRMOD_CONSOLE    0
#  define  VG_ERRMOD_WINDOW     1
#  define  VG_ERRMOD_QUIET      2

/**** Hook functions ****/

#  define  VG_HOOKFUNC_SECSTRUCTSEL     0     /* FastaLoad() */
#  define  VG_HOOKFUNC_NUM              1

#  define  VG_HOOKFUNC_CALL(X)          VegaSet.HookFunc[X].Func(VegaSet.HookFunc[X].UserData)
#  define  VG_HOOKFUNC_CHECK(X)         (VegaSet.HookFunc[X].Func)

/**** Move modes ****/

#  define  VG_MOVE_ALL                  0
#  define  VG_MOVE_MOL                  1
#  define  VG_MOVE_RES                  2
#  define  VG_MOVE_SEG                  3

/**** Parameters for surface calculation ****/

#  define  VG_ILM_PROBE_RAD             1.4
#  define  VG_VLOGP_DOT_DENSITY         10
#  define  VG_VLOGP_PROBE_RAD           1.5

/**** Parameter types ****/

#  define  VG_PARTYPE_UNK               0
#  define  VG_PARTYPE_BOOL              1
#  define  VG_PARTYPE_CHAR              2
#  define  VG_PARTYPE_FLOAT             3
#  define  VG_PARTYPE_INT               4
#  define  VG_PARTYPE_UNSIGNED          8
#  define  VG_PARTYPE_NOZERO           16
#  define  VG_PARTYPE_MAX              32
#  define  VG_PARTYPE_MIN              64
#  define  VG_PARTYPE_CMTX            128

#  define  VG_PARTYPE_MCHAR             (VG_PARTYPE_CHAR|VG_PARTYPE_CMTX)
#  define  VG_PARTYPE_RCHAR             (VG_PARTYPE_CHAR|VG_PARTYPE_MAX|VG_PARTYPE_MIN)
#  define  VG_PARTYPE_UFLOAT            (VG_PARTYPE_FLOAT|VG_PARTYPE_UNSIGNED)
#  define  VG_PARTYPE_RUFLOAT           (VG_PARTYPE_FLOAT|VG_PARTYPE_UNSIGNED|VG_PARTYPE_MAX|VG_PARTYPE_MIN)
#  define  VG_PARTYPE_ZUFLOAT           (VG_PARTYPE_FLOAT|VG_PARTYPE_UNSIGNED|VG_PARTYPE_NOZERO)
#  define  VG_PARTYPE_UINT              (VG_PARTYPE_INT|VG_PARTYPE_UNSIGNED)
#  define  VG_PARTYPE_RUINT             (VG_PARTYPE_INT|VG_PARTYPE_UNSIGNED|VG_PARTYPE_MAX|VG_PARTYPE_MIN)
#  define  VG_PARTYPE_ZINT              (VG_PARTYPE_INT|VG_PARTYPE_NOZERO)
#  define  VG_PARTYPE_ZUINT             (VG_PARTYPE_INT|VG_PARTYPE_UNSIGNED|VG_PARTYPE_NOZERO)

/**** Reset the endian definitions ****/

#  ifdef BIG_ENDIAN
#    undef  BIG_ENDIAN                          /* MSB first: 68000, ibm, net */
#  endif
#  ifdef LITTLE_ENDIAN
#    undef  LITTLE_ENDIAN                       /* LSB first: i386, vax */
#  endif

/**** 64 bit macros ****/

#  if defined(__GNUC__) || defined(__BORLANDC__)
#    define  MakeInt64(X)       X ## LL
#  else
#    define  MakeInt64(X)       X
#  endif


/**** Windows definitions ****/

#  if defined(__WIN32__) && !defined(WIN32)
#    define  WIN32
#  endif

/**** Linux x86 definitions ****/

#  ifdef linux
#    define  VEGA_OSTYPE          3
#    define  LITTLE_ENDIAN
#  endif

/**** Win32 definitions ****/

#  ifdef WIN32
#    if defined (__BORLANDC__) || defined(_MSC_VER)
#      define  VG_USE_EXCEPTION
#    endif

#    define  VEGA_OSTYPE        4
#    define  LITTLE_ENDIAN
#    define  BIODOCK_EXE        "Bin\\Win32\\BioDock.exe"
#    define  WINDD_EXE          "WinDD.exe"
#    define  VG_ERROR_PROMPT    "\n%s %d: %s.\n\n"
#    define  C_DIRSEP           "\\"
#    define  LocPrintf          VG_DosPrintf
#    define  RemoveFile         DeleteFile
#    define  VG_INLINE          __inline

#  else

#    define  C_DIRSEP           "/"
#    define  VG_ERROR_PROMPT    "\n\033[33m%s %d:\033[0m %s.\n\n"
#    define  LocPrintf          fprintf
#    define  RemoveFile         remove
#    define  VG_INLINE          __inline
#  endif

/**** Generic OS *****/

#  ifndef VEGA_OSTYPE
#    define  VEGA_OSTYPE        99
#  endif

#  ifdef LITTLE_ENDIAN
#    define  VG_CENTROID_ELEM   0x6358
#  else
#    define  VG_CENTROID_ELEM   0x5863
#  endif

/**** DLL ****/

#  ifdef VEGABASE_DLL
#    define  VEGA_EXPORT         __cdecl
#    define  VEGA_EXPORTA        __cdecl
#    define  VEGA_EXTERN         __declspec(dllexport)
#    ifdef  VEGABASE_BUILD
#      define  VEGA_EXTERNVAR    extern
#    else
#      define  VEGA_EXTERNVAR    extern __declspec(dllimport)
#    endif
#  else
#    define  VEGA_EXPORT         HD_FASTCALL
#    define  VEGA_EXPORTA
#    define  VEGA_EXTERN
#    define  VEGA_EXTERNVAR      extern
#  endif

#  include "vgopsin.h"

/**** Atom description ****/

typedef struct {
  HD_ULONG         Num;                                 /* Atom number                  */
  HD_QCHAR         Name;                                /* Atom name                    */
  HD_QCHAR         ResName;                             /* Residue name                 */
  HD_QCHAR         ResSeq;                              /* Number of residue            */
} VG_ATMDESC;

/**** Internal coordinates ****/

typedef struct {
  HD_ATOM *             Ptr;
  HD_LONG               na, nb, nc;
  HD_FLOAT              r, w, t;
  HD_LONG               pos[3];
} VG_ATMINT;

/**** Atom list for selection ****/

typedef struct __ATMLST {
  struct __ATMLST *     Ptr;                            /* Pointer to next structure     */
  HD_ULONG              Num;                            /* Atom number                   */
  HD_QCHAR              Name;                           /* Atom name                     */
  HD_QCHAR              ResSeq;                         /* Residue number                */
  HD_QCHAR              ResName;                        /* Residue name                  */
  HD_ATOM *             Atm;                            /* Atom ptr after translation    */
  HD_ULONG              NMol;                           /* Molecule number               */
  HD_BYTE               ChainID;                        /* Chain indicator               */
} VG_ATMLST;

/**** Atom selection (see ATMLST) ****/

#define  VG_ATMSEL_MAXNAME              32

typedef struct __ATMSEL {
  struct __ATMSEL *     Ptr;                            /* Pointer to next structure     */
  HD_BOOL               Active;                         /* Active flag                   */
  HD_CHAR               Name[VG_ATMSEL_MAXNAME];        /* Selection name                */
  HD_LONG               Type;                           /* Selection type                */
  HD_ULONG              TotAtm;                         /* Number of atoms in the list   */
  VG_ATMLST *           BegList;                        /* Atom list                     */
  VG_ATMLST *           LastAtm;                        /* Last atom of the list         */
  VG_ATMLST *           SelAtm;                         /* Selected atom pointer         */
  HD_LONG               SelAtmNum;                      /* Selected atom number          */

  /**** Used by VEGA ZZ ****/

  HD_FLOAT              Base;                           /* Base torsion angle            */
  HD_ULONG              Steps;                          /* Torsion steps                 */
  HD_FLOAT              Window;                         /* Torsion window                */
} VG_ATMSEL;

/**** Parameter context ****/

typedef struct __vg_cparam {
  struct __vg_cparam *  Next;                           /* Pointer to the next item      */
  struct __vg_cparam *  Prev;                           /* Pointer to the previous item  */
  HD_PAR                Data;                           /* Parameter structure data      */
  HD_STRING             FileName;                       /* File name                     */
  HD_STRING             Name;                           /* Parameter name                */
  long                  LastMod;                        /* Time of the last modification */
} VG_CPARAM;

/**** Force field descriptor for atomic types ****/

typedef struct {
  HD_DCHAR              Atom;                           /* Element                       */
  HD_BYTE               NSost;                          /* Number of substituents        */
  HD_BYTE               Ring;                           /* Type of ring                  */
  HD_BYTE               Arom;                           /* The ring is aromatic ?        */
  HD_BYTE               NSub;                           /* Sublevel number               */
} VG_FFDESC;

/**** Force field parameter structure ****/

typedef struct {
  HD_CHAR *         CPtr;
  HD_CHAR *         Beg;
  FILE *            FFIN;                               /* File Handle                   */
  HD_ULONG          Line;                               /* Current template line number  */
  HD_ULONG          TotArgs;                            /* Total number of arguments     */
  HD_UWORD          Args;                               /* Current argument              */
} VG_FFPAR;

/**** File handle ****/

typedef void *      VG_FILE;

/**** File format structure ****/

typedef struct {
  HD_LONG               Id;                             /* Identification code           */
  const HD_CHAR *       Com;                            /* Command token                 */
  const HD_CHAR *       Ext;                            /* File extension                */
  HD_LONG               Flags;                          /* Control flags                 */
  HD_LONG               MsAllow;                        /* Allowed mesures               */
  HD_LONG               Merge;                          /* Merge flags                   */
} VG_FILEFORMAT;

/**** Fingerprint ****/

struct __vg_fingerprint {
  HD_UBYTE *        Data;                               /* Data                          */
  HD_LONG           Ones;                               /* Number of ones                */
  HD_ULONG          Len;                                /* Vector length                 */
};
typedef struct __vg_fingerprint * VG_FINGERPRINT;


/**** Hook function data ****/

typedef struct {
  HD_LONG HD_CALLBACK (*Func)(HD_VOID *UserData);       /* User function                 */
  HD_VOID *           UserData;                         /* User data pointer             */
  HD_LONG             Flags;                            /* Flags                         */
} VG_HOOKFUNC;

/**** Matrix structure ****/

typedef struct {
  HD_DOUBLE        a1, b1, c1;
  HD_DOUBLE        a2, b2, c2;
  HD_DOUBLE        a3, b3, c3;
} VG_MATRIX_3X3;

/**** Types ****/

typedef struct _VgMol2Sub {
  struct _VgMol2Sub *   Ptr;            /* Pointer to the next list element   */
  struct _VgMol2Sub *   ConnSub;        /* Pointer to connected substructures */
  HD_ULONG              SubNum;         /* Progressive number                 */
  HD_ULONG              ConnSubNum;     /* Number of connected substructures  */
  HD_QCHAR              ResName;        /* Residue name                       */
  HD_QCHAR              ResSeq;         /* Residue number                     */
  HD_ULONG              AtmNum;         /* Number of the most important atom  */
  HD_BYTE               ChainID;        /* Chain identificator                */
} VG_MOL2SUB;

/**** Plane coefficients ****/

typedef struct {
  HD_FLOAT     a, b, c, d;
} VG_PLANE;

/**** Preferences ****/

typedef struct {
  HD_CHAR           AMMP_FFIEELD[128]; /* AMMP force field                    */
  HD_CHAR           LANGUAGE[20];   /* Language for strings translation       */
  HD_STRING         MOPAC_DEF;      /* Mopac: default parameters              */
  HD_LONG           MOPAC_CRG;      /* Mopac: total charge                    */
  HD_LONG           MOPAC_MMOK;     /* Mopac: polipeptidic correction         */
  HD_FLOAT          SAS_PROBERAD;   /* SAS: probe radius                      */
  HD_LONG           SAS_POINTS;     /* SAS: points density                    */
  VG_FILEFORMAT *   OUTFORMAT;      /* Number of output format                */
  HD_ULONG          RENSTART;       /* Starting residue for renumber          */
  HD_ULONG          MAXATMINFO;     /* Max atoms for extra infos (-f INFO)    */
  HD_FLOAT          ENCONTDIST;     /* Contact distance for score calculation */
  HD_FLOAT          ENCUTOFF;       /* Cutoff distance for energy calculation */
  HD_FLOAT          ENDIEL;         /* Dielectric for energy calculation      */
  HD_FLOAT          ENFILTER;       /* Filter for energy calculation          */
  HD_LONG           ENNUMLIG;       /* Ligand number for energy calculation   */
  HD_FLOAT          VOL_DEN;        /* Dot density for volume calclulation    */
  HD_FLOAT          VOL_RAD;        /* Volume radius                          */
  HD_FLOAT          SOL_RAD;        /* Solvatation radius                     */
  HD_FLOAT          CONNTOL;        /* Connectivity tolerance (%)             */
  HD_WORD           SOL_SHAPE;      /* Shape (0=Cubic, 1=Sphere, 2=shell      */
  HD_LONG           MAXCPU;         /* Max number of CPUs used by HyperDrive  */
  HD_LONG           OCLDEVTYPE;     /* OpenCL device type                     */
  HD_LONG           XTCPREC;        /* Number of decimals for XTC compression */
  HD_CHAR           PSFFFIELD[128]; /* PSF force field                        */

  /**** OpenGL specific preferences ****/

  HD_ULONG          MOPAC_MAXATM;   /* Mopac: max number of atoms             */
  HD_FLOAT          CHART_ZOOMFACT; /* Zoom in/out factor for chart window    */
  HD_BOOL           SYS_GLASSWIN;   /* Enable/disable glass windows           */
} VG_PREFS;


/**** Print function ****/

typedef HD_LONG HD_STACKCALL (*VG_CONPRINTFUNC)(VG_FILE, const HD_CHAR *, va_list Vl);

/**** Used with loader subroutine ****/

typedef union {
  HD_CHAR               Line[VG_LINELEN + 1];
  HD_LONG               Hdr;
} VG_RECORD;

/**** Parameter for trajectory analysis ****/

typedef struct {
  HD_CHAR **        Arg;                /* Arg list pointer           */
  HD_LONG           Com;                /* Command                    */
  HD_ULONG          Flags;              /* Atom selection flags       */
  HD_CHAR *         OutFile;            /* Ptr to output file name    */
  VG_FILEFORMAT *   OutForm;            /* Output format              */
  VG_ATMDESC        Atm[VG_MAXTRJATM];  /* Atom descriptions          */
  VG_ATMSEL *       Sel;                /* Selection                  */
  HD_UWORD          Num;                /* Number of atoms/args       */
} VG_TRJPAR;

/**** To select a space region ****/

typedef struct {
  HD_ULONG          Points;         /* Number of points            */
  HD_XYZF           Low;            /* Coordinates of lower corner */
  HD_XYZF           Hi;             /* Coordinates of high corner  */
  HD_XYZF           StepS;          /* Step size                   */
  HD_ULONG          StX, StY, StZ;  /* Number of steps             */
  VG_TRJPAR *       Par;            /* Pointer to parameters       */
} VG_SPACEREG;

/**** Score data ****/

typedef struct {
  HD_BOOL               Enabled;                  /* Enabled                    */
  HD_BOOL               Result;                   /* Result                     */
  HD_FLOAT              Energy[VG_SCORE_MAXENE];  /* Energies                   */
  HD_FLOAT *            EnergyVect;               /* Energy vector              */
  HD_LONG *             AaContMap;                /* Amino acid contact map     */
  HD_LONG               Fingerprint;              /* Fingerprint                */
} VG_SCORE_DATA;

/**** Trajectory info ****/

typedef struct {
  HD_CHAR               FileName[VG_MAX_PATH];  /* Trajectory file name         */
  HD_CHAR               MolName[VG_MAX_PATH];   /* Molecule name                */
  HD_CHAR               RmsdName[VG_MAX_PATH];  /* Reference file name          */
  HD_CHAR               LineDel[4];             /* Line delimiter               */
  const HD_CHAR *       Mol2CharTyp;            /* Mol2 charge type             */
  VG_MOL2SUB *          Mol2BegSub;             /* Mol2 substructure list       */
  HD_ULONG              Mol2SubNum;             /* Mol2 number of substructures */
  HD_DLONG *            Mol2Pot;                /* Mol2 atom types              */
  HD_ULONG *            Mol2AtmNum;             /* Mol2 atom number array       */
  HD_ATOM *             BegAtm;                 /* Atom buffer pointer          */
  HD_ATOM **            LastAtm;                /* Last atom pointer            */
  HD_ULONG *            TotalAtm;               /* Pointer to the number of atm */
  HD_ULONG              MolLig;                 /* MLigand molecule ID          */
  HD_ULONG              TotalLig;               /* Number of ligand atoms       */
  FILE *                FH;                     /* File handle                  */
  HD_LONG               AccessMode;             /* File access mode             */
  HD_FLOAT *            Energy;                 /* Energy buffer                */
  HD_ULONG              EneFrames;              /* Energy frames                */
  HD_FLOAT              EneMax, EneMin;         /* Value range                  */
  HD_LONG               Flags;                  /* Flags                        */
  HD_ULONG              EneStep;                /* Energy step                  */
  HD_ULONG              ConvStep;               /* Energy step -> frame step    */
  HD_ULONG              Format;                 /* Trajectory format            */
  HD_ULONG              SubFormat;              /* Trajectory subformat         */
  HD_ULONG              Frames;                 /* Number of frames             */
  HD_ULONG              FramesReal;             /* Real number of frames        */
  HD_ULONG              FrmStep;                /* Frame step                   */
  HD_ULONG              FrmCur;                 /* Current frame number         */
  HD_ULONG              FrmMax;                 /* Max. energy frame            */
  HD_ULONG              FrmMin;                 /* Lowest energy frame          */
  HD_DLONG              FrmSize;                /* Frame size                   */
  HD_LONG               IffCoordFormat;         /* IFF coordinate format        */
  HD_ULONG              MolAtm;                 /* Number of atom               */
  HD_ULONG              MolBonds;               /* Number of bonds              */
  HD_FLOAT              Temp;                   /* Temperature                  */
  HD_ULONG              StartTime;              /* Start time                   */
  HD_DLONG              StartData;              /* File data pointer            */
  HD_DLONG *            SeekTab;                /* Fast seek table              */
  HD_XYZF *             VectorBuf;              /* Vector buffer                */
  HD_FLOAT              Precision;              /* Xdrf compression precision   */
  HD_ATOM *             RmsdStructure;          /* Reference structure          */
  HD_ULONG              RmsdRefFrm;             /* RMSD reference frame         */
  HD_LONG               RmsdMode;               /* RMSD calculation mode        */
  HD_BOOL               SwapEndian;             /* Swap endian flag             */
  HD_BOOL               ActiveOnly;             /* Active atom only             */
  HD_BOOL               DoublePrecision;        /* HD_DOUBLE precision coord.      */
  HD_ULONG              PdbConectNum;           /* Number of CONECT for frame   */
  HD_ULONG              PdbTerNum;              /* Number of TER for frame      */
  HD_ULONG              FixedAtoms;             /* Number of fixed atoms        */
  HD_ULONG              FreeAtoms;              /* Number of fixed atoms        */
  HD_ATOM **            FreeAtomMap;            /* Map of free atoms            */
  HD_DOUBLE             UnitCell[6];            /* Unit cell pointer            */
  HD_ULONG              UnitCellRecSize;        /* Unit cell record size        */

  VG_MATRIX_3X3         CifMatrix;              /* Transformation matrix        */
  HD_BOOL               CifFractCoord;          /* Fractional coordinates       */
  HD_LONG               CifOffModelNum;         /* CIF model number offset      */
  HD_LONG               CifOffX;                /* CIF X-coord offset           */
  HD_LONG               CifOffY;                /* CIF Y-coord offset           */
  HD_LONG               CifOffZ;                /* CIF Z-coord offset           */

  HD_ULONG              InterRatio;             /* Interpolation ratio          */
  HD_ULONG              InterWinSize;           /* Interpolation window size    */
  HD_XYZF **            InterBuf;               /* Interpolation buffers        */
  HD_LONG *             InterKnots;             /* Interpolation knots          */
  HD_ULONG              InterTotKnots;          /* Interpolation num. of knots  */
  HD_ULONG              InterOrder;             /* Interpolation order          */
} VG_TRJINFO;

/**** Workspace ****/

typedef struct __VgWorkSpace {
  struct __VgWorkSpace  *Next;                     /* Pointer to next element     */
  struct __VgWorkSpace  *Prev;                     /* Pointer to prevoius element */
  HD_ULONG              Num;                       /* Workspace number            */
  HD_STRING             Name;                      /* Workspace name              */
  HD_ATOM *             BegAtm;                    /* Atom list begin             */
  HD_ATOM *             LastAtm;                   /* Last atom pointer           */
  HD_LIST *             SrfList;                   /* VG_Surface list                */
  HD_SRFINFO *          SrfInfoCur;                /* Current surface             */
  HD_ULONG              TotalAtm;                  /* Number of atoms             */
  HD_ULONG              AtmLoaded;                 /* Loaded atoms                */
  VG_ATMSEL *           BegSel;                    /* Atom selection              */
  VG_ATMSEL *           LastSel;                   /* Last atom selection         */
  VG_TRJINFO            TrjInfo;                   /* Trajectory data             */

  /**** VEGA ZZ ****/

#ifdef VEGA_ZZ
  HD_LIST *             Redo;                      /* Redo list                   */
  HD_LIST *             Undo;                      /* Undo list                   */
  HD_CHAR               LastFileName[VG_MAX_PATH]; /* Last file name              */
  HD_LONG               LastSaveFileFormat;        /* Last save file format       */
  VG_WKSVIEW            View;                      /* Workspace view              */
  HD_ATOM *             MoveMol;                   /* Molecule to move            */
  VG_GLOBJ *            BegObj;                    /* OpenGL object list          */
  VG_GLOBJ *            LastObj;                   /* Last OpenGL object          */
  HD_ULONG              MenuActFlag;               /* Menu activation             */
  HD_ULONG              TotMol;                    /* Number of molecules         */
#endif
} VG_WRKSPACE;

/**** VEGA context ****/

typedef struct {

  /**** Molecule ***/

  HD_ATOM *         BegAtm;               /* Pointer of the first atom    */
  HD_ATOM *         LastAtm;              /* Pointer of the last atom     */
  HD_ATOM *         PrevAtm;              /* Previous atom see AllocAtm() */
  HD_ULONG          TotalAtm;             /* Number of atoms              */

  /**** Switches ****/

  HD_BOOL           GLOBSW_CACHECHECK;    /* Check if the cache is changed    */
  HD_BOOL           GLOBSW_CONNSAV;       /* Save the connectivity            */
  HD_BOOL           GLOBSW_CONNCALC;      /* Calculate the connectivity       */
  HD_BOOL           GLOBSW_FIXDECSEP;     /* Fix decimal separator            */
  HD_BOOL           GLOBSW_MESTRJ;        /* Make a mesure in trajectory      */
  HD_BOOL           GLOBSW_FIXSAV;        /* Save the constraints             */
  HD_BOOL           GLOBSW_64BIT;         /* 64 bit file format               */
  HD_BOOL           GLOBSW_BIGENDIAN;     /* Big endian file format           */
  HD_BOOL           GLOBSW_LOADMON;       /* Load the monitors                */
  HD_BOOL           GLOBSW_VDWCALC;       /* Assign de VdW radii              */

  HD_CHAR *         DbGetName;
  HD_LIST *         SrfList;              /* List of surfaces                 */
  HD_LIST *         WksList;              /* List of workspaces               */
  HD_LONG           InfoXmlProp[2];       /* InfoXML flags                    */
  HD_LONG           WorkSpaceLock;
  HD_STRING         DcdFile;              /* Name of trajectory file          */
  HD_STRING         FFName;               /* Force filed name (IFF)           */
  HD_SRFINFO *      SrfInfoCur;           /* Current surface                  */
  HD_ULONG          AtmLoaded;
  HD_ULONG          GlobErr;
  HD_ULONG          ErrMode;
  HD_VOID *         Catalog;
  VG_ATMSEL *       BegSel;
  VG_ATMSEL *       LastSel;
  VG_SCORE_DATA *   ScoreData;            /* Score data                       */
  VG_SPACEREG       Region;
  VG_TRJINFO        TrjInfo;
  VG_WRKSPACE *     WksCur;

  /**** Mopac ****/

  HD_BOOL           MopacFlag;            /* TRUE when manual parameters      */
  HD_STRING         MopacDef;             /* Mopac default keywords           */

  /**** Fasta loader ****/

  HD_LONG           FastaCapCterm;      /* C-Term capping                     */
  HD_LONG           FastaCapNterm;      /* N-Term capping                     */
  HD_LONG           FastaSecStrFlags;   /* Secondary structure flags          */

  /**** Used by VEGA ZZ ****/

  HD_CHAR *         ReturnStr;
  HD_LONG           BorderSize, DpiX, DpiY, WinOffsetY;
  HD_ULONG          ReturnStrLen;
} VG_CTX;

/**** Global settings ****/

typedef struct {
  HD_BOOL           Destroying;                   /* Destroying flag (VEGA ZZ)   */
  HD_BOOL           GLOBSW_OPENGL;                /* OpenGL mode                 */
  HD_BOOL           GLOBSW_STDOUT;                /* Set the output to stdout    */
  HD_CPUINFO        CpuInfo;                      /* CPU information             */
  const HD_FLOAT *  DvResTab;                     /* Mean residue diameter       */
  HD_FLOAT *        DvSumMtx;
  HD_LONG           ErrMode;                      /* Error mode                  */
  const HD_QCHAR *  AAResTab;                     /* Residue table               */
  HD_ULONG          GlobErr;                      /* Global error code           */
  HD_VOID *         Catalog;                      /* Catalog handle              */
  HD_LIST *         CharmmParList;                /* Charmm parameter  list      */
  HD_VOID *         ZipUserFunc;                  /* Zip user functions          */

  /**** Caches ****/

  HD_STRING *       PathsCache;     /* File path cache                        */
  HD_LIST *         HybTemCache;    /* Hybridization template cache           */
  HD_MUTEX          PkInfoMtx;      /* File cache mutex                       */
  HD_LIST *         PkInfoCache;    /* File cache                             */

  /**** Database ****/

  const HD_CHAR *   DbDataStr;      /* Default database.dat file name         */
  HD_LIST *         DbList;         /* Database list                          */
  HD_ULONG          OpenCallNum;    /* DbOpen() counter                       */

  /**** Hook functions ****/

  VG_HOOKFUNC       HookFunc[VG_HOOKFUNC_NUM];

  /**** Preference pointers ****/

  HD_CHAR *         AMMP_FFIEELD;   /* AMMP force field                       */
  HD_CHAR *         LANGUAGE;       /* Language for strings translation       */
  HD_CHAR *         PSFFFIELD;      /* PSF force field                        */
  HD_FLOAT *        CONNTOL;        /* Connectivity tolerance (%)             */
  HD_FLOAT *        ENDIEL;         /* Dielectric constant                    */
  HD_FLOAT *        SAS_PROBERAD;   /* SAS: probe radius                      */
  HD_FLOAT *        SOL_RAD;        /* Solvatation radius                     */
  HD_FLOAT *        VOL_DEN;        /* Dot density for volume calclulation    */
  HD_FLOAT *        VOL_RAD;        /* Volume radius                          */
  HD_LONG *         ENNUMLIG;       /* Ligand number for energy calculation   */
  HD_LONG *         MAXCPU;         /* Max number of CPUs used by HyperDrive  */
  HD_LONG *         MOPAC_CRG;      /* Mopac: total charge                    */
  HD_LONG *         MOPAC_MMOK;     /* Mopac: polipeptidic correction         */
  HD_LONG *         SAS_POINTS;     /* SAS: points density                    */
  HD_LONG *         XTCPREC;        /* Number of decimals for XTC compression */
  HD_ULONG *        MAXATMINFO;     /* Max atoms for extra infos (-f INFO)    */
  HD_WORD *         SOL_SHAPE;      /* Shape (0=Cubic, 1=Sphere, 2=shell      */
  VG_FILEFORMAT **  OUTPUTFORMAT;   /* Ouytput file format                    */

  /**** Custom functions ****/

  VG_CONPRINTFUNC   ConPrintf;
  HD_LONG           HD_STACKCALL (*AmmpPrintf)(FILE *FH, const HD_CHAR *Fmt, ...);
  HD_LONG           HD_FASTCALL  (*GL_MessageBox)(const HD_CHAR *Msg, const HD_CHAR *Title, HD_LONG Flags);
  HD_VOID           HD_FASTCALL  (*QueueSync)(HD_VOID);

  /**** Library handles ****/

  VG_OPSIN          hOpsin;

#if defined(LINUX) || defined(WIN32)
  HD_VOID *         hIndigo;
  HD_VOID *         hIndigoRenderer;
  HD_VOID *         hInChI;
  HD_VOID *         hLibBz2;
  HD_VOID *         hNetCdf;
  HD_VOID *         hSQLite;
  HD_VOID *         hZ32;
  HD_VOID *         hZip32;
  HD_VOID *         hZipLib;
  HD_VOID *         hZlib32;
#  ifdef USE_XDRF_DLL
  HD_VOID *         hXdrf;
#  endif
#endif
} VG_SETTINGS;

#endif
