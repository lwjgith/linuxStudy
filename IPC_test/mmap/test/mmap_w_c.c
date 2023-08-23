#include <fcntl.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/mman.h>
#include<unistd.h>
#include<sys/wait.h>

struct student {
    int id;
    char name[256];
    int age;
};

int main()
{
    struct student stu={1,"ming",18};
    struct student *p;
    int fd;
    fd = open("testmap",O_RDWR|O_CREAT|O_TRUNC,0644);
    if(fd < 0) {
        perror("open error");
        exit(1);
    }
    ftruncate(fd, sizeof(stu));
    p = mmap(NULL, sizeof(stu), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if(p == MAP_FAILED) {
        perror("mmap error");
        exit(1);
    }
    close(fd);
    while(1)
    {
        memcpy(p,&stu,sizeof(stu));
        stu.id++; 
        sleep(1);
    }
    munmap(p, sizeof(stu));
    return 0;
}