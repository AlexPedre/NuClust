
/********************************************
****       NuClust - Builder class       ****
**** (c) 2022-2025 - Alessandro Pedretti ****
********************************************/


#include <stdio.h>
#include <string.h>

#include <hdfile.h>
#include <hdstring.h>
#include <math.h>

#include <vgbase.h>
#include <vgdna.h>
#include <vghdstrutils.h>
#include <vgpk_def.h>

#ifdef __BORLANDC__
#  pragma hdrstop
#  pragma argsused
#endif

/**** Constants ****/

#define  NUC_BUILD_DEF_DATA
#define  NUC_RESTR_K            1.0f

#include "globals.h"
#include "build.h"

/**** Constructor ****/

HD_FASTCALL NUC_Build::NUC_Build()
{
  ResMap   = NULL;
  ResPairs = NULL;

  /**** Create the VEGA context ****/

  if ((hVega = VG_CtxCreate()) == NULL)
    NUC_Error(TRUE, "Can't create the VEGA context");

  /**** Choose the output format ****/

  for(OutFormat3D = VegaFileInfo; (OutFormat3D -> Com) && (strcasecmp("PDBOMM", OutFormat3D -> Com)); ++OutFormat3D);
  hVega -> GLOBSW_CONNSAV = TRUE;
}


/**** Destructor ****/

HD_FASTCALL NUC_Build::~NUC_Build(HD_VOID)
{
  delete [] ResMap;
  delete [] ResPairs;

  VG_CtxFree(hVega);
}


/**** Build the 3D structure ****/

HD_VOID HD_FASTCALL NUC_Build::Create3D(HDC_String &Seq, HD_LONG Type)
{
  HD_ATOM *       Atm;

  if ((hVega -> BegAtm = VG_DnaBuild(hVega, Seq.Cstr(),
                                     Type == NUC_TYPE_DNA ? VG_DNA_ADNA : VG_RNA_ARNA,
                                     &hVega -> LastAtm, &hVega -> TotalAtm,
                                     VG_DNA_BUILD_CHAIN53|VG_DNA_BUILD_ADDHYDROG|VG_DNA_BUILD_NORMALIZE)) == NULL) {
     NUC_Error(TRUE, "Can't build the nucleic acid");
  }

  NucType = Type;
  ResNum  = Seq.Len();

  /**** Build the residue map ****/

  ResMap = new NUC_RESIDUE [ResNum];
  NUC_RESIDUE *ResPtr = ResMap;

  ResPtr -> First = hVega -> BegAtm;
  for(Atm = hVega -> BegAtm -> Ptr; Atm; Atm = Atm -> Ptr) {
    if (ResPtr -> First -> ResSeq.L != Atm -> ResSeq.L) {
      ResPtr -> Last = Atm -> Prev;
      ++ResPtr;
      ResPtr -> First = Atm;
    }

    /**** Fix the atom names ****/

    if ((Atm -> Name.C[0] == 'H') && (Atm -> Name.C[2] == '\'')) {
      if (Atm -> Name.C[3] == '1') Atm -> Name.C[3] = 0;
      else if (Atm -> Name.C[3] == '2') Atm -> Name.C[3] = '\'';
    }
  } /* End of for (Atm) */

  ResPtr -> Last = hVega -> LastAtm;

  /**** Fix the hydrogen names at 5' ****/

  for(Atm = ResMap[0].First; Atm; Atm = Atm -> Ptr) {
    if (Atm -> Name.L == *(HD_LONG *)"H5'") {
      Atm -> Name.L = *(HD_LONG *)"HO5'";
      break;
    }
  } /* End of for (Atm) */

  /**** Fix the hydrogen names at 3' ****/

  for(Atm = ResMap[ResNum - 1].First; Atm; Atm = Atm -> Ptr) {
    if (Atm -> Name.L == *(HD_LONG *)"H3'") {
      Atm -> Name.L = *(HD_LONG *)"HO3'";
      break;
    }
  } /* End of for (Atm) */
}


/**** Get the atom number ****/

HD_ATOM * HD_FASTCALL NUC_Build::GetAtm(NUC_RESIDUE *Res, HD_LONG Name)
{
  for(HD_ATOM *Atm = Res -> First; Atm; Atm = Atm -> Ptr) {
    if (Atm -> Name.L == Name) return Atm;
    if (Atm == Res -> Last) break;
  } /* End of for (Atm) */

  return NULL;
}


/**** Add the restraints ****/

