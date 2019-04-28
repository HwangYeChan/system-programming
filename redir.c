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

void do_redirection(){
    char *for1[1024]={operation};
    char *for2[1024]={};

    int now=1;  
    int fd[2];
    for(;;now++)
        if(!strcmp(option[now-1],">")) break;
        else for1[now]=option[now-1];
    for1[now]=NULL;

    for(int i=now;i<number_of_option;i++)
        for2[i-now]=option[i];
    for2[number_of_option]=NULL;

    int dest;
    pid_t pid=fork();

    if(pid<0) perror("fork");
    if(!pid){
        dest=open(for2[0],O_WRONLY|O_CREAT|O_TRUNC,0644);
        if(dest==-1){
            perror("file creating error");
            exit(0);
        }
        if(dup2(dest,1)<0)
            perror("dest duplicative error");
        close(dest);
        execvp(for1[0],for1);
        printf("%s: command not found\n",for1[0]);                 
        exit(0);        
    }
    if(pid>0) wait(NULL);
}
