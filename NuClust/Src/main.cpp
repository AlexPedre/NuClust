
/********************************************
****         NuClust - Main code         ****
**** (c) 2022-2025 - Alessandro Pedretti ****
********************************************/


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <hyperdrive.h>
#include <hdargs.h>
#include <hdatdl.h>
#include <hdatom.h>
#include <hddir.h>
#include <hdlist.h>
#include <hdmath.h>
#include <hdrandom.h>
#include <hdstring.h>
#include <signal.h>

#include <vgbase.h>
#include <vgdna.h>
#include <vghdstrutils.h>

#ifdef __BORLANDC__
#  pragma hdrstop
#  pragma argsused
#endif

#include "getopt.h"
#include "globals.h"
#include "build.h"
#include "nupack.h"
#include "version.h"


/**** Local variables ****/

static NUC_SIGNALHANDLER    SignaHandlerInt;

/**** Local prototypes ****/

static HD_VOID              SignalHandler(HD_LONG Signal);


/**** Main code ****/

int main(int argc, char *argv[])
{
  const HD_CHAR *         ArgPtr;
  const HD_CHAR **        DistStr;
  HD_LONG                 i;
  HDC_String              OutClustFile;

  HD_BOOL                 FixDec           = FALSE;
  const HD_CHAR *         ArgStr           = "b:c:d:fhk:n:r:s:t:v";
  const HD_CHAR *         Sequence         = NULL;
  const HD_CHAR *         SeqName          = NULL;
  HD_DLONG                Seed             = HD_GetTickCount();
  HD_LONG                 Build            = NUC_BUILD_NONE;
  HD_LONG                 ClustDistFlag    = NUC_DIST_DEFAULT;
  HD_LONG                 RetCode          = EXIT_FAILURE;
  HD_LONG                 SaveFlags        = NUC_SAVEFLG_NONE;
  HD_ULONG                BestNum          = 10;
  HD_ULONG                ClustIterMax     = 1000;
  HD_ULONG                ClustNum         = 20;
  NUC_Build *             Builder          = NULL;
  NUC_Nupack *            Nupack           = NULL;

  const HD_CHAR *         BuildList[]      = {"CLOSEST", "LOWEST", "MFE", "SHARED", /* Don't change the order */
                                              NULL };


  const HD_CHAR *         ClustDistList[]  = {"APTAMAT", "BP"         , "DISTANCE", /* Don't change the order */
                                              "ENERGY" , "PROBABILITY", "STRUCTURE",
                                              NULL };

  /**** Set the signal handler ****/

  signal(SIGFPE , SignalHandler);
  signal(SIGILL , SignalHandler);
  signal(SIGSEGV, SignalHandler);
  SignaHandlerInt = signal(SIGINT , SignalHandler);

  try {

    /**** Show how to use the program ****/

    if (argc == 1) throw 1;

    /**** Decode the parameters ****/

    opterr = 0;
    while ((i = getopt(argc, argv, ArgStr)) != EOF) {
      switch(i) {
      case 'b':   /* Build the 3D structures */
        {
          HDC_Args    Arg;
          if (!Arg.Parse(optarg))
            NUC_Error(TRUE, "Misssing what to build");

          for(HD_LONG k = 0; k < Arg.Count(); ++k) {
            HD_LONG j;
            for(j = 0; (BuildList[j]) && strcasecmp(Arg.GetChar(k), BuildList[j]); ++j);
            if (!BuildList[j])
               NUC_Error(TRUE, "Unknown build parameter %s", Arg.GetChar(k));

            Build |= 1 << j;
          } /* End of for (k) */
        }
        break;

      case 'c':   /* Set the output file */
        OutClustFile = optarg;
        OutClustFile.ChangeExt("csv");
        break;

      case 'd':   /* Distance function */
        {
          HDC_Args    Arg;
          if (!Arg.Parse(optarg))
            NUC_Error(TRUE, "Invalid number of distance parameters");

          ClustDistFlag = NUC_DIST_NONE;
          for(HD_LONG k = 0; k < Arg.Count(); ++k) {
            HD_LONG j;
            for(j = 0; (ClustDistList[j]) && strcasecmp(Arg.GetChar(k), ClustDistList[j]); ++j);
            if (!ClustDistList[j])
               NUC_Error(TRUE, "Unknown distance parameter %s", Arg.GetChar(k));

            ClustDistFlag |= 1 << j;
          } /* End of for (k) */
        }
        break;

      case 'f':   /* Fix the decimal separator of the CSV files */
        FixDec = TRUE;
        break;

      case 'h':   /* Show the help */
        throw 1;

      case 'k':   /* Number of clusters */
        if (HD_StrDataTypeC(optarg) == HD_STRDT_NUMBER) {
          ClustNum = atoi(optarg);
          if (!ClustNum)
            NUC_Error(TRUE, "The number of clusters must be greater than zero");
        } else {
          NUC_Error(TRUE, "Invalid number of clusters");
        }
        break;

      case 'n':   /* Sequence name */
        SeqName = optarg;
        break;

      case 's':   /* Sequence */
        Sequence = optarg;
        break;

      case 'r':   /* Random seed */
        if (HD_StrDataTypeC(optarg) == HD_STRDT_NUMBER)
          sscanf(optarg, "%" HD_STRFMT_DL "d", &Seed);
        else
          NUC_Error(TRUE, "Invalid random seed");
        break;

      case 't':  /* Top ranked structures */
        if (HD_StrDataTypeC(optarg) == HD_STRDT_NUMBER) BestNum = atoi(optarg);
        else NUC_Error(TRUE, "Invalid number of top ranked suboptimal structures");
        break;

      case 'v': /* Save the VEGA ZZ script */
        SaveFlags |= NUC_SAVEFLG_VEGASCRIPT;
        break;

      case '?': /* Show this help */
        for(ArgPtr = ArgStr; *ArgPtr; ++ArgPtr) {
          if ((*ArgPtr != ':') && (*ArgPtr == optopt)) {
            NUC_Error(TRUE, "Option -%c requires an argument", optopt);
          }
        } /* End of for (ArgPtr) */
        if (isprint(optopt)) NUC_Error(TRUE, "Unknown option -%c", optopt);
        else NUC_Error(TRUE, "Unknown option character `\\x%x'", optopt);
      } /* End of switch */
    } /* End of while */

    /**** Check the options ****/

    if (optind >= argc) NUC_Error(TRUE, "Missing NUPACK file");
    if ((Build == NUC_BUILD_NONE) && (SaveFlags & NUC_SAVEFLG_VEGASCRIPT))
      NUC_Warning("Option -v ignored");

    /**** Initialize the VegaBase library ****/

    VG_Init(NULL);
    VegaSet.GLOBSW_STDOUT = TRUE;

    /**** Load the NUPACK file ****/

    Nupack = new NUC_Nupack;
    if (Sequence) Nupack -> SetSequence(Sequence);
    printf("* Loading the NUPACK file\n");
    Nupack -> Load(argv[optind], BestNum);
    if (SeqName) Nupack -> SetName(SeqName);
    printf("  Mfe structure %.3f kcal/mol (bp = %.0f)\n"
           "  Found %u suboptimal structures\n"
           "  Analyzed the top %u suboptimal structures\n",
           Nupack -> Mfe -> Energy, Nupack -> Mfe -> BasePairs,
           (HD_ULONG)Nupack -> StructList.size(), Nupack -> BestNum);

    PrintRuler(8, Nupack -> Sequence.Len());
    printf("  Seq: %s\n"
           "  Mfe: %s\n"
           "  Com: %s\n",
           Nupack -> Sequence.Cstr(), Nupack -> Mfe -> Struct.Cstr(), Nupack -> ComStruct.Cstr());


    if (Nupack -> StructList.size() > 1) {

      /**** Statistics ****/

      if (Nupack -> BestNum < Nupack -> StructList.size()) {
        printf("\n  Statistics for the top %u suboptimal structures:\n", Nupack -> BestNum);
        PrintStat(&Nupack -> StatBest);
      }

      printf("\n  Statistics for all %u suboptimal structures:\n", (HD_ULONG)Nupack -> StructList.size());
      PrintStat(&Nupack -> StatTot);

      /**** Cluster analysis ****/

      printf("* Performing the clustering\n"
             "  Number of clusters: %u\n"
             "  Max iterations: %u\n"
             "  Distance parameters:", ClustNum, ClustIterMax);

      HD_LONG     Mask = 1;
      for(DistStr = ClustDistList; *DistStr; ++DistStr) {
        if (ClustDistFlag & Mask) printf(" %s", *DistStr);
        Mask <<= 1;
      } /* End of for (DistStr) */
      printf("\n");

      Nupack -> Cluster(ClustNum, ClustIterMax, ClustDistFlag, Seed);
      Nupack -> ClusterPrint();

      /**** Save the clusters ****/

      if (!OutClustFile.IsEmpty()) {
        printf("* Saving the output files\n");
        Nupack -> ClusterSave(OutClustFile.Cstr(), FixDec);
      }
    } else {
      printf("\n* Clustering not performed\n");
    }

    /**** Build the 3D structures ****/

    if (Build != NUC_BUILD_NONE) {

      if (Nupack -> StructList.size() == 1)
        Build = NUC_BUILD_MFE;

      printf("* Building the 3D structure\n");
      Builder = new NUC_Build();
      Builder -> Create3D(Nupack -> Sequence, Nupack -> Type);

      HDC_String Prefix;
      HDC_String PdbFileName = Nupack -> Name + ".pdb";

      printf("* Saving the PDB file of the 3D structure\n");
      Builder -> Save3D(PdbFileName);

      printf("* Saving the OpenMM common Python script\n");
      Builder -> SaveOmmCommon(Nupack -> Name);

      HD_LONG ClustDgt  = (HD_LONG)log10((HD_DOUBLE)Nupack -> ClusterNum) + 1;
      HD_LONG StructDgt = (HD_LONG)log10((HD_DOUBLE)Nupack -> StructList.size()) + 1;
      std::list <HDC_String>    PrefixList;

      /**** Closest to the cluster centroids ****/

      if (Build & NUC_BUILD_CLOSEST) {
        for(HD_ULONG k = 0; k < Nupack -> ClusterNum; ++k) {
          Builder -> RestrAdd(Nupack -> Clusters[k].Closest -> Struct, k + 1, "closest to centroid");
          Prefix.Print("%s_%0*uC_S%0*u",
                       Nupack -> Name.Cstr(), ClustDgt, k + 1, StructDgt, Nupack -> Clusters[k].Closest -> ID);
          Builder -> SaveOmm(Prefix, PdbFileName, SaveFlags);
          PrefixList.push_back(Prefix);
        } /* End of for (k) */
      }

      /**** Lowest to the cluster centroids ****/

      if (Build & NUC_BUILD_LOWEST) {
        for(HD_ULONG k = 0; k < Nupack -> ClusterNum; ++k) {
          Builder -> RestrAdd(Nupack -> Clusters[k].Lowest -> Struct, k + 1, "lowest energy");
          Prefix.Print("%s_%0*uL_S%0*u",
                       Nupack -> Name.Cstr(), ClustDgt, k + 1, StructDgt, Nupack -> Clusters[k].Lowest -> ID);
          Builder -> SaveOmm(Prefix, PdbFileName, SaveFlags);
          PrefixList.push_back(Prefix);
        } /* End of for (k) */
      }

      /**** Lowest energy structure ****/

      if (Build & NUC_BUILD_MFE) {
        printf("* Saving restraints and OpenMM input file for MFE\n");
        Builder -> RestrAdd(Nupack -> Mfe -> Struct, 0, "MFE");
        Prefix.Print("%s_MFE_S%0*u", Nupack -> Name.Cstr(), StructDgt, 1);
        Builder -> SaveOmm(Prefix, PdbFileName, SaveFlags);
        PrefixList.push_back(Prefix);
      }

      /**** Shared substructure of each cluster ****/

      if (Build & NUC_BUILD_SHARED) {

        //HDC_String Com = "...........(.((.(((....)))))))....(((..((..((.....))...).)))................";

        for(HD_ULONG k = 0; k < Nupack -> ClusterNum; ++k) {

          Builder -> RestrAdd(Nupack -> Clusters[k].ComStruct, k + 1, "shared");
//          Builder -> RestrAdd(Com, k + 1, "shared");
          Prefix.Print("%s_%0*uS", Nupack -> Name.Cstr(), ClustDgt, k + 1);
          Builder -> SaveOmm(Prefix, PdbFileName, SaveFlags);
          PrefixList.push_back(Prefix);
        } /* End of for (k) */
      }

      /**** Save the script to run all ****/

      std::list <HDC_String>::iterator  PrefixPtr;
      HDC_String                        AllTemplate, Scripts;

      VG_StrGetPrgPath(Scripts, VG_PATH_DATA);
      Scripts += "NuClust" HD_DIRSEP "runall.py";
      try {
        AllTemplate.Load(Scripts);
      } catch (...) {
        NUC_Error(TRUE, "Can't load the template file tu run all the scripts");
      }

      Scripts.Empty();
      for(PrefixPtr = PrefixList.begin(); PrefixPtr != PrefixList.end(); ++PrefixPtr) {
        Scripts += (PrefixPtr == PrefixList.begin()) ? "  '" : ",\n  '";
        Scripts += *PrefixPtr;
        Scripts += "'";
      } /* End of for (PrefixPtr) */

      AllTemplate.SubstAll("{PREFIXLIST}", Scripts);
      Scripts = Nupack -> Name + "_all.py";
      AllTemplate.Save(Scripts);
    }

    printf("* Done\n");
    RetCode = EXIT_SUCCESS;
  } catch (int ThrowCode) {
    if (ThrowCode) {
      fprintf(stderr, "\n"
                      MYPRG_PRODUCT " " MYPRG_VER_2 " - (c) " MYPRG_COPYRIGHT "\n"
                      "\n"
                      "Usage: " MYPRG_PRODUCT " -b[WHAT] -c[CLUSTFILE] -d[DIST] -fh -i[CLUSTMAXITER]\n"
                      "               -k[CLUSTNUM] -n[SEQNAME] -r[SEED] -s[SEQUENCE] -t[TOPNUM] -v NUPACK_FILE\n"
                      "\n"
                      "Supported NUPACK input formats:\n"
                      " csv, txt\n"
                      "\n"
                      "Options:\n"
                      " b -> Build the 3D structures of:\n"
                      "      CLOSEST     = Structures closest to each cluster centroid\n"
                      "      LOWEST      = Structures with the lowest energy of each cluster\n"
                      "      MFE         = Lowest energy structure\n"
                      "      SHARED      = Shared substructure for each cluster\n"
                      " c -> Output cluster file\n"
                      " d -> Parameters used to calculate the distance for the cluster analysis:\n"
                      "      APTAMAT     = Matrix-based similarity of secondary structure with MFE\n"
                      "      BP          = Number of base pairs\n"
                      "      DISTANCE    = Distance from MFE\n"
                      "      ENERGY      = Energy hcal/mol\n"
                      "      PROBABILITY = Suboptimal structure probability\n"
                      "      STRUCTURE   = H-bond network\n"
                      "      The parameters must be separated by a space and between double quotes\n"
                      " f -> Fix the decimal separator according the locale settings\n"
                      " h -> Show this help\n"
                      " i -> Maximum number of iterations for cluster analysis (default %u)\n"
                      " k -> Number of clusters (default %u)\n"
                      " n -> Sequence name\n"
                      " s -> Base sequence (for csv format)\n"
                      " r -> Seed for random number generator\n"
                      " t -> Analyze the top ranked suboptimal structures (default %u, 0 = all)\n"
                      " v -> Save the script to show the restraint in VEGA ZZ\n"
                      "\n"
                      "Examples:\n"
                      " " MYPRG_PRODUCT " nupack_file.txt\n"
                      " " MYPRG_PRODUCT " -k 10 -c cluster_file.csv nupack_file.txt\n"
                      " " MYPRG_PRODUCT " -f -c cluster_file.csv -d \"Bp Energy Structure\" nupack_file.txt"
                      " " MYPRG_PRODUCT " -b shared -c cluster_file.csv -d Structure -v nupack_file.txt",
                      ClustIterMax, ClustNum, BestNum);
    }
    fprintf(stderr, "\n");
  } catch (...) {
    NUC_Error(FALSE, "Unhandled exception");
  }

  /**** Free the resources ****/

  delete Builder;
  delete Nupack;
  VG_Free();

  return RetCode;
}


