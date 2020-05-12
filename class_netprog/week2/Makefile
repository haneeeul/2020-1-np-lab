CC = gcc
CFLAGS = -Wall

all : hello_server.c hello_client.c
	$(CC) $(CFLAGS) -o hello_server hello_server.c
	$(CC) $(CFLAGS) -o hello_client hello_client.c

hello_server : hello_server.c
	$(CC) $(CFLAGS) -o hello_server hello_server.c

hello_client : hello_client.c
	$(CC) $(CFLAGS) -o hello_client hello_client.c

clean :
	rm hello_server hello_client
