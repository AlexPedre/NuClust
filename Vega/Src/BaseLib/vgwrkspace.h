
/*************************************************
****        VEGA - Workspace manager          ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef  __GL_WRKSPACE_H
#  define  __GL_WRKSPACE_H

#  include <hyperdrive.h>
#  include <hdmatrix.h>

#  include "vgatom.h"
#  include "vgtraj.h"

#  ifdef VEGA_ZZ
#    include "gl_global.h"
#    include "gl_objs.h"
#  endif

#ifdef VEGA_ZZ
#  include "../Plugins/plugin.h"
#endif

/**** View data ****/

typedef struct {
  HD_DOUBLE             FovAngle;                   /* Field of vision angle       */
  HD_FLOAT              Scale;                      /* Scale                       */
  HD_MTX4X4F            RotMat;                     /* Rotation matrix             */
  HD_XYZF               RotCenter;                  /* Rotation center             */
  HD_XYZF               RotCenterBak;               /* Rotation center bak         */
  HD_XYZF               ViewCenter;                 /* View center                 */
  HD_XYZF               ViewCenterBak;              /* View center bak             */
  HD_XYZF               ViewRot;                    /* View rotation               */
} VG_WKSVIEW;

/**** VG_Surface attributes for undo ****/

typedef struct {
  HD_LONG               Flags;                     /* Flags                       */
  HD_UBYTE              Alpha;                     /* Alpha blending value        */
  HD_UBYTE              DotSize;                   /* Dot size                    */
} VG_UNDO_SRFATT;

/**** Undo structure data ****/

typedef struct __VgUndo {
  struct __VgUndo *     Next;                      /* Pointer to next element     */
  struct __VgUndo *     Prev;                      /* Pointer to prevoius element */
  HD_ATOM **            AtmSeq;                    /* Atom sequence               */
  HD_BYTE *             ChainIDMtx;                /* Atom chain ID matrix        */
  HD_BYTE *             ChiralMtx;                 /* Atom chirality matrix       */
  HD_CHAR *             LabelStr;                  /* Undo menu label             */
  HD_FLOAT *            ChargeMtx;                 /* Atom charge matrix          */
  HD_FLOAT *            CoordMtx;                  /* Atom coordinate matrix      */
  HD_FLOAT *            FixMtx;                    /* Atom constraint matrix      */
  HD_LONG *             FlagsMtx;                  /* Atom flag matrix            */
  HD_DLONG *            PotMtx;                    /* Atom potential matrix       */
  HD_LONG *             NameMtx;                   /* Atom name matrix            */
  HD_LONG *             ResNameMtx;                /* Residue name matrix         */
  HD_LONG *             ResSeqMtx;                 /* Residue number matrix       */
  HD_LONG               Type;                      /* Undo type                   */
  VG_PUSH_ATOMO *       Atomo;                     /* Single atom                 */
  HD_UBYTE *            ActiveMtx;                 /* Active atom matrix          */
  HD_UBYTE *            BndOrdMtx;                 /* Bond order matrix           */
  HD_UBYTE *            ColorMtx;                  /* Color matrix                */
  HD_UBYTE *            DrawModeMtx;               /* Draw mode matrix            */
  HD_UBYTE *            LabelMtx;                  /* Label matrix                */
  HD_UBYTE *            NSostMtx;                  /* Number of substituent mtx   */
  HD_UBYTE *            SrfColMtx;                 /* VG_Surface color matrix     */
  HD_ULONG              Bonds;                     /* Number of bonds             */
  HD_ULONG              SrfListNum;                /* NUmber of surfaces          */
  HD_ULONG              SrfTot;                    /* Total surface dots          */
  HD_ULONG *            ConnectMtx;                /* Connectivity matrix         */
  VG_UNDO_SRFATT *      SrfAttMtx;                 /* VG_Surface attribute matrix */
  HD_WORD *             ElemMtx;                   /* Atom element matrix         */
  VG_WRKSPACE           Data;                      /* Workspace data              */
} VG_UNDO;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_WksAdd                          _VG_WksAdd
#    define  VG_WksAreEmpty                     _VG_WksAreEmpty
#    define  VG_WksChange                       _VG_WksChange
#    define  VG_WksFreeAll                      _VG_WksFreeAll
#    define  VG_WksInit                         _VG_WksInit
#    define  VG_WksIsLocked                     _VG_WksIsLocked
#    define  VG_WksLock                         _VG_WksLock
#    define  VG_WksPop                          _VG_WksPop
#    define  VG_WksPush                         _VG_WksPush
#    define  VG_WksRemove                       _VG_WksRemove
#    define  VG_WksSetName                      _VG_WksSetName
#    define  VG_WksUnLock                       _VG_WksUnLock

