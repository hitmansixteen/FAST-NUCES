//Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23506 for x64
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

template <typename T>
class bst{
	struct treeNode{
		T data;
		treeNode * lchild, *rchild;

		treeNode(const T& obj){
			data=obj;//deep copy
			lchild=rchild=nullptr;
		}

	};

	treeNode* root;
	int n;

	bool getAccess(const T& key, treeNode*& par){
		//returns false if key exists
		par=nullptr;
		treeNode*curr = root;
		while(curr!=nullptr){
			par=curr;
			if(key==curr->data)
				return true;
			else if(key<curr->data){
				curr=curr->lchild;
			}else{
				curr=curr->rchild;
			}
		}
		return false;
	}

	void printInOrder(treeNode* curr){
		if(curr!=nullptr){
			//LNR
			printInOrder(curr->lchild);
			cout<<(curr->data)<<" ";
			printInOrder(curr->rchild);
		}
	}

	void printPostOrder(treeNode* curr){
		if(curr!=nullptr){
			//LRN
			printPostOrder(curr->lchild);
			printPostOrder(curr->rchild);
			cout<<(curr->data)<<" ";
		}
	}

	void cleanup(treeNode* curr){
		if(curr!=nullptr){//post order
			cleanup(curr->lchild);
			cleanup(curr->rchild);
			delete curr;
		}
	}
	void copy(treeNode*& curr, treeNode* objptr){
		//Using Pre-order
		if(objptr!=nullptr){
			curr = new treeNode(objptr->data);
			copy(curr->lchild, objptr->lchild);
			copy(curr->rchild, objptr->rchild);
		}
	}


	void eraseCase0(treeNode* curr, treeNode* par){
		if(curr==root){
			root=nullptr;
		}else{
			if(curr==par->lchild)
				par->lchild=nullptr;
			else 
				par->rchild=nullptr;
		}
		delete curr;	
	}

	void eraseCase1(treeNode* curr, treeNode* par){
		if(curr==root){
			root = (curr->lchild!=nullptr)?curr->lchild:curr->rchild;
		}else{
			if(curr==par->lchild){
				par->lchild=(curr->lchild!=nullptr)?curr->lchild:curr->rchild;
			}else{//par->rchild==curr
				par->rchild=(curr->lchild!=nullptr)?curr->lchild:curr->rchild;
			}
		}

		delete curr;	
	}





	int numOfChild(treeNode* curr){
		if(curr==nullptr)
			return -1;
		else
			return 
			int(curr->lchild!=nullptr)+
			int(curr->rchild!=nullptr);
	}


public:
	void erase(const T& key){
		treeNode* par;
		if(getAccess(key, par)){
			//key found
			treeNode*curr = 
				(par->data<key)?par->rchild:par->lchild;//tertiary operator
			    //condition?do something:else do this
				
			if(numOfChild(curr)==0){
				//case 0
				eraseCase0(curr, par);
			}else if(numOfChild(curr)==1){
				//case 1
				eraseCase1(curr, par);
			}else{
				//case 2
				//eraseCase2(curr, par);
			}

		

		}
	}


	bst(const bst<T> & obj){
		//copy constructor
		copy(root, obj.root); 
	}

	const bst<T>& operator = (const bst<T>& obj){
		cleanup(root);//uses post order
		copy(root, obj.root);//uses preorder
	}

	void insert(const T & data){
		treeNode* par;
		if(getAccess(data, par)==false){
			//add new node as a child of parent
			//par contains the parent pointer
			treeNode * temp = new treeNode(data);
			if(par==nullptr){//tree is empty
				root=temp;
			}else{
				if(par->data<data){
					par->rchild=temp;
				}else{
					par->lchild=temp;
				}
			}
			n++;
		}
	}

	//public
	void printInOrder(){
		printInOrder(root);
	}

	bst(){
		root=nullptr;
		n=0;
	}

	~bst(){
		cleanup(root);
	}



};

int main(){
	bst<int> t1;
	for(int i=0; i<10; i++){
		t1.insert(i);
	}

	//bst<int> t2=t1;
	t1.printInOrder();

}




