//#include<iostream>
//using namespace std;
//
//int divide(int n1, int n2,int result){
//	if (n1 >= n2)
//		return divide(n1 - n2, n2, result + 1);
//	return result;
//}
//int divide(int n1, int n2){
//	int result = 0;
//	while (n1 >= n2){
//		n1 -= n2;
//		result++;
//	}
//	return result;
//}
//
//int mod(int n1, int n2){
//	if (n1 < n2)
//		return n1;
//	return mod(n1 - n2, n2);
//}
//int mod_loop(int n1, int n2){
//	while (n1 >= n2)
//		n1 -= n2;
//	return n1;
//
//}
//
//int main(){
//
//	int num1,num2;
//
//	cout << "Enter Num1: ";
//	cin >> num1;
//	cout << "Enter Num2: ";
//	cin >> num2;
//	
//	cout <<"divide by recursion " <<divide(num1, num2, 0)<<endl;
//	cout << "divide by loop "<<divide(num1, num2) << endl;
//	cout << "mod by recursion "<<mod(num1, num2) << endl;
//	cout << "divide by loop " << mod_loop(num1, num2) << endl;
//	
//
//
//	system("pause");
//	return 0;
//}