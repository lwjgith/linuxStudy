#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>

int main(int argc,char *argv[])
{
    DIR * dp;
    struct dirent *sdp;
    dp = opendir(argv[1]);
    if(dp == NULL) {
        perror("opendir error");
        exit(1);
    }

    while((sdp = readdir(dp)) != NULL) {
        if(strcmp(sdp->d_name,".") == 0 || strcmp(sdp->d_name,"..") == 0)
            continue;
        printf("%s\t",sdp->d_name);
    }

    printf("\n");
    closedir(dp);

    return 0;
}