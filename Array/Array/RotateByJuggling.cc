#include<iostream>
using namespace std;
void IReverse(int a[],int n)
{
	int l=0,r=n-1;
	while(l<r)
	{
		swap(a[l],a[r]);
		l++;
		r--;
	
	}

}

void print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
	
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int gcd(int n,int k)
{
	if(k==0)
	{
		return n;
	}
	else 
	return gcd(k,n%k);

}
void rotate(int a[],int n,int k)
{
	int g=gcd(n,k);
	cout<<g<<endl;

}
int main()
{
	int a[]={1,2,3,4,5,6,7};
	int n=sizeof(a)/sizeof(a[0]);
	int k;
	cin>>k;
	rotate(a,n,k);
	print(a,n);
	return 0;
}
