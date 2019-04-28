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

void command_cat(){
    char ch;
    int fd;
    for(int i=0;i<number_of_option;i++){
        fd=open(option[i],O_RDONLY);
        if(fd==-1){
        	printf("cat: %s: No such file or directory\n",option[i]);
        	continue;
        }
        while(read(fd,&ch,1))
            write(1,&ch,1);
        close(fd);
    }
}
