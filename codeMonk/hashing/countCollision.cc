#include<iostream>
using namespace std;
int main()
{
	int t,n,a;
	cin>>t;
	while(t--)
	{
		int hash[10],count=0;
		for(int i=0;i<10;i++)
		{
			hash[i]=0;
		}
		cin>>n;
		while(n--)
		{
			cin>>a;
			if(hash[a%10]==0)
			{
				hash[a%10]=1;
			}
			else
			count++;
		
		
		}
		cout<<count<<endl;
	
	}
	return 0;
}
