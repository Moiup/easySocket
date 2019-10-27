CC=gcc
FLAG=-Wall -W

all: client server

server: easySocket.o server.c
	$(CC) $(FLAG) easySocket.o server.c -o server

client: easySocket.o client.c
	$(CC) $(FLAG) easySocket.o client.c -o client

easySocket.o: ../easySocket/easySocket.h ../easySocket/easySocket.c
	$(CC) $(FLAG) -c ../easySocket/easySocket.c -o easySocket.o

clean:
	rm -rf *.o client server