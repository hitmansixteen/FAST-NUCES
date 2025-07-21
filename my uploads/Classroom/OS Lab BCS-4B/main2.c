#include <stdio.h>

int main(int argc,char **argv){
   
    float total = argc-1;
    int i;
    int sum=0;
    float average=0;
    while(--argc){
        printf("%s\n",argv[argc]);
        sum+=atoi(argv[argc]);
    }
    printf("The Sum is: %d!\n", sum);
    average = sum/total;
    printf("The Average is: %f!\n", average);
    return 0;
}
