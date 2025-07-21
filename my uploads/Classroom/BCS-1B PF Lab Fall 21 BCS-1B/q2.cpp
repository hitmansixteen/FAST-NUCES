#include<iostream>
using namespace std;

bool hasSum(int data[], int size, int total)
{
    bool flag = 0;
    int sum;
    for (int i = 0; i < size && flag == 0; i++)
    {
        sum = 0;
        for (int j = i; j < size && flag == 0; j++)
        {
            sum = sum + data[j];
            if (sum == total)
            {
                flag = 1;
            }
        }
    }
    return flag;


}

int main()
{
    int data[9];
    int total;
    int n;
    bool flag;
    for (int i = 0; i < 9; i++)
    {
        cin >> data[i];
    }
    cout << "data: ";
    for (int i = 0; i < 9; i++)
    {
        cout << data[i] << "   ";
    }
    cout << endl;
    cout << "total = ";
    cin >> total;

    flag = hasSum(data, 9, total);

    if (flag == true)
        cout << endl << "Return: true";
    else
        cout << endl << "Return: false";


    return 0;
}