//#include<iostream>
//using namespace std;
//
//int binarysearch(int *arr, int l, int r, int key){
//
//	if (l <= r){
//		int mid = (l + r) / 2;
//		if (arr[mid] == key)
//			return mid;
//		if (arr[mid]>key)
//			return binarysearch(arr, l, mid - 1, key);
//		if (arr[mid]<key)
//			return binarysearch(arr, mid + 1, r, key);
//	}
//	return -1;
//}
//
//int main(){
//
//	int arr[100];
//	for (int i = 0; i < 100; i++)
//		arr[i] = i;
//	int key;
//
//	cout << "Enter Number you want to find: ";
//	cin >> key;
//	int k = binarysearch(arr, 0, 99, key);
//	if (k != -1)
//		cout << "Key found index " << k << endl;
//	else
//		cout << "index not found\n";
//
//
//	system("pause");
//	return 0;
//}