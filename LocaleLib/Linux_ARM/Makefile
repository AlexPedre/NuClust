#
# ********************************************
# ****       Makefile for LocaleLib       ****
# **** (c) 2000-2025, Alessandro Pedretti ****
# ****   for Linux ARM64, native target   ****
# ********************************************
#
#

CC         = gcc
CPU        = -mcpu=native
CFLAGS     = -O3 -fPIC $(CPU) -DLITTLE_ENDIAN
VER        =
DLL32      =
DLL64      = 
LIBRARY    = liblocale$(VER).a
SHARED     = liblocale$(VER).so

O          = .o
EXTRAOBJ   =
RM         = rm -f


include ../Makefile.in

