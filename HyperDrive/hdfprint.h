
/*********************************************
****  HyperDrive - Molecular fingerprints ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifndef __HD_FPRINT_H
#  define  __HD_FPRINT_H

#  include <hyperdrive.h>

#  define  HD_FPTOP_NONE          0   /* None                           */
#  define  HD_FPTOP_ELEM          1   /* Consider the elements          */
#  define  HD_FPTOP_NOMTH         2   /* Don't use the multithreading   */

/**** End of fingerprint calculation ****/

#  define  HD_FPTOP_SEL_ACTIVE    0   /* Active only                    */
#  define  HD_FPTOP_SEL_ALL       1   /* All atoms                      */
#  define  HD_FPTOP_SEL_MOLECULE  2   /* Molecule                       */
#  define  HD_FPTOP_SEL_RESIDUE   3   /* Residue                        */
#  define  HD_FPTOP_SEL_SEGMENT   4   /* Segment                        */

/**** Types ****/

typedef struct {
  HD_ATOM *     Atm;            /* Atom pointer  */
  HD_ULONG      ClassID;        /* Atom class ID */
} HD_FPTOPCLASS;

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_FpTopCrc32              _HD_FpTopCrc32
#endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

/**** Base64 encoding/decoding ****/

HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_FpTopCrc32(HD_ULONG *Crc32, HD_ATOM *InizAtm, HD_ULONG AllAtmNum, HD_LONG Select, HD_LONG Flags);

#  ifdef __cplusplus
   }
#  endif
#endif

