#include<iostream>
using namespace std;
void FloorCeil(int a[],int &floor,int &ceil,int size,int l,int r,int k)
{
	int mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(a[mid]==k)
		{
		
			ceil=mid;
			floor=mid;
			return;
		
		}
		else if(a[mid]<k)
		{
			floor=a[mid];
			l=mid+1;
		
		}
		else
		{
			
			ceil=a[mid];
			r=mid-1;
			
		}
	
	
	}


}
int main()
{
	int a[]={1, 2, 8, 10, 10, 12, 19};
	int size=sizeof(a)/sizeof(a[0]);
	int floor=-1,ceil=-1,k;
	cin>>k;
	FloorCeil(a,floor,ceil,size,0,size-1,k);
	cout<<"floor="<<floor<<endl;
	cout<<"ceil="<<ceil<<endl;
	return 0;
}
