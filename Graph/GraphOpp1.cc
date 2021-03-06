#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph
{
	int v;
	vector<int> *adj;
	public:
	Graph(int v);
	void AddEdge(int a,int b);
	void DFS(int s);
	void DFSUtil(int s,bool visited[]);
	void BFS(int s);
};
Graph::Graph(int v)
{
	this->v=v;
	adj=new vector<int>[v];

}
void Graph::AddEdge(int a,int b)
{
	adj[a].push_back(b);

}
void Graph::DFS(int s)
{
	bool visited[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	DFSUtil(s,visited);

}
void Graph::DFSUtil(int s,bool visited[])
{
	
	vector<int> ::iterator it;
	visited[s]=true;
	cout<<s<<" ";
	for(it=adj[s].begin();it!=adj[s].end();it++)
	{
		if(!visited[*it])
		{
			DFSUtil(*it,visited);
		}	
	
	}

}
void Graph::BFS(int s)
{
	bool visited[v];
	queue<int> q;
	vector <int> ::iterator it;
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	q.push(s);
	visited[s]=true;
	while(!q.empty())
	{
		int temp=q.front();
		cout<<temp<<" ";
		q.pop();
		
		for(it=adj[temp].begin();it!=adj[temp].end();it++)
		{
			if(!visited[*it])
			{
				q.push(*it);
				visited[*it]=true;
			}	
				
		}
	
	}
	
}
int main()
{
	Graph g(4);
	g.AddEdge(0,1);
	g.AddEdge(1,2);
	g.AddEdge(2,3);
	g.AddEdge(3,1);
	g.AddEdge(0,3);
	cout<<"DFS :\n";
	g.DFS(0);
	cout<<"BFS:\n";
	g.BFS(0);
}
