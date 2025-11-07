
/*******************************************
****     HyperDrive - Cpu detection     ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#ifndef __HD_CPU_H
#  define  __HD_CPU_H

#  include <hyperdrive.h>

/**** HyperDrive SIMD features ****/

#define  HD_FEAT_SIMD_NONE       0      /* None                               */
#define  HD_FEAT_SIMD_3DNOW      1      /* 3DNow!                             */
#define  HD_FEAT_SIMD_3DNOWPRO   2      /* Enhanced 3DNow!                    */
#define  HD_FEAT_SIMD_ALTIVEC    4      /* AltiVec                            */
#define  HD_FEAT_SIMD_MMX        8      /* MMX                                */
#define  HD_FEAT_SIMD_SSE       16      /* SSE                                */
#define  HD_FEAT_SIMD_SSE2      32      /* SSE 2                              */
#define  HD_FEAT_SIMD_SSE3      64      /* SSE 3                              */

/**** HyperDrive CPU features ****/

#define  HD_FEAT_CPU_UNK         0      /* Unknown CPU                        */
#define  HD_FEAT_CPU_I386        1      /* Intel 80386                        */
#define  HD_FEAT_CPU_I486        2      /* Intel 80486                        */
#define  HD_FEAT_CPU_I586        3      /* Intel Pentium                      */
#define  HD_FEAT_CPU_I686        4      /* Intel Pentium Pro / Pentium II     */
#define  HD_FEAT_CPU_IP3         5      /* Intel Pentium III                  */
#define  HD_FEAT_CPU_IP4         6      /* Intel Pentium IV                   */
#define  HD_FEAT_CPU_ICORE2      7      /* Intel Core 2                       */

#define  HD_FEAT_CPU_AMDK5     101      /* AMD K5                             */
#define  HD_FEAT_CPU_AMDK6     102      /* AMD K6                             */
#define  HD_FEAT_CPU_AMDK6II   103      /* AMD K6 II 3D / K6 III 3D           */
#define  HD_FEAT_CPU_AMDK7     104      /* AMD Duron / Athlon                 */
#define  HD_FEAT_CPU_AMDK7XP   105      /* AMD Athlon 4 / XP / MP             */
#define  HD_FEAT_CPU_AMDK8     106      /* AMD Athlon 64 / FX / Opteron       */

#define  HD_FEAT_CPU_VIAC3     201      /* VIA C3                             */
#define  HD_FEAT_CPU_VIAC3_2   202      /* VIA C3-2                           */

#define  HD_FEAT_CPU_IDTWC6    301      /* IDT Winchip C6                     */
#define  HD_FEAT_CPU_IDTW2     302      /* IDT Winchip 2                      */

#define  HD_FEAT_CPU_MC000     401      /* Motorola 68000                     */
#define  HD_FEAT_CPU_MC020     402      /* Motorola 68020                     */
#define  HD_FEAT_CPU_MC020881  403      /* Motorola 68020 / 68881             */
#define  HD_FEAT_CPU_MC030     404      /* Motorola 68030                     */
#define  HD_FEAT_CPU_MC030881  405      /* Motorola 68030 / 68881             */
#define  HD_FEAT_CPU_MC040     406      /* Motorola 68040                     */
#define  HD_FEAT_CPU_MC060     406      /* Motorola 68060                     */

#define  HD_FEAT_CPU_R3000     501      /* MIPS R3000                         */
#define  HD_FEAT_CPU_R4400     502      /* MIPS R4400                         */
#define  HD_FEAT_CPU_R8000     503      /* MIPS R8000                         */

#define  HD_FEAT_CPU_ARM       601      /* ARM                                */

/**** HyperDrive code features ****/

#define  HD_FEAT_CODE_NONE      0       /* None                               */
#define  HD_FEAT_CODE_16        1       /* 16 bit code                        */
#define  HD_FEAT_CODE_32        2       /* 32 bit code                        */
#define  HD_FEAT_CODE_64        4       /* 64 bit code                        */
#define  HD_FEAT_CODE_PARALLEL  8       /* Parallel code                      */

/**** CPU information ****/

typedef struct __hd_cpuinfo {
  HD_ULONG              Size;           /* Structure length                   */
  HD_ULONG              Cores;          /* Total cores                        */
  HD_ULONG              Groups;         /* Processor groups (Windows only)    */
  HD_ULONG              Logical;        /* Logical CPUs                       */
  HD_ULONG              NumaNodes;      /* NUMA nodes                         */
  HD_ULONG              Sockets;        /* CPU sockets                        */
} HD_CPUINFO;


/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_GetCpuInfo              _HD_GetCpuInfo
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_GetCpuInfo(HD_CPUINFO *Info);

#  ifdef __cplusplus
   }
#  endif
#endif

