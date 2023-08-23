#include<unistd.h>

#include<fcntl.h>

#include<stdio.h>
#include<errno.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd;
    fd = open("./dict.cp4",O_RDONLY|O_CREAT,0664); //参数三需要有O_CREAT 八进制数 与mask按位与
    
    printf("fd=%d, errno=%d:%s\n",fd,errno,strerror(errno));

    close(fd);
    return 0;
}