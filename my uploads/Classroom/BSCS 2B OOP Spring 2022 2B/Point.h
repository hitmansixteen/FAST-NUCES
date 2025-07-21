#pragma once
#include <iostream>
#include"circle.h"

using namespace std;
class Point{
	int x_co;
	int y_co;
	friend class circle;
public:
	Point(){
		cout<<"Point() called\n";
		x_co=0;
		y_co=0;
	}

	Point(int x,int y){
		cout<<"Point(int,int) called\n";
		x_co=x;
		y_co=y;
	}

	void Print(){cout<<"("<<x_co<<","<<y_co<<")\n";}



	~Point(){cout<<"~Point() called\n";}



	
};