// Program to demo shared memory. This program will create a shared memory segment and write to it
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    void *shared_memory;
    char buff[100] = "";
    int shmid = 0;

    // creates a shared memory segment with key 2345, having size 1024 bytes. 
    // IPC_CREAT is used to create the shared segment if it does not exist. 0666 are the permisions on the shared segment
    shmid = shmget((key_t)2345, 1024, 0666|IPC_CREAT); 
    printf("Key of shared memory is %d\n",shmid);

    shared_memory = shmat(shmid, NULL, 0); //process attached to the shared memory segment
    printf("Process attached at %p\n",shared_memory); //print the address where the shared memory segment is attached to this process
    
    printf("Enter some data to be written to the shared memory segment\n");
    //get input from the user
    read(0, buff, 100);

    strcpy(shared_memory, buff); //data written to the shared memory

    sleep(100);
}
