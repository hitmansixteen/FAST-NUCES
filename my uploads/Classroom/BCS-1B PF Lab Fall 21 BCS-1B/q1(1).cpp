#include<iostream>
using namespace std;

int sumOfN(int data[],int size,int ind, int n)
{
    int sum;
    if(size-ind>n)
    {
        sum=0;
        for(int i=ind;i<ind+n;i++)
        {
            sum=sum+data[i];
        }
    }
    else
    {
        sum=0;
        for(int i=ind;i<size;i++)
        {
            sum=sum+data[i];
        }
    }
    return sum;
        
}

int main()
{
    int data[9]={3,4,1,5,7,11,3,5,4};
    int ind;
    int n;
    cout<<"data: ";
    for (int i = 0; i < 9; i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;
    cout<<"Ind = ";
    cin>>ind;
    cout<<"N = ";
    cin>>n;

    cout<<endl<<"Return: "<<sumOfN(data,9,ind,n);
    

    return 0;
}