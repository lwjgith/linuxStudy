#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/time.h>

void myfunc(int signo)
{
    printf("hello\n");
}
int main(void)
{
    struct itimerval it,oldit;
    signal(SIGALRM,myfunc);

    it.it_value.tv_sec = 2;
    it.it_value.tv_usec = 0;
    
    it.it_interval.tv_sec = 5;
    it.it_interval.tv_usec = 0;
    
    if(setitimer(ITIMER_REAL, &it, &oldit) == -1)
    {
        perror("setitimer error");
        return -1;
    }
    while(1);
    return 0;
}