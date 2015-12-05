#include<iostream>
using namespace std;
int FindEquilibriumPoint(int a[],int size)
{
	int leftsum=0,sum=0;
	for(int i=0;i<size;i++)
	{
		sum+=a[i];
	
	}
	for(int i=0;i<size;i++)
	{
		sum-=a[i];
		if(sum==leftsum)
		{
			return i;
			//cout<<"Equilibrium point is:"<<i<<endl;
		}
		leftsum+=a[i];
	}
	return -1;
}
int main()
{
	int a[]={-7, 1, 5, 2, -4, 3, 0};
	int size=sizeof(a)/sizeof(a[0]);
	
	int index=FindEquilibriumPoint(a,size);
	if(index!=-1)
	{
		cout<<index<<endl;
	}
	return 0;
}
