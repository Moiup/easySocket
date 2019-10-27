/**
 * Name: server.c
 *
 * Description: The server code example
 *
 * Author: Mohammed-Bashir Mahdi
 *
 * Date: 22/08/2019
 *
 */
#include "../easySocket/easySocket.h"
#include <stdio.h>
#include <stdlib.h>

#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 8000
#define MESSAGE_SIZE 15

int main(){
    int sock_id;
    char message[MESSAGE_SIZE];

    /* Creating the client socket */
    sock_id = easySocket_client_creation();
    if(sock_id == easySocket_NO_VAL){
        fprintf(stderr, "Error creating the server socket.\n");
        exit(EXIT_FAILURE);
    }

    /* Connecting the client to the server */
    if(easySocket_client_connect(sock_id, SERVER_ADDRESS, SERVER_PORT) == easySocket_NO_VAL){
        fprintf(stderr, "Error connecting to the server %s - %d.\n",
                                                                SERVER_ADDRESS,
                                                                SERVER_PORT);
        exit(EXIT_FAILURE);
    }

    easySocket_read(sock_id, message, MESSAGE_SIZE);
    fprintf(stdout, "Message received: %s\n", message);

    close(sock_id);

    return EXIT_SUCCESS;
}