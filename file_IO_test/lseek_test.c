#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
    int fd = open(argv[1],O_RDWR);
    if(fd < 0) {
        perror("open error");
        exit(1);
    }

    int lenth = lseek(fd, 111, SEEK_END);
    printf("file size:%d\n",lenth);
    write(fd,"a",1);    //要想拓展需要io操作
    close(fd);

    return 0;
}