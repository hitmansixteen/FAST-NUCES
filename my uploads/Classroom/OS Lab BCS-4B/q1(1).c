#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(int argc,char **argv){
	FILE* file = fopen(argv[1],"r");
	if(!file){
		printf("Can't open file\n");
		return 0;
	}
	int sizeOfStr = strlen(argv[2]);
	
	char *str = (char *)malloc(sizeOfStr * sizeof(char));
	str = argv[2];
	
	fseek(file,0,SEEK_END);
	int sizeOfFile = ftell(file);
	fseek(file,0,SEEK_SET);
	char *strFile = (char *)malloc(sizeOfFile * sizeof(char));
	fread(strFile,sizeof(char),sizeOfFile,file);
	
	char *p1,*p2,*p3;
	p1 = strFile;
	p2 = str;
	int i,j;
	int flag=0;
	for(i = 0; i<strlen(strFile); i++)
    {
    if(*p1 == *p2)
    {
		p3 = p1;
		for(j = 0;j<strlen(str);j++)
		{
		if(*p3 == *p2)
		{
		  p3++;
		  p2++;
		} 
		else break;
		}
		p2 = str;
		if(j == strlen(str))
		{
		 	flag = 1;
			printf("\nSubstring found at index : %d\n",i);
		}
    }
    p1++; 
	}
	if(flag==0)
	{
	   printf("Substring Not found\n");
	}
	fclose(file);
	
	

	return 0;
}
