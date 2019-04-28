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

void command_mv(){
    if(number_of_option==0)
        printf("mv: missing file operand\nTry \'mv --help\' for more information.\n");
    else if(number_of_option==1) 
        printf("mv: missing destination file operand after \'%s\'\nTry \'mv --help\' for more information.\n",option[0]);
    else if(number_of_option==2){
        char temp_dir[2][1024]={};
        for(int i=0;i<2;i++){
            if(option[i][0]=='~' && option[i][1]=='/'){
                strcat(temp_dir[i],"/home/os");
                strcat(temp_dir[i],option[i]+1);
            }
            else if(option[i][0]!='/'){
                getcwd(now_dir,1024);
                strcat(temp_dir[i],now_dir);
                strcat(temp_dir[i],"/");
                strcat(temp_dir[i],option[i]);
            }
            else
                strcat(temp_dir[i],option[i]);
        }
        strcat(temp_dir[1],"/");
        strcat(temp_dir[1],option[0]);
        int an_error=rename(temp_dir[0],temp_dir[1]);
        if(an_error){
            //MORE ERRORS..
        }
    }

}

