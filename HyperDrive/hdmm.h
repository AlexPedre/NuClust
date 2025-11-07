
/*********************************************
****   HyperDrive - Molecular Mechanics   ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifndef __HDMM_H
#  define  __HDMM_H

#  ifndef __HDRIVE_H
#    include "hyperdrive.h"
#  endif

/**** Macros ****/

#  define  MAX_MULT              4

#  ifdef HD_LITTLE_ENDIAN
#    define  HD_PARAM_TYPE_X     MakeInt64(0x0000000000000058)
#  else
#    define  HD_PARAM_TYPE_X     MakeInt64(0x5800000000000000)
#  endif

/**** Energy calculation flags ****/

#define  HD_ENECALC_NONE              0
#define  HD_ENECALC_ANGLE             1
#define  HD_ENECALC_BOND              2
#define  HD_ENECALC_DIHEDRAL          4
#define  HD_ENECALC_ELECT             8
#define  HD_ENECALC_HBOND            16
#define  HD_ENECALC_IMPROPER         32
#define  HD_ENECALC_NBOND            64

#define  HD_ENECALC_STD               (HD_ENECALC_ANGLE|HD_ENECALC_BOND|HD_ENECALC_DIHEDRAL|\
                                       HD_ENECALC_ELECT|HD_ENECALC_IMPROPER|HD_ENECALC_NBOND)


/**** Force field prameters ****/

typedef struct {
  HD_LIST *     Angles;                 /* Angles                             */
  HD_LIST *     Bonds;                  /* Bonds                              */
  HD_LIST *     Dihedrals;              /* Dihedrals                          */
  HD_LIST *     HbondPairs;             /* H-bond pairs                       */
  HD_LIST *     Impropers;              /* Impropers                          */
  HD_LIST *     Nbond;                  /* Non bonds                          */
  HD_LIST *     NbondPairs;             /* Non bond pairs                     */
} HD_PAR;

/**** Four body parameter (double precision) ****/

typedef struct {
  HD_DOUBLE     k;      /* Force constant                                     */
  HD_DOUBLE     delta;  /* Phase shift                                        */
  HD_LONG       n;      /* Periodicity                                        */
} HD_PAR4BODY;

/**** Four body parameter (single precision) ****/

typedef struct {
  HD_FLOAT      k;      /* Force constant                                     */
  HD_FLOAT      delta;  /* Phase shift                                        */
  HD_LONG       n;      /* Periodicity                                        */
} HD_PAR4BODYF;

/**** Angle parameter (double precision) ****/

typedef struct __HdParAngle {
  struct __HdParAngle * Next;           /* Pointer to next list element       */
  struct __HdParAngle * Prev;           /* Pointer to previous list element   */
  HD_OCHAR              Type[3];        /* Atom types involved in the angle   */
  HD_DOUBLE             ForceConst;     /* Force constant (Ktheta)            */
  HD_DOUBLE             Angle;          /* Rest angle (Theta 0)               */
  HD_DOUBLE             Kub;            /* Urey-Bradley force constant        */
  HD_DOUBLE             Rub;            /* Urey-Bradley distance              */
} HD_PARANGLE;

/**** Angle parameter (single precision) ****/

typedef struct __HdParAnglef {
  struct __HdParAnglef * Next;          /* Pointer to next list element       */
  struct __HdParAnglef * Prev;          /* Pointer to previous list element   */
  HD_OCHAR              Type[3];        /* Atom types involved in the angle   */
  HD_FLOAT              ForceConst;     /* Force constant (Ktheta)            */
  HD_FLOAT              Angle;          /* Rest angle (Theta 0)               */
  HD_FLOAT              Kub;            /* Urey-Bradley force constant        */
  HD_FLOAT              Rub;            /* Urey-Bradley distance              */
} HD_PARANGLEF;

/**** Bond parameter (double precision) ****/

typedef struct __HdParBond {
  struct __HdParBond *  Next;           /* Pointer to next list element       */
  struct __HdParBond *  Prev;           /* Pointer to previous list element   */
  HD_OCHAR              Type[2];        /* Atom types involved in the bond    */
  HD_DOUBLE             ForceConst;     /* Force constant for the bond (Kb)   */
  HD_DOUBLE             Dist;           /* Rest distance for the bond  (b0)   */
} HD_PARBOND;

