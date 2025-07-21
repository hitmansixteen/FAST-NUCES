#include<iostream>
using namespace std;

class Box
{
	int length;  
	int breadth;  
	int height; 
	static int objectCount;
public:

	Box(){
	length=0;
	breadth=0;
	height=0;
	}

	Box(int leng,int brea,int heig){
		length=leng;
		breadth=brea;
		height=heig;
	}

	void setLength(int len){length=len;}
	void setbreadth(int bre){breadth=bre;}
	void setheight(int hei){height=hei;}

	int getLength(){return length;}
	int getbreadth(){return breadth;}
	int getheight(){return height;}

	static int getCount(){return objectCount++;}

	double Volume(){return length*breadth*height;}

	double Area(){return length*breadth;}
};

int Box::objectCount=1;

int main()
{
	Box b1;
	cout<<"Number of Objects made are: "<<Box::getCount()<<endl;
	b1.setLength(2);
	b1.setbreadth(2);
	b1.setheight(2);

	Box b2(7,8,9);
	cout<<"Number of Objects made are: "<<Box::getCount()<<endl;

	cout<<"Volume of b1 is:"<<b1.Volume()<<endl;
	cout<<"Area of b1 is:"<<b1.Area()<<endl;
	cout<<"Volume of b2 is:"<<b2.Volume()<<endl;
	cout<<"Area of b2 is:"<<b2.Area()<<endl;


	
	system("pause");
	return 0;
}