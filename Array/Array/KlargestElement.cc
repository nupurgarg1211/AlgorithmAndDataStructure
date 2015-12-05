#include<iostream>
using namespace std;
int left(int i)
{
	return 2*i+1;

}
int right(int i)
{

	return 2*i+2;
}
int getParent(int i)
{
	return (i-1)/2;
}
void swap(int &a,int & b)
{
	int temp=a;
	a=b;
	b=temp;
}
void  Maxheapify(int a[],int i,int size)
{
	
	//int l=Maxheapify(a,left(i),size);
	//cout<<"here"<<endl;
	//int r=Maxheapify(a,right(i),size);
	int l=left(i);
	int r=right(i);
	int largest=i;
	
	if(a[largest]<a[l] && l<size)
	{
		
		largest=l;
	}
	if(a[largest]<a[r] && r<size)
	{
		largest=r;
	}
	if(a[largest]!=a[i])
	{
	
		//cout<<largest<<" "<<i<<endl;
		swap(a[largest],a[i]);
		Maxheapify(a,largest,size);
	}
}
void CreateMaxHeap(int size,int a[])
{
	for(int i=getParent(size-1);i>=0;i--)
	{
		
		 Maxheapify(a,i,size);
	}

}
void extractKMax(int a[],int size,int k)
{
	for(int i=0;i<k;i++)
	{
		int temp=a[size-1];
		a[size-1]=a[0];
		a[0]=temp;
		cout<< a[size-1]<< " ";
		size--;
		Maxheapify(a,0,size);
		
	}
}
int main()
{
	int a[]={1,23,12,9,30,2,50},k;
	int size =sizeof(a)/sizeof(a[0]);
	CreateMaxHeap(size,a);
	cin>>k;
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<" "<<endl;
	}
	extractKMax(a,size,k);
	return 0;
}
