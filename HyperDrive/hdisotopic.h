
/*********************************************
****  HyperDrive - Isotopic distribution  ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifndef __HDISOTOPIC_H
#  define  __HDISOTOPIC_H

#  include <hyperdrive.h>

/**** _HD_IsoCalc() flags ****/

#  define  HD_ISOCALC_NONE              0 /* None                             */
#  define  HD_ISOCALC_PERCENT           1 /* Calculate percentual distrib.    */
#  define  HD_ISOCALC_SORTBYP           2 /* Sort the list by probability     */

/**** Isotopic errors ****/

#  define  HD_ERR_ISO_EMPTY          1301 /* File empty                       */
#  define  HD_ERR_ISO_FRMELEM        1302 /* Invelid element in formula       */
#  define  HD_ERR_ISO_FRMINV         1303 /* Invalid formula                  */
#  define  HD_ERR_ISO_FRMINVCHAR     1304 /* Invalid character in formula     */
#  define  HD_ERR_ISO_FRMINDEX       1305 /* Index too large in formula       */
#  define  HD_ERR_ISO_FRMUNKELEM     1306 /* Unknown element in formula       */
#  define  HD_ERR_ISO_INVMASSP       1307 /* Invalid mass or probability      */
#  define  HD_ERR_ISO_NOTHING        1308 /* Nothing to calculate             */
#  define  HD_ERR_ISO_UNKFORMAT      1309 /* Unknown isotope file format      */

/**** Isotope list ****/

typedef struct __hd_isotope {
  struct __hd_isotope * Next;           /* Pointer to next element            */
  struct __hd_isotope * Prev;           /* Pointer to prevoius element        */
  double                P;              /* Isotopic probability               */
  double                Mass;           /* Isotopic mass                      */
} HD_ISOTOPE;

/**** Element list ****/

typedef struct __hd_isoelem {
  struct __hd_isoelem * Next;           /* Pointer to next element            */
  struct __hd_isoelem * Prev;           /* Pointer to prevoius element        */
  HD_DCHAR              Symbol;         /* Element symbol                     */
  HD_LIST *             Isotopes;       /* Isotope list                       */
} HD_ISOELEM;

/**** Peak list ****/

typedef HD_ISOTOPE      HD_ISOPEAK;

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_IsoCalcFormula          _HD_IsoCalcFormula
#    define  HD_IsoCalcMolecule         _HD_IsoCalcMolecule
#    define  HD_IsoTabFree              _HD_IsoTabFree
#    define  HD_IsoTabLoad              _HD_IsoTabLoad
#    define  HD_MonoIsoCalcFormula      _HD_MonoIsoCalcFormula
#    define  HD_MonoIsoCalcMolecule     _HD_MonoIsoCalcMolecule
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_LIST *         HDRIVE_EXPORT HD_IsoCalcFormula(HD_LIST *IsoTable, const HD_CHAR *Formula, double Charge,
                                                                HD_ULONG MaxPeaks, HD_LONG Flags);
HDRIVE_EXTERN HD_LIST *         HDRIVE_EXPORT HD_IsoCalcMolecule(HD_LIST *IsoTable, HD_ATOM *Atm, double Charge,
                                                                 HD_ULONG MaxPeaks, HD_LONG Flags);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_IsoTabFree(HD_LIST *Table);
HDRIVE_EXTERN HD_LIST *         HDRIVE_EXPORT HD_IsoTabLoad(const HD_CHAR *FileName);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_MonoIsoCalcFormula(HD_LIST *IsoTable, const HD_CHAR *Formula);
HDRIVE_EXTERN HD_DOUBLE         HDRIVE_EXPORT HD_MonoIsoCalcMolecule(HD_LIST *IsoTable, HD_ATOM *Atm);

#  ifdef __cplusplus
   }
#  endif
#endif
