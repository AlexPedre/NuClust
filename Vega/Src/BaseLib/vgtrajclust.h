
/*************************************************
****       VEGA - Trajectory clustering       ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_TRACLUST
#  define  __VG_TRACLUST

#  include  "vgglobdef.h"

/**** Cluster ****/

typedef struct __vg_trjcitem {
  struct __vg_trjcitem *        Next;           /* Next structure element     */
  struct __vg_trjcitem *        Prev;           /* Previous structure element */
  HD_FLOAT                      Energy;         /* Best energy                */
  HD_ULONG *                    AngleSteps;     /* Angle steps                */
  HD_ULONG                      Clustered;      /* Clustered conformers       */
  HD_ULONG                      Frame;          /* Trajectory frame naumber   */
  HD_ULONG                      Num;            /* Cluster number             */
  HD_XYZF *                     Coord;          /* Atomic coordinates         */
} VG_TRJCITEM;

/**** Cluster context ****/

typedef struct {
  HD_ATOM *                     BegAtm;         /* Atom list                  */
  VG_ATMSEL **                  BegTor;         /* Torsions                   */
  HD_FLOAT *                    TorVal;         /* Torsion value array        */
  HD_FLOAT                      Rmsd;           /* RMSD treshold              */
  HD_BOOL                       ActiveOnly;     /* Consider active only atoms */
  HD_ULONG                      FirstFrm;       /* First frame to analyze     */
  HD_ULONG                      LastFrm;        /* Last frame to analyze      */
  HD_ULONG                      SkipFrm;        /* Frame to skip              */
  HD_ULONG                      TotAtm;         /* Total number of atoms      */
  HD_ULONG                      TotTor;         /* Number of torsions         */
  HD_LIST *                     Clusters;       /* Cluster list               */
} VG_TRJCLUST;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_TrjClustCoord                   _VG_TrjClustCoord
#    define  VG_TrjClustFree                    _VG_TrjClustFree
#    define  VG_TrjClustSave                    _VG_TrjClustSave
#    define  VG_TrjClustSaveEne                 _VG_TrjClustSaveEne
#    define  VG_TrjClustSortEne                 _VG_TrjClustSortEne
#    define  VG_TrjClustTor                     _VG_TrjClustTor
#    define  VG_TrjClustTorRmsd                 _VG_TrjClustTorRmsd
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN VG_TRJCLUST *   VEGA_EXPORT VG_TrjClustCoord(VG_CTX *Ctx, VG_TRJINFO *Info, HD_ULONG FirstFrm, HD_ULONG LastFrm, HD_ULONG SkipFrm, HD_FLOAT RmsdVal, HD_BOOL ActiveOnly);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_TrjClustFree(VG_TRJCLUST *Clust);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_TrjClustSave(VG_CTX *Ctx, const HD_CHAR *FileName, VG_TRJCLUST *Clust, HD_ULONG Format, HD_FLOAT Precision, HD_LONG Flg);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_TrjClustSaveEne(VG_CTX *Ctx, const HD_CHAR *FileName, VG_TRJCLUST *Clust);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_TrjClustSortEne(VG_TRJCLUST *Clust);
VEGA_EXTERN VG_TRJCLUST *   VEGA_EXPORT VG_TrjClustTor(VG_CTX *Ctx, VG_TRJINFO *Info, VG_ATMSEL *Selection, HD_ULONG FirstFrm, HD_ULONG LastFrm, HD_ULONG SkipFrm);
VEGA_EXTERN VG_TRJCLUST *   VEGA_EXPORT VG_TrjClustTorRmsd(VG_CTX *Ctx, VG_TRJINFO *Info, VG_ATMSEL *Selection, HD_ULONG FirstFrm, HD_ULONG LastFrm, HD_ULONG SkipFrm, HD_FLOAT RmsdVal);

#  ifdef __cplusplus
}
#  endif
#endif
