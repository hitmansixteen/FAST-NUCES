#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char **argv){
	
	
	int file = open(argv[1],O_RDONLY);
	
	dup2(file,0);
	
	char data[500];
	
	int status = read(0,data,500);
	
	close(file);
	
	file = open(argv[2],O_WRONLY);
	
	dup2(file,1);
	
	printf("%s\n",data);
	
	close(file);

	return 0;
}
