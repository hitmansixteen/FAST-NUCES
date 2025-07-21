#include<iostream>
#include"vector.h"
using namespace std;

int main() {
	system("cls");

	vector a,b,c;
	cin >> a>>b>>c;
	cout << a << b<<c;
	int x=a*b;
	cout<<"\nDot Product of a and b\n" << x << endl;
	cout<< "\na == b\n" <<(a == b)<<endl<< "\na != b\n" << (a != b)<<endl;

	a = b= c;
	cout << "\na = b = c\n" << "a = " << a << endl << "b = " << b << endl<< "c = " << c<<endl;
	cout <<a[1]<<endl;
	cout<<a[5] << endl;
	cout << "Unit vector of a stored in b= " << (b ^ a)<<endl;
	cout << "Unit vector of a stored in b, then unit vector of b stored in c= " << (c^b^a)<<endl;
	
	system("pause");
	return 0;
}