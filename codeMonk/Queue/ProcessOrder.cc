#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n,NoOfOp=0,a;
	queue<int> q1,q2;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		q1.push(a);
	
	}
	for(int i=0;i<n;i++)
	{
		cin>>a;
		q2.push(a);
	
	}	
	while(!q2.empty())
	{
		a=q2.front();
		q2.pop();
	
		while(a!=q1.front())
		{
			int a=q1.front();
			q1.pop();
			q1.push(a);
			NoOfOp++;
	
		}
		
		q1.pop();
		//q2.pop();
		
	}
	NoOfOp+=n;
	cout<<NoOfOp<<endl;
	
	
	return 0;
}
