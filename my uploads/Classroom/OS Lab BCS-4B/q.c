#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <pthread.h>


void *func(void *param){
	int *arr = (int*)param;
	
	int count[10];
	
	int i;
	for(i=0;i<10;i++){
		count[i]=0;
	}
	
	int x;
	for(i=0;i<10;i++){
		x=arr[i];
		count[x]++;
	}
	
	for(i=0;i<10;i++){
		printf("%d ",count[i]);
	}
	printf("\n");
	
	for(i=0;i<10;i++){
		if(count[i]==2){
			printf("%d is repeated twice\n",i);
		}
	}

	pthread_exit(NULL);
}

int main(int argc,char **argv){
	pthread_t t;
	int arr[10];
	int i=0;
	for(i=0;i<10;i++){
		do{
		printf("Enter number %d: ",i);
		scanf("%d",&arr[i]);				
		}while(arr[i]>9 || arr[i]<1);
	}
	
	pthread_create(&t,NULL,&func,(void *)arr);
	
	pthread_join(t,NULL);
	
	return 0;

	
}
