#
# ********************************************
# ****      Makefile for Locale.dll       ****
# **** (c) 2000-2025, Alessandro Pedretti ****
# ****  for Mingw32 - Pentium Pro target  ****
# ********************************************
#
#

CC         = gcc
CPU        = -march=pentiumpro
CFLAGS     = -O3 $(CPU) -malign-double -mrtd -DLOCALE_DLL \
             -fomit-frame-pointer -funroll-loops -Wall
VER        =
DLL32      = locale
DLL64      = 
LIBRARY    =

O          = .o
EXTRAOBJ   = locale$(O)
RM         = del


include ../Makefile.in

