//to display type of file by passing file name as argument
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
    struct stat buffer;
    // The stat structure is returned by the fstat() and stat() functions.
    // It provides detailed information about a file.
    // The information returned depends on the type of file and/or the file system on which the file resides.
    if(argc<2){
        printf("Too few arguments\n");
        exit(0);
    }
    int st = stat(argv[1],&buffer);
    if(st<0){
        printf("Error\n");
        exit(0);
    }
    if(S_ISREG(buffer.st_mode)) printf("Regular File\n"); 
    // s_ISREG = macro
    if(S_ISFIFO(buffer.st_mode)) printf("FIFO File\n"); 
    if(S_ISDIR(buffer.st_mode)) printf("Directory\n");
    if(S_ISCHR(buffer.st_mode)) printf("Character Device File");
    if(S_ISLNK(buffer.st_mode)) printf("Symbolic Link File");


}