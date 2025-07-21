//#include<iostream>
//using namespace std;
//
//int mod(int x, int y) {
//	return ((x % y) + y) % y;
//}
//
//template <typename T>
//class Stack {
//private:
//	int size; // number of elements
//	int maxsize; // max size of stach
//	T* arr; // template array
//	int top;
//	int bottom;
//	bool flip; // a flag to logically flip the stack
//public:
//	Stack() {
//		size = 0;
//		cout << "Enter the size of the stack? ";
//		cin >> maxsize;
//		arr = new T[maxsize];
//		flip = 0;
//		top = -1;
//		bottom = 0;
//	}
//	~Stack() { delete[] arr; }
//	bool push(int x) {
//		if (isFull()) grow(); //grow the array if stack is full
//		if (!flip) { // if stack is pushing without flip
//			top = mod(++top ,maxsize);
//			arr[top] = x;
//		}
//		else {// if stack is pushing with flip
//			bottom = mod(--bottom, maxsize);
//			arr[bottom]=x;
//		}
//		size++;
//		cout << "Push!\n";
//		print();
//		return true;
//	}
//	bool pop(int& x) {
//		if (isEmpty()) return false;
//		if (size < maxsize / 2) shrink(); // shrink the array if stack is half empty 
//		if (!flip) {
//			x = arr[top]; // mod helps to make the array crcular
//			top = mod(--top, maxsize);
//		}
//		else {
//			x = arr[bottom];
//			bottom = mod(++bottom, maxsize);
//		}
//		size--;
//		cout << "Pop!\n";
//		print();
//		return true;
//	}
//	bool isFull() { 
//		if (size == maxsize)
//			cout << "Stack Overflow!\n";
//		return size == maxsize;
//	}
//	bool isEmpty() { 
//		if (size == 0)
//			cout << "Stack Underflow!\n";
//		return size == 0; 
//	}
//	void flipStack(bool const x) { 
//		flip = x;
//		cout << "flipStack!\n";
//		print();
//	}
//	void print() { // different prints for both when stack flipped either way
//		if (isEmpty()) return;
//		if (!flip) {
//			for (int i = top, x = 0; x < size; x++) {
//				cout << arr[i--] << " ";
//				i = mod(i, maxsize);
//			}
//		}
//		else {
//			for (int i = bottom, x = 0; x < size; x++) {
//				cout << arr[i++] << " ";
//				i = mod(i, maxsize);
//			}
//		}
//		cout << endl;
//	}
//	void grow() {
//		cout << "Growing Stack!\n";
//		int newmax = maxsize * 2 + 1;
//		int x;
//		T* temp = new T[newmax];
//		if (!flip) {
//			x = top;
//			for (int i = size-1; i >=  0; i--)
//				temp[i] = arr[x-- % maxsize];
//			top = size - 1;
//			bottom = 0;
//		}
//		else {
//			x = bottom;
//			for (int i = size-1; i >= 0; i--)
//				temp[i] = arr[x-- % maxsize];
//			bottom = size - 1;
//			top = 0;
//		}
//		delete[] arr;
//		maxsize = newmax;
//		arr = new T[maxsize];
//		arr = temp;
//
//	}
//
//	void shrink() {
//		cout << "Shrinking Stack!\n";
//		int newmax = (maxsize/ 2)+1;
//		int x;
//		T* temp = new T[newmax];
//		if (!flip) {
//			x = top;
//			for (int i = size - 1; i >= 0; i--)
//				temp[i] = arr[x-- % maxsize];
//			top = size - 1;
//			bottom = 0;
//		}
//		else {
//			x = bottom;
//			for (int i = size - 1; i >= 0; i--)
//				temp[i] = arr[x-- % maxsize];
//			bottom = size - 1;
//			top = 0;
//		}
//		delete[] arr;
//		maxsize = newmax;
//		arr = new T[maxsize];
//		arr = temp;
//	}
//};
//
//int main() {
//	Stack<int> *a = new Stack<int>();
//	int choice = 1;
//	bool f = 0;
//	while (choice) {
//		cout << "1.Push\n2.Pop\n3.FlipStack\n0.Exit\nEnter Choice: ";
//		cin >> choice;
//		switch (choice) {
//		case 0:
//			break;
//		case 1:
//			int i, x;
//			cout << "Enter number of elements you want to PUSH!: ";
//			cin >> x;
//			cout << "Enter Element: ";
//			for (int j = 0; j < x; j++) {
//				cin >> i;
//				a->push(i);
//			}
//			break;
//		case 2:
//			int y, z;
//			cout << "Enter number of elements you want to POP!: ";
//			cin >> z;
//			for (int j = 0; j < z; j++) {
//				a->pop(y);
//			}
//			break;
//		case 3:
//			if (!f) {
//				a->flipStack(1);
//				f = 1;
//			}
//			else {
//				a->flipStack(0);
//				f = 0;
//			} 
//			
//			break;
//		}
//	}
//	delete a;
//	
//
//
//	return 0;
//}