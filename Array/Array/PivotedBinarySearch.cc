#include<iostream>
using namespace std;
int findPivot(int a[],int l,int r)
{
	int mid;
	mid=(l+r)/2;
	if(a[mid]>a[mid+1])
	{
		return mid;
	
	}
	else if(a[mid]<a[mid-1])
	{
		return mid-1;
	}
	else if(a[l]<a[mid])
	{
		return findPivot(a,mid+1,r);
	}
	else
		return findPivot(a,l,mid-1);
}
int binarySearch(int a[],int l,int r,int n)
{
	int mid;
	
	while(l<r)
	{
		mid=(l+r)/2;
		if(a[mid]==n)
		{
			return mid;
		}
		else if(a[mid]<n)
		{
			l=mid+1;
		}
		else 
		{
		
			r=mid-1;
		}
	
	}
	return -1;
}	
int PivotedBinarySearch(int a[],int size,int n)
{
	int pivot=findPivot(a,0,size);
	int index=binarySearch(a,0,pivot,n);	
	if(index==-1)
	{
	index=binarySearch(a,pivot+1,size,n);
	}	
	return index; 
}
	
int main()
{
	int a[]={5,6,7,8,9,10,1,2,3};
	int size=sizeof(a)/sizeof(a[0]);
	int n;
	cin>>n;
	//int pivot=findPivot(a,0,size);
	//cout<<pivot;
	int index=PivotedBinarySearch(a,size,n);
	cout<<index;
	return 0;
}
