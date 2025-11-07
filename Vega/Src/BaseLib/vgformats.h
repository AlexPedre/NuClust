
/*************************************************
****         VEGA - Format Definitions        ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_FORMATS_H
#  define  __VG_FORMATS_H

/**** Trajectory formats ****/

#  define  FTRJ_NONE                0
#  define  FTRJ_AMBER               1
#  define  FTRJ_AMBERNC             2
#  define  FTRJ_ARC                 3
#  define  FTRJ_AUTODOCK4           4
#  define  FTRJ_BIODOCK             5
#  define  FTRJ_CIF                 6
#  define  FTRJ_CSR                 7
#  define  FTRJ_DCD                 8
#  define  FTRJ_ESCHERNG            9
#  define  FTRJ_GRAMM              10
#  define  FTRJ_IFF                11
#  define  FTRJ_MDLMOL             12
#  define  FTRJ_MOL2               13
#  define  FTRJ_PDB                14
#  define  FTRJ_TRR                15
#  define  FTRJ_XTC                16

#  define  FTRJ_264                17
#  define  FTRJ_265                18
#  define  FTRJ_AVI                19
#  define  FTRJ_AVIXVID            20
#  define  FTRJ_MKV                21
#  define  FTRJ_MOV                22
#  define  FTRJ_MP4                23
#  define  FTRJ_MPEG1              24
#  define  FTRJ_MPEG2TS            25
#  define  FTRJ_MPEG2VOB           26

/**** File format types ****/

#  define  FORM_TYPE_MOLE       65536  /* Molecule                           */
#  define  FORM_TYPE_SURF      131072  /* VG_Surface                            */
#  define  FORM_TYPE_PLOT      262144  /* Plot                               */
#  define  FORM_TYPE_CALC      524288  /* Calculation                        */
#  define  FORM_TYPE_FIELD    1048576  /* COMFA field                        */
#  define  FORM_TYPE_SCREEN   2097152  /* Screen output                      */
#  define  FORM_TYPE_TRAJ     4194304  /* Trajectory output                  */

/**** File formats ****/

