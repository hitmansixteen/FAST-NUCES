#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	char buff[1024];
	int fd1[2];
	int fd2[2];
	pipe(fd1);
	pipe(fd2);
	
	if(fork()){
		int f = open("file.txt",O_RDONLY);
		char c;
		int i=0;
		while(read(f,&c,1)){
			buff[i] = c;
			i++;
		}
		i--;
		buff[i]='\0';
		i++;				
		close(f);
		
		
		write(fd1[1],buff,i);
		wait(NULL);
		read(fd2[0],buff,1024);
		for(i=0;buff[i]!='\0';i++){}
		int u = open("updated.txt",O_WRONLY);
		write(u,buff,i);
		close(u);
			
	}
	else{
	
		read(fd1[0],buff,1024);
	
		int i,j;
		
		for(i=0;buff[i]!='\0';i++){}
		for(j=0;j<i;j++){
			if(buff[j] == '&' || buff[j] == '@' || buff[j] == '#' || buff[j] == '%' || buff[j] == '*' || buff[j] == '?' || buff[j] == '$' || buff[j] == '"' || buff[j] == '~')
				buff[j] = ' ';
		
		}
		
		write(fd2[1],buff,i+1);
		
	
	}
	return 0;
}
