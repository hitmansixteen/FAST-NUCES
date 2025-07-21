#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>


int main(int argc,char **argv){
	FILE* file = fopen(argv[1],"r");
	if(!file){
		printf("Can't open file\n");
		return 0;
	}
	int pid = fork();
	char ch;
	int i=0;
	int a=0,b=0,c=0,d=0,e=0,f=0,g=0;
	if(pid==0){
		printf("Child Process Start\n");
		while((ch=fgetc(file))!=EOF){
			if(ch=='(')
				a++;
			else if(ch=='"')
				b++;
			else if(ch==',')
				c++;
			else if(ch=='.')
				d++;
			else if(ch==';')
				e++;
			else if(ch==':')
				f++;
			else if(ch==')')
				g++;
			i++;
	
		}
		printf("( = %d\n",a);
		printf("\" = %d\n",b);
		printf(", = %d\n",c);
		printf(". = %d\n",d);
		printf("; = %d\n",e);
		printf(": = %d\n",f);
		printf(") = %d\n",g);
		
		fclose(file);
	} else{
		wait(NULL);
		printf("Program completed\n");
		
	}
	
	

	return 0;
}
