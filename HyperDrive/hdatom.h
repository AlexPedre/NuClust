
/*********************************************
****       HyperDrive - Atom header       ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifndef __HD_ATOM_H
#  define  __HD_ATOM_H

#  ifndef __HDRIVE_H
#    include "hyperdrive.h"
#  endif

#  define  HD_ELEM_NUM            118     /* Number of elements in periodic table  */

/********************************
****       Bond orders       ****
****  See HD_ATOM structure  ****
********************************/

#  define  VG_BOND_NONE           0       /* Atom not bonded or unknown bond order */
#  define  VG_BOND_SINGLE         1       /* Single bond                           */
#  define  VG_BOND_DOUBLE         2       /* Double bond                           */
#  define  VG_BOND_TRIPLE         3       /* Triple bond                           */
#  define  VG_BOND_PARDOUBLE      4       /* Partial double                        */


/********************************
****        Label types      ****
****  See HD_ATOM structure  ****
********************************/

#  define  VG_ATMLBL_NONE         0       /* Don't change the order */
#  define  VG_ATMLBL_NAME         1
#  define  VG_ATMLBL_ELEMENT      2
#  define  VG_ATMLBL_NUMBER       3
#  define  VG_ATMLBL_TYPE         4
#  define  VG_ATMLBL_CHARGE       5
#  define  VG_ATMLBL_CHIRAL       6
#  define  VG_ATMLBL_FIX          7

/**** Residue labels ****/

#  define  VG_ATMLBL_RESNAMESEQ   8       /* Don't change the order */
#  define  VG_ATMLBL_RESNAME      9
#  define  VG_ATMLBL_RESSEQ      10
#  define  VG_ATMLBL_NUM         11


/********************************
****    Color definitions    ****
****  See HD_ATOM structure  ****
********************************/

#  define  VGCOL_NONE             0
#  define  VGCOL_BLACK            1
#  define  VGCOL_WHITE            2
#  define  VGCOL_RED              3
#  define  VGCOL_GREEN            4
#  define  VGCOL_CYAN             5
#  define  VGCOL_YELLOW           6
#  define  VGCOL_FIREBIRCK        7
#  define  VGCOL_MAGENTA          8
#  define  VGCOL_PINK             9
#  define  VGCOL_VIOLET          10
#  define  VGCOL_GRAY            11
#  define  VGCOL_ORANGE          12
#  define  VGCOL_DARKGREEN       13
#  define  VGCOL_BLUE            14
#  define  VGCOL_DARKYELLOW      15
#  define  VGCOL_BROWN           16
#  define  VGCOL_SKYBLUE         17
#  define  VGCOL_DARKGRAY        18
#  define  VGCOL_GHOSTPINK       19
#  define  VGCOL_GHOSTGREEN      20
#  define  VGCOL_GHOSTBLUE       21
#  define  VGCOL_GHOSTYELLOW     22
#  define  VGCOL_GHOSTGRAY       23
#  define  VGCOL_SAND            24

#  define  VGCOL_NUM             24


/********************************
****  Bit values for Flags   ****
****  See HD_ATOM structure  ****
********************************/

#  define  VG_ATMF_NONE          0
#  define  VG_ATMF_ACTIVE        1
#  define  VG_ATMF_AROMATIC      2
#  define  VG_ATMF_CENTROID      4
#  define  VG_ATMF_CENTROIDFIX   8
#  define  VG_ATMF_CHIRAL       16
#  define  VG_ATMF_EXCLUDE      32
#  define  VG_ATMF_HETATM       64
#  define  VG_ATMF_MOLEND      128
#  define  VG_ATMF_ORGANIC     256
#  define  VG_ATMF_SEGEND      512
#  define  VG_ATMF_PRIVATE    1024


/********************************
****       Draw modes        ****
****  See HD_ATOM structure  ****
********************************/

#  define  VG_ATMD_WIREFRAME     0    /* Vectors only                */
#  define  VG_ATMD_CPK_DOTTED    1    /* CPK/Van der Waals dotted    */
#  define  VG_ATMD_CPK_WIRE      2    /* CPK/Van der Waals wireframe */
#  define  VG_ATMD_CPK_SOLID     3    /* CPK/Van der Waals solid     */
#  define  VG_ATMD_BALL_WIRE     4    /* Ball & stick wireframe      */
#  define  VG_ATMD_BALL_SOLID    5    /* Ball & stick solid          */
#  define  VG_ATMD_STICK_WIRE    6    /* Stick wireframe             */
#  define  VG_ATMD_STICK_SOLID   7    /* Stick solid                 */
#  define  VG_ATMD_TUBE_SOLID    8    /* Tube solid                  */
#  define  VG_ATMD_TRACE_SOLID   9    /* Trace solid                 */