#    define  VG_UndoDestroy                     _VG_UndoDestroy
#    define  VG_UndoDestroyLast                 _VG_UndoDestroyLast
#    define  VG_UndoDisable                     _VG_UndoDisable
#    define  VG_UndoPop                         _VG_UndoPop
#    define  VG_UndoPush                        _VG_UndoPush
#    define  VG_UndoPushAtm                     _VG_UndoPushAtm
#    define  VG_UndoPushPol                     _VG_UndoPushPol
#    define  VG_UndoPushStr                     _VG_UndoPushStr
#    define  VG_UndoRemove                      _VG_UndoRemove
#    define  VG_UndoRemoveAll                   _VG_UndoRemoveAll
#    define  VG_UndoReset                       _VG_UndoReset
#    define  VG_UndoResetEx                     _VG_UndoResetEx
#    define  VG_UndoSetMaxLevels                _VG_UndoSetMaxLevels

#    define  VG_WksCpyAtm                       _VG_WksCpyAtm
#    define  VG_WksCpyAtmID                     _VG_WksCpyAtmID
#    define  VG_WksFree                         _VG_WksFree
#    define  VG_WksViewPop                      _VG_WksViewPop
#    define  VG_WksViewPush                     _VG_WksViewPush
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN VG_WRKSPACE *   VEGA_EXPORT VG_WksAdd(VG_CTX *Ctx);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_WksAreEmpty(VG_CTX *Ctx, HD_BOOL All);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_WksChange(VG_CTX *Ctx, VG_WRKSPACE *Wks, HD_ULONG Idx, HD_BOOL UpdateList);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_WksFreeAll(VG_CTX *Ctx);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_WksInit(VG_CTX *Ctx);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_WksIsLocked(VG_CTX * Ctx);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_WksLock(VG_CTX * Ctx, HD_BOOL Repaint);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_WksPop(VG_CTX *Ctx, VG_WRKSPACE *Wks);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_WksPush(VG_CTX *Ctx, VG_WRKSPACE *Wks);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_WksRemove(VG_CTX *Ctx, VG_WRKSPACE *Wks, HD_ULONG Idx, HD_BOOL Ask);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_WksSetName(VG_CTX * Ctx, const HD_CHAR *NewName);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_WksUnLock(VG_CTX * Ctx);

VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_UndoDestroy(HD_LIST *Undo);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_UndoDestroyLast(HD_VOID);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_UndoDisable(HD_BOOL Disable);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_UndoPop(HD_BOOL Reverse);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_UndoPush(HD_LONG Type, HD_ULONG Label);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_UndoPushAtm(HD_ATOM *Atm, HD_ULONG Label);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_UndoPushPol(HD_LONG Type, HD_ULONG Label);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_UndoPushStr(HD_LONG Type, const HD_CHAR *LabelStr);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_UndoRemove(HD_LIST *Undo, VG_UNDO *Item);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_UndoRemoveAll(HD_LIST *Undo);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_UndoReset(HD_VOID);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_UndoResetEx(HD_LIST *Undo, HD_LIST *Redo);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_UndoSetMaxLevels(HD_ULONG MaxLevels);

VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_WksCpyAtm(VG_WRKSPACE *Dest, VG_WRKSPACE *Src);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_WksCpyAtmID(HD_ULONG DestID, HD_ULONG SrcID);
VEGA_EXTERN HD_BOOL         VEGA_EXPORT VG_WksFree(HD_BOOL);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_WksViewPop(VG_WKSVIEW *);
VEGA_EXTERN HD_VOID         VEGA_EXPORT VG_WksViewPush(VG_WKSVIEW *);

#  ifdef __cplusplus
}
#  endif
#endif
