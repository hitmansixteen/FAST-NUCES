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
	printf("Enter Operator: ");
	scanf("%c",&c);
	double arr[2];
	printf("Enter Operand1: ");
	scanf("%lf",&arr[0]);
	printf("Enter Operand2: ");
	scanf("%lf",&arr[1]);
	
	write(fd,&c,sizeof(char));
	write(fd,arr,sizeof(double)*2);
	
	sleep(3);
	
	double ans;
	
	read(fd,&ans,sizeof(double));
	
	printf("Answer: %f\n",ans);
	
	
	
	
	
	close(fd);


	return 0;
}

