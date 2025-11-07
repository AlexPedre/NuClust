
/*************************************************
****          VEGA - Info XML saver           ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_INFOXML_H
#  define  __VG_INFOXML_H

#  define  VG_INFOXML_VERSION           "1.0"

/**** Value types ****/

#  define VG_XMLIVT_DOUBLE              0  /* Don't change the order */
#  define VG_XMLIVT_FLOAT               1
#  define VG_XMLIVT_FLOAT3              2
#  define VG_XMLIVT_FREEFORMAT          3
#  define VG_XMLIVT_INT                 4
#  define VG_XMLIVT_STRING              5

/**** Measure units ****/

#  define VG_XMLIMEAS_NONE              0
#  define VG_XMLIMEAS_ANGSTROM          1
#  define VG_XMLIMEAS_ANGSTROM2         2
#  define VG_XMLIMEAS_ANGSTROM3         3
#  define VG_XMLIMEAS_DALTONS           4
#  define VG_XMLIMEAS_DEBYE             5

/**** Calculation properties 1 ****/

#  define  VG_XMLIP1_NONE                   0 /* None to calculate                */

#  define  VG_XMLIP1_AACOMP                 1 /* Aminoacid composition            */
#  define  VG_XMLIP1_AREA                   2 /* VG_Surface area                  */
#  define  VG_XMLIP1_AREAPRORAD             4 /* VG_Surface area probe radius     */
#  define  VG_XMLIP1_ATOMS                  8 /* Number of atoms                  */
#  define  VG_XMLIP1_CENTGEO               16 /* Geometry center                  */
#  define  VG_XMLIP1_CENTMASS              32 /* Center of mass                   */
#  define  VG_XMLIP1_CENTROIDS             64 /* Number of centroids              */
#  define  VG_XMLIP1_CHAINS               128 /* Number of chains                 */
#  define  VG_XMLIP1_CHARGE               256 /* Charge                           */
#  define  VG_XMLIP1_DIMENSIONS           512 /* Number of chains                 */
#  define  VG_XMLIP1_DIPOLE              1024 /* Dipole                           */
#  define  VG_XMLIP1_FORMULA             2048 /* Formula                          */
#  define  VG_XMLIP1_GYRRAD              4096 /* Radius of gyration               */
#  define  VG_XMLIP1_HEAVYATOMS          8192 /* Number of heavy atoms            */
#  define  VG_XMLIP1_HYDROGENS          16384 /* Number of hydrogens              */
#  define  VG_XMLIP1_LOGPCRIPPEN        32768 /* Ghoose & Crippen logP            */
#  define  VG_XMLIP1_LOGPBROTO          65536 /* Broto & Moreau logP              */
#  define  VG_XMLIP1_LOGPVIRTUAL       131072 /* Virtual logP                     */
#  define  VG_XMLIP1_MOLECULES         262144 /* Number of molecules              */
#  define  VG_XMLIP1_PSA               524288 /* Polar surface area               */
#  define  VG_XMLIP1_RESIDUES         1048576 /* Number of residues               */
#  define  VG_XMLIP1_SEGMENTS         2097152 /* Number of segments               */
#  define  VG_XMLIP1_VOLUME           4194304 /* Volume                           */
#  define  VG_XMLIP1_WATERS           8388608 /* Number of waters                 */
#  define  VG_XMLIP1_WEIGHT          16777216 /* Molecular weight                 */
#  define  VG_XMLIP1_CHIRAL          33554432 /* List of chiral centers           */
#  define  VG_XMLIP1_CHIRALNUM       67108864 /* Number of chiral centers         */
#  define  VG_XMLIP1_EZBOND        0x08000000 /* List of E/Z bonds                */
#  define  VG_XMLIP1_EZBONDNUM     0x10000000 /* Number of E/Z bonds              */
#  define  VG_XMLIP1_ATT           0x20000000 /* Used atom types                  */
#  define  VG_XMLIP1_TORNUM        0x40000000 /* Number of torsions               */
#  define  VG_XMLIP1_TORFLEXNUM    0x80000000 /* Number of flexible torsions      */
#  define  VG_XMLIP1_ALL           0xffffffff /* Calculate all                    */

#  define  VG_XMLIP2_NONE                   0 /* None to calculate                */
#  define  VG_XMLIP2_MOLNAME       0x00000001 /* Molecule name                    */
#  define  VG_XMLIP2_HBONDACC      0x00000002 /* Number of H-bond acceptors       */
#  define  VG_XMLIP2_HBONDDON      0x00000004 /* Number of H-bond donor           */
#  define  VG_XMLIP2_GCMR          0x00000008 /* Molar refractivity (Ghose)       */
#  define  VG_XMLIP2_REALMOLS      0x00000010 /* Real number of molecules         */
#  define  VG_XMLIP2_RINGS         0x00000020 /* Number of rings                  */
#  define  VG_XMLIP2_ISOTOPIC      0x00000040 /* Isotopic distribution            */
#  define  VG_XMLIP2_TORADOCKNUM   0x00000080 /* Number of AutoDock torsions      */
#  define  VG_XMLIP2_MONOISOTOPIC  0x00000100 /* Monoisotopic mass                */
#  define  VG_XMLIP2_SMILES        0x00000200 /* Smiles                           */
#  define  VG_XMLIP2_INCHI         0x00000400 /* InChI                            */
#  define  VG_XMLIP2_INCHIKEY      0x00000800 /* InChIKey                         */
#  define  VG_XMLIP2_HLB           0x00001000 /* HLB                              */
#  define  VG_XMLIP2_ANGLES        0x00002000 /* Number of bond angles            */
#  define  VG_XMLIP2_BONDS         0x00004000 /* Number of bonds                  */
#  define  VG_XMLIP2_COORDTYP      0x00008000 /* Coordinate type (0D, 1D, 2D, 3D) */
#  define  VG_XMLIP2_ALL           0xffffffff /* Calculate all                    */

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_InfoXmlSave                     _VG_InfoXmlSave
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_BOOL VEGA_EXPORT VG_InfoXmlSave(VG_CTX *Ctx, FILE *FH, HD_STRING FileName, HD_ULONG SasPoints, float SasProbeRad, HD_LONG Prop1, HD_LONG Prop2);

#  ifdef __cplusplus
}
#  endif
#endif
