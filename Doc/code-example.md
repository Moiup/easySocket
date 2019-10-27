[Main menu](../Readme.md)
# Code example
You will find an exemple of a server and of a client script. Both code can be found in the folder _Example_, whith the name server.c and client.c.

To access the doc, [click here](easySocket-doc.md)

## HOW TO?
To run it: 
```
$ make all
```
Then: 
```
$ server
```
And: 
```
$ client
```
To remove everything:
```
$ make clean
```

### **Results**
For the server, you should have :
```
Server launched on 127.0.0.1 - port : 8000
Message sent, bye bye.
```

For the client you should get:
```
Message received: Hello Word!
```

## The code
### **Server**
Create the server, wait for a client, send him a message and exit.
```C
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
    sock_id = easySocket_server_creation(SERVER_ADDRESS, SERVER_PORT, MAX_CONNECTION);
    if(sock_id == easySocket_NO_VAL){
        fprintf(stderr, "Error creating the server socket.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Server launched on %s - port : %d\n", SERVER_ADDRESS, SERVER_PORT);

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
```

### **Client**
Connect to the server, receive a message and exit.
```C
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
        fprintf(stderr, "Error connecting to the server %s - %d.\n", SERVER_ADDRESS, SERVER_PORT);
        exit(EXIT_FAILURE);
    }

    easySocket_read(sock_id, message, MESSAGE_SIZE);
    fprintf(stdout, "Message received: %s\n", message);

    close(sock_id);

    return EXIT_SUCCESS;
}
```