
/********************************************
****       NuClust - Builder class       ****
**** (c) 2022-2025 - Alessandro Pedretti ****
********************************************/


#ifndef __NUC_BUILD_H
#  define  __NUC_BUILD_H

#  include <list>
#  include <hdstring.h>
#  include <vgformats.h>

/**** Restraints file formats ****/

#  define NUC_RESTRFMT_OMM        0
#  define NUC_RESTRFMT_VEGA       1

/**** Nucleotide description ****/

typedef struct {
  HD_CHAR           BaseName;
  HD_QCHAR          ResName;
  HD_QCHAR          Name;
} NUC_NUCDESC;

/**** Restraint pair *****/

typedef struct {
  NUC_NUCDESC       N1;
  NUC_NUCDESC       N2;
  HD_FLOAT          Dist;
} NUC_RESTRAINTS;

/**** Restraint map ****/

typedef struct {
  HD_ATOM *         Atm1;
  HD_ATOM *         Atm2;
  HD_FLOAT          Dist;
} NUC_RESTRMAP;

/**** Residue ****/

typedef struct {
  HD_ATOM *         First;          /* First atom pointer                     */
  HD_ATOM *         Last;           /* Last atom pointer                      */
} NUC_RESIDUE;


/**** Restraints data ****/

/*
 * Célia Fonseca Guerra, F. Matthias Bickelhaupt, Jaap G. Snijders, and Evert Jan Baerends
 * "Hydrogen Bonding in DNA Base Pairs: Reconciliation of Theory and Experiment"
 * J. Am. Chem. Soc. 2000, 122, 4117-4128
 */

#  ifdef NUC_BUILD_DEF_DATA

const NUC_RESTRAINTS DnaRestraints[] = {

  /**** Whatson-Crick ****/

  {{'A', "DA\0"  , "N1\0"  }, {'T', "DT\0"  , "N3\0"  }, 2.81f},
  {{'A', "DA\0"  , "N6\0"  }, {'T', "DT\0"  , "O4\0"  }, 2.85f},

  {{'C', "DC\0"  , "N3\0"  }, {'G', "DG\0"  , "N1\0"  }, 2.88f},
  {{'C', "DC\0"  , "N4\0"  }, {'G', "DG\0"  , "O6\0"  }, 2.73f},
  {{'C', "DC\0"  , "O2\0"  }, {'G', "DG\0"  , "N2\0"  }, 2.87f},

  /**** Non Whatson-Crick ****/

  {{'A', "DA\0"  , "N7\0"  }, {'A', "DA\0"  , "N6\0"  }, 2.96f},
  {{'A', "DA\0"  , "N6\0"  }, {'A', "DA\0"  , "N1\0"  }, 2.96f},

  {{'A', "DA\0"  , "N7\0"  }, {'C', "DC\0"  , "N4\0"  }, 2.97f},
  {{'A', "DA\0"  , "N6\0"  }, {'C', "DC\0"  , "N3\0"  }, 2.94f},

  {{'G', "DG\0"  , "N7\0"  }, {'G', "DG\0"  , "N1\0"  }, 2.85f},
  {{'G', "DG\0"  , "O6\0"  }, {'G', "DG\0"  , "N2\0"  }, 2.91f},

  {{'G', "DG\0"  , "N1\0"  }, {'T', "DT\0"  , "O2\0"  }, 2.91f},
  {{'G', "DG\0"  , "O6\0"  }, {'T', "DT\0"  , "N3\0"  }, 2.75f},

  {{0  , "\0\0\0", "\0\0\0"}, {0  , "\0\0\0", "\0\0\0"}, 0.0f}};

const NUC_RESTRAINTS RnaRestraints[] = {

  /**** Whatson-Crick ****/

  {{'A', "A\0\0" , "N1\0"  }, {'U', "U\0\0" , "N3\0"  }, 2.85f},
  {{'A', "A\0\0" , "N6\0"  }, {'U', "U\0\0" , "O4\0"  }, 2.81f},

  {{'C', "C\0\0" , "N3\0"  }, {'G', "G\0\0" , "N1\0"  }, 2.88f},
  {{'C', "C\0\0" , "N4\0"  }, {'G', "G\0\0" , "O6\0"  }, 2.73f},
  {{'C', "C\0\0" , "O2\0"  }, {'G', "G\0\0" , "N2\0"  }, 2.87f},

  /**** Non Whatson-Crick ****/

  {{'A', "A\0\0" , "N7\0"  }, {'A', "D\0\0" , "N6\0"  }, 2.96f},
  {{'A', "A\0\0" , "N6\0"  }, {'A', "D\0\0" , "N1\0"  }, 2.96f},

  {{'A', "A\0\0" , "N7\0"  }, {'C', "D\0\0" , "N4\0"  }, 2.97f},
  {{'A', "A\0\0" , "N6\0"  }, {'C', "D\0\0" , "N3\0"  }, 2.94f},

  {{'G', "G\0\0" , "N7\0"  }, {'G', "D\0\0" , "N1\0"  }, 2.85f},
  {{'G', "G\0\0" , "O6\0"  }, {'G', "D\0\0" , "N2\0"  }, 2.91f},

  /**** Wobble ****/

  {{0  , "\0\0\0", "\0\0\0"}, {0  , "\0\0\0", "\0\0\0"}, 0.0f}};

  #  else

extern NUC_RESTRAINTS     DnaRestraints[];
extern NUC_RESTRAINTS     RnaRestraints[];

#  endif

/**** Build class ****/

class NUC_Build
{
  public:

        /**** Properties ****/

        HD_ULONG                    ResNum;
        std::list <NUC_RESTRMAP *>  RestList;

        /**** Methods ****/

                                    HD_FASTCALL NUC_Build();
                                    HD_FASTCALL ~NUC_Build();
        HD_VOID                     HD_FASTCALL Create3D(HDC_String &Seq, HD_LONG Type);
        HD_VOID                     HD_FASTCALL RestrAdd(HDC_String &Struct, HD_ULONG ClusterID, const HD_CHAR *Name);
        HD_VOID                     HD_FASTCALL Save3D(HDC_String &FileName);
        HD_VOID                     HD_FASTCALL SaveOmm(HDC_String Prefix, HDC_String &PdbFileName, HD_LONG SaveFlags);
        HD_VOID                     HD_FASTCALL SaveOmmCommon(HDC_String Prefix);

  private:

        /**** Properties ****/

        HD_LONG *                 ResPairs;
        HD_LONG                   NucType;
        HD_LONG                   ResPairsNum;
        HDC_String                CommonFileName;
        HDC_String                OmmTemplate;
        NUC_RESIDUE *             ResMap;
        VG_CTX *                  hVega;
        VG_FILEFORMAT *           OutFormat3D;

        /**** Methods ****/

        HD_ATOM *                 HD_FASTCALL GetAtm(NUC_RESIDUE *Res, HD_LONG Name);
        HD_VOID                   HD_FASTCALL RestrListAdd(NUC_RESIDUE *N1, NUC_RESIDUE *N2, const NUC_RESTRAINTS *RestDataPtr);
        HD_VOID                   HD_FASTCALL RestrListSave(const HD_CHAR *FileName, HD_LONG Format);
        HD_LONG                   HD_FASTCALL RestrScan(const HD_CHAR *Str, HD_LONG Idx);
        HD_LONG                   HD_FASTCALL StructChk(HDC_String &Struct);

};
#endif

