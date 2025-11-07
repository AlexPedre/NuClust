
/********************************************
****       NuClust - NUPACK class        ****
**** (c) 2022-2025 - Alessandro Pedretti ****
********************************************/


#ifdef WIN32
#  include <windows.h>
#else
#  include <sys/ioctl.h>
#  include <unistd.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <list>

#include <hdargs.h>
#include <hdrandom.h>
#include <math.h>

#ifdef __BORLANDC__
#  pragma hdrstop
#  pragma argsused
#endif

#include "globals.h"
#include "nupack.h"

/**** Constants ****/

#define  NUC_BUFSIZE          4096

/**** Macros ****/

#define  NUC_CLUSTPRINT_HDR(What, Label)    if (DistFlags & What) HdrStr += Label;


#define  NUC_CLUSTPRINT_VAL(What, Fmt, Val) if (DistFlags & What) printf(" " Fmt, Clust -> Center -> Val);

#define  NUC_CLUSTSAVE_HDR(What, Label)     if ((DistFlags & What) && (fprintf(FH, ";Center" Label) <= 0)) \
                                              throw 0;

#define  NUC_CLUSTSAVE_VAL(What, Val)       if (DistFlags & What) { \
                                              Data += ";"; \
                                              Data += Clust -> Center -> Val; \
                                            }

#define  NUC_KMEANS_CENT(What, Par)         if (DistFlags & What) \
                                              Center -> Par +=  pts[i] -> Par;

#define  NUC_KMEANS_DIST(What, Par)         if (DistFlags & What) { \
                                              Tmp = (HD_FLOAT)(Structure -> Par - Centroid -> Par);\
                                              Dist += Tmp * Tmp; \
                                            }

/**** Local variables ****/

static HD_LONG                DistFlags;


/**** Constructor ****/

HD_FASTCALL NUC_Nupack::NUC_Nupack()
{
  Centers                = NULL;
  CentersPtr             = NULL;
  Clusters               = NULL;
  Config.distance_method = KmeansDistance;
  Config.centroid_method = KmeansCentroid;
  Name                   = "UserSequence";
  Objects                = NULL;
}


/**** Destructor ****/

HD_FASTCALL NUC_Nupack::~NUC_Nupack(HD_VOID)
{
  std::list <NUC_MODEL *>::iterator Mod;
  for(Mod = StructList.begin(); Mod != StructList.end(); ++Mod)
    delete [] (*Mod) -> StructVal;

  if (Centers) {
    for(HD_ULONG k = 0; k < ClusterNum; ++k)
      delete [] Centers[k].StructVal;

    delete [] Centers;
  }
  delete [] CentersPtr;
  delete [] Clusters;
  delete [] Objects;
}


/**** Perform the clustering ****/

