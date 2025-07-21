//#include<iostream>
//#include <vector>
//#include<queue>
//using namespace std;
//
//template<typename K, typename V>
//class SpecialBST {
//	class node {
//	public:
//		K key;
//		V value;
//		node* left;
//		node* right;
//		node() {
//			left = NULL;
//			right = NULL;
//		}
//		node(K k, V v) {
//			key = k;
//			value = v;
//			left = NULL;
//			right = NULL;
//		}
//	};
//	node* root;
//	bool insert(K k, V v, node*& p) {
//		if (!p) {
//			p = new node(k, v);
//			makeroot(root, p);
//			return true;
//		}
//		else if (k < p->key)
//			insert(k, v, p->left);
//		else if (k > p->key)
//			insert(k, v, p->right);
//		else
//			return false;
//	}
//	void inorder(node* p, vector<V>* vec) {
//		if (p) {
//			inorder(p->left, vec);
//			vec->push_back(p->value);
//			cout << p->key << " ";
//			inorder(p->right, vec);
//
//		}
//	}
//	V* search(K k, node* p,node* q) {
//		if (!p) {
//			makeroot(root, q);
//			return NULL;
//		}
//		else if (k < p->key) 
//			search(k, p->left, p);
//		else if (k > p->key)
//			search(k, p->right, p);
//		else {
//			makeroot(root, p);
//			return &p->value;
//		}
//	}
//	bool Delete(K k, node*& p,node*& q) {
//		if (!p) {
//			makeroot(root, q);
//			return false;
//		}
//		else if (k < p->key)
//			Delete(k, p->left,p);
//		else if (k > p->key)
//			Delete(k, p->right,p);
//		else {
//			if (!p->left && !p->right) {
//				delete p;
//				p = NULL;
//				makeroot(root, q);
//			}
//			else if (p->left && !p->right) {
//				node* temp = p;
//				p = p->left;
//				delete temp;
//				makeroot(root, q);
//			}
//			else if (!p->left && p->right) {
//				node* temp = p;
//				p = p->right;
//				delete temp;
//				makeroot(root, q);
//			}
//			else {
//				node* successor = p->right;
//				while (successor->left)
//					successor = successor->left;
//				p->key = successor->key;
//				p->value = successor->key;
//				Delete(successor->key, p->right,p);
//				makeroot(root, q);
//			}
//			return true;
//		}
//	}
//	void Destroy(node*& p) {
//		if (p) {
//			Destroy(p->left);
//			Destroy(p->right);
//			delete p;
//		}
//	}
//	void leftRotate(node*& p){
//		node* y = p;
//		node* x = y->right;
//		node* z = x->left;
//		p = x;
//		x->left = y;
//		y->right = z;
//	}
//	void rightRotate(node*& p) {
//		node* y = p;
//		node* x = y->left;
//		node* z = x->right;
//		p = x;
//		x->right = y;
//		y->left = z;
//	}
//	void makeroot(node*& p1, node* p2) {
//		if (p1 == p2)
//			return;
//		else if (p1->key > p2->key)
//			makeroot(p1->left, p2);
//		else if (p1->key < p2->key)
//			makeroot(p1->right, p2);
//		if (p1->key < p2->key) {
//			if (p1->right)
//				leftRotate(p1);
//		}
//		else {
//			if (p1->left)
//				rightRotate(p1);
//		}
//			
//	}
//public:
//	SpecialBST() { root = NULL; }
//
//	bool insert(K k, V v) {
//		if (!insert(k, v, root)) {
//			cout <<"Already Exists!\n";
//			return false;
//		}
//		return true;
//	}
//	V* search(K k) { return search(k, root,root); }
//	bool Delete(K k) { return Delete(k, root,root); }
//	vector<V>* getValuesLevelWise(){
//		if (!root)
//			return NULL;
//		queue<node*> q;
//		q.push(root);
//		vector<V>* vec = new vector<V>;
//		cout << "ValuesLevelWise: \n";
//		while (!q.empty()) {
//			int count = q.size();
//			while (count > 0) {
//				node* p = q.front();
//				cout << p->value << " ";
//				q.pop();
//				vec->push_back(p->value);
//				if (p->left)
//					q.push(p->left);
//				if (p->right)
//					q.push(p->right);
//				count--;
//			}
//			cout << endl;
//		}
//		return vec;
//	}
//	vector<V>* getValuesInOrder(){
//		vector<V>* vec = new vector<V>;
//		inorder(root, vec);
//		cout << endl;
//		return vec;
//	}
//	~SpecialBST(){
//		Destroy(root);
//	}
//};
//
//int main() {
//	SpecialBST<int, int> bst;
//	bst.insert(13, 13);
//	bst.insert(7, 7);
//	bst.insert(25, 25);
//	bst.insert(17, 17);
//	bst.insert(39, 39);
//	bst.insert(15, 15);
//	bst.insert(14, 14);
//	bst.insert(16, 16);
//	bst.getValuesLevelWise();
//	bst.search(50);
//	bst.getValuesLevelWise();
//	bst.Delete(24);
//	bst.getValuesLevelWise();
//
//	system("pause");
//	return 0;
//}