
/*********************************************
****        HyperDrive library 2.0        ****
****            Public header             ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/

/*
 * Define HDRIVE_DLL to use and compile HDRIVE.DLL
 * for Win32 with export library.
 *
 * Define HD_USE_LEADING_UNDERSCORE to add a leading underscore
 * to the exported functions
 */


#ifndef __HDRIVE_H
#  define  __HDRIVE_H

/**** Version ****/

#  define  HDRIVE_VERSION         2
#  define  HDRIVE_REVISION        0
#  define  HDRIVE_VERSTR          "2.0"

/**** Boolean constants ****/

#  ifndef FALSE
#    define  FALSE    0
#  endif
#  ifndef TRUE
#    define  TRUE     1
#  endif

/**** Arguments ****/

#  define  HD_ARGS_STARTARGSBUF      64 /* Starting argument buffer size      */
#  define  HD_ARGS_STARTBUFSIZE     256 /* Starting line buffer size          */

/**** _HD_AtmBoxCalcEx() flags ****/

#  define  HD_ATMBOXCALCFLG_NONE       0
#  define  HD_ATMBOXCALCFLG_ACTIVEONLY 1
#  define  HD_ATMBOXCALCFLG_NORADIUS   2

/**** Fast Fourier Transformation direction ****/

#  define  HD_FFT_DIRNORMAL             1.0f
#  define  HD_FFT_DIRREVERSE           -1.0f

/**** MLP scale factor ****/

#  define  HD_MLP_SCALE_FACTOR          0.80f

/**** Max ring detection ****/

#  define  HD_MAXRINGSIZE               7
#  define  HD_MAXBIGRING               50 /* For HD_BndInsideRing()           */

/**** Macros ****/

#  define  HD_Cube(X)                           ((X) * (X) * (X))
#  define  HD_Quad(X)                           ((X) * (X))
#  define  HD_MlpCalc(XYP, XYN, AREA, DOTS)     (HD_MLP_SCALE_FACTOR * (2.86E-2f * (XYP) + 1.52E-2f * (XYN)) * AREA / (DOTS))
#  define  HD_IsEven(X)                         (((X) & 1) == 0)
#  define  HD_IsOdd(X)                          (((X) & 1) != 0)
#  define  HD_ADDR(func)                        &func, "_" #func,

/**** Template class cast ****/

#  if defined(__BCPLUSPLUS__) && !defined(__clang__)
#    define  HD_TMCCAST
#  else
#    define  HD_TMCCAST                 class
#  endif

/**** Windows specific definitions ****/

#if defined(_WINDOWS) || defined(WINDOWS) || defined(_WIN32) || defined(_WIN32_) || defined(WIN32)
#  include <windows.h>
#  define  HD_DIRSEP               "\\"
#  define  HD_DIRSEPC              '\\'
#  define  HD_DIRSEPW              L"\\"
#  define  HD_FILE_CASEINS

#  ifndef WIN32
#    define  WIN32
#  endif

#  ifdef __BORLANDC__
#    ifndef strcasecmp
#      define  strcasecmp            stricmp
#    endif
#    ifndef strncasecmp
#      define  strncasecmp           strnicmp
#    endif
#  endif

#  ifdef _MSC_VER
#    ifndef strcasecmp
#      define  strcasecmp            _stricmp
#    endif
#    ifndef strncasecmp
#      define  strncasecmp           _strnicmp
#    endif
#  endif

#  define  HD_CALLBACK               WINAPI
#  define  HD_FASTCALL               __fastcall
#  define  HD_STACKCALL              __cdecl
#  define  HD_LITTLE_ENDIAN
#  define  HD_MAX_PATH               MAX_PATH
#  define  HDRIVE_USCOREV(X)         X

#  ifdef __GNUC__
#    define  HD_INLINE               __inline__
#  else
#    define  HD_INLINE               __inline
#  endif

/**** Windows DLL ****/

#  ifdef HDRIVE_DLL
#    define  HDRIVE_EXPORT            __cdecl
#    define  HDRIVE_EXPORTV           __cdecl
#    define  HDRIVE_EXTERN            __declspec(dllexport)
#  endif

#else

/**** Other operating systems ****/

#  define  HD_FASTCALL
#  define  HD_CALLBACK
#  define  HD_STACKCALL
#  define  HD_INLINE               __inline
#  define  HD_USE_DIRENT
#  define  HDRIVE_USCOREV(X)       X

#  ifdef AMIGA
#    define  HD_MAX_PATH           256
#    define  HD_FILE_CASEINS
#  else
#    ifndef PATH_MAX
#      define  PATH_MAX            4096
#    endif
#    define  HD_MAX_PATH           PATH_MAX
#  endif
#endif

/**** Linux x86 ****/

#ifdef linux
#  define  HD_LITTLE_ENDIAN
#  if defined(__x86_64__) || defined(__aarch64__)
#    define  HD_64BIT
#  endif
#endif

#  ifdef WIN64
#    define  HD_64BIT
#  endif

/**** Directory separator ****/

#  ifndef HD_DIRSEP
#    define  HD_DIRSEP                  "/"
#    define  HD_DIRSEPC                 '/'
#    define  HD_DIRSEPW                 L"/"
#  endif

#  define  HD_DIRSEP_AUTO               "\0"
#  define  HD_DIRSEP_AUTOC              0

#  ifndef AMIGA
#    define  HD_DIRSEP_AUTOW            L"\0"
#  endif

/**** CPU architecture ****/

#  if defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86) || defined(_X86_)
#    define  HD_CPUARCH_X86
#  endif

#  include <hdtypes.h>

/**** Error codes ****/

#  define  HD_ERR_NONE                  0 /* None                               */
#  define  HD_ERR_CONUNACCBD            1 /* Unacceptable bond order            */
#  define  HD_ERR_ILLPAR                2 /* Illegal parameters                 */
#  define  HD_ERR_OUTOFMEM              3 /* Out of memory                      */
#  define  HD_ERR_UNKCOVRAD             4 /* Unknown covalent radius            */
#  define  HD_ERR_UNKVDWRAD             5 /* Unknown VdW radius                 */
#  define  HD_ERR_NOATOMS               6 /* No atoms                           */
#  define  HD_ERR_NOTAVAILABLE          7 /* Not available                      */
#  define  HD_ERR_INVCHAR               8 /* Invalid character                  */
#  define  HD_ERR_STRTOOLONG            9 /* String too long                    */
#  define  HD_ERR_STRTOOSHORT          10 /* String too short                   */
#  define  HD_ERR_MATH                 11 /* Math error                         */

