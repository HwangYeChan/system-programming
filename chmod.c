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

void command_chmod(){
    if(number_of_option==0)
        printf("chmod: missing operand\nTry \'chmod --help\' for more information.\n");
    else{
        if('0'<=option[0][0] && option[0][0]<='9'){
            int mod=atoi(option[0]);
            for(int i=0;i<number_of_option;i++){
                getcwd(now_dir,1024);
                char path_name[1024]={};
                strcat(path_name,now_dir);
                strcat(path_name,"/");
                strcat(path_name,option[i]);

                mode_t old;
                old=umask(0);
                int fd=chmod(path_name,mod);
                umask(old);
            }
        }
    }
}
