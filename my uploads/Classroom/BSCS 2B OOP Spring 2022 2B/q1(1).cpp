#include<iostream>
using namespace std;

class Account{
	int AccountNo;
	float Balance;
public:
	Account(){
	AccountNo=0;
	Balance=0;
	}
	Account(int Acc,float bal){
		AccountNo=Acc;
		Balance=bal;
	}
	void setAccountNo(int Acc){AccountNo=Acc;}
	void setBalance(float bal){Balance=bal;}

	int getAccountNo(){return AccountNo;}
	float getBalance(){return Balance;}

	virtual void Print(){}
	virtual bool Debit(float c){return 0;}
	virtual float Credit(float c){return 0;}
};

class CurrentAccount:public Account{
	float Service_charges;
	float Min_balance;
public:
	CurrentAccount(){
		Service_charges=10;
		Min_balance=100;
	}
	CurrentAccount(float c, float m,int acc,float bal):Account(acc,bal){
		Service_charges=c;
		Min_balance=m;
	}
	void Print(){
		cout<<"Account Number: "<<getAccountNo()<<endl;
		cout<<"Account Balance: "<<getBalance()<<endl;
		cout<<"Minimum Balance: "<<Min_balance<<endl;
		cout<<"Service Balance: "<<Service_charges<<endl;
	}
	bool Debit(float c){
		bool flag=1;
		if(getBalance()<Min_balance){
			setBalance(getBalance()-Service_charges);
		}
		if(getBalance()<c){
			flag=0;
		}
			
		return flag;
	}
	float credit(float c){setBalance(getBalance()+c);
		return getBalance();
	}
	
};

class SavingAccount: public Account{
	float interest;

public:
	SavingAccount(){
		interest=5;
	}
	SavingAccount(float c,int acc,float bal):Account(acc,bal){
		interest =c;
	}
	void Print(){
		cout<<"Account Number: "<<getAccountNo()<<endl;
		cout<<"Account Balance: "<<getBalance()<<endl;
		cout<<"Interest Rate: "<<interest<<endl;
	}
	bool Debit(float c){
		bool flag=1;
		if(getBalance()<c){
			flag=0;
		}
			
		return flag;
	}
	float Credit(float c){
		int x =getBalance()+c;
		setBalance(x);
		return getBalance();
	}
};

int main()
{
	Account *laraib = new CurrentAccount(10,100,6456456,500);
	Account *Akhtar = new SavingAccount(5,64890456,1500);

	laraib->Print();
	cout<<endl;
	laraib->Credit(200);
	cout<<laraib->Debit(1800);
	cout<<endl;
	laraib->Print();
	cout<<endl;

	Akhtar->Print();
	cout<<endl;
	Akhtar->Credit(200);
	cout<<Akhtar->Debit(1500);
	cout<<endl;
	Akhtar->Print();




	system("pause");
	return 0;
}