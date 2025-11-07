
/*******************************************
****        HyperDrive - Types          ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#ifndef __HDTYPES_H
#  define  __HDTYPES_H

#  ifndef AMIGA
#    include <wchar.h>
#  endif

#  define  MAXBOND              6       /* Max bonded atoms                   */
#  define  MAXRING              4       /* Max condensed rings                */

/**** Integer types ****/

typedef int                     HD_BOOL;
typedef char                    HD_BYTE;
typedef unsigned char           HD_UBYTE;
typedef char                    HD_CHAR;
typedef unsigned char           HD_UCHAR;
typedef short                   HD_WORD;
typedef unsigned short          HD_UWORD;
typedef int                     HD_LONG;
typedef unsigned int            HD_ULONG;

/**** Floating poit types ****/

typedef double                  HD_DOUBLE;
typedef float                   HD_FLOAT;
typedef float                   HD_FLOAT32;
typedef double                  HD_FLOAT64;
typedef long double             HD_FLOAT80;
typedef long double             HD_FLOAT128;
typedef long double             HD_LONGDOUBLE;

/**** Other types ****/

typedef void *                  HD_FILE;
typedef void *                  HD_POINTER;

#  ifdef __cplusplus
#    if defined(HD_64BIT) || defined(WIN64) || defined(_WIN64) || defined(__x86_64__) || defined(__arm64__)
#      define  HD_NULL          0LL
#      define  HD_NULLPTR       0LL
#    else
#      define  HD_NULL          0L
#      define  HD_NULLPTR       0L
#    endif
#  else
#    define  HD_NULL            ((void *)0)
#    define  HD_NULLPTR         ((void *)0)
#  endif

#  define  HD_TAGEND            ((void *)0)

//#  if defined(__cplusplus) && defined(__BORLANDC__) && !defined(__WIN32__)
#  if defined(__cplusplus) && defined(__BORLANDC__) && defined(__clang__)
#    define  HD_VOID            void
#  else
typedef void                    HD_VOID;
#  endif

/**** Hack to fix g++ bug ****/

#  if defined(__cplusplus) && defined(__GNUC__)
#    define  HD_VOID            void
#  endif

#  ifndef AMIGA
typedef wchar_t                 HD_WCHAR;
#  endif

#  ifdef __BORLANDC__
typedef __int64                 HD_DLONG;
typedef unsigned __int64        HD_UDLONG;
#  else
typedef long long               HD_DLONG;
typedef unsigned long long      HD_UDLONG;
#  endif

typedef union {
  HD_CHAR               C[2];
  HD_UWORD              US;
  HD_WORD               S;
} HD_DCHAR;

typedef union {
  HD_CHAR               C[4];
  HD_UBYTE              UC[4];
  HD_LONG               L;
  HD_UWORD              US[2];
  HD_WORD               S[2];
} HD_QCHAR;

typedef union {
  HD_CHAR               C[8];
  HD_DLONG              DL;
  HD_UDLONG             UDL;
  HD_LONG               L[2];
  HD_ULONG              UL[2];
  HD_UWORD              US[4];
  HD_WORD               S[4];
} HD_OCHAR;

/**** Generic XYZ vector (double precision) ****/

typedef struct {
  HD_DOUBLE             x, y, z;
} HD_XYZ;

/**** Generic XYZ vector (single precision) ****/

typedef struct {
  HD_FLOAT              x, y, z;
} HD_XYZF;

/**** Generic XYZ vector (integer) ****/

typedef struct {
  HD_LONG               x, y, z;
} HD_XYZL;

/**** Generic XYZ vector (unsigned integer) ****/

typedef struct {
  HD_ULONG              x, y, z;
} HD_XYZUL;

/**** Argument parser ****/

typedef void *          HD_ARGS;

/**** Generic handle ****/

typedef void *          HD_HANDLE;

/**** Time ****/

typedef long            HD_TIME;

/**** File types ****/

#  ifdef HD_64BIT
typedef HD_UDLONG               HD_SIZE;
typedef HD_DLONG                HD_POS;
typedef HD_DLONG                HD_LONG_PTR;
#  else
typedef HD_ULONG                HD_SIZE;
typedef HD_LONG                 HD_POS;
typedef HD_LONG                 HD_LONG_PTR;
#  endif

/**** Atom structure ****/

