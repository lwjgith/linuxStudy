#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>
#include<unistd.h>
#include<signal.h>

int main()
{
    pid_t pid;
    pid = fork();
    if(pid > 0) {
        printf("parent=%d\n",getpid());
        sleep(1);
        kill(getpid(), SIGKILL);
    }
    else if (pid == 0) {
        printf("child = %d,parent=%d\n",getpid(),getppid());
    }
}