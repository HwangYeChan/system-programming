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

void command_cd(){
    if(number_of_option==0)
        while(strcmp(now_dir,"/home/os")){
            chdir("..");
            getcwd(now_dir,1024);
        }
    if(number_of_option==1){
        int an_error=chdir(option[0]);
        if(an_error){
            if(errno==ENOENT) printf("bash: cd: %s: No such file or directory\n",option[0]);
            if(errno==ENOTDIR) printf("bash: cd: %s: Not a directory\n",option[0]);
            //MORE ERRORS..
        }
    }
    if(number_of_option==2)
        printf("bash: cd: too many arguments\n");
}
