#include<iostream>
using namespace std;
int main()
{
    int array[10];
    int disarray[10];
    int index, n = 0;
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter Number: ";
        cin >> array[i];
    }

    for (int i = 0; i < 10; i++)
    {
        index = 0;

        for (int j = 0; j <= i; j++)
        {
            if (array[i] == array[j])
            {
                index++;
            }
            
        }
        if (index <= 1)
        {
            disarray[n] = array[i];
            n++;
        }

        
    }

    for (int i = 0; i < n; i++)
    {
        cout << disarray[i] << " ";
    }
    return 0;
}