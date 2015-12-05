#include<iostream>
#include<climits>
#include<stack>
#include<vector>
using namespace std;

class Graph
{
	int vertex;
	vector <int > *adj;
	public:
	Graph(int v)
	{
		vertex=v;
		adj=new vector<int>[v];
	}
	void AddEdge(int a,int b)
	{
		adj[a].push_back(b);
	
	}

};
int main()
{
	int a=3;
	Graph *g=new Graph(a);
	g->AddEdge(1,2);
	g->AddEdge(1,3);
	return 0;
}
