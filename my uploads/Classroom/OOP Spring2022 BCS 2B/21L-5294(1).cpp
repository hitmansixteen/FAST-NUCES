#include <iostream>
#include <fstream>
using namespace std;

void deallocate(int **&ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] ptr[i];
    }

    delete[] ptr;
    ptr = nullptr;
}

void Input(int **&value_arr, int **&index_arr, int &row, int &col)
{
    char myfile[30];
    cout << "Enter Name of the file: ";
    cin >> myfile;
    ifstream fin(myfile);
    fin >> row;
    fin >> col;

    value_arr = new int *[row];
    index_arr = new int *[row];

    int cols;
    for (int i = 0; i < row; i++)
    {
        fin >> cols;

        value_arr[i] = new int[cols];
        index_arr[i] = new int[cols + 1];
        index_arr[i][0] = cols;
        for (int j = 0; j < cols; j++)
        {
            fin >> index_arr[i][j + 1];
            fin >> value_arr[i][j];
        }
    }
    fin.close();
}

void Output(int **value_arr, int **index_arr, int row, int col)
{
    int index;
    for (int i = 0; i < row; i++)
    {
        index = 0;
        for (int j = 0; j < col; j++)
        {
            if (index_arr[i][index + 1] == j)
            {
                cout << value_arr[i][index] << " ";
                index++;
            }
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

void Transpose(int **&value_arr, int **&index_arr, int row, int col)
{
    int **transpose_value = new int *[col];
    int **transpose_index = new int *[col];
    int count;

    for (int i = 0; i < col; i++)
    {
        count = 0;
        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < index_arr[j][0]; k++)
            {
                if (index_arr[j][k + 1] == i)
                    count++;
            }
        }

        transpose_value[i] = new int[count];
        transpose_index[i] = new int[count + 1];
        transpose_index[i][0] = count;
    }
    int index;
    for (int i = 0; i < col; i++)
    {
        index = 0;
        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < index_arr[j][0]; k++)
            {
                if (index_arr[j][k + 1] == i)
                {
                    transpose_index[i][index + 1] = j;
                    transpose_value[i][index] = value_arr[j][k];

                    index++;
                }
            }
        }
    }
    swap(row, col);
    for (int i = 0; i < col; i++)
    {
        delete[] value_arr[i];
        delete[] index_arr[i];
    }
    delete[] value_arr;
    delete[] index_arr;

    value_arr = transpose_value;
    index_arr = transpose_index;
}

int main()
{
    system("cls");

    int **value_arr1, **index_arr1;
    int row1, col1;

    Input(value_arr1, index_arr1, row1, col1);
    cout << "value_arr 1: \n";
    Output(value_arr1, index_arr1, row1, col1);
    Transpose(value_arr1, index_arr1, row1, col1);
    cout << "Result: \n";
    Output(value_arr1, index_arr1, row1, col1);
    deallocate(value_arr1, row1);
    deallocate(index_arr1, row1);

    return 0;
}