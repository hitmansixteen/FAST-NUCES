#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<string.h>

int main(int argc,char *argv[]){
	char *pipe_name = argv[1];
	int fd = open(pipe_name,O_RDWR);
	
	char *string = argv[2];
	
	printf("%s\n",string);
	write(fd,string,strlen(string));
	
	close(fd);


	return 0;
}

