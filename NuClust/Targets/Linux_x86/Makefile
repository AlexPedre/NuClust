#
# *********************************************
# ****         Makefile for NuClust        ****
# **** (c) 2022-2025 - Alessandro Pedretti ****
# ****   for Linux x86, Intel x86 target   ****
# *********************************************
#
#

# Compiler options

CC         = g++
CFLAGS     = -O3  -march=pentiumpro -malign-double -ffast-math -fomit-frame-pointer \
             -msse3 -funroll-loops -DLINUX -DLOCALE_DLL -DPB_USE_SSE \
             -I ../../../HyperDrive \
             -I ../../../OpenCL/include \
             -I ../../../Vega/Src/BaseLib
LDFLAGS    = -L ../../../HyperDrive/Linux_86-32 \
             -L ../../../Vega/BaseLib/Linux_x86 \
             -s

# Target

TARGET     = Linux_x86
LIBS       = -lvegabase -lhdrive
EXTRAOBJS  =
EXE        = nuclust
RM         = rm -f

include ../../Src/Makefile.in
