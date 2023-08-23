#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int arc,char *argv[])
{
    //  判断文件类型
    struct stat sbuf;
    // int ret = stat(argv[1],&sbuf);
    int ret = lstat(argv[1], &sbuf);
    if(ret == -1) {
        perror("stat error");
        exit(1);
    }
    //printf("file size %ld\n",sbuf.st_size);
    if(S_ISREG(sbuf.st_mode)) { 
        printf("It's a regular\n");
    } else if (S_ISDIR(sbuf.st_mode)) {
        printf("it's a dir\n");
    } else if(S_ISFIFO(sbuf.st_mode)) {
        printf("it's a pipe\n");
    } else if(S_ISLNK(sbuf.st_mode)) {
        printf("it's a sym link\n");
    }
    
    return 0;
}