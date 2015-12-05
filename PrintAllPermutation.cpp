#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
void swap(int &a,int &b)
{
	char temp=a;
	a=b;
	b=temp;
	
}
void permute(string a,int l,int r)
{
	if(l==r)
	{
		cout<<a<<endl;
	}
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(a[i],a[l]);
			permute(a,l+1,r);
			swap(a[i],a[l]);
			
		}
	}

}
int main()
{
	string a="ABC";
	int size=a.length();
	permute(a,0,size-1);		
	return 0;	
}
