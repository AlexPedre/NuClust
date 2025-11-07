
/*********************************************
****      HyperDrive - Pharmacophore      ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifndef __HDPHARM_H
#  define  __HDPHARM_H

#  include <hdlist.h>


/**** Pharmacophoric point ****/

typedef struct __hd_pharmpt {
  struct __hd_pharmpt *         Next;           /* Pointer to next list item     */
  struct __hd_pharmpt *         Prev;           /* Pointer to previous list item */
  HD_XYZF                       Coord;          /* Cartesian coordinates         */
  HD_FLOAT                      Val;            /* Property value                */
} HD_PHARMPT;

/**** List of Pharmacophoric points ****/

typedef HD_LIST *               HD_PHARMPTLIST;

/**** Pharmaophoric field ****/

typedef struct __hd_pharmfield {
  struct __hd_pharmfield *      Next;           /* Pointer to next list item     */
  struct __hd_pharmfield *      Prev;           /* Pointer to previous list item */
  HD_LONG                       Id;             /* Field id (optional)           */
  HD_PHARMPTLIST                Points;         /* List of pharmacophoric points */
  HD_STRING                     Name;           /* Field name (optional)         */
} HD_PHARMFIELD;

/**** List of Pharmacophoric fields ****/

typedef HD_LIST *               HD_PHARMFIELDLIST;

/**** Pharmacophore ****/

struct __hd_pharm {
  HD_LONG                       Tag;            /* User data                     */
  HD_PHARMFIELDLIST             Fields;         /* Pharmacophoric fields         */
  HD_STRING                     Name;           /* Name (optional)               */
  HD_VOID *                     TagPtr;         /* Pointer to user data          */
};

typedef struct __hd_pharm *     HD_PHARM;

/**** Compare flags for _HD_PharmPtsFind() ****/

#  define  HD_PHARMFINDCMP_GT           0
#  define  HD_PHARMFINDCMP_LT           1

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_PharmFieldAdd           _HD_PharmFieldAdd
#    define  HD_PharmFieldCalc          _HD_PharmFieldCalc
#    define  HD_PharmFree               _HD_PharmFree
#    define  HD_PharmNew                _HD_PharmNew
#    define  HD_PharmNewC               _HD_PharmNewC

#    define  HD_PharmPtsFind            _HD_PharmPtsFind
#    define  HD_PharmPtsReduce          _HD_PharmPtsReduce
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_PHARMFIELD *   HDRIVE_EXPORT HD_PharmFieldAdd(HD_PHARM Pharm);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_PharmFieldCalc(HD_PHARM Pharm, HD_SRFINFO *SrfInfo, HD_FLOAT ThreshVal, HD_FLOAT CutDist, HD_LONG CmpMode);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_PharmFree(HD_PHARM Pharm);
HDRIVE_EXTERN HD_PHARM          HDRIVE_EXPORT HD_PharmNew(HD_STRING Name);
HDRIVE_EXTERN HD_PHARM          HDRIVE_EXPORT HD_PharmNewC(const HD_CHAR *Name);

HDRIVE_EXTERN HD_SURFACE **     HDRIVE_EXPORT HD_PharmPtsFind(HD_SRFINFO *SrfInfo, HD_FLOAT Val, HD_ULONG *TotPts, HD_LONG CmpMode);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_PharmPtsReduce(HD_SURFACE ***RawPharmPts, HD_ULONG *TotRawPharmPts, HD_FLOAT CutOff, HD_LONG CmpMode);

#  ifdef __cplusplus
   }
#  endif

#endif