HD_VOID HD_FASTCALL NUC_Nupack::Cluster(HD_ULONG ClustNum, HD_ULONG ClustIterMax,
                                        HD_LONG ClustDistFlag, HD_DLONG Seed)
{
  HD_ULONG          k;

  Centers                = new NUC_MODEL [ClustNum];
  CentersPtr             = new NUC_MODEL * [ClustNum];
  Objects                = new NUC_MODEL * [StructList.size()];
  Config.num_objs        = (HD_SIZE)StructList.size();
  Config.k               = ClustNum;
  Config.max_iterations  = ClustIterMax;
  DistFlags              = ClustDistFlag;

  Config.objs            = (HD_VOID **)Objects;
  Config.centers         = (HD_VOID **)CentersPtr;
  Config.clusters        = new HD_LONG [Config.num_objs];

  std::list <NUC_MODEL *>::iterator Mod;
  NUC_MODEL ** ObjPtr = Objects;
  for(Mod = StructList.begin(); Mod != StructList.end(); ++Mod)
    *ObjPtr++ = *Mod;

  /**** Fill the cluster centers ****/

  HDC_Random Rnd(HD_RNDGEN_DEFAULT);
  Rnd.Init(Seed);

  HD_ULONG *  RndVect = new HD_ULONG [Config.num_objs];

  for(k = 0; k < Config.num_objs; k++)
    RndVect[k] = k;

  for(k = 0; k < Config.num_objs; k++) {
    HD_ULONG    Tmp = RndVect[k];
    HD_ULONG    Idx = Rnd.RandMaxI(Config.num_objs - 1);

    RndVect[k]  = RndVect[Idx];
    RndVect[Idx] = Tmp;
  } /* End of for (k) */

  for(k = 0; k < ClustNum; k++) {
    NUC_MODEL * CenterPtr = Centers + k;
    NUC_MODEL * ObjectPtr = Objects[RndVect[k]];

    CenterPtr -> BasePairs   = ObjectPtr -> BasePairs;
    CenterPtr -> Energy      = ObjectPtr -> Energy;
    CenterPtr -> Probability = ObjectPtr -> Probability;
    CenterPtr -> StructVal   = new HD_FLOAT [SeqLen];
//    CenterPtr -> StructVal   = new NUC_BASE [SeqLen];
    CenterPtr -> Struct.SetLen(SeqLen);

    for(HD_LONG j = 0; j < SeqLen; ++j)
      CenterPtr -> StructVal[j] = ObjectPtr -> StructVal[j];

    CentersPtr[k] = CenterPtr;
  } /* End of for (k) */

  delete [] RndVect;

  /**** Run the clustering ****/

  switch(kmeans(&Config)) {
  case KMEANS_EXCEEDED_MAX_ITERATIONS:
    NUC_Error(TRUE, "Maximum number of clustering iterations exceeded (%u)", Config.max_iterations);
    break;

  case KMEANS_ERROR:
    NUC_Error(TRUE, "Unable to complete the clustering");
    break;

  default:
    break;
  } /* End of switch */


  /**** Sort the structures by cluster ****/

  for(Mod = StructList.begin(), k = 0; Mod != StructList.end(); ++Mod, ++k)
    (*Mod) -> ClusterID = Config.clusters[k];

  StructList.sort(SortFunc);

  /**** Count the structures in each cluster ****/

  HD_ULONG *  StrNum = new HD_ULONG[ClustNum];
  HD_MemZero(StrNum, sizeof(HD_ULONG) * ClustNum);

  HD_ULONG    RealClustNum  = 0;
  HD_ULONG    PrevClusterID = (*StructList.begin()) -> ClusterID;
  for(Mod = StructList.begin(), k = 0; Mod != StructList.end(); ++Mod, ++k) {
    if ((*Mod) -> ClusterID != PrevClusterID) {
      PrevClusterID = (*Mod) -> ClusterID;
      ++RealClustNum;
    }
    (*Mod) -> ClusterID = RealClustNum;
    ++StrNum[Config.clusters[k]];
  } /* End of for (Mod) */
  ++RealClustNum;

  /**** Analyze the clusters ****/

  HD_ULONG j = 0;
  Clusters = new NUC_CLUSTER [RealClustNum];
  for(k = 0; k < ClustNum; ++k) {
    if (StrNum[k]) {
      NUC_CLUSTER * ClustPtr = Clusters + j;
      ClustPtr -> Center  = CentersPtr[k];
      ClustPtr -> Closest = NULL;
      ClustPtr -> ID      = j;
      ClustPtr -> Lowest  = NULL;
      ClustPtr -> Num     = StrNum[k];
      Float2Struct(CentersPtr[k]);
      ++j;
    }
  } /* End of for (k) */
  delete[] StrNum;

  /**** Search for the closest structure to the center ****/

  NUC_BASE *    CommonData = new NUC_BASE [SeqLen];
  NUC_CLUSTER * CurClust   = NULL;

  for(Mod = StructList.begin(), k = 0; Mod != StructList.end(); ++Mod, ++k) {
    NUC_BASE *  DataPtr = CommonData;

    if ((!CurClust) || ((*Mod) -> ClusterID != CurClust -> ID)) {
      if (CurClust) Prob2Struct(CurClust++, DataPtr);
      else CurClust = Clusters;

      (*Mod) -> Flags         |= NUC_DATAFLG_LOWENE|NUC_DATAFLG_CENTER;
      CurClust -> Closest      = *Mod;
      CurClust -> ClosestDist  = KmeansDistance((HD_POINTER)*Mod, (HD_POINTER)CentersPtr[(*Mod) -> ClusterID]);
      CurClust -> Lowest       = *Mod;

      /**** Common substructure ****/

      for(HD_CHAR *Ptr = (*Mod) -> Struct.Cstr(); *Ptr; ++Ptr) {
        if (*Ptr == '(') {
          DataPtr -> NumClose = 0;
          DataPtr -> NumDot   = 0;
          DataPtr -> NumOpen  = 1;
        } else if (*Ptr == ')') {
          DataPtr -> NumClose = 1;
          DataPtr -> NumDot   = 0;
          DataPtr -> NumOpen  = 0;
        } else {
          DataPtr -> NumClose = 0;
          DataPtr -> NumDot   = 1;
          DataPtr -> NumOpen  = 0;
        }
        ++DataPtr;
      } /* End of for (Ptr) */
    } else {
      HD_FLOAT TmpDist = KmeansDistance((HD_POINTER)*Mod, (HD_POINTER)CentersPtr[(*Mod) -> ClusterID]);
      if (TmpDist < CurClust -> ClosestDist) {
        CurClust -> Closest -> Flags &= ~NUC_DATAFLG_CENTER;
        CurClust -> Closest           = *Mod;
        CurClust -> ClosestDist       = TmpDist;
        CurClust -> Closest -> Flags |= NUC_DATAFLG_CENTER;
      }

      /**** Common substructure ****/

      for(HD_CHAR *Ptr = (*Mod) -> Struct.Cstr(); *Ptr; ++Ptr) {
        if (*Ptr == '(') ++DataPtr -> NumOpen;
        else if (*Ptr == ')') ++DataPtr -> NumClose;
             else ++DataPtr -> NumDot;
        ++DataPtr;
      } /* End of for (Ptr) */
    }
  } /* End of for (Mod) */

  Prob2Struct(CurClust, CommonData);

  for(k = 0; k < RealClustNum; ++k)
    Clusters[k].ClosestDist = sqrt(Clusters[k].ClosestDist);

  delete [] CommonData;

  ClusterNum = RealClustNum;
}


/**** Print the clusters ****/