/**** Bond parameter (single precision) ****/

typedef struct __HdParBondf {
  struct __HdParBondf * Next;           /* Pointer to next list element       */
  struct __HdParBondf * Prev;           /* Pointer to previous list element   */
  HD_OCHAR              Type[2];        /* Atom types involved in the bond    */
  HD_FLOAT              ForceConst;     /* Force constant for the bond (Kb)   */
  HD_FLOAT              Dist;           /* Rest distance for the bond  (b0)   */
} HD_PARBONDF;

/**** Dihedral parameter (double precision) ****/

typedef struct __HdParDihed {
  struct __HdParDihed * Next;           /* Pointer to next list element       */
  struct __HdParDihed * Prev;           /* Pointer to previous list element   */
  HD_OCHAR              Type[4];        /* Atom types involved in dihedral    */
  HD_LONG               Mult;           /* Multiplicity                       */
  HD_PAR4BODY           Val[MAX_MULT];  /* Multiplicity values                */
} HD_PARDIHEDRAL;

/**** Dihedral parameter (single precision) ****/

typedef struct __HdParDihedf {
  struct __HdParDihedf *Next;           /* Pointer to next list element       */
  struct __HdParDihedf *Prev;           /* Pointer to previous list element   */
  HD_OCHAR              Type[4];        /* Atom types involved in dihedral    */
  HD_LONG               Mult;           /* Multiplicity                       */
  HD_PAR4BODYF          Val[MAX_MULT];  /* Multiplicity values                */
} HD_PARDIHEDRALF;

/**** Improper parameter (double precision) ****/

typedef struct __HdParImpro {
  struct __HdParImpro * Next;           /* Pointer to next list element       */
  struct __HdParImpro * Prev;           /* Pointer to previous list element   */
  HD_OCHAR              Type[4];        /* Atom types involved in improper    */
  HD_LONG               Mult;           /* Multiplicity                       */
  HD_PAR4BODY           Val[MAX_MULT];  /* Multiplicity values                */
} HD_PARIMPROPER;

/**** Improper parameter (single precision) ****/

typedef struct __HdParImprof {
  struct __HdParImprof *Next;           /* Pointer to next list element       */
  struct __HdParImprof *Prev;           /* Pointer to previous list element   */
  HD_OCHAR              Type[4];        /* Atom types involved in improper    */
  HD_LONG               Mult;           /* Multiplicity                       */
  HD_PAR4BODYF          Val[MAX_MULT];  /* Multiplicity values                */
} HD_PARIMPROPERF;

/**** Non-bond parameters (double precision) ****/

typedef struct __HdParNbond {
  struct __HdParNbond * Next;          /* Pointer to next list element       */
  struct __HdParNbond * Prev;          /* Pointer to previous list element   */
  HD_OCHAR              Type;           /* Atom type                          */
  HD_DOUBLE             Ignored;
  HD_DOUBLE             Sigma;
  HD_DOUBLE             Epsilon;
  HD_DOUBLE             Ignored14;
  HD_DOUBLE             Sigma14;
  HD_DOUBLE             Epsilon14;
  HD_DOUBLE             A, B;
  HD_DOUBLE             A14, B14;
} HD_PARNONBONDED;

/**** Non-bond parameters (single precision) ****/

typedef struct __HdParNbondf {
  struct __HdParNbondf *Next;           /* Pointer to next list element       */
  struct __HdParNbondf *Prev;           /* Pointer to previous list element   */
  HD_OCHAR              Type;           /* Atom type                          */
  HD_FLOAT              Ignored;
  HD_FLOAT              Sigma;
  HD_FLOAT              Epsilon;
  HD_FLOAT              Ignored14;
  HD_FLOAT              Sigma14;
  HD_FLOAT              Epsilon14;
  HD_FLOAT              A, B;
  HD_FLOAT              A14, B14;
} HD_PARNONBONDEDF;

/**** Non-bond parameter pairs (double precision) ****/

typedef struct __HdParNbondP {
  struct __HdParNbondP  *Next;          /* Pointer to next list element       */
  struct __HdParNbondP  *Prev;          /* Pointer to previous list element   */
  HD_OCHAR              Type[2];        /* Atom types                         */
  HD_DOUBLE             A, B;
  HD_DOUBLE             A14, B14;
} HD_PARNONBONDPAIR;

