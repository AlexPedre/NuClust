
/*************************************************
****       VEGA - Hybridization template      ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_HYBTEM_H
#  define  __VG_HYBTEM_H

#  include <hdlist.h>

/**** Hybridization templates ****/

#  define  VG_HYB_TEM_NA                "NA.hyb"
#  define  VG_HYB_TEM_PROT              "PROTEIN.hyb"

/**** VG_HybTemLoad() flags ****/

#  define  VG_HYM_FLGLOAD_NONE          0       /* No spacial flags                 */
#  define  VG_HYM_FLGLOAD_USECACHE      1       /* Use the cache                    */
#  define  VG_HYM_FLGLOAD_CHECKCHANGE   2       /* Check if the template is changed */

/**** Flags for VG_ADDHPOT ****/

#  define  VG_HYB_FLGPOT_NONE           0       /* No spacial flags                 */
#  define  VG_HYB_FLGPOT_CONTINUE       1       /* Continue search                  */

/**** Jolly character ****/

#  ifdef LITTLE_ENDIAN
#    define  VG_ADDH_ASTQ               0x0000002a
#  else
#    define  VG_ADDH_ASTQ               0x2a000000
#  endif

/**** Hybridization handle ****/

typedef struct __vg_hyb {
  struct __vg_hyb *     Next;
  struct __vg_hyb *     Prev;
  HD_STRING             FileName;       /* File name                          */
  long                  LastMod;        /* Time of the last modification      */
  HD_LIST *             HybPot;         /* Atom types                         */
} VG_HYB;

/**** Hybridization potential ****/

typedef struct __vg_hyb_pot {
  struct __vg_hyb_pot * Next;           /* Pointer to the next element        */
  struct __vg_hyb_pot * Prev;           /* Pointer to the prevoius element    */
  HD_QCHAR              ResName;        /* Residue name                       */
  HD_QCHAR              Name;           /* Atom name                          */
  HD_OCHAR              Pot;            /* Atom type                          */
  HD_WORD               Flags;          /* Flags                              */
  HD_WORD               Warn;           /* Warning message                    */
} VG_HYBPOT;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_HybTemAtmCheck                  _VG_HybTemAtmCheck
#    define  VG_HybTemCacheFree                 _VG_HybTemCacheFree
#    define  VG_HybTemLoad                      _VG_HybTemLoad
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_WORD         VEGA_EXPORT VG_HybTemAtmCheck(HD_ATOM *Atm, HD_LIST *InizTem, HD_OCHAR *CorPot);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_HybTemCacheFree(HD_VOID);
VEGA_EXTERN HD_LIST *       VEGA_EXPORT VG_HybTemLoad(const HD_CHAR *FileName, HD_LONG Flags);

#  ifdef __cplusplus
}
#  endif
#endif

