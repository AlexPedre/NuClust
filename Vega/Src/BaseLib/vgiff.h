
/*************************************************
****            VEGA - Include IFF            ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __IFF
#  define  __IFF

/**** Save flags ****/

#  define  IFF_CHUNK_ALL        0xffffffff
#  define  IFF_CHUNK_MON        1
#  define  IFF_CHUNK_SRF        2
#  define  IFF_CHUNK_XYZ        4
#  define  IFF_CHUNK_TRJ        (0xffffffff & ~IFF_CHUNK_MON & ~IFF_CHUNK_SRF & ~IFF_CHUNK_XYZ)

/**** Monitor structure ****/

typedef struct __vg_monitor {
  struct __vg_monitor * Next;           /* Pointer to the next element        */
  struct __vg_monitor * Prev;           /* Pointer to the previous element    */
  HD_UBYTE              Type;           /* Monitor type                       */
  HD_ULONG              ObjAtom[6];     /* Atom index array                   */
  HD_CHAR *             Label;
} VG_MONITOR;

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_IFFLoadMem                      _VG_IFFLoadMem
#    define  VG_IFFLoad                         _VG_IFFLoad
#    define  VG_IFFSaveMem                      _VG_IFFSaveMem
#    define  VG_IFFSave                         _VG_IFFSave

#    define  VG_IffTrApply                      _VG_IffTrApply
#    define  VG_IffTrDestroy                    _VG_IffTrDestroy
#    define  VG_MonListDestroy                  _VG_MonListDestroy
#    define  VG_MonListShow                     _VG_MonListShow
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_ATOM *  VEGA_EXPORT VG_IFFLoadMem(VG_CTX *Ctx, HD_BYTE *Data, HD_ULONG Size, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_LIST **SrfList, HD_BOOL *IsMulti);
VEGA_EXTERN HD_ATOM *  VEGA_EXPORT VG_IFFLoad(VG_CTX *Ctx, const HD_CHAR *FileName, HD_ATOM **LastAtom, HD_ULONG *TotAtomi, HD_LIST **SrfList, HD_BOOL *IsMulti);
VEGA_EXTERN HD_BYTE *  VEGA_EXPORT VG_IFFSaveMem(VG_CTX *Ctx, HD_ULONG *Size, const HD_CHAR *MolName, HD_LONG WriteFlags, HD_LONG ChunkFlags);
VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_IFFSave(VG_CTX *Ctx, const HD_CHAR *FileName, HD_LONG WriteFlags, HD_LONG ChunkFlags);

#    ifdef VEGA_ZZ

VEGA_EXTERN HD_BOOL    VEGA_EXPORT VG_IffTrApply(HD_VOID);
VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_IffTrDestroy(HD_VOID);
VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_MonListDestroy(HD_VOID);
VEGA_EXTERN HD_VOID    VEGA_EXPORT VG_MonListShow(HD_ATOM *InizAtm, HD_ULONG Tot);

#    endif
#  ifdef __cplusplus
}
#  endif
#endif

