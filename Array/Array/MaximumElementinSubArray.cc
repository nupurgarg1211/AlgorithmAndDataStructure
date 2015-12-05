#include<iostream>
#include<climits>
#include<deque>
using namespace std;
int main()
{
	int a[]={1,2,3,1,4,5,2,3,6};
	int n=sizeof(a)/sizeof(a[0]);
	int max=INT_MIN;
	deque<int> q;
	int k=3,i;
	for(i=0;i<k;i++)
	{
		while(!q.empty() && a[i]>a[q.back()] )
		{
			q.pop_back();
		}
		q.push_back(i);
	
	}
	for(;i<n;i++)
	{
		cout<<a[q.front()]<<endl;
		while(!q.empty() && q.front()<=i-k)
		q.pop_front();
		
		while(!q.empty() && a[i]>a[q.back()])
		q.pop_back();
		
		q.push_back(i);
	
	
	}
	return 0;
}
