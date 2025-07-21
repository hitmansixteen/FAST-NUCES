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
	
	char string[1024];
	
	int size = read(fd,string,1024);
	
	int i;
	for(i=0;i<strlen(string);i++){
		if(string[i]>=65 && string[i]<=90){
			string[i]+=32;
		}
		else if(string[i]>=97 && string[i]<=122){
			string[i]-=32;
		}
	
	}
	string[size] = '\0';
	
	printf("%s\n",string);
	
	
	 
	close(fd);


	return 0;
}
