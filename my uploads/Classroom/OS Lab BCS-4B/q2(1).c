#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char **argv){
	
	
	int file = open(argv[1],O_WRONLY);
	
	dup2(file,1);
	
	
	close(file);

	return 0;
}
