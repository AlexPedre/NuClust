
/********************************************
****       NuClust - NUPACK class        ****
**** (c) 2022-2025 - Alessandro Pedretti ****
********************************************/


#ifndef __NUC_NUPACK_H
#  define  __NUC_NUPACK_H

#  include <list>
#  include <hdstring.h>

#  include "kmeans.h"

/**** File formats ****/

#  define  NUC_FORMAT_UNK         0
#  define  NUC_FORMAT_CSV         1
#  define  NUC_FORMAT_TXT         2

/**** NUPACK class ****/

class NUC_Nupack
{
  public:

        /**** Properties ****/

        HD_LONG                   SeqLen;
        HD_LONG                   Type;
        HD_ULONG                  BestNum;
        HD_ULONG                  ClusterNum;
        NUC_MODEL *               Mfe;
        std::list <NUC_MODEL *>   StructList;
        HDC_String                ComStruct;
        HDC_String                Name;
        HDC_String                Sequence;
        NUC_CLUSTER *             Clusters;
        NUC_STAT                  StatBest, StatTot;

        /**** Methods ****/

                                  HD_FASTCALL NUC_Nupack();
                                  HD_FASTCALL ~NUC_Nupack();
        HD_VOID                   HD_FASTCALL Cluster(HD_ULONG ClustNum, HD_ULONG ClustIterMax, HD_LONG ClustDistFlag, HD_DLONG Seed);
        HD_VOID                   HD_FASTCALL ClusterPrint(HD_VOID);
        HD_VOID                   HD_FASTCALL ClusterSave(const HD_CHAR *FileName, HD_BOOL FixDec);
        HD_VOID                   HD_FASTCALL Load(const HD_CHAR *FileName, HD_ULONG TopNum);
        HD_VOID                   HD_FASTCALL SetSequence(const HD_CHAR *SeqStr);
        HD_VOID                   HD_FASTCALL SetName(const HD_CHAR *NameStr);
        HD_VOID                   HD_FASTCALL Stat(NUC_STAT *Res, HD_ULONG Num);

  private:

        /**** Properties ****/

        kmeans_config             Config;
        NUC_MODEL *               Centers;
        NUC_MODEL **              CentersPtr;
        NUC_MODEL **              Objects;

        /**** Methods ****/

        HD_VOID                   HD_FASTCALL Float2Struct(NUC_MODEL *Mod);
        HD_VOID                   HD_FASTCALL GetComStruct(HDC_String &ComStruct, HDC_String &Struct);
        static HD_VOID                        KmeansCentroid(const HD_POINTER *objs, const HD_LONG *clusters,
                                                             HD_SIZE num_objs, HD_LONG cluster, HD_POINTER centroid);
        static HD_FLOAT                       KmeansDistance(const HD_POINTER A, const HD_POINTER C);
        HD_VOID                   HD_FASTCALL LoadCsv(FILE *FH);
        HD_VOID                   HD_FASTCALL LoadTxt(FILE *FH);
        HD_VOID                   HD_FASTCALL Prob2Struct(NUC_CLUSTER * Clust, NUC_BASE *DataPtr);
        static bool                           SortFunc(NUC_MODEL *Mod1, NUC_MODEL *Mod2);
        HD_VOID                   HD_FASTCALL Struct2Float(NUC_MODEL *Mod);
};

#endif

