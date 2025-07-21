#include <iostream>
using namespace std;

void input(int *&new_set, int &size)
{
    cout << "Enter the size of set: ";
    cin >> size;
    new_set = new int[size];

    cout << "Enter " << size << " elements: ";

    for (int i = 0; i < size; i++)
    {
        cin >> new_set[i];
    }
}

void output(int *arr, int size)
{
    cout << "Resultant Set: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;
}

bool isElement(int *arr, int size, int x)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
            return true;
    }
    return false;
}

void intersection_set(int *arr1, int size1, int *arr2, int size2)
{

    int size = 0;

    for (int i = 0; i < size1; i++)
    {
        if (isElement(arr2, size2, arr1[i]) == true)
            size++;
    }

    int *Interset = new int[size];
    int index = 0;
    for (int i = 0; i < size1; i++)
    {
        if (isElement(arr2, size2, arr1[i]) == true)
            Interset[index++] = arr1[i];
    }

    output(Interset, size);

    delete[] Interset;
    Interset = nullptr;
}

void union_set(int *arr1, int size1, int *arr2, int size2)
{
    int index = 0;

    int *unionset = new int[index + 1];

    for (int i = 0; i < size1; i++)
    {
        if (isElement(arr2, size2, arr1[i]) == true)
            unionset[index++] = arr1[i];
    }
    for (int i = 0; i < size1; i++)
    {
        if (isElement(arr2, size2, arr1[i]) != true)
            unionset[index++] = arr1[i];
    }
    for (int i = 0; i < size2; i++)
    {
        if (isElement(arr1, size1, arr2[i]) != true)
            unionset[index++] = arr2[i];
    }

    output(unionset, index);

    delete[] unionset;
    unionset = nullptr;
}

void difference_set(int *arr1, int size1, int *arr2, int size2)
{
    int index = 0;

    int *diffset = new int[index + 1];

    for (int i = 0; i < size1; i++)
    {
        if (isElement(arr2, size2, arr1[i]) != true)
            diffset[index++] = arr1[i];
    }

    output(diffset, index);

    delete[] diffset;
    diffset = nullptr;
}

void complement_set(int *arr1, int size1, int *arr2, int size2)
{
    int index = 0;

    int *compset = new int[index + 1];

    for (int i = 0; i < size1; i++)
    {
        if (isElement(arr2, size2, arr1[i]) != true)
            compset[index++] = arr1[i];
    }

    output(compset, index);

    delete[] compset;
    compset = nullptr;
}

int main()
{
    system("cls");

    int size1;
    int *arr1;
    cout << "=====Set 1=====\n";
    input(arr1, size1);
    int size2;
    int *arr2;
    cout << "=====Set 2=====\n";
    input(arr2, size2);

    int option;

    cout << "==========Calculator Menu==========\n";
    cout << "1.Set Intersection\n";
    cout << "2.Set Union\n";
    cout << "3.Set Difference\n";
    cout << "4.Set Complement\n";

    cout << "What Operation do you want to perform?\nOption: ";
    cin >> option;

    if (option == 1)
        intersection_set(arr1, size1, arr2, size2);
    else if (option == 2)
        union_set(arr1, size1, arr2, size2);
    else if (option == 3)
        difference_set(arr1, size1, arr2, size2);
    else if (option == 4)
        complement_set(arr1, size1, arr2, size2);

    delete[] arr1;
    arr1 = nullptr;
    delete[] arr2;
    arr2 = nullptr;

    return 0;
}