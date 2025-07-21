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
#define SIZE 1024

int main(int argc,char **argv){
	
    key_t key = ftok("shmfile",65);
  

    int shmid = shmget(key,1024,0666|IPC_CREAT);
  

    char *str = (char*) shmat(shmid,(void*)0,0);
	
	int fd = open(argv[1],O_RDONLY);
	read(fd,str,1024);
  
    
  
    printf("Data written in memory: %s\n",str);
    
    sleep(10);
    
      
    shmdt(str);
  
    return 0;
}
