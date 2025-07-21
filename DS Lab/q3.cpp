//#include<iostream>
//using namespace std;
//
//int fib(int n){
//	if (n == 0 || n == 1)
//		return n;
//	return fib(n - 1) + fib(n - 2);
//}
//int fib_loop(int n){
//	if (n == 0 || n == 1)
//		return n;
//	int num1, num2, num3;
//	num1 = 0;
//	num2 = 1;
//	for (int i = 2; i <= n; i++)
//	{
//		num3 = num1 + num2;
//		num1 = num2;
//		num2 = num3;
//	}
//	return num3;
//}
//
//int main(){
//
//	int num;
//
//	cout << "Enter Number: ";
//	cin >> num;
//
//	for (int i = 0; i < num; i++)
//	{
//		cout << fib(i) << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < num; i++)
//	{
//		cout << fib_loop(i) << " ";
//	}
//	cout << endl;
//
//
//
//	system("pause");
//	return 0;
//}