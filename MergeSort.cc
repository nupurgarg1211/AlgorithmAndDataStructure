#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;

}
void Merge(int a[],int start1,int start2 ,int r)
{
	while(start1<=start2-1 && start2<=r)
	{
		if(a[start1]>a[start2])
		{
			swap(a[start1],a[start2]);
		
		}
		start1++;
		
	
	}
	
}
void MergeSort(int a[],int l,int r)
{
	if(l>=r)
	{
		return;
	}
	int mid=(l+r)/2;
	MergeSort(a,0,mid);
	MergeSort(a,mid+1,r);
	Merge(a,l,mid+1,r);

}
void printArray(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
int main()
{
	int a[]={4,5,9,2,3};
	int n=sizeof(a)/sizeof(a[0]);
	MergeSort(a,0,n-1);
	printArray(a,n);
	return 0;
}

