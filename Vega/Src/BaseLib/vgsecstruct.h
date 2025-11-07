
/*************************************************
****   VEGA - Secondary structure routines    ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_SECSTRUCT_H
#  define __VG_SECSTRUCT_H

/**** Structure types ****/

enum {
  VG_SSTYP_ALPHAHELIX,  /* Don't change the order ! */
  VG_SSTYP_LEFTHELIX,
  VG_SSTYP_310HELIX,
  VG_SSTYP_PIHELIX,
  VG_SSTYP_BETA,
  VG_SSTYP_BETAANTIPAR,
  VG_SSTYP_BETAPAR,
  VG_SSTYP_CUSTOM
};

/**** Change flags ****/

#  define  VG_SSCHG_NONE        0
#  define  VG_SSCHG_ACTIVEONLY  1
#  define  VG_SSCHG_ANGLES      2
#  define  VG_SSCHG_OMEGA       4
#  define  VG_SSCHG_PHI         8
#  define  VG_SSCHG_PSI        16

/**** Torsion values ****/

typedef struct {
  const HD_CHAR *  Name;       /* Struct. name   */
  HD_LONG          CodeChar;   /* Code char      */
  HD_DOUBLE        Phi;        /* Phi torsion    */
  HD_DOUBLE        Psi;        /* Psi torsion    */
  HD_DOUBLE        Omega;      /* Omega torsion  */
  HD_DOUBLE        AngCarb;    /* Carbonyl angle */
} VG_SSANGLES;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VegaSsAngles                       _VegaSsAngles

#    define  VG_SecStructChange                 _VG_SecStructChange
#  endif

/**** Global variables ****/

VEGA_EXTERNVAR const VG_SSANGLES      VegaSsAngles[];

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_BOOL       VEGA_EXPORT VG_SecStructChange(HD_ATOM *InizAtm, HD_ULONG TotAtm, HD_FLOAT Phi,
                                                         HD_FLOAT Psi, HD_FLOAT Omega, const HD_CHAR *Pattern, HD_LONG Flags);

#  ifdef __cplusplus
}
#  endif
#endif

