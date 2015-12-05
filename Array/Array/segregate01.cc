#include<iostream>
using namespace std;
void swap(int a[],int l,int r)
{
	int temp=a[l];
	a[l]=a[r];
	a[r]=temp;
}
void segregate(int a[],int size)
{
	int l=0,r=size-1;
	while(l<r)
	{
		while(a[l]==0)
		{
			l++;
		}
		while(a[r]==1)
		{
			r--;
		}
		if(l > r)
			break;
		swap(a,l,r);
		for(int i = 0; i < size; i++)
			cout << a[i] << "  ";
		cout << "\n";
		l++;
		r--;
		cout << l << "   " << r << endl;
	}
}
void print(int a[],int size)
{
	for(int i=0;i<size;i++)
	{
	
		//cout<<a[i]<<" ";
	}
}
int main()
{
	int a[]={0,1,1,0,0,0,1,1,1,0};
	int size =sizeof(a)/sizeof(a[0]);
	segregate(a,size);
	print(a,size);
	return 0;
}
