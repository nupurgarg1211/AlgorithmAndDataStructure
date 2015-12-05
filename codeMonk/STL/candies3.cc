#include<iostream>
#include<set>
#include<vector>
#include<cassert>
using namespace std;
int main()
{
	int t,n,m;
	long long int a;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		assert(1<=n && n<=100000);
    		assert(1<=m && m<=100000);
		set<long long int> s;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			assert(0<= a && a<= 1000000000000);
			s.insert(a);
		}
		for(int i=0;i<m;i++)
		{
			cin>>a;
			assert(0<= a && a<= 1000000000000);
			if(s.find(a)!=s.end())
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
			s.insert(a);
		}
	
	
	
	}

	return 0;
}
