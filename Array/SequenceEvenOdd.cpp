#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
	cout<<a<<" swapped"<<b<<endl;
}
void printArray(int a[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<" "<<endl;
	}

}
int main()
{
	int a[]={1,3,5,7,2,4,8,6,3};
	int size=sizeof(a)/sizeof(a[0]);
	int l=0,r=size-1;
	while(l<r)
	{
		while(a[l]%2==0)
		{
			l++;	
		
		}
		while(a[r]%2!=0)
		{
			r--;	
		
		}
		cout<<l<<" "<<r<<" l and r"<<endl;
		swap(a[l],a[r]);
		l++;
		r--;
	}
	printArray(a,size);
	return 0;
}