HD_VOID HD_FASTCALL NUC_Nupack::ClusterPrint(HD_VOID)
{
  HD_ULONG        Cols, k;

  HDC_String      HdrStr = " ID     Nstr";

  /**** Print the header ****/

  NUC_CLUSTPRINT_HDR(NUC_DIST_ENERGY     , "  Energy "  );
  NUC_CLUSTPRINT_HDR(NUC_DIST_APTAMAT    , "  AptaMat"  );
  NUC_CLUSTPRINT_HDR(NUC_DIST_BP         , "    Bp   "  );
  NUC_CLUSTPRINT_HDR(NUC_DIST_DISTANCE   , "  MfeDist"  );
  NUC_CLUSTPRINT_HDR(NUC_DIST_PROBABILITY, "  Probab."  );
//  NUC_CLUSTPRINT_HDR(NUC_DIST_STRUCTURE  , "  Structure");
  NUC_CLUSTPRINT_HDR(NUC_DIST_ALL        , "  Common substructure");


#ifdef WIN32
  CONSOLE_SCREEN_BUFFER_INFO    Csbi;

  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Csbi);
    Cols = Csbi.srWindow.Right - Csbi.srWindow.Left - 2;
#else
  struct winsize                WinSize;

  ioctl(STDOUT_FILENO, TIOCGWINSZ, &WinSize);
  Cols = WinSize.ws_col - 3;
#endif

  HD_ULONG Len = HdrStr.Len();
  if (Len < Cols) Len = Cols;
  printf("\n  %s\n  ", HdrStr.Cstr());
  for(k = 0; k < Len; ++k) printf("=");
  printf("\n");


  for(k = 0; k < ClusterNum; ++k) {
    NUC_CLUSTER *   Clust = Clusters + k;

    printf("   %-4u   %-4u", k + 1, Clust -> Num);

    NUC_CLUSTPRINT_VAL(NUC_DIST_ENERGY     , "%8.3f", Energy       );
    NUC_CLUSTPRINT_VAL(NUC_DIST_APTAMAT    , "%8.3f", AptaMat      );
    NUC_CLUSTPRINT_VAL(NUC_DIST_BP         , "%8.3f", BasePairs    );
    NUC_CLUSTPRINT_VAL(NUC_DIST_DISTANCE   , "%8.3f", MfeDist      );
    NUC_CLUSTPRINT_VAL(NUC_DIST_PROBABILITY, "%8.2e", Probability  );
  //  NUC_CLUSTPRINT_VAL(NUC_DIST_STRUCTURE  , " %s"  , Struct.Cstr());
    printf("  %s\n", Clust -> ComStruct.Cstr());
  } /* End of for (k) */

  printf("\n");
}


/**** Save the clusters ****/

HD_VOID HD_FASTCALL NUC_Nupack::ClusterSave(const HD_CHAR *FileName, HD_BOOL FixDec)
{
  FILE *        FH;

  if ((FH = fopen(FileName, "w")) == NULL)
    NUC_Error(TRUE, "Can't create the output file");

  HDC_String    Data;

  try {

    /**** Header ****/

    if (fprintf(FH, "StructID;ClusterID;ClosestToCenter;"
                    "Energy;LowEne;AptaMat;Bp;MfeDist;Probability;Structure\n") <= 0)
      throw 0;

    /**** Rows ****/

    std::list <NUC_MODEL *>::iterator Mod;
    for(Mod = StructList.begin(); Mod != StructList.end(); ++Mod) {
      NUC_MODEL *   ModPtr = *Mod;
      Data.Print("%u;%u;%d;"
                 "%.3f;%d;%.2f;%.0f;%.2f;%.6f",
                 ModPtr -> ID, ModPtr -> ClusterID + 1, (ModPtr -> Flags & NUC_DATAFLG_CENTER) != 0,
                 ModPtr -> Energy, (ModPtr -> Flags & NUC_DATAFLG_LOWENE) != 0,
                 ModPtr -> AptaMat, ModPtr -> BasePairs, ModPtr -> MfeDist, ModPtr -> Probability);
      if (FixDec) Data.FixDecSep();
      if (fprintf(FH, "%s;%s\n", Data.Cstr(), ModPtr -> Struct.Cstr()) <= 0)
        throw 0;
    } /* End of for (Mod) */
  } catch (...) {
    fclose(FH);
    NUC_Error(TRUE, "Can't write the output file");
  }
  fclose(FH);

  HDC_String File = FileName;
  File.ChangeExt((const HD_CHAR *)NULL);
  File += "_clust.csv";

  if ((FH = fopen(File.Cstr(), "w")) == NULL)
    NUC_Error(TRUE, "Can't create the output file");

  try {

    /**** Header ****/

    if (fprintf(FH, "ClusterID;StructNum;"
                    "ClosestID;ClosestEne;ClosestAptaMat;ClosestBp;ClosestMfeDist;ClosestProb;ClosestDistFromCenter;"
                    "LowestID;LowestEne;LowestAptaMat;LowestBp;LowestMfeDist;LowestProb") <= 0)
      throw 0;

    NUC_CLUSTSAVE_HDR(NUC_DIST_ENERGY     , "Ene"    )
    NUC_CLUSTSAVE_HDR(NUC_DIST_APTAMAT    , "AptaMat")
    NUC_CLUSTSAVE_HDR(NUC_DIST_BP         , "Bp"     )
    NUC_CLUSTSAVE_HDR(NUC_DIST_DISTANCE   , "MfeDist")
    NUC_CLUSTSAVE_HDR(NUC_DIST_PROBABILITY, "Prob")
    NUC_CLUSTSAVE_HDR(NUC_DIST_STRUCTURE  , "Struct" )

    if (fprintf(FH, ";CommonSubstruct\n") <= 0) throw 0;

    /**** Rows ****/

    NUC_CLUSTER * Clust = Clusters;
    for(HD_ULONG k = 0; k < ClusterNum; ++k) {
      Data.Print("%u;%u;"
                 "%u;%.3f;%.2f;%.0f;%.0f;%f;%f;"
                 "%u;%.3f;%.2f;%.0f;%.0f;%f",
                 Clust -> ID + 1, Clust -> Num,
                 Clust -> Closest -> ID,  Clust -> Closest -> Energy,  Clust -> Closest -> AptaMat, Clust -> Closest -> BasePairs,
                 Clust -> Closest -> MfeDist, Clust -> Closest -> Probability, Clust -> ClosestDist,
                 Clust -> Lowest -> ID, Clust -> Lowest -> Energy, Clust -> Lowest -> AptaMat, Clust -> Lowest -> BasePairs,
                 Clust -> Lowest -> MfeDist, Clust -> Lowest -> Probability);

      NUC_CLUSTSAVE_VAL(NUC_DIST_ENERGY     , Energy     )
      NUC_CLUSTSAVE_VAL(NUC_DIST_APTAMAT    , AptaMat    )
      NUC_CLUSTSAVE_VAL(NUC_DIST_BP         , BasePairs  )
      NUC_CLUSTSAVE_VAL(NUC_DIST_DISTANCE   , MfeDist    )
      NUC_CLUSTSAVE_VAL(NUC_DIST_PROBABILITY, Probability)

      if (FixDec) Data.FixDecSep();

      if ((fprintf(FH, "%s", Data.Cstr()) <= 0) ||
          ((DistFlags & NUC_DIST_STRUCTURE) &&
           (fprintf(FH, ";%s", Clust -> Center -> Struct.Cstr()) <= 0)) ||
          (fprintf(FH, ";%s\n", Clust -> ComStruct.Cstr()) <= 0))
        throw 0;

      ++Clust;
    } /* End of for (k) */
  } catch (...) {
    fclose(FH);
    NUC_Error(TRUE, "Can't write the cluster file");
  }
  fclose(FH);

}


