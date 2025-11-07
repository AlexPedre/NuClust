
/*************************************************
****           VEGA - Add hydrogens           ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_ADDHYD_H
#  define  __VG_ADDHYD_H

#  include <hyperdrive.h>

/**** Constants ****/

#  define  VG_ADDH_HVDWRAD                1.20f

/**** Flags for AddHyd() ****/

#  define  VG_ADDH_FLG_NONE               0       /* No special flags                */
#  define  VG_ADDH_FLG_ACTONLY            1       /* Add H to active atoms anly      */
#  define  VG_ADDH_FLG_BONDORD            2       /* Use the bond order for atom typ */
#  define  VG_ADDH_FLG_HPOSENDRES         4       /* Place the H at the residue end  */
#  define  VG_ADDH_FLG_IUPACNAMES         8       /* Use Ipuac atom names            */
#  define  VG_ADDH_FLG_NA                16       /* The molecule is a nucleic ac.   */
#  define  VG_ADDH_FLG_PROT              32       /* The molecule is a protein       */
#  define  VG_ADDH_FLG_PROT_COO          64       /* Protonate carboxylates          */
#  define  VG_ADDH_FLG_PROT_N1          128       /* Protonate primary amines        */
#  define  VG_ADDH_FLG_PROT_N2          256       /* Protonate secondary amines      */
#  define  VG_ADDH_FLG_PROT_N3          512       /* Protonate tertiary amines       */
#  define  VG_ADDH_FLG_NO_RM_HYDROG    1024       /* Don't remove the hydrogens      */
#  define  VG_ADDH_FLG_QUIET           2048       /* Don't show the messages         */

#  define  VG_ADDH_FLG_PROT_N           (VG_ADDH_FLG_PROT_N1|VG_ADDH_FLG_PROT_N2|VG_ADDH_FLG_PROT_N3)

/**** Atom types ****/

/*
 * D    Deuterium
 * DC   Deuterium bonded to carbon
 * H    Hydrogen
 * HC   Hydrogen bonded to carbon
 * C    Generic carbon
 * C+   Sp2 charged carbon in guanidine
 * C1   Sp carbon
 * C2   Sp2 carbon
 * C3   Sp3 carbon
 * Cac  Sp2 acylic carbon
 * Car  Sp2 carbon in carboxylate group
 * N    Generic nitrogen
 * N1   Sp nitrogen
 * N2   Sp2 nitrogen
 * N3   Sp3 nitrogen
 * N3+  Sp3 charged nitrogen
 * Nam  Sp3 nitrogen in amidic group
 * Ng+  Sp3 nitrogen in charged guanidine
 * Nim  Sp2 nitrogen in imidazole ring
 * NimH protonated Sp2 nitrogen in imidazole ring
 * Nox  Sp3 nitrogen in nitrate
 * Npl  Generic planar nitrogen
 * Npy  Sp2 nitrogen in pyridine ring
 * Ntr  Sp3 nitrogen in nitro group
 * O    Generic oxygen
 * O2   Sp2 oxygen
 * O3   Sp3 oxygen
 * O-   Sp2 oxygen in charged carboxylate group
 * S    Generic sulphur
 * S2   Sp2 sulphur
 * S3   Sp3 sulphur
 * S3+  Sp3 positive charged sulphur
 * Sac  Acylic sulphur
 * Sox  Sulphur in sulfoxide group
 * So2  (not used)
 * P    Generic phosphorus
 * P3+  Sp3 charged phosphorus
 * Pac  Acylic phosphorus
 * Pox  Phosphorus in phosphate
 * B    Generic boron
 * Bac  Acylic boron
 * Box  Boron in boronic acid
 * As   Arsenic
 */

