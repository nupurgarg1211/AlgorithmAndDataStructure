#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
int main()
{
	string a="afabcbcde";
	int hash[26];
	//memset(hash,0,25);
	for(int i=0;i<26;i++)
	{
		hash[i]=0;
	}
	for(int i=0;i<a.length();i++)
	{
		hash[a[i]-'a']+=1;
		//cout<<i<<" "<<hash[i]<<endl;
	}
	for(int i=0;i<26;i++)
	{
		if(hash[i]>1)
		{
			char ans=i+'a';
			cout<<ans<<endl;
			//cout<<i<<endl;
		
		}
	
	}		
	return 0;	
}