/**** Get the common substructure ****/

HD_VOID HD_FASTCALL NUC_Nupack::GetComStruct(HDC_String &ComStruct, HDC_String &Struct)
{
  HD_CHAR *     PtrCom = ComStruct.Cstr();
  HD_CHAR *     Ptr    = Struct.Cstr();

  while(*Ptr) {
    if (*Ptr != *PtrCom) *PtrCom = '.';
    ++Ptr;
    ++PtrCom;
  } /* End of while (Ptr) */
}


/**** Convert the structure to a float vector ****/

HD_VOID HD_FASTCALL NUC_Nupack::Float2Struct(NUC_MODEL *Mod)
{
#if 1
  HD_FLOAT *    StructValPtr =  Mod -> StructVal;

  for(HD_CHAR *Ptr = Mod -> Struct.Cstr(); *Ptr; ++Ptr) {
    *Ptr = *StructValPtr > 0.5f ? '|' : '.';
    ++StructValPtr;
  } /* End of for (Ptr) */
#else
  NUC_BASE *   StructValPtr =  Mod -> StructVal;

  for(HD_CHAR *Ptr = Mod -> Struct.Cstr(); *Ptr; ++Ptr) {

    if (StructValPtr -> Close > StructValPtr -> Open) {
      if (StructValPtr -> Close > StructValPtr -> Dot) *Ptr = ')';
      else *Ptr = '.';
    } else {
      if (StructValPtr -> Open > StructValPtr -> Dot) *Ptr = '(';
      else *Ptr = '.';
    }

    ++StructValPtr;
  } /* End of for (Ptr) */
#endif
}


/**** Calculate the centroid for K-means ****/

