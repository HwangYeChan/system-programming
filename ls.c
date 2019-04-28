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

void command_ls(){
    if(number_of_option==0){
        int printed=0;
        getcwd(now_dir,1024);
        DIR *d=opendir(now_dir);
        struct dirent *ent;
        while(ent=readdir(d))
            if((ent->d_name)[0]!='.'){
                printf("%s  ",ent->d_name);
                printed=1;
            }
        closedir(d);
        if(printed)
            printf("\n");
    }
    // MORE OPTIONS..
}
