#include<iostream>
using namespace std;

bool hasSum(int a[], int size, int mySum)
{
    bool sum = 0;
    
    for (int i = 0; i < size - 2; i++)
    {
        if ((a[i] + a[i + 1] + a[i + 2]) == mySum)
        {
            sum = 1;
        }

    }
    
    return sum;
}

int main()
{
    int size, mySum;
    bool d;
    cout << "Enter the size of the array: ";
    cin >> size;
    int a[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter Number " << i + 1 << " of array: ";
        cin >> a[i];
    }



    cout << "Enter value of sum: ";
    cin >> mySum;

    d = hasSum(a, size, mySum);

    if (d == 1)
    {
        cout << "True";
    }
    else
        cout << "False";

    return 0;
}

