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
                cout << value_arr[i][index] << "  ";
                index++;
            }
            else
                cout << "0  ";
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

void Addition(int **value_arr1, int **index_arr1, int **value_arr2, int **index_arr2, int row, int col, int **&result_value, int **&result_index)
{
    result_value = new int *[row];
    result_index = new int *[row];

    int index, index1, index2, count, sum, value1, value2;
    bool flag;

    for (int i = 0; i < row; i++)
    {
        count = 0, flag = 0, index1 = 0, index2 = 0;
        for (int j = 0; j < col; j++)
        {
            if (index_arr1[i][index1 + 1] == j)
            {
                index1++;
                flag = 1;
            }
            if (index_arr2[i][index2 + 1] == j)
            {
                index2++;
                flag = 1;
            }
            if (flag == 1)
            {
                count++;
                flag = false;
            }
        }
        result_value[i] = new int[count];
        result_index[i] = new int[count + 1];
        result_index[i][0] = count;
    }

    for (int i = 0; i < row; i++)
    {
        flag = 0, index1 = 0, index2 = 0, index = 0;
        for (int j = 0; j < col; j++)
        {
            if (index_arr1[i][index1 + 1] == j)
            {
                value1 = value_arr1[i][index1];
                index1++;
                flag = 1;
            }
            if (index_arr2[i][index2 + 1] == j)
            {
                value2 = value_arr2[i][index2];
                index2++;
                flag = 1;

                if (flag == 1)
                {
                    flag = false;
                    sum = value1 + value2;
                    result_value[i][index] = sum;
                    result_index[i][index + 1] = j;
                    value1 = 0, value2 = 0;
                    index++;
                }
            }
        }
    }
}

void Multiplication(int **value_arr1, int **index_arr1, int **value_arr2, int **index_arr2, int row1, int col1, int row2, int col2, int **&result_value, int **&result_index)
{
    result_value = new int *[row1];
    result_index = new int *[row1];

    int index, index1, sum, count, value1, value2;

    for (int i = 0; i < row1; i++)
    {
        value1 = 0, value2 = 0, sum = 0, count = 0, index1 = 0;
        for (int j = 0; j < row1; j++)
        {
            for (int k = 0; k < row2; k++)
            {
                if (index_arr1[i][index1 + 1] == k)
                {
                    value1 = value_arr1[i][index1 + 1];
                    index1++;
                }
                for (int l = 0; l < index_arr2[k][0]; l++)
                {
                    if (index_arr2[k][l + 1] == j)
                    {
                        value2 = value_arr2[k][l];
                    }
                }
                sum += value1 * value2;
                value1 = 0, value2 = 0;
            }
            if (sum != 0)
            {
                count++;
            }
            sum = 0, index1 = 0;
        }
        result_value[i] = new int[count];
        result_index[i] = new int[count + 1];
        result_index[i][0] = count;
    }

    for (int i = 0; i < row1; i++)
    {
        value1 = 0, value2 = 0, sum = 0, count = 0, index1 = 0, index = 0;
        for (int j = 0; j < row1; j++)
        {
            for (int k = 0; k < row2; k++)
            {
                if (index_arr1[i][index1 + 1] == k)
                {
                    value1 = value_arr1[i][index1];
                    index1++;
                }
                for (int l = 0; l < index_arr2[k][0]; l++)
                {
                    if (index_arr2[k][l + 1] == j)
                    {
                        value2 = value_arr2[k][l];
                    }
                }
                sum += value1 * value2;
                value1 = 0, value2 = 0;
            }
            if (sum != 0)
            {
                result_value[i][index] = sum;
                result_index[i][index + 1] = j;
                index++;
            }
            sum = 0, index1 = 0;
        }
    }
}

int main()
{
    system("cls");

    int **value_arr1, **index_arr1, **value_arr2, **index_arr2;
    int row1, col1, row2, col2;
    int option;
    cout << "1.Transpose\n2.Addition\n3.Multiplication\nOption: ";
    cin >> option;
    if (option == 1)
    {
        Input(value_arr1, index_arr1, row1, col1);
        cout << "Matrix 1: \n";
        Output(value_arr1, index_arr1, row1, col1);
        Transpose(value_arr1, index_arr1, row1, col1);
        cout << "Result: \n";
        Output(value_arr1, index_arr1, row1, col1);

        deallocate(value_arr1, row1);
        deallocate(index_arr1, row1);
    }
    else
    {
        Input(value_arr1, index_arr1, row1, col1);
        cout << "Matrix 1: \n";
        Output(value_arr1, index_arr1, row1, col1);
        Input(value_arr2, index_arr2, row2, col2);
        cout << "Matrix 2: \n";
        Output(value_arr2, index_arr2, row2, col2);
        if (option == 2)
        {
            if (row1 == row2 && col1 == col2)
            {
                int **add_value, **add_index;
                Addition(value_arr1, index_arr1, value_arr2, index_arr2, row1, col1, add_value, add_index);
                cout << "Result: \n";
                Output(add_value, add_index, row1, col1);
                deallocate(add_value, row1);
                deallocate(add_index, row1);
            }
            else
                cout << "Addition can't be computed";
        }
        if (option == 3)
        {
            if (col1 == row2)
            {
                int **mult_value, **mult_index;
                Multiplication(value_arr1, index_arr1, value_arr2, index_arr2, row1, col1, row2, col2, mult_value, mult_index);
                cout << "Result: \n";
                Output(mult_value, mult_index, row1, col1);
                deallocate(mult_value, row1);
                deallocate(mult_index, row1);
            }
            else
                cout << "Multiplication can't be computed";
        }

        deallocate(value_arr1, row1);
        deallocate(index_arr1, row1);
        deallocate(value_arr2, row2);
        deallocate(index_arr2, row2);
    }

    return 0;
}