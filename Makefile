CC=gcc
FLAG=-W -Wall

client: easySocket.o client.h client.c
	$(CC) $(FLAG) easySocket.o client.c -o client

server-master: easySocket.o server-master.h server-master.c
	$(CC) $(FLAG) easySocket.o server-master.c -o server-master

easySocket.o: easySocket/easySocket.h easySocket/easySocket.c
	$(CC) $(FLAG) -c easySocket/easySocket.c -o easySocket.o

clean:
	rm -rf *.o

clean_all:
	rm -rf *.o server-master client