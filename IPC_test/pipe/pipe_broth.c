#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<wait.h>
void sys_err(const char *str)
{
    perror(str);
    exit(1);
}

int main(int argc,char *argv[])
{
    int fd[2];
    int ret,i;
    pid_t pid;
    ret = pipe(fd);
    if(ret == -1) {
        sys_err("pipe error");
    }
    for(i = 0;i < 2;i++)
    {
        pid = fork();
        if(pid == -1) {
            sys_err("fork error");
        }
        if(pid == 0)
            break;//子进程退出
    }
    if(i == 2)
    {
        close(fd[0]);
        close(fd[1]);
        wait(NULL);
        wait(NULL);
    }else if (i == 0) {
        close(fd[0]);
        dup2(fd[1],STDOUT_FILENO);
        execlp("ls", "ls",NULL);
        sys_err("execlp ls error");
    }else if (i == 1) {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        execlp("wc", "wc","-l",NULL);
        sys_err("execlp wc error");
    }
    return 0;
}