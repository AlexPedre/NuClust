#
# ********************************************
# ****      Makefile for HelloWorld       ****
# **** (c) 2001-2025, Alessandro Pedretti ****
# ****       Generic Unix makefile        ****
# ********************************************
#
#

CC         = cc
#CC        = gcc
CFLAGS     = -O2
LDFLAGS    = -s -llocale
LIBDIR     = ../Unix

OBJS   = main.o

all: helloworld

helloworld: main.o
	$(CC) $(CFLAGS) -o helloworld main.o -L $(LIBDIR) $(LDFLAGS)

clean: 
	rm -f *.o

main.o: main.c globstr.h ../locale.h
	$(CC) $(CFLAGS) -c main.c


