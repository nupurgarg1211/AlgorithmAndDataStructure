#include<iostream>
#include<list>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int n,m,t;
	
	//list<long long int> l;
	cin>>t;
	while(t--)
	{
		long long int a,arr[100000];
		memset(arr, 0, 100000);
		/*for(int i=0;i<100000;i++)
		{
			arr[i]=-1;
		}*/
		cin>>n>>m;
		int i=0;
		while(n>0)
		{
		
			cin>>a;
			
			arr[a]=a;
			n--;
			
		}
		
		while(m>0)
		{
			cin>>a;
			if(arr[a]==a)
			{
				cout<<"YES"<<endl;
			}
			else
			cout<<"NO"<<endl;
			arr[a]=a;
			m--;	
		}
		
	}
	return 0;
}
