#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<wait.h>

int main(){
	int arr[5][5] = {{500,200,12,13,15},{140,15,160,170,20},{20,40,700,1000,11},{10,20,20,20,20},{20,10,12,10,1000}};
	pid_t pid = fork();
	
	if(pid == 0){
		printf("I am child having id %d\n",getpid());
		printf("My parent's id is %d\n",getppid());
		printf("frequency count\n");
		int i,j;
		int a[10001]={0};
		
		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
				a[arr[i][j]]++;
			}	
		}
		for(i=0;i<=1000;i++){
			if(a[i]!=0){
				printf("Number %d freq %d\n",(i),a[i]);
			}
		}
		
	
	}
	else{
		wait(NULL);
		int upperSum=0;
		int lowerSum=0;
		int i,j;
		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
				if(i<=j) upperSum+=arr[i][j];
				if(i>=j) lowerSum+=arr[i][j];
			}	
		}
		
		printf("My child id is %d\n",pid);
		printf("I am parent having id %d\n",getpid());
		printf("Upper Triangular sum is %d\n",upperSum);
		printf("Lower Triangular sum is %d\n",lowerSum);
	}
	

	return 0;
}
