#include<iostream>
#include<algorithm>
using namespace std;
int ceil(int a[],int size,int k,int &floor)
{
	int start=0,end=size-1;
	int mid,ceil=-1;
	while(start<=end)
	{
		mid=(start+end)/2;
		
		if(a[mid]==k)
		{
			ceil=k;
			return k;
		
		}
		else if(a[mid]<k)
		{
			start=mid+1;
			floor=a[mid];
			
			
		}
		else
		{
			ceil=a[mid];
			end=mid-1;
			
		
		}
	
	}
	return ceil;

}
int main()
{
	int a[]={4,2,6,7,3,9};
	int size=sizeof(a)/sizeof(a[0]);
	sort(a,a+size);
	int floor=-1;
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<endl;
	}
	int k;
	cin>>k;
	cout<<"ceil="<<ceil(a,size,k,floor)<<endl;
	cout<<"floor="<<floor<<endl;
	
}
