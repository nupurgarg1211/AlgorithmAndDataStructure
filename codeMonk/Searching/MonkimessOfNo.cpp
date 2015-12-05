#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int t,n,max=INT_MIN,p1,p2,currentMax;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		long long int a[n],b[n];
		p1=0;
		p2=0;
		currentMax=0;
		max=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		
		}
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
		
		}
		while(p1!=n && p2!=n)
		{
			if(a[p1]<=b[p2])
			{
				currentMax=p2-p1;
				p2++;
			
			}
			else
			{
				p1++;
			
			}
			if(max<currentMax)
			{
			
				max=currentMax;
			}
			
		}
		cout<<max<<endl;
	}
	return 0;

}
