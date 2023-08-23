#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <sys/types.h>
#include<unistd.h>

int main()
{
    pid_t pid;
    int ret,fd;

    pid = fork();
    if(pid > 0)
        exit(0);

    pid = setsid();
    if(pid == -1) {
        perror("setsid error");
    }
    ret = chdir("/home/lwj/my_linux");
    if(ret == -1) 
        perror("chdir error");
    umask(0022);
    close(STDIN_FILENO);
    fd = open("/dev/null", O_RDWR);
    if(fd == -1)
        perror("open error\n");
    dup2(fd, STDOUT_FILENO);
    dup2(fd,STDERR_FILENO);
    while(1);
    
    return 0;
}