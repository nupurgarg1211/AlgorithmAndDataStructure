#include<iostream>
using namespace std;
void merge(int a[],int b[],int n1,int n2)
{
	int i=n2,j=0,k=0;
	while(k<n1)
	{
		if((i<n1 && a[i]<b[j])||j==n2)
		{
			a[k]=a[i];
			k++;
			i++;
		}
		else if(a[i]>b[j]||i==n1)
		{
			a[k]=b[j];
			k++;
			j++;
			
		
		}
	
	}
	
}
void print(int a[],int n1)
{
	for(int i=0;i<n1;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int a[]={2,-1,7,-1,-1,10,-1};
	int b[]={5,8,12,14};
	int n1=sizeof(a)/sizeof(a[0]);
	int n2=sizeof(b)/sizeof(b[0]);
	int i=n1-1;
	for(int j=n1-1;j>=0;j--)
	{
		if(a[j]!=-1)
		{
			a[i]=a[j];
			i--;
		
		}
	
	}
	merge(a,b,n1,n2);
	print(a,n1);
	return 0;
}
