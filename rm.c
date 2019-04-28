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

void command_rm(){
    if(number_of_option==0)
        printf("rm: missing operand\nTry \'rm --help\' for more information.\n");
    else
        for(int i=0;i<number_of_option;i++){
            getcwd(now_dir,1024);
            char path_name[1024]={};
            strcat(path_name,now_dir);
            strcat(path_name,"/");
            strcat(path_name,option[i]);
            int an_error=unlink(path_name);
            if(an_error){
                if(errno==EISDIR) printf("rm: cannot remove \'%s\': Is a directory\n",option[0]);
                if(errno==ENOENT) printf("bash: cd: %s: No such file or directory\n",option[0]);
                //MORE ERRORS..
            }
        }
}
