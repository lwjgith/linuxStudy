#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>

void isFile(char *);

void read_dir(char *dir,void (*func)(char *))
{
    char path[257];
    DIR *dp;
    struct dirent *sdp;
    dp = opendir(dir);
    if(dp == NULL) {
        perror("opendir error");
        return ;
    }

    while((sdp = readdir(dp)) != NULL) {
        if(strcmp(sdp->d_name,".") == 0 || strcmp(sdp->d_name, "..") == 0) {
            continue;
        }
        //目录项本身不可访问，拼接，目录/目录项
        sprintf(path, "%s/%s",dir,sdp->d_name);
        // isFile(path);
        // func(path);
        (*func)(path);
    }

    closedir(dp);
    return ;
}

void isFile(char *name)
{
    int ret = 0;
    struct stat st;
    //获取文件属性
    ret = stat(name,&st);
    if(ret == -1) {
        perror("stat error");
        return ;
    }

    if(S_ISDIR(st.st_mode)) {
        read_dir(name,isFile);
    }
    printf("%10s\t%ld\n",name,st.st_size);
    return;
}

int main(int argc,char *argv[])
{
    //判断命令行参数
    if(argc == 1) {
        isFile(".");
    } else {
        isFile(argv[1]);
    }
    return 0;
}