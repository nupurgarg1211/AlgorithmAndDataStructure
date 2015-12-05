#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int a[]={4,5,7,8,9,10};
	int size=sizeof(a)/sizeof(a[0]);
	int start=0,end=size-1,mid,k;
	cin>>k;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(a[mid]==k)
		{
			cout<<" yes"<<endl;
			exit(0);
				
		}
		else if(a[mid]<k)
		{
			start=mid+1;
		}
		else
			end=mid-1;
	}
	cout<<"NO"<<endl;
	return 0;
}
