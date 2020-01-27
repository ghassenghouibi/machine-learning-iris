.PHONY: clean

CC = gcc
CFLAGS = -W -Wall 
 

all: main.o init.o utils.o som.o
	$(CC) main.o init.o utils.o som.o -lm -o iris

utils.o : utils.h
	$(CC) -c utils.c -o utils.o $(CFLAGS)

main.o: utils.h
	$(CC) -c main.c -o main.o $(CFLAGS)

init.o: utils.h
	$(CC) -c init.c -o init.o $(CFLAGS)

som.o: utils.h
	$(CC) -c som.c -o som.o $(CFLAGS)

clean:
	rm -rf *.o