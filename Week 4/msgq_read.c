// Program to demo Message Queue - Read

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define BUF_SIZE 100

// structure for message queue
struct mesg_buffer 
{
    long mesg_type;
    char mesg_text[BUF_SIZE];
} message;

int main()
{
    key_t key;
    int msgid;

    // ftok to generate unique key
    key = ftok("progfile", 65);
    
    // msgget creates a message queue and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);

    // msgrcv to receive message
    msgrcv(msgid, &message, sizeof(message), 1, 0);

    // display the message
    printf("Message received : %s\n", message.mesg_text);

    // destroy the message queue
    msgctl(msgid, IPC_RMID, NULL);
    
    return 0;
}
