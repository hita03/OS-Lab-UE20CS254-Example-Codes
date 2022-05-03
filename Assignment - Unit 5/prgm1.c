// Write a c program to truncate the files in a directory created after a certain date to half of it's original size.
#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(){
    DIR *dir;
    struct dirent *dirent;
    struct stat statbuf;
    int fd;
    char *filename;
    int size;
    int half;
    char date[100];
     printf("Enter the date in dd/mm/yyyy format: ");
    scanf("%s",date);
    char path[100];
    
    printf("Enter the path of the directory: ");
    scanf("%s", path);

    dir = opendir(path);
    if(dir == NULL){
        printf("Cannot open directory\n");
        return 1;
    }

    while((dirent = readdir(dir)) != NULL){
        filename = dirent->d_name;
        if(stat(filename, &statbuf) == -1){
            printf("Cannot stat file %s\n", filename);
            continue;
        }
        if(S_ISREG(statbuf.st_mode)){
            fd = open(filename, O_RDWR);
            if(fd == -1){
                printf("Cannot open file %s\n", filename);
                continue;
            }
            size = statbuf.st_size;
            half = size/2;
            if(ftruncate(fd, half) == -1){
                printf("Cannot truncate file %s\n", filename);
                continue;
            }
            if(strcmp(date,ctime(&statbuf.st_ctime)) < 0){
            	printf("File %s truncated to %d bytes\n", filename, half);
            }
        }
    }
    closedir(dir);
    return 0;
    
}