/********************************
****        Chirality        ****
****  See HD_ATOM structure  ****
********************************/

#  define  VG_ATMC_NONE           0    /* Not chiral                            */
#  define  VG_ATMC_R            'R'    /* R                                     */
#  define  VG_ATMC_S            'S'    /* S                                     */
#  define  VG_ATMC_UNDEF        '*'    /* Undefined chirality                   */
#  define  VG_ATMC_E            'E'    /* E if involved in a double bond        */
#  define  VG_ATMC_Z            'Z'    /* Z if involved in a double bond        */


/********************************
**** Bit values of the Flags ****
****   HD_SRFINFO structure  ****
********************************/

#  define  VG_SRFF_NONE           0   /* None                                   */
#  define  VG_SRFF_ACTIVE         1   /* The surface is visible                 */
#  define  VG_SRFF_ALPHA          2   /* Enable the alpha blending              */
#  define  VG_SRFF_LOCK           4   /* Locked surface                         */
#  define  VG_SRFF_GLLIST         8   /* Use the OpenGL list                    */
#  define  VG_SRFF_GLLISTUPD     16   /* Force the list update                  */
#  define  VG_SRFF_GLVBO         32   /* Use the OpenGL vertex buffer objects   */
#  define  VG_SRFF_GLCOLBUILD    64   /* Rebuild the OpenGL color array         */


/*********************************
****       Surface types      ****
**** See HD_SRFINFO structure ****
*********************************/

#  define  VG_SRFT_DOTTED         0   /* The first 4 bytes are for              */
#  define  VG_SRFT_MESH           1   /* the surface type                       */
#  define  VG_SRFT_SOLID          2

/*************************
****      Macros      ****
*************************/

#  define  VG_AtmEqRing(Atm, Num)       (((Atm) -> Ring.C[0] == Num) || ((Atm) -> Ring.C[1] == Num) ||\
                                         ((Atm) -> Ring.C[2] == Num) || ((Atm) -> Ring.C[3] == Num))

#  define  VG_AtmIsActive(Atm)          ((Atm) -> Flags & VG_ATMF_ACTIVE)
#  define  VG_AtmIsArom(Atm)            ((Atm) -> Flags & VG_ATMF_AROMATIC)
#  define  VG_AtmIsCentroid(Atm)        ((Atm) -> Flags & VG_ATMF_CENTROID)
#  define  VG_AtmIsCentroidFix(Atm)     ((Atm) -> Flags & VG_ATMF_CENTROIDFIX)
#  define  VG_AtmIsChiral(Atm)          ((Atm) -> Flags & VG_ATMF_CHIRAL)
#  define  VG_AtmIsExclude(Atm)         ((Atm) -> Flags & VG_ATMF_EXCLUDE)
#  define  VG_AtmIsHetAtm(Atm)          ((Atm) -> Flags & VG_ATMF_HETATM)
#  define  VG_AtmIsMolEnd(Atm)          ((Atm) -> Flags & VG_ATMF_MOLEND)
#  define  VG_AtmIsNotRing(Atm)         ((Atm) -> Ring.L == 0)
#  define  VG_AtmIsOrganic(Atm)         ((Atm) -> Flags & VG_ATMF_ORGANIC)
#  define  VG_AtmIsRing(Atm)            ((Atm) -> Ring.L != 0)
#  define  VG_AtmIsSegEnd(Atm)          ((Atm) -> Flags & VG_ATMF_SEGEND)

#  define  VG_AtmRings(Atm)             (((Atm) -> Ring.C[0] != 0) + ((Atm) -> Ring.C[1] != 0) + \
                                         ((Atm) -> Ring.C[2] != 0) + ((Atm) -> Ring.C[3] != 0))
#  define  VG_AtmRingClr(Atm)           (Atm) -> Ring.L = 0

