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

void set_option(int index){
    int blank=0;
    int start=-1,end=-1;
    for(int i=0;i<strlen(now_order)+1;i++){
        blank+=(now_order[i]==' ' || now_order[i]=='\0');
        if(start==-1 && blank==index+1)
            start=i;
        if(end==-1 && blank==index+2)
            end=i;
    }
    for(int i=start+1;i<end;i++)
        option[index][i-start-1]=now_order[i];
}
