#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long int n,q,key;
	cin>>n>>q;
	long long int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	
	}
	sort(a,a+n);
	while(q--)
	{
		cin>>key;
		int start=0,end=n-1,mid;
		bool flag=0;
		while(start<=end)
		{
			mid=(start+end)/2;
			if(a[mid]==key)
			{
				cout<<"YES"<<endl;
				flag=1;
				break;
			
			}
			else if(a[mid]<key)
			{
				start=mid+1;
			
			}
			else
			{
				end=mid-1;
			}
		}
		if(flag==0)
		cout<<"NO"<<endl;
	
	}
	return 0;
}

