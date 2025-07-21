#include<stdio.h>
//#include"header.h"

int main(int argc,char **argv){
    int order = atoi(argv[argc-1]);
    //printf("%d\n",order);
    int size = argc-2;
    printf("%d %d\n",order,size);
    
    int array[100];
    int i,j;
    for(i=size,j=0;i>0;i--,j++){
        array[j] = atoi(argv[i]);
    }
    
    printf("Array Element: ");
    print(array,size);
    sort(array,size,order);
    printf("Sorted Element: ");
    print(array,size);
    findHighest(array,size,2);
    
    
    return 0;
}

