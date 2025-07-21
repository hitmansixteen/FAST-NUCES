//#include<iostream>
//using namespace std;
//
//void myTokenizer(char *data,char **&list_tokens,char delimeter)
//{
//	
//	int index=0;
//	int count=0;
//	int sum=0;
//	
//	list_tokens = new char*[index+1];
//	
//	for(int i=0;i<=strlen(data);i++)
//	{	
//		list_tokens[index][i-sum]=data[i];
//		count++;
//		
//		if(data[i]==delimeter||data[i]=='\0')
//		{
//			list_tokens[index][i-sum]='\0';
//			index++;
//			sum=sum+count;
//			list_tokens[index] = new char[count];
//			count=0;
//		}
//		
//	}
//	cout<<"Tokens are: ";
//	for(int i=0;i<index;i++)
//	{
//		cout<<list_tokens[index];
//		cout<<endl;
//		
//	}
//
//
//	
//}
//
//
//int main()
//{
//	char **list_tokens;
//	char *data ="my,name,is,Mr,Faheem";
//	
//
//	
//	char delimeter;
//	cout<<"Delimeter: ";
//	cin>>delimeter;
//
//	myTokenizer(data,list_tokens,delimeter);
//
//	
//	
//	system("pause");
//	return 0;
//}