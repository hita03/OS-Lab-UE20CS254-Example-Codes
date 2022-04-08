//program to display conents of a directory
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
int main(int argc, char *argv[]){
    DIR *dp;//dir pointer
    struct dirent *dirp;
    if(argc!=2){
        printf("Too few arguments\n");
        exit(0);
    }
    dp = opendir(argv[1]);
    if(dp==NULL){
        printf("Error\n");
        exit(0);
    }
    //if dir opened successfully
    while((dirp=readdir(dp))!=NULL){
        //directory is not empty
        printf("Name = %s\n",dirp->d_name);

    }
    closedir(dp);
    return 0;
}
