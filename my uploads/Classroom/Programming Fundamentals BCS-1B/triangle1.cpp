#include<iostream>
using namespace std;
int main() {
    int N;
    cout << "N: ";
    cin >> N;
    for(int i=1; i<=N;i++)
    {
        for(int j=1;j<i;j++)
        {
            cout<<" ";
        }
        for(int k=i;k<=N;k++)
        {
            cout<<"*";
        }
        cout<<endl;
        
    }

    system("pause");
	return 0;
} 
