#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include <sys/select.h>
#include <sys/types.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

void catch_child(int signo) 
{
    pid_t wpid;
    int status;
    // while((wpid = wait(NULL)) != -1){
    while((wpid = waitpid(-1, &status, 0)) != -1){
        if(WIFEXITED(status))
            printf("------catch %d\t%d\n",wpid,WEXITSTATUS(status));
    }
    
    return ;
}
int main()
{
    pid_t pid;
    int i;
    int ret=0;
    sigset_t set,oldset;
    sigemptyset(&set);

    sigaddset(&set,SIGCHLD);
    
    ret = sigprocmask(SIG_BLOCK, &set,&oldset);

    for(i = 0;i < 5;i++) {
        if((pid=fork()==0)) 
            break;
    }

    if(i == 5) {
        struct sigaction act;
        act.sa_handler = catch_child;
        
        sigemptyset(&act.sa_mask);
        
        sigaction(SIGCHLD, &act, NULL);

        ret = sigprocmask(SIG_UNBLOCK, &set,&oldset);
        printf("parent pid = %d\n",getpid());
        while(1);
    }
    else {
        printf("child pid = %d\n",getpid());
        return i;
    }
    return 0;
}