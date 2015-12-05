/*  
In an unsorted array find 2 no. of odd occurence

Input: {12, 23, 34, 12, 12, 23, 12, 45}
Output: 34 and 45
*/
#include<iostream>
using namespace std;
int main()
{
	int a[]={12, 23, 34, 12, 12, 23, 12, 45};
	int n=sizeof(a)/sizeof(a[0]);
	int xor1=a[0],setBit,x=0,y=0;
	
	for(int i=1;i<n;i++)
	{
		xor1=xor1^a[i];
		
	}
	setBit=xor1 & ~(xor1-1);
	for(int i=0;i<n;i++)
	{
		if(setBit & a[i])
		{
			x=x^a[i];
		}
		else
		y=y^a[i];
	}
	cout<<"Two odd occurence no. are-"<<x<<" "<<y<<endl;
	return 0;
}
