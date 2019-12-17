.PHONY: clean, mrproper

CC = gcc
CFLAGS = -W -Wall 
 

all: main.o init.o
	$(CC) main.o init.o -o iris

main.o: init.h
	$(CC) -c main.c -o main.o $(CFLAGS)

init.o: init.h
	$(CC) -c init.c -o init.o $(CFLAGS)

clean:
	rm -rf *.bak rm -rf *.o

mrproper: clean
	rm -rf iris
