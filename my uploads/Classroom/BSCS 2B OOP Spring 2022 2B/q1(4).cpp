#include <iostream>
using namespace std;

class Polynomial{
	int totalTerms;
	int* coeff;
	int* exp;

public:
	Polynomial(){
		totalTerms = 0;
		coeff = nullptr;
		exp = nullptr;
	}

	Polynomial(int terms, int* coefficient, int* exponent){
		totalTerms = terms;
		coeff = new int[terms];
		exp = new int[terms];

		for (int i = 0; i < no; i++){
			coeff[i] = coefficient[i];
			exp[i] = exponent[i];
		}
	}

	Polynomial& operator++(){
		for (int i = 0; i < totalTerms; i++)
			coeff[i]++;
		return *this;
	}

	Polynomial operator++(int){
		Polynomial temp(*this);
		for (int i = 0; i < totalTerms; i++)
			coeff[i]++;
		return temp;
	}

	Polynomial operator+(Polynomial& P){
		int max1 = 0;
		int max2 = 0;
		int max = 0;
		int found1,found2;
		for (int i = 0; i < totalTerms; i++)
		{
			if (exp[i] > max1)
			max1 = exp[i];
		}
		

		for (int i = 0; i < P.totalTerms; i++)
		{
			if (P.exp[i] > max2)
			max2 = P.exp[i];
		}
		
		
		if (max1 > max2)
			max = max1;
		else
			max = max2;
		int count = 0;
		for (int i = max; i >= 0; i--){
			bool found1 = false;

			for (int j = 0; j < totalTerms && found1 == false; j++)
			if (exp[j] == i)
				found1 = true;

			bool found2 = false;

			for (int j = 0; j < P.totalTerms && found2 == false; j++)
			if (P.exp[j] == i)
				found2 = true;

			if (found1 == true || found2 == true)
				count++;
		}

		Polynomial temp;
		temp.totalTerms = count;
		temp.coeff = new int[count];
		temp.exp = new int[count];

		count = 0;
		for (int i = max; i >= 0; i--){
			found1 = -1;

			for (int j = 0; j < totalTerms && found1 == -1; j++)
			if (exp[j] == i)
				found1 = j;

			found2 = -1;

			for (int j = 0; j < P.totalTerms && found2 == -1; j++)
			if (P.exp[j] == i)
				found2 = j;

			if (found1 != -1 && found2 != -1){
				temp.exp[count] = i;
				temp.coeff[count] = coeff[found1] + P.coeff[found2];
				count++;
			}
			else if (found1 != -1 && found2 == -1){
				temp.exp[count] = i;
				temp.coeff[count] = coeff[found1];
				count++;
			}
			else if (found1 == -1 && found2 != -1){
				temp.exp[count] = i;
				temp.coeff[count] = P.coeff[found2];
				count++;
			}
		}

		return temp;
	}

	bool operator!(){
		if (totalTerms == 1 && coeff[0] == 0 && exp[0] == 0)
			return true;
		return false;
	}

	bool operator!=(Polynomial& P){
		if (totalTerms != P.totalTerms)
			return true;
		for (int i = 0; i < totalTerms; i++)
		if (coeff[i] != P.coeff[i] || exp[i] != P.exp[i])
			return true;
		return false;
	}

	

	Polynomial& operator=(Polynomial& copy){
		if (totalTerms > 0){
			delete[] coeff;
			delete[] exp;
		}

		totalTerms = copy.totalTerms;
		coeff = new int[totalTerms];
		exp = new int[totalTerms];

		for (int i = 0; i < totalTerms; i++){
			coeff[i] = copy.coeff[i];
			exp[i] = copy.exp[i];
		}

		return *this;
	}

	Polynomial(Polynomial& copy){
		totalTerms = copy.totalTerms;
		coeff = new int[totalTerms];
		exp = new int[totalTerms];

		for (int i = 0; i < totalTerms; i++){
			coeff[i] = copy.coeff[i];
			exp[i] = copy.exp[i];
		}
	}

	friend Polynomial operator+(int, Polynomial&){
		bool found = false;
	for (int i = 0; i < P.totalTerms; i++)
	if (P.exp[i] == 0)
		found = true;
	if (found == true){
		Polynomial temp(P);
		for (int i = 0; i < temp.totalTerms; i++)
		if (temp.exp[i] == 0)
			temp.coeff[i] += a;
		return temp;
	}
	else{
		Polynomial temp;
		temp.totalTerms = P.totalTerms + 1;
		temp.coeff = new int[temp.totalTerms];
		temp.exp = new int[temp.totalTerms];
		for (int i = 0; i < P.totalTerms; i++){
			temp.coeff[i] = P.coeff[i];
			temp.exp[i] = P.exp[i];
		}

		temp.coeff[P.totalTerms] = a;
		temp.exp[P.totalTerms] = 0;
		return temp;
	}
	}
	friend ostream& operator<<(ostream&, Polynomial&){
		for (int i = 0; i < P.totalTerms; i++){
		if (P.coeff[i] != 1)
			out << P.coeff[i];
		if (P.exp[i] != 0)
			out << "x";
		if (P.exp[i] != 1 && P.exp[i] != 0)
			out << "^" << P.exp[i];
		if (i != P.totalTerms - 1)
			out << "+";
	}
	return out;
	}
	
};





int main()
{
	int coeff_P1[] = { 1, 2, 5 }; //Coefficients for Polynomial P1
	int exp_P1[] = { 4, 2, 0 }; //Exponents for Polynomial P1
	int coeff_P2[] = { 4, 3 }; //Coefficients for Polynomial P2
	int exp_P2[] = { 6, 2 }; //Exponents for Polynomial P2

	Polynomial P1(3, coeff_P1, exp_P1);//Creates P1 with 3 terms (P1 = 1x^4 + 2x^2 + 5x^0 )
	Polynomial P2(2, coeff_P2, exp_P2);//Creates P2 with 2 terms (P2 = 4x^6 + 3x^2)

	cout << "P1 = " << P1 << endl; //Prints P1 = x^4+2x^2+5
	cout << "P2 = " << P2 << endl; //Prints P2 = 4x^6+3x^2

	if (!P1)
		cout << "P1 is zero" << endl; /*if polynomial has only 1 term and its coeff and exp are zero. i.e. if p1 = 0.*/

	if (P1 != P2)
		cout << "P1 is Not Equal to P2" << endl;

	cout << ++P1 << endl; //adds 1 in all the coefficient.
	cout << P1 << endl;

	cout << P1++ << endl; //adds 1 in all the coefficient.
	cout << P1 << endl;

	Polynomial P3 = P1 + P2; //Adds P1 and P2 and saves result in P3.You may consume extra space for resultant Polynomial in Add function
	cout << "P3 = " << P3 << endl; //Prints P3 = 4x^6+x^4+5x^2+5

	P3 = 2 + P2; //Assume P1 already has a constant term, add 2 in it.
	cout << "P3 = " << P3 << endl;

	Polynomial P4;

	P4 = P1;
	cout << "P4 = " << P4 << endl;

	system("pause");
	return 0;
}