#  ifdef LITTLE_ENDIAN
#    define  VG_ADDH_FF_D                 MakeInt64(0x0000000000000044)
#    define  VG_ADDH_FF_DC                MakeInt64(0x0000000000004344)
#    define  VG_ADDH_FF_H                 MakeInt64(0x0000000000000048)
#    define  VG_ADDH_FF_HC                MakeInt64(0x0000000000004348)
#    define  VG_ADDH_FF_C                 MakeInt64(0x0000000000000043)
#    define  VG_ADDH_FF_Cp                MakeInt64(0x0000000000002b43)
#    define  VG_ADDH_FF_C1                MakeInt64(0x0000000000003143)
#    define  VG_ADDH_FF_C2                MakeInt64(0x0000000000003243)
#    define  VG_ADDH_FF_C3                MakeInt64(0x0000000000003343)
#    define  VG_ADDH_FF_Cac               MakeInt64(0x0000000000636143)
#    define  VG_ADDH_FF_Car               MakeInt64(0x0000000000726143)
#    define  VG_ADDH_FF_N                 MakeInt64(0x000000000000004e)
#    define  VG_ADDH_FF_N1                MakeInt64(0x000000000000314e)
#    define  VG_ADDH_FF_N2                MakeInt64(0x000000000000324e)
#    define  VG_ADDH_FF_N3                MakeInt64(0x000000000000334e)
#    define  VG_ADDH_FF_N3p               MakeInt64(0x00000000002b334e)
#    define  VG_ADDH_FF_Nam               MakeInt64(0x00000000006d614e)
#    define  VG_ADDH_FF_Ngp               MakeInt64(0x00000000002b674e)
#    define  VG_ADDH_FF_Nim               MakeInt64(0x00000000006d694e)
#    define  VG_ADDH_FF_NimH              MakeInt64(0x00000000486d694e)
#    define  VG_ADDH_FF_Nox               MakeInt64(0x0000000000786f4e)
#    define  VG_ADDH_FF_Npl               MakeInt64(0x00000000006c704e)
#    define  VG_ADDH_FF_Npy               MakeInt64(0x000000000079704e)
#    define  VG_ADDH_FF_Ntr               MakeInt64(0x000000000072744e)
#    define  VG_ADDH_FF_O                 MakeInt64(0x000000000000004f)
#    define  VG_ADDH_FF_O2                MakeInt64(0x000000000000324f)
#    define  VG_ADDH_FF_O3                MakeInt64(0x000000000000334f)
#    define  VG_ADDH_FF_Om                MakeInt64(0x0000000000002d4f)
#    define  VG_ADDH_FF_S                 MakeInt64(0x0000000000000053)
#    define  VG_ADDH_FF_S2                MakeInt64(0x0000000000003253)
#    define  VG_ADDH_FF_S3                MakeInt64(0x0000000000003353)
#    define  VG_ADDH_FF_S3p               MakeInt64(0x00000000002b3353)
#    define  VG_ADDH_FF_Sac               MakeInt64(0x0000000000636153)
#    define  VG_ADDH_FF_Sox               MakeInt64(0x0000000000786f53)
#    define  VG_ADDH_FF_So2               MakeInt64(0x0000000000326f53)
#    define  VG_ADDH_FF_P                 MakeInt64(0x0000000000000050)
#    define  VG_ADDH_FF_P3p               MakeInt64(0x00000000002b3350)
#    define  VG_ADDH_FF_Pac               MakeInt64(0x0000000000636150)
#    define  VG_ADDH_FF_Pox               MakeInt64(0x0000000000786f50)
#    define  VG_ADDH_FF_B                 MakeInt64(0x0000000000000042)
#    define  VG_ADDH_FF_Bac               MakeInt64(0x0000000000636142)
#    define  VG_ADDH_FF_Box               MakeInt64(0x0000000000786f42)
#    define  VG_ADDH_FF_As                MakeInt64(0x0000000000007341)
#    define  VG_ADDH_FF_As3p              MakeInt64(0x000000002b337341)
#    define  VG_ADDH_FF_Asac              MakeInt64(0x0000000063617341)
#    define  VG_ADDH_FF_Asox              MakeInt64(0x00000000786f7341)
#  else
#    define  VG_ADDH_FF_D                 MakeInt64(0x4400000000000000)
#    define  VG_ADDH_FF_DC                MakeInt64(0x4443000000000000)
#    define  VG_ADDH_FF_H                 MakeInt64(0x4800000000000000)
#    define  VG_ADDH_FF_HC                MakeInt64(0x4843000000000000)
#    define  VG_ADDH_FF_C                 MakeInt64(0x4300000000000000)
#    define  VG_ADDH_FF_Cp                MakeInt64(0x432b000000000000)
#    define  VG_ADDH_FF_C1                MakeInt64(0x4331000000000000)
#    define  VG_ADDH_FF_C2                MakeInt64(0x4332000000000000)
#    define  VG_ADDH_FF_C3                MakeInt64(0x4333000000000000)
#    define  VG_ADDH_FF_Cac               MakeInt64(0x4361630000000000)
#    define  VG_ADDH_FF_Car               MakeInt64(0x4361720000000000)
#    define  VG_ADDH_FF_N                 MakeInt64(0x4e00000000000000)
#    define  VG_ADDH_FF_N1                MakeInt64(0x4e31000000000000)
#    define  VG_ADDH_FF_N2                MakeInt64(0x4e32000000000000)
#    define  VG_ADDH_FF_N3                MakeInt64(0x4e33000000000000)
#    define  VG_ADDH_FF_N3p               MakeInt64(0x4e332b0000000000)
#    define  VG_ADDH_FF_Nam               MakeInt64(0x4e616d0000000000)
#    define  VG_ADDH_FF_Ngp               MakeInt64(0x4e672b0000000000)
#    define  VG_ADDH_FF_Nim               MakeInt64(0x4e696d0000000000)
#    define  VG_ADDH_FF_NimH              MakeInt64(0x4e696d4800000000)
#    define  VG_ADDH_FF_Nox               MakeInt64(0x4e6f780000000000)
#    define  VG_ADDH_FF_Npl               MakeInt64(0x4e706c0000000000)
#    define  VG_ADDH_FF_Npy               MakeInt64(0x4e70790000000000)
#    define  VG_ADDH_FF_Ntr               MakeInt64(0x4e74720000000000)
#    define  VG_ADDH_FF_O                 MakeInt64(0x4f00000000000000)
#    define  VG_ADDH_FF_O2                MakeInt64(0x4f32000000000000)
#    define  VG_ADDH_FF_O3                MakeInt64(0x4f33000000000000)
#    define  VG_ADDH_FF_Om                MakeInt64(0x4f2d000000000000)
#    define  VG_ADDH_FF_S                 MakeInt64(0x5300000000000000)
#    define  VG_ADDH_FF_S2                MakeInt64(0x5332000000000000)
#    define  VG_ADDH_FF_S3                MakeInt64(0x5333000000000000)
#    define  VG_ADDH_FF_S3p               MakeInt64(0x53332b0000000000)
#    define  VG_ADDH_FF_Sac               MakeInt64(0x5361630000000000)
#    define  VG_ADDH_FF_Sox               MakeInt64(0x536f780000000000)
#    define  VG_ADDH_FF_So2               MakeInt64(0x536f320000000000)
#    define  VG_ADDH_FF_P                 MakeInt64(0x5000000000000000)
#    define  VG_ADDH_FF_P3p               MakeInt64(0x50332b0000000000)
#    define  VG_ADDH_FF_Pac               MakeInt64(0x5061630000000000)
#    define  VG_ADDH_FF_Pox               MakeInt64(0x506f780000000000)
#    define  VG_ADDH_FF_B                 MakeInt64(0x4200000000000000)
#    define  VG_ADDH_FF_Bac               MakeInt64(0x4261630000000000)
#    define  VG_ADDH_FF_Box               MakeInt64(0x426f780000000000)
#    define  VG_ADDH_FF_As                MakeInt64(0x4173000000000000)
#    define  VG_ADDH_FF_As3p              MakeInt64(0x4173332b00000000)
#    define  VG_ADDH_FF_Asac              MakeInt64(0x4173616300000000)
#    define  VG_ADDH_FF_Asox              MakeInt64(0x41736f7800000000)
#  endif

