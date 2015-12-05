#include<iostream>
using namespace std;
int main()
{
	int a[]={1,2,3,4,5,6};
	int n=sizeof(a)/sizeof(a[0]);
	int k,last=n,i=0;
	cin>>k;
	int mid=last/2;
	while(i>=0 && i<n && last<=n && last>=0)
	{
		if(k==a[mid])
		{
			cout<<" yes";
			break;
		}
		else if(a[mid]<k)
		{
			
			i=mid+1;
		}
		else
		{
			
			last=mid-1;
		}
		mid = (i + last)/2;
	}
	cout<<"No"<<endl;
	return 0;	
}
