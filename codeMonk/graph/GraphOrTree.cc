#include<iostream>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int degree[N],sum=0;
	for(int i=0;i<N;i++)
	{
		cin>>degree[N];
		sum+=degree[N];
	}
	sum=sum/2;
	int NoOfEdges=N-1;
	if(sum==NoOfEdges)
	{
		cout<<"YES"<<endl;
	}
	else
	cout<<"NO"<<endl;

	return 0;
}
