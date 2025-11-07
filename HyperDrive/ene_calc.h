
/*********************************************
****   HyperDrive - Energy calcualtion    ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#include "hdfloat.h"


/**** Free the energy resources ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_FP(HD_EneInFree)(HD_VP(HD_ENEIN) *EneIn)
{
  if (!EneIn) return;

  HD_FreeSafe(EneIn -> AngleMtx   );
  HD_FreeSafe(EneIn -> Angles     );
  HD_FreeSafe(EneIn -> BondMtx    );
  HD_FreeSafe(EneIn -> Bonds      );
  HD_FreeSafe(EneIn -> DihedralMtx);
  HD_FreeSafe(EneIn -> Dihedrals  );
  HD_FreeSafe(EneIn -> ImproperMtx);
  HD_FreeSafe(EneIn -> Impropers  );

  HD_ListClear(EneIn -> DihedralPar);
  HD_ListClear(EneIn -> ImproperPar);
  HD_Free(EneIn);
}


/**** Check the parameters for the initialization ****/

HDRIVE_EXTERN HD_VP(HD_ENEIN) * HDRIVE_EXPORT HD_FP(HD_EneChkPar)(HD_PAR *FFParMis, HD_ATOM *InizAtm, HD_ULONG AtomNum,
                                                                   HD_PAR *FFPar, HD_LONG EnergyTerms)
{
  HD_ATOM               *Atm;
  HD_ATOM               **Bnd;
  HD_VP(HD_ENEANGLE)    *AngMtxPtr;
  HD_VP(HD_ENEATOM)     *AngBnd1, *AngBnd2, *AtmMtxPtr;
  HD_VP(HD_ENEBOND)     *BndMtxPtr, *BndMtxStart;
  HD_VP(HD_ENEDIHEDRAL) *DihedMtxPtr;
  HD_VP(HD_ENEIMPROPER) *ImpMtxPtr;
  HD_VP(HD_ENEIN)       *EneIn;
  HD_ULONG              j, k;

  if ((!InizAtm) || (!EnergyTerms) || (!FFParMis)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_NULL;
  }

  if ((EneIn = HD_Calloc(sizeof(HD_VP(HD_ENEIN)))) == HD_NULL)
    return HD_NULL;

  GlobErrCode          = HD_ERR_NONE;
  EneIn -> AtomNum     = AtomNum;
  EneIn -> EnergyTerms = EnergyTerms;

  /**** Atoms ****/

  if ((EneIn -> AtomMtx = (HD_VP(HD_ENEATOM) *)HD_Calloc(sizeof(HD_VP(HD_ENEATOM)) * EneIn -> AtomNum)) == HD_NULL)
    return HD_NULL;

  AtmMtxPtr = EneIn -> AtomMtx;
  for(Atm = InizAtm; Atm; Atm = Atm -> Ptr) {
    AtmMtxPtr -> x      = (HD_FLOAT_INT)Atm -> x;
    AtmMtxPtr -> y      = (HD_FLOAT_INT)Atm -> y;
    AtmMtxPtr -> z      = (HD_FLOAT_INT)Atm -> z;
    AtmMtxPtr -> Charge = (HD_FLOAT_INT)Atm -> Charge;
    AtmMtxPtr -> Num    = Atm -> Num;
    ++AtmMtxPtr;
  } /* End of for (Atm) */

  /**** Bonds ****/

  if (EnergyTerms & (HD_ENECALC_ANGLE|HD_ENECALC_BOND|HD_ENECALC_DIHEDRAL)) {
    if ((EneIn -> BondNum = HD_GenBondMtx(InizAtm, &EneIn -> Bonds)) != 0) {
      if ((EneIn -> BondMtx = (HD_VP(HD_ENEBOND) *)HD_Malloc(sizeof(HD_VP(HD_ENEBOND)) * EneIn -> BondNum + 1)) == HD_NULL) {
        HD_FP(HD_EneInFree)(EneIn);
        return HD_NULL;
      }
      if (EnergyTerms & HD_ENECALC_BOND)
        FFParMis -> Bonds = HD_ParAssBonds(HD_NULL, FFPar -> Bonds, EneIn -> Bonds);

      for(Bnd = EneIn -> Bonds, BndMtxPtr = EneIn -> BondMtx;
          *Bnd; Bnd += 2, ++BndMtxPtr) {
        BndMtxPtr -> Atoms[0] = &EneIn -> AtomMtx[Bnd[0] -> Num - 1];
        BndMtxPtr -> Atoms[1] = &EneIn -> AtomMtx[Bnd[1] -> Num - 1];
      } /* End of for (Bnd) */
      BndMtxPtr -> Atoms[0] = HD_NULL;
      BndMtxPtr -> Atoms[1] = HD_NULL;
    } else {
      HD_FP(HD_EneInFree)(EneIn);
      return HD_NULL;
    }
  }

  /**** Angles ****/

  if (EnergyTerms & HD_ENECALC_ANGLE) {
    if ((EneIn -> AngleNum = HD_GenAngleMtx(InizAtm, &EneIn -> Angles)) != 0) {
      if ((EneIn -> AngleMtx = (HD_VP(HD_ENEANGLE) *)HD_Malloc(sizeof(HD_VP(HD_ENEANGLE)) * EneIn -> AngleNum + 1)) == HD_NULL) {
        HD_FP(HD_EneInFree)(EneIn);
        return HD_NULL;
      }
      FFParMis -> Angles = HD_ParAssAngles(HD_NULL, FFPar -> Angles, EneIn -> Angles);

      for(Bnd = EneIn -> Angles, AngMtxPtr = EneIn -> AngleMtx;
          *Bnd; Bnd += 3, ++AngMtxPtr) {
        AngMtxPtr -> Atoms[0] = &EneIn -> AtomMtx[Bnd[0] -> Num - 1];
        AngMtxPtr -> Atoms[1] = &EneIn -> AtomMtx[Bnd[1] -> Num - 1];
        AngMtxPtr -> Atoms[2] = &EneIn -> AtomMtx[Bnd[2] -> Num - 1];
      } /* End of for (Bnd) */
      AngMtxPtr -> Atoms[0] = HD_NULL;
      AngMtxPtr -> Atoms[1] = HD_NULL;
      AngMtxPtr -> Atoms[2] = HD_NULL;

      /**** Find the bond distances ****/

      AngMtxPtr   = EneIn -> AngleMtx;
      BndMtxStart = EneIn -> BondMtx;
      for(j = 0; j < EneIn -> AngleNum; ++j) {
        for(k = 0; k < 2; ++k) {
          if (AngMtxPtr -> Atoms[k] -> Num < AngMtxPtr -> Atoms[k + 1] -> Num) {
            AngBnd1 = AngMtxPtr -> Atoms[k    ];
            AngBnd2 = AngMtxPtr -> Atoms[k + 1];
          } else {
            AngBnd1 = AngMtxPtr -> Atoms[k + 1];
            AngBnd2 = AngMtxPtr -> Atoms[k    ];
          }
          while(BndMtxStart -> Atoms[0] != AngBnd1) ++BndMtxStart;

          for(BndMtxPtr = BndMtxStart; *BndMtxPtr -> Atoms; ++BndMtxPtr) {
            if (BndMtxPtr -> Atoms[1] == AngBnd2) {
              AngMtxPtr -> BondLen[k] = &BndMtxPtr -> Len;
              break;
            }
          } /* End of for (BndMtxPtr) */
        } /* End of for (k) */
        ++AngMtxPtr;
      } /* End of for (j) */
    } else {
      HD_FP(HD_EneInFree)(EneIn);
      return HD_NULL;
    }
  }

  /**** Dhiedrals ****/

  if (EnergyTerms & HD_ENECALC_DIHEDRAL) {
    if ((EneIn -> DihedralNum = HD_GenTorsionMtx(EneIn -> Bonds, &EneIn -> Dihedrals)) != 0) {
      if ((EneIn -> DihedralMtx = (HD_VP(HD_ENEDIHEDRAL) *)HD_Malloc(sizeof(HD_VP(HD_ENEDIHEDRAL)) * EneIn -> DihedralNum + 1)) == HD_NULL) {
        HD_FP(HD_EneInFree)(EneIn);
        return HD_NULL;
      }
      FFParMis -> Dihedrals = HD_ParAssDihedrals(HD_NULL, FFPar -> Dihedrals, EneIn -> Dihedrals);

      for(Bnd = EneIn -> Dihedrals, DihedMtxPtr = EneIn -> DihedralMtx;
          *Bnd; Bnd += 4, ++DihedMtxPtr) {
        DihedMtxPtr -> Atoms[0] = &EneIn -> AtomMtx[Bnd[0] -> Num - 1];
        DihedMtxPtr -> Atoms[1] = &EneIn -> AtomMtx[Bnd[1] -> Num - 1];
        DihedMtxPtr -> Atoms[2] = &EneIn -> AtomMtx[Bnd[2] -> Num - 1];
        DihedMtxPtr -> Atoms[3] = &EneIn -> AtomMtx[Bnd[3] -> Num - 1];
      } /* End of for (Bnd) */
      DihedMtxPtr -> Atoms[0] = HD_NULL;
      DihedMtxPtr -> Atoms[1] = HD_NULL;
      DihedMtxPtr -> Atoms[2] = HD_NULL;
      DihedMtxPtr -> Atoms[3] = HD_NULL;
    } else {
      HD_FP(HD_EneInFree)(EneIn);
      return HD_NULL;
    }
  }

  /**** Impropers ****/

  if (EnergyTerms & HD_ENECALC_IMPROPER) {
    if ((EneIn -> ImproperNum = HD_GenImproperMtx(InizAtm, &EneIn -> Impropers)) != 0) {
      if ((EneIn -> ImproperMtx = (HD_VP(HD_ENEIMPROPER) *)HD_Malloc(sizeof(HD_VP(HD_ENEIMPROPER)) * EneIn -> DihedralNum + 1)) == HD_NULL) {
        HD_FP(HD_EneInFree)(EneIn);
        return HD_NULL;
      }
      FFParMis -> Impropers = HD_ParAssImpropers(HD_NULL, FFPar -> Impropers, EneIn -> Impropers);

      for(Bnd = EneIn -> Impropers, ImpMtxPtr = EneIn -> ImproperMtx;
          *Bnd; Bnd += 4, ++ImpMtxPtr) {
        ImpMtxPtr -> Atoms[0] = &EneIn -> AtomMtx[Bnd[0] -> Num - 1];
        ImpMtxPtr -> Atoms[1] = &EneIn -> AtomMtx[Bnd[1] -> Num - 1];
        ImpMtxPtr -> Atoms[2] = &EneIn -> AtomMtx[Bnd[2] -> Num - 1];
        ImpMtxPtr -> Atoms[3] = &EneIn -> AtomMtx[Bnd[3] -> Num - 1];
      } /* End of for (Bnd) */
      ImpMtxPtr -> Atoms[0] = HD_NULL;
      ImpMtxPtr -> Atoms[1] = HD_NULL;
      ImpMtxPtr -> Atoms[2] = HD_NULL;
      ImpMtxPtr -> Atoms[3] = HD_NULL;
    } else {
      HD_FP(HD_EneInFree)(EneIn);
      return HD_NULL;
    }
  }

  /**** Non bond ****/

  if (EnergyTerms & HD_ENECALC_NBOND)
    FFParMis -> Nbond = HD_ParAssNonBonded(HD_NULL, FFPar -> Nbond, InizAtm);

  return EneIn;
}


/**** Assign the parameters ****/

HDRIVE_EXTERN HD_BOOL HDRIVE_EXPORT HD_FP(HD_EneAssignPar)(HD_VP(HD_ENEIN) *EneIn, HD_PAR *FFPar)
{
  if (EneIn -> EnergyTerms & HD_ENECALC_ANGLE) {
    if (!HD_FP(HD_ParAssignAngles)(EneIn -> AngleMtx, FFPar -> Angles, EneIn -> Angles))
      return FALSE;

    HD_Free(EneIn -> Angles);
    EneIn -> Angles = HD_NULL;
  }

  if (EneIn -> EnergyTerms & HD_ENECALC_BOND) {
    if (!HD_FP(HD_ParAssignBonds)(EneIn -> BondMtx, FFPar -> Bonds, EneIn -> Bonds))
      return FALSE;
    HD_Free(EneIn -> Bonds);
    EneIn -> Bonds = HD_NULL;
  }

  return TRUE;
}