HD_VOID NUC_Nupack::KmeansCentroid(const HD_POINTER *objs, const HD_LONG *clusters,
                                   HD_SIZE num_objs, HD_LONG cluster, HD_POINTER centroid)
{
  HD_SIZE         i;

  HD_LONG         num_cluster  = 0;
  NUC_MODEL *     Center       = (NUC_MODEL *)centroid;

  if (num_objs <= 0) return;

  for(i = 0; i < num_objs; i++) {
    if (clusters[i] != cluster) continue;
    num_cluster++;
  } /* End of for (i) */

  if (!num_cluster) return;

  HD_LONG         k;

  HD_FLOAT        D            = (HD_FLOAT)num_cluster;
  HD_LONG         Len          = Center -> Struct.Len();
  NUC_MODEL **    pts          = (NUC_MODEL **)objs;

  Center -> AptaMat     = 0.0f;
  Center -> BasePairs   = 0.0f;
  Center -> Energy      = 0.0f;
  Center -> MfeDist     = 0.0f;
  Center -> Probability = 0.0f;

  HD_CHAR *   Ptr1 = Center -> Struct.Cstr();
  HD_CHAR *   Ptr2 = pts[0] -> Struct.Cstr();
  for(k = 0; k < Len; ++k) Ptr1[k] = Ptr2[k];

  for(i = 0; i < num_objs; i++) {
    if (clusters[i] != cluster) continue;

    NUC_KMEANS_CENT(NUC_DIST_APTAMAT    , AptaMat    );
    NUC_KMEANS_CENT(NUC_DIST_BP         , BasePairs  );
    NUC_KMEANS_CENT(NUC_DIST_DISTANCE   , MfeDist    );
    NUC_KMEANS_CENT(NUC_DIST_ENERGY     , Energy     );
    NUC_KMEANS_CENT(NUC_DIST_PROBABILITY, Probability);

    if (DistFlags & NUC_DIST_STRUCTURE) {
#if 1
      for(k = 0; k < Len; ++k)
        Center -> StructVal[k] += pts[i] -> StructVal[k];
#else
      for(k = 0; k < Len; ++k) {
        Center -> StructVal[k].Close += pts[i] -> StructVal[k].Close;
        Center -> StructVal[k].Dot   += pts[i] -> StructVal[k].Dot;
        Center -> StructVal[k].Open  += pts[i] -> StructVal[k].Open;
      } /* End of for (k) */
#endif
    }
  } /* End of for (i) */

  Center -> AptaMat     /= D;
  Center -> BasePairs   /= D;
  Center -> Energy      /= D;
  Center -> MfeDist     /= D;
  Center -> Probability /= D;

  if (DistFlags & NUC_DIST_STRUCTURE) {
#if 1
    for(k = 0; k < Len; ++k)
      Center -> StructVal[k] /= D;
#else
    for(k = 0; k < Len; ++k) {
      Center -> StructVal[k].Close /= D;
      Center -> StructVal[k].Dot   /= D;
      Center -> StructVal[k].Open  /= D;
    } /* End of for (k) */
#endif
  }
}


/**** Calculate the distance of a structure from the centroid for K-means ****/

HD_FLOAT NUC_Nupack::KmeansDistance(const HD_POINTER A, const HD_POINTER C)
{
  HD_FLOAT        Tmp;

  NUC_MODEL *     Structure = (NUC_MODEL *)A;
  NUC_MODEL *     Centroid  = (NUC_MODEL *)C;
  HD_FLOAT        Dist      = 0.0f;

  NUC_KMEANS_DIST(NUC_DIST_APTAMAT    , AptaMat    );
  NUC_KMEANS_DIST(NUC_DIST_BP         , BasePairs  );
  NUC_KMEANS_DIST(NUC_DIST_DISTANCE   , MfeDist    );
  NUC_KMEANS_DIST(NUC_DIST_ENERGY     , Energy     );
  NUC_KMEANS_DIST(NUC_DIST_PROBABILITY, Probability);

  /**** Calculate the similarity of the structure ****/

  if (DistFlags & NUC_DIST_STRUCTURE) {
#if 0
    HD_CHAR *   Ptr1 = Structure -> Struct.Cstr();
    HD_CHAR *   Ptr2 = Centroid  -> Struct.Cstr();
    HD_LONG     Len  = Structure -> Struct.Len();
    HD_LONG     Dis  = 0;


    for(HD_LONG k = 0; k < Len; ++k)
      if (Ptr1[k] != Ptr2[k]) ++Dis;

    Dist += (HD_FLOAT)Dis / (HD_FLOAT)Len;
#endif

    HD_LONG     Len = Structure -> Struct.Len();
    HD_LONG     M11 = 0;
    HD_LONG     M01 = 0;

    for(HD_LONG k = 0; k < Len; ++k) {
      HD_BOOL Val1 = Structure -> StructVal[k] > 0.5f;
      HD_BOOL Val2 = Centroid  -> StructVal[k] > 0.5f;

      if (Val1 == Val2) {
        if (Val1) ++M11;
      } else ++M01;
    } /* End of while */

    Dist += ((HD_FLOAT)(M01) / (HD_FLOAT)(M01 + M11));
  }

  return Dist;
}

/**** Load the NUPACK output ****/

