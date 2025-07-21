#include<iostream>
#include <vector>
#include<queue>
#include<string>
using namespace std;

template<typename K, typename V>
class SpecialBST {
	class node {
	public:
		K key;
		V value;
		node* left;
		node* right;
		node() {
			left = NULL;
			right = NULL;
		}
		node(K k, V v) {
			key = k;
			value = v;
			left = NULL;
			right = NULL;
		}
	};
	node* root;
	bool insert(K k, V v, node*& p) {
		if (!p) {
			p = new node(k, v);
			makeroot(root, p);
			return true;
		}
		else if (k < p->key)
			insert(k, v, p->left);
		else if (k > p->key)
			insert(k, v, p->right);
		else
			return false;
	}
	void inorder(node* p, vector<V>* vec) {
		if (p) {
			inorder(p->left, vec);
			vec->push_back(p->value);
			inorder(p->right, vec);

		}
	}
	V* search(K k, node* p, node* q) {
		if (!p) {
			makeroot(root, q);
			return NULL;
		}
		else if (k < p->key)
			search(k, p->left, p);
		else if (k > p->key)
			search(k, p->right, p);
		else {
			makeroot(root, p);
			return &p->value;
		}
	}
	bool Delete(K k, node*& p, node*& q) {
		if (!p) {
			makeroot(root, q);
			return false;
		}
		else if (k < p->key)
			Delete(k, p->left, p);
		else if (k > p->key)
			Delete(k, p->right, p);
		else {
			if (!p->left && !p->right) {
				delete p;
				p = NULL;
				makeroot(root, q);
			}
			else if (p->left && !p->right) {
				node* temp = p;
				p = p->left;
				delete temp;
				makeroot(root, q);
			}
			else if (!p->left && p->right) {
				node* temp = p;
				p = p->right;
				delete temp;
				makeroot(root, q);
			}
			else {
				node* successor = p->right;
				while (successor->left)
					successor = successor->left;
				p->key = successor->key;
				p->value = successor->value;
				Delete(successor->key, p->right, p);
				makeroot(root, q);
			}
			return true;
		}
	}
	void Destroy(node*& p) {
		if (p) {
			Destroy(p->left);
			Destroy(p->right);
			delete p;
		}
	}
	void leftRotate(node*& p) {
		node* y = p;
		node* x = y->right;
		node* z = x->left;
		p = x;
		x->left = y;
		y->right = z;
	}
	void rightRotate(node*& p) {
		node* y = p;
		node* x = y->left;
		node* z = x->right;
		p = x;
		x->right = y;
		y->left = z;
	}
	void makeroot(node*& p1, node* p2) {
		if (p1 == p2)
			return;
		else if (p1->key > p2->key)
			makeroot(p1->left, p2);
		else if (p1->key < p2->key)
			makeroot(p1->right, p2);
		if (p1->key < p2->key) {
			if (p1->right)
				leftRotate(p1);
		}
		else {
			if (p1->left)
				rightRotate(p1);
		}

	}
public:
	SpecialBST() { root = NULL; }