/**** Multithreading errors ****/

#  define  HD_ERR_MTH_CREATEMTX       101 /* Unable to create mutex             */
#  define  HD_ERR_MTH_CREATEBARRIER   102 /* Unable to create barrier           */
#  define  HD_ERR_MTH_CREATESEMAPHORE 103 /* Unable to create semaphore         */
#  define  HD_ERR_MTH_CREATETHREADS   104 /* Unable to create threads           */
#  define  HD_ERR_MTH_WAIT            105 /* Unable to wait                     */

/**** Force field parameters ****/

#  define  HD_ERR_PARAM_EMPTYLIST     201 /* The input list is empty            */
#  define  HD_ERR_PARAM_UNKFORMAT     202 /* Unknown file format                */

/**** Interchange File Format (IFF) ****/

#  define  HD_ERR_IFF_CSIZE           301 /* Invalid IFF chunk size             */
#  define  HD_ERR_IFF_FORMAT          302 /* Not in requested IFF format        */
#  define  HD_ERR_IFF_NOIFF           303 /* Invalid IFF file size              */
#  define  HD_ERR_IFF_SIZE            304 /* Invalid IFF file size              */

/**** I/O errors ****/

#  define  HD_ERR_IO_CANTCREATE       401 /* Can't create the file              */
#  define  HD_ERR_IO_CANTREAD         402 /* Can't perform read operation       */
#  define  HD_ERR_IO_CANTWRITE        403 /* Can't perform write operation      */
#  define  HD_ERR_IO_NOTFOUND         404 /* File/directory not found           */
#  define  HD_ERR_IO_NOTHINGTOSAVE    405 /* Nothing to save                    */
#  define  HD_ERR_IO_INVALIDPATH      406 /* Invalid path                       */
#  define  HD_ERR_IO_STAT             407 /* Stat error                         */
#  define  HD_ERR_IO_NOTALLOWED       408 /* Operation not allowed              */
#  define  HD_ERR_IO_UNKFORMAT        409 /* Unknown file format                */
#  define  HD_ERR_IO_DIRCREATE        410 /* Can't create the directory         */
#  define  HD_ERR_IO_DIRREMOVE        411 /* Can't remove the directory         */
#  define  HD_ERR_IO_FILEREMOVE       412 /* Can't remove the file              */
#  define  HD_ERR_IO_FILEMOVE         413 /* Can't rename/move the file         */
#  define  HD_ERR_IO_FILEEMPTY        414 /* Empty file                         */
#  define  HD_ERR_IO_EOF              415 /* End of file                        */

/**** RLE compression errors ****/

#  define  HD_ERR_RLE_DESTBUFOVF      501 /* Destination buffer overflow        */
#  define  HD_ERR_RLE_SRCBUFUEND      502 /* Unexpected end of source buffer    */

/**** Surface errors ****/

#  define  HD_ERR_SRF_ASIN            601 /* Invalid asin argument              */
#  define  HD_ERR_SRF_INVROTAX        602 /* Invalid rotation axis length       */
#  define  HD_ERR_SRF_INVVEC1SQLEN    603 /* Invalid vector 1 square length     */
#  define  HD_ERR_SRF_INVVEC2SQLEN    604 /* Invalid vector 2 square length     */
#  define  HD_ERR_SRF_TESSEL          605 /* Tassellation error                 */
#  define  HD_ERR_SRF_UNALLMODE       606 /* Unallowed mode                     */

/**** Energy engine errors ****/

#  define  HD_ERR_ENE_PARKEYILLTYPE   701 /* Illegal type of parameter key      */
#  define  HD_ERR_ENE_PARKEYUNK       702 /* Unknown parameter key              */
#  define  HD_ERR_ENE_PARNOTFOUND     703 /* Parameter not found                */
#  define  HD_ERR_ENE_PARVALUE        704 /* Illegal parameter value            */

/**** TCP/IP errors (see hdsocket.h, from 801)****/

/**** ATDL (see hdatdl.h, from 901) ****/

/**** Argument parser ****/

#  define  HD_ERR_ARG_BUFOVFL        1001 /* Argument buffer overflow           */
#  define  HD_ERR_ARG_NOPARSE        1002 /* Arguments not parsed               */
#  define  HD_ERR_ARG_INVNUM         1003 /* Invalid argument number            */
#  define  HD_ERR_ARG_UNBALQUOTES    1004 /* Unbalanced quotes                  */

/**** Charge (see hdcharge.h, from 1101) ****/

/**** Sequence errors (see hdseq.h, from 1201) ****/

/**** Isotopic errors (see hdisotopic.h, from 1301) ****/

/**** Linear regression errors (see hdlinreg.h, from 1401) ****/

/**** Matrix errors (see hdmatrix.h, from 1501) ****/

/**** Process errors (see hdprocess.h, from 1601 ****/

/**** Dynamic lybrary ****/

#  define  HD_ERR_DLL_FUNCADDR       1601 /* Can't obtain the function address  */
#  define  HD_ERR_DLL_NOTFOUND       1602 /* Library not found                  */

/**** OpenCL errors (see hdocl.h, from 1701) ****/

/**** Random number errors (see hdrandom.h, from 1801) ****/

/**** Regex errors (see hdregex.h, from 1900) ****/

/**** H-Bond check mode ****/

#  define HD_HBOND_CHK_NONE           0
#  define HD_HBOND_CHK_N              1
#  define HD_HBOND_CHK_O              2
#  define HD_HBOND_CHK_F              4
#  define HD_HBOND_CHK_S              8

#  define HD_HBOND_CHK_NO             (HD_HBOND_CHK_N|HD_HBOND_CHK_O)

/**** Flags for _HD_AtmsMeanPlane() ****/

#  define  HD_ATMMP_NONE              0 /* None                               */
#  define  HD_ATMMP_ACTIVEONLY        1 /* Active atom only                   */
#  define  HD_ATMMP_FIRSTMOL          2 /* Consider only the first molecule   */
#  define  HD_ATMMP_HEAVATOMS         4 /* Heavy atoms only                   */
#  define  HD_ATMMP_FIRSTSEG          8 /* Consider only the first segment    */

/**** Coordinate types for HD_AtmsCoordType() function ****/

#  define  HD_COORDTYP_0D             0 /* 0D => x = y = z = 0                */
#  define  HD_COORDTYP_1D             1 /* 1D => y = z = 0                    */
#  define  HD_COORDTYP_2D             2 /* 2D => z = 0                        */
#  define  HD_COORDTYP_3D             3 /* 3D                                 */
#  define  HD_COORDTYP_UNK            4 /* Unknown                            */

