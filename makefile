CC = g++
CFLAGS = -Wall -Wextra -std=c11

all: test.exe main.exe

test.exe: list.o test.o
	$(CC) $(CFLAGS) list.o test.o -o test.exe

main.exe: list.o main.o
	$(CC) $(CFLAGS) list.o main.o -o main.exe

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

test.o: test.c list.h
	$(CC) $(CFLAGS) -c test.c

main.o: main.c list.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o test.exe main.exe