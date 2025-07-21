#include<iostream>
using namespace std;

void selection_sort(int *&arr, int size){
	int min;
	for (int i = 0; i < size-1; i++)
	{
		min = i;
		for (int j = i+1; j < size; j++)
			if (arr[j] < arr[min])
				min = j;
		swap(arr[i], arr[min]);
	}
		
}

int binary_search(int *&arr,int l,int r, int element){
	
	if (l<=r){
		int mid = (l + r) / 2;

		if (arr[mid] == element)
			return mid;
		if (arr[mid]<element)
			return binary_search(arr, mid + 1, r, element);
		if (arr[mid] > element)
			return binary_search(arr, l, mid-1, element);
		
	}

	return -1;

}


int main(){
	
	int size,element;
	cout << "Enter the size of array: ";
	cin >> size;
	while (size < 1)
		cin >> size;

	int *arr = new int[size];
	cout << "Enter the Elements of the array: ";
	for (int i = 0; i < size; i++)
		cin >> arr[i];

	selection_sort(arr, size);

	cout << "\nSorted Array: ";
	for (int i = 0; i < size; i++)
		cout<< arr[i]<<" ";
	cout << endl;

	cout << "Search an element: ";
	cin >> element;

	int flag = binary_search(arr,0, size, element);

	if (flag == -1)
		cout << "\nNot Present\n";
	else{
		cout << "The searched element is present at index " << flag << endl;
	}

	system("pause");
	return 0;
}