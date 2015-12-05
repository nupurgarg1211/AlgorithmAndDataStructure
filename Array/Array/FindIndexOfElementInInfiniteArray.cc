#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int a[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
	int key=11,mid;
	int slow=0,fast=1;
	
	while(key>a[fast] )
	{
		slow=fast;
		fast=2*fast;
		
	}
	//cout<<slow<<" "<<fast<<endl;	
	while(slow<=fast)
	{
		mid=(slow+fast)/2;
		if(a[mid]==key)
		{
			cout<<mid<<endl;
			exit(0);
		}
		else if(a[mid]<key)
		{
			slow=mid+1;
		}
		else
		fast=mid-1;
	
	
	}
	cout<<" Not present"<<endl;
	return 0;
}
