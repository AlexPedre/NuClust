#
# ********************************************
# ****      Makefile for Locale.dll       ****
# **** (c) 2000-2025, Alessandro Pedretti ****
# ****     for Mingw64 - AMD 64 target    ****
# ********************************************
#
#

CC         = gcc
CPU        = -m64
CFLAGS     = -O3 $(CPU) -DLOCALE_DLL -funroll-loops -Wall
VER        =
DLL32      = locale
DLL64      = 
LIBRARY    =

O          = .o
EXTRAOBJ   = locale$(O)
RM         = del


include ../Makefile.in

