#include<iostream>
using namespace std;
int main() 
{
    int n;
    cout<<"Input Height: ";
    cin>>n;

    if(n<=9)
    {
        for(int row=n;row>=1;row--)
        {
            for(int num=1;num<=row;num++)
            {
                cout<<num;
            }
            for(int space=row*2;space<n*2-1;space++)
            {
                cout<<" ";
            }
            for(int rnum=row;rnum>=1;rnum--)
            {
                if(rnum!=n)
                    cout<<rnum;
            }
            cout<<endl;
        }
    }
    else
        cout<<"Height should not be greater than 9.\n";

    system("pause");
	return 0;
} 
