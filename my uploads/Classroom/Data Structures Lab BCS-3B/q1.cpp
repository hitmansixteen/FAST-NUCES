#include<iostream>
#include<list>
using namespace std;

class graph{
	int v; //No of vertices
	list<int> *adj; //adjacency lists
	void dfs(int v, bool visited[]){
		visited[v] = true;
		cout << v << " ";

		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			dfs(*i, visited);

	}
	
public:
	graph(int n){ 
		v = n;
		adj = new list<int>[n]; 
		 

	}
	void takeinput(int n, int w){ adj[n].push_back(w); }
	void explorefunction(int start){
		bool *visited = new bool[v];
		for (int i = 0; i < v; i++)
			visited[i] = false;
		dfs(start, visited);

	}
};

int main(){
	graph g(4);
	g.takeinput(0, 1);
	g.takeinput(0, 2);
	g.takeinput(1, 2);
	g.takeinput(2, 0);
	g.takeinput(2, 3);
	g.takeinput(3, 3);

	cout << "Following is the Depth First Traversal\n";
	g.explorefunction(1); 


	system("pause");
	return 0;
}