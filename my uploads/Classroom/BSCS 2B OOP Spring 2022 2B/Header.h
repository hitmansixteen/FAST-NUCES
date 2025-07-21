#include<iostream>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date();
	
	void Print()
	{
		cout<<day<<"/"<<month<<'/'<<year<<endl;
	}
	void Input()
	{
		cout<<"Enter day: ";
		cin>>day;
		while(day>31||day<1)
		{
			cout<<"Enter day again: ";
			cin>>day;
		}
		cout<<"Enter month: ";
		cin>>month;
		while(month>12||month<1)
		{
			cout<<"Enter month again: ";
			cin>>month;
		}
		
		cout<<"Enter year: ";
		cin>>year;
		cout<<endl;
	}
	void SetDay(int Day)
	{
		day=Day;
	}
	void SetMonth(int Month)
	{
		month=Month;
	}
	void SetYear(int Year)
	{
		year=Year;
	}

	int GetDay()
	{
		return day;
	}
	int GetMonth()
	{
		return month;
	}
	int GetYear()
	{
		return year;
	}
	
	
};
Date ::Date()
{
		cout<<"Default constructor called\n";
		day=1;
		month=1;
		year=1926;
}




