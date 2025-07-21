#include<iostream>
using namespace std;

void merge(int *arr, int l, int r, int mid){
	int i, j,k;
	int n1 = mid + 1 - l;
	int n2 = r - mid;

	int *a = new int[n1];
	int *b = new int[n2];

	for (i = 0; i < n1; i++)
		a[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		b[j] = arr[mid+1 + j];

	i = 0, j = 0, k = l;
	while (i < n1 && j < n2){
		if (a[i] <= b[j]){
			arr[k] = a[i];
			i++; k++;
		}
		else{
			arr[k] = b[j];
			j++; k++;
		}
	}

	while (i < n1){
		arr[k] = a[i];
		i++; k++;
	}
	while (j < n2){
		arr[k] = b[j];
		j++; k++;
	}

	delete[] a;
	delete[] b;
}

void merge_sort(int *arr, int l,int r){

	if (r <= l)
		return;

	int mid = (l + r) / 2;
	merge_sort(arr, l, mid);
	merge_sort(arr, mid + 1, r);
	merge(arr, l, r, mid);
		
}


int main(){

	int arr[] = { 2,1,10,7,3,6,5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Unsorted array: ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
	merge_sort(arr,0, size-1);

	cout << "\nSorted Array: ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;




	system("pause");
	return 0;
 }