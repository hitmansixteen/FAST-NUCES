//#include<iostream>
//using namespace std;
//
//template<class T>
//class DoubleyLinkedList{
//	class node{
//	public:
//		T data;
//		node* next;
//		node* prev;
//	};
//	node* head;
//
//	node* createNode(T val){// create a node  O(1)
//		node *temp = new node();
//		temp->data = val;
//		temp->next = NULL;
//		temp->prev = NULL;
//
//		return temp;
//	}
//public:
//	DoubleyLinkedList(){ head = NULL; }
//
//	void insert(T data){//O(n)
//		if (head == NULL){
//			head = createNode(data);
//			print();
//			return;
//		}
//		node *curr;
//		curr = head;
//		while (curr->next){
//			curr = curr->next;
//		}
//
//		node* temp = createNode(data);
//		temp->next = curr->next;
//		temp->prev = curr;
//		curr->next = temp;
//
//		print();
//	}
//
//	void print() {//O(n)
//		node* p = head;
//		while (p) {
//			cout << p->data << " ";
//			p = p->next;
//		}
//		cout << endl;
//	}
//
//	bool search(T data){//O(n)
//		if (head == NULL){
//			cout << "Empty LinkedList\n";
//			return false;
//		}
//		node *curr;
//		curr = head;
//		while (curr && curr->data != data){
//			curr = curr->next;
//		}
//
//		if (curr == NULL){
//			cout << data << " Not Found!\n";
//			return false;
//		}
//		else{
//			cout << data << " Found!\n";
//			return true;
//		}
//	}
//
//	void Update(T data, T new_data){//O(n)
//		if (head == NULL){
//			cout << "Empty LinkedList\n";
//			return;
//		}
//		node *curr;
//		curr = head;
//		while (curr){
//			if (curr->data == data){
//				cout << "Updated!\n";
//				curr->data = new_data;
//				print();
//			}
//			curr = curr->next;
//		}
//
//		if (curr == NULL){
//			cout << data << " Not Found!\n";
//		}
//		return;
//	}
//		void insertSorted(T const data) {//O(n2)
//			node *p, *q;
//			for (p = head; p->next; p = p->next){
//				for (q = p->next; q; q = q->next)
//					if (p->data > q->data)
//						swap(q->data, p->data);
//			}
//				
//
//			if (head == NULL) {
//				head = createNode(data);
//				print();
//				return;
//			}
//			node *curr;
//			curr = head;
//	
//			
//			while (curr->next && curr->data < data) { 
//				curr = curr->next;
//			}
//			node* temp = createNode(data);
//			if (curr == head) {
//				temp->next = head;
//				head = temp;
//				curr->prev = temp;
//			}
//			else {
//				temp->next = curr->next;
//				temp->prev = curr;
//				curr->next = temp;
//			}
//			
//			print();
//		}
//
//};
//
//int main(){
//
//	DoubleyLinkedList<int> a;
//	a.search(5);
//	a.insert(5);
//	a.insert(4);
//	a.insert(3);
//	a.insert(6);
//	a.insert(7);
//	a.insert(9);
//	a.insert(1);
//	a.insert(2);
//	a.insert(13);
//
//	a.search(5);
//	a.search(4);
//	a.search(3);
//	a.search(21);
//
//	a.insertSorted(7);
//
//	a.Update(5, 1);
//	a.Update(4, 1);
//	a.Update(7, 1);
//	a.Update(2, 1);
//
//
//	system("pause");
//	return 0;
//}