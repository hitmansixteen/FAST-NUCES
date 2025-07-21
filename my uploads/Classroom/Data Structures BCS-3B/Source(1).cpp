#include<iostream>
#include<list>
#include<vector>
#include<assert.h>
#include<string>
#include<fstream>
#include<time.h>

using namespace std;

class MinHeap {
	pair<int, int>* array;
	int size;
public:
	MinHeap(int s = 100) {
		array = new pair<int, int>[s];
		size = 0;
	}
	bool isEmpty() {
		if (size == 0)
			return true;
		return false;
	}
	int isPresent(int x){
		for (int i = 1; i <= size; i++)
			if (array[i].first == x)
				return i;
		return 0;
	}
	int getKey(int x){
		for (int i = 1; i <= size; i++)
			if (array[i].first == x)
				return array[i].second;
		return -1;
	}
	void insert(int x, int k){
		size++;
		array[size].first = x;
		array[size].second = INT_MAX;
		decreaseKey(size, k);

	}
	int min() { return array[1].first; }
	int ExtractMin(int* x)
	{
		int min = array[1].first;
		(*x) = array[1].second;
		array[1].first = array[size].first;
		array[1].second = array[size].second;
		size--;
		BuildHeap(1);

		return min;
	}
	void BuildHeap(int i){
		if (i <= size / 2){
			int index = 2 * i;
			if (2 * i + 1 <= size && array[2 * i + 1].second < array[2 * i].second)
				index = 2 * i + 1;

			if (array[index].second < array[i].second){
				swap(array[i].first, array[index].first);
				swap(array[i].second, array[index].second);

				BuildHeap(index);
			}
		}
	}
	void decreaseKey(int x, int k){
		int i = isPresent(x);
		array[i].second = k;
		while (i > 1 && array[i / 2].second > k){
			swap(array[i].first, array[i / 2].first);
			swap(array[i].second, array[i / 2].second);

			i = i / 2;
		}
	}
	void print(){
		for (int i = 1; i <= size; i++)
			cout << array[i].first << " ";
		cout << endl;
	}
	~MinHeap() { delete[] array; }
};

