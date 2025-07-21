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
	
	int arr[1024];
	int size = read(fd,arr,1024);
	size/=sizeof(int);
	int i,sum=0;
	for(i=0;i<size;i++){
		sum+=arr[i];
	
	}
	write(fd,&sum,sizeof(int));
	
	close(fd);


	return 0;
}

