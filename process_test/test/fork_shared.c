#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int var = 100;

int main(void)
{
    pid_t pid;
    pid = fork();
    if(pid == -1) {
        perror("fork error");
        exit(1);
    } else if(pid == 0) {
        var = 200;
        printf("%dchild%d\n",var,getpid());
    } else if(pid > 0) {
        printf("%dparent    pid=%d,parent-id=%d\n",var,getpid(),getppid());
    }
    return 0;
}