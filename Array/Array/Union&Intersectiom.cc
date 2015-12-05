#include<iostream>
using namespace std;
bool ifPresent(int k,int a[],int l,int r)
{
	int mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(a[mid]==k)
		{
			return true;
		
		}
		else if(a[mid]<k)
		{
			l=mid+1;
		
		}
		else
		r=mid-1;
	}
	return false;
}
int main()
{
	int a[]={1,3,4,5,7};
	int b[]={2,3,5,6};
	int size1=sizeof(a)/sizeof(a[0]);
	int size2=sizeof(b)/sizeof(b[0]);
	if(size1<size2)
	{
		cout<<"Intersection"<<endl;
		for(int i=0;i<size1;i++)
		{
			if(ifPresent(a[i],b,0,size2-1))
			{
				cout<<a[i]<<" ";
			}
			
		
		}
		
	}
	else
	{
	
		cout<<"Intersection"<<endl;
		for(int i=0;i<size2;i++)
		{
			if(ifPresent(b[i],a,0,size1-1))
			{
				cout<<b[i]<<" ";
			}
			
		
		}
	
	
	}
	cout<<"Union"<<endl;
		int i,j;
		for(i=0,j=0;i<size1 && j<size2;)
		{
			if(a[i]==b[j])
			{
				cout<<a[i]<<" ";
				i++;
				j++;
			}
			else if(a[i]<b[i])
			{
				cout<<a[i]<<" ";
				i++;
			}
			else
			{
				cout<<b[j]<<" ";
				j++;
			}
		}
		if(i==size1)
		{
			while(j<size2)
			{
				cout<<b[j];
				j++;
			}	
		
		}
		else if(j==size2)
		{
			while(i<size1)
			{
				cout<<a[i];
				i++;
			}	
		
		}
	

}
