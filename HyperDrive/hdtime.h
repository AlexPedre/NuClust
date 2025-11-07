
/*******************************************
****      HyperDrive - Time header      ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#ifndef __HD_TIME_H
#  define  __HD_TIME_H

#  ifndef __HDRIVE_H
#    include "hyperdrive.h"
#  endif

/**** Constants ****/

#  define  HD_TM_DAYTOSEC               86400
#  define  HD_TM_HOURTOSEC              3600

/**** HD_Sleep() flags ****/

#  define HD_SLPUNIT_MSEC               0       /* Milliseconds               */
#  define HD_SLPUNIT_SEC                1       /* Seconds                    */
#  define HD_SLPUNIT_MIN                2       /* Minuts                     */
#  define HD_SLPUNIT_HRS                3       /* Hours                      */

/**** Time structure ****/

typedef struct {
  HD_UBYTE      Sec;                    /* Seconds                            */
  HD_UBYTE      Min;                    /* Minuts                             */
  HD_UBYTE      Hour;                   /* Hour                               */
  HD_UBYTE      Day;                    /* Day                                */
  HD_UBYTE      Mon;                    /* Month                              */
  HD_UBYTE      Year;                   /* Year (year - 1900)                 */
} HD_TIMESTRUCT;

/**** ETA structure ****/

typedef struct {
  HD_TIME       Eta;                    /* Estimated time                     */
  HD_UDLONG     IterCur;                /* Current iteration                  */
  HD_UDLONG     IterFirst;              /* First iteration                    */
  HD_UDLONG     IterLast;               /* Last iteration                     */
  HD_TIME       Start;                  /* Start time (sec.)                  */
} HD_ETA;

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_GetTickCount            _HD_GetTickCount
#    define  HD_GmTime                  _HD_GmTime
#    define  HD_GmTimeInt               _HD_GmTimeInt
#    define  HD_Sleep                   _HD_Sleep
#    define  HD_TimeStructD             _HD_TimeStructD
#    define  HD_TimeStructI             _HD_TimeStructI
#    define  HD_TimeToInt               _HD_TimeToInt
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_ULONG          HDRIVE_EXPORT HD_GetTickCount(HD_VOID);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_GmTime(HD_TIMESTRUCT *TimeStruct, HD_TIME Tm);
HDRIVE_EXTERN HD_TIME           HDRIVE_EXPORT HD_GmTimeInt(HD_VOID);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_Sleep(HD_ULONG Delay, HD_LONG Unit);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_TimeStructD(HD_TIMESTRUCT *TimeStruct, HD_DOUBLE Sec);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_TimeStructI(HD_TIMESTRUCT *TimeStruct, HD_ULONG Sec);
HDRIVE_EXTERN HD_TIME           HDRIVE_EXPORT HD_TimeToInt(HD_TIMESTRUCT *TimeStruct);

#  ifdef __cplusplus
   }
#  endif
#endif