/**** Non-bond parameter pairs (single precision) ****/

typedef struct __HdParNbondPf {
  struct __HdParNbondPf *Next;          /* Pointer to next list element       */
  struct __HdParNbondPf *Prev;          /* Pointer to previous list element   */
  HD_OCHAR              Type[2];        /* Atom types                         */
  HD_FLOAT              A, B;
  HD_FLOAT              A14, B14;
} HD_PARNONBONDPAIRF;

/**** H-bond parameters pairs (double precision) ****/

typedef struct __HdParHbondP {
  struct __HdParHbondP  *Next;          /* Pointer to next list element       */
  struct __HdParHbondP  *Prev;          /* Pointer to previous list element   */
  HD_OCHAR              Type[2];        /* Atom types                         */
  HD_DOUBLE             Emin, Rmin;
} HD_PARHBONDPAIR;

/**** H-bond parameters pairs (single precision) ****/

typedef struct __HdParHbondPf {
  struct __HdParHbondPf *Next;          /* Pointer to next list element       */
  struct __HdParHbondPf *Prev;          /* Pointer to previous list element   */
  HD_OCHAR              Type[2];        /* Atom types                         */
  HD_DOUBLE             Emin, Rmin;
} HD_PARHBONDPAIRF;

/**** Atom structure (double precision) ****/

typedef struct {
  HD_DOUBLE             x, y, z;        /* Coordinates                        */
  HD_DOUBLE             Charge;         /* Atomic charge                      */
  HD_ULONG              Num;            /* Atom number                        */
} HD_ENEATOM;

/**** Atom structure (single precision) ****/

typedef struct {
  HD_FLOAT              x, y, z;        /* Coordinates                        */
  HD_FLOAT              Charge;         /* Atomic charge                      */
  HD_ULONG              Num;            /* Atom number                        */
} HD_ENEATOMF;

/**** Angle structure (double precision) ****/

typedef struct {
  HD_ENEATOM            *Atoms[3];      /* Atom array                         */
  HD_DOUBLE             *BondLen[2];    /* Bond lenght array                  */
  HD_DOUBLE             Ktheta;         /* Force constant                     */
  HD_DOUBLE             Theta0;         /* Rest angle                         */
} HD_ENEANGLE;

/**** Angle structure (single precision) ****/

typedef struct {
  HD_ENEATOMF           *Atoms[3];      /* Atom array                         */
  HD_FLOAT              *BondLen[2];    /* Bond lenght array                  */
  HD_FLOAT              Ktheta;         /* Force constant                     */
  HD_FLOAT              Theta0;         /* Rest angle                         */
} HD_ENEANGLEF;

/**** Bond structure (double precision) ****/

typedef struct {
  HD_ENEATOM            *Atoms[2];      /* Atom array                         */
  HD_DOUBLE             Len;            /* Bond lenght                        */
  HD_DOUBLE             Kb;             /* Force constant for the bond        */
  HD_DOUBLE             B0;             /* Rest distance for the bond  (b0)   */
} HD_ENEBOND;

/**** Bond structure (single precision) ****/

typedef struct {
  HD_ENEATOMF           *Atoms[2];      /* Atom array                         */
  HD_FLOAT              Len;            /* Bond lenght                        */
  HD_FLOAT              Kb;             /* Force constant for the bond        */
  HD_FLOAT              B0;             /* Rest distance for the bond (b0)    */
} HD_ENEBONDF;

/**** Dihedral structure (double precision) ****/

typedef struct {
  HD_ENEATOM            *Atoms[4];      /* Atom array                         */
  HD_PARDIHEDRAL        *Param;         /* Parameters                         */
} HD_ENEDIHEDRAL;

/**** Dihedral structure (single precision) ****/

typedef struct {
  HD_ENEATOMF           *Atoms[4];      /* Atom array                         */
  HD_PARDIHEDRALF       *Param;         /* Parameters                         */
} HD_ENEDIHEDRALF;

/**** Improper structure (double precision) ****/

typedef struct {
  HD_ENEATOM            *Atoms[4];      /* Atom array                         */
  HD_PARIMPROPER        *Param;         /* Parameters                         */
} HD_ENEIMPROPER;

/**** Improper structure (single precision) ****/

