#include<iostream>
using namespace std;

template <typename T> class myVector{
private:
	T *arrayPtr;
	int capacity;
	int current_size;

public:
	myVector(){
		arrayPtr = new T[2];
		for (int i = 0; i < 2; i++)
			arrayPtr[i] = 0;
		
		capacity = 2;
		current_size = 2;
	}
	myVector(int c){
		capacity = c;
		arrayPtr = new T[capacity];
		current_size = c;
		for (int i = 0; i < current_size; i++)
			arrayPtr[i] = 0;
		
	}
	myVector(myVector &v){
		delete[] arrayPtr;
		capacity = v.capacity;
		current_size = v.current_size;
		arrayPtr = new T[capacity];
		for (int i = 0; i < current_size; i++)
			arrayPtr[i] = v.arrayPtr[i];
	}

	int getcapacity(){ return capacity; }
	int getcurrent_size(){ return current_size; }
	T*& getarrayPtr(){ return arrayPtr; }

	void operator + (int n){
		if (capacity <= current_size){
			capacity *= 2;
			int *temp = new T[capacity];
			for (int i = 0; i < current_size; i++)
				temp[i] = arrayPtr[i];
			temp[current_size] = n;
			current_size++;
			delete[] arrayPtr;
			arrayPtr = new T[capacity];
			for (int i = 0; i < current_size; i++)
				arrayPtr[i] = temp[i];
			delete[] temp;
		}
		else
			arrayPtr[current_size] = n;
	}
	void operator - (){
		current_size--;
		arrayPtr[current_size] = '\0';

	}

	int* operator + (myVector &v){
		T *temp = new T[current_size + v.current_size];

		for (int i = 0; i < current_size; i++)
			temp[i] = arrayPtr[i];
		for (int i = current_size; i < current_size+v.current_size; i++)
			temp[i] = v.arrayPtr[i-current_size];
		
		return temp;
	}

	myVector& operator = (myVector &v){
		delete[] arrayPtr;
		capacity = v.capacity;
		current_size = v.current_size;
		arrayPtr = new T[capacity];
		for (int i = 0; i < current_size; i++)
			arrayPtr[i] = v.arrayPtr[i];
		return *(this);
	}
	bool operator [](int n){
		if (n >= current_size){
			return false;
		}
		else{
			cout << "Enter value: ";
			cin >> arrayPtr[n];
			return true;
		}
			
	}
	friend ostream& operator<<(ostream& out, myVector& v){
		for (int i = 0; i < v.current_size; i++)
			cout << v.arrayPtr[i] << " ";

		cout << endl;
		return out;
	}
	friend istream& operator>>(istream& in, myVector& v){
		cout << "Enter element: \n";
		for (int i = 0; i < v.current_size; i++)
			cin>> v.arrayPtr[i];
		return in;
	}
	~myVector(){
		delete[] arrayPtr;
		arrayPtr = nullptr;
	}
};

int main()
{
	myVector<int> v(5),w(5);

	int choice=1;
	while (choice != 0){
		cout << "myVector!!!\n";
		cout << "1) add a new element in v\n";
		cout << "2) delete an element in v\n";
		cout << "3) merge two vectors v+w\n";
		cout << "4) Assign Operator v=w\n";
		cout << "5) add element at index []\n";
		cout << "6) Input Elements of v\n";
		cout << "7) Output Elements of v\n";
		cout << "8) add a new element in w\n";
		cout << "9) delete an element in w\n";
		cout << "10) Input Elements of w\n";
		cout << "11) Output Elements of w\n";
		cout << "0) exit\n";

		cout << "Enter your choice\n";
		cin >> choice;

		if (choice == 1){
			int ele;
			cin >> ele;
			v + ele;
		}
		else if (choice == 2){
			-v;
		}
		else if (choice == 3){
			int *arr = v + w;
			int size = sizeof(arr) / sizeof(arr[0]);
			for (int i = 0; i < size; i++)
			{
				cout << arr[i] << " ";
			}
		}
		else if (choice == 4){
			v = w;
		}
		else if (choice == 5){
			int n;
			cin >> n;
			if (v[n] != true)
				cout << "false\n";

		}
		else if (choice == 6){
			cin >> v;
		}
		else if (choice == 7){
			cout << v;
		}
		else if (choice == 8){
			int ele1;
			cin >> ele1;
			w + ele1;
		}
		else if (choice == 9){
			-w;
		}
		else if (choice == 10){
			cin >> w;
		}
		else if (choice == 11){
			cout << w;
		}
		else if (choice == 0){
			choice = 0;
		}

	}

	



	system("pause");
	return 0;
}