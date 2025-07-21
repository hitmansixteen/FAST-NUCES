//Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23506 for x64
#include <iostream>
#include <stack>
using namespace std;
template <typename T>
class LinkedList{
private:


	struct Node{  
		T data;
		Node*next;//pointer to next node

		Node(const T&d,Node*nptr=nullptr){
			data=d;//assumes operator is available
			next=nptr;
		}

		Node(){
			next=nullptr;
		}

    };

	Node * head, *tail;
	int size;

public:
	LinkedList(){//create an empty list
		head=tail=new Node;//dummy
		size=0;
	}

	bool empty()
	{
		return size==0;
	}

	//Use for push
	void insertAtHead(const T& obj){
		//empty
		//currently head and tail point to dummy
		//non-empty
		//head points to dummy, tail points to a different node
		//O(1)
		head->next = new Node(obj, head->next);//next points to???

		if(size==0)
			tail=tail->next;
		size++;

	}

	//For pop: remove at head
	//Peek: read at head 

	void insertAtTail(const T& obj){
		//empty
		//currently head and tail point to dummy
		//non-empty
		//head points to dummy, tail points to a different node
		//O(1)

		tail->next=new Node(obj);
		tail=tail->next;
		size++;
		
	}

	void insertInOrder(const T& obj){
		//O(n)
		
		if(size==0)
			insertAtHead(obj);
		else{
			Node * curr = head->next, *prev=head;

			if(obj<=curr->data){
				insertAtHead(obj);//smallest key at the start
			}else if(tail->data<=obj){
				insertAtTail(obj);//largest key at the end
			}else{
				//insert somewhere inside the the list
				Node* temp=new Node(obj);				
				while(curr!=nullptr && curr->data<=obj){
					prev=curr;//prev is one step behind curr
					curr=curr->next;
				}
				//connect temp
				prev->next=temp;
				temp->next=curr;
				size++;
				// temp-->curr
			}

		}
	}

	void eraseAtHead(){
		if(size>0){//O(1)
			Node * temp = head->next;
			head->next=head->next->next;
			delete temp;
			if(size==1)
				tail=head;
			size--;
		}
	}

	void eraseAtTail(){
		if(size>0){

			Node* ptail=head;//pointing to dummy

			while(ptail->next!=tail)//O(n)
				ptail=ptail->next;
			
			
			delete tail;
			ptail->next=nullptr;
			tail=ptail;

			size--;
		}
	}



	//testing
	void print(){
		Node * curr = head->next;
		while(curr!=nullptr){
			cout<<(curr->data)<<" ";
			//curr is a 4-byte address of a node
			curr = curr->next; //(*curr).next
		}
	}

	void eraseAtKey(const T& key){
		if(size>0){

			Node* prev=head, curr=head->next;//curr cannot be null
			
			while(curr!=nullptr && curr->data!=key){
				prev=curr;
				curr=curr->next;
			}

			if(curr!=nullptr){
				//curr is not nullptr, also, prev is not null

				if(curr==tail)
					tail=prev;
				prev->next=curr->next;
				delete curr;
				size--;
			}
		}
	}








	~LinkedList(){
		stack<Node*> lnodes;

		Node* curr=head;

		while(curr!=nullptr){
			lnodes.push(curr);
		}

		while(!lnodes.empty()){
			delete lnodes.top();
			lnodes.pop();
		}
	}

};

int main()
{

	LinkedList<int> l;
	l.insertInOrder(5);
	l.insertInOrder(11);
	l.insertInOrder(13);
	l.insertInOrder(2);


	l.print();
	







}
