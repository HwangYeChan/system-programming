#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

char now_order[1024];
char operation[1024];
char option[100][1024];
char now_dir[1024];

int number_of_option;

void do_pipe(){
    char *for1[1024]={operation};
    char *for2[1024]={};
    int now=1;  
    int fd[2];
    for(;;now++)
        if(!strcmp(option[now-1],"|")) break;
        else for1[now]=option[now-1];
    for1[now]=NULL;

    for(int i=now;i<number_of_option;i++)
        for2[i-now]=option[i];
    for2[number_of_option]=NULL;

    if(pipe(fd)<0){
        perror("making pipe error");
        exit(0);
    }

    pid_t pid1=fork();
    if(pid1<0) perror("fork error"); 
    if(!pid1){
        if(close(1)==-1) perror("close error");
        if(dup(fd[1]));
        if(close(fd[0])<0 || close(fd[1])<0)
            perror("close error");
        execvp(for1[0],for1);
        printf("%s: command not found\n",for1[0]);
        exit(0);
    }

    pid_t pid2=fork();
    if(pid2<0) perror("fork error"); 
    if(!pid2){
        if(close(0)==-1) perror("close error");
        if(dup(fd[0]));
        if(close(fd[0])<0 || close(fd[1])<0)
            perror("close error");
        execvp(for2[0],for2);
        printf("%s: command not found\n",for2[0]);
        exit(0);
    }
    if(close(fd[0])<0 || close(fd[1])<0) perror("close error");
    while(1)
        if(wait(NULL)==-1)
            break;
}
