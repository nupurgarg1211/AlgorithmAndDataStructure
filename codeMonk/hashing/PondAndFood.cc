#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	long int t,n;
	long int a,b;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int hash[1000000],count=0;
		memset(hash,0,1000000);
		while(n--)
		{
			cin>>a>>b;
			
			
			hash[a]+=1;
			
			if(hash[b]!=0)
			{
			
				hash[b]-=1;
			}
			else
			{
			
				count++;
			
			}	
				
		
		}
		cout<<count<<endl;
	
		
	}
	return 0;
}
