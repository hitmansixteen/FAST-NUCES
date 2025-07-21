#include<iostream>
using namespace std;

template <class T>
class stack{
	class node{
	public:
		T data;
		node* next;
		node(){ next = NULL; }
		node(T ele){
			next = NULL;
			data = ele;
		}
	};
	node* head;
	int size;
public:
	stack(){
		head = NULL;
		size = 0;
	}
	int Size(){ return size; }
	bool isEmpty(){
		if (!head)
			return true;
		else
			return false;
	}
	bool top(T& ele){
		if (head){
			ele = head->data;
				return true;
		}
		else
			return false;
	}
	bool pop(T& ele){
		if (!isEmpty()){
			node* temp = head;
			head = head->next;
			ele = temp->data;
			delete temp;
			size--;
			return true;
		}
		cout << "Error!\n";
		return false;
	}
	void print(){
		node* temp = head;
		while (temp){
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void push(T const& e){
		node* temp = new node(e);
		temp->next = head;
		head = temp;
		size++;
		
	}
	void triple(){
		stack<char>* temp = new stack<char>;
		int count = 1;
		T ele1,ele2;

		while (count < 3 && !isEmpty()){
			pop(ele1);
			temp->push(ele1);
			top(ele1);
			temp->top(ele2);
			if (ele1 == ele2)
				count++;
			else{
				count = 0;
			}
			if (count == 3){
				temp->pop(ele1);
				temp->pop(ele1);
				temp->pop(ele1);
				count = 0;
			}
		}
		while (!temp->isEmpty()){
			temp->pop(ele1);
			push(ele1);
		}
		print();
	}
	void delete_middle(){
		stack<int>* temp = new stack<int>;
		int count = 0;
		int ele;
		int mid = (size / 2) -1;

		for (int i = 0; i < mid; i++){
			pop(ele);
			temp->push(ele);
		}
		pop(ele);
		while (!temp->isEmpty()){
			temp->pop(ele);
			push(ele);
		}
		print();
	}
	~stack(){
		T ele;
		while (!isEmpty()){
			pop(ele);
		}
	}
	
};

int main(){
	
	stack<int>* h = new stack<int>;
	h->push(6);
	h->push(5);
	h->push(4);
	h->push(3);
	h->push(2);
	h->push(1);
	h->print();
	h->delete_middle();
	
	stack<char>* t = new stack<char>;
	t->push('y');
	t->push('b');
	t->push('b');
	t->push('b');
	t->push('z');
	t->push('a');
	t->print();
	t->triple();


	system("pause");
	return 0;
}