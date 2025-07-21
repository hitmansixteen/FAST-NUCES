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
	
	char c;
	double arr[2];
	
	read(fd,&c,sizeof(char));
	read(fd,arr,sizeof(double)*2);
	
	double ans;
	
	if(c == '+'){
		ans=arr[0]+arr[1];
	}
	else if(c == '-'){
		ans=arr[0]-arr[1];
	}
	else if(c == '*'){
		ans=arr[0]*arr[1];
	}
	else if(c == '/'){
		ans=arr[0]/arr[1];
	}
	else{
		printf("Wrong operator sent! Sending 0 as answer\n");
		ans=0;
	}
	
	write(fd,&ans,sizeof(double));
	
	close(fd);


	return 0;
}

