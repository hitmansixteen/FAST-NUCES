#include<iostream>
using namespace std;
template<typename T>
class BST{
	class node{
	public:
		T data;
		node* left;
		node* right;

		node(){
			data = NULL;
			left = right = nullptr;

		}
		node(T d){
			data = d;
			left = right = nullptr;

		}
	};
	int height(node* temp)
	{
		int h = 0;

		if (temp){
			int leftHeight = height(temp->left);
			int rightHeight = height(temp->right);
			int maxHeight = max(leftHeight, rightHeight);
			h = maxHeight + 1;
		}

		return h;
	}

	int difference(node* temp){
		int leftHeight = height(temp->left);
		int rightHeight = height(temp->right);
		int balanceFactor = leftHeight - rightHeight;

		return balanceFactor;
	}
	int max(int a, int b){
		return (a > b) ? a : b;
	}
	bool insert(node*&p, T d){
		if (!p){
			p = new node(d);
		}
		if (p->data > d)
			insert(p->left, d);
		else if (p->data < d)
			insert(p->right, d);
		else
			return false;

		int balancefactor = difference(p);
			if (balancefactor > 1){
				if (difference(p->left) > 0)
					LeftLeft(p);
				else
					LeftRight(p);
			}
			else if (balancefactor < -1){
				if (difference(p->right) > 0)
					RightLeft(p);
				else
					RightRight(p);
	
			}

		return true;

	}
	node* RightRight(node*& temp){
		node* temporary = temp;
		temp = temp->right;
		temporary->right = NULL;
		if (temp->left == NULL)
			temp->left = temporary;
		else{
			node* current = temp;
			while (current->left != NULL)
				current = current->left;
			current->left = temporary;
		}
	
		return temporary;
	
	}
	
	node* LeftLeft(node*& temp){
		node* temporary = temp;
		temp = temp->left;
		temporary->left = NULL;
		if (temp->right == NULL)
			temp->right = temporary;
		else{
			node* current = temp;
			while (current->right != NULL)
				current = current->right;
			current->right = temporary;
	
		}
		return temporary;
	}
	
	node* RightLeft(node*& temp){
		LeftLeft(temp->right);
		return RightRight(temp);
	}
	
	node* LeftRight(node*& temp){
		RightRight(temp->left);
		return LeftLeft(temp);
	}
	bool search(node*p, T d){
		if (!p)
			return false;
		else if (p->data > d)
			search(p->left, d);
		else if (p->data < d)
			search(p->right, d);
		else
			return true;
	}
	void preorder(node*p){
		if (p){
			cout << p->data << " ";
			preorder(p->left);
			preorder(p->right);
		}
	}
	void InOrder(node*p){
		if (p){
			InOrder(p->left);
			cout << p->data << " ";
			InOrder(p->right);
		}
	}
	void postorder(node*p){
		if (p){
			postorder(p->left);
			postorder(p->right);
			cout << p->data << " ";
		}
	}
	node* findmin(node *p){
		if (!p->left)
			return p;
		return findmin(p->left);
	}
	node* secondmin(node *p){
		if (!((p->left)->left))
			return p;
		return secondmin(p->left);
	}
	bool check(node* temp){
		if (difference(temp) >= -1 || (difference(temp) <= 1))
			return true;
		else
			return false;
	}

	bool isAVL(node* temp){
		if (temp) 
			return (check(temp) && isAVL(temp->left) && isAVL(temp->right));
		else 
			return true;
	}


	node* root;
public:
	BST(){ root = nullptr; }
	bool insert(T d){ return insert(root, d); }
	bool search(T d){ return search(root, d); }
	void preorder(){ preorder(root); cout << endl; }
	void InOrder(){ InOrder(root); cout << endl; }
	void postorder(){ postorder(root); cout << endl; }
	void findmin(){ 
		node *p = findmin(root);
		if (p)
			cout << "Minimum: " << p->data << endl;

	}
	void secondmin(){
		node *p = secondmin(root);
		if (p)
			cout << "Second Minimum: " << p->data << endl;

	}
	bool isAVL(){
		if (!root){
			cout << "Empty Tree!\n";
			return true;
		}
		else if (isAVL(root)){
			cout << "Tree is AVL!\n";
			return true;
		}
		cout << "Not AVL\n";
		return false;
		 
	}
};
int main(){

	BST<int> bst;
	bst.insert(1);
	cout << "PreOrder Print: ";
	bst.preorder();
	bst.insert(2);
	cout << "PreOrder Print: ";
	bst.preorder();
	bst.insert(3);
	cout << "PreOrder Print: ";
	bst.preorder();
	bst.insert(4);
	cout << "PreOrder Print: ";
	bst.preorder();
	bst.insert(5);
	cout << "PreOrder Print: ";
	bst.preorder();
	bst.insert(6);
	cout << "PreOrder Print: ";
	bst.preorder();
	bst.insert(7);
	cout << "PreOrder Print: ";
	bst.preorder();
	bst.insert(8);
	cout << "InOrder Print: ";
	bst.InOrder();
	cout << "PreOrder Print: ";
	bst.preorder();
	cout << "PostOrder Print: ";
	bst.postorder();
	if (bst.search(10))
		cout << "found!\n";
	else
		cout << "Not found!\n";
	bst.findmin();
	bst.secondmin();
	bst.isAVL();


	system("pause");
	return 0;
}