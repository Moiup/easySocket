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
#define MAX_CONNECTION 15

int main(){
    int sock_id;
    int client_id;

    /* Creating the socket */
    sock_id = easySocket_server_creation(
                                        SERVER_ADDRESS,
                                        SERVER_PORT,
                                        MAX_CONNECTION
                                    );
    if(sock_id == easySocket_NO_VAL){
        fprintf(stderr, "Error creating the server socket.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Server launched on %s - port : %d\n",
                                                        SERVER_ADDRESS,
                                                        SERVER_PORT
                                                    );

    /* Accepting a client */
    client_id = easySocket_server_accept(sock_id);
    if(client_id == easySocket_NO_VAL){
        fprintf(stderr, "Error accepting client.\n");
        exit(EXIT_FAILURE);
    }

    /* Sending "Hello Word!" */
    easySocket_send_message(client_id, "Hello Word!");

    fprintf(stdout, "Message sent, bye bye.\n");

    close(sock_id);
    close(client_id);

    return EXIT_SUCCESS;
}