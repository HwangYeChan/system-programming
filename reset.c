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

void reset_prev(){
    for(int i=0;i<1024;i++){
        now_order[i]='\0';
        operation[i]='\0';
        now_dir[i]='\0';
    }
    for(int i=0;i<100;i++)
        for(int j=0;j<1024;j++){
            option[0][i]='\0';
            option[1][i]='\0';
        }
}
