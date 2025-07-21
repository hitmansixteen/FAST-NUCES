#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int n;

int fib(int n){
	if (n==0||n==1)
		return n;
	return fib(n-1)+fib(n-2);
}

void *func1(void* param){
	
	int size = (int)param;
	int *array = (int *)malloc(sizeof(int)*size);
	
	int i;
	for(i=0;i<size;i++)
		array[i]=fib(i);
	
	pthread_exit(array);
}

void *func2(void* param){
	
	int *array = (int *)param;
	
	int even=0;
	int i;
	
	for(i=0;i<n;i++){
		if(array[i]%2==0){
			even++;
		}
	}

	
	pthread_exit((void *)even);
}

void *func3(void* param){
	
	int *array = (int *)param;
	
	int odd=0;
	int i;
	
	for(i=0;i<n;i++){
		if(array[i]%2==1){
			odd++;
		}
	}

	
	pthread_exit((void *)odd);
}

void *func4(void* param){
	
	int *array = (int *)param;
	
	int sum=0;
	int i;
	
	for(i=0;i<n;i++){
		sum+=array[i];
	}
	
	FILE *file = fopen("sum.txt","w");
	
	fprintf(file,"%d",sum);
	
	fclose(file);
	
	pthread_exit((void *)sum);
}


int main(int argc,char**argv){
	
	pthread_t thread1,thread2,thread3,thread4;
	
	int num = atoi(argv[1]);
	n=num;
	pthread_create(&thread1,NULL,&func1,(void *)num);
	
	int *join1;
	
	pthread_join(thread1,(void**)&join1);
	
	printf("Thread ID %lu: ",thread1);
	int i;
	for(i=0;i<num;i++)
		printf("%d ",join1[i]);
	printf("\n");
	
	pthread_create(&thread2,NULL,&func2,(void*)join1);
	
	int join2;
	pthread_join(thread2,(void **)&join2);
	printf("Thread ID %lu even numbers are %d\n",thread2,join2);
	
	pthread_create(&thread3,NULL,&func3,(void*)join1);
	
	int join3;
	pthread_join(thread3,(void **)&join3);
	printf("Thread ID %lu odd numbers are %d\n",thread3,join3);
	
	pthread_create(&thread4,NULL,&func4,(void*)join1);
	
	int join4;
	pthread_join(thread4,(void **)&join4);
	printf("Thread ID %lu Sum is %d\n",thread4,join4);
	
	

	



	exit(0);
}