HD_VOID HD_FASTCALL NUC_Build::RestrAdd(HDC_String &Struct, HD_ULONG ClusterID, const HD_CHAR *Name)
{
  HD_LONG                 NumOpen  = StructChk(Struct);

  if (NumOpen == -1)
    NUC_Error(TRUE, "Invalid secondary structure");

  /**** Scan to get the pair indexes ****/

  delete [] ResPairs;
  ResPairs    = new HD_LONG [NumOpen * 2];
  ResPairsNum = 0;
  RestrScan(Struct.Cstr(), 0);

  /**** Search for the atom pairs ****/

  const NUC_RESTRAINTS *  RestDataPtr;

  HD_LONG *               Pair     = ResPairs;
  const NUC_RESTRAINTS *  RestData = (NucType == NUC_TYPE_DNA) ? DnaRestraints : RnaRestraints;

  RestList.clear();
  for(HD_LONG k = 0; k < NumOpen; ++k) {
    HD_BOOL         Found = FALSE;
    NUC_RESIDUE *   N1    = ResMap + Pair[0];
    NUC_RESIDUE *   N2    = ResMap + Pair[1];

    for(RestDataPtr = RestData; RestDataPtr -> Dist; ++RestDataPtr) {
      if ((RestDataPtr -> N1.ResName.L == N1 -> First -> ResName.L) &&
          (RestDataPtr -> N2.ResName.L == N2 -> First -> ResName.L)) {
        RestrListAdd(N1, N2, RestDataPtr);
        Found = TRUE;
      } else if ((RestDataPtr -> N1.ResName.L == N2 -> First -> ResName.L) &&
                 (RestDataPtr -> N2.ResName.L == N1 -> First -> ResName.L)) {
        RestrListAdd(N2, N1, RestDataPtr);
        Found = TRUE;
      }
    } /* End of for (RestDataPtr) */

    if (!Found) {
      if (ClusterID) {
        NUC_Warning("Invalid base pair %.4s:%.4s - %.4s:%.4s in %s structure cluster %u",
                  N1 -> First -> ResName.C, N1 -> First -> ResSeq.C,
                  N2 -> First -> ResName.C, N2 -> First -> ResSeq.C,
                  Name, ClusterID);
      } else {
        NUC_Warning("Invalid base pair %.4s:%.4s - %.4s:%.4s in %s structure",
                  N1 -> First -> ResName.C, N1 -> First -> ResSeq.C,
                  N2 -> First -> ResName.C, N2 -> First -> ResSeq.C,
                  Name);
      }
    }
    Pair += 2;
  } /* End of for (k) */
}


/**** Add a pair to the restraints list ****/

HD_VOID HD_FASTCALL NUC_Build::RestrListAdd(NUC_RESIDUE *N1, NUC_RESIDUE *N2, const NUC_RESTRAINTS *RestDataPtr)
{
  NUC_RESTRMAP *  Rest = new NUC_RESTRMAP;

  Rest -> Dist = RestDataPtr -> Dist;
  Rest -> Atm1 = GetAtm(N1, RestDataPtr -> N1.Name.L);
  Rest -> Atm2 = GetAtm(N2, RestDataPtr -> N2.Name.L);

  if ((!Rest -> Atm1) || (!Rest -> Atm2)) {
    NUC_Error(TRUE, "Can't find the distance for %.4s:%.4s - %.4s:%.4s nucleotides",
              N1 -> First -> ResName.C, N1 -> First -> ResSeq.C,
              N2 -> First -> ResName.C, N2 -> First -> ResSeq.C);
  }

  RestList.push_back(Rest);
}


/**** Save the restraint list to a text file ****/

HD_VOID HD_FASTCALL NUC_Build::RestrListSave(const HD_CHAR *FileName, HD_LONG Format)
{
  FILE *    FH;

  if ((FH = fopen(FileName, "w")) == NULL)
    NUC_Error(TRUE, "Can't create the restraint file");

  try {
    std::list <NUC_RESTRMAP *>::iterator  Rest;

    HD_ATOM *   PrevAtm1 = NULL;
    HD_ULONG    PairID   = 1;

    /**** Write the header ****/

    if ((Format == NUC_RESTRFMT_VEGA) &&
        (fprintf(FH, "@echo off\n"
                     "echo * Showing the constraints in VEGA ZZ\n"
                     "\n") <= 0))
      throw 0;

    for(Rest = RestList.begin(); Rest != RestList.end(); ++Rest) {
     HD_ATOM *      Atm1 = (*Rest) -> Atm1;
     HD_ATOM *      Atm2 = (*Rest) -> Atm2;

     switch(Format) {
     case NUC_RESTRFMT_OMM:
       if (fprintf(FH, "%-6u %-6u %-6u %5.3f %10.3f %.2s:%.4s:%.4s %.2s:%.4s:%.4s\n",
                   PairID, Atm1 -> Num, Atm2 -> Num, (*Rest) -> Dist / 10.0f, NUC_RESTR_K,
                   Atm1 -> Name.C, Atm1 -> ResName.C, Atm1 -> ResSeq.C,
                   Atm2 -> Name.C, Atm2 -> ResName.C, Atm2 -> ResSeq.C) <= 0)
         throw 0;
       if (PrevAtm1) {
         if ((PrevAtm1 -> ResName.L != Atm1 -> ResName.L) ||
             (PrevAtm1 -> ResSeq.L  != Atm1 -> ResSeq.L )) {
           PrevAtm1 = Atm1;
           ++PairID;
         }
       } else PrevAtm1 = Atm1;
       break;

      case NUC_RESTRFMT_VEGA:
        if (fprintf(FH, "SendVegaCmd \"Distance %u %u 3\" > NUL:\n", Atm1 -> Num, Atm2 -> Num) <= 0)
          throw 0;
     } /* End of switch */
    } /* End of for (Rest) */

    /**** Write the footer ****/

    if ((Format == NUC_RESTRFMT_VEGA) &&
        (fprintf(FH, "\n"
                     "echo * Done\n") <= 0))
      throw 0;

  } catch (...) {
    fclose(FH);
    NUC_Error(TRUE, "Can't write the restraint file");
  }
  fclose(FH);
}


