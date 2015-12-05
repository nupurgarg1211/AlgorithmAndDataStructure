#include<iostream>
using namespace std;
void moveToEnd(int a[],int size1)
{
	int j=size1-1;
	for(int i=size1-1;i>=0;i--)
	{
		if(a[i]!=0)
		{
			a[j]=a[i];
			j--;
		}
	}
}
void merge(int a[],int b[],int size1,int size2)
{
	int i=0,start2=0;
	int start1=size1-size2;
	while(i<size1)
	{
		if( start1>=size1 || start2>=size2)
		{
			break;
		}
		if(a[start1]<b[start2] )
		{
			a[i]=a[start1];
			start1++;
		
		}
		else if(a[start1]>b[start2] )
		{
			a[i]=b[start2];
			start2++;
		
		}
		i++;
	
	}
	cout<<start1<<" "<<start2<<endl;
	cout<<size1<<" "<<size2<<endl;
	cout << i << endl;
	if(start1<size1) 
	{
		for(int j=start1;j<size1;j++)
		{
			a[i]=a[j];
			i++;
		}
	}
	
	else if(start2<size2 )
	{
		cout << "hello\n";
		for(int j=start2;j<size2;j++)
		{
			a[i]=b[j];
			i++;
		
		}
	
	}
	
}
int main()
{
	int a[]={2,0,3,0,0,5,9,0};
	int b[]={10,11,17,19};
	int size1=sizeof(a)/sizeof(a[0]);
	int size2=sizeof(b)/sizeof(b[0]);
	//int i=size-1,j=size1-1;
	moveToEnd(a,size1);
	for(int i=0;i<size1;i++)
	{
		cout<<a[i]<<" ";
	}
	cout << endl;
	merge(a,b,size1,size2);
	for(int i=0;i<size1;i++)
	{
		cout<<a[i]<<" ";
	}
	
	return 0;
}
