#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>
#include<unistd.h>
int main(int argc, char *argv[])
{

    pid_t pid = fork();
    if(pid == -1){
        perror("fork error");
        exit(1);
    } else if (pid == 0) {
        // execlp("ls", "-l","-d","-h",NULL);  //错误写法
        // execlp("ls", "ls","-l","-h",NULL);
        // execlp("date", "date",NULL);
        // execl("./a.out","./a.out",NULL);
        execl("/bin/ls","ls","-l",NULL);
        char *argv[] = {"ls","-l","-h",NULL};

        // execvp("ls", argv);

        perror("exec error");
        exit(1);
    } else if(pid > 0) {
        sleep(1);
        printf("parent:%d\n",getpid());
    }

    return 0;
}