/**** Bond angles ****/

#  define  VG_ADDH_ANG_SP3_MAX            116.0f /* 114.0f original Babel value */
#  define  VG_ADDH_ANG_SP3_MAX_N          116.0f
#  define  VG_ADDH_ANG_SP2_MAX            122.0f
#  define  VG_ADDH_ANG_SP_MIN             160.0f

/**** Planarity ****/

#  define  VG_ADDH_PLAN                   0.20f

/**** Distances ****/

#  define  V1_C1_C1_CUTOFF                1.22f
#  define  V1_C2_C_CUTOFF                 1.41f
#  define  V1_C2_N_CUTOFF                 1.37f

#  define  V1_N1_C1_CUTOFF                1.20f
#  define  V1_N3_C_CUTOFF                 1.38f
#  define  V1_N3_N3_CUTOFF                1.43f
#  define  V1_N3_N2_CUTOFF                1.41f

#  define  V1_O2_C2_CUTOFF                1.30f
#  define  V1_O2_AS_CUTOFF                1.685f

#  define  V1_S2_C2_CUTOFF                1.76f
#  define  V1_S2_AS_CUTOFF                2.11f

#  define  V2_C3_C_CUTOFF                 1.53f
#  define  V2_C3_N_CUTOFF                 1.46f
#  define  V2_C3_O_CUTOFF                 1.44f

#  define  V2_N2_C_CUTOFF                 1.38f
#  define  V2_N2_N_CUTOFF                 1.40f  /* 1.32f original Babel value */

#  define  V2_C2_C_CUTOFF                 1.42f
#  define  V2_C2_N_CUTOFF                 1.38f  /* 1.41f original Babel value */
#  define  GEN_C3_C_CUTOFF                1.45f

/**** Geometries for AddH() ****/

#  define  VG_ADDH_GEO_SP                  0
#  define  VG_ADDH_GEO_SP2                 1
#  define  VG_ADDH_GEO_SP3                 2

/**** Bond lengths for AddH() ****/

#  define  VG_ADDH_DIST_C_SP               1.090f
#  define  VG_ADDH_DIST_C_SP2              1.103f
#  define  VG_ADDH_DIST_C_SP3              1.115f
#  define  VG_ADDH_DIST_N_SP2              1.020f
#  define  VG_ADDH_DIST_N_SP3              1.020f
#  define  VG_ADDH_DIST_O_SP3              0.950f
#  define  VG_ADDH_DIST_S_SP3              1.390f

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_AddhSetAtmNameProt              _VG_AddhSetAtmNameProt
#    define  VG_AddHyd                          _VG_AddHyd
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_AddhSetAtmNameProt(VG_CTX *Ctx, HD_ATOM *Atm, HD_ATOM *Conn);
VEGA_EXTERN HD_ULONG        VEGA_EXPORT VG_AddHyd(VG_CTX *Ctx, HD_ATOM **InizAtm, HD_ULONG *TotAtm, HD_ATOM **LastAtom, HD_LONG Flags);

#  ifdef __cplusplus
}
#  endif
#endif
