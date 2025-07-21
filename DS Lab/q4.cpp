#include<iostream>
using namespace std;

int trisum(int n){
	if (n == 1 || n == 2 || n == 3)
		return n;
	return trisum(n - 1) + trisum(n - 2) + trisum(n - 3);
	
}
void trisum_loop(int n){
	int n1 = 1, n2 = 2, n3 = 3;
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == 1){
			cout << n1 << " ";
			continue;
		}
		if (i == 2){
			cout << n2 << " ";
			continue;
		}
		if (i == 3){
			cout << n3 << " ";
			continue;
		}
		result = n1 + n2 + n3;
		n1 = n2;
		n2 = n3;
		n3 = result;
		cout << result << " ";
	}
	cout << endl;
}

int main(){

	int num;

	cout << "Enter Number: ";
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		cout << trisum(i) << " ";
	}
	cout << endl;
	trisum_loop(num);

	
	cout<< endl;

	



	system("pause");
	return 0;
}