
/*********************************************
****   HyperDrive - Sequence management   ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifndef __HDSEQ_H
#  define  __HDSEQ_H

#  include <hyperdrive.h>
#  include <hdstring.h>

/**** Load flags ****/

#  define  HD_SEQLOAD_FILE              1 /* Load from file                     */
#  define  HD_SEQLOAD_MEM               2 /* Load from memory                   */

/**** Amino acid IDs ****/

#  define HD_SEQALIGN_AAID_MIN          1  /* Lowest amino acid ID              */
#  define HD_SEQALIGN_AAID_MAX         20  /* Highest amino acid ID             */

/**** Alignment constant ****/

#  define HD_SEQALIGN_PROT_GEP          1 /* Protein gap extension penality     */
#  define HD_SEQALIGN_PROT_GOP         12 /* Protein gap opening penality       */
#  define HD_SEQALIGN_PROT_GML         20 /* Protein gap min. lenght            */
#  define HD_SEQALIGN_PROT_MISWEIGTH   -1 /* Mismatch weight (not used)         */

#  define HD_SEQALIGN_NA_GEP            3 /* Nucleic gap extension penality     */
#  define HD_SEQALIGN_NA_GOP           -1 /* Nucleic gap opening penality       */
#  define HD_SEQALIGN_NA_GML           60 /* Nucleic gap min. lenght            */
#  define HD_SEQALIGN_NA_MISWEIGTH     -1 /* Mismatch weight                    */

/**** Sequence errors ****/

#  define  HD_ERR_SEQ_GEP            1201 /* Gap extension penality must >= 0   */
#  define  HD_ERR_SEQ_GOP            1202 /* Gap opening penality must >= 0     */
#  define  HD_ERR_SEQ_MINLEN         1203 /* Minimum length must >= 1           */
#  define  HD_ERR_SEQ_MISWEIGHT      1204 /* Mismatch weight must < 0           */
#  define  HD_ERR_SEQ_MTXFILE        1205 /* Unknown matrix file format         */
#  define  HD_ERR_SEQ_NUM            1206 /* At least two sequence required     */

/**** Sequence ****/

typedef struct __hd_seq {
  struct __hd_seq *     Next;           /* Pointer to next element            */
  struct __hd_seq *     Prev;           /* Pointer to prevoius element        */
  HD_STRING             Name;           /* Sequence name                      */
  HD_STRING             Seq;            /* Sequence                           */
} HD_SEQ;

/**** Substitution matrix ****/

typedef struct {
  HD_STRING             Name;           /* Matrix name                        */
  HD_STRING             Ruler;          /* Matrix ruler                       */
  HD_LONG               m[128][128];    /* Matrix elements                    */
  HD_LONG               Match;          /* Match (max) value                  */
  HD_LONG               Mismh;          /* Mismatch (min) value               */
} HD_SUBMTX;

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_SeqA2AAA                _HD_SeqA2AAA
#    define  HD_SeqA2Id                 _HD_SeqA2Id
#    define  HD_SeqAAA2A                _HD_SeqAAA2A
#    define  HD_SeqAAA2Id               _HD_SeqAAA2Id
#    define  HD_SeqAdd                  _HD_SeqAdd
#    define  HD_SeqB2BBB                _HD_SeqB2BBB
#    define  HD_SeqB2Id                 _HD_SeqB2Id
#    define  HD_SeqBBB2B                _HD_SeqBBB2B
#    define  HD_SeqBBB2Id               _HD_SeqBBB2Id
#    define  HD_SeqFree                 _HD_SeqFree
#    define  HD_SeqId2A                 _HD_SeqId2A
#    define  HD_SeqId2AAA               _HD_SeqId2AAA
#    define  HD_SeqId2B                 _HD_SeqId2B
#    define  HD_SeqId2BBB               _HD_SeqId2BBB
#    define  HD_SeqLoad                 _HD_SeqLoad
#    define  HD_SubMatrixBuild          _HD_SubMatrixBuild
#    define  HD_SubMatrixCopy           _HD_SubMatrixCopy
#    define  HD_SubMatrixFree           _HD_SubMatrixFree
#    define  HD_SubMatrixLoad           _HD_SubMatrixLoad
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT HD_SeqA2AAA(HD_CHAR ResName);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT HD_SeqA2Id(HD_CHAR ResName);
HDRIVE_EXTERN HD_CHAR           HDRIVE_EXPORT HD_SeqAAA2A(HD_LONG ResName);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT HD_SeqAAA2Id(HD_LONG ResName);
HDRIVE_EXTERN HD_SEQ *          HDRIVE_EXPORT HD_SeqAdd(HD_LIST *SeqList, const HD_CHAR *Name, const HD_CHAR *SeqStr);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT HD_SeqB2BBB(HD_CHAR ResName);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT HD_SeqB2Id(HD_CHAR ResName);
HDRIVE_EXTERN HD_CHAR           HDRIVE_EXPORT HD_SeqBBB2B(HD_LONG ResName);
HDRIVE_EXTERN HD_LONG           HDRIVE_EXPORT HD_SeqBBB2Id(HD_LONG ResName);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_SeqFree(HD_LIST *SeqList);
HDRIVE_EXTERN HD_CHAR           HDRIVE_EXPORT HD_SeqId2A(HD_LONG Id, HD_BOOL D);
HDRIVE_EXTERN HD_QCHAR *        HDRIVE_EXPORT HD_SeqId2AAA(HD_LONG Id, HD_BOOL D);
HDRIVE_EXTERN HD_CHAR           HDRIVE_EXPORT HD_SeqId2B(HD_LONG Id);
HDRIVE_EXTERN HD_QCHAR *        HDRIVE_EXPORT HD_SeqId2BBB(HD_LONG Id);
HDRIVE_EXTERN HD_LIST *         HDRIVE_EXPORT HD_SeqLoad(const HD_CHAR *FileName, HD_LONG Flags);
HDRIVE_EXTERN HD_SUBMTX *       HDRIVE_EXPORT HD_SubMatrixBuild(HD_LONG Ms);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_SubMatrixCopy(HD_SUBMTX *DestMtx, HD_SUBMTX *SrcMtx);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_SubMatrixFree(HD_SUBMTX *Mtx);
HDRIVE_EXTERN HD_SUBMTX *       HDRIVE_EXPORT HD_SubMatrixLoad(const HD_CHAR *FileName);

#  ifdef __cplusplus
   }
#  endif
#endif
