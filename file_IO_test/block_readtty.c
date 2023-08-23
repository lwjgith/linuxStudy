#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(void)
{
    char buf[10];
    int n;
    //      dev/tty
    n = read(STDIN_FILENO,buf,10);  //输入

    if(n < 0) {
        perror("read STDIN_FILENO");
        exit(1);
    }
    write(STDOUT_FILENO,buf,n); //输出
    return 0;
}