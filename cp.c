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

void command_cp(){
   if(number_of_option==0)
        printf("cp: missing file operand\nTry \'cp --help\' for more information.\n");
    else if(number_of_option==1) 
        printf("cp: missing destination file operand after \'%s\'\nTry \'cp --help\' for more information.\n",option[0]);
    else{
        for(int i=0;i<number_of_option-1;i++){
            mode_t old;
            old=umask(0);
            int from=open(option[i],O_RDONLY);
            int to=open(option[number_of_option-1],O_WRONLY|O_CREAT|O_TRUNC,0644);
            if(from==-1 || to==-1){
                printf("error in cp\n");
                return;
            }
            char ch;
            while(read(from,&ch,1)>0)
                write(to,&ch,1);
            close(from);
            close(to);
            umask(old);
        }

    }
}
