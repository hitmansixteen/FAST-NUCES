#include<stdio.h>
void sort(int array[],int size,int order){
    int i,j;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            if(order==1 && array[j]>array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1]=temp;
            }else if(order==0&& array[j]<array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1]=temp;
            }
        }
    }
    
}
void findHighest(int array[],int size,int position){
        sort(array,size,0);
        if(position>=size || position<0){
            printf("Invalid position\n");
        }else{
            printf("The %d higest value in the array is: %d\n",position,array[position-1]);
        }
}

void print(int array[],int size){
    int j;
    for(j=0;j<size;j++){
        printf("%d ", array[j]);
    }
    printf("\n");
}
