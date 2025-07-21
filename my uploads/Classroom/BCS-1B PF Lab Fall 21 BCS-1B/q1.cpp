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
    int data[9];
    for (int i = 0; i < 9; i++)
    {
        cin>>data[i];
    }
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