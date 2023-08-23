#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
    int fd = open(argv[1],O_RDONLY);
    int newfd = dup(fd);

    write(newfd,"1234567",7);
    printf("newfd = %d\n",newfd);
    return 0;
}