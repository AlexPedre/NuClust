
/**************************************************
**** HyperDrive - Windows compatibility header ****
****    (c) 2004-2025, Alessandro Pedretti     ****
**************************************************/


#ifndef __WINCOMP_H
#  define  __WINCOMP_H

#  ifdef WIN32

/**** For compatibility with old headers ****/

#    ifndef CACHE_FULLY_ASSOCIATIVE
typedef ULONG_PTR  KAFFINITY;

typedef enum _LOGICAL_PROCESSOR_RELATIONSHIP {
    RelationProcessorCore,
    RelationNumaNode,
    RelationCache,
    RelationProcessorPackage,
    RelationGroup,
    RelationAll = 0xffff
} LOGICAL_PROCESSOR_RELATIONSHIP;

typedef enum _PROCESSOR_CACHE_TYPE {
    CacheUnified,
    CacheInstruction,
    CacheData,
    CacheTrace
} PROCESSOR_CACHE_TYPE;
#    endif

#    if (WINVER <= 0x0502)
typedef struct _GROUP_AFFINITY {
  KAFFINITY                       Mask;
  WORD                            Group;
  WORD                            Reserved[3];
} GROUP_AFFINITY, *PGROUP_AFFINITY;

typedef struct _PROCESSOR_RELATIONSHIP {
  BYTE                            Flags;
  BYTE                            EfficiencyClass;
  BYTE                            Reserved[20];
  WORD                            GroupCount;
  GROUP_AFFINITY                  GroupMask[ANYSIZE_ARRAY];
} PROCESSOR_RELATIONSHIP, *PPROCESSOR_RELATIONSHIP;

typedef struct _NUMA_NODE_RELATIONSHIP {
  DWORD                           NodeNumber;
  BYTE                            Reserved[20];
  GROUP_AFFINITY                  GroupMask;
} NUMA_NODE_RELATIONSHIP, *PNUMA_NODE_RELATIONSHIP;

typedef struct _CACHE_RELATIONSHIP {
  BYTE                            Level;
  BYTE                            Associativity;
  WORD                            LineSize;
  DWORD                           CacheSize;
  PROCESSOR_CACHE_TYPE            Type;
  BYTE                            Reserved[20];
  GROUP_AFFINITY                  GroupMask;
} CACHE_RELATIONSHIP, *PCACHE_RELATIONSHIP;

typedef struct _PROCESSOR_GROUP_INFO {
  BYTE                            MaximumProcessorCount;
  BYTE                            ActiveProcessorCount;
  BYTE                            Reserved[38];
  KAFFINITY                       ActiveProcessorMask;
} PROCESSOR_GROUP_INFO, *PPROCESSOR_GROUP_INFO;

typedef struct _GROUP_RELATIONSHIP {
  WORD                            MaximumGroupCount;
  WORD                            ActiveGroupCount;
  BYTE                            Reserved[20];
  PROCESSOR_GROUP_INFO            GroupInfo[ANYSIZE_ARRAY];
} GROUP_RELATIONSHIP, *PGROUP_RELATIONSHIP;

typedef struct _SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX {
  LOGICAL_PROCESSOR_RELATIONSHIP Relationship;
  DWORD                           Size;
  union {
    PROCESSOR_RELATIONSHIP        Processor;
    NUMA_NODE_RELATIONSHIP        NumaNode;
    CACHE_RELATIONSHIP            Cache;
    GROUP_RELATIONSHIP            Group;
  } DUMMYUNIONNAME;
} SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX, *PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX;
#    endif

#    if (WINVER < 0x0601)
typedef struct _PROCESSOR_NUMBER {
  WORD                            Group;
  BYTE                            Number;
  BYTE                            Reserved;
} PROCESSOR_NUMBER, *PPROCESSOR_NUMBER;

BOOL WINAPI GetThreadGroupAffinity(HANDLE hThread, PGROUP_AFFINITY GroupAffinity);
BOOL WINAPI SetThreadGroupAffinity(HANDLE hThread, CONST GROUP_AFFINITY * GroupAffinity, PGROUP_AFFINITY PreviousGroupAffinity);
BOOL WINAPI SetThreadIdealProcessorEx(HANDLE hThread, PPROCESSOR_NUMBER lpIdealProcessor, PPROCESSOR_NUMBER lpPreviousIdealProcessor);

#    endif
#  endif
#endif

