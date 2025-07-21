#include<iostream>
using namespace std;


char** AllocateMemory(int& rows,int& cols)
{
	cout<<"Enter Rows: ";cin>>rows;
	cout<<"Enter Columns: ";cin>>cols;

	char **ptr = new char*[rows];

	for(int i=0;i<cols;i++)
	{
		ptr[i] = new char[cols];
	}

	return ptr;
}

void InputMatrix(char **matrix,int rows,int cols)
{
	cout<<"Input Matrix: ";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin>>matrix[i][j];
		}
	}
	
	cout<<endl;
}

void OutputMatrix(char **matrix,int rows,int cols)
{
	cout<<"Output Matrix: \n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
}

void char_seperate(char **matrix,char *&alphabets,char *&numbers,char *&specialchar,int rows,int cols)
{
	int index_a=0;int index_n=0;int index_s=0;

	alphabets = new char[index_a+1];
	numbers = new char[index_n+1];
	specialchar = new char[index_s+1];


	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			if((matrix[i][j]>='A'&&matrix[i][j]<='Z')||(matrix[i][j]>='a'&&matrix[i][j]<='z'))
				matrix[i][j]=alphabets[index_a++];
			else if(matrix[i][j]>='0'&&matrix[i][j]<='9')
				matrix[i][j]=numbers[index_n++];
			else
				matrix[i][j]=specialchar[index_s++];

		}
	}
	cout<<"alphabets ";
	for (int i = 0; i < index_a; i++)
	{
		cout<<alphabets[i]<<" ";
	}
	cout<<endl;
	cout<<"Numbers ";
	for (int i = 0; i < index_n; i++)
	{
		cout<<numbers[i]<<" ";
	}
	cout<<endl;
	cout<<"specialchar ";
	for (int i = 0; i < index_s; i++)
	{
		cout<<specialchar[i]<<" ";
	}
	cout<<endl;
}


int main()
{
	int rows,cols;
	char **ptr = AllocateMemory(rows,cols);
	InputMatrix(ptr,rows,cols);
	OutputMatrix(ptr,rows,cols);

	char *alphabets,*numbers,*specialchar;

	char_seperate(ptr,alphabets,numbers,specialchar,rows,cols);

	

	
	system("pause");
	return 0;
}