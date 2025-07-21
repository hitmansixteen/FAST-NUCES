#include<iostream>
using namespace std;

class Complex{
	int real;
	int imaginary;
public:
	Complex();
	Complex(int,int);
	
	bool operator==(Complex C){
		if(real==C.real && imaginary==C.imaginary)
			return true;
		return false;
	}

	bool operator!=(Complex C){
		if(real==C.real && imaginary==C.imaginary)
			return false;
		return true;
	}

	bool operator<(Complex C){
		if(imaginary<C.imaginary)
			return false;
		return true;
	}

	bool operator>(Complex C){
		if(imaginary>C.imaginary)
			return false;
		return true;
	}

	Complex& operator-(Complex C){
		Complex temp;
		temp.real=real-C.real;
		temp.imaginary=imaginary-C.imaginary;

		return temp;
	}
	
	Complex& operator+(Complex C){
		Complex temp;
		temp.real=real+C.real;
		temp.imaginary=imaginary+C.imaginary;

		return temp;
	}

	
	
};

Complex::Complex(int num,int imag){
	real=num;imaginary=imag;
	
}

int main() 
{ 
	Complex C1; 
	Complex C2(5,6); 
	Complex C3; 
	cout<<"Input a complex number"<<endl; 
	cin>>C3; 
	cout<<C1<<C2<<C3; 
	if(C1==C2) 
		cout<<"C1 == C2"<<endl; 
	else 
		cout<<"C1 != C2"<<endl; 
	if(C1!=C3) 
		cout<<"C1 != C3"<<endl; 
	else 
		cout<<"C1==C3"<<endl; 
	Complex C4= C2 - C3; 
	cout<<C4; 
	system("pause"); 
	return 0; 
}