/**** Show an error ****/

HD_VOID NUC_Error(HD_BOOL Throw, const HD_CHAR *Err, ...)
{
  HDC_String    Msg;
  va_list       Vl;

  va_start(Vl, Err);
  Msg.VPrint(Err, Vl);
  VG_StrIso2Dos(Msg.Cstr());
  fprintf(stderr, "\nERROR: %s.\n", Msg.Cstr());
  va_end(Vl);

  if (Throw) throw 0;
}


/**** Show a warning ****/

HD_VOID NUC_Warning(const HD_CHAR *Warn, ...)
{
  HDC_String    Msg;
  va_list       Vl;

  va_start(Vl, Warn);
  Msg.VPrint(Warn, Vl);
  VG_StrIso2Dos(Msg.Cstr());
  fprintf(stderr, "\nWARNING: %s.\n", Msg.Cstr());
  va_end(Vl);
}


/**** Print ruler for sequence ****/

HD_VOID HD_FASTCALL PrintRuler(HD_LONG Offset, HD_LONG Len)
{
  HD_LONG     k;
  HD_LONG     Count = 2;

  /**** Tens ****/

  printf("\n%*c", Offset - 1, ' ');
  for(k = 10; k <= Len; k += 10)
    printf("%*d", 10, k / 10);

  /**** Units ****/

  printf("\n%*c", Offset, '1');
  for(k = 1; k < Len; ++k) {
    if (Count == 10) {
      printf("0");
      Count = 0;
    } else printf("%c", Count + '0');
    ++Count;
  } /* End of for (k) */

  /**** Line ****/

  printf("\n%*c", Offset, '=');
  for(k = 1; k < Len; ++k)
    printf("-");
  printf("\n");
}


