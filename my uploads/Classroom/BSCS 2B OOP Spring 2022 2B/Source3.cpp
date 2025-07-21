#include<iostream>
using namespace std;

void f1(int, int);
void f2(int, int);
void f3(int, int);

void f1(int m, int n) {
	cout << "Function 1 start\n";
	f2(m, n);
	cout << "Function 1 end\n";
}
void f2(int m, int n) {
	cout << "Function 2 start\n";
	f3(m, n);
	cout << "Function 2 end\n";
}
void f3(int m, int n) {
	cout << "Function 3 start\n";
	if (n == 0)
		throw n;
	else
		throw (float)m / n;
	cout << "Function 3 end\n";
}

int main() {
	try {
		cout << "Main start\n";
		f1(36, 2);
		cout << "Main end\n";
	}
	catch (int x) { cout << "Exception called: " <<x<<endl; }
	catch (float x) { cout << "Result is: " << x << endl; }
	
	
	
	return 0;
}