/**** Scan the secondary structure ****/

HD_LONG HD_FASTCALL NUC_Build::RestrScan(const HD_CHAR *Str, HD_LONG Idx)
{
  while(Str[Idx]) {
    if (Str[Idx] == ')') return Idx;
    if (Str[Idx] == '(') {
      HD_LONG * ResPairsPtr = ResPairs + ResPairsNum;
      ResPairsNum += 2;
      ResPairsPtr[0] = Idx;
      Idx            = RestrScan(Str, Idx + 1);
      ResPairsPtr[1] = Idx;
    }
    ++Idx;
  } /* End of while */

  return 0;
}


/**** Save 3D structure ****/

HD_VOID HD_FASTCALL NUC_Build::Save3D(HDC_String &FileName)
{
  if (!VG_Saver(hVega, FileName.Cstr(), OutFormat3D, VG_PK_NONE, TRUE))
    NUC_Error(TRUE, "Can't save the 3D structure");
}


/**** Save OpenMM input file ****/

HD_VOID HD_FASTCALL NUC_Build::SaveOmm(HDC_String Prefix, HDC_String &PdbFileName, HD_LONG SaveFlags)
{
  /**** Load the template file if needed ****/

  if (OmmTemplate.IsEmpty()) {
    HDC_String TemplateFile;
    VG_StrGetPrgPath(TemplateFile, VG_PATH_DATA);
    TemplateFile += "NuClust" HD_DIRSEP "parameters.py";
    try {
      OmmTemplate.Load(TemplateFile);
    } catch (...) {
      NUC_Error(TRUE, "Can't load the OpenMM template file");
    }
  }

  HDC_String  OmmStr = OmmTemplate;

  OmmStr.SubstAll("{COMMONPART}", CommonFileName);
  OmmStr.SubstAll("{FILEPREFIX}", Prefix        );
  OmmStr.SubstAll("{PDBFILE}"   , PdbFileName   );

  /**** Save the OpenMM input file ****/

  HDC_String FileName = Prefix + ".py";
  OmmStr.Save(FileName);

  /**** Save the restraints ****/

  FileName = Prefix + "_restr.txt";
  RestrListSave(FileName.Cstr(), NUC_RESTRFMT_OMM);

  if (SaveFlags & NUC_SAVEFLG_VEGASCRIPT) {
    FileName.ChangeExt("cmd");
    RestrListSave(FileName.Cstr(), NUC_RESTRFMT_VEGA);
  }
}


/**** Save OpenMM common file ****/

HD_VOID HD_FASTCALL NUC_Build::SaveOmmCommon(HDC_String Prefix)
{
  CommonFileName  = Prefix;
  CommonFileName += "_com.py";

  VG_StrGetPrgPath(Prefix, VG_PATH_DATA);
  Prefix += "NuClust" HD_DIRSEP "common.py";

  if (!HD_FileCopyC(CommonFileName.Cstr(), Prefix.Cstr()))
    NUC_Error(TRUE, "Can't copy the common.py");

  CommonFileName.RemoveExt();
}


/**** Chech the secondary structure ****/

HD_LONG HD_FASTCALL NUC_Build::StructChk(HDC_String &Struct)
{
  HD_ULONG      NumOpen  = 0;
  HD_ULONG      NumClose = 0;

  /**** Check if the parenthesis are balanced ****/

  for(HD_CHAR *Ptr = Struct.Cstr(); *Ptr; ++Ptr) {
    if (*Ptr == '(') ++NumOpen;
    else if (*Ptr == ')') ++NumClose;
  } /* End of for (Ptr) */

  return (NumOpen == NumClose) ? NumOpen : -1;
}


