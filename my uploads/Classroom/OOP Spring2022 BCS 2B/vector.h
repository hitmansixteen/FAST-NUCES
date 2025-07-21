#pragma once
#include<iostream>
using namespace std;

class vector {
	int size;
	float* arr;
public:
	vector();
	vector(vector&);
	friend istream& operator >> (istream&, vector&);
	friend ostream& operator << (ostream&, vector&);
	int operator * (vector&);
	bool operator!=(vector&);
	bool operator==(vector&);
	vector& operator=(vector&);
	float operator[](int);
	vector& operator^(vector&);
	~vector();
	
};
