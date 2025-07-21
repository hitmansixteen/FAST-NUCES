#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char **argv){
	
	
	int file = open(argv[2],O_WRONLY);
	
	dup2(file,1);

	execlp("cat","cat",argv[1],NULL);
	
	close(file);

	return 0;
}