/**** Mass flags ****/

#  define  HD_MASS_ACTIVE             0  /* Active atoms only                 */
#  define  HD_MASS_ALL                1  /* All atoms                         */

/**** Flags for HD_MthCreateThreads() ****/

#  define  HD_MTH_THREADS_NONE        0 /* None                               */
#  define  HD_MTH_THREADS_SYNC        1 /* Synchronized start                 */
#  define  HD_MTH_THREADS_WAIT        2 /* Wait all threads                   */

/**** Surface calculation modes for _HD_SrfCalcNsc() ****/

#  define  HD_NSC_NONE                0 /* No flags                           */
#  define  HD_NSC_ACTATMONLY          1 /* Calc. the surface for active atoms */
#  define  HD_NSC_ATOM_AREA           2 /* Return the area for each atom      */
#  define  HD_NSC_DOTS                4 /* Return the dot list                */
#  define  HD_NSC_VOLUME              8 /* Return the volume                  */

/**** Flags for surface dot property calculation ****/

#  define  HD_SRFDOT_ALLATM           0 /* Consider all atoms                 */
#  define  HD_SRFDOT_NOINVATM         1 /* Exclude invisible atoms            */
#  define  HD_SRFDOT_ACTATMONLY       2 /* Active atoms only                  */
#  define  HD_SRFDOT_PSASMOOTH        4 /* Smooth the PSA                     */

/**** Default values for solid surface calculation ****/

#  define  HD_SRFSOL_DEF_TARGETVAL    0.475f
#  define  HD_SRFSOL_DEF_MESHSIZE     0.6f

/**** Flags for HD_ImproperFilter() function ****/

#  define  HD_IMPRFILTER_NONE         0 /* No filter                          */
#  define  HD_IMPRFILTER_ACTIVEONLY   1 /* Active impropers only              */
#  define  HD_IMPRFILTER_EXAROM       2 /* Exclude impropers in aromatic ring */
#  define  HD_IMPRFILTER_EXRING       4 /* Exclude impropers inside the rings */

/**** Flags for HD_TorsionFilter() function ****/

#  define  HD_TORFILTER_NONE          0 /* No filter                          */
#  define  HD_TORFILTER_REDUNDANT     1 /* Remove redundant torsions          */
#  define  HD_TORFILTER_FLEXIBLE      2 /* Keep flexible torsions             */
#  define  HD_TORFILTER_ACTIVEONLY    4 /* Active torsions only               */
#  define  HD_TORFILTER_OMEGA         8 /* Omega torsions                     */
#  define  HD_TORFILTER_PHI          16 /* Phi torsions                       */
#  define  HD_TORFILTER_PSI          32 /* Psi torsions                       */
#  define  HD_TORFILTER_AUTODOCK     64 /* AutoDock flexible torsions         */

/**** Callback function ****/

typedef HD_LONG (HD_CALLBACK *HD_CALLBACKFUNC)(HD_VOID *);

/**** Point list inside the surface box ****/

typedef struct _BoxSrf {
  struct _BoxSrf *      Ptr;            /* Ponter to the next element         */
  HD_SURFACE **         Dot;            /* Pointer to the face dot            */
} HD_FACEBOXSRF;

/**** Surface box ****/

typedef struct {
  HD_FACEBOXSRF *       FirstDot;       /* Fist dot in the box                */
  HD_FACEBOXSRF *       LastDot;        /* Last dot in the box                */
} HD_FACEBOX;

/**** HyperDrive features (see hdcpu.h) ****/

typedef struct {
  HD_LONG               Code;           /* Code flags                         */
  HD_LONG               Cpu;            /* Cpu optimization                   */
  const HD_CHAR *       CpuStr;         /* Cpu optimization (string)          */
  const HD_CHAR *       FeatStr;        /* Complete feature string            */
  HD_LONG               Simd;           /* SIMD optimization                  */
  HD_LONG               Reserved;       /* Reserved                           */
} HD_FEATURES;


/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE

/**** Atom ****/

#  define  HD_AtmBoxCalc                _HD_AtmBoxCalc
#  define  HD_AtmBoxCalcEx              _HD_AtmBoxCalcEx
#  define  HD_AtmCreateSeekTable        _HD_AtmCreateSeekTable
#  define  HD_AtmCreateSeekTableEx      _HD_AtmCreateSeekTableEx
#  define  HD_AtmDistance               _HD_AtmDistance
#  define  HD_AtmDistanceRec            _HD_AtmDistanceRec
#  define  HD_AtmDistanceSq             _HD_AtmDistanceSq
#  define  HD_AtmFlagsPop               _HD_AtmFlagsPop
#  define  HD_AtmFlagsPush              _HD_AtmFlagsPush
#  define  HD_AtmGetImpValence          _HD_AtmGetImpValence
#  define  HD_AtmGetHvyValence          _HD_AtmGetHvyValence
#  define  HD_AtmIsHbondAcceptor        _HD_AtmIsHbondAcceptor
#  define  HD_AtmIsHbondDonor           _HD_AtmIsHbondDonor
#  define  HD_AtmIsPolar                _HD_AtmIsPolar
#  define  HD_AtmPotClear               _HD_AtmPotClear
#  define  HD_AtmPotPop                 _HD_AtmPotPop
#  define  HD_AtmPotPush                _HD_AtmPotPush
#  define  HD_AtmsBoxBuild              _HD_AtmsBoxBuild
#  define  HD_AtmsBoxFree               _HD_AtmsBoxFree
#  define  HD_AtmsCalcGeoCent           _HD_AtmsCalcGeoCent
#  define  HD_AtmsCalcGeoCentEx         _HD_AtmsCalcGeoCentEx
#  define  HD_AtmsCalcGyrRad            _HD_AtmsCalcGyrRad
#  define  HD_AtmsCalcMassCent          _HD_AtmsCalcMassCent
#  define  HD_AtmsCoordType             _HD_AtmsCoordType
#  define  HD_AtmsMeanPlane             _HD_AtmsMeanPlane
#  define  HD_AtmsNormalize             _HD_AtmsNormalize
#  define  HD_AtmsNormalizeEx           _HD_AtmsNormalizeEx
#  define  HD_AtmsTranslate             _HD_AtmsTranslate
#  define  HD_AtmsTranslateEx           _HD_AtmsTranslateEx
#  define  HD_CipCalc                   _HD_CipCalc
#  define  HD_FindChiral                _HD_FindChiral
#  define  HD_FindEZ                    _HD_FindEZ
#  define  HD_FindMols                  _HD_FindMols
#  define  HD_FindRing                  _HD_FindRing
#  define  HD_FindRing3                 _HD_FindRing3
#  define  HD_FindRings                 _HD_FindRings
#  define  HD_ReportChirality           _HD_ReportChirality

