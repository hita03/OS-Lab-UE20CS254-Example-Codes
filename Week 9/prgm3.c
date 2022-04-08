//program to perform file operations
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
    int fd;
    char buf[10];
    fd= open("abc.txt",O_RDWR|O_CREAT,0644);
    // if file exists, open it in read write mode
    // if not, then create one with the given name
    //0644 == owner has read, write, execute permission
    printf("%d\n ",fd);
    if(fd<0){
        printf("Error\n");
        exit(0);
    }
    write(fd,"hello\n",6); // fd = file descriptor, writing 6 bytes of info to buffer
    lseek(fd,0,SEEK_SET);
    read(fd,buf,6); //reading same info from buffer
    write(1,buf,6); 
    // this displays junk values, because file pointer is at end of 6 bytes, and there is no more info entered by us.
    //So it displays whatever is beyond that - which is junk. For actually displaying content  of file, bring pointer to 0th byte.(lseek(fd,0,SEEK_SET);)
    
    close(fd);
    return 0;
}