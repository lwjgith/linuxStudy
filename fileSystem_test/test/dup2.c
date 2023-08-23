#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
    int fd1 = open(argv[1],O_RDWR);
    int fd2 = open(argv[2],O_RDWR);
    int fdret = dup2(fd1,fd2);
    //返回新文件描述符 fd2
    printf("fdret = %d\n",fdret);
    int ret = write(fd2,"1234567",7);//写入fd1指向文件
    printf("%d\n",ret);
    
    dup2(fd1,STDOUT_FILENO);//将屏幕重定向到fd1

    printf("----------------");
    return 0;
}