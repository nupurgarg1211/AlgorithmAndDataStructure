#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int a[]={10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	int size = sizeof(a)/sizeof(a[0]);
	int l=0,r=size-1,max=INT_MIN,min=INT_MAX,j=0;
	
	while(a[l]<a[l+1])
	{
		l++;
	
	}
	while(a[r]>a[r-1])
	{
		r--;
	}
	

	
	for(int i=l;i<=r;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
		if(min>a[i])
		{
			min=a[i];
			
		}
	}
	
	while(j<l)
	{
		if(min<a[j])
		{
			l=j;
				
		
		}
		j++;
	
	}
	j=size-1;
	while(j<l)
	{
		if(max>a[j])
		{
			r=j;
				
		
		}
		j--;
	
	}
	cout<<"start of subarray="<<l<<"end of sub array"<<r<<endl; 
	return 0;
}
