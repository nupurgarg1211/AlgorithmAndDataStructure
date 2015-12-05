#include<iostream>
using namespace std;
void segregate(int a[],int size)
{
	int low=0,mid=0,high=size-1;
	while(mid<=high)
	{
		if(a[mid]==0)
		{
			swap(a[mid],a[low]);
			mid++;
			low++;
		}
		else if(a[mid]==1)
		{
			mid++;
		
		}
		else if(a[mid]==2)
		{
		
			swap(a[mid],a[high]);
			high--;
		}
	
	}
}
void printArray(int a[],int size)
{
	for(int i=0;i<size;i++)
	{
	
		cout<<a[i]<<" ";
	}
}
int main()
{
	int a[]={0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
	int size=sizeof(a)/sizeof(a[0]);
	segregate(a,size);
	printArray(a,size);
	return 0;
}