typedef struct {
  HD_ENEATOMF           *Atoms[4];      /* Atom array                         */
  HD_PARIMPROPERF       *Param;         /* Parameters                         */
} HD_ENEIMPROPERF;

/**** Energy input (double precision) ****/

typedef struct {
  HD_ULONG              AtomNum;        /* Number of atoms                    */
  HD_ENEATOM            *AtomMtx;       /* Atom coordinates                   */

  HD_ULONG              AngleNum;       /* Number of angles                   */
  HD_ENEANGLE           *AngleMtx;      /* Angle matrix                       */

  HD_ULONG              BondNum;        /* Number of bonds                    */
  HD_ENEBOND            *BondMtx;       /* Bond matrix                        */

  HD_ULONG              DihedralNum;    /* Number of dihedrals                */
  HD_ENEDIHEDRAL        *DihedralMtx;   /* Dihedral matrix                    */
  HD_LIST               *DihedralPar;   /* Dihedral parameters                */

  HD_ULONG              ImproperNum;    /* Number of impropers                */
  HD_ENEIMPROPER        *ImproperMtx;   /* Improper matrix                    */
  HD_LIST               *ImproperPar;   /* Improper parameters                */

  HD_LONG               EnergyTerms;    /* Energy terms                       */

  /**** For private use only ****/

  HD_ATOM               **Angles;
  HD_ATOM               **Atoms;
  HD_ATOM               **Bonds;
  HD_ATOM               **Dihedrals;
  HD_ATOM               **Impropers;
} HD_ENEIN;

/**** Energy input (single precision) ****/

typedef struct {
  HD_ULONG              AtomNum;        /* Number of atoms                    */
  HD_ENEATOMF           *AtomMtx;       /* Atom coordinates                   */

  HD_ULONG              AngleNum;       /* Number of angles                   */
  HD_ENEANGLEF          *AngleMtx;      /* Angle matrix                       */

  HD_ULONG              BondNum;        /* Number of bonds                    */
  HD_ENEBONDF           *BondMtx;       /* Bond matrix                        */

  HD_ULONG              DihedralNum;    /* Number of dihedrals                */
  HD_ENEDIHEDRALF       *DihedralMtx;   /* Dihedral matrix                    */
  HD_LIST               *DihedralPar;   /* Dihedral parameters                */

  HD_ULONG              ImproperNum;    /* Number of impropers                */
  HD_ENEIMPROPERF       *ImproperMtx;   /* Improper matrix                    */
  HD_LIST               *ImproperPar;   /* Improper parameters                */

  HD_LONG               EnergyTerms;    /* Energy terms                       */

  /**** For private use only ****/

  HD_ATOM               **Angles;
  HD_ATOM               **Atoms;
  HD_ATOM               **Bonds;
  HD_ATOM               **Dihedrals;
  HD_ATOM               **Impropers;
} HD_ENEINF;

/**** Energy output (double precision) ****/

typedef struct {
  HD_DOUBLE             Angle;          /* Angle                              */
  HD_DOUBLE             Bond;           /* Bond                               */
  HD_DOUBLE             Dihedral;       /* Dihedral                           */
  HD_DOUBLE             Elect;          /* Electrostatic                      */
  HD_DOUBLE             Hbond;          /* H-bond                             */
  HD_DOUBLE             Improper;       /* Improper                           */
  HD_DOUBLE             Nbond;          /* Non bond                           */
} HD_ENEOUT;

/**** Energy output (single precision) ****/

typedef struct {
  HD_FLOAT              Angle;          /* Angle                              */
  HD_FLOAT              Bond;           /* Bond                               */
  HD_FLOAT              Dihedral;       /* Dihedral                           */
  HD_FLOAT              Elect;          /* Electrostatic                      */
  HD_FLOAT              Hbond;          /* H-bond                             */
  HD_FLOAT              Improper;       /* Improper                           */
  HD_FLOAT              Nbond;          /* Non bond                           */
} HD_ENEOUTF;

/**** H-bond ****/

typedef struct __HdHbond {
  struct __HdHbond      *Next;          /* Pointer to next list element       */
  struct __HdHbond      *Prev;          /* Pointer to previous list element   */
  HD_ATOM               *Acc;           /* H-bond acceptor                    */
  HD_ATOM               *Don;           /* H-bond donor                       */
  HD_FLOAT                 Ene;            /* H-bond energy                      */
} HD_HBOND;

