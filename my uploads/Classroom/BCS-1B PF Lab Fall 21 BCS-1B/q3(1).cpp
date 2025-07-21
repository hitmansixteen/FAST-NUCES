#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream fin("inventory.txt");
    

    char name[10][20];
    int quantity[10];
    float price_per_unit[10];
    int n;
    int buy;
    bool flag=1;
    float bill=0;

    while(flag==1)
    {
        cout<<"Code"<<" "<<"Name"<<" "<<" "<<"Quantity"<<" "<<"Price per unit"<<endl;
        for(int i=0;i<10;i++)
        {
            fin>>name[i];
            fin>>quantity[i];
            fin>>price_per_unit[i];
            cout<<i+1<<"   "<<name[i]<<"   "<<"   "<<quantity[i]<<"   "<<price_per_unit[i]<<endl;

        }
        cout<<endl<<"Enter code of the item: ";
        cin>>n;
        while(n<1 || n>10)
        {
            cout<<endl<<"Enter code of the item again: ";
            cin>>n;
        }
        cout<<endl<<"Enter the quantity: ";
        cin>>buy;
        while(quantity[n-1]<buy)
        {
            cout<<endl<<"Enter the quantity again: ";
            cin>>buy;
        }
        quantity[n-1]=quantity[n-1]-buy;
        cout<<"Press 1 if you want to continue shopping and 0 to show the bill";
        cin>>flag;

        bill=bill+buy*price_per_unit[n-1];
    
    }
    cout<<"Your bill is: $"<<bill;
    ofstream fout("inventory.txt");
    for(int i=0;i<10;i++)
        {
            fout<<name[i]<<" ";
            fout<<quantity[i]<<" ";
            fout<<price_per_unit[i]<<" ";
            fout<<endl;
        }

    return 0;
}