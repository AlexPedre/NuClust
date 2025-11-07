
/********************************************
****       NuClust - Version header      ****
**** (c) 2022-2025 - Alessandro Pedretti ****
********************************************/


#ifndef __NUC_GLOBALS_H
#  define  __NUC_GLOBALS_H

#  include <hyperdrive.h>
#  include <vgbase.h>

/**** Build flags ****/

#  define  NUC_BUILD_NONE             0
#  define  NUC_BUILD_CLOSEST          1
#  define  NUC_BUILD_LOWEST           2
#  define  NUC_BUILD_MFE              4
#  define  NUC_BUILD_SHARED           8

/**** Flags for NUPACK data ****/

#  define  NUC_DATAFLG_NONE           0
#  define  NUC_DATAFLG_CENTER         1
#  define  NUC_DATAFLG_MFE            2
#  define  NUC_DATAFLG_LOWENE         4

/**** Flags for Kmeans distance calculation ****/

#  define  NUC_DIST_NONE              0
#  define  NUC_DIST_APTAMAT           1
#  define  NUC_DIST_BP                2
#  define  NUC_DIST_DISTANCE          4
#  define  NUC_DIST_ENERGY            8
#  define  NUC_DIST_PROBABILITY      16
#  define  NUC_DIST_STRUCTURE        32

#  define  NUC_DIST_DEFAULT          (NUC_DIST_BP|NUC_DIST_ENERGY|NUC_DIST_PROBABILITY|NUC_DIST_STRUCTURE)
#  define  NUC_DIST_ALL              0xffffffff

/**** Save flags ****/

#  define  NUC_SAVEFLG_NONE           0
#  define  NUC_SAVEFLG_VEGASCRIPT     1

/**** Constants ****/

#  define NUC_TYPE_DNA                0
#  define NUC_TYPE_RNA                1

/**** Types ****/

typedef HD_VOID (*NUC_SIGNALHANDLER)(HD_LONG);

/**** Base data ****/

typedef struct {
  HD_LONG         NumClose;               /* Number of close parenthesis */
  HD_LONG         NumDot;                 /* Number of dots              */
  HD_LONG         NumOpen;                /* Number of open parenthesis  */
} NUC_BASE;

/**** NUPACK model ****/

typedef struct {
  HD_FLOAT                AptaMat;
  HD_FLOAT                BasePairs;
  HD_FLOAT                Energy;
  HD_FLOAT                MfeDist;
  HD_FLOAT                Probability;
  HD_FLOAT *              StructVal;
  HD_LONG                 Flags;
  HD_ULONG                ClusterID;
  HD_ULONG                ID;
  HDC_String              Struct;
//  NUC_BASE *              StructVal;
} NUC_MODEL;

/**** NUPACK data ****/

typedef struct {
  HD_FLOAT                AptaMat;
  HD_FLOAT                BasePairs;
  HD_FLOAT                Energy;
  HD_FLOAT                MfeDist;
  HD_FLOAT                Probability;
} NUC_DATA;

/**** Statistics ****/

typedef struct {
  HD_ULONG                Num;
  NUC_DATA                Mean;
  NUC_DATA                Max;
  NUC_DATA                Min;
  NUC_DATA                StdDev;
  NUC_DATA                Sum;
  NUC_DATA                Sum2;
} NUC_STAT;

/**** Cluster data ****/

typedef struct {
  HD_FLOAT                ClosestDist;    /* Distance from the center of closest */
  HD_ULONG                ID;             /* Cluster ID                          */
  HD_ULONG                Num;            /* Number of structures                */
  HDC_String              ComStruct;      /* Common substructure                 */
  NUC_MODEL *             Center;         /* Center pointer                      */
  NUC_MODEL *             Closest;        /* Structure closest to the center     */
  NUC_MODEL *             Lowest;         /* Structure with the lowest energy    */
} NUC_CLUSTER;

/**** Prototypes ****/

HD_VOID     HD_FASTCALL PrintRuler(HD_LONG Offset, HD_LONG Len);
HD_VOID     HD_FASTCALL PrintStat(NUC_STAT *Data);
HD_VOID                 NUC_Error(HD_BOOL Throw, const HD_CHAR *Err, ...);
HD_VOID                 NUC_Warning(const HD_CHAR *Warn, ...);

#endif