#  define  VG_AtmSetActive(Atm)         (Atm) -> Flags |= VG_ATMF_ACTIVE
#  define  VG_AtmSetArom(Atm)           (Atm) -> Flags |= VG_ATMF_AROMATIC
#  define  VG_AtmSetCentroid(Atm)       (Atm) -> Flags |= VG_ATMF_CENTROID
#  define  VG_AtmSetCentroidFix(Atm)    (Atm) -> Flags |= VG_ATMF_CENTROIDFIX
#  define  VG_AtmSetChiral(Atm)         (Atm) -> Flags |= VG_ATMF_CHIRAL
#  define  VG_AtmSetExclude(Atm)        (Atm) -> Flags |= VG_ATMF_EXCLUDE
#  define  VG_AtmSetHetAtm(Atm)         (Atm) -> Flags |= VG_ATMF_HETATM
#  define  VG_AtmSetMolEnd(Atm)         (Atm) -> Flags |= VG_ATMF_MOLEND
#  define  VG_AtmSetMolSeg(Atm)         (Atm) -> Flags |= VG_ATMF_MOLEND|VG_ATMF_SEGEND
#  define  VG_AtmSetOrganic(Atm)        (Atm) -> Flags |= VG_ATMF_ORGANIC
#  define  VG_AtmSetRing(Atm, Num)      (Atm) -> Ring.C[0] = Num
#  define  VG_AtmSetSegEnd(Atm)         (Atm) -> Flags |= VG_ATMF_SEGEND

#  define  VG_AtmToggleActive(Atm)      (Atm) -> Flags ^= VG_ATMF_ACTIVE
#  define  VG_AtmToggleArom(Atm)        (Atm) -> Flags ^= VG_ATMF_AROMATIC

#  define  VG_AtmUnSetActive(Atm)       (Atm) -> Flags &= ~VG_ATMF_ACTIVE
#  define  VG_AtmUnSetArom(Atm)         (Atm) -> Flags &= ~VG_ATMF_AROMATIC
#  define  VG_AtmUnSetCentroid(Atm)     (Atm) -> Flags &= ~VG_ATMF_CENTROID
#  define  VG_AtmUnSetCentroidFix(Atm)  (Atm) -> Flags &= ~VG_ATMF_CENTROIDFIX
#  define  VG_AtmUnSetChiral(Atm)       (Atm) -> Flags &= ~VG_ATMF_CHIRAL
#  define  VG_AtmUnSetExclude(Atm)      (Atm) -> Flags &= ~VG_ATMF_EXCLUDE
#  define  VG_AtmUnSetHetAtm(Atm)       (Atm) -> Flags &= ~VG_ATMF_HETATM
#  define  VG_AtmUnSetMolEnd(Atm)       (Atm) -> Flags &= ~VG_ATMF_MOLEND
#  define  VG_AtmUnSetMolSeg(Atm)       (Atm) -> Flags &= ~(VG_ATMF_MOLEND|VG_ATMF_SEGEND)
#  define  VG_AtmUnSetOrganic(Atm)      (Atm) -> Flags &= ~VG_ATMF_ORGANIC
#  define  VG_AtmUnSetSegEnd(Atm)       (Atm) -> Flags &= ~VG_ATMF_SEGEND

#  ifdef HD_LITTLE_ENDIAN
#    define HD_ELEM_AG                  0x6741
#    define HD_ELEM_AU                  0x7541
#    define HD_ELEM_AL                  0x4c41
#    define HD_ELEM_AS                  0x7341
#    define HD_ELEM_B                   0x0042
#    define HD_ELEM_BA                  0x6142
#    define HD_ELEM_BE                  0x6542
#    define HD_ELEM_BI                  0x6942
#    define HD_ELEM_BR                  0x7242
#    define HD_ELEM_C                   0x0043
#    define HD_ELEM_CA                  0x6143
#    define HD_ELEM_CD                  0x6443
#    define HD_ELEM_CL                  0x6c43
#    define HD_ELEM_CO                  0x6f43
#    define HD_ELEM_CR                  0x7243
#    define HD_ELEM_CS                  0x7343
#    define HD_ELEM_CU                  0x7543
#    define HD_ELEM_D                   0x0044
#    define HD_ELEM_F                   0x0046
#    define HD_ELEM_FE                  0x8546
#    define HD_ELEM_FR                  0x7246
#    define HD_ELEM_GA                  0x6147
#    define HD_ELEM_H                   0x0048
#    define HD_ELEM_HG                  0x6748
#    define HD_ELEM_I                   0x0049
#    define HD_ELEM_K                   0x004b
#    define HD_ELEM_LA                  0x614c
#    define HD_ELEM_LI                  0x694c
#    define HD_ELEM_MG                  0x674d
#    define HD_ELEM_MN                  0x6e4d
#    define HD_ELEM_N                   0x004e
#    define HD_ELEM_NA                  0x614e
#    define HD_ELEM_NI                  0x694e
#    define HD_ELEM_O                   0x004f
#    define HD_ELEM_P                   0x0050
#    define HD_ELEM_PO                  0x6f50
#    define HD_ELEM_PB                  0x6250
#    define HD_ELEM_PT                  0x7450
#    define HD_ELEM_RA                  0x6152
#    define HD_ELEM_RB                  0x6252
#    define HD_ELEM_S                   0x0053
#    define HD_ELEM_SB                  0x6253
#    define HD_ELEM_SC                  0x6353
#    define HD_ELEM_SE                  0x6553
#    define HD_ELEM_SI                  0x6953
#    define HD_ELEM_SN                  0x6e53
#    define HD_ELEM_SR                  0x7253
#    define HD_ELEM_T                   0x0054
#    define HD_ELEM_TE                  0x6554
#    define HD_ELEM_TI                  0x6954
#    define HD_ELEM_Y                   0x0059
#    define HD_ELEM_YB                  0x6259
#    define HD_ELEM_ZN                  0x6e5a
#    define HD_ELEM_ZR                  0x725a

