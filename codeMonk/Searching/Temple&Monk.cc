#include<iostream>
#include<algorithm>
using namespace std;
int *a;
bool check(int mid,int k)
{
	int prev=mid+a[0];
	k--;
	for(int i=1;i<a.length();i++)
	{
	
	
	}
	return 1;
	
}
int main()
{
	long long int n,k,h=10000000,l=0,mid;
	cin>>n>>k;
	a=new int[n];
	for(int i=0;i<n;i++)
	{
	
		cin>>a[i];
	}
	sort(a,a+n);
	while(l<h)
	{
		mid=(l+h)/2;
		bool res=check(mid,k);
	
	}
	return 0;
}
