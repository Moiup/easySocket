#include "server-master.h"


int main(){
    int client_id;
    int server_sock = easySocket_server_creation(SERVER_ADRESS, SERVER_PORT, SERVER_MAX_CONNECTION);    

    fprintf(stdout, "Server id %d\n", server_sock);

    easySocket_set_non_block_read(server_sock);

    while(1){
        client_id = easySocket_server_accept(server_sock);
        if(client_id != -1){
            fprintf(stdout, "Client id %d\n", client_id);
            close(client_id);
        }
    }

    return EXIT_SUCCESS;
}