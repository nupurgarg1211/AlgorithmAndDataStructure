#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int a[]={2,3,4,1,7,8};
	int n=sizeof(a)/sizeof(a[0]),min=INT_MAX,maxdiff=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(min>a[i])
		{
			min=a[i];
		}
		if(maxdiff<a[i]-min)
		{
			maxdiff=a[i]-min;
		}
		
	
	}
	cout<<maxdiff<<endl;
	return 0;
}
