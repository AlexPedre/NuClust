#
# ********************************************
# ****       Makefile for LocaleLib       ****
# **** (c) 2000-2025, Alessandro Pedretti ****
# ****        Linux x86-32 version        ****
# ********************************************
#
#

CC         = gcc
CPU        = -march=pentiumpro
CFLAGS     = -O3 $(CPU) -malign-double -fomit-frame-pointer -funroll-loops -DLITTLE_ENDIAN
VER        =
DLL32      =
DLL64      = 
LIBRARY    = liblocale$(VER).a
SHARED     = liblocale$(VER).so

O          = .o
EXTRAOBJ   =
RM         = rm -f


include ../Makefile.in