#  define  FORM_UNK                 (  0 )
#  define  FORM_PDB_2               (  0 | FORM_TYPE_MOLE)
#  define  FORM_PDB                 (  1 | FORM_TYPE_MOLE)
#  define  FORM_PDB_NONSTD          (  2 | FORM_TYPE_MOLE)
#  define  FORM_BIOSYM_OLD          (  3 | FORM_TYPE_MOLE)
#  define  FORM_BIOSYM              (  4 | FORM_TYPE_MOLE)
#  define  FORM_IFF                 (  5 | FORM_TYPE_MOLE)
#  define  FORM_CSSR                (  6 | FORM_TYPE_MOLE)
#  define  FORM_MOPINT              (  7 | FORM_TYPE_MOLE)
#  define  FORM_XYZ                 (  8 | FORM_TYPE_MOLE)
#  define  FORM_PDB_Q               (  9 | FORM_TYPE_MOLE)
#  define  FORM_QUANTA_SRF          ( 10 | FORM_TYPE_SURF)
#  define  FORM_BIOSYM_SRF          ( 11 | FORM_TYPE_SURF)
#  define  FORM_PDB_FAT             ( 12 | FORM_TYPE_MOLE)
#  define  FORM_QMC                 ( 13 | FORM_TYPE_MOLE)
#  define  FORM_QUANTA_MSF          ( 14 | FORM_TYPE_MOLE)
#  define  FORM_VRML_SRF_POINTS     ( 15 | FORM_TYPE_MOLE)
#  define  FORM_VRML_SRF_CPK        ( 16 | FORM_TYPE_MOLE)
#  define  FORM_VRML                ( 17 | FORM_TYPE_MOLE)
#  define  FORM_VRML_SOLID          ( 18 | FORM_TYPE_MOLE)
#  define  FORM_INFO                ( 19 | FORM_TYPE_CALC)
#  define  FORM_FASTA               ( 20 | FORM_TYPE_MOLE)
#  define  FORM_SCORE               ( 21 | FORM_TYPE_CALC)
#  define  FORM_MOL2                ( 22 | FORM_TYPE_MOLE)
#  define  FORM_CRD                 ( 23 | FORM_TYPE_MOLE)
#  define  FORM_GROMOS              ( 24 | FORM_TYPE_MOLE)
#  define  FORM_QUANTA_LOGP         ( 25 | FORM_TYPE_SURF)
#  define  FORM_QUANTA_MEP          ( 26 | FORM_TYPE_SURF)
#  define  FORM_GROMOS_NM           ( 27 | FORM_TYPE_MOLE)
#  define  FORM_PLOT_CSV            ( 28 | FORM_TYPE_PLOT)
#  define  FORM_PLOT_QUANTA         ( 29 | FORM_TYPE_PLOT)
#  define  FORM_PLOT_BIN            ( 30 | FORM_TYPE_PLOT)
#  define  FORM_COMFAFLD            ( 31 | FORM_TYPE_FIELD)
#  define  FORM_QUANTA_ILM          ( 32 | FORM_TYPE_SURF)
#  define  FORM_HIN                 ( 33 | FORM_TYPE_MOLE)
#  define  FORM_PDB_ATDL            ( 34 | FORM_TYPE_MOLE)
#  define  FORM_MDLV2000            ( 35 | FORM_TYPE_MOLE)
#  define  FORM_GAMESS              ( 36 | FORM_TYPE_MOLE)
#  define  FORM_ALCHEMY             ( 37 | FORM_TYPE_MOLE)
#  define  FORM_CSV_SRF             ( 38 | FORM_TYPE_SURF)
#  define  FORM_CSV_ILM             ( 39 | FORM_TYPE_SURF)
#  define  FORM_CSV_LOGP            ( 40 | FORM_TYPE_SURF)
#  define  FORM_CSV_MEP             ( 41 | FORM_TYPE_SURF)
#  define  FORM_PSFX                ( 42 | FORM_TYPE_MOLE)
#  define  FORM_C3DCC1              ( 43 | FORM_TYPE_MOLE)
#  define  FORM_CRT                 ( 44 | FORM_TYPE_MOLE)
#  define  FORM_TINKER_XYZ          ( 45 | FORM_TYPE_MOLE)
#  define  FORM_GAUSSIAN_OUT        ( 46 | FORM_TYPE_MOLE)
#  define  FORM_GAUSSIAN_IN         ( 47 | FORM_TYPE_MOLE)
#  define  FORM_RIFF                ( 48 | FORM_TYPE_MOLE)
#  define  FORM_CPMDXYZ             ( 49 | FORM_TYPE_MOLE)
#  define  FORM_AMMP                ( 50 | FORM_TYPE_MOLE)
#  define  FORM_CML                 ( 51 | FORM_TYPE_MOLE)
#  define  FORM_CML2                ( 52 | FORM_TYPE_MOLE)
#  define  FORM_PQR_PDB             ( 53 | FORM_TYPE_MOLE)
#  define  FORM_PQR_XML             ( 54 | FORM_TYPE_MOLE)
#  define  FORM_CHEMSOL             ( 55 | FORM_TYPE_MOLE)
#  define  FORM_MDLV3000            ( 56 | FORM_TYPE_MOLE)
#  define  FORM_INFOXML             ( 57 | FORM_TYPE_CALC)
#  define  FORM_CIF                 ( 58 | FORM_TYPE_MOLE)
#  define  FORM_MMCIF               ( 59 | FORM_TYPE_MOLE)
#  define  FORM_PDB_LARGE           ( 60 | FORM_TYPE_MOLE)
#  define  FORM_MOPCAR              ( 61 | FORM_TYPE_MOLE)
#  define  FORM_MOPZMAT             ( 62 | FORM_TYPE_MOLE)
#  define  FORM_INCHI               ( 63 | FORM_TYPE_MOLE)
#  define  FORM_INCHIAUX            ( 64 | FORM_TYPE_MOLE)
#  define  FORM_PDB_QT_AD           ( 65 | FORM_TYPE_MOLE)
#  define  FORM_SMILES              ( 66 | FORM_TYPE_MOLE)
#  define  FORM_INDIGO              ( 67 | FORM_TYPE_MOLE)
#  define  FORM_INCHIKEY            ( 68 | FORM_TYPE_MOLE)
#  define  FORM_PDB_QT_VINA         ( 69 | FORM_TYPE_MOLE)
#  define  FORM_SPILLO_RBS          ( 70 | FORM_TYPE_MOLE)
#  define  FORM_NAMDBIN             ( 71 | FORM_TYPE_MOLE)
#  define  FORM_CDX                 ( 72 | FORM_TYPE_MOLE)
#  define  FORM_LIGEN_GRID_SRF      ( 73 | FORM_TYPE_SURF)
#  define  FORM_LIGEN_GRIDBIN_SRF   ( 74 | FORM_TYPE_SURF)
#  define  FORM_LIGEN_PHARM_SRF     ( 75 | FORM_TYPE_SURF)
#  define  FORM_LIGEN_PHARMBIN_SRF  ( 76 | FORM_TYPE_SURF)
#  define  FORM_LIGEN_POCKET        ( 77 | FORM_TYPE_MOLE)
#  define  FORM_LIGEN_POCKETBIN     ( 78 | FORM_TYPE_MOLE)
#  define  FORM_EMPIRECAR           ( 79 | FORM_TYPE_MOLE)
#  define  FORM_PDB_OPENMM          ( 80 | FORM_TYPE_MOLE)

