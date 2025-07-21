#include<iostream>
using namespace std;

class bst{
	class node{
	public:
		int marks;
		char grade;
		node* left;
		node* right;
		node(){
			left = nullptr;
			right = nullptr;
		}
		node(int m,char g){
			marks = m;
			grade = g;
			left = nullptr;
			right = nullptr;
		}
	};
	node *root;
	int a;
	int b;
	int c;
	int f;
	void insert(node *&p,int m){
		if (!p){
			char gr;
			if (m > 80){
				gr = 'A';
				a++;
			}
			else if (m >= 70 && m<=80){
				gr = 'B';
				b++;
			}
			else if (m >= 50 && m <= 69){
				gr = 'C';
				c++;
			}
			else{
				gr = 'D';
				f++;
			}
			p = new node(m, gr);
		}
		else if (p->marks > m)
			insert(p->left, m);
		else if (p->marks <= m)
			insert(p->right, m);
	}
public:
	bst(){
		root = NULL;
		a = b = c = f = 0;
	}
	void insert(int m){
		insert(root, m);
	}
	void print(){
		if (a)
			cout << "A Grade= " << a << " Students\n";
		if (b)
			cout << "B Grade= " << b << " Students\n";
		if (c)
			cout << "C Grade= " << c << " Students\n";
		if (f)
			cout << "F Grade= " << f << " Students\n";
	}
};

int main()
{
	bst tree;
	int size;
	cout << "Enter Size: ";
	cin >> size;
	int x;
	for (int i = 0; i < size; i++)
	{
		cout << "Input: ";
		cin >> x;
		tree.insert(x);
	}
	cout << "----------\n";
	tree.print();

	system("pause");
	return 0;
}