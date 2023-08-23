#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/wait.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
    int i;
    pid_t pid,wpid;
    for(i = 0;i < 5;i++) {
        if(fork() == 0) {   //循环期间，子进程不fork
            break;
        }
    }
    if(i == 5)  //  父进程
    {
        /*
        while((wpid = waitpid(-1, NULL, 0))) {  //阻塞方式回收
            printf("wait child %d\n",wpid);
        };
        */
        while((wpid = waitpid(-1, NULL, WNOHANG)) != -1) {  //非阻塞方式回收
            if(wpid > 0)
            printf("wait child %d\n",wpid);
            else if(wpid == 0) {
                sleep(1);
                continue;
            }
        };
    }
    else
    {
        sleep(i);
        printf("%dchild pid %d\n",i,getpid());
    }
    return 0;
}