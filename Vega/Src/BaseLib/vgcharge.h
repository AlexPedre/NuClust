
/*************************************************
****               VEGA - Charge              ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_CHARGE_H
#  define  __VG_CHARGE_H

#  include <hyperdrive.h>

/**** Constants ****/

#  define       VG_CHGTOTAMINO         27
#  define       VG_CHGTEM_ATMMAX        8
#  define       VG_CHGTEM_IDMAX        32
#  define       VG_CHGTEM_RESDESCMAX  128
#  define       VG_CHGTEM_RESMAX       16

/**** Atom flags ****/

# define        VG_CHTEM_ATMFLG_ADD     0
# define        VG_CHTEM_ATMFLG_DEL     1

/**** Residue types ****/

# define        VG_CHTEM_RESTYP_RES     0
# define        VG_CHTEM_RESTYP_MACRO   1

/**** Atom charge structure ****/

typedef struct __vg_chgtematm {
  struct __vg_chgtematm *       Next;                           /* Pointer to next element     */
  struct __vg_chgtematm *       Prev;                           /* Pointer to prevoius element */
  HD_QCHAR                      Name[VG_CHGTEM_ATMMAX];         /* Residue names               */
  HD_FLOAT                      Charge;                         /* Atom charge                 */
  HD_BYTE                       NSost;                          /* Number of bonds             */
  HD_BYTE                       Flags;                          /* Atom flags                  */
  HD_UBYTE                      GroupID;                        /* Group ID                    */
  HD_UBYTE                      NameNum;                        /* Number of names             */
} VG_CHGTEM_ATM;

/**** Residue charge structure ****/

typedef struct __vg_chgtemres {
  struct __vg_chgtemres *       Next;                           /* Pointer to next element     */
  struct __vg_chgtemres *       Prev;                           /* Pointer to prevoius element */
  HD_CHAR                       Desc[VG_CHGTEM_RESDESCMAX];     /* Residue description         */
  HD_CHAR                       Id[VG_CHGTEM_IDMAX];            /* Identification string       */
  HD_QCHAR                      Name[VG_CHGTEM_RESMAX];         /* Residue names               */
  HD_ULONG                      NameNum;                        /* Number of names             */
  HD_LIST *                     Atoms;                          /* Atom list                   */
  HD_BYTE                       Type;                           /* Entry type                  */
} VG_CHGTEM_RES;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_ChargeTemFree                   _VG_ChargeTemFree
#    define  VG_ChargeTemLoad                   _VG_ChargeTemLoad
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_VOID                 VEGA_EXPORT VG_ChargeTemFree(HD_LIST **Tem);
VEGA_EXTERN HD_LIST *               VEGA_EXPORT VG_ChargeTemLoad(const HD_CHAR *Template);

#  ifdef __cplusplus
}
#  endif
#endif
