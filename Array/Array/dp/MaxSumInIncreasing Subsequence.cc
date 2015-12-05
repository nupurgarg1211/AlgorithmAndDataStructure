#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
int max1(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int a[]={1,101,2,3,100,4,5};
	int n=sizeof(a)/sizeof(a[0]);
	int sum[n],max;
	memset(sum,0,n);
	
	for(int i=0;i<n;i++)
	{
		sum[i]=a[i];
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j])
			{
				sum[i]=max1(sum[i],sum[j]+a[i]);
				cout<<sum[i]<<endl;
			}
		
		}
	
	}
	max=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(max<sum[i])
		{
			max=sum[i];
		}
	}
	cout<<"ans="<<max;
	return 0;
}
