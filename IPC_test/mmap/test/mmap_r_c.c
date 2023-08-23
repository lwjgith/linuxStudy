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
    fd = open("testmap",O_RDONLY);
    if(fd < 0) {
        perror("open error");
        exit(1);
    }
    ftruncate(fd, sizeof(stu));
    p = mmap(NULL, sizeof(stu), PROT_READ, MAP_SHARED, fd, 0);
    if(p == MAP_FAILED) {
        perror("mmap error");
        exit(1);
    }
    close(fd);
    while(1)
    {
        printf("id=%d,name=%s,age=%d\n",p->id,p->name,p->age);
        sleep(1);
    }
    munmap(p, sizeof(stu));
    return 0;
}