/**** Bond ****/

#  define  HD_BndAngle                  _HD_BndAngle
#  define  HD_BndAnglef                 _HD_BndAnglef
#  define  HD_BndCheck                  _HD_BndCheck
#  define  HD_BndCheckLen               _HD_BndCheckLen
#  define  HD_BndInsideRing             _HD_BndInsideRing
#  define  HD_BndIsAnti                 _HD_BndIsAnti
#  define  HD_BndMake                   _HD_BndMake
#  define  HD_BndUnlink                 _HD_BndUnlink
#  define  HD_FixArom                   _HD_FixArom
#  define  HD_FixCarboxylate            _HD_FixCarboxylate

/**** Connectivity ****/

#  define  HD_AaTranslateName           _HD_AaTranslateName
#  define  HD_AssignCovRad              _HD_AssignCovRad
#  define  HD_AssignVdwRadToAtms        _HD_AssignVdwRadToAtms
#  define  HD_Connect                   _HD_Connect
#  define  HD_ConnectEx                 _HD_ConnectEx
#  define  HD_GetAtmByMass              _HD_GetAtmByMass
#  define  HD_GetAtmCovRad              _HD_GetAtmCovRad
#  define  HD_GetAtmElem                _HD_GetAtmElem
#  define  HD_GetAtmMass                _HD_GetAtmMass
#  define  HD_GetAtmNum                 _HD_GetAtmNum
#  define  HD_GetAtmVdwRad              _HD_GetAtmVdwRad

/**** Count ****/

#  define  HD_CountAngle                _HD_CountAngle
#  define  HD_CountAtm                  _HD_CountAtm
#  define  HD_CountBndHydrog            _HD_CountBndHydrog
#  define  HD_CountBond                 _HD_CountBond
#  define  HD_CountHbondAtm             _HD_CountHbondAtm
#  define  HD_CountHeavy                _HD_CountHeavy
#  define  HD_CountHydrog               _HD_CountHydrog
#  define  HD_CountImproper             _HD_CountImproper
#  define  HD_CountMols                 _HD_CountMols
#  define  HD_CountMolsReal             _HD_CountMolsReal
#  define  HD_CountMolsRealEx           _HD_CountMolsRealEx
#  define  HD_CountRes                  _HD_CountRes
#  define  HD_CountRings                _HD_CountRings
#  define  HD_CountSeg                  _HD_CountSeg
#  define  HD_CountTorsion              _HD_CountTorsion
#  define  HD_Formula                   _HD_Formula
#  define  HD_GenAngleMtx               _HD_GenAngleMtx
#  define  HD_GenBondMtx                _HD_GenBondMtx
#  define  HD_GenHbondMtx               _HD_GenHbondMtx
#  define  HD_GenImproperMtx            _HD_GenImproperMtx
#  define  HD_GenTorsionMtx             _HD_GenTorsionMtx
#  define  HD_ImproperFilter            _HD_ImproperFilter
#  define  HD_Mass                      _HD_Mass
#  define  HD_MassEx                    _HD_MassEx
#  define  HD_TorsionFilter             _HD_TorsionFilter

/**** CRC calculation ****/

#  define  HD_Crc16Mem                  _HD_Crc16Mem
#  define  HD_Crc16Str                  _HD_Crc16Str
#  define  HD_Crc32File                 _HD_Crc32File
#  define  HD_Crc32FileC                _HD_Crc32FileC
#  define  HD_Crc32Mem                  _HD_Crc32Mem
#  define  HD_Crc32Str                  _HD_Crc32Str
#  define  HD_Crc64File                 _HD_Crc64File
#  define  HD_Crc64FileC                _HD_Crc64FileC
#  define  HD_Crc64Mem                  _HD_Crc64Mem
#  define  HD_Crc64Str                  _HD_Crc64Str

/**** Fast Fourier Transformation ****/

#  define  HD_Dftf                      _HD_Dftf
#  define  HD_FastDftFreef              _HD_FastDftFreef
#  define  HD_FastDftf                  _HD_FastDftf
#  define  HD_FastDftpf                 _HD_FastDftpf
#  define  HD_FastDftInitf              _HD_FastDftInitf

/**** Generic functions ****/

#  define  HD_Bsearch                   _HD_Bsearch
#  define  HD_Close                     _HD_Close
#  define  HD_ErrCode                   _HD_ErrCode
#  define  HD_Flush                     _HD_Flush
#  define  HD_GetFeatures               _HD_GetFeatures
#  define  HD_GetVersion                _HD_GetVersion
#  define  HD_Init                      _HD_Init
#  define  HD_Is64bitOS                 _HD_Is64bitOS
#  define  HD_Isort                     _HD_Isort
#  define  HD_Qsort                     _HD_Qsort
#  define  HD_QsortP                    _HD_QsortP

/**** Memory managment ****/

#  define  HD_Alloca                    _HD_Alloca
#  define  HD_Calloc                    _HD_Calloc
#  define  HD_CallocMA                  _HD_CallocMA
#  define  HD_Free                      _HD_Free
#  define  HD_FreeMA                    _HD_FreeMA
#  define  HD_FreeSafe                  _HD_FreeSafe
#  define  HD_Malloc                    _HD_Malloc
#  define  HD_MallocMA                  _HD_MallocMA
#  define  HD_MallocTrim                _HD_MallocTrim
#  define  HD_MemCpy                    _HD_MemCpy
#  define  HD_MemStats                  _HD_MemStats
#  define  HD_MemZero                   _HD_MemZero
#  define  HD_Realloc                   _HD_Realloc

/**** Molecular Hydropathicity Index (ILM) ****/

#  define  HD_IlmCalc                   _HD_IlmCalc
#  define  HD_IlmCalcCutOff             _HD_IlmCalcCutOff
#  define  HD_WaterExclude              _HD_WaterExclude

/**** Multithreading ****/

