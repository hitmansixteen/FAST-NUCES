#include<iostream>
#include"Header.h"
using namespace std;


int main()
{
	Date date1;

	date1.Print();
	date1.Input();
	date1.Print();

	Date xmasDay;
	xmasDay.SetDay(25);
	xmasDay.SetMonth(12);
	xmasDay.SetYear(2020);

	
	
	cout<<xmasDay.GetDay()<<"/"<<xmasDay.GetMonth()<<"/"<<xmasDay.GetYear();
	
	
	system("pause");
	return 0;
}