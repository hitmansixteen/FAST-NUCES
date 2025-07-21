//#include<iostream>
//using namespace std;
//
//class Shape {
//	int length;
//	int width;
//public:
//	Shape() { cout << "Shape() called\n"; }
//	void setlen(int l) { length = l; }
//	void setwid(int w) { width = w; }
//	int getlen() { return length; }
//	int getwid() { return width; }
//	~Shape() { cout << "~Shape() called\n"; }
//
//};
//class Square: public Shape {
//	int area;
//	int volume;
//public:
//	Square() { cout << "Square() called\n"; }
//	void display() {
//		cout << "x-coordinates: " << getlen() << endl;
//		cout << "y-coordinates: " << getwid() << endl;
//	}
//	int Area() { 
//		area = (getlen() * getlen());
//		cout << "Area: "<< area<<endl;
//		return area; 
//	}
//	int Volume() {
//		volume = (getlen() * getlen() * getlen());
//		cout << "Volume: "<<volume<<endl;
//		return volume; 
//	}
//	~Square() { cout << "~Square called\n"; };
//};
//
//class Rectangle : public Shape {
//	int area;
//	int volume;
//public:
//	Rectangle() { cout << "Rectangle() called\n"; }
//	void display() {
//		cout << "x-coordinates: " << getlen() << endl;
//		cout << "y-coordinates: " << getwid() << endl;
//	}
//	int Area() {
//		area = (getlen() * getwid());
//		cout << "Area: " << area << endl;
//		return area;
//	}
//	int Volume() {
//		volume = (getlen() * getwid() * getlen());
//		cout << "Volume: " << volume << endl;
//		return volume;
//	}
//	~Rectangle() { cout << "~Rectangle called\n"; };
//
//};
//
//int main() {
//	//////////////////shape////////////
//	Shape A;
//	A.setlen(15);
//	cout << A.getlen() << endl;
//	A.setwid(14);
//	cout << A.getwid() << endl;
//	//////////////////Square////////////
//	Square B;
//	B.setlen(15);
//	cout << B.getlen() << endl;
//	B.setwid(15);
//	cout << B.getwid() << endl;
//	B.Area();cout << endl;
//	B.Volume();cout << endl;
//	//////////////////rectangle////////////
//	Rectangle C;
//	C.setlen(12);
//	cout << C.getlen() << endl;
//	C.setwid(14);
//	cout << C.getwid() << endl;
//	C.Area();cout << endl;
//	C.Volume();cout << endl;
//	
//	
//	return 0;
//	system("pause");
//}