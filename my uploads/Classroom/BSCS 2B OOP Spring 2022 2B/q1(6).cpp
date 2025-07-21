//#include<iostream>
//#include<string>
//using namespace std;
//
//class diablo{
//	int capacity;
//	string colour;
//	int seats;
//	int year;
//	int engine_no;
//	int frame_no;
//	string name;
//public:
//	diablo();
//
//	void set_capacity(int cap){capacity=cap;}
//	void set_colour(string color){colour=color;}
//	void set_seats(int seat){seats=seat;}
//	void set_year(int years){year=years;}
//	void set_engine_no(int engine){engine_no=engine;}
//	void set_frame_no(int frame){frame_no=frame;}
//	void set_name(string names){name=names;}
//
//	int get_capacity(){return capacity;}
//	string get_colour(){return colour;}
//	int get_seats(){return seats;}
//	int get_year(){return year;}
//	int get_engine_no(){return engine_no;}
//	int get_frame_no(){return frame_no;}
//	string get_name(){return name;}
//
//	void print();
//
//	diablo(diablo &);
//	
//};
//
//diablo::diablo(){
//	colour = "Hot Red";
//	capacity = 1000;
//	seats = 4;
//}
//
//diablo::diablo(diablo &copy){
//	colour = copy.colour;
//	capacity=copy.capacity;
//	seats=copy.seats;
//}
//
//void diablo::print(){
//	cout<<"Owner Name: "<<name<<endl;
//		cout<<"Colour: "<<colour<<endl;
//		cout<<"Cubic Capacity: "<<capacity<<endl;
//		cout<<"Number of seats: "<<seats<<endl;
//		cout<<"Year: "<<year<<endl;
//		cout<<"Engine Number: "<<engine_no<<endl;
//		cout<<"Frame Number: "<<frame_no<<endl;
//		
//}
//
//
//int main(){
//
//	diablo obj1;
//	obj1.set_engine_no(1000);
//	obj1.set_year(2021);
//	obj1.set_frame_no(45);
//	obj1.set_name("Laraib");
//	obj1.print();
//	diablo obj2 = obj1;
//	obj2.set_engine_no(1500);
//	obj2.set_year(2011);
//	obj2.set_frame_no(55);
//	obj2.set_name("Ahmad");
//	cout<<endl;
//	obj2.print();
//
//	system("pause");
//	return 0;
//}