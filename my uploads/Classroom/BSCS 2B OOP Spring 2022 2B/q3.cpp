#include<iostream>
using namespace std;



class Shape{
protected:
	int radius;
	int length;
	int breadth;
public:
	Shape(int l,int r,int b){
		length=l;
		radius=r;
		breadth=b;
	}
	virtual int RectangleArea() = 0;
	virtual int SquareArea() = 0;
	virtual float CircleArea() = 0;
};

class Area: public Shape{
public:
	Area(int l,int r,int b):Shape(l,r,b){}
	virtual int RectangleArea(){return length*breadth;}
	virtual int SquareArea(){return length*length;}
	virtual float CircleArea(){return 3.14*radius*radius;}
};
int main(){

	Shape *c = new Area(4,5,6);//length,radius,breadth
	cout<<"Rectangle Area: "<<c->RectangleArea()<<endl;
	cout<<"Square Area: "<<c->SquareArea()<<endl;
	cout<<"Radius Area: "<<c->CircleArea()<<endl;
		
	system("pause");
	return 0;
}