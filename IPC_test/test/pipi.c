#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include<unistd.h>
#include<errno.h>

void sys_err(const char *str)
{
    perror(str);
    perror("\n");
    exit(1);
}

int main(int argc,char *argv[])
{
    int ret;
    int fd[2];
    pid_t pid;
    char buf[1024];
    ret = pipe(fd);
    if(ret == -1)
        sys_err("pipe error");
    pid = fork();
    if(pid > 0) {
        close(fd[0]);       //父进程写
        sleep(3);

        write(fd[1],"hello pipe\n",strlen("hello pipe\n"));
        close(fd[1]);
    } else if(pid == 0) {
        close(fd[1]);
        ret = read(fd[0], buf,sizeof(buf));
        printf("child ret = %d\n",ret);
        write(STDOUT_FILENO, buf, ret);
        close(fd[0]);
    } else {
        sys_err("fork error");
    }
    return 0;
}