#include<iostream>
using namespace std;

int FirstOccurrence(int a[],int n,int x)
{
	int mid,l=0,r=n-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		//cout<<"mid="<<mid<<endl;
		if(mid==0||a[mid]==x && a[mid-1]<x)
		{
			//s=mid;
			//cout<<"first="<<mid<<endl;
			return mid;
			
		}
		if(a[mid]>=x)
		{
		
			r=mid-1;
		
		}
		if(a[mid]<x)
		{
			l=mid+1;
		
		}
		//cout<<"in while"<<endl;
	}
	return -1;
	

}
int SecondOccurrence(int a[],int n,int x,int index1)
{
	int mid,l=index1,r=n-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		//cout<<"mid="<<mid<<endl;
		if(mid==n-1||a[mid]==x && a[mid+1]>x)
		{
			
			//cout<<"2nd ="<<mid<<endl;
			return mid;
			
		}
		if(a[mid]>x)
		{
		
			r=mid-1;
		
		}
		if(a[mid]<=x)
		{
			l=mid+1;
		
		}
	
	}
	

}
int count(int a[],int n,int x)
{
	int index1,index2;
	index1=FirstOccurrence(a,n,x);
	//cout<<index1<<endl;
	if(index1==-1)
	{
		return index1;
	}
	else
	index2=SecondOccurrence(a,n,x,index1);
	return index2-index1+1;
}
int main()
{
	int a[]={1,1,2,2,2,2,4,4,4,7,8,8,8};
	int size=sizeof(a)/sizeof(a[0]);
	int ans,x;
	cin>>x;
	ans=count(a,size,x);
	cout<<ans<<endl;
	return 0;
}