HD_VOID HD_FASTCALL NUC_Nupack::Load(const HD_CHAR *FileName, HD_ULONG TopNum)
{
  FILE *          FH;
  HD_CHAR         Buf[NUC_BUFSIZE];
  HD_LONG         Format = NUC_FORMAT_UNK;


  if ((FH = fopen(FileName, "r")) == NULL)
    NUC_Error(TRUE, "File not found");

  while(fgets(Buf, NUC_BUFSIZE, FH)) {
    if (!strncmp(Buf,  "MFE proxy structure", 19)) {
      Format = NUC_FORMAT_TXT;
      break;
    } else if (!strncmp(Buf,  ",Suboptimal proxy structure,", 28)) {
      Format = NUC_FORMAT_CSV;
      break;
    }
  } /* End of while */

  fseek(FH, 0, SEEK_SET);
  if (StructList.size()) StructList.clear();

  switch(Format) {
  case NUC_FORMAT_CSV:
    if (Sequence.IsEmpty()) {
      fclose(FH);
      NUC_Error(TRUE, "The CSV formnat require the sequence (-s option)");
    }
    LoadCsv(FH);

    if (SeqLen != Sequence.Len())
      NUC_Error(TRUE, "Input file not compatible with the sequence length");
    break;

  case NUC_FORMAT_TXT:
    LoadTxt(FH);
    break;

  default:
    fclose(FH);
    NUC_Error(TRUE, "Unknown file format");
  } /* End of switch */

  if (!StructList.size())
    NUC_Error(TRUE, "No suboptimal structure found");

  if ((!TopNum) || (TopNum > StructList.size()))
    BestNum = StructList.size();
  else
    BestNum = TopNum;

  /**** Search for the common substructure *****/

  std::list <NUC_MODEL *>::iterator Mod;
  for(Mod = StructList.begin(); Mod != StructList.end(); ++Mod) {
    NUC_MODEL * ModPtr = *Mod;
    if (ModPtr -> ID > BestNum) break;
    if (ModPtr -> ID == 1) {
      Mfe       = ModPtr;
      ComStruct = ModPtr -> Struct;
    } else GetComStruct(ComStruct, ModPtr -> Struct);
  } /* End of for (Mod) */

  /**** Calculate the statistics ****/

  Stat(&StatBest, BestNum);
  Stat(&StatTot, StructList.size());
}


/**** Load csv format ****/

HD_VOID HD_FASTCALL NUC_Nupack::LoadCsv(FILE *FH)
{
  HD_CHAR     Buf[NUC_BUFSIZE];
  HDC_Args    Arg;

  HD_ULONG    Loaded = 0;

  /**** Skip the header ****/

  try {
    if (!fgets(Buf, NUC_BUFSIZE, FH)) throw 0;

    while(fgets(Buf, NUC_BUFSIZE, FH)) {
      if (Arg.Parse(Buf, ",\n\r") >= 7) {
        NUC_MODEL * Mod = new NUC_MODEL;

        Mod -> ClusterID   = 0;
        Mod -> Flags       = Loaded ? NUC_DATAFLG_NONE : NUC_DATAFLG_MFE;
        Mod -> ID          = ++Loaded;
        Mod -> Struct      = Arg.GetChar(1);
        Mod -> BasePairs   = Arg.GetFloat(2);
        Mod -> Energy      = Arg.GetFloat(3);
        Mod -> MfeDist     = Arg.GetFloat(4);
        Mod -> AptaMat     = Arg.GetFloat(5);
        Mod -> Probability = Arg.GetFloat(6);

        if (Loaded == 1) SeqLen = Mod -> Struct.Len();
        Struct2Float(Mod);
        StructList.push_back(Mod);
      }
    } /* End of while */
  } catch (...) {
    fclose(FH);
    NUC_Error(TRUE, "Can't read the file");
  }

  fclose(FH);
}


/**** Load txt format ****/

HD_VOID HD_FASTCALL NUC_Nupack::LoadTxt(FILE *FH)
{
  HD_CHAR           Buf[NUC_BUFSIZE];
  HDC_Args          Arg, Tag;

  const HD_CHAR *   ErrMsg = "Can't read the file";
  HD_ULONG          Loaded = 0;

  /**** Read the first line ****/

  if (!fgets(Buf, NUC_BUFSIZE, FH)) {
    fclose(FH);
    NUC_Error(TRUE, ErrMsg);
  }

  Tag.Parse(Buf, ":\n\r");

  SetName(Tag.GetChar(0));
  SetSequence(Tag.GetChar(1));

  /**** Check the nucleic acid type ****/

  for(HD_CHAR *Ptr = Sequence.Cstr(); *Ptr; ++Ptr) {
    if ((*Ptr != 'A') && (*Ptr != 'T') &&
        (*Ptr != 'C') && (*Ptr != 'G') && (*Ptr != 'U')) {
      fclose(FH);
      NUC_Error(TRUE, "Invalid sequence in NUPACK file");
    }
    if (*Ptr == 'U') Type = NUC_TYPE_RNA;
  } /* End of for (Ptr) */

  try {
    while(fgets(Buf, NUC_BUFSIZE, FH)) {
      if ((Tag.Parse(Buf, ":") > 1) &&
          (!strncasecmp(Tag.GetChar(0), "Suboptimal", 10))) {
        Arg.Parse(Tag.GetChar(1), " ,=\n\r");
        NUC_MODEL * Mod = new NUC_MODEL;

        Mod -> ClusterID   = 0;
        Mod -> Flags       = Loaded ? NUC_DATAFLG_NONE : NUC_DATAFLG_MFE;
        Mod -> ID          = ++Loaded;
        Mod -> Struct      = Arg.GetChar(0);
        Mod -> BasePairs   = Arg.GetFloat(2);
        Mod -> Energy      = Arg.GetFloat(4);
        Mod -> MfeDist     = Arg.GetFloat(7);
        Mod -> AptaMat     = Arg.GetFloat(9);
        Mod -> Probability = Arg.GetFloat(11);

        Struct2Float(Mod);
        StructList.push_back(Mod);
      }
    } /* End of while */


  } catch (...) {
    fclose(FH);
    NUC_Error(TRUE, ErrMsg);
  }

  fclose(FH);
}


/**** Convert open/close/dot probabilities to string ****/

