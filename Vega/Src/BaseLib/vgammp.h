
/*************************************************
****            VEGA - AMMP header            ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_AMMP_H
#  define  __VG_AMMP_H

#  include <hdmemstream.h>

/**** Constants ****/

#  define  VG_AMMP_PARAM                "SP4.par"
#  define  VG_AMMP_TEMPLATE             "SP4"

/**** Constraint ****/

#  define  VG_AMMP_CONST_NONE           0
#  define  VG_AMMP_CONST_FIX            1
#  define  VG_AMMP_CONST_TETHER         2

/**** Error codes ****/

#  define  VG_AMMP_ERR_NONE             0       /* No error                   */
#  define  VG_AMMP_ERR_DIED             1       /* Process died               */

/**** Minimization modes ****/

#  define  VG_AMMP_MIN_SINGLEPOINT      0       /* Don't change the order !   */
#  define  VG_AMMP_MIN_STEEP            1
#  define  VG_AMMP_MIN_TRUST            2
#  define  VG_AMMP_MIN_CONJU            3
#  define  VG_AMMP_MIN_QNEWT            4
#  define  VG_AMMP_MIN_TRUNC            5
#  define  VG_AMMP_MIN_GENETIC          6
#  define  VG_AMMP_MIN_POLYTOPE         7
#  define  VG_AMMP_MIN_RIGID            8

/**** Conformational search modes ****/

#  define  VG_AMMP_TSRC_SYSTEMATIC      0       /* Don't change the order !   */
#  define  VG_AMMP_TSRC_RANDOM          1
#  define  VG_AMMP_TSRC_BOLTZMANN       2

/**** Potential terms ****/

#  define  VG_AMMP_POT_ANGLE            0
#  define  VG_AMMP_POT_BOND             1
#  define  VG_AMMP_POT_HYBRID           2
#  define  VG_AMMP_POT_NONBOND          3
#  define  VG_AMMP_POT_TORSION          4

#  define  VG_AMMP_POT_TOT              5

/**** Angle potential types ****/

#  define  VG_AMMP_PANGLE_NONE          0       /* None                       */
#  define  VG_AMMP_PANGLE_ANGLE         1       /* Standard angle function    */
#  define  VG_AMMP_PANGLE_CANGLE        2       /* UFF cosine angle function  */
#  define  VG_AMMP_PANGLE_HOANGLE       3       /* Homotopy angle function    */
#  define  VG_AMMP_PANGLE_MMANGLE       4       /* MM3 angle function         */

/**** Bond potential types ****/

#  define  VG_AMMP_PBOND_NONE           0       /* None                       */
#  define  VG_AMMP_PBOND_BOND           1       /* Standard bond function     */
#  define  VG_AMMP_PBOND_HOBOND         2       /* Homotopy bond function     */
#  define  VG_AMMP_PBOND_MMBOND         3       /* MM3 bond function          */

/**** Nonbond potential types ****/

#  define  VG_AMMP_PNONBOND_NONE        0       /* None                       */
#  define  VG_AMMP_PNONBOND_NONBON      1       /* Standard nonbond function  */
#  define  VG_AMMP_PNONBOND_DEBYE       2       /* Debye screened function    */
#  define  VG_AMMP_PNONBOND_HARD        3       /* Hard shell function        */
#  define  VG_AMMP_PNONBOND_SCREEN      4       /* Screened function          */
#  define  VG_AMMP_PNONBOND_SHADOW      5       /* Shadow function            */

/**** Save flags ****/

#  define  VG_AMMP_SAVE_NONE            0       /* None                       */
#  define  VG_AMMP_SAVE_FIX             1       /* Atom fixing                */
#  define  VG_AMMP_SAVE_TETHER          2       /* Tether section             */


/**** Ammp context ****/

#  ifdef VEGA_ZZ

/**** Communication modes ****/

#    define  VG_AMMP_COM_PIPE           0
#    define  VG_AMMP_COM_TELNET         1

/**** Pipe modes ****/

#    define  VG_AMMP_PIPE_CON           0
#    define  VG_AMMP_PIPE_B64CHARGE     1
#    define  VG_AMMP_PIPE_B64XYZ        2
#    define  VG_AMMP_PIPE_CHARGE        3
#    define  VG_AMMP_PIPE_XYZ           4

#    define  VG_PIPE_BUFSIZE            1024

/**** Callback function ****/

typedef HD_BOOL (HD_FASTCALL *VG_AMMP_ENDFUNC)(HD_VOID *);

#  endif

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_AmmpLoad                        _VG_AmmpLoad
#    define  VG_AmmpLoadMem                     _VG_AmmpLoadMem
#    define  VG_AmmpSave                        _VG_AmmpSave
#    define  VG_AmmpSetFF                       _VG_AmmpSetFF
#    define  VG_AmmpSetHost                     _VG_AmmpSetHost
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_ATOM *         VEGA_EXPORT VG_AmmpLoad(VG_CTX *Ctx, FILE *FH, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_ATOM *         VEGA_EXPORT VG_AmmpLoadMem(VG_CTX *Ctx, HD_MEMSTREAM hStream, VG_RECORD *Lin, HD_ATOM **LastAtom, HD_ULONG *TotAtomi);
VEGA_EXTERN HD_BOOL           VEGA_EXPORT VG_AmmpSave(VG_CTX *Ctx, FILE *FH, const HD_CHAR *ForceField, HD_LONG Flags);
VEGA_EXTERN HD_BOOL           VEGA_EXPORT VG_AmmpSetFF(const HD_CHAR *Fname);
VEGA_EXTERN HD_VOID           VEGA_EXPORT VG_AmmpSetHost(HD_VOID *NewHost);

#  ifdef __cplusplus
}
#  endif
#endif