#  ifndef VEGA_ZZ
#    define  FORM_TRAJ_AMBER        ( FTRJ_AMBER   | FORM_TYPE_TRAJ)
#    define  FORM_TRAJ_AMBERNC      ( FTRJ_AMBERNC | FORM_TYPE_TRAJ)
#    define  FORM_TRAJ_DCD          ( FTRJ_DCD     | FORM_TYPE_TRAJ)
#    define  FORM_TRAJ_IFF          ( FTRJ_IFF     | FORM_TYPE_TRAJ)
#    define  FORM_TRAJ_MOL2         ( FTRJ_MOL2    | FORM_TYPE_TRAJ)
#    define  FORM_TRAJ_PDB          ( FTRJ_PDB     | FORM_TYPE_TRAJ)
#    define  FORM_TRAJ_TRR          ( FTRJ_TRR     | FORM_TYPE_TRAJ)
#    define  FORM_TRAJ_XTC          ( FTRJ_XTC     | FORM_TYPE_TRAJ)
#  endif

/**** Save trajectory flags ****/

#  define  FTRJ_FLAG_NONE          0 /* Don't change the order */
#  define  FTRJ_FLAG_ACTONLY       1
#  define  FTRJ_FLAG_SWAPEND       2
#  define  FTRJ_FLAG_APPEND        4

/**** Plot data flags ****/

#  define  FPLOT_FLG_TRAJ          256

/**** Plot data formats ****/

#  define  FPLOT_UNK                0
#  define  FPLOT_CHARMMENE         (1 | FPLOT_FLG_TRAJ)
#  define  FPLOT_CSV                2
#  define  FPLOT_DIF                3
#  define  FPLOT_GROMACSLOG        (4 | FPLOT_FLG_TRAJ)
#  define  FPLOT_NAMDOUT           (5 | FPLOT_FLG_TRAJ)

/**** VG_Surface output formats ****/

#  define  SRF_QUANTA              0
#  define  SRF_CSV                 1
#  define  SRF_IFF                 2
#  define  SRF_INSIGHT             3
#  define  SRF_RAW                 4
#  define  SRF_VRML_POINTS         5
#  define  SRF_VRML_SOLID          6

/**** VG_Surface properties ****/

#  define  SRF_PROP_VDW        0x00000100
#  define  SRF_PROP_VLOGP      0x00000200
#  define  SRF_PROP_MEP        0x00000300
#  define  SRF_PROP_ILM        0x00000400
#  define  SRF_PROP_PSA        0x00000500
#  define  SRF_PROP_DEEP       0x00000600
#  define  SRF_PROP_HBACC      0x00000700
#  define  SRF_PROP_HBDON      0x00000800

/**** Biosym subformats ****/

#  define  BIOSYM_OLD              1
#  define  BIOSYM_NEW              3

/**** CIF subformats ****/

#  define  CIF_PURE                0
#  define  CIF_MM                  1

/**** CSSR subformats ****/

#  define  CSSR_PURE               0
#  define  CSSR_QMC                1

/**** MOPAC flags ****/

#  define  MOPAC_FLG_NONE          0
#  define  MOPAC_FLG_ATMFIX        1

/**** PDB subformats ****/

#  define  PDB_PURE                0
#  define  PDB_NONSTD              1
#  define  PDB_PDBQ                2
#  define  PDB_FAT                 3
#  define  PDB_ATDL                4
#  define  PDB_ORAC                5
#  define  PDB_2                   6
#  define  PDB_PQR                 7
#  define  PDB_LARGE               8
#  define  PDB_SPILLO              9
#  define  PDB_OPENMM             10

/**** PDBQT subformats ****/

#  define  PDBQT_AUTODOCK          0
#  define  PDBQT_VINA              1

/**** PSF subformats ****/

#  define  PSF_CHARMM              0
#  define  PSF_XPLOR               1

/**** Chem3D subformats ****/

#  define C3D_CC1                  0
#  define C3D_CC2                  1
#  define C3D_MMADS                2

/**** Selection types ****/

#  define  SL_DISTANCE             0
#  define  SL_BOND                 1
#  define  SL_ANGLE                2
#  define  SL_TORSION              3
#  define  SL_PLANEANG             4
#  define  SL_MULTI                5
#  define  SL_NONE                 6

/**** Merge fields ****/

#  define  VG_MERGE_NONE           0
#  define  VG_MERGE_ATMCHARGE      1
#  define  VG_MERGE_ATMNAME        2
#  define  VG_MERGE_ATMTYPE        4
#  define  VG_MERGE_CHAINID        8
#  define  VG_MERGE_CONN          16
#  define  VG_MERGE_CONSTR        32
#  define  VG_MERGE_COORD         64
#  define  VG_MERGE_ELEMENT      128
#  define  VG_MERGE_MOLID        256
#  define  VG_MERGE_RESNAME      512
#  define  VG_MERGE_RESSEQ      1024
#  define  VG_MERGE_SEGMENTS    2048