/**** Force field assigned prameters ****/

typedef struct {
  HD_ATOM **            BegAngles;      /* Angle array                        */
  HD_ATOM *             BegAtoms;       /* Atom list                          */
  HD_ATOM **            BegBonds;       /* Bond array                         */
  HD_ATOM **            BegDihedrals;   /* Dihedral array                     */
  HD_ATOM **            BegImpropers;   /* Improper array                     */
  HD_PAR                Missing;        /* Missing parameters                 */
  HD_PARANGLE **        Angles;         /* Angles                             */
  HD_PARBOND **         Bonds;          /* Bonds                              */
  HD_PARDIHEDRAL **     Dihedrals;      /* Dihedrals                          */
  HD_PARHBONDPAIR **    HbondPairs;     /* H-bond pairs                       */
  HD_PARIMPROPER **     Impropers;      /* Impropers                          */
  HD_PARNONBONDED **    Nbonds;         /* Non bonds                          */
  HD_PARNONBONDPAIR **  NbondPairs;     /* Non bond pairs                     */
  HD_ULONG              AngleNum;       /* Number of bonds                    */
  HD_ULONG              AtomNum;        /* Number of atoms                    */
  HD_ULONG              BondNum;        /* Number of bonds                    */
  HD_ULONG              DihedralNum;    /* Number of dihedrals                */
  HD_ULONG              ImproperNum;    /* Number of impropers                */
} HD_PARATM;

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE

/**** Energy ****/

#  define  HD_EneChkPar                 _HD_EneChkPar
#  define  HD_EneChkParf                _HD_EneChkParf
#  define  HD_EneInFree                 _HD_EneInFree
#  define  HD_EneInFreef                _HD_EneInFreef
#  define  HD_EneHbondf                 _HD_EneHbondf
#  define  HD_EneHBondPairf             _HD_EneHBondPairf
#  define  HD_EneParGetf                _HD_EneParGetf
#  define  HD_EneParGeti                _HD_EneParGeti
#  define  HD_EneParSetf                _HD_EneParSetf
#  define  HD_EneParSeti                _HD_EneParSeti
#  define  HD_ScoreCalc                 _HD_ScoreCalc

/**** Parameters ****/

#  define  HD_ParAppend                 _HD_ParAppend
#  define  HD_ParAssAngles              _HD_ParAssAngles
#  define  HD_ParAssBonds               _HD_ParAssBonds
#  define  HD_ParAssDihedrals           _HD_ParAssDihedrals
#  define  HD_ParAssImpropers           _HD_ParAssImpropers
#  define  HD_ParAssNonBonded           _HD_ParAssNonBonded
#  define  HD_ParAtmAssign              _HD_ParAtmAssign
#  define  HD_ParAtmFree                _HD_ParAtmFree
#  define  HD_ParCalcVdW                _HD_ParCalcVdW
#  define  HD_ParFree                   _HD_ParFree
#  define  HD_ParListMerge              _HD_ParListMerge
#  define  HD_ParLoad                   _HD_ParLoad
#  define  HD_ParMerge                  _HD_ParMerge
#  define  HD_ParSave                   _HD_ParSave
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

/**** Energy ****/

HDRIVE_EXTERN HD_ENEIN *     HDRIVE_EXPORT HD_EneChkPar(HD_PAR *FFParMis, HD_ATOM *InizAtm, HD_ULONG AtomNum, HD_PAR *FFPar, HD_LONG EnergyTerms);
HDRIVE_EXTERN HD_ENEINF *    HDRIVE_EXPORT HD_EneChkParf(HD_PAR *FFParMis, HD_ATOM *InizAtm, HD_ULONG AtomNum, HD_PAR *FFPar, HD_LONG EnergyTerms);
HDRIVE_EXTERN HD_VOID        HDRIVE_EXPORT HD_EneInFree(HD_ENEIN *EneIn);
HDRIVE_EXTERN HD_VOID        HDRIVE_EXPORT HD_EneInFreef(HD_ENEINF *EneIn);
HDRIVE_EXTERN HD_ULONG       HDRIVE_EXPORT HD_EneHbondf(HD_LIST **HbondList, HD_FLOAT *Energy, HD_ATOM **AcceptorMtx, HD_ULONG Acceptors,
                                                        HD_ATOM **DonorMtx, HD_ULONG Donors, HD_LIST *HbondPairs);
