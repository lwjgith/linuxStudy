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
        if(i == 2)
        {
            if((pid = fork()) == 0)//获取第三个子进程pid
                break;
        }
        else if(fork() == 0) {   //循环期间，子进程不fork
            break;
        }
    }
    if(i == 5)  //  父进程
    {
        sleep(5);
        // wpid=waitpid(-1, NULL, WNOHANG);//-1表示回收任意子进程
        wpid = waitpid(pid, NULL, WNOHANG); //回收一个进程，不阻塞
        if(wpid == -1) {
            perror("waitpid error");
            exit(1);
        }
        printf("parent,wait a child finish%d\n",wpid);
    }
    else
    {
        sleep(i);
        printf("%dchild pid %d\n",i,getpid());
    }
    return 0;
}