HD_VOID HD_FASTCALL NUC_Nupack::Prob2Struct(NUC_CLUSTER *Clust, NUC_BASE *DataPtr)
{
  HD_CHAR *     Ptr;
  HD_LONG       Candidate, j, k;

  HD_LONG       Bal = 0;

  if (Clust -> ID == 15)
    Bal = Bal;

  Clust -> ComStruct.SetLen(SeqLen);
  Ptr = Clust -> ComStruct.Cstr();

  for(k = 0; k < SeqLen; ++k) {
    Ptr[k] = '.';
    if (DataPtr[k].NumOpen > DataPtr[k].NumClose) {
      if (DataPtr[k].NumOpen > DataPtr[k].NumDot) {
        Ptr[k] = '(';
        ++Bal;
      }
    } else {
      if (DataPtr[k].NumClose > DataPtr[k].NumDot) {
        Ptr[k] = ')';
        if (--Bal < 0) {

          /**** Too many closed parenthesis ****/

          Candidate = k;
          for(j = k - 1; j; --j) {
            if ((Ptr[j] == ')') && (DataPtr[j].NumClose < DataPtr[Candidate].NumClose))
              Candidate = j;
          } /* End of for (j) */
          Ptr[Candidate] = '.';
          Bal = 0;
        }
      }
    }
  } /* End of for (k) */

  /**** Too many open parenthesis ****/

  if (Bal != 0) {
    Candidate = -1;
    for(j = SeqLen; j; --j) {
      if (Ptr[j] == '(') {
        if (Candidate == -1) Candidate = j;
        else if (DataPtr[j].NumOpen < DataPtr[Candidate].NumOpen)
          Candidate = j;
        ++Bal;
      } else if (Ptr[j] == ')') --Bal;
      if (Bal == 0) Candidate = -1;
    } /* End of for (j) */

    if (Candidate >= 0) Ptr[Candidate] = '.';
  }

  /**** Check the parenthesis ****/

  Bal = 0;
  for(k = 0; k < SeqLen; ++k) {
    if (Ptr[k] == '(') ++Bal;
    else if (Ptr[k] == ')') --Bal;

    if (Bal < 0) {
      Ptr[k] = '.';
      Bal = 0;
    }
  }
  if (Bal) {
    Bal = 0;
    for(k = SeqLen - 1; k >= 0; --k) {
      if (Ptr[k] == ')') ++Bal;
      else if (Ptr[k] == '(') --Bal;

      if (Bal < 0) {
        Ptr[k] = '.';
        Bal = 0;
      }
    } /* End of for (k) */
  }
}


/**** Sort callback function ****/

bool NUC_Nupack::SortFunc(NUC_MODEL *Mod1, NUC_MODEL *Mod2)
{
  if (Mod1 -> ClusterID < Mod2 -> ClusterID) return true;

  return (Mod1 -> Energy < Mod1 -> Energy);
}


/**** Calculate the statistics ****/

