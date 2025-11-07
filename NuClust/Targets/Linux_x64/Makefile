#
# *********************************************
# ****         Makefile for NuClust        ****
# **** (c) 2022-2025 - Alessandro Pedretti ****
# ****     for Linux x64, AMD64 target     ****
# *********************************************
#
#

# Compiler options

CC         = g++
CFLAGS     = -O3 -m64 -msse3 -mfpmath=sse -ffast-math -funroll-loops \
             -DLINUX -DLOCALE_DLL -DPB_USE_SSE \
             -I ../../../HyperDrive \
             -I ../../../OpenCL/include \
             -I ../../../Vega/Src/BaseLib
LDFLAGS    = -L ../../../HyperDrive/Linux_86-64 \
             -L ../../../Vega/BaseLib/Linux_x64 \
             -s

# Target

TARGET     = Linux_x64
LIBS       = -lvegabase -lhdrive -ltirpc
EXTRAOBJS  =
EXE        = nuclust
RM         = rm -f

include ../../Src/Makefile.in
