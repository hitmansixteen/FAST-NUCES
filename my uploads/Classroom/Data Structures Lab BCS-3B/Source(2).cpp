#include<iostream>
using namespace std;

template<typename k,typename v>
class MinHeap{
	class HeapItem{
	public:
		k key;
		v value;
		HeapItem(){
			key = value = 0;
		}
		HeapItem(k _key, v _value){
			key = _key;
			value = _value;
		}
	};
	HeapItem *arr;
	int capacity;
	int totalitems;
	void heapup(HeapItem *arr, int root, int bottom){
		int parent;
		if (bottom>root){
			parent = (bottom - 1) / 2;
			if (arr[parent].key > arr[bottom].key){
				swap(arr[parent].key, arr[bottom].key);
				heapup(arr,root, parent);
			}
		}
	}
	void heapdown(HeapItem *arr, int root, int bottom){
		int max, right, left;
		left = 2 * root + 1;
		right = 2 * root + 2;
		if (left <= bottom){
			if (left == bottom)
				max = left;
			else{
				if (arr[left].key <= arr[right].key)
					max = right;
				else
					max = left;
			}
			if (arr[root].key < arr[max].key){
				swap(arr[root].key, arr[max].key);
				heapdown(arr, max, bottom);
			}
		}
	}
	void grow(){
		cout << "Heap Grow!\n";
		int newcapacity = capacity * 2;
		HeapItem *temp = new HeapItem[newcapacity];
		for (int i = 0; i < capacity; i++)
		{
			temp[i].key = arr[i].key;
		}
		capacity = newcapacity;
		delete[] arr;
		arr = temp;

	}
public:
	MinHeap(){
		arr = nullptr;
		capacity = 0;
		totalitems = 0;
	}
	MinHeap(int _capacity){
		capacity = _capacity;
		if (arr) delete[] arr;
		arr = new HeapItem[capacity];
	}
	void insert(k key, v value){
		if (totalitems == capacity)
			grow();
		arr[totalitems].key = key;

		heapup(arr,0, totalitems);
		totalitems++;
	}
	void print(){
		for (int i = 0; i < totalitems; i++)
		{
			cout << arr[i].key << " ";
		}
		cout << endl;
	}
	void deleteMin(){
		if (isempty()){
			cout << "Heap is Empty!\n";
			return;
		}
		cout << "Minimum deleted: ";
		swap(arr[0].key, arr[totalitems-1].key);
		totalitems--;
		heapdown(arr, 0, totalitems);
	}
	bool isempty()const{
		return totalitems == 0;
	}
	void getMin(v& _value){
		if (isempty()){
			cout << "Heap is Empty!\n";
			return;
		}
		_value = value;
	}
	~MinHeap(){ delete[] arr; }
};

int main(){

	MinHeap<int, int> arr(10);
	for (int i = 10; i > 0; i--)
	{
		arr.insert(i, i);
		arr.print();
	}
	cout << endl << endl;
	for (int i = 0; i < 10; i++)
	{
		arr.deleteMin();
		arr.print();
	}
	arr.print();
	system("pause");
	return 0;
}