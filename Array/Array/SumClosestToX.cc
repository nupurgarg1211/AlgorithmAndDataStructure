#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;
int main()
{
	int a[]={10, 22, 28, 29, 30, 40};
	int n=sizeof(a)/sizeof(a[0]),l=0,r=n-1,k,mindiff=INT_MAX,diff,first,second;
	cin>>k;
	while(l<r)
	{
		diff=abs(k-(a[l]+a[r]));
		if(mindiff>diff)
		{
			first=a[l];
			second=a[r];
			mindiff=diff;
			cout<<mindiff<<endl;
		}
		if(a[l]+a[r]<k)
		{
			l++;
		}
		else
		{
			r--;
		}
		
	}
	cout<<first<<" "<<second<<endl;
	return 0;
}
