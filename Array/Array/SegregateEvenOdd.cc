#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
int main()
{
	int a[]={12, 34, 45, 9, 8, 90, 3};
	int size=sizeof(a)/sizeof(a[0]);
	int l=0,r=size-1;
	while(l<=r)
	{
		while(a[l]%2==0)
		{
			l++;
			
		}
		while(a[r]%2!=0)
		{
			r--;
		
		}
		if(l>r)
		break;
		swap(a[l],a[r]);
		
	
	}
	for(int i=0;i<size;i++)
	{
	
		cout<<a[i]<<" ";
	}
	return 0;
}
