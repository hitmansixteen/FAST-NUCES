//#include<iostream>
//#include<cstring>
//#include <string>
//using namespace std;
//
//class Person{
//private: 
//	string fullName;  
//	int height; 
//public: 
//	Person(string name,int  Height){
//		fullName=name;
//		height=Height;
//	} //constructor 
//	virtual void printInfo(){
//		cout<<"Name: "<<fullName<<endl;
//		cout<<"Height: "<<height<<endl;
//		
//	} //this function is to print all  private variables
//	string getname(){return fullName;}
//	int getheight(){return height;}
//	virtual ~Person(){
//		cout<<"person destructor"<<endl;
//
//	}
//
//
//
//};
//
//class Employee: public Person{
//private: 
//	string department;  
//	int ID; 
//public: 
//	Employee(string name,int Height,string Departement,int id) : Person( name, Height){
//		department=Departement;
//		ID=id;
//	}  //constructor
//
//	virtual void printInfo(){
//		cout<<"Department: "<<department<<endl;
//		cout<<"ID: "<<ID<<endl;
//		cout<<"Name: "<<getname()<<endl;
//		cout<<"Height: "<<getheight()<<endl;
//	}
//	virtual ~Employee(){
//		cout<<"employee destructor"<<endl;	
//	}
//
//
//
//};
//
//class Student: public Person{
//private: 
//	string schoolName;
//public: 
//	Student (string name,int  height, string  SchoolName) : Person(name, height){
//		schoolName=SchoolName;
//	}  //constructo
//
//	virtual void printInfo(){
//		cout<<"School Name: "<<schoolName<<endl;
//		cout<<"Name: "<<getname()<<endl;
//		cout<<"Height: "<<getheight()<<endl;
//	}
//	virtual ~Student(){
//		cout<<"Student destructor"<<endl;	
//	}
//
//
//
//};
//
//int main(){
//
//	Person *p[2];
//	p[0] = new Employee("Laraib",192,"CEO",5294);
//	p[1] = new Student("Akhtar",129,"FAST-NUCES");
//
//	for (int i = 0; i < 2; i++){p[i]->printInfo();}
//
//	for (int i = 0; i < 2; i++){delete p[i];}
//
//	
//	system("pause");
//	return 0;
//}