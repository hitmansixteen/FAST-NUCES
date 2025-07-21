#include<iostream>
using namespace std;

template<class T>
class CircularlyLinkedList{
	class node{
	public:
		T data;
		node* next;
	};
	node* head;

	node* createNode(T val){// create a node  O(1)
		node *temp = new node();
		temp->data = val;
		temp->next = NULL;

		return temp;
	}
public:
	CircularlyLinkedList(){ head = NULL; }

	void insert(T data){// O(n)
		if (head == NULL){
			head = createNode(data);
			head->next = head;
			print();
			return;
		}
		node *curr;
		curr = head;
		while (curr->next!=head){
			curr = curr->next;
		}

		node* temp = createNode(data);
		temp->next = curr->next;
		curr->next = temp;

		print();
	}

	void print() {//O(n)
		node* p = head;
		do{
			cout << p->data << " ";
			p = p->next;
		} while (p != head);
		cout << endl;
	}

	bool search(T data){//O(n)
		if (head == NULL){
			cout << "Empty LinkedList\n";
			return false;
		}
		node *curr;
		curr = head;
		while (curr->next!=head && curr->data != data){
			curr = curr->next;
		}

		if (curr->next == head){
			cout << data << " Not Found!\n";
			return false;
		}
		else{
			cout << data << " Found!\n";
			return true;
		}
	}

	void Update(T data, T new_data){//O(n)
		if (head == NULL){
			cout << "Empty LinkedList\n";
			return;
		}
		node *curr;
		curr = head;
		while (curr->next != head){
			if (curr->data == data){
				cout << "Updated!\n";
				curr->data = new_data;
				print();
			}
			curr = curr->next;
		}

		if (curr->next == head){
			cout << data << " Not Found!\n";
		}
		return;
	}

	bool Check(){//O(n)
		node* p = head;
		while (p->next != head && p->next){
			p = p->next;
		}
		if (p->next == head){
			cout << "This is a Circularly Linked List!\n";
			return true;
		}
		else{
			cout << "This is not a Circularly Linked List!\n";
			return false;
		}
	}

	void insertBefore(T const v1, T const v2) {// O(n)
		if (head == NULL) {
			cout << v2 << " Not Found!\n";
			return;
		}
		node *prev, *curr;
		prev = head;
		curr = prev->next;
		node* temp = createNode(v1);
		while (curr != head && curr->data != v2){
			prev = curr;
			curr = curr->next;
		}
		temp->next = curr;
		prev->next = temp;
		print();

	}
};

int main(){

	CircularlyLinkedList<int> a;
		a.search(5);
		a.insert(5);
		a.insert(4);
		a.insert(3);
		a.insert(6);
		a.insert(7);
		a.insertBefore(9,7);
		a.insertBefore(7,3);
		a.insert(13);
		a.insertBefore(2,5);
	
		a.search(5);
		a.search(4);
		a.search(3);
		a.search(2);
	
		a.Update(5, 1);
		a.Update(4, 1);
		a.Update(7, 1);
		a.Update(2, 1);

		a.Check();
	

	system("pause");
	return 0;
}