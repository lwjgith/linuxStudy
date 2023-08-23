#include <fcntl.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/mman.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    int *p,fd;
    pid_t pid;
    int var = 2;
    fd = open("testmap", O_CREAT|O_TRUNC|O_RDWR,0644);
    if(fd < 0) {
        perror("open error");
        exit(1);
    }
    ftruncate(fd, 4);
    p = mmap(NULL, 4, PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);
    if(p == MAP_FAILED)
    {
        perror("mmap error");
    }
    close(fd);
    pid = fork();
    if(pid == 0)
    {
        *p = 2000;
        var = 10;
        printf("p=%d,var=%d\n",*p,var);
    }
    else {
        sleep(1);
        printf("p = %d, var = %d\n",*p,var);
        wait(NULL);
    }

    int ret = munmap(p, 4);
    if(ret == -1)
    {
        perror("munmap error");
    }
    return 0;
}