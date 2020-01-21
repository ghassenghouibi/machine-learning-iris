.PHONY: clean, mrproper

CC = gcc
CFLAGS = -W -Wall 
 

all: main.o init.o utils.o som.o
	$(CC) main.o init.o utils.o som.o -lm -o iris

utils.o : init.h
	$(CC) -c utils.c -o utils.o $(CFLAGS)

main.o: init.h
	$(CC) -c main.c -o main.o $(CFLAGS)

init.o: init.h
	$(CC) -c init.c -o init.o $(CFLAGS)

som.o: init.h
	$(CC) -c som.c -o som.o $(CFLAGS)

clean:
	rm -rf *.bak rm -rf *.o

mrproper: clean
	rm -rf iris
