#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int t;
	cin>>t;
	string a;
	
	while(t--)
	{
		cin>>a;
		int hash[26],count=0;
		for(int i=0;i<26;i++)
		{
			hash[i]=0;
		}
		if((a.length()%2)!=0)
		{
			cout<<"-1"<<endl;
			continue;
		}
		for(int i=0;i<a.length()/2;i++)
		{
			hash[a[i]-'a']+=1;
		
		}
		for(int i=(a.length()/2);i<a.length();i++)
		{
			if(hash[a[i]-'a']>0)
			{
				hash[a[i]-'a']-=1;
			}
			
		}
		for(int i=0;i<26;i++)
		{
			if(hash[i]!=0)
			{
				count+=hash[i];
			}
			
		}
		cout<<count<<endl;
	}
	return 0;
}
