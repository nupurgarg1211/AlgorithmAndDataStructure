#include<iostream>
#include<cstring>
using namespace std;
void checkPalindromePossible(string a,int size)
{
	int ans=0,hash[26];
	//memset(hash,0,26);
	for(int i=0;i<26;i++)
	{
		hash[i]=0;
	}
	for(int i=0;i<size;i++)
	{
		hash[a[i]-'a']=hash[a[i]-'a']+1;
	}
	for(int j=0;j<26;j++)
	{
		if(hash[j]!=0 && hash[j]%2!=0)
		{
			ans=ans+(hash[j]%2);
			//cout<<hash[j]<<" ";
		}	
	}
	if(ans>1)
		cout<<"NO";
	else
		cout<<"YES";	

}
int main()
{
	string a;
	cin>>a;
	checkPalindromePossible(a,a.length());
	return 0;
}
