#include<iostream>
using namespace std;

template <class T>
class Node {
public:
	T data;
	Node<T>* next;
};

template <class T>
class LinkedList{
private:
	Node<T>* head;

public:
	LinkedList(){ head = NULL; }

	void insertAtStart(T const element){
		Node<T> *p = new Node<T>;
		p->data = element;
		p->next = head;
		head = p;
		print();
	}
	void insertAtEnd(T const element){
		Node<T> *p = head;
		while (p->next != NULL)
			p = p->next;
		Node<T> *temp = new Node<T>;
		temp->data = element;
		p->next = temp;
		temp->next = NULL;
		print();
	}
	void print() const{
		Node<T> *p = head;
		while (p != NULL) {
			cout << p->data<<" ";
			p = p->next;
		}
		cout << endl;

	}
	bool search(T const& element) const {
		Node<T> *p = head;
		bool flag = 0;
		while (p != NULL && flag == 0){
			if (p->data == element)
				flag = 1;
			p = p->next;
		}
		return flag;
	}
	bool isEmpty() const{
		if (head == NULL)
			return true;
		else
			return false;
	}
	bool insertBefore(T const v1, T const v2) const{
		if (search(v2) == false)
			return false;
		else{
			Node<T>* current = head, *previous = NULL;
			while (current->data != v2){
				previous = current;
				current = current->next;
			}
			Node<T> *p = new Node<T>;
			p->data = v1;
			previous->next = p;
			p->next = current;
		}
	}
	void deleteAll(T const value){
		Node<T> *current = head, *p = head, *previous = NULL;
		while (p != NULL){
			current = head;
			while (current != NULL && current->data != value){
				previous = current;
				current = current->next;
			}
			if (current != NULL && current->data == value){
				if (current == head)
					head = head->next;
				else
					previous->next = current->next;
			}
			p = current;
			delete[] current;
		}
	}
	~LinkedList(){
		Node<T>*p = head;
		while (head != NULL){
			head = head->next;
			delete[] p;
			p = head;
		}
	}
	void DeleteAtStart(){
		Node<T>*p = head;
		head = head->next;
		delete[] p;
		print();
	}
	void reverse(){
		Node<T>* p = head, *previous = NULL, *next = NULL;
		while (p != NULL) {
			next = p->next;
			p->next = previous;
			previous = p;
			p = next;
		}
		head = previous;
		print();
	}
};

int main(){
	LinkedList<int> head;
	head.insertAtStart(2);
	head.insertAtStart(6);
	head.insertAtStart(7);
	head.insertAtEnd(9);
	head.insertAtStart(7);
	head.insertAtStart(8);
	head.insertAtStart(9);
	head.insertBefore(3, 7);
	head.deleteAll(7);
	head.print();
	cout << head.search(2) << endl;
	cout << head.search(9) << endl;
	cout << head.search(10) << endl;
	head.DeleteAtStart();
	head.reverse();
	

	
	system("pause");
	return 0;
}
