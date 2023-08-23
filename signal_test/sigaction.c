#include <bits/types/sigset_t.h>
#include <signal.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdlib.h>
#include<unistd.h>

void sig_catch(int signo)
{
    if(signo == SIGINT){
        printf("catch you%d\n",signo);
        sleep(10);
    }

    // if(signo == SIGQUIT)
    //     printf("-------catch you%d\n",signo);
    return ;
}

int main()
{
    struct sigaction act,oldact;
    act.sa_handler = sig_catch;         
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGQUIT);
    act.sa_flags = 0;
    int ret = sigaction(SIGINT, &act, &oldact);
    if(ret == -1)
        perror("sigaction error");
    ret = sigaction(SIGQUIT, &act, &oldact);
    // if(ret == -1)
    //     perror("sigaction error");
    while(1);
    return 0;

}