typedef struct __hd_atom {
  struct __hd_atom *Ptr;                /* Address of next structure          */
  struct __hd_atom *Prev;               /* Address of prev. structure         */
  HD_OCHAR          Pot;                /* Atom type (potential)              */
  HD_ULONG          Num;                /* Atom number                        */
  HD_QCHAR          Name;               /* Atom name                          */
  HD_QCHAR          ResName;            /* Residue name                       */
  HD_QCHAR          ResSeq;             /* Number of residue                  */
  HD_QCHAR          Ring;               /* Ring indicator                     */
  HD_LONG           Flags;              /* See above                          */
  HD_FLOAT          x, y, z;            /* X, Y, Z coodinates                 */
  HD_FLOAT          Charge;             /* Atomic charge                      */
  HD_FLOAT          Rad;                /* Atomic radius                      */
  HD_FLOAT          Fix;                /* Fixing parameter                   */
  struct __hd_atom *Conn[MAXBOND];      /* Connectivity matrix                */
  HD_UBYTE          Order[MAXBOND];     /* Bond order                         */
  HD_UBYTE          NSost;              /* Number of bonded atoms             */
  HD_BYTE           ChainID;            /* Chain indicator                    */
  HD_DCHAR          Elem;               /* Element                            */
  HD_UBYTE          ColorID;            /* Color ID (OpenGL)                  */
  HD_UBYTE          Label;              /* Label (OpenGL)                     */
  HD_UBYTE          DrawMode;           /* Draw mode (OpenGL)                 */
  HD_BYTE           Chiral;             /* Chirality flag                     */
} HD_ATOM;

/**** Atom table ****/

typedef struct {
  HD_DCHAR              Atom;           /* Element name                       */
  HD_UWORD              AtmNum;         /* Atomic number                      */
  HD_FLOAT              Mass;           /* Atomic mass                        */
  HD_LONG               MassI;          /* Integer mass                       */
  HD_FLOAT              CovRad;         /* Covalent radius                    */
  HD_FLOAT              VdwRad;         /* Van Der Waals radius               */
} HD_ATMTAB;

/**** Atom list inside the box ****/

typedef struct _BoxAtm {
  struct _BoxAtm *      Ptr;            /* Ponter to the next element         */
  HD_ATOM *             Atm;            /* Pointer to atom                    */
  HD_FLOAT              Rad;            /* Atom radius                        */
} HD_CONNBOXATM;

/**** Atom box ****/

typedef struct {
  HD_CONNBOXATM *       FirstAtm;       /* Fist atom in the box               */
  HD_CONNBOXATM *       LastAtm;        /* Last atom in the box               */
} HD_CONNBOX;

/**** Atom grid ****/

typedef struct {
  HD_CONNBOX *          BoxAtom;        /* Begin of the box list              */
  HD_LONG               Xb, Yb, Zb;     /* Boxes along X, Y and Z axis        */
  HD_LONG               XyTotb;         /* Number of boxes per XY plane       */
  HD_LONG               Totb;           /* Number of all boxes                */
  HD_XYZF               BoxSize;        /* Box dimensions                     */
  HD_XYZF               MaxC;           /* Max molecule coordinates           */
  HD_XYZF               MinC;           /* Min molecule coordinates           */
} HD_ATMSGRID;

/**** Dummy item list ****/

typedef struct __HdListItem {
  struct __HdListItem * Next;           /* Pointer to the next list item      */
  struct __HdListItem * Prev;           /* Pointer to the previous list item  */
} HD_LISTITEM;

/**** Generic pointer list list ****/

typedef struct __HdListItemPtr {
  struct __HdListItemPtr *      Next;   /* Pointer to the next list item      */
  struct __HdListItemPtr *      Prev;   /* Pointer to the previous list item  */
  HD_VOID *                     Ptr;    /* Pointer storing the data           */
} HD_LISTITEMPTR;

/**** List info ****/

typedef struct {
  HD_LISTITEM *         Beg;            /* Start of the list                  */
  HD_LISTITEM *         Last;           /* Last item in the list              */
  HD_ULONG              ItemSize;       /* Item size                          */
  HD_ULONG              Num;            /* Number of items                    */
  HD_LONG               Flags;          /* User flags                         */
} HD_LIST;

/**** MAC address ****/

typedef struct {
  HD_UBYTE      Addr[6];                /* 48 bit hardware address            */
} HD_MACADDR;

/**** Memory statistics ****/

typedef struct {
  HD_UDLONG             Fp;             /* System bytes                       */
  HD_UDLONG             MaxFp;          /* Max. system bytes                  */
  HD_UDLONG             Used;           /* In use bytes                       */
} HD_MEMSTATS;

/**** RGBA structure ****/

typedef struct {
  HD_UBYTE      R, G, B, A;             /* RGBA components                    */
} HD_RGBA;

/**** Color structure ****/

typedef union {
  HD_RGBA       RGBA;                   /* RGBA components                    */
  HD_UBYTE      V[4];                   /* Vector                             */
  HD_LONG       L;                      /* Signed long                        */
  HD_ULONG      UL;                     /* Unsigned long                      */
} HD_COLOR;

/**** String types ****/

struct __hd_string {
  HD_CHAR *     Cstr;                   /* String buffer                      */
  HD_LONG       Len;                    /* Len                                */
};

typedef struct __hd_string *    HD_STRING;

#  ifndef AMIGA

struct __hd_wstring {
  HD_WCHAR *    Wstr;                   /* String buffer                      */
  HD_LONG       Len;                    /* Len                                */
};

