#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int a[]={16,17,4,3,5,2};
	int size=sizeof(a)/sizeof(a[0]);
	int max=INT_MIN;
	for(int i=size-1;i>=0;i--)
	{
		if(max<a[i])
		{
			max=a[i];
			cout<<a[i]<<" ";
		
		}
	
	}
	return 0;
}
