#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int main()
{
	string a,b;
	cin>>a>>b;
	int hash1[26],hash2[26],count=0;
	for(int i=0;i<26;i++)
	{
		hash1[i]=0;
		hash2[i]=0;
	}
	
	for(int i=0;i<a.length();i++)
	{
		hash1[a[i]-'a']+=1;
		
	
	}
	for(int j=0;j<b.length();j++)
	{
		hash2[b[j]-'a']+=1;
	}
	for(int i=0;i<26;i++)
	{
		if(hash1[i]!=hash2[i])
		{
			count+=abs(hash1[i]-hash2[i]);
		
		}
	
	}
	cout<<count<<endl;
	return 0;
}
