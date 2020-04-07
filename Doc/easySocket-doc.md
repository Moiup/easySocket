[Main menu](../Readme.md)

# easySocket

## **Server**

```C
int easySocket_server_creation(char, int, int)
```
Create the server socket. [More here.](./functions/easySocket_server_creation.md)

```C
int easySocket_server_accept(int)
```
Wait for client connection. [More here.](./functions/easySocket_server_accept.md)

## **Client**

```C
int easySocket_client_creation()
```
Create the client socket. [More here.](./functions/easySocket_client_creation.md)

```C
int easySocket_client_connect(int, char, int)
```
Connect the client to the server. [More here.](./functions/easySocket_client_connect.md)

## **Message**

```C
int easySocket_send_message(int, char, size_t)
```
Send a message. [More here.](./functions/easySocket_send_message.md)

```C
void easySocket_set_non_block(int)
```
Set a socket to non-blocking. [More here.](./functions/easySocket_set_non_block.md)

```C
size_t easySocket_read(int, void, size_t)
```
Read messages. [More here.](./functions/easySocket_read.md)
