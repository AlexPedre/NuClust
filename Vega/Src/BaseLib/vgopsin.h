
/*******************************************
****       VEGA - OPSIN interface       ****
**** (c) 1996-2025, Alessandro Pedretti ****
*******************************************/


#ifndef __OPSIN_H
#  define  __OPSIN_H

#  include <hdprocess.h>

/**** Structure context ****/

struct __vg_opsin {
  HD_BOOL               Connected;      /* Connected flag                     */
  HD_LONG               Flags;          /* Flags                              */
  HD_PROC               hProc;          /* Process handle                     */
  HD_THREAD             hWaitThread;    /* Wait thread handle                 */
};

typedef struct __vg_opsin *     VG_OPSIN;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_OpsinContextCreate              _VG_OpsinContextCreate
#    define  VG_OpsinContexFree                 _VG_OpsinContexFree
#    define  VG_OpsinIupac2Smi                  _VG_OpsinIupac2Smi
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN VG_OPSIN        VEGA_EXPORT VG_OpsinContextCreate(HD_VOID);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_OpsinContexFree(VG_OPSIN hOpsin);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_OpsinIupac2Smi(VG_OPSIN hOpsin, HD_STRING Smiles, const HD_CHAR *Iupac);

#  ifdef __cplusplus
}
#  endif

#endif

