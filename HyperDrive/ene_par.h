
/*********************************************
****  HyperDrive - Force field parameters ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#include "hdfloat.h"


/**** Assign angle parameters (thread) ****/

static HD_LONG HD_CALLBACK HD_FP(TH_ParAssignAngles)(void *HdtGlobVars)
{
  HDT_BEGIN
    HD_ATOM             **AngleMtx;
    HD_VP(HD_ENEANGLE)  *OutMtx;
    HD_LIST             *AnglePar;
  HDT_END

  HD_ATOM               **Angle;
  HD_VP(HD_ENEANGLE)    *OutPtr;
  HD_PARANGLE           *Par;
  HD_ULONG              ThreadID;

  HD_ULONG              j = 1;

  HDT_ObtainThIDInt(ThreadID);

  for(Angle = HDT_GetVarTh(AngleMtx), OutPtr = HDT_GetVarTh(OutMtx);
      (GlobErrCode == HD_ERR_NONE) && (*Angle);
      Angle += 3, ++OutPtr) {
    if (j == ThreadID) {
      Par = (HD_PARANGLE *)HDT_GetVarTh(AnglePar) -> Beg;
      while(Par) {
        if ((ParCompare(Par -> Type[1], Angle[1]) &&
            ((ParCompare(Par -> Type[0], Angle[0]) && ParCompare(Par -> Type[2], Angle[2])) ||
             (ParCompare(Par -> Type[0], Angle[2]) && ParCompare(Par -> Type[2], Angle[0]))))) {
          OutPtr -> Ktheta = (HD_FLOAT_INT)Par -> ForceConst;
          OutPtr -> Theta0 = (HD_FLOAT_INT)Par -> Angle;
          break;
        }
        Par = Par -> Next;
      } /* End of while */
      if (!Par) {
        GlobErrCode = HD_ERR_ENE_PARNOTFOUND;
        return TRUE;
      }
    }
    if ((++j) > MthThreads) j = 1;
  } /* End of for */

  return FALSE;
}


/**** Assign angle parameters ****/

HD_BOOL HD_FASTCALL HD_FP(HD_ParAssignAngles)(HD_VP(HD_ENEANGLE) *OutMtx, HD_LIST *AnglePar, HD_ATOM **AngleMtx)
{
  HDT_BEGIN
    HD_ATOM             **AngleMtx;
    HD_VP(HD_ENEANGLE)  *OutMtx;
    HD_LIST             *AnglePar;
  HDT_END

  HD_LONG               Err;

  HDT_AllocGlobVarsInt();

  if (!AngleMtx) {
    GlobErrCode = HD_ERR_PARAM_EMPTYLIST;
    return FALSE;
  }

  HDT_GetVar(AngleMtx   ) = AngleMtx;
  HDT_GetVar(AnglePar   ) = AnglePar;
  HDT_GetVar(OutMtx     ) = OutMtx;

  if (MthThreads > 1) {
    Err = HD_MthCreateThreads(0, HD_FP(TH_ParAssignAngles),
                              &HdtGlobVars, HD_MTH_THREADS_WAIT);
    HDT_FreeGlobVarsInt();
  } else Err = HD_FP(TH_ParAssignAngles)(&HdtGlobVars);

  return (!Err);
}


/**** Assign bond parameters (thread) ****/

static HD_LONG HD_CALLBACK HD_FP(TH_ParAssignBonds)(void *HdtGlobVars)
{
  HDT_BEGIN
    HD_ATOM             **BondMtx;
    HD_VP(HD_ENEBOND)   *OutMtx;
    HD_LIST             *BondPar;
  HDT_END

  HD_ATOM               **Bond;
  HD_VP(HD_ENEBOND)     *OutPtr;
  HD_PARBOND            *Par;
  HD_ULONG              ThreadID;

  HD_ULONG              j = 1;

  HDT_ObtainThIDInt(ThreadID);

  for(Bond = HDT_GetVarTh(BondMtx), OutPtr = HDT_GetVarTh(OutMtx);
      (GlobErrCode == HD_ERR_NONE) && (*Bond);
      Bond += 2, ++OutPtr) {
    if (j == ThreadID) {
      Par = (HD_PARBOND *)HDT_GetVarTh(BondPar -> Beg);
      while(Par) {
        if ((ParCompare(Par -> Type[0], Bond[0]) && ParCompare(Par -> Type[1], Bond[1])) ||
            (ParCompare(Par -> Type[0], Bond[1]) && ParCompare(Par -> Type[1], Bond[0]))) {
          OutPtr -> Kb = (HD_FLOAT_INT)Par -> ForceConst;
          OutPtr -> B0 = (HD_FLOAT_INT)Par -> Dist;
          break;
        }
        Par = Par -> Next;
      } /* End of for */
      if (!Par) {
        GlobErrCode = HD_ERR_ENE_PARNOTFOUND;
        return TRUE;
      }
    }
    if ((++j) > MthThreads) j = 1;
  } /* End of for */

  return FALSE;
}


/**** Assign bond parameters ****/

HD_BOOL HD_FASTCALL HD_FP(HD_ParAssignBonds)(HD_VP(HD_ENEBOND) *OutMtx, HD_LIST *BondPar, HD_ATOM **BondMtx)
{
  HDT_BEGIN
    HD_ATOM             **BondMtx;
    HD_VP(HD_ENEBOND)   *OutMtx;
    HD_LIST             *BondPar;
  HDT_END

  HD_LONG               Err;
  HDT_AllocGlobVarsInt();

  if (!BondMtx) {
    GlobErrCode = HD_ERR_PARAM_EMPTYLIST;
    return FALSE;
  }

  HDT_GetVar(BondMtx   ) = BondMtx;
  HDT_GetVar(BondPar   ) = BondPar;
  HDT_GetVar(OutMtx    ) = OutMtx;

  if (MthThreads > 1) {
    Err = HD_MthCreateThreads(0, HD_FP(TH_ParAssignBonds),
                              &HdtGlobVars, HD_MTH_THREADS_WAIT);
    HDT_FreeGlobVarsInt();
  } else Err = HD_FP(TH_ParAssignBonds)(&HdtGlobVars);

  return (!Err);
}

