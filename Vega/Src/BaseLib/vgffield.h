
/*************************************************
****      VEGA - Force Field Attribution      ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_FFIELD_H
#  define  __VG_FFIELD_H

#  include <hdatdl.h>

/**** Constatnts ****/

#  define  VG_SMARTS_PURGE  1000            /* Number of calls after that SMARTS  */
                                            /* is purged                          */
/**** SMARTS atom type ****/

typedef struct __vg_smarts_type {
  struct __vg_smarts_type * Next;
  struct __vg_smarts_type * Prev;
  HD_OCHAR                  Type;           /* Atom type                          */
  HD_LONG                   Handle;         /* Indigo handle                      */
  HD_STRING                 Smarts;         /* Smarts string                      */
} VG_SMARTS_TYPE;

/**** SMARTS template handle ****/

typedef struct __vg_smarts_temp {
  struct __vg_smarts_temp * Next;
  struct __vg_smarts_temp * Prev;
  HD_STRING                 Name;           /* Potential name                     */
  HD_STRING                 FileName;       /* File name                          */
  HD_LONG                   Version;        /* Version                            */
  HD_LONG                   Revision;       /* Revision                           */
  HD_UDLONG                 SessionID;      /* Indigo session ID                  */
  HD_ULONG                  Count;          /* Conter to purge the data           */
  long                      LastMod;        /* Time of the last modification      */
  HD_LIST *                 AtTypes;        /* Atom types                         */
} VG_SMARTS_TEMP;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_AssignFF                        _VG_AssignFF
#    define  VG_AtdlLoad                        _VG_AtdlLoad
#    define  VG_AtmToAtdl                       _VG_AtmToAtdl
#    define  VG_ChkTempFF                       _VG_ChkTempFF
#    define  VG_FindRing                        _VG_FindRing
#    define  VG_SmartsAssign                    _VG_SmartsAssign
#    define  VG_SmartsFreeCache                 _VG_SmartsFreeCache
#    define  VG_SmartsLoad                      _VG_SmartsLoad
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_BOOL             VEGA_EXPORT VG_AssignFF(VG_CTX *Ctx, const HD_CHAR *FFFile, HD_BOOL ActiveOnly, HD_BOOL Quiet);
VEGA_EXTERN HD_ATDL *           VEGA_EXPORT VG_AtdlLoad(VG_CTX *Ctx, const HD_CHAR *FFFile, HD_BOOL Quiet);
VEGA_EXTERN HD_VOID             VEGA_EXPORT VG_AtmToAtdl(HD_CHAR *Str, HD_ATOM *Atm);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT VG_ChkTempFF(HD_STRING FileName, const HD_CHAR *TempName);
VEGA_EXTERN HD_VOID             VEGA_EXPORT VG_FindRing(VG_CTX *Ctx, HD_ATOM *InizAtm, HD_BOOL Quiet);
VEGA_EXTERN HD_BOOL             VEGA_EXPORT VG_SmartsAssign(VG_SMARTS_TEMP *Smarts, HD_ATOM *InizAtm, HD_ULONG TotAtm, HD_BOOL ActiveOnly);
VEGA_EXTERN HD_VOID             VEGA_EXPORT VG_SmartsFreeCache(HD_VOID);
VEGA_EXTERN VG_SMARTS_TEMP *    VEGA_EXPORT VG_SmartsLoad(VG_CTX *Ctx, const HD_CHAR *FileName, HD_BOOL Quiet);

#  ifdef __cplusplus
}
#  endif
#endif