	bool insert(K k, V v) {
		if (!insert(k, v, root)) {
			cout << "Already Exists!\n";
			return false;
		}
		return true;
	}
	V* search(K k) { return search(k, root, root); }
	bool Delete(K k) { return Delete(k, root, root); }
	vector<V>* getValuesLevelWise() {
		if (!root)
			return NULL;
		queue<node*> q;
		q.push(root);
		vector<V>* vec = new vector<V>;
		cout << "ValuesLevelWise: \n";
		while (!q.empty()) {
			int count = q.size();
			while (count > 0) {
				node* p = q.front();
				cout << p->value << " ";
				q.pop();
				vec->push_back(p->value);
				if (p->left)
					q.push(p->left);
				if (p->right)
					q.push(p->right);
				count--;
			}
			cout << endl;
		}
		return vec;
	}
	vector<V>* getValuesInOrder() {
		vector<V>* vec = new vector<V>;
		inorder(root, vec);
		return vec;
	}
	~SpecialBST() {
		Destroy(root);
	}
};
class StudentData {
public:
	int roll_no;
	string first_name;
	string last_name;
	string department;
	int batch;
	float cgpa;
	StudentData(int r, string fn, string ln, string d, int b, float c) {
		roll_no = r;
		first_name = fn;
		last_name = ln;
		department = d;
		batch = b;
		cgpa = c;
	}
	StudentData() {
		roll_no = 0;
		first_name = '\0';
		last_name = '\0';
		department = '\0';
		batch = 0;
		cgpa = 0;
	}
};
class StudentList {
	SpecialBST<int, StudentData> bst;
public:
	bool insertNewStudent(int r, string fn, string ln, string d, int b, float c) {
		StudentData data(r, fn, ln, d, b, c);
		return bst.insert(r, data);
	}
	bool deleteStudent(int r) { return bst.Delete(r); };
	void search(int r) {
		StudentData* data = bst.search(r);
		if (data) {
			cout << "Roll Number: " << data->roll_no << endl;
			cout << "First Name: " << data->first_name << endl;
			cout << "Last Name: " << data->last_name << endl;
			cout << "Batch: " << data->batch << endl;
			cout << "Department: " << data->department << endl;
			cout << "CGPA: " << data->cgpa << endl;
		}
		else
			cout << "Roll number does not exist!\n";
	}
	bool search_r(int r) { return bst.search(r); }
	void update(int o_r,int r, string fn, string ln, string d, int b, float c) {
		StudentData* data;
		if (o_r == r) {
			data = bst.search(o_r);
			data->roll_no = r;
			data->first_name = fn;
			data->last_name = ln;
			data->batch = b;
			data->department = d;
			data->cgpa = c;
			cout << "Student data updated successfully.\n";
		}
		else if (bst.search(r))
			cout << "Roll Number already exists\n";
		else {
			deleteStudent(o_r);
			insertNewStudent(r, fn, ln, d, b, c);
			cout << "Student data updated successfully.\n";
		}
	}
	void print() {
		vector<StudentData>* vec;
		StudentData* data;
		vec = bst.getValuesInOrder();
		cout << "Total Students: " << vec->size() << endl;
		for (int i = 0; i < vec->size(); i++) {
			data = &(vec->at(i));
			cout << "Roll Number: " << data->roll_no << endl;
			cout << "First Name: " << data->first_name << endl;
			cout << "Last Name: " << data->last_name << endl;
			cout << "Batch: " << data->batch << endl;
			cout << "Department: " << data->department << endl;
			cout << "CGPA: " << data->cgpa << endl;
		}
	}

};
int main() {
	StudentList list;
	char choice = '0';
	string fn, ln, d;
	float c;
	int b, r,o_r;
	do {
		cout << "Press 'I' to insert a new student." << endl;
		cout << "Press 'D' to delete a student." << endl;
		cout << "Press 'S' to search a student by roll number." << endl;
		cout << "Press 'U' to update the data of a student." << endl;
		cout << "Press 'P' to print all the students sorted by roll number." << endl;
		cout << "Press 'E' to exit.\n>";
		cin >> choice;

		switch (choice) {
		case 'I':
			cout << "Please enter the data of new student in the order: Roll Number, First Name, Last Name, Batch, Department, CGPA\n>";
			cin >> r >> fn >> ln >> b >> d >> c;
			if (r < 0 || c > 4.0 || c < 0.0 || b < 0)
				cout << "Invalid Input" << endl;
			else if (!list.insertNewStudent(r, fn, ln, d, b, c))
				cout << "Roll Number already exists!\n";
			else
				cout << "New student inserted successfully!\n";
			break;
		case 'D':
			cout << "Please enter the roll number of the student that you want to delete:\n>";
			cin >> r;
			if (!list.deleteStudent(r))
				cout << "Roll Number does not Exists!\n";
			else
				cout << "Student deleted successfully!\n";
			break;
		case 'S':
			cout << "Please enter the roll number of the student that you want to search:\n>";
			cin >> r;
			list.search(r);
			break;
		case 'U':
			cout << "Please enter the roll number of the student whose data you want to update:\n>";
			cin >> o_r;
			if(o_r<0)
				cout << "Invalid Input" << endl;
			else if(!list.search_r(o_r))
				cout << "Roll Number does not Exists!\n";
			else {
				cout << "Please enter the data of new student in the order: Roll Number, First Name, Last Name, Batch, Department, CGPA\n>";
				cin >> r >> fn >> ln >> b >> d >> c;
				if (r < 0 || c > 4.0 || c < 0.0 || b < 0)
					cout << "Invalid Input" << endl;
				else
					list.update(o_r, r, fn, ln, d, b, c);
			}
			break;
		case 'P':
			list.print();
			break;
		}
	}while(choice!='E');

	return 0;
}