#  define  VG_MERGE_ALL          (0xffffffff)
#  define  VG_MERGE_CAR          (VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_RESNAME|VG_MERGE_RESSEQ|VG_MERGE_SEGMENTS|VG_MERGE_ATMCHARGE|VG_MERGE_ATMTYPE)
#  define  VG_MERGE_MOL2         (VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_RESNAME|VG_MERGE_RESSEQ|VG_MERGE_ATMCHARGE|VG_MERGE_ATMTYPE|VG_MERGE_CHAINID|VG_MERGE_CONN)
#  define  VG_MERGE_PDB          (VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_RESNAME|VG_MERGE_RESSEQ|VG_MERGE_CHAINID|VG_MERGE_SEGMENTS|VG_MERGE_CONN)
#  define  VG_MERGE_PDBQT        (VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_RESNAME|VG_MERGE_RESSEQ|VG_MERGE_ATMCHARGE|VG_MERGE_ATMTYPE)

#  define  MS_NONE                 0      /* Please don't chenge the order */
#  define  MS_DISTANCE             1
#  define  MS_ANGLE                2
#  define  MS_TORSION              4
#  define  MS_PLANEANG             8
#  define  MS_VLOGP               16
#  define  MS_DIPOLE              32
#  define  MS_SURFACE             64
#  define  MS_SURFDIA            128
#  define  MS_VOLUME             256
#  define  MS_VOLDIA             512
#  define  MS_PSA               1024
#  define  MS_ILM               2048
#  define  MS_LIPBROTO          4096
#  define  MS_LIPCRIPPEN        8192
#  define  MS_RMSD_ALN_H       16384
#  define  MS_GYRRAD           32768
#  define  MS_PROTFOLD         65536
#  define  MS_EXTRACT         131072
#  define  MS_OVALITY         262144
#  define  MS_RMSD_ALN        524288
#  define  MS_RMSD           1048576
#  define  MS_RMSD_H         2097152
#  define  MS_RMSD_HUNG      4194304
#  define  MS_RMSD_HUNG_H    8388608

#  define  MS_ALL             0xffffffff

/**** Control flags for file formats ****/

#  define  FORM_FLAG_NONE         0  /* Nothing                            */
#  define  FORM_FLAG_CONN         1  /* Allow the connectivity calculation */
#  define  FORM_FLAG_CONNAL       2  /* The connectivity is needed         */
#  define  FORM_FLAG_FFCALC       4  /* Allow the force field attribuition */
#  define  FORM_FLAG_CHARGE       8  /* Allow atomic charges attribuition  */
#  define  FORM_FLAG_STDOUT      16  /* Allow the stdout use               */
#  define  FORM_FLAG_CHKCHG      32  /* Check the charges                  */
#  define  FORM_FLAG_CHKFF       64  /* Check the force field              */
#  define  FORM_FLAG_VDW        128  /* Assign VdW radii                   */
#  define  FORM_FLAG_RINGS      256  /* Search for the rings               */
#  define  FORM_FLAG_INONLY     512  /* Input only                         */
#  define  FORM_FLAG_TO3D      1024  /* Convert to 3D                      */
#  define  FORM_FLAG_NOAPPEND  2048  /* Append disabled                    */

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VegaFileInfo                       _VegaFileInfo
#  endif

