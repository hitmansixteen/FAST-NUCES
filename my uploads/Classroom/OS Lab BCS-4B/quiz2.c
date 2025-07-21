#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<wait.h>

int main(int argc,char *argv[]){
	
	char *str = argv[1];
	
	int i;
	for(i=0;str[i]!='\0';i++);
	
	printf("The length of your name is %d\n",i);

	return 0;
}
