#include<iostream>
#include"vector.h"
#include<math.h>
using namespace std;

vector::vector() {
	int size = 0;
	arr = nullptr;
}

vector::vector(vector& copy) {
	if (size > 0)
		delete[] arr;
	size = copy.size;
	arr = new float[size];
	for (int i = 0; i < size; i++) { arr[i] = copy.arr[i]; }
}

istream& operator >> (istream& in, vector& v) {
	if (v.size > 0)
		delete[] v.arr;
	cout << "Dimension: ";
	in >> v.size;
	v.arr = new float[v.size];
	cout << "Vector: ";
	for (int i = 0; i < v.size; i++) {in >> v.arr[i];}

	return in;
}

ostream& operator << (ostream& out, vector& v) {
	out << "Vector: < ";
	for (int i = 0; i < v.size; i++) {
		out << v.arr[i]<<" ";
	}
	out << ">\n";

	return out;
}

int vector::operator * (vector &v) {
	int x = v.size;
	int sum = 0;
	if(size<v.size)
		x = size;
	for(int i=0;i<x;i++){sum+=arr[i]*v.arr[i];}
	return sum;
}

bool vector::operator!=(vector& v) {
	int x;
	bool flag=0;
	x = v.size;
	if (x == size) {
		for (int i = 0; i < x; i++)
			if (arr[i] != v.arr[i])
				flag = 1;
	}
	else
		flag = 1;
	return flag;

}
bool vector::operator==(vector& v) {
	int x;
	bool flag = 1;
	x = v.size;
	if (x == size) {
		for (int i = 0; i < x; i++)
			if (arr[i] != v.arr[i])
				flag = 0;
	}
	else
		flag = 0;
	return flag;
}

vector& vector::operator = (vector& v) {
	if (size > 0)
		delete[] arr;
	size = v.size;
	arr = new float[size];
	for (int i = 0; i < size; i++) { arr[i] = v.arr[i]; }

	return *(this);
}

float vector::operator[](int i) {
	if (i >= this->size || this->size==0 ) {
		cout << "Out of Bound. Size of vector is ";
		return this->size;
	}
	else
		return arr[i];
}

vector& vector::operator^(vector& v) {
	if (size > 0 && this != &v) {
		delete[] arr;
		size = v.size;
		arr = new float[size];
	}
		
	float unit = 0;
	for (int i = 0; i < size; i++) { unit += v.arr[i]*v.arr[i]; }

	for (int i = 0; i < size; i++) { arr[i] = v.arr[i] / pow(unit, 0.5); }

	return *(this);
}

vector::~vector() {
	if (size > 0) {
		delete[] arr;
		arr = nullptr;
	}
}
