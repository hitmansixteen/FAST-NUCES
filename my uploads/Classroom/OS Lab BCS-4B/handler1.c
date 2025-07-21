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
	
	int arr[5] = {1,2,3,4,5};
	int size = sizeof(int)*5;
	
	write(fd,arr,size);
	
	sleep(3);
	int sum;
	
	read(fd,&sum,sizeof(int));
	
	printf("Sum is %d\n",sum);
	
	close(fd);


	return 0;
}

