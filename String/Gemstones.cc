#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,hash[26],count=0;
	cin>>n;
	string rocks[n];
	for(int i=0;i<26;i++)
	{
		hash[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>rocks[i];
	
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<rocks[i].length();j++)
		{
			if(hash[rocks[i][j]-'a']==i)
			{
				hash[rocks[i][j]-'a']=hash[rocks[i][j]-'a']+1;
				
			}
		
		}
	
	}
	for(int i=0;i<26;i++)
	{
		if(hash[i]==n)
		{
			//cout<<hash[i]<<endl;
			count++;
		}	
	}
	cout<<count<<endl;
	return 0;
}