HD_VOID HD_FASTCALL NUC_Nupack::Stat(NUC_STAT *Res, HD_ULONG Num)
{
  HD_MemZero(Res, sizeof(NUC_DATA));
  Res -> Num = Num;

  std::list <NUC_MODEL *>::iterator Mod;
  for(Mod = StructList.begin(); Mod != StructList.end(); ++Mod) {
    NUC_MODEL *ModPtr = *Mod;

    /**** Sum ****/

    Res -> Sum.AptaMat     += ModPtr -> AptaMat;
    Res -> Sum.BasePairs   += ModPtr -> BasePairs;
    Res -> Sum.Energy      += ModPtr -> Energy;
    Res -> Sum.MfeDist     += ModPtr -> MfeDist;
    Res -> Sum.Probability += ModPtr -> Probability;

    /**** Square sum ****/

    Res -> Sum2.AptaMat     += ModPtr -> AptaMat     * ModPtr -> AptaMat;
    Res -> Sum2.BasePairs   += ModPtr -> BasePairs   * ModPtr -> BasePairs;
    Res -> Sum2.Energy      += ModPtr -> Energy      * ModPtr -> Energy;
    Res -> Sum2.MfeDist     += ModPtr -> MfeDist     * ModPtr -> MfeDist;
    Res -> Sum2.Probability += ModPtr -> Probability * ModPtr -> Probability;

    /**** Min/max value ****/

    if (Num == Res -> Num) {
      Res -> Max.AptaMat     = ModPtr -> AptaMat;
      Res -> Max.BasePairs   = ModPtr -> BasePairs;
      Res -> Max.Energy      = ModPtr -> Energy;
      Res -> Max.MfeDist     = ModPtr -> MfeDist;
      Res -> Max.Probability = ModPtr -> Probability;

      Res -> Min.AptaMat     = ModPtr -> AptaMat;
      Res -> Min.BasePairs   = ModPtr -> BasePairs;
      Res -> Min.Energy      = ModPtr -> Energy;
      Res -> Min.MfeDist     = ModPtr -> MfeDist;
      Res -> Min.Probability = ModPtr -> Probability;
    } else {
      if (ModPtr -> AptaMat     > Res -> Max.AptaMat    ) Res -> Max.AptaMat     = ModPtr -> AptaMat;
      if (ModPtr -> BasePairs   > Res -> Max.BasePairs  ) Res -> Max.BasePairs   = ModPtr -> BasePairs;
      if (ModPtr -> Energy      > Res -> Max.Energy     ) Res -> Max.Energy      = ModPtr -> Energy;
      if (ModPtr -> MfeDist     > Res -> Max.MfeDist    ) Res -> Max.MfeDist     = ModPtr -> MfeDist;
      if (ModPtr -> Probability > Res -> Max.Probability) Res -> Max.Probability = ModPtr -> Probability;

      if (ModPtr -> AptaMat     < Res -> Min.AptaMat    ) Res -> Min.AptaMat     = ModPtr -> AptaMat;
      if (ModPtr -> BasePairs   < Res -> Min.BasePairs  ) Res -> Min.BasePairs   = ModPtr -> BasePairs;
      if (ModPtr -> Energy      < Res -> Min.Energy     ) Res -> Min.Energy      = ModPtr -> Energy;
      if (ModPtr -> MfeDist     < Res -> Min.MfeDist    ) Res -> Min.MfeDist     = ModPtr -> MfeDist;
      if (ModPtr -> Probability < Res -> Min.Probability) Res -> Min.Probability = ModPtr -> Probability;
    }

    if (--Num == 0) break;
  } /* End of for (Mod) */

  if (Res -> Num == 1) {

    /**** Mean ****/

    Res -> Mean.AptaMat     = Res -> Sum.AptaMat;
    Res -> Mean.BasePairs   = Res -> Sum.BasePairs;
    Res -> Mean.Energy      = Res -> Sum.Energy;
    Res -> Mean.MfeDist     = Res -> Sum.MfeDist;
    Res -> Mean.Probability = Res -> Sum.Probability;

    /**** Standard deviation ****/

    Res -> StdDev.AptaMat     = 0.0f;
    Res -> StdDev.BasePairs   = 0.0f;
    Res -> StdDev.Energy      = 0.0f;
    Res -> StdDev.MfeDist     = 0.0f;
    Res -> StdDev.Probability = 0.0f;
  } else {
    HD_FLOAT NumF = (HD_FLOAT)Res -> Num;

    /**** Mean ****/

    Res -> Mean.AptaMat     = Res -> Sum.AptaMat     / NumF;
    Res -> Mean.BasePairs   = Res -> Sum.BasePairs   / NumF;
    Res -> Mean.Energy      = Res -> Sum.Energy      / NumF;
    Res -> Mean.MfeDist     = Res -> Sum.MfeDist     / NumF;
    Res -> Mean.Probability = Res -> Sum.Probability / NumF;

    /**** Standard deviation ****/

    Res -> StdDev.AptaMat     = sqrt(NumF * Res -> Sum2.AptaMat     - Res -> Sum.AptaMat     * Res -> Sum.AptaMat    ) / NumF;
    Res -> StdDev.BasePairs   = sqrt(NumF * Res -> Sum2.BasePairs   - Res -> Sum.BasePairs   * Res -> Sum.BasePairs  ) / NumF;
    Res -> StdDev.Energy      = sqrt(NumF * Res -> Sum2.Energy      - Res -> Sum.Energy      * Res -> Sum.Energy     ) / NumF;
    Res -> StdDev.MfeDist     = sqrt(NumF * Res -> Sum2.MfeDist     - Res -> Sum.MfeDist     * Res -> Sum.MfeDist    ) / NumF;
    Res -> StdDev.Probability = sqrt(NumF * Res -> Sum2.Probability - Res -> Sum.Probability * Res -> Sum.Probability) / NumF;
  }
}


/**** Set the sequence ****/

HD_VOID HD_FASTCALL NUC_Nupack::SetName(const HD_CHAR *NameStr)
{
  Name = NameStr;

  Name.Trim();
  Name.ReplaceChar(' ', '_');
  Name.Lower();
}


/**** Set the sequence ****/

HD_VOID HD_FASTCALL NUC_Nupack::SetSequence(const HD_CHAR *SeqStr)
{
  Sequence = SeqStr;
  Type     = NUC_TYPE_DNA;
  Sequence.Trim();
  Sequence.Upper();
  SeqLen = Sequence.Len();

  /**** Check the nucleic acid type ****/

  for(HD_CHAR *Ptr = Sequence.Cstr(); *Ptr; ++Ptr) {
    if ((*Ptr != 'A') && (*Ptr != 'T') &&
        (*Ptr != 'C') && (*Ptr != 'G') && (*Ptr != 'U')) {
      NUC_Error(TRUE, "Invalid sequence");
    }
    if (*Ptr == 'U') Type = NUC_TYPE_RNA;
  } /* End of for (Ptr) */
}


/**** Convert the structure to a float vector ****/

HD_VOID HD_FASTCALL NUC_Nupack::Struct2Float(NUC_MODEL *Mod)
{
  HD_FLOAT *    StructValPtr =  new HD_FLOAT [Mod -> Struct.Len()];
  Mod -> StructVal = StructValPtr;

  for(HD_CHAR *Ptr = Mod -> Struct.Cstr(); *Ptr; ++Ptr) {
    *StructValPtr++ = (*Ptr == '(') || (*Ptr == ')') ? 1.0f : 0.0f;
  } /* End of for (Ptr) */
}

