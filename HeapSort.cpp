#include<iostream>
using namespace std;
int Parent(int i)
{
	return (i-1)/2;
}
int left(int i)
{
	return (2*i)+1;

}
int Right(int i)
{
	return (i*2)+2;

}
int ExtractMin(int a[],int size,int heapSize)
{
	int temp=a[0];
	a[0]=a[size-1];
	heapSize--;
	heapify(0);

}
void heapify(int i,int size,int a[])
{
	int l=left(i);
	int r=Right(i);
	int smallest=i;
	if(l<size && a[l]<a[i])
	{
		smallest=l;
	
	}
	if(r<size && a[r]<a[smallest])
	{
		smallest=r;
	}
	if(i!=smallest)
	{
		swap(a[smallest],a[i]);
		heapify(smallest);
	
	}

}
void createMinHeap(int a[],int size)
{
	for(int i=(size-1)/2;i>=0;i--)
	{
		heapify(i);
	
	}

}
int main()
{
	int a[]={5,7,3,2,8,9,10};
	int size=sizeof(a)/sizeof(a[0]);
	createMinHeap(a,size);
		

	return 0;
}
