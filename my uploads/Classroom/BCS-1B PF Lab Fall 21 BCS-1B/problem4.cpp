#include<iostream>
using namespace std;
int main()
{
    int d[10];
    int size = 10,seg,index,temp,size1=10,max;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter Number: ";
        cin >> d[i]; 
    }
    
    cout << "Enter segregation value.";
    cin >> seg;
    


    
    for (int i = 0; i < size; i++)
    {
        if (seg < d[i])
        {
            max = d[0];
            index = 0;
            for (int j = 0; j < size1; j++)
            {
                if (max < d[j])
                {
                    max = d[j];
                    index = j;
                }

            }

            temp = d[size1 - 1];
            d[size1 - 1] = d[index];
            d[index] = temp;
            size1--;
        }

    }
    for (int i = 0; i < size; i++)
    {
        cout << d[i] << " ";
    }


    return 0;
}