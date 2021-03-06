#include<iostream>
#include<list>
using namespace std;
class Graph
{
	int v;
	list<int> *adj;
	public:
	Graph(int v);
	void AddEdge(int a,int b);
	void BFS(int s);

};
 Graph::Graph(int v)
 {
 	this->v=v;
 	adj=new list<int>[v];
 }
void  Graph::AddEdge(int a,int b)
{
	adj[a].push_back(b);	

}
void  Graph::BFS(int s)
{
	bool *visited=new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	
	}
	list<int> queue;
	visited[s]=true;
	queue.push_back(s);
	list<int>:: iterator i;
	while(!queue.empty())
	{
		s=queue.front();
		cout<<s<<" ";
		queue.pop_front();
		for(i=adj[s].begin();i!=adj[s].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				queue.push_back(*i);
			}
		}
	
	}
	
}
int main()
{
	
	Graph g(7);
	g.AddEdge(1,2);
	g.AddEdge(2,3);
	g.AddEdge(3,4);
	g.AddEdge(4,5);
	g.AddEdge(5,6);
	g.AddEdge(1,3);
	g.AddEdge(1,4);
	g.AddEdge(2,3);
	g.AddEdge(2,5);
	g.AddEdge(3,6);
	g.BFS(3);
	return 0;
	

}

