#
# ********************************************
# ****       Makefile for LocaleLib       ****
# **** (c) 2000-2025, Alessandro Pedretti ****
# ****  for Linux x86-64 - AMD64 target  ****
# ********************************************
#
#

CC         = gcc
CPU        = -m64
CFLAGS     = -O3 $(CPU) -fPIC -funroll-loops -DLITTLE_ENDIAN
VER        =
DLL32      =
DLL64      = 
LIBRARY    = liblocale$(VER).a
SHARED     = liblocale$(VER).so

O          = .o
EXTRAOBJ   =
RM         = rm -f


include ../Makefile.in

