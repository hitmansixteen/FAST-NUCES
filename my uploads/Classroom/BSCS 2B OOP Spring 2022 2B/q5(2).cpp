#include<iostream>
using namespace std;


void copyArray(int* arr, int *&arr1, int size)
{
	for(int i = 0; i < size; i++)
	{
		arr1[i]=arr[i];
	}
	
}

int reduceArray(int *arr, int *&arr1, int size)
{
	int size1=size;
	int index;
	
	for (int i = 0; i < size1; i++)
	{
		index=0;
		for (int j = 0; j < size1; j++)
		{
			if(arr[index]<arr[j])
				index=j;
		}
		swap(arr[index],arr[size1-1]);
		size1--;
		
	}


	bool found;
	int x=1;

	copyArray(arr,arr1,size);
	delete []arr;
	arr = nullptr;

	arr= new int[x];

	for (int i = 1; i < size; i++)
	{
		found=0;
		for(int j=i-1;j>0&&found==0;j--)
		{
			if(arr1[j]==arr1[i])
				found=1;
			
		}
		if(found==0)
		{
			arr[x-1]=arr1[i];
			x++;
		}
			
	}
	return x-1;
}

int main()
{
	int* arr;
	int* arr1;
	int size;
	cout<<"Enter Size: ";
	cin>>size;

	arr = new int[size];
	arr1 = new int[size];

	cout<<"Enter elements of array: ";

	for(int i = 0; i < size; i++)
	{
		cin>>arr[i];
	}

	copyArray(arr,arr1,size);

	int newsize= reduceArray(arr,arr1,size);

	cout<<"Array after reduction is: ";
	for (int i = 0; i < newsize; i++)
	{
		cout<<arr[i]<<" ";
	}









	
	

	


	
	
	system("pause");
	return 0;
}