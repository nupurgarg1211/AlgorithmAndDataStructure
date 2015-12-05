#include<iostream>
using namespace std;
int main()
{
	int t,N;
	string a,q="";
	cin>>t;
	while(t--)
	{
		int hash[26];
		q="";
		for(int i=0;i<26;i++)
		{
			hash[i]=0;
		}
		cin>>N;
		cin>>a;
		for(int i=0;i<N;i++)
		{
			int x=a[i]+hash[a[i]-'a'];
			if(x>'z')
			{
				x=x-26;
			}
			q+=x;
			hash[a[i]-'a']+=1;
			cout<<"a[i]="<<a[i]<<endl;
		}	
		cout<<q<<endl;
	
	}
	
	return 0;
}
