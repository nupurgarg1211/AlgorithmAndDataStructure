#include<iostream>
using namespace std;
int main()
{
	int a[]= {4, 2, 4, 5, 2, 3, 1};
	int size=sizeof(a)/sizeof(a[0]);
	int xor1=a[0];
	for(int i=1;i<size;i++)
	{
		xor1=xor1^a[i];
	
	}
	
	for(int i=1;i<=size-2;i++)
	{
		xor1=xor1^i;
	}
	int side_bit=xor1 & ~(xor1-1);
	int x=0,y=0;
	for(int i=0;i<size;i++)
	{
		if(a[i] & side_bit)
		{
			x=x^a[i];
		}
		else
		{
			y=y^a[i];
		}
	
	}
	
	for(int i=1;i<=size-2;i++)
	{
		if(i & side_bit)
		{
			x=x^i;
		}
		else
		{
			y=y^i;
		}
	
	}
	cout<<"x="<<x<<"y="<<y<<endl;
	return 0;
}
