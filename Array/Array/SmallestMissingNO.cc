//array is sorted n element range fron 0 to m-1 n m>n;

#include<iostream>
using namespace std;
int findSmallestMissingNo(int a[],int size)
{
	if(a[0]!=0)
	{
		return 0;
	}
	int start=0,end=size-1,mid;
	while(start<=end)
	{
		mid=(start+end)/2;
		//cout<<mid<<endl;
		if(a[start]!=start)
		{
			return start;
		}
		//cout<<a[mid]<<" "<<mid<<endl;
		if(a[mid]>mid)
		{
			end=mid-1;
			//cout<<"here";
		
		}
		if(a[mid]<=mid)
		{
			start=mid+1;
		
		}
		
	}
	return end+1;
}
int main()
{
	int a[]={0, 1, 2, 6, 9};
	int size=sizeof(a)/sizeof(a[0]);
	//cout<<size<<endl;
	int smallestMissing=findSmallestMissingNo(a,size);
	cout<<smallestMissing<<endl;
	return 0;
}
