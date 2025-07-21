#include<iostream>
using namespace std;

template <class T>
class LinkedList{
	class Node{
	public:
		T data;
		Node* next;
		Node(){
			next = NULL;
		}
		Node(T ele){
			next = NULL;
			data = ele;
		}
	};
public:
	Node* head;
	LinkedList(){ head = NULL; }
	void insert(T ele){
		Node* temp = new Node(ele);
		Node *p = head;
		if (head == NULL){
			head = temp;
			return;
		}
		while (p->next){
			p = p->next;
		}
		p->next = temp;
		print();
	}
	void print(){
		Node* temp = head;
		while (temp){
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	LinkedList* add(LinkedList* l2){
		Node* temp1 = head;
		int carry=0;
		Node* temp2 = l2->head;
		while (temp1 && temp2){
			temp1->data = temp1->data + temp2->data + carry;
			if (temp1->data >= 10){
				temp1->data = temp1->data % 10;
				carry += 1;
			}
			else
				carry = 0;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		while (temp2){
			insert(temp2->data);
			temp2 = temp2->next;

		}
		
		return this;
	}
};

int main(){
	LinkedList<int>* result = NULL;
	LinkedList<int>* l1 = new LinkedList<int>;
	LinkedList<int>* l2 = new LinkedList<int>;
	
	l1->insert(2);
	l1->insert(4);
	l1->insert(3);

	l2->insert(5);
	l2->insert(6);
	l2->insert(4);
	l2->insert(4);


	result = l1->add(l2);
	result->print();

	
	system("pause");
	return 0;
}