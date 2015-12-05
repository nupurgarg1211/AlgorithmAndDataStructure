#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[]={5,7,2,1,4,3};
	int k;
	sort(a,a+6);
	cin>>k;
	int sum=0;
	
	int size=sizeof(a)/sizeof(a[0]);
	for(int i=0;i<size;i++)
	{
		int l=i+1;
		int r=size-1;
		sum=a[i];		
		while(l<r)
		{
			sum=sum+a[l]+a[r];
			if(sum==k)
			{
				cout<<a[l]<<" "<<a[r]<<" "<<a[i]<<endl;
				exit (0);
			
			}
			if(sum>k)
			{
				sum=sum-a[r]-a[l];
				r=r-1;
				
			}
			if(sum<k)
			{
				sum=sum-a[r]-a[l];
				l=l+1;
				
			}
		
		
		}
	}
	
	
	return 0;
}
