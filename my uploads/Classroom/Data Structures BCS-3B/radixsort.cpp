#include<iostream>
#include<math.h>
#include"myqueue.h"
using namespace std;

void radixsort(queue<string> q){
    int n, k, power, pos;
    string x,val;
    cout << "Enter the size: ";
    cin >> n;
    cout << "Enter strings(of same size!!): ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enqueue(x);
    }
    k = 0;
    x = q.front(); //assuming all the values have k number of characters
    k = x.length();
    queue<string>* key = new queue<string>[128];
    for (int i = k-1; i >= 0; i--)
    {
        while (!q.isEmpty())
        {
            val = q.front();
            q.dequeue();
            pos = val[i];
            key[pos].enqueue(val);
        }
        for (int j = 0; j < 128; j++)
        {
            while (!key[j].isEmpty()) {
                val = key[j].front();
                key[j].dequeue();
                q.enqueue(val);
            }
        }
        q.print();
    }



}
void radixsort(queue<int> array){
    int n,k,x,val,power,pos;
    cout<<"Enter the size: ";
    cin>>n;
    cout<<"Enter values: ";
    for (int i = 0; i < n; i++){
        cin>>x;
        array.enqueue(x);
    }
    k=0;
    x=array.front(); //assuming all the values have k number of digits
    while(x){
        x/=10;
        k++;
    }
    queue<int>* key = new queue<int>[10];
    for (int i = 0; i < k; i++)
    {
        while(!array.isEmpty())
        {
            val = array.front();
            power = pow(10,i);
            pos = (val / power)%10;
            array.dequeue();
            key[pos].enqueue(val);
        }
        for (int j = 0; j < 10; j++)
        {
            while(!key[j].isEmpty()){
                val = key[j].front();
                key[j].dequeue();
                array.enqueue(val);
            }
        }
        array.print();  
    }
    


    
}

int main()
{
    system("cls");
    queue<string> q;
    radixsort(q);   
    
    

    return 0;
}