typedef struct __hd_wstring *   HD_WSTRING;
#  endif

/**** String list item ****/

struct __hd_stritem {
  struct __hd_stritem * Next;           /* Pointer to the next list item      */
  struct __hd_stritem * Prev;           /* Pointer to the previous  list item */
  HD_STRING             Str;            /* String                             */
};

typedef struct __hd_stritem *   HD_STRITEM;

#  ifndef AMIGA
struct __hd_wstritem {
  struct __hd_wstritem *Next;           /* Pointer to the next list item      */
  struct __hd_wstritem *Prev;           /* Pointer to the previous  list item */
  HD_WSTRING            Str;            /* String                             */
};

typedef struct __hd_wstritem *   HD_WSTRITEM;
#  endif

/**** String list ****/

struct __hd_strlist {
  HD_STRITEM            Beg;            /* Start of the list                   */
  HD_STRITEM            Last;           /* Last item in the list               */
  HD_ULONG              ItemSize;       /* Item size                           */
  HD_ULONG              Num;            /* Number of items                     */
  HD_LONG               Flags;          /* User flags                          */
};

typedef struct __hd_strlist * HD_STRLIST;

/**** Surface data structure ****/

typedef struct __hd_surface {
  struct __hd_surface * Next;           /* Pointer to next element             */
  struct __hd_surface * Prev;           /* Pointer to prevoius element         */
  HD_ULONG              Num;            /* Dot number (from 0 to n)            */
  HD_ULONG              AtmNum;         /* Atom number                         */
  HD_FLOAT              x, y, z;        /* Coordinates (don't change the order */
  HD_FLOAT              Val;            /* of these two fields)                */
  HD_UBYTE              Color[3];       /* Color vector in RGBA format         */
  HD_BYTE               Flags;          /* Flags                               */
} HD_SURFACE;

/**** Surface info structure ****/

typedef struct __hd_srfinfo {
  struct __hd_srfinfo * Next;           /* Pointer to next element             */
  struct __hd_srfinfo * Prev;           /* Pointer to prevoius element         */
  HD_SURFACE *          BegSrf;         /* Begin of the surface list           */
  HD_SURFACE *          LastSrf;        /* Last surface dot                    */
  HD_SURFACE **         BegFace;        /* List of faces                       */
  HD_ULONG              TotFace;        /* Number of faces                     */
  HD_ULONG              TotSrf;         /* Number of the surface dots          */
  HD_FLOAT *            BegNorm;        /* Begin of the normal array           */
  HD_VOID *             Name;           /* Surface name (HD_STRING)            */
  HD_LONG               Flags;          /* Flags                               */
  HD_LONG               GlList;         /* Display list                        */
  HD_ULONG              GlVbo;          /* Vertex buffer objects               */
  HD_ULONG              GlVboCol;       /* Color buffer objects                */
  HD_ULONG              GlVboNorm;      /* Normal buffer objects               */
  HD_UBYTE              Type;           /* Surface type                        */
  HD_UBYTE              Alpha;          /* Alpha blending value                */
  HD_UBYTE              DotSize;        /* Dot size for dotted surfaces        */
} HD_SRFINFO;

#  ifndef AMIGA
struct __hd_wstrlist {
  HD_WSTRITEM           Beg;            /* Start of the list                   */
  HD_WSTRITEM           Last;           /* Last item in the list               */
  HD_ULONG              ItemSize;       /* Item size                           */
  HD_ULONG              Num;            /* Number of items                     */
  HD_LONG               Flags;          /* User flags                          */
};

typedef struct __hd_wstrlist * HD_WSTRLIST;

/**** Multithreading ****/

typedef void *          HD_BARRIER;
typedef void *          HD_EVENT;
typedef void *          HD_MUTEX;
typedef void *          HD_SEMAPHORE;
typedef void *          HD_THREAD;

#  endif

/**** Callback types ****/

#  ifdef __HDRIVE_H
typedef HD_LONG HD_CALLBACK (*HD_SORTCALLBACK)(const HD_VOID *V1, const HD_VOID *V2);
typedef HD_VOID HD_CALLBACK (*HD_ATOMCALLBACK)(HD_ATOM *Atm);
typedef HD_BOOL HD_CALLBACK (*HD_BNDLENCALLBACK)(HD_FLOAT Len, HD_FLOAT IdealLen, HD_ATOM *Atm1, HD_ATOM *Atm2, HD_LONG ViolType, HD_VOID *UserArg);
typedef HD_BOOL HD_CALLBACK (*HD_BUMPCALLBACK)(HD_ULONG BumpNum, HD_ATOM *Atm1, HD_ATOM *Atm2);
typedef float   HD_CALLBACK (*HD_SCORECALLBACK)(HD_ATOM *Atm1, HD_ATOM *Atm2, HD_VOID *UserArg);
#  endif
#endif