#    define HD_ELEM_LP                  0x504c

/**** Atom names ****/

#    define HD_ATMNAME_C                0x00000043
#    define HD_ATMNAME_CA               0x00004143
#    define HD_ATMNAME_N                0x0000004e


#else
#    define HD_ELEM_AG                  0x4167
#    define HD_ELEM_AU                  0x4175
#    define HD_ELEM_AL                  0x414c
#    define HD_ELEM_AS                  0x4173
#    define HD_ELEM_B                   0x4200
#    define HD_ELEM_BA                  0x4261
#    define HD_ELEM_BE                  0x4265
#    define HD_ELEM_BI                  0x4269
#    define HD_ELEM_BR                  0x4272
#    define HD_ELEM_C                   0x4300
#    define HD_ELEM_CA                  0x4361
#    define HD_ELEM_CD                  0x4364
#    define HD_ELEM_CL                  0x436c
#    define HD_ELEM_CO                  0x436f
#    define HD_ELEM_CR                  0x4372
#    define HD_ELEM_CS                  0x4373
#    define HD_ELEM_CU                  0x4375
#    define HD_ELEM_D                   0x4400
#    define HD_ELEM_F                   0x4600
#    define HD_ELEM_FE                  0x4665
#    define HD_ELEM_FR                  0x4672
#    define HD_ELEM_GA                  0x4761
#    define HD_ELEM_H                   0x4800
#    define HD_ELEM_HG                  0x4867
#    define HD_ELEM_I                   0x4900
#    define HD_ELEM_K                   0x4b00
#    define HD_ELEM_LA                  0x4c61
#    define HD_ELEM_LI                  0x4c69
#    define HD_ELEM_MG                  0x4d67
#    define HD_ELEM_MN                  0x4d6e
#    define HD_ELEM_N                   0x4e00
#    define HD_ELEM_NA                  0x4e61
#    define HD_ELEM_NI                  0x4e69
#    define HD_ELEM_O                   0x4f00
#    define HD_ELEM_P                   0x5000
#    define HD_ELEM_PB                  0x5062
#    define HD_ELEM_PO                  0x506f
#    define HD_ELEM_PT                  0x5074
#    define HD_ELEM_RA                  0x5261
#    define HD_ELEM_RB                  0x5262
#    define HD_ELEM_S                   0x5300
#    define HD_ELEM_SB                  0x5362
#    define HD_ELEM_SC                  0x5363
#    define HD_ELEM_SE                  0x5365
#    define HD_ELEM_SI                  0x5369
#    define HD_ELEM_SN                  0x536e
#    define HD_ELEM_SR                  0x5372
#    define HD_ELEM_T                   0x5400
#    define HD_ELEM_TE                  0x5465
#    define HD_ELEM_TI                  0x5469
#    define HD_ELEM_Y                   0x5900
#    define HD_ELEM_YB                  0x5962
#    define HD_ELEM_ZN                  0x5a6e
#    define HD_ELEM_ZR                  0x5a72

#    define HD_ELEM_LP                  0x4c50

/**** Atom names ****/

#    define HD_ATMNAME_C                0x43000000
#    define HD_ATMNAME_CA               0x43410000
#    define HD_ATMNAME_N                0x4e000000
#  endif
#endif
