#include "client.h"


int main(){
    int client_id;

    client_id = easySocket_client_creation();

    easySocket_client_connect(client_id, SERVER_ADRESS, SERVER_PORT);

    close(client_id);

    return EXIT_SUCCESS;
}