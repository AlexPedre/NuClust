#
# *********************************************
# ****         Makefile for NuClust        ****
# **** (c) 2022-2025 - Alessandro Pedretti ****
# ****   for Linux ARM64, native target    ****
# *********************************************
#
#

# Compiler options

CC         = g++
CFLAGS     = -O3 -mcpu=native -ffast-math \
             -Wall -Wno-psabi -DLINUX -DLOCALE_DLL -DPB_NO_OCL \
             -I ../../../HyperDrive \
             -I ../../../OpenCL/include \
             -I ../../../Vega/Src/BaseLib
LDFLAGS    = -L ../../../HyperDrive/Linux_ARM \
             -L ../../../Vega/BaseLib/Linux_ARM \
             -s

# Target

TARGET     = Linux_ARM
LIBS       = -lvegabase -lhdrive
EXTRAOBJS  =
EXE        = nuclust
RM         = rm -f

include ../../Src/Makefile.in
