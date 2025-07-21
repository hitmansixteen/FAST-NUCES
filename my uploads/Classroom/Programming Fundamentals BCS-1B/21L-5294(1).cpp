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
    int mySum;
    bool d;
    int a[8]={1, 4, 5, 6, 7, 8, 9, 2};



    cout << "Enter value of sum: ";
    cin >> mySum;

    d = hasSum(a, 8, mySum);

    if (d == 1)
    {
        cout << "True";
    }
    else
        cout << "False";

    return 0;
}