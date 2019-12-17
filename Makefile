.PHONY: clean, mrproper

CC = gcc
CFLAGS = -W -Wall 
 

all: main.o  
	$(CC) main.o -o iris

main.o: 
	$(CC) -c main.c -o main.o $(CFLAGS)

clean:
	rm -rf *.bak rm -rf *.o

mrproper: clean
	rm -rf iris
