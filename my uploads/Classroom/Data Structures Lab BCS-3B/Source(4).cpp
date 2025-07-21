#include<iostream>
using namespace std;

template<class T>
class queue{
	class node{
	public:
		T data;
		node* next;
		node(){ next = nullptr; }
		node(T ele){
			data = ele;
			next = nullptr;
		}
	};
	node* head;
	node* tail;
	int size;
public:
	queue(){ head = tail = NULL; size = 0; }
	bool isEmpty(){ return size == 0; }
	void enqueue(T ele){
		node* temp = new node(ele);
		if (isEmpty())
			head = tail = temp;
		else{
			tail->next = temp;
			tail = temp;
		}
		size++;
		print();
	}
	void dequeue(){
		node* temp = head;
		if (isEmpty())
			cout << "Empty Queue\n";
		else{
			head = head->next;
			delete temp;
			size--;
		}
		print();
	}
	void print(){
		node *p = head;
		while (p){
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	int Size(){ return size; }
	T front(){ return head->data; }
	T rear(){ return tail->data; }
};


int main(){
	queue<int> *q = new queue<int>;
	int x;
	for (int i = 0; i < 8; i++)
	{
		cin >> x;
		q->enqueue(x);
	}
	q->dequeue();
	int k;
	bool flag = 1;
	int count = 0;
	cout << "Enter the value of k: ";
	cin >> k;
	queue<int>* p = new queue<int>;
	while (q->Size()){
		int temp;
		for (int i = 0; i < 2 && q->Size(); i++)
		{
			temp = q->front();
			q->dequeue();
			p->enqueue(temp);
			if (q->Size()){
				if (temp + 1 == q->front()){
					count++;
				}
			}
			
		}
		if (q->Size()){
			temp = q->front();
			q->dequeue();
			p->enqueue(temp);
		}
		if (count != 2){
			flag = 0;
		}
		count = 0;


		for (int i = 0; i < k && q->Size(); i++)
		{
			temp = q->front();
			q->dequeue();
			p->enqueue(temp);
		}
	}
	q = p;
	if (flag == 1)
		cout << "Yes\n";
	else
		cout << "No\n";

	system("pause");

}