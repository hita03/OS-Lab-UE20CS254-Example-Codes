// Program to demo shared memory. This program will read from a shared memory segment
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

    shmid = shmget((key_t)2345, 1024, 0666); 
    printf("Key of shared memory is %d\n", shmid);

    shared_memory = shmat(shmid, NULL, 0); //process attached to the shared memory segment
    printf("Process attached at %p\n", shared_memory); //print the address where the shared memory segment is attached to this process
    
    printf("Data read from shared memory is : %s\n",(char *)shared_memory);
}