#  define  HD_MthCloseBarrierEx         _HD_MthCloseBarrierEx
#  define  HD_MthCloseEventEx           _HD_MthCloseEventEx
#  define  HD_MthCloseMutexEx           _HD_MthCloseMutexEx
#  define  HD_MthCloseSemaphoreEx       _HD_MthCloseSemaphoreEx
#  define  HD_MthCloseThread            _HD_MthCloseThread
#  define  HD_MthCreateBarrierEx        _HD_MthCreateBarrierEx
#  define  HD_MthCreateEventEx          _HD_MthCreateEventEx
#  define  HD_MthCreateMutexEx          _HD_MthCreateMutexEx
#  define  HD_MthCreateSemaphoreEx      _HD_MthCreateSemaphoreEx
#  define  HD_MthCreateThread           _HD_MthCreateThread
#  define  HD_MthCreateThreads          _HD_MthCreateThreads
#  define  HD_MthDisable                _HD_MthDisable
#  define  HD_MthEnable                 _HD_MthEnable
#  define  HD_MthGetCPUs                _HD_MthGetCPUs
#  define  HD_MthMutexOffEx             _HD_MthMutexOffEx
#  define  HD_MthMutexOnEx              _HD_MthMutexOnEx
#  define  HD_MthReleaseSemaphoreEx     _HD_MthReleaseSemaphoreEx
#  define  HD_MthResetEventEx           _HD_MthResetEventEx
#  define  HD_MthSet                    _HD_MthSet
#  define  HD_MthSetEventEx             _HD_MthSetEventEx
#  define  HD_MthSetThreadAffinity      _HD_MthSetThreadAffinity
#  define  HD_MthStartWait              _HD_MthStartWait
#  define  HD_MthThreads                _HD_MthThreads
#  define  HD_MthWaitBarrierEx          _HD_MthWaitBarrierEx
#  define  HD_MthWaitEventEx            _HD_MthWaitEventEx
#  define  HD_MthWaitSemaphoreEx        _HD_MthWaitSemaphoreEx
#  define  HD_MthWaitThread             _HD_MthWaitThread
#  define  HD_MthWaitThreads            _HD_MthWaitThreads

/**** Residue ****/

#  define  HD_ResNamePop                _HD_ResNamePop
#  define  HD_ResNamePush               _HD_ResNamePush

/**** RLE de/compression ****/

#  define  HD_RlePack8                  _HD_RlePack8
#  define  HD_RleUnPack8                _HD_RleUnPack8

/**** Surface ****/

#  define  HD_GetBestHbAcc              _HD_GetBestHbAcc
#  define  HD_GetBestHbDon              _HD_GetBestHbDon
#  define  HD_SrfAlloc                  _HD_SrfAlloc
#  define  HD_SrfCalcNsc                _HD_SrfCalcNsc
#  define  HD_SrfDeep                   _HD_SrfDeep
#  define  HD_SrfDotDefColor            _HD_SrfDotDefColor
#  define  HD_SrfDotIlm                 _HD_SrfDotIlm
#  define  HD_SrfDotMlp                 _HD_SrfDotMlp
#  define  HD_SrfFree                   _HD_SrfFree
#  define  HD_SrfHbAcc                  _HD_SrfHbAcc
#  define  HD_SrfHbDon                  _HD_SrfHbDon
#  define  HD_SrfIlm                    _HD_SrfIlm
#  define  HD_SrfMep                    _HD_SrfMep
#  define  HD_SrfMlp                    _HD_SrfMlp
#  define  HD_SrfPsa                    _HD_SrfPsa
#  define  HD_SrfSolArea                _HD_SrfSolArea
#  define  HD_SrfSolCalc                _HD_SrfSolCalc
#  define  HD_SrfSortByAtm              _HD_SrfSortByAtm
#  define  HD_SrfVertexFace             _HD_SrfVertexFace

/**** Endian ****/

#  define  HD_SwapAddrDL                _HD_SwapAddrDL
#  define  HD_SwapAddrL                 _HD_SwapAddrL
#  define  HD_SwapAddrW                 _HD_SwapAddrW
#  define  HD_SwapDL                    _HD_SwapDL
#  define  HD_SwapL                     _HD_SwapL
#  define  HD_SwapUDL                   _HD_SwapUDL
#  define  HD_SwapUL                    _HD_SwapUL
#  define  HD_SwapUW                    _HD_SwapUW
#  define  HD_SwapW                     _HD_SwapW

#endif

#ifndef HDRIVE_EXTERN
#  define  HDRIVE_EXTERN        extern
#endif

#ifndef HDRIVE_EXPORT
#  define  HDRIVE_EXPORT
#endif

#ifndef HDRIVE_EXPORTV
#  define  HDRIVE_EXPORTV
#endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

/**** Atom ****/

HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_AtmBoxCalc(HD_ATOM *Atm, HD_FLOAT *VdwRadTable, HD_XYZF *Min, HD_XYZF *Max);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_AtmBoxCalcEx(HD_ATOM *Atm, HD_FLOAT *VdwRadTable, HD_XYZF *Min, HD_XYZF *Max, HD_LONG Flags);
HDRIVE_EXTERN HD_ATOM **          HDRIVE_EXPORT HD_AtmCreateSeekTable(HD_ATOM *InizAtm, HD_ULONG TotAtm);
HDRIVE_EXTERN HD_ATOM **          HDRIVE_EXPORT HD_AtmCreateSeekTableEx(HD_ULONG *SelAtms, HD_ATOM *InizAtm, HD_BOOL ExclAtm, HD_BOOL ActiveOnly, HD_BOOL ExclCentroids);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_AtmDistance(HD_ATOM *Atm1, HD_ATOM *Atm2);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_AtmDistanceRec(HD_ATOM *Atm1, HD_ATOM *Atm2);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_AtmDistanceSq(HD_ATOM *Atm1, HD_ATOM *Atm2);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_AtmFlagsPop(HD_ATOM *Atm, HD_LONG *FlagsBuf);
HDRIVE_EXTERN HD_LONG *           HDRIVE_EXPORT HD_AtmFlagsPush(HD_ATOM *Atm, HD_ULONG TotAtm);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_AtmGetHvyValence(HD_ATOM *Atm);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_AtmGetImpValence(HD_ATOM *Atm);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_AtmIsHbondAcceptor(HD_ATOM *Atm, HD_LONG Chk);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_AtmIsHbondDonor(HD_ATOM *Atm, HD_LONG Chk);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_AtmIsPolar(HD_ATOM *Atm);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_AtmPotClear(HD_ATOM *Atm, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_AtmPotPop(HD_ATOM *Atm, HD_DLONG *FFBuf);
HDRIVE_EXTERN HD_DLONG *          HDRIVE_EXPORT HD_AtmPotPush(HD_ATOM *Atm, HD_ULONG TotAtm);
HDRIVE_EXTERN HD_ATMSGRID *       HDRIVE_EXPORT HD_AtmsBoxBuild(HD_ATOM *InizAtm, HD_ULONG TotAtomi, HD_XYZF *DeltaCell, HD_XYZF *BoxSize, HD_FLOAT BoxLength,
                                                                HD_FLOAT MaxLength, HD_LONG MaxNumBox, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_AtmsBoxFree(HD_ATMSGRID *Grid);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_AtmsCalcGeoCent(HD_ATOM *Atm, HD_XYZF *Vect);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_AtmsCalcGeoCentEx(HD_ATOM *Atm, HD_XYZF *Vect, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_AtmsCalcGyrRad(HD_ATOM *Atm, HD_XYZF *MassCent, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_AtmsCalcMassCent(HD_ATOM *Atm, HD_XYZF *Vect, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_AtmsCoordType(HD_ATOM *Atm, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_AtmsMeanPlane(HD_ATOM *InizAtm, HD_DOUBLE *a, HD_DOUBLE *b, HD_DOUBLE *c, HD_LONG Flags);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_AtmsNormalize(HD_ATOM *Atm);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_AtmsNormalizeEx(HD_ATOM *Atm, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_AtmsTranslate(HD_ATOM *Atm, HD_XYZF *Vect);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_AtmsTranslateEx(HD_ATOM *Atm, HD_XYZF *Vect, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_ULONG *          HDRIVE_EXPORT HD_CipCalc(HD_ATOM *InizAtm, HD_ULONG TotAtomi);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_FindChiral(HD_ATOM *InizAtm, HD_ULONG TotAtomi);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_FindEZ(HD_ATOM *InizAtm, HD_ULONG TotAtomi);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_FindMols(HD_ATOM **InizAtm, HD_ATOM **LastAtm, HD_ULONG TotAtm);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_FindRing(HD_QCHAR *Ring, HD_ATOM *AtmMtr[][HD_MAXRINGSIZE], HD_ATOM *Atm);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_FindRing3(HD_ATOM **AtmMtr, HD_ATOM *Atm);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_FindRings(HD_ATOM *InizAtm);
HDRIVE_EXTERN HD_BYTE             HDRIVE_EXPORT HD_ReportChirality(HD_ULONG *Vgid, HD_ATOM *Atm);

/**** Bond ****/

HDRIVE_EXTERN HD_DOUBLE           HDRIVE_EXPORT HD_BndAngle(HD_ATOM *Atm1, HD_ATOM *Atm2, HD_ATOM *Atm3);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_BndAnglef(HD_ATOM *Atm1, HD_ATOM *Atm2, HD_ATOM *Atm3);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_BndCheck(HD_ATOM *Atm1, HD_ATOM *Atm2, HD_UBYTE *Type);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_BndCheckLen(HD_ATOM *InizAtm, HD_ULONG TotAtm, HD_FLOAT MaxTol, HD_FLOAT MinTol, HD_BNDLENCALLBACK CallBack, HD_BOOL ActiveOnly, void *UserArg);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_BndInsideRing(HD_ATOM *Atm1, HD_ATOM *Atm2, HD_ATOM **Path, HD_ULONG MaxPathLen);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_BndIsAnti(HD_ATOM *a, HD_ATOM *b, HD_ATOM *c, HD_ATOM *d);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_BndMake(HD_ATOM *, HD_ATOM *, HD_BYTE);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_BndUnlink(HD_ATOM *Atm1, HD_ATOM *Atm2);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_FixArom(HD_ATOM *Atm, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_FixCarboxylate(HD_ATOM *Atm, HD_BOOL ActiveOnly);

/**** Connectivity ****/

HDRIVE_EXTERN HD_QCHAR            HDRIVE_EXPORT HD_AaTranslateName(HD_QCHAR ResName);
HDRIVE_EXTERN HD_FLOAT *          HDRIVE_EXPORT HD_AssignCovRad(HD_ATOM *InizAtm, HD_ULONG TotAtm);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_AssignVdwRadToAtms(HD_ATOM *InizAtm, HD_FLOAT ProRad, HD_ATOMCALLBACK PrintHook);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_Connect(HD_ATOM *InizAtm, HD_ULONG TotAtm, HD_FLOAT ConnTol, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_ConnectEx(HD_ULONG *Bumps, HD_ATOM *InizAtm, HD_ULONG TotAtm, HD_FLOAT ConnTol, HD_BOOL ActiveOnly, HD_BUMPCALLBACK BumpHook);
HDRIVE_EXTERN HD_WORD             HDRIVE_EXPORT HD_GetAtmByMass(HD_FLOAT MassF);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_GetAtmCovRad(HD_UWORD Elem);
HDRIVE_EXTERN HD_WORD             HDRIVE_EXPORT HD_GetAtmElem(HD_UWORD AtmNum);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_GetAtmMass(HD_UWORD Elem);
HDRIVE_EXTERN HD_UWORD            HDRIVE_EXPORT HD_GetAtmNum(HD_UWORD Elem);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_GetAtmVdwRad(HD_UWORD Elem);

/**** Count ****/

HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_CountAngle(HD_ATOM *Atm);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_CountAtm(HD_ATOM *Atm, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_CountBndHydrog(HD_ATOM *Atm);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_CountBond(HD_ATOM *Atm, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_CountHbondAtm(HD_BOOL Acceptor, HD_ATOM *InizAtm, HD_LONG Chk, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_CountHeavy(HD_ATOM *Atm, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_CountHydrog(HD_ATOM *Atm, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_CountImproper(HD_ATOM *Atm);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_CountMols(HD_ATOM *Atm);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_CountMolsReal(HD_ATOM *Atm, HD_ULONG TotAtm);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_CountMolsRealEx(HD_ULONG *ActMol, HD_ATOM *Atm, HD_ULONG TotAtm);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_CountRes(HD_ATOM *Atm);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_CountRings(HD_ATOM *InizAtm, HD_ULONG TotAtm);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_CountSeg(HD_ATOM *Atm);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_CountTorsion(HD_ATOM **Bond);
HDRIVE_EXTERN HD_CHAR *           HDRIVE_EXPORT HD_Formula(HD_ATOM *Atm);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_GenAngleMtx(HD_ATOM *Atm, HD_ATOM ***AngleMtx);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_GenBondMtx(HD_ATOM *Atm, HD_ATOM ***BondMtx);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_GenHbondMtx(HD_ATOM *InizAtm, HD_ATOM ***AcceptorMtx, HD_ULONG *Acceptors, HD_ATOM ***DonorMtx,
                                                               HD_ULONG *Donors, HD_LONG AccChk, HD_LONG DonChk, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_GenImproperMtx(HD_ATOM *Atm, HD_ATOM ***ImproperMtx);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_GenTorsionMtx(HD_ATOM **Bond, HD_ATOM ***TorsionMtx);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_ImproperFilter(HD_ATOM ***ImproperMtx, HD_ULONG *TotImproper, HD_LONG Flags);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_Mass(HD_ATOM *InizAtm);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_MassEx(HD_ATOM *InizAtm, HD_LONG Flags);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_TorsionFilter(HD_ATOM ***TorsionMtx, HD_ULONG *TotTor, HD_ULONG TotAtm, HD_LONG Flags);

/**** CRC calculation ****/

HDRIVE_EXTERN HD_UWORD            HDRIVE_EXPORT HD_Crc16Mem(const HD_VOID *MemPtr, HD_UWORD Size);
HDRIVE_EXTERN HD_UWORD            HDRIVE_EXPORT HD_Crc16Str(const HD_CHAR *Str);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_Crc32File(HD_ULONG *Crc32, HD_STRING FileName);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_Crc32FileC(HD_ULONG *Crc32, const HD_CHAR *FileName);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_Crc32Mem(const HD_VOID *MemPtr, HD_ULONG Size);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_Crc32Str(const HD_CHAR *Str);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_Crc64File(HD_UDLONG *Crc64, HD_STRING FileName);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_Crc64FileC(HD_UDLONG *Crc64, const HD_CHAR *FileName);
HDRIVE_EXTERN HD_UDLONG           HDRIVE_EXPORT HD_Crc64Mem(const HD_VOID *MemPtr, HD_ULONG Size);
HDRIVE_EXTERN HD_UDLONG           HDRIVE_EXPORT HD_Crc64Str(const HD_CHAR *Str);

/**** Fast Fourier Transformation ****/

HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_Dftf(HD_FLOAT *x1, HD_FLOAT *y1, HD_FLOAT *Mag, HD_ULONG m, HD_FLOAT Dir);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_FastDftf(HD_FLOAT *x1, HD_FLOAT *y1, HD_HANDLE DH, HD_FLOAT Dir);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_FastDftpf(HD_FLOAT *x1, HD_FLOAT *y1, HD_HANDLE DH, HD_FLOAT Dir);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_FastDftFreef(HD_HANDLE DH);
HDRIVE_EXTERN HD_HANDLE           HDRIVE_EXPORT HD_FastDftInitf(HD_LONG Size, HD_FLOAT Dir);

/**** Generic functions ****/

HDRIVE_EXTERN HD_VOID *           HDRIVE_EXPORT HD_Bsearch(HD_VOID *Key, HD_VOID *BaseP, HD_ULONG Elem, HD_ULONG Width,
                                                           HD_SORTCALLBACK Fcmp);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_Close(HD_VOID);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_ErrCode(HD_VOID);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_Flush(HD_VOID);
HDRIVE_EXTERN const HD_FEATURES * HDRIVE_EXPORT HD_GetFeatures(HD_VOID);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_GetVersion(HD_ULONG *Version, HD_ULONG *Revision);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_Init(HD_VOID);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_Is64bitOS(HD_VOID);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_Isort(HD_VOID *BaseP, HD_ULONG Elem, HD_ULONG Width, HD_SORTCALLBACK Fcmp);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_Qsort(HD_VOID *BaseP, HD_ULONG Elem, HD_ULONG Width, HD_SORTCALLBACK Fcmp);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_QsortP(HD_VOID *BaseP, HD_ULONG Elem, HD_ULONG Width, HD_SORTCALLBACK Fcmp);


/**** Memory managment ****/

HDRIVE_EXTERN HD_VOID *           HDRIVE_EXPORT HD_Alloca(HD_ULONG Size);
HDRIVE_EXTERN HD_VOID *           HDRIVE_EXPORT HD_Calloc(HD_ULONG Size);
HDRIVE_EXTERN HD_VOID *           HDRIVE_EXPORT HD_CallocMA(HD_ULONG Size, HD_ULONG Align);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_Free(HD_VOID *Addr);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_FreeMA(HD_VOID *Addr);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_FreeSafe(HD_VOID *Addr);
HDRIVE_EXTERN HD_VOID *           HDRIVE_EXPORT HD_Malloc(HD_ULONG Size);
HDRIVE_EXTERN HD_VOID *           HDRIVE_EXPORT HD_MallocMA(HD_ULONG Size, HD_ULONG Align);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_MallocTrim(HD_VOID);
HDRIVE_EXTERN HD_VOID *           HDRIVE_EXPORT HD_MemCpy(HD_VOID *Dest, const HD_VOID *Src, HD_ULONG Count);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_MemStats(HD_MEMSTATS *Stats);
HDRIVE_EXTERN HD_VOID *           HDRIVE_EXPORT HD_MemZero(HD_VOID *Dest, HD_ULONG Count);
HDRIVE_EXTERN HD_VOID *           HDRIVE_EXPORT HD_Realloc(HD_VOID *Old, HD_ULONG Size);

/**** Molecular Hydropathicity Index (ILM) ****/

HDRIVE_EXTERN HD_DOUBLE           HDRIVE_EXPORT HD_IlmCalc(HD_ATOM *Atm, HD_DOUBLE IlmCutOff, HD_LONG Flags);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_IlmCalcCutOff(HD_ATOM *InizAtm);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_WaterExclude(HD_ATOM *InizAtm);

/**** Multithreading ****/

HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_MthCloseBarrierEx(HD_BARRIER Bh);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_MthCloseEventEx(HD_EVENT hEvent);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_MthCloseMutexEx(HD_MUTEX Mutex);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_MthCloseSemaphoreEx(HD_SEMAPHORE Sem);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_MthCloseThread(HD_THREAD ThreadHandle);
HDRIVE_EXTERN HD_BARRIER          HDRIVE_EXPORT HD_MthCreateBarrierEx(HD_LONG Count);
HDRIVE_EXTERN HD_EVENT            HDRIVE_EXPORT HD_MthCreateEventEx(HD_BOOL InitState, HD_BOOL Auto);
HDRIVE_EXTERN HD_MUTEX            HDRIVE_EXPORT HD_MthCreateMutexEx(HD_VOID);
HDRIVE_EXTERN HD_SEMAPHORE        HDRIVE_EXPORT HD_MthCreateSemaphoreEx(HD_LONG MaxCount);
HDRIVE_EXTERN HD_THREAD           HDRIVE_EXPORT HD_MthCreateThread(HD_LONG (HD_CALLBACK *Routine)(HD_VOID *), HD_VOID *Args);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_MthCreateThreads(HD_LONG Threads, HD_LONG (HD_CALLBACK *Routine)(HD_VOID *), HD_VOID *Args, HD_LONG Flags);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_MthDisable(HD_VOID);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_MthEnable(HD_VOID);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_MthGetCPUs(HD_VOID);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_MthMutexOffEx(HD_MUTEX Mutex);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_MthMutexOnEx(HD_MUTEX Mutex);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_MthReleaseSemaphoreEx(HD_SEMAPHORE Sem);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_MthResetEventEx(HD_EVENT hEvent);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_MthSet(HD_ULONG Threads);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_MthSetEventEx(HD_EVENT hEvent);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_MthSetThreadAffinity(HD_THREAD ThreadHandle, HD_LONG LogicalCpuNumber);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_MthStartWait(HD_VOID);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_MthThreads(HD_VOID);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_MthWaitBarrierEx(HD_BARRIER Bh);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_MthWaitEventEx(HD_EVENT hEvent);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_MthWaitSemaphoreEx(HD_SEMAPHORE Sem);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_MthWaitThread(HD_THREAD ThreadHandle);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_MthWaitThreads(HD_THREAD *ThreadHandles, HD_ULONG Num, HD_LONG *ReturnCode);

/**** Residue ****/

HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_ResNamePop(HD_ATOM *Atm, HD_LONG *ResNameBuf);
HDRIVE_EXTERN HD_LONG *           HDRIVE_EXPORT HD_ResNamePush(HD_ATOM *Atm, HD_ULONG TotAtm);

/**** RLE de/compression ****/

HDRIVE_EXTERN HD_UBYTE *          HDRIVE_EXPORT HD_RlePack8(HD_ULONG *DestSize, HD_UBYTE *Src, HD_ULONG SrcSize);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_RleUnPack8(HD_UBYTE *Dest, HD_ULONG DestSize, HD_UBYTE *Src , HD_ULONG SrcSize);

/**** Surface ****/

HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_GetBestHbAcc(HD_FLOAT Dist);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_GetBestHbDon(HD_FLOAT Dist);
HDRIVE_EXTERN HD_SURFACE *        HDRIVE_EXPORT HD_SrfAlloc(HD_SURFACE **, HD_SURFACE **);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_SrfCalcNsc(HD_ATOM **SeekTable, HD_LONG nat, HD_LONG densit,
                                                              HD_FLOAT ProbeRad, HD_LONG mode, HD_DOUBLE *value_of_area,
                                                              HD_DOUBLE *value_of_parea,  HD_DOUBLE **at_area, HD_DOUBLE *value_of_vol,
                                                              HD_SURFACE **NewSrf, HD_ULONG *nu_dots);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_SrfDeep(HD_SURFACE *InizSrf, HD_ULONG TotSrf, HD_ATOM *InizAtm, HD_LONG Flags);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_SrfFree(HD_SURFACE *);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_SrfDotDefColor(HD_UBYTE *NewDefColor);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_SrfDotIlm(HD_ATOM *Atm, HD_FLOAT X, HD_FLOAT Y, HD_FLOAT Z, HD_DOUBLE IlmCutOff);
HDRIVE_EXTERN HD_FLOAT            HDRIVE_EXPORT HD_SrfDotMlp(HD_ATOM *Atm, HD_FLOAT X, HD_FLOAT Y, HD_FLOAT Z, HD_LONG Flags, HD_FLOAT *Contrib);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_SrfHbAcc(HD_SURFACE *InizSrf, HD_ULONG TotSrf, HD_ATOM *InizAtm, HD_LONG Flags);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_SrfHbDon(HD_SURFACE *InizSrf, HD_ULONG TotSrf, HD_ATOM *InizAtm, HD_LONG Flags);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_SrfIlm(HD_SURFACE *InizSrf, HD_ULONG TotSrf, HD_ATOM *InizAtm, HD_LONG Flags);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_SrfMep(HD_SURFACE *InizSrf, HD_ULONG TotSrf, HD_ATOM *InizAtm, HD_LONG Flags);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_SrfMlp(HD_FLOAT *VlogP, HD_SURFACE *InizSrf, HD_ULONG TotSrf, HD_ATOM *InizAtm, HD_FLOAT Area, HD_FLOAT *Contrib, HD_LONG Flags);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_SrfPsa(HD_SURFACE *InizSrf, HD_ULONG TotSrf, HD_ATOM *InizAtm, HD_LONG Flags);
HDRIVE_EXTERN HD_DOUBLE           HDRIVE_EXPORT HD_SrfSolArea(HD_DOUBLE *AreaP, HD_ATOM *InizAtm, HD_SURFACE **Faces, HD_ULONG TotFaces);
HDRIVE_EXTERN HD_SURFACE *        HDRIVE_EXPORT HD_SrfSolCalc(HD_SURFACE ***Faces, HD_ULONG *TotFaces, HD_SURFACE **LastDot, HD_ULONG *TotDot,
                                                              HD_FLOAT **Normals, HD_ATOM *InizAtm, HD_ULONG TotAtm, HD_FLOAT ProbeRad,
                                                              HD_FLOAT MeshSize, HD_FLOAT fTargetValue, HD_BOOL ActiveOnly);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_SrfSortByAtm(HD_SURFACE **InizSrf);
HDRIVE_EXTERN HD_SURFACE **       HDRIVE_EXPORT HD_SrfVertexFace(HD_SURFACE **InizSrf, HD_SURFACE **LastDot, HD_LONG *TotSrf);

/**** Endian ****/

HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_SwapAddrDL(HD_VOID *Val);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_SwapAddrL(HD_VOID *Val);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_SwapAddrW(HD_VOID *Val);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_SwapL(HD_LONG Val);
HDRIVE_EXTERN HD_DLONG            HDRIVE_EXPORT HD_SwapDL(HD_DLONG Val);
HDRIVE_EXTERN HD_UDLONG           HDRIVE_EXPORT HD_SwapUDL(HD_UDLONG Val);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_SwapUL(HD_ULONG Val);
HDRIVE_EXTERN HD_UWORD            HDRIVE_EXPORT HD_SwapUW(HD_UWORD Val);
HDRIVE_EXTERN HD_WORD             HDRIVE_EXPORT HD_SwapW(HD_WORD Val);

#  ifdef __cplusplus
   }
#  endif
#endif

