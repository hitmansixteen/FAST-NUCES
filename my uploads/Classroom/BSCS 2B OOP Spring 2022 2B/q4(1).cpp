//#include<iostream>
//using namespace std;
//
//void Input(char *&arr,int &size)
//{
//	bool flag=0;
//	int i=0;
//	for(;flag==0;i++)
//	{
//		if(i==size)
//			size*=2;
//		cin>>arr[i];
//		if(arr[i]=='q')
//		{
//			flag=1;
//		}	
//	}
//	size=i;
//}
//
//void reverse(char *arr,int size)
//{
//	int start=0;
//	int end=size-1;
//
//	while(start<end)
//	{
//		swap(arr[start],arr[end]);
//
//		start++;
//		end--;
//	}
//
//
//}
//
//void Output (char *arr, int size)
//{
//	cout<<"=====Reversed Array is======\n";
//	for (int i= 0; i<size; i++)
//	{
//		cout<<arr[i]<<" ";
//	}
//
//	cout<<endl;
//}
//
//int main()
//{
//	int size=5;
//	
//	char *ptr = new char[size];
//
//	Input(ptr,size);
//	reverse(ptr,size);
//	Output(ptr,size);
//
//
//	delete[] ptr;
//	
//
//
//	
//	
//	system("pause");
//	return 0;
//}