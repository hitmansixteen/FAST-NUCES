#include<iostream>
using namespace std;

class BST{
	class node{
	public:
		int data;
		node* left;
		node* right;
		node(){
			data = 0;
			left = right = nullptr;
		}
		node(int d){
			data = d;
			left = right = nullptr;
		}
	};
	node* root;
	bool insert(int d, node*& Node){
		if (!Node)
			Node = new node(d);
		else if (Node->data == d)
			return false;
		else if (Node->data > d)
			insert(d, Node->left);
		else
			insert(d, Node->right);
		return true;
	}
	void copy_helper(node *&q,node *&p){
		if (!p)
			q = nullptr;
		else{
			q = new node(p->data);
			copy_helper(q->left, p->left);
			copy_helper(q->right, p->right);
		}
		
	}
	void preOrder(node* t) {
		if (t){
			visit(t);
			preOrder(t->left);
			preOrder(t->right);
		}
	}
	void inOrder(node* t) {
		if (t){
			inOrder(t->left);
			visit(t);
			inOrder(t->right);
		}
	}
	void postOrder(node* t) {
		if (t){
			postOrder(t->left);
			postOrder(t->right);
			visit(t);
		}
	}
	void visit(node* t){ cout << t->data << " "; }
	node* search(node* d, int key){
		if (d){
			if (d->data > key)
				search(d->left, key);
			else if (d->data < key)
				search(d->right, key);
			else
				return d;
		}
		else
			return nullptr;
	}
	void length(node* t,int &count) {
		if (t){
			count++;
			length(t->left,count);
			length(t->right,count);
		}
	}
	void leafCount(node* t, int &count) {
		if (t){
			if (!t->left && !t->right)
				count++;
			leafCount(t->left, count);
			leafCount(t->right, count);
		}
	}
	void destroy(node *&p){
		if (p){
			destroy(p->left);
			destroy(p->right);
			delete p;
		}
	}
public:
	BST(){ root = nullptr; }
	bool insert(int d){
		if (!insert(d, root)){
			cout << "Already Exists\n";
			return false;
		}
		return true;
	}
	BST(BST &b){copy_helper(root, b.root);}
	void preOrder() {preOrder(root);}
	void inOrder(){inOrder(root);}
	void postOrder() {postOrder(root);}
	node* search(int key){
		node* temp = search(root, key);
		if (temp)
			cout << temp->data << " found! \n";
		else
			cout << key<<" Not found\n";
		return nullptr;
	}
	int length(){
		int count = 0;
		length(root, count);
		return count;
	}
	int leafCount(){
		int count = 0;
		leafCount(root, count);
		return count;
	}
	~BST(){destroy(root);}
};

int main(){
	BST tree;

	tree.insert(500);
	tree.insert(1000);
	tree.insert(1);
	tree.insert(600);
	tree.insert(700);
	tree.insert(10);
	tree.insert(30);
	tree.insert(9000);
	tree.insert(50000);
	tree.insert(20);

	cout << "Printing data using recursive inorder traversal: ";  	
	tree.inOrder();

	cout << "\nCOPY CONSTRUCTOR\n";
	BST tree1(tree);

	cout << "\n Preorder Traversal \n";  	
	tree1.preOrder();
	cout << "\n Inorder Traversal \n";
	tree1.inOrder();
	cout << "\n Postorder Traversal \n";
	tree1.postOrder();

	cout << "\n SEARCH: ";

	tree.search(1);
	tree.search(30);
	tree.search(50);

	cout << "\nTree Length: " << tree.length() << endl << endl;

	cout << "\nTree Leaf Nodes: " << tree.leafCount() << "\n";

	cout << endl;

	system("pause");
	return 0;
}