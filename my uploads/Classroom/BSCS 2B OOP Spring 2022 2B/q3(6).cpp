//#include<iostream>
//using namespace std;
//
//
//void encrypt(char *mystr,int len)
//{
//	for(int i=0;mystr[i]!='\0';i++)
//		mystr[i]+=len;
//
//	cout<<"Encrypted String: "<<endl;
//	cout<<mystr<<endl;
//}
//
//void decrypt(char *mystr,int len)
//{
//	for(int i=0;mystr[i]!='\0';i++)
//		mystr[i]-=len;
//
//	cout<<"Decrypted String: "<<endl;
//	cout<<mystr<<endl;
//}
//
//int main()
//{
//	char mystr[100];
//
//	cin.getline(mystr,100);
//	
//	int length=strlen(mystr);
//
//	encrypt(mystr,length);
//	decrypt(mystr,length);
//	
//
//	
//	system("pause");
//	return 0;
//}