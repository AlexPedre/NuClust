
/*************************************************
****        VEGA - Private definitions        ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_PRIVATE_H
#  define  __VG_PRIVATE_H

/**** Global variables ****/

extern const HD_CHAR *            PackerNames[];
extern const HD_ULONG             UndoDrawMode[];
extern const HD_ULONG             UndoLabel[];
extern const HD_CHAR *            VegaPDBAtmRec[];

/**** Prototypes ****/

HD_LONG              HD_CALLBACK VG_DbSortFunc(const HD_VOID *, const HD_VOID *);
HD_LONG              HD_CALLBACK VG_MolListSortFunc(const HD_VOID *, const HD_VOID *);

#endif

