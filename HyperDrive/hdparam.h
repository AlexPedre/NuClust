
/*********************************************
****  HyperDrive - Force field parameters ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifndef __HDPARAM_H
#  define  __HDPARAM_H

#  ifndef __HDRIVE_H
#    include "hyperdrive.h"
#  endif

/**** Energy parameter keywords ****/

enum {
  HD_ENEPAR_HBOND_AEXP = 0,
  HD_ENEPAR_HBOND_REXP,
  HD_ENEPAR_HBOND_HAEX,
  HD_ENEPAR_HBOND_AAEX,
  HD_ENEPAR_HBOND_HBCD,
  HD_ENEPAR_HBOND_HBCE,
  HD_ENEPAR_HBOND_HBDA,

  HD_ENEPAR_HBOND_END
};

/**** Parameters for the energy calculation ****/

typedef struct __HdEnePar {
  HD_LONG       Hbond_AEXP;                     /* H-Bond attractive term exponent    */
  HD_LONG       Hbond_REXP;                     /* H-Bond repulsive term exponent     */
  HD_LONG       Hbond_HAEX;                     /* H-Bond HA cosine exponent          */
  HD_LONG       Hbond_AAEX;                     /* H-Bond AA cosine exponent          */
  HD_FLOAT      Hbond_HBCD;                     /* H-Bond cutoff distance             */
  HD_FLOAT      Hbond_HBCE;                     /* H-Bond cutoff energy               */
  HD_FLOAT      Hbond_HBDA;                     /* H-Bond distance for surface calc.  */
} HD_ENEPAR;

#  ifdef HDRIVE_GLOBVAR

/**** Default parameters for the energy calculation ****/

HD_ENEPAR       EnePar;
const HD_ENEPAR DefEnePar       = { 4,          /* H-Bond attractive term exponent    */
                                    6,          /* H-Bond repulsive term exponent     */
                                    2,          /* H-Bond HA cosine exponent          */
                                    2,          /* H-Bond AA cosine exponent          */
                                    3.0f,       /* H-Bond cutoff distance             */
                                    -0.05f,     /* H-Bond cutoff energy               */
                                    0.96f,      /* H-Bond distance for surface calc.  */
                                  };

const char      *EneParKeys[]   = { "AEXP",     /* H-Bond                             */
                                    "REXP",
                                    "HAEX",
                                    "AAEX",
                                    "HBCD",
                                    "HBCE",
                                    "HBDA",
                                    HD_NULL
                                  };
#  else

extern const HD_CHAR *  EneParKeys[];
extern const HD_ENEPAR  DefEnePar;
extern HD_ENEPAR        EnePar;

#  endif
#endif
