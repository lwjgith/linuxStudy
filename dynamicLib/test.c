#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include "mymath.h"

int mul(int a, int b)
{
    return a*b;
}

int main(int argc, char *argv[])
{
    int a = 14,b = 7;
    printf("%d+%d=%d\n", a, b, add(a, b));
    printf("%d-%d=%d\n", a, b, sub(a, b));
    printf("%d/%d=%d\n", a, b, div1(a, b));
    printf("%d*%d=%d\n", a, b, mul(a,b));
    return 0;
}