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

void reset_prev();
void remove_blank_in_now_order();
void set_operation();
int count_blank();
void set_option(int index);
void command_pwd();
void command_cd();
void command_ls();
void command_mkdir();
void command_rm();
void command_rmdir();
void command_cp();
void command_mv();
void do_pipe();
void do_redirection();

int main(){
    while(1){
        getcwd(now_dir,1024);
        printf("User@Machine:~%s$ ",now_dir+8);
        reset_prev();

        fgets(now_order,1024,stdin);

        remove_blank_in_now_order();

        number_of_option=count_blank();
        set_operation();
        for(int i=0;i<number_of_option;i++)
            set_option(i);
        if(number_of_option==0) operation[strlen(operation)-1]='\0';
        else option[number_of_option-1][strlen(option[number_of_option-1])-1]='\0';

        if(!strcmp(operation,"exit"))
            return 0;
        if(!strcmp(operation,"\0"))
            continue;

  
        for(int i=0;i<number_of_option;i++)
            if(!strcmp(option[i],"|")){
                do_pipe();
                continue;
            }

        for(int i=0;i<number_of_option;i++)    
            if(!strcmp(option[i],">")){
                do_redirection();
                continue;
            }



        if(!strcmp(operation,"pwd"))
            command_pwd();

        else if(!strcmp(operation,"cd"))
            command_cd();

        else if(!strcmp(operation,"ls"))
            command_ls();

        else if(!strcmp(operation,"mkdir"))
            command_mkdir();

        else if(!strcmp(operation,"rm"))
            command_rm();
            
        else if(!strcmp(operation,"rmdir"))
            command_rmdir();

        else if(!strcmp(operation,"mv"))
            command_mv();

        else if(!strcmp(operation,"cp"))
            command_cp();
        
        else if(!strcmp(operation,"cat"))
            command_cat();
        
        else
            system(now_order);

    }
}