HDRIVE_EXTERN HD_FLOAT       HDRIVE_EXPORT HD_EneHBondPairf(HD_ATOM *Don1, HD_ATOM *Acc, HD_FLOAT Dist, HD_FLOAT Eps, HD_FLOAT Rmin);
HDRIVE_EXTERN HD_BOOL        HDRIVE_EXPORT HD_EneParGetf(HD_FLOAT *Val, const HD_CHAR *Key, HD_BOOL Default);
HDRIVE_EXTERN HD_BOOL        HDRIVE_EXPORT HD_EneParGeti(HD_LONG *Val, const HD_CHAR *Key, HD_BOOL Default);
HDRIVE_EXTERN HD_BOOL        HDRIVE_EXPORT HD_EneParSetf(const HD_CHAR *Key, HD_FLOAT Val);
HDRIVE_EXTERN HD_BOOL        HDRIVE_EXPORT HD_EneParSeti(const HD_CHAR *Key, HD_LONG Val);
HDRIVE_EXTERN HD_BOOL        HDRIVE_EXPORT HD_ScoreCalc(HD_FLOAT *Energy, HD_FLOAT **EnergyVect, HD_ATOM *InizRec, HD_ULONG TotRec, HD_ATOM *InizLig, HD_ULONG TotLig, HD_SCORECALLBACK Fctn, HD_BOOL ActiveOnly, HD_VOID *UserArg);

/**** Force field parameters ****/

HDRIVE_EXTERN HD_BOOL        HDRIVE_EXPORT HD_ParAppend(HD_PAR *Par, const HD_CHAR *FileName);
HDRIVE_EXTERN HD_LIST *      HDRIVE_EXPORT HD_ParAssAngles(HD_PARANGLE **ParArray, HD_LIST *AnglePar, HD_ATOM **AngleMtx);
HDRIVE_EXTERN HD_LIST *      HDRIVE_EXPORT HD_ParAssBonds(HD_PARBOND **ParArray, HD_LIST *BondPar, HD_ATOM **BondMtx);
HDRIVE_EXTERN HD_LIST *      HDRIVE_EXPORT HD_ParAssDihedrals(HD_PARDIHEDRAL **ParArray, HD_LIST *DihedralPar, HD_ATOM **DihedralMtx);
HDRIVE_EXTERN HD_LIST *      HDRIVE_EXPORT HD_ParAssImpropers(HD_PARIMPROPER **ParArray, HD_LIST *ImproperPar, HD_ATOM **ImproperMtx);
HDRIVE_EXTERN HD_LIST *      HDRIVE_EXPORT HD_ParAssNonBonded(HD_PARNONBONDED **ParArray, HD_LIST *NonBondedPar, HD_ATOM *InizAtm);
HDRIVE_EXTERN HD_PARATM *    HDRIVE_EXPORT HD_ParAtmAssign(HD_PAR *FFPar, HD_ATOM *BegAtm, HD_ULONG AtomNum, HD_LONG EnergyTerms);
HDRIVE_EXTERN HD_VOID        HDRIVE_EXPORT HD_ParAtmFree(HD_PARATM *ParAtm);
HDRIVE_EXTERN HD_VOID        HDRIVE_EXPORT HD_ParCalcVdW(HD_LIST *Nbond);
HDRIVE_EXTERN HD_VOID        HDRIVE_EXPORT HD_ParFree(HD_PAR *Par);
HDRIVE_EXTERN HD_BOOL        HDRIVE_EXPORT HD_ParListMerge(HD_PAR *DestPar, HD_PAR *Par);
HDRIVE_EXTERN HD_BOOL        HDRIVE_EXPORT HD_ParLoad(HD_PAR *Par, const HD_CHAR *FileName);
HDRIVE_EXTERN HD_BOOL        HDRIVE_EXPORT HD_ParMerge(const HD_CHAR *DestFile, const HD_CHAR *SrcFile, HD_PAR *Par);
HDRIVE_EXTERN HD_BOOL        HDRIVE_EXPORT HD_ParSave(HD_PAR *Par, const HD_CHAR *FileName, const HD_CHAR *Header);

#  ifdef __cplusplus
   }
#  endif
#endif

