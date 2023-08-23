#include <signal.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdlib.h>
#include<unistd.h>

void print_set(sigset_t *set)
{
    int i;
    for(i = 1;i < 32;i++) {
        if(sigismember(set, i))
            putchar('1');
        else
            putchar('0');
    }
    printf("\n");
}
int main()
{
    int ret=0;
    sigset_t set,oldset,pedset;
    sigemptyset(&set);

    sigaddset(&set,SIGINT);
    sigaddset(&set, SIGQUIT);
    
    ret = sigprocmask(SIG_BLOCK, &set,&oldset);
    if(ret == -1)
        perror("signprocmask error\n");
        
    while(1){
        ret = sigpending(&pedset);
        if(ret == -1)
            perror("sigpending error");
        print_set(&pedset);
        sleep(1);
    }
    
    return 0;


}