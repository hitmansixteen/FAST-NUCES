//#include<iostream>
//using namespace std;
//
//template<typename T>
//class calculator{
//	T Num1;
//	T Num2;
//	T Result;
//public:
//	calculator(){}
//	calculator(T n1,T n2){
//		Num1=n1;
//		Num2=n2;
//		Result=0;
//	}
//	T Sum(T n1,T n2,T n3){
//		Result=n1+n2+n3;
//		return Result;
//	}
//	T Sum(T n1,T n2){
//		Result=n1+n2;
//		return Result;
//	}
//	T Subtract(T n1,T n2,T n3){
//		Result=n1-n2-n3;
//		return Result;
//	}
//	T Subtract(T n1,T n2){
//		Result=n1-n2;
//		return Result;
//	}
//	T Multiply(T n1,T n2,T n3){
//		Result=n1*n2*n3;
//		return Result;
//	}
//	T Multiply(T n1,T n2){
//		Result=n1*n2;
//		return Result;
//	}
//	T Division(T n1,T n2,T n3){
//		Result=(n1/n2)/n3;
//		return Result;
//	}
//	T Division(T n1,T n2){
//		Result=n1/n2;
//		return Result;
//	}
//	T Modulus(T n1,T n2){
//		Result=n1%n2;
//		return Result;
//	}
//	T Max(T n1,T n2,T n3){
//		if(n1>n2)
//			Result=n1;
//		else
//			Result=n2;
//		return Result;
//	}
//	T Min(T n1,T n2){
//		if(n1<n2)
//			Result=n1;
//		else
//			Result=n2;
//		result Result;
//	}
//	void print(){cout<<"Result: "<<Result<<endl;}
//};
//
//
//int main(){
//
//	calculator<float> c;
//
//	c.Sum(5,7,8);
//	c.print();
//	c.Subtract(5,7,8);
//	c.print();
//	c.Multiply(5,7,8);
//	c.print();
//	c.Division(5,7,8);
//	c.print();
//	c.Modulus(7,5);
//	c.print();
//	
//	system("pause");
//	return 0;
//}