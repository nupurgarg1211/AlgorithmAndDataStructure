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
	int a[]={0,1,0,1,0,0,1,1,1,0};
	int size=sizeof(a)/sizeof(a[0]);
	int l=0,r=size-1;
	//boll flag1=0,flag2=0;
	while(l<r )
	{
		while(a[l]!=1)
		{
			l++;
			//flag1=1;
		
		}
		while(a[r]!=0)
		{
			r--;
			//flag2=0;
		
		}
		
		swap(a[l],a[r]);
		l++;
		r--;
	}
	for(int i=0;i<size-1;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}
