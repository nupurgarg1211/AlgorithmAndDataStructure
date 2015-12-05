#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int hash[26],flag=0;
		for(int i=0;i<26;i++)
		{
			hash[i]=0;
		}
		string a,b;
		cin>>a>>b;
		for(int j=0;j<a.length();j++)
		{
			if(hash[a[j]-'a']==0)
			{
				hash[a[j]-'a']=1;
				//cout<<hash[a[j]-'a']<<endl;
			}
		}
		for(int j=0;j<b.length();j++)
		{
			if(hash[b[j]-'a']!=0)
			{
				cout<<"YES"<<endl;
				flag=1;
				break;
			}	
		
		}
		if(flag==0)
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
