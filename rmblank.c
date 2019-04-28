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

void remove_blank_in_now_order(){
    int blank_in_front=0;
    for(int i=0;now_order[i];i++)
        if(now_order[i]==' ') blank_in_front++;
        else break;
    for(int i=0;i<strlen(now_order);i++)
        now_order[i]=now_order[i+blank_in_front];   
    for(int i=0;i<blank_in_front;i++)
        now_order[strlen(now_order)-1-i]='\0';

    for(int i=strlen(now_order)-1;;i--)
        if(now_order[i]==' ') now_order[i]='\0';
        else break;

    for(int i=0;now_order[i+1];i++)   
        if(now_order[i]==' ' && now_order[i+1]==' '){
            for(int j=i+1;j<strlen(now_order);j++)
                now_order[j]=now_order[j+1];
            i--;
        }
}
