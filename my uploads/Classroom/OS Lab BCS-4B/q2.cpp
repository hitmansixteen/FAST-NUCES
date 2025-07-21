#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include<pthread.h>
#include <sys/stat.h>
#include <iostream>



using namespace std;

int size;
void* func1(void* param){
	char *map = (char*)param;
	for(int i=0;i<50;i++){
		if(map[i]>='0'&&map[i]<='9'){
			map[i]=' '; 
		}
	}

	pthread_exit(NULL);
}
void* func2(void* param){
char *map = (char*)param;
	for(int i=50;i<100;i++){
		if(map[i]>='0'&&map[i]<='9'){
			map[i]=' '; 
		}
	}
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	
	int fd = open(argv[1], O_RDWR);
	
	
	char *map = (char*)mmap(NULL, 101, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	
	pthread_t thread1,thread2;
	
	pthread_create(&thread1,NULL,&func1,(void *)map);
	pthread_create(&thread1,NULL,&func2,(void *)map);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	munmap(map, 101);
	close(fd);
	
	
	
	
	return 0;
	
	

}
