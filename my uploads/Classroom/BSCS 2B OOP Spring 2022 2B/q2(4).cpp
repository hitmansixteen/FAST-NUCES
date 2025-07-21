//#include<iostream>
//
//using namespace std;
//
//class student{
//	int *array;
//public:
//	student();
//
//	void set_marks(int marks,int index);
//	
//	void display();
//
//	student(student &);
//	void deallocate();
//	
//};
//
//student::student(){
//	array = new int[5];
//}
//
//student::student(student &copy){
//	array = new int[5];
//	for (int i = 0; i < 5; i++)
//	{
//		array[i]=copy.array[i];
//	}
//}
//
//void student::set_marks(int marks,int index){
//	while(index<0 || index>4){
//		cout<<"Enter Index again: ";
//		cin>>index;
//	}
//	array[index]=marks;
//}
//
//void student::display(){
//	cout<<"Marks: ";
//	for (int i = 0; i < 5; i++)
//	{
//		cout<<array[i]<<" ";
//	}
//}
//
//void student::deallocate(){
//	cout<<"\n Destructor called\n";
//	delete[] array;
//}
//
//
//int main(){
//
//	student obj1;
//	int marks;
//	for(int i=0;i<5;i++){
//		cout<<"Enter marks: ";
//		cin>>marks;
//		obj1.set_marks(marks,i);
//	}
//	obj1.display();
//	student obj2 = obj1;
//	obj1.deallocate();
//	cout<<endl;
//	obj2.display();
//	
//
//	system("pause");
//	return 0;
//}