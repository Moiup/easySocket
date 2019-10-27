[Main menu](../../Readme.md)->[doc](../easySocket-doc.md)

# easySocket_send_message(\_,\_)

Send a message.

## **Declaration**

```C
int easySocket_send_message(
                            int dest_id,
                            char *message,
                        )
```

## **Parameters**
**dest_id**  
The id of the recipient.

**message**  
The message to send.

## **Result**
Return the number of bytes written, `easySocket_NO_VAL` if failed.