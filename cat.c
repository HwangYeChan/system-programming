void command_cat(){
    char ch;
    int fd;
    for(int i=0;i<number_of_option;i++){
        fd=open(option[i],O_RDONLY);
        while(read(fd,&ch,1))
            write(1,&ch,1);
        close(fd);
    }
}