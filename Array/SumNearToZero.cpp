#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<climits>
using namespace std;
int main()
{
	int a[]={1,60,-10,2,70,-80,85};
	int size=sizeof(a)/sizeof(a[0]);
	sort(a,a+size);
	int l=0,r=size-1,sum=0,minSum=INT_MAX,loc1,loc2;
	while(l<r)
	{
		sum=a[l]+a[r];
		if(abs(sum)<abs(minSum))
		{
			minSum=sum;
			loc1=l;
			loc2=r;
			//cout<<"here"<<endl;
		
		}
		if(sum==0)
		{
			cout<<a[l]<<" "<<a[r]<<endl; 
			exit(0);
		}
		if(sum>0)
		{
			r--;
		
		}
		else
		l++;
		
	
	}
	cout<<a[loc1]<<" "<<a[loc2]<<endl;	
	return 0;
}
