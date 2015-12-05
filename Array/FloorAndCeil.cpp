#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int a[]={1,4,6,7,9,12,16,19};
	int size=sizeof(a)/sizeof(a[0]);
	int start=0,end=size-1,mid,k,floor=-1,ceil=-1;
	cin>>k;
	while(start<=end)
	{
		mid=(start+end)/2;
		
		if(a[mid]==k)
		{
			floor=k;
			ceil=k;
			cout<<floor<<" "<<ceil<<endl;
			exit(0);
		}
		else if(a[mid]<k)
		{
			floor=a[mid];
			start=mid+1;
		}
		else
		{
			end=mid-1;
			ceil=a[mid];
		
		}
		
	}
	cout<<floor<<" "<<ceil<<endl;

}


