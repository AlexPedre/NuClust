#
# *********************************************
# ****        Makefile for NuClust         ****
# **** (c) 2022-2025 - Alessandro Pedretti ****
# ****    for Mingw64, Intel x64 target    ****
# *********************************************
#
#

# Compiler options

CC         = g++
CFLAGS     = -O3 -m64 -msse3 -mfpmath=sse -ffast-math -funroll-loops \
             -DWIN32 -DWIN64 -DLOCALE_DLL -DPB_USE_SSE \
             -DHDRIVE_DLL -DHD_USE_LEADING_UNDERSCORE  \
             -DVEGABASE_DLL -DVG_USE_LEADING_UNDERSCORE \
             -I ../../../HyperDrive \
             -I ../../../OpenCL/include \
             -I ../../../Vega/Src/BaseLib
LDFLAGS    = -L ../../../HyperDrive/Mingw64 \
             -L ../../../Vega/BaseLib/Mingw64 \
             -s -static -static-libgcc -static-libstdc++

# Target

TARGET     = Mingw64
LIBS       = -lvegabase -lhdrive
EXTRAOBJS  = getopt.o resources.o
EXE        = NuClust.exe
RM         = del

include ../../Src/Makefile.in
