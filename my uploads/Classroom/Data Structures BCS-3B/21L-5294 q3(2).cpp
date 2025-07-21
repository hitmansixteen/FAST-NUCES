#include<iostream>
using namespace std;

int mod(int x, int y) {// this function is made to take mod of negative numbers since in c++ -1%5=-1 and not 4 which we want
	return ((x % y) + y) % y;
}


template <typename T>
class Stack {
private:
	int size; // number of elements
	int maxsize; // max size of stach
	T* arr; // template array
	int top;
public:
	Stack() {
		size = 0;
		maxsize = 5;
		arr = new T[maxsize];
		top = -1;
	}
	~Stack() { delete[] arr; }
	bool push(int x) {
		/*if (isFull()) return false;*/ // will not be used since it is overwriting the oldest element in stack
		top = mod(++top, maxsize); // mod helps to make the array crcular
		arr[top] = x;
		if (!isFull()) {
			size++;
		}
		cout << "Push!\n";
		print();
		return true;
	}
	bool pop(int& x) {
		if (isEmpty()) return false;
		swap(arr[top], arr[mod((top - 1), maxsize)]);
		x = arr[top];
		top = mod(--top,maxsize);
		size--;
		cout << "Pop!\n";
		print();
		return true;
	}
	bool isFull() {
		if (size == maxsize)
			cout << "Stack Overflow!\n";
		return size == maxsize;
	}
	bool isEmpty() {
		if (size == 0)
			cout << "Stack Underflow!\n";
		return size == 0;
	}
	void print() { // print stack
		if (isEmpty()) return;
		for (int i = top, x = 0; x < size; x++) {
			cout << arr[i--] << " ";
			i = mod(i, maxsize);
		}
		cout << endl;
	}
};

int main() {
	Stack<int>* a = new Stack<int>();
	int choice = 1;
	bool f = 0;
	while (choice) {
		cout << "1.Push\n2.Pop\n0.Exit\nEnter Choice: ";
		cin >> choice;
		switch (choice) {
		case 0:
			break;
		case 1:
			int i, x;
			cout << "Enter number of elements you want to PUSH!: ";
			cin >> x;
			cout << "Enter Element: ";
			for (int j = 0; j < x; j++) {
				cin >> i;
				a->push(i);
			}
			break;
		case 2:
			int y, z;
			cout << "Enter number of elements you want to POP!: ";
			cin >> z;
			for (int j = 0; j < z; j++) {
				a->pop(y);
			}

			break;
		}
	}
	delete a;



	return 0;
}