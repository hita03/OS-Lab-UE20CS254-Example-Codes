// Program to demo Message Queue - Write

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAX 10
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

    printf("Enter message to be passed :\n");
    //fgets(message.mesg_text, sizeof(message), stdin);
    read(0, message.mesg_text, BUF_SIZE);

    printf("Message being sent: %s\n", message.mesg_text);
    
    // ftok to generate unique key
    key = ftok("progfile", 65);

    // msgget creates a message queue and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1;

    // msgsnd to send message
    msgsnd(msgid, &message, sizeof(message), 0);

    sleep(60);
    return 0;
}
