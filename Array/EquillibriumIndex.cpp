#include<iostream>
using namespace std;
int main()
{
	int a[]={-7,1,5,2,-4,3,0},sum=0,left=0;
	int size=sizeof(a)/sizeof(a[0]);
	bool flag=0;
	for(int i=0;i<size;i++)
	{
		sum=sum+a[i];
	}
	for(int j=0;j<size;j++)
	{
		sum=sum-a[j];//right sum
		if(sum==left)
		{
			cout<<j<<endl;
			flag=1;
		
		}
		left=left+a[j];//left sum for next element
	
	
	}
	if(!flag)
	cout<< "-1"<<endl;


}
