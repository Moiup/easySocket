#include "server-master.h"

void add_client(int *connect_id, int client_id, int len){
    int i;

    for(i = 0; i < len; i++){
        if(connect_id[i] == -1){
            connect_id[i] = client_id;
            break;
        }
    }
}

int main(){
    int client_id;
    int server_sock = easySocket_server_creation(SERVER_ADRESS, SERVER_PORT, SERVER_MAX_CONNECTION);    

    int connected_id[SERVER_MAX_CONNECTION];
    /* Initialisating all the client id to 0 */
    memset(connected_id, -1, SERVER_MAX_CONNECTION);

    fprintf(stdout, "Server id %d\n", server_sock);

    easySocket_set_non_block(server_sock);

    while(1){
        client_id = easySocket_server_accept(server_sock);
        if(client_id != -1){
            fprintf(stdout, "Client id %d\n", client_id);
        }
    }

    return EXIT_SUCCESS;
}