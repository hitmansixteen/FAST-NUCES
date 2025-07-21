#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
#include<sys/types.h>


int main(int argc,char **argv){
	
	char *p = argv[1];
	pid_t pid1,pid2;
	pid1 = fork();
	
	if(pid1==0){
		printf("I am child 1 my pid is %d and my parent pid is %d\n",getpid(),getppid());
		
		printf("%s\n",p);
		execv("./c1",p);
		
	}
	else{
		waitpid(pid1,NULL,0);
		pid2=fork();
	}
	
	
	
	if(pid2==0){
		printf("I am child 2 my pid is %d and my parent pid is %d\n",getpid(),getppid());
	
	}else{
		waitpid(pid2,NULL,0);
	}
	
	
	
	
	

	return 0;
}
