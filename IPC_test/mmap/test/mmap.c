#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<sys/mman.h>
void sys_err(const char *str)
{
    perror(str);
    exit(1);
}

int main(int argc,char *argv[])
{
    char *p=NULL;
    int fd;
    fd = open("testmap", O_RDWR|O_CREAT|O_TRUNC,0644);
    if(fd == -1)
        sys_err("open error");

    /*
    lseek(fd, 10, SEEK_END);
    write(fd, "\0", 1);
    */
    ftruncate(fd, 20);//替代上2行

    int len = lseek(fd, 0, SEEK_END);
    p = mmap(NULL,len,PROT_WRITE|PROT_READ,MAP_SHARED,fd,0);
    if(p == MAP_FAILED)
        sys_err("mmap error");
    
    strcpy(p,"hello map");
    printf("%s\n",p);

    int ret = munmap(p, len);
    if(ret == -1)
        sys_err("munmap error");

    return 0;
}