#  ifdef __MAIN
VEGA_EXTERN VG_FILEFORMAT VegaFileInfo[] = {
/* PDB 2.2         */ { FORM_PDB_2         , "PDB2"      , "pdb" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN,
                        MS_NONE,
                        VG_MERGE_PDB },

/* PDB             */ { FORM_PDB            , "PDB"       , "pdb" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN,
                        MS_NONE,
                        VG_MERGE_PDB },

/* PDB Not Std.    */ { FORM_PDB_NONSTD     , "PDBNOTSTD" , "pdb" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN,
                        MS_NONE,
                        VG_MERGE_PDB },

/* Old Biosym      */ { FORM_BIOSYM_OLD     , "OLDBIOSYM" , "car" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_FFCALC|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG|FORM_FLAG_CHKFF,
                        MS_NONE,
                        VG_MERGE_CAR },

/* New Biosym      */ { FORM_BIOSYM         , "BIOSYM"    , "car" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_FFCALC|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG|FORM_FLAG_CHKFF,
                        MS_NONE,
                        VG_MERGE_CAR },

/* IFF             */ { FORM_IFF            , "IFF"       , "iff" ,
                        FORM_FLAG_CONN|FORM_FLAG_FFCALC|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG|FORM_FLAG_CHKFF,
                        MS_NONE,
                        VG_MERGE_ALL },

/* CSSR            */ { FORM_CSSR           , "CSSR"      , "cssr",
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CONNAL|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_ATMCHARGE|VG_MERGE_CONN },

/* Mopac Int.      */ { FORM_MOPINT         , "MOPINT"    , "dat" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CHARGE,
                        MS_NONE,
                        VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_ATMCHARGE },

/* Xyz             */ { FORM_XYZ            , "XYZ"       , "xyz" ,
                        FORM_FLAG_STDOUT,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD },

/* PDBQ            */ { FORM_PDB_Q          , "PDBQ"      , "pdb" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG,
                        MS_NONE,
                        VG_MERGE_PDB },

/* Quanta VG_Surface  */ { FORM_QUANTA_SRF     , "QUANTASRF" , "srf" ,
                        0,
                        SRF_QUANTA|SRF_PROP_VDW,
                        VG_MERGE_NONE },

/* Insight Surf.   */ { FORM_BIOSYM_SRF     , "BIOSYMSRF" , "srf" ,
                        FORM_FLAG_STDOUT,
                        SRF_INSIGHT|SRF_PROP_VDW,
                        VG_MERGE_NONE },

/* PDB Fat         */ { FORM_PDB_FAT        , "PDBF"      , "pdb" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_FFCALC|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG|FORM_FLAG_CHKFF,
                        MS_NONE,
                        VG_MERGE_PDB|VG_MERGE_ATMCHARGE|VG_MERGE_ATMTYPE },

/* QMC             */ { FORM_QMC            , "QMC"       , "qmc" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CONNAL|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_ATMCHARGE|VG_MERGE_CONN },

/* Quanta Msf      */ { FORM_QUANTA_MSF     , "MSF"       , "msf" ,
                        FORM_FLAG_CONN|FORM_FLAG_FFCALC|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_RESNAME|VG_MERGE_RESSEQ|VG_MERGE_ATMCHARGE },

/* VRML Dot Surf.  */ { FORM_VRML_SRF_POINTS, "VRMLPTS"   , "wrl" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_VDW,
                        MS_NONE,
                        VG_MERGE_NONE },

/* VRML CPK        */ { FORM_VRML_SRF_CPK   , "VRMLCPK"   , "wrl" ,
                        FORM_FLAG_STDOUT,
                        MS_NONE,
                        VG_MERGE_NONE },

/* VRML wireframe  */ { FORM_VRML           , "VRML"      , "wrl" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CONNAL,
                        MS_NONE },
/* VRML Solid Srf  */ { FORM_VRML_SOLID     , "VRMLSOL"   , "wrl" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_VDW,
                        MS_NONE,
                        VG_MERGE_NONE },

/* Informations    */ { FORM_INFO           , "INFO"      , "inf" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CONNAL|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG|FORM_FLAG_RINGS|FORM_FLAG_VDW,
                        MS_NONE,
                        VG_MERGE_NONE },

/* Fasta           */ { FORM_FASTA          , "FASTA"     , "fas" ,
                        FORM_FLAG_STDOUT,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_RESNAME|VG_MERGE_RESSEQ|VG_MERGE_SEGMENTS },

/* Inter. Energy   */ { FORM_SCORE          , "SCORE"     , "xml" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_FFCALC|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG|FORM_FLAG_CHKFF,
                        MS_NONE,
                        VG_MERGE_NONE },

/* Sybyl Mol 2     */ { FORM_MOL2           , "MOL2"      , "mol2",
//                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CONNAL|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG|FORM_FLAG_CHKFF|FORM_FLAG_RINGS,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CONNAL|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG|FORM_FLAG_RINGS,
                        MS_NONE,
                        VG_MERGE_MOL2 },

/* CHARMm CRD      */ { FORM_CRD            , "CRD"       , "CRD" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_RESNAME|VG_MERGE_RESSEQ|VG_MERGE_ATMCHARGE },

/* Gromos          */ { FORM_GROMOS         , "GROMOS"    , "gro" ,
                        FORM_FLAG_STDOUT,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_RESNAME|VG_MERGE_RESSEQ },

/* Quanta LogP Srf */ { FORM_QUANTA_LOGP    , "QUANTALOGP", "srf" ,
                        FORM_FLAG_CONN|FORM_FLAG_CONNAL|FORM_FLAG_VDW|FORM_FLAG_RINGS,
                        MS_NONE,
                        VG_MERGE_NONE },

/* Quanta Mep Srf  */ { FORM_QUANTA_MEP     , "QUANTAMEP" , "srf" ,
                        FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG|FORM_FLAG_VDW,
                        MS_NONE,
                        VG_MERGE_NONE },

/* Gromos nm       */ { FORM_GROMOS_NM      , "GROMOSNM"  , "gro" ,
                        FORM_FLAG_STDOUT,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_RESNAME|VG_MERGE_RESSEQ },

/* CSV Plot        */ { FORM_PLOT_CSV       , "CSV"       , "csv" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CHARGE,
                        MS_ALL,
                        VG_MERGE_NONE },

/* Quanta Plot     */ { FORM_PLOT_QUANTA    , "QUANTAPLT" , "plt" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CHARGE,
                        MS_ALL,
                        VG_MERGE_NONE },

/* Binary Plot     */ { FORM_PLOT_BIN       , "BINPLT"    , "bin" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CHARGE,
                        MS_ALL,
                        VG_MERGE_NONE },

/* COMFA fld       */ { FORM_COMFAFLD       , "COMFAFLD"  , "fld" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CHARGE,
                        MS_VLOGP,
                        VG_MERGE_NONE },

/* Quanta ILM Srf  */ { FORM_QUANTA_ILM     , "QUANTAILM" , "srf" ,
                        FORM_FLAG_CONN|FORM_FLAG_CONNAL|FORM_FLAG_VDW|FORM_FLAG_RINGS,
                        MS_NONE,
                        VG_MERGE_NONE },

/* HyperChem HIN   */ { FORM_HIN            , "HIN"       , "hin",
                        FORM_FLAG_INONLY|FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CONNAL|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG|FORM_FLAG_CHKFF,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_RESNAME|VG_MERGE_RESSEQ|VG_MERGE_SEGMENTS|VG_MERGE_ATMCHARGE|VG_MERGE_ATMTYPE },

/* PDB ATDL        */ { FORM_PDB_ATDL       , "PDBA"     , "pdb" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CONNAL|FORM_FLAG_FFCALC|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG|FORM_FLAG_CHKFF|FORM_FLAG_RINGS,
                        VG_MERGE_PDB|VG_MERGE_ATMCHARGE|VG_MERGE_ATMTYPE,
                        VG_MERGE_NONE },

/* MDL V2000       */ { FORM_MDLV2000       , "MDLMOL"   , "mol" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CONNAL|FORM_FLAG_RINGS,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD },

/* GAMESS          */ { FORM_GAMESS         , "GAMESS"   , "inp" ,
                        FORM_FLAG_STDOUT,
                        MS_NONE,
                        VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_ATMCHARGE },

/* ALCHEMY         */ { FORM_ALCHEMY        , "ALCHEMY"  , "alc" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CONNAL|FORM_FLAG_CHKFF|FORM_FLAG_RINGS,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_ATMCHARGE|VG_MERGE_CONN },

/* Csv VG_Surface     */ { FORM_CSV_SRF        , "CSVSRF"   , "csv" ,
                        FORM_FLAG_STDOUT|SRF_CSV|SRF_PROP_VDW,
                        MS_NONE,
                        VG_MERGE_NONE },

/* Csv ILM Srf     */ { FORM_CSV_ILM        , "CSVILM"   , "csv" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CONNAL|FORM_FLAG_VDW|FORM_FLAG_RINGS,
                        MS_NONE,
                        VG_MERGE_NONE },

/* Csv LogP Srf    */ { FORM_CSV_LOGP       , "CSVLOGP"  , "csv" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CONNAL|FORM_FLAG_VDW|FORM_FLAG_RINGS,
                        MS_NONE,
                        VG_MERGE_NONE },

/* Csv Mep Srf     */ { FORM_CSV_MEP        , "CSVMEP"   , "csv" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG|FORM_FLAG_VDW,
                        MS_NONE,
                        VG_MERGE_NONE },

/* PSF X-Plor      */ { FORM_PSFX          , "PSFX"      , "psf",
                        FORM_FLAG_STDOUT|FORM_FLAG_FFCALC|FORM_FLAG_CONN|FORM_FLAG_CONNAL|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG|FORM_FLAG_CHKFF|FORM_FLAG_RINGS,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_ATMTYPE|VG_MERGE_ATMCHARGE|VG_MERGE_CONN|VG_MERGE_RESNAME|VG_MERGE_RESSEQ },

/* Chem3D          */ { FORM_C3DCC1        , "CC1"       , "cc1",
                        FORM_FLAG_INONLY|FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CONNAL|FORM_FLAG_CHKFF|FORM_FLAG_RINGS,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_ATMTYPE },

/* IUMSC CRT       */ { FORM_CRT           , "CRT"       , "crt",
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CONNAL,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_CONN },

/* TINKER XYZ      */ { FORM_TINKER_XYZ    , "TIXYZ"     , "xyz",
                        FORM_FLAG_INONLY|FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CONNAL|FORM_FLAG_FFCALC|FORM_FLAG_CHKFF,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_CONN|VG_MERGE_ATMTYPE },

/* GAUSSIAN OUT    */ { FORM_GAUSSIAN_OUT   , "GAUSSOUT" , "log",
                        FORM_FLAG_INONLY|FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CONNAL,
                        MS_NONE,
                        VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_ATMCHARGE },

/* GAUSSIAN IN     */ { FORM_GAUSSIAN_IN   , "GAUSSIN"   , "gjf",
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CONNAL,
                        MS_NONE,
                        VG_MERGE_ELEMENT|VG_MERGE_COORD },

/* RIFF            */ { FORM_RIFF           , "RIFF"      , "iff" ,
                        FORM_FLAG_CONN|FORM_FLAG_FFCALC|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG|FORM_FLAG_CHKFF,
                        MS_NONE,
                        VG_MERGE_ALL },

/* CPMD Xyz        */ { FORM_CPMDXYZ         , "CPMDXYZ"  , "xyz" ,
                        FORM_FLAG_STDOUT,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD },

/* AMMP            */ { FORM_AMMP            , "AMMP"     , "amp" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG|FORM_FLAG_CONN|FORM_FLAG_CONNAL,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ATMCHARGE|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_CONN|VG_MERGE_RESNAME },

/* CML             */ { FORM_CML             , "CML"      , "cml" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_CONN },

/* CML 2.0          */ { FORM_CML2            , "CML2"     , "cml" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_CONN },

/* PQR             */ { FORM_PQR_PDB          , "PQR"      , "pqr" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG|FORM_FLAG_VDW,
                        MS_NONE,
                        VG_MERGE_PDB },

/* PQR XML         */ { FORM_PQR_XML          , "PQRXML"   , "xml" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG|FORM_FLAG_VDW,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_ATMCHARGE|VG_MERGE_RESNAME|VG_MERGE_RESSEQ },

/* ChemSol         */ { FORM_CHEMSOL          , "CHEMSOL"  , "cs" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_ATMCHARGE },

/* MDL V3000       */ { FORM_MDLV3000       , "MDLMOL3"   , "mol" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CONNAL|FORM_FLAG_RINGS,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD },

/* Info XML       */  { FORM_INFOXML        , "INFOXML"   , "xml" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_FFCALC|FORM_FLAG_CONN|FORM_FLAG_CONNAL|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG|FORM_FLAG_RINGS|FORM_FLAG_VDW,
                        MS_NONE,
                        VG_MERGE_NONE },

/* CIF            */  { FORM_CIF            , "CIF"       , "cif" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD },

/* mmCIF          */  { FORM_MMCIF          , "MMCIF"     , "cif" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ELEMENT|VG_MERGE_COORD },

/* PDB Large      */  { FORM_PDB_LARGE      , "PDBL"      , "pdb" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN,
                        MS_NONE,
                        VG_MERGE_PDB },

/* Mopac cart.    */  { FORM_MOPCAR         , "MOPCAR"    , "dat" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_CHARGE,
                        MS_NONE,
                        VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_ATMCHARGE },

/* Mopac Z-matrix */  { FORM_MOPZMAT         , "MOPZMAT"  , "arc" ,
                        FORM_FLAG_INONLY|FORM_FLAG_STDOUT|FORM_FLAG_CONN,
                        MS_NONE,
                        VG_MERGE_ELEMENT|VG_MERGE_COORD },

/* InChI          */  { FORM_INCHI           , "INCHI"    , "inchi" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_TO3D|FORM_FLAG_NOAPPEND,
                        MS_NONE,
                        VG_MERGE_NONE },

/* InChI Aux      */  { FORM_INCHIAUX        , "INCHIAUX" , "inchi" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN,
                        MS_NONE,
                        VG_MERGE_NONE },

/* PDBQT AutoDock */  { FORM_PDB_QT_AD       , "PDBQT"    , "pdbqt" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_FFCALC|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG|FORM_FLAG_CHKFF|FORM_FLAG_CONN|FORM_FLAG_CONNAL,
                        MS_NONE,
                        VG_MERGE_PDBQT },

/* Smiles         */  { FORM_SMILES          , "SMILES"   , "smi" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_TO3D|FORM_FLAG_NOAPPEND,
                        MS_NONE,
                        VG_MERGE_NONE },

/* Indigo         */  { FORM_INDIGO          , "INDIGO"   , "indigo" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_TO3D|FORM_FLAG_NOAPPEND,
                        MS_NONE,
                        VG_MERGE_NONE },

/* InChIKey       */  { FORM_INCHIKEY        , "INCHIKEY" , "ikey" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN|FORM_FLAG_TO3D|FORM_FLAG_NOAPPEND,
                        MS_NONE,
                        VG_MERGE_NONE },

/* PDBQT Vina     */  { FORM_PDB_QT_VINA     , "VINA"     , "pdbqt" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_FFCALC|FORM_FLAG_CHARGE|FORM_FLAG_CHKCHG|FORM_FLAG_CHKFF|FORM_FLAG_CONN|FORM_FLAG_CONNAL,
                        MS_NONE,
                        VG_MERGE_PDBQT },

/* Spillo RBS     */  { FORM_SPILLO_RBS     , "SPILLORBS" , "rbs" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN,
                        MS_NONE,
                        VG_MERGE_PDB },

/* NAMD bin       */  { FORM_NAMDBIN        , "NAMDBIN"   , "coor" ,
                        FORM_FLAG_NONE,
                        MS_NONE,
                        VG_MERGE_COORD },

/* ChemDraw CDX   */  { FORM_CDX            , "CDX"       , "cdx"  ,
                        FORM_FLAG_NONE,
                        MS_NONE,
                        VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_CONN },

/* LiGen grid     */  { FORM_LIGEN_GRID_SRF , "LIGENGRID" , "txt"  ,
                        FORM_FLAG_NONE,
                        MS_NONE,
                        VG_MERGE_NONE },

/* LiGen grid bin */  { FORM_LIGEN_GRIDBIN_SRF, "LIGENGRIDBIN", "bin" ,
                        FORM_FLAG_NONE,
                        MS_NONE,
                        VG_MERGE_NONE },

/* LiGen pharm.   */  { FORM_LIGEN_PHARM_SRF, "LIGENPHARM", "txt" ,
                        FORM_FLAG_NONE,
                        MS_NONE,
                        VG_MERGE_NONE },

/* LiGen pharm. bin */{ FORM_LIGEN_PHARMBIN_SRF, "LIGENPHARMBIN", "bin" ,
                        FORM_FLAG_NONE,
                        MS_NONE,
                        VG_MERGE_NONE },

/* LiGen pocket   */  { FORM_LIGEN_POCKET   , "LIGENPOCKET", "txt" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ATMTYPE|VG_MERGE_COORD|VG_MERGE_ELEMENT|VG_MERGE_RESNAME },

/* LiGen pkt bin  */  { FORM_LIGEN_POCKET   , "LIGENPOCKETBIN", "bin" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN,
                        MS_NONE,
                        VG_MERGE_ATMNAME|VG_MERGE_ATMTYPE|VG_MERGE_COORD|VG_MERGE_ELEMENT|VG_MERGE_RESNAME },

/* ENPIRE arc     */  { FORM_EMPIRECAR      , "EMPIREARC", "arc" ,
                        FORM_FLAG_INONLY|FORM_FLAG_STDOUT|FORM_FLAG_CONN,
                        MS_NONE,
                        VG_MERGE_ELEMENT|VG_MERGE_COORD|VG_MERGE_ATMCHARGE },

/* PDB OpenMM     */  { FORM_PDB_OPENMM      , "PDBOMM"   , "pdb" ,
                        FORM_FLAG_STDOUT|FORM_FLAG_CONN,
                        MS_NONE,
                        VG_MERGE_PDB },

/**** Trajectories ****/

/* Amber          */  { FORM_TRAJ_AMBER     , "TRJAMBE"  , "mdcrd" ,
                        FORM_FLAG_NONE,
                        MS_NONE,
                        VG_MERGE_NONE },

/* Amber NC      */  { FORM_TRAJ_AMBERNC   , "TRJAMBERNC", "nc" ,
                        FORM_FLAG_NONE,
                        MS_NONE,
                        VG_MERGE_NONE },

/* Charmm DCD     */  { FORM_TRAJ_DCD       , "TRJDCD"    , "dcd" ,
                        FORM_FLAG_NONE,
                        MS_NONE,
                        VG_MERGE_NONE },

/* IFF            */  { FORM_TRAJ_IFF       , "TRJIFF"    , "iff" ,
                        FORM_FLAG_NONE,
                        MS_NONE,
                        VG_MERGE_NONE },

/* Mol2           */  { FORM_TRAJ_MOL2      , "TRJMOL2"   , "mol2" ,
                        FORM_FLAG_STDOUT,
                        MS_NONE,
                        VG_MERGE_NONE },

/* PDB            */  { FORM_TRAJ_PDB       , "TRJPDB"    , "pdb" ,
                        FORM_FLAG_STDOUT,
                        MS_NONE,
                        VG_MERGE_NONE },

/* Gromacs Trr    */  { FORM_TRAJ_TRR       , "TRJTRR"    , "trr" ,
                        FORM_FLAG_NONE,
                        MS_NONE,
                        VG_MERGE_NONE },

/* Gromacs Xtc    */  { FORM_TRAJ_XTC       , "TRJXTC"    , "xtc" ,
                        FORM_FLAG_NONE,
                        MS_NONE,
                        VG_MERGE_NONE },

/* End */             { 0                    , NULL        , NULL  ,
                        FORM_FLAG_NONE,
                        MS_NONE,
                        VG_MERGE_NONE}
};
#  else
VEGA_EXTERNVAR VG_FILEFORMAT  VegaFileInfo[];
#  endif

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_GetFileFormatByID               _VG_GetFileFormatByID
#    define  VG_GetFileFormatByName             _VG_GetFileFormatByName
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN VG_FILEFORMAT *   VEGA_EXPORT VG_GetFileFormatByID(HD_LONG FormatID);
VEGA_EXTERN VG_FILEFORMAT *   VEGA_EXPORT VG_GetFileFormatByName(const HD_CHAR *FormatName);

#  ifdef __cplusplus
}
#  endif
#endif