/**** Print the statistics ****/

HD_VOID HD_FASTCALL PrintStat(NUC_STAT *Data)
{
  const HD_CHAR *     Format = "  %-11s %10.6f %10.6f %10.6f %10.6f %10.6f\n";

  printf("\n"
         "                  Mean       DevStd     Min        Max        Range\n"
         "  ==================================================================\n");
  printf(Format, "AptaMat",
         Data -> Mean.AptaMat, Data -> StdDev.AptaMat, Data -> Min.AptaMat,
         Data -> Max.AptaMat , Data -> Max.AptaMat -   Data -> Min.AptaMat);
  printf(Format, "BasePairs",
         Data -> Mean.BasePairs, Data -> StdDev.BasePairs, Data -> Min.BasePairs,
         Data -> Max.BasePairs , Data -> Max.BasePairs -   Data -> Min.BasePairs);
  printf(Format, "Energy",
         Data -> Mean.Energy, Data -> StdDev.Energy, Data -> Min.Energy,
         Data -> Max.Energy , Data -> Max.Energy -   Data -> Min.Energy);
  printf(Format, "MfeDist",
         Data -> Mean.MfeDist, Data -> StdDev.MfeDist, Data -> Min.MfeDist,
         Data -> Max.MfeDist , Data -> Max.MfeDist -   Data -> Min.MfeDist);
  printf(Format, "Probability",
         Data -> Mean.Probability, Data -> StdDev.Probability, Data -> Min.Probability,
         Data -> Max.Probability , Data -> Max.Probability -   Data -> Min.Probability);
  printf("\n");
}


/**** Signal handler ****/

static HD_VOID SignalHandler(HD_LONG Signal)
{
  switch(Signal) {
  case SIGFPE:
    NUC_Error(TRUE, "Illegal floating point operation");

  case SIGILL:
    NUC_Error(TRUE, "Illegal operation");

  case SIGINT:
#ifdef WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#endif
    fprintf(stderr, "\nAborted by user\n");
    SignaHandlerInt(Signal);

  case SIGSEGV:
    NUC_Error(TRUE, "Access violation");

  default:
    NUC_Error(TRUE, "Internal error (code %d)", Signal);
  } /* End of switch */
}






