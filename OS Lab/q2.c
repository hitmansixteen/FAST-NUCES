#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int N;

void *func(void* param){
	
	int i;
	int summation=0;
	for(i=1;i<=N;i++)
		summation+=i;
	
	printf("Summation of %d is %d\n",N,summation);
	
	pthread_exit(NULL);
}

int main(){
	
	printf("Enter number: ");
	scanf("%d",&N);
	
	pthread_t thread;
	

	pthread_create(&thread,NULL,&func,NULL);
	pthread_join(thread,NULL);
	
	



	exit(0);
}
