#include <signal.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdlib.h>
#include<unistd.h>

void sig_catch(int signo)
{
    printf("catch you%d\n",signo);
    return ;

}

int main()
{
    signal(SIGINT, sig_catch);
    while(1);
    return 0;

}