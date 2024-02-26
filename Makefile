# Makefile for Ex1
# Compiler
CC = gcc

#Warrnings
CFLAGS= -g -Wall
Main.o:	Main.c StrList.h
	$(CC) $(CFLAGS) -c Main.c

StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) -c StrList.c

StrList: StrList.o Main.o
	$(CC) $(CFLAGS) StrList.o Main.o -o StrList

clean:
	rm -f *.o
	rm -f *.a	
	rm -f StrList