#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>

int main(void)
{
    pid_t pid,wpid;
    int status;
    pid=fork();
    if(pid == 0) {
        printf("-child my id=%d,going to sleep 1 s\n",getpid());
        sleep(5);
        printf("child die\n");
        return 73;
    } else if(pid > 0) {
        wpid = wait(&status);   //子进程未终止，父进程阻塞
        // wpid = wait(NULL);   //不关心子进程结束原因
        if(wpid == -1) {
            perror("wait error\n");
            exit(1);
        }
        if(WIFEXITED(status)) { //为真，子进程正常终止
            printf("child exit exit with %d\n",WEXITSTATUS(status));
        }
        if(WIFSIGNALED(status)) {   //为真，子进程被信号终止
            printf("child kill with signal %d\n",WTERMSIG(status));
        }
        printf("parent wait finish %d\n",wpid);
    }else {
        perror("fork");
        return 1;
    }
    return 0;
}