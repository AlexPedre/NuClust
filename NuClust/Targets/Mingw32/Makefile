#
# *********************************************
# ****        Makefile for NuClust         ****
# **** (c) 2022-2025 - Alessandro Pedretti ****
# ****   for Mingw32, Pentium Pro target   ****
# *********************************************
#
#

# Compiler options

CC         = g++
CFLAGS     = -O3 -march=pentiumpro -ffast-math -malign-double \
             -DWIN32 -DLOCALE_DLL \
             -DHDRIVE_DLL -DHD_USE_LEADING_UNDERSCORE  \
             -DVEGABASE_DLL -DVG_USE_LEADING_UNDERSCORE \
             -I ../../../HyperDrive \
             -I ../../../OpenCL/include \
             -I ../../../Vega/Src/BaseLib
LDFLAGS    = -L ../../../HyperDrive/Mingw32 \
             -L ../../../Vega/BaseLib/Mingw32 \
             -s -static -static-libgcc -static-libstdc++

# Target

TARGET     = Mingw32
LIBS       = -lvegabase -lhdrive
EXTRAOBJS  = getopt.o resources.o
EXE        = NuClust.exe
RM         = del

include ../../Src/Makefile.in
