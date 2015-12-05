//implement it again

#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int a[]={4,5,2,3,9,25,1};
	int size=sizeof(a)/sizeof(a[0]);
	int next=-1,max;
	
	if(size==0)
	exit(0);	
	cout<<a[size-1]<<" "<<"-1"<<endl;
	
	for(int i=size-2;i>=0;i--)
	{
		if(a[i+1]>a[i])
		{
			next=a[i+1];
			cout<<a[i]<<" "<<next<<endl;
		}
		else
		{
			cout<<a[i]<<" "<<next<<endl;
		}
	
	}
	return 0;
}
