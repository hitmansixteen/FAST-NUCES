#include<iostream>
using namespace std;


class specialization{
	int id;
	string description;
public:
	specialization(){
		id=0;
		description="";

	}
	specialization(int i,string d){
		id=i;
		description=d;
	}
};
class person{
	string name;
	int age;
	int phone_number;
	char sex;
	int no_of_appointment_per_day;
	string email_id;
public:
	person(){
		name="";
		age=0;
		phone_number=0;
		sex='x';
		no_of_appointment_per_day=0;
		email_id="";
	}
	person(string n,int a,int p,char c,int no_a,string e){
		name=n;
		age=a;
		phone_number=p;
		sex=c;
		no_of_appointment_per_day=no_a;
		email_id=e;
	}
	virtual int get_remaining_appointment()=0;
	virtual void setschedule()=0;
	virtual void show_schedule()=0;

	void setname(string n){name=n;}
	void setage(int n){age=n;}
	void setphone(int n){phone_number=n;}
	void setsex(char n){sex=n;}
	void setno_of_appointment(int n){no_of_appointment_per_day=n;}
	void setemail(string n){email_id=n;}

	string getname(){return name;}
	int getage(){return age;}
	int getphone(){return phone_number;}
	char getsex(){return sex;}
	int getno_of_appointment(){return no_of_appointment_per_day;}
	string getemail(){return email_id;}

};

class doctor : public person{
	int id;
	bool *schedule;
	specialization spe;
public:
	doctor(){
		int id=0;
		schedule = new bool[7];
	}
	doctor(int i,string n,int a,int p,char c,int no_a,string e): person(n,a,p,c,no_a,e){
		int id=i;
		schedule = new bool[7];
	}
	void setschedule(){
		
		for (int i = 0; i < 7; i++)
		{
			cout<<"Appointment on day: "<<i+1<<"   //enter 0 or 1//";
			cin>>schedule[i];//0 or 1
		}
		int count=0;
		for (int i = 0; i < 7; i++)
		{
			if(schedule[i]==1) count++;
		}
		setno_of_appointment(count);
	}
	void show_schedule(){
		for (int i = 0; i < 7; i++)
		{
			cout<<"Day "<<i+1<<" is ";
			if(schedule[i]==1)
				cout<<"booked\n";
			else
				cout<<"free\n";
		}
	}
	int get_remaining_appointment(){return get_remaining_appointment();}
	~doctor(){
		delete[] schedule;
	}
};

class patients :  public person{
	int id;
	string name;
	int age;
	string diagnosis;
	int appointment_id;
public:
	patients(int i,string d,string n,int a,int p,char c,int no_a,string e): person(n,a,p,c,no_a, e){
		id=i;
		diagnosis=d;
	}
	int get_remaining_appointment(){return get_remaining_appointment();}
	void setschedule(){cout<<"";}
	void show_schedule(){cout<<"";}
};
int main()
{
	person *people[2];
	people[0] = new doctor(0247,"dr.laraib",29,32475667,'M',0,"laraibakhtar40@gmail.com");
	people[1] = new patients(5294,"heart patient","mr. akhtar",19,032456,'M',6,"raoaktar10@gmail.com");

	people[0]->setschedule();
	people[0]->show_schedule();

	cout<<"Patient has "<<people[1]->getno_of_appointment()<<" appointments booked\n";

	system("pause");
	return 0;
}