class Graph {
	int V;
	int no_of_vertex;
	int no_of_edges;
	vector<pair<int, int>>* adj;
	string* info;
public:
	Graph(int size=10) {
		V = size;
		adj = new vector<pair<int, int>>[V];
		info = new string[V];
		for (int i = 0; i < size; i++)
			info[i] = "\0";
		no_of_vertex = V - 1;
	}
	void setV(int size) {
		delete[] adj;
		delete[] info;
		V = size;
		adj = new vector<pair<int, int>>[V];
		info = new string[V];
		for (int i = 0; i < size; i++)
			info[i] = "\0";
		no_of_vertex = V - 1;
	}
	void insert(int a, int b, int weight) {
		if (a <= 0 || a >= V || b <= 0 || b >= V) {
			cout << "Out of Bound\n";
			return;
		}
		if (info[a] == "\0" || info[b] == "\0") {
			cout << "Vertex does not exist\n";
			return;
		}
		adj[a].push_back(make_pair(b, weight));
		adj[b].push_back(make_pair(a, weight));
		no_of_edges+=2;
	}
	void insertnames(int i, string data) {
		info[i] = data;
	}
	void grow() {
		cout << "Growing!\n";
		vector<pair<int, int>>* tempadj = new vector<pair<int, int>>[V*2];
		string* tempinfo = new string[V*2];
		for (int i = 0; i < V; i++) {
			if (info[i] != "\0") {
				tempadj[i] = adj[i];
				tempinfo[i] = info[i];
			}
		}
		for(int i=V;i<V*2;i++)
			tempinfo[i] = "\0";
		delete[] adj;
		delete[] info;
		adj = tempadj;
		info = tempinfo;
		V = V * 2;
		
	}
	void insertvertex() {
		if (info[V-1]!="\0")
			grow();
		string name;
		cout << "Enter name for the vertex: ";
		cin >> name;
		insertnames(++no_of_vertex, name);

	}
	Graph MST() {
		Graph g(V);
		MinHeap heap;
		int* parent = new int[V];
		for (int i = 0; i < V; i++) {
			heap.insert(i, INT_MAX);
			parent[i] = -1;
		}
		for (int i = 0; i < V; i++)
			g.insertnames(i, info[i]);
		int x = rand() % V;
		if (x == 0)
			x++;
		cout << "random value: " << x << endl;
		heap.decreaseKey(x, 0);

		while (!heap.isEmpty()) {
			int x;
			int u = heap.ExtractMin(&x);
			if (parent[u] != -1) 
				g.insert(u, parent[u], x);

			for (vector<pair<int, int>>::iterator itr = adj[u].begin(); itr != adj[u].end(); itr++) {
				pair<int, int> v = (*itr);
				if (heap.isPresent(v.first) && v.second < heap.getKey(v.first)) {
					parent[v.first] = u;
					heap.decreaseKey(v.first, v.second);
				}
			}
		}
		return g;
	}
	void printnames(){
		cout << "The edges are : " << endl;
		for (int i = 0; i < V; i++){
			if(info[i] != "\0")
				cout << info[i] << " : ";
			for (vector< pair<int, int> > ::iterator itr = adj[i].begin(); itr != adj[i].end(); itr++)
				cout << " \t (" << info[(*itr).first] << " , " << (*itr).second << ") \t ";
			if (info[i] != "\0")
				cout << endl;
			
		}
	}
	void print() {
		cout << "The edges are : " << endl;
		for (int i = 0; i < V; i++) {
			if (info[i] != "\0")
				cout << i << " : ";
			for (vector< pair<int, int> > ::iterator itr = adj[i].begin(); itr != adj[i].end(); itr++)
				cout << "(" << (*itr).first << " , " << (*itr).second << ") \t ";
			if (info[i] != "\0")
				cout << endl;

		}
	}
	void writeonfile(string filename) {
		fstream file(filename);
		if (file.is_open()) {
			file << no_of_vertex << "\n";
			for (int i = 1; i <= no_of_vertex; i++)
				if (info[i] != "\0")
					file << i << "," << info[i] << "\n";
			file << no_of_edges << "\n";
			for (int i = 0; i < V; i++) 
				for (vector< pair<int, int> > ::iterator itr = adj[i].begin(); itr != adj[i].end(); itr++) 
						file << i <<"," << (*itr).first << " " << (*itr).second << "\n";


		}
		else
			cout << "file can't be opened\n";
		file.close();

	}

};
Graph getfromfile(string filename) {
	fstream file(filename);
	Graph g1;
	if (file.is_open()) {
		int size;
		string info;
		int x;
		file >> size;
		g1.setV(size + 1);
		while (size) {
			getline(file, info, ',');
			x = stoi(info);
			getline(file, info, ' ');
			getline(file, info, '\n');
			g1.insertnames(x, info);
			size--;
		}

		file >> size;
		int a;
		int b;
		int weight;
		while (size) {
			getline(file, info, ',');
			a = stoi(info);
			file >> b;
			file >> weight;
			g1.insert(a, b, weight);
			size--;
		}
		file.close();
		return g1.MST();
	}
	else
		cout << "file can't be opened\n";
	file.close();
	return g1;
	
}

int main() {
	srand(time(0));
	int choice = -1;
	Graph g1,g2;
	string name;
	int a, b, weight;
	while (choice){
		cout << "=========================================\n";
		cout << "1.Input a graph from a file\n";
		cout << "2.Save a graph in a file\n";
		cout << "3.Add a vertex in a existing graph G\n";
		cout << "4.Add an edge in Existing graph G\n";
		cout << "5.Print the set of edges\n";
		cout << "6.Print the set of edges(names)\n";
		cout << "0.Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cout << "=========================================\n";
		switch (choice){
		case 0:
			break;
		case 1:
			cout << "Enter file name: ";
			cin >> name;
			g1 = getfromfile(name);
			break;
		case 2:
			cout << "Enter file name: ";
			cin >> name;
			g1.writeonfile(name);
			cout << "Check the output file: \n";
			break;
		case 3:
			g1.insertvertex();
			break;
		case 4:
			cout << "Enter starting vertex\n";
			cin >> a;
			cout << "Enter ending vertex\n";
			cin >> b;
			cout << "Enter weight\n";
			cin >> weight;

			g1.insert(a, b, weight);
			break;
		case 5:
			g2 = g1.MST();
			g2.print();
			break;
		case 6:
			g2 = g1.MST();
			g2.printnames();
			break;
		default:
			break;
		}
	}
	return 0;
}