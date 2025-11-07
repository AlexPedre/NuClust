
/*********************************************
****   HyperDrive - Molecular Mechanics   ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifndef __HDMM_PRIVATE_H
#  define  __HDMM_PRIVATE_H

#  ifndef __HDMM_H
#    include "hdmm.h"
#  endif

/**** Prototypes ****/

HD_BOOL HD_FASTCALL HD_ParAssignAngles(HD_ENEANGLE *OutMtx, HD_LIST *AnglePar, HD_ATOM **AngleMtx);
HD_BOOL HD_FASTCALL HD_ParAssignAnglesf(HD_ENEANGLEF *OutMtx, HD_LIST *AnglePar, HD_ATOM **AngleMtx);
HD_BOOL HD_FASTCALL HD_ParAssignBonds(HD_ENEBOND *OutMtx, HD_LIST *BondPar, HD_ATOM **BondMtx);
HD_BOOL HD_FASTCALL HD_ParAssignBondsf(HD_ENEBONDF *OutMtx, HD_LIST *BondPar, HD_ATOM **BondMtx);

#endif

