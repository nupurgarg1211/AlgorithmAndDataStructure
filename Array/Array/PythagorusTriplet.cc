#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int a[]={10, 4, 6, 12, 5};
	int n=sizeof(a)/sizeof(a[0]);
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		a[i]=a[i]*a[i];
	}
	for(int i=n-1;i>=0;i--)
	{
		int l=0,r=i-1;
		while(l<r)
		{
			if(a[l]+a[r]<a[i])
			{
				l++;
			}
			else if(a[l]+a[r]>a[i])
			{
				r--;
			}
			else
			{
				cout<<sqrt(a[l])<<" "<<sqrt(a[r])<<" "<<sqrt(a[i])<<endl;
				cout<<"YES"<<endl;
				exit(0);
			}
		}
	
	}
	cout<<"NO"<<endl;
	return 0;
}
