//This program checks for array that has consecutive no.s
#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;
int getMax(int a[],int n)
{
	int max=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
		
	}
	return max;

}
int getMin(int a[],int n)
{
	int min=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(min>a[i])
		{
			min=a[i];
		}
		
	}
	return min;

}

int main()
{
	int a[]={3,1,4,3,0};
	int size=sizeof(a)/sizeof(a[0]);
	int min,max;
	min=getMin(a,size);
	max=getMax(a,size);
	if((max-min+1)==size)
	{
		for(int i=0;i<size;i++)
		{
		
			if(a[abs(a[i])-min]>0)
			{
				a[abs(a[i])-min]=-a[abs(a[i])-min];
				//cout<<a[abs(a[i])-min]<<endl;
			}
			else
			{
				
				/*cout<<a[i]<<endl;
				cout<<"else:"<<a[abs(a[i]-min)]<<endl;*/
				cout<<"not consecutive"<<endl;
				exit(0);
			}	
		
		}
		cout<<"Consecutive";
		exit(0);
	
	
	
	}
	cout<<"not consecutive"<<endl;
	return 0;
}
