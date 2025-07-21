#include<iostream>
using namespace std;
int main() 
{
     int count;
     int array[10];
     int freq[10];
     for(int i=0;i<10;i++)
     {
         cout<<"Enter Number: ";
         cin>>array[i];
         freq[i]=1;
     }
     for(int j=0;j<10;j++)
     {
         count=1;
         for(int k=j+1;k<10;k++)
         {
             if (array[j]==array[k])
             {
                 count++;
                 freq[k]=0;
             }
             
         }
         if(freq[j]!=0)
         {
             freq[j]=count;
         }
     }
     for(int l=0;l<10;l++)
     {
         if(freq[l]!=0)
            cout<<array[l]<<" occurs "<<freq[l]<< " times.\n";
     }
     
    system("pause");
	return 0;
} 
