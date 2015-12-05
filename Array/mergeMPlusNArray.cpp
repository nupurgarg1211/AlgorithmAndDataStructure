#include<iostream>
using namespace std;
void shiftArrayToend(int a[],int n)
{
	for(int j=n-1;j>0;j--)
	{
		if(a[j]!=0)
		continue;
		else
		{
			int k=j-1;
			while(a[k]==0 && k>0)
			{
				k--;
			
			}
			a[j]=a[k];
			a[k]=0;
		
		}
	
	
	}

}
void printArray(int a[],int n)
{
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";

}
void merge(int a[],int b[],int n,int m)
{
	int up=n;
	int down=0;
	int count=0,i=0;
	while(count!=m+n)
	{
		if(a[up]<b[down])
		{
			//cout<<"if"<<endl;
			a[i]=a[up];
			//cout<<a[up]<<" "<<a[down]<<" "<<up<<endl ;
			up++;
			//if(up==m+n)
			//break;
		}
		
		else 
		{
			//cout<<"else"<<endl;
			a[i]=b[down];
			//cout<<a[up]<<" "<<a[down]<<" "<<down<<endl ;
			down++;
			//if(down==n)
			//break;
		
		}
		i++;
		count++;
	}
}
int main()
{
	int m,n;
	cin>>m>>n;
	int a[m+n],b[n];
	for(int i=0;i<m+n;i++)
	cin>>a[i];
	for(int i=0;i<n;i++)
	cin>>b[i];
	shiftArrayToend(a,m+n);
	printArray(a,m+n);
	merge(a,b,n,m);
	cout<<"after Merge:";
	printArray(a,m+n);

	return 0;
	
}
