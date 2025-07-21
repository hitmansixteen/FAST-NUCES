#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<string.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<fcntl.h>

#define KEY 99999
#define SIZE 4096

int main(int argc,char **argv){
	key_t key = ftok("shmfile",65);
  
    int shmid = shmget(key,1024,0666|IPC_CREAT);
  
    char *str = (char*) shmat(shmid,(void*)0,0);
  
  	char buff[1024];
  	char num[1024];
  	
  	
  	strncpy(buff,str,1024);
  	float avg;
  	float sum=0;
  	int i;
  	float k=0;
  	int j=0;
  	for(i=0;buff[i]!='\0';i++){
  		num[j] = buff[i];
  		if(buff[i+1]==' ' || buff[i+1] == '\0'){
  			sum += atoi(num);
  			k++;
  			j=0;
  		}
  		else
  			j++;
  	}
  	avg = sum/k;
  	
  	printf("SUM: %f\n",sum);
  	printf("Average: %f\n",avg);
  	
    
      
    
    shmdt(str);
    
    
    shmctl(shmid,IPC_RMID,NULL);
}
