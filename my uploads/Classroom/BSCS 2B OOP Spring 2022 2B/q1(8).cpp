//#include<iostream>
//#include<cstdlib>
//#include<ctime>
//using namespace std;
//
//
//void dynamic(char *&arr)
//{
//	arr = new char[3];
//
//	arr[0]='J';
//	arr[1]='Q';
//	arr[2]='K';
//
//	for (int i = 0; i < 3; i++)
//	{
//		swap(arr[rand()%3],arr[rand()%3]);
//	} 
//
//	
//	
//}
//
//int main()
//{
//	srand(time(0));
//	int choose;
//
//	char *arr;
//	int money=100,penalty,option=0;
//	int i;
//	cout<<"Enter 1 to make static array\nEnter 2 to make dynamic aray(pointers not deleted)\nEnter 3 to make dynamic array(pointers deleted)\nEnter Option: ";
//	cin>>choose;
//	while(choose<1&&choose>3)
//	{
//		cout<<"Enter Option again: ";
//		cin>>choose;
//	}
//
//	if(choose==1)
//	{
//		arr[0]='J';
//		arr[1]='Q';
//		arr[2]='K';
//		while(money>0)
//		{
//		cout<<"Enter penalty: ";
//		cin>>penalty;
//		while(money<penalty)
//		{
//			cout<<"Penalty cannot be greater than money: ";
//			cin>>penalty;
//			
//		}
//		cout<<"Enter the card number you want to pick: ";
//		cin>>option;
//		while(option<1&&option>3)
//		{
//			cout<<"Enter the card number again: ";
//			cin>>option;
//			
//		}
//		
//		i=rand() % 3;
//		if(arr[option-1]==arr[i])
//		{
//			money = money + penalty*3;
//			cout<<"You have "<<money<<"$"<<endl;
//		}
//			
//		else
//		{
//			money = money - penalty;
//			cout<<"You have "<<money<<"$"<<endl;
//		}
//		}
//
//	}
//		
//	else if(choose==2)
//	{
//		
//		while(money>0)
//		{
//		cout<<"Enter penalty: ";
//		cin>>penalty;
//		while(money<penalty)
//		{
//			cout<<"Penalty cannot be greater than money: ";
//			cin>>penalty;
//			
//		}
//		cout<<"Enter the card number you want to pick: ";
//		cin>>option;
//		while(option<1&&option>3)
//		{
//			cout<<"Enter the card number again: ";
//			cin>>option;
//			
//		}
//		
//		dynamic(arr);
//
//		i=rand() % 3;
//		if(arr[option-1]==arr[i])
//		{
//			money = money + penalty*3;
//			cout<<"You have "<<money<<"$"<<endl;
//		}
//			
//		else
//		{
//			money = money - penalty;
//			cout<<"You have "<<money<<"$"<<endl;
//		}
//		}
//
//	}
//
//		
//
//	
//
//
//	
//
//	cout<<"Game Over!"<<endl;
//
//
//	
//	
//	system("pause");
//	return 0;
//}