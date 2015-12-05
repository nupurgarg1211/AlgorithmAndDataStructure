#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph
{
	int v;
	vector<int> *adj;
	bool DetectCycleUtil(int v,bool visited[],bool recStack[]);
	void DFSUtil(int s,bool visited[]);
	public:
	Graph(int v);
	void AddEdge(int a,int b);
	bool DetectCycle(int s);
	void DFS(int s);
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
/*This detect cycle by remembering the node in recursion stack as this will help us to figure out whether this node is parent of the current node.So for each vertex that are not visited yet we call DetectCycleUtil() which check whether there is a cycle or not.If we don't get any cycle after checking for every node we return false as there is no cycle in the graph    */
bool Graph::DetectCycle(int s)
{
	bool visited[v];
	bool recStack[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
		recStack[i]=false;
		
	}	
	for(int i=0;i<v;i++)
	{
		if(!visited[i])
		{
			if(DetectCycleUtil(s,visited,recStack))
			{
				return true;
			}
		}
	
	}
	return false;
}
/* Below function detect cycle by traversing adjacency list of the vertex passed.During traversal it checks whether the traversed node is previously visited or not and whether this node is part of any  cycle by making recursive call on this vertex.If the current vertex has edge to the vertex in recStack[] than there is a back edge           */
bool Graph::DetectCycleUtil(int v,bool visited[],bool recStack[])
{
	vector <int> ::iterator it;
	visited[v]=true;
	recStack[v]=true;
	for(it=adj[v].begin();it!=adj[v].end();it++)
	{
		if(!visited[*it] && DetectCycleUtil(*it,visited,recStack))
		{
		
			return true;
		}
		else if(recStack[*it])
		{
		
			return true;
		}
	
	}
	recStack[v]=false;
	return false;

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
void Graph:: DFSUtil(int s,bool visited[])
{
	cout<<s<<" ";
	visited[s]=true;
	vector<int> ::iterator it;
	for(it=adj[s].begin();it!=adj[s].end();it++)
	{
		if(!visited[*it])
		{
			//visited[*it]=true;
			DFSUtil(*it,visited);
		
		}	
	}
}
void Graph::BFS(int s)
{
	bool visited[v];
	queue<int> q;
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	q.push(s);
	visited[s]=true;
	//cout<<s<<" ";
	vector <int> ::iterator it;
	while(!q.empty())
	{
	
		int temp=q.front();
		q.pop();
		cout<<temp<<" ";
		for(it=adj[temp].begin();it!=adj[temp].end();it++)
		{
			if(!visited[*it])
			{
				//cout<<*it<<" ";
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
	g.AddEdge(0,3);
	g.AddEdge(1,3);
	//g.AddEdge(2,0);//for cycle
	cout<<"Whether there is a cycle or not?\n ans="<<g.DetectCycle(0);
	cout<<"\nDFS of a graph:"<<endl;
	g.DFS(0);
	cout<<"\nBFS of a graph:"<<endl;
	g.BFS(0);
	return 0;
}
