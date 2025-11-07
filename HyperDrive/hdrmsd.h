
/*********************************************
****       HyperDrive - RMSD header       ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifndef __HD_RMSD_H
#  define  __HD_RMSD_H

#  ifndef __HDRIVE_H
#    include "hyperdrive.h"
#  endif

/**** File attributes ****/

#  define  HD_RMSD_NONE                 0
#  define  HD_RMSD_ACTIVEONLY           1
#  define  HD_RMSD_HYDROGENS            2

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_RmsdCalc                _HD_RmsdCalc
#    define  HD_RmsdCalcHungarian       _HD_RmsdCalcHungarian
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_RmsdCalc(HD_ATOM *Atm0, HD_ATOM *Atm1, HD_ULONG AtmNum, HD_LONG Flags);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_RmsdCalcHungarian(HD_DOUBLE *Rmsd, HD_ATOM *Atm0, HD_ATOM *Atm1, HD_ULONG AtmNum, HD_ULONG *CipVect, HD_LONG Flags);

#  ifdef __cplusplus
   }
#  endif
#endif

