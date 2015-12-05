#include<iostream>
#include<climits>
using namespace std;
class Heap
{
	int *heap;
	int heapSize;
	int capacity;
	public:
	Heap(int c);
	int getParent(int i);
	int getLeft(int i);
	int getRight(int i);
	int getMin();
	void decreaseKey(int i,int data);
	void deleteKey(int i);
	void createHeap(int a[],int n);
	void printArray(); 
	void minHeapify(int i);
	void swap(int *a,int *b);
	int extractMin();

};
Heap::Heap(int c)
{
	capacity=c;
	heapSize=0;
	heap=new int[c];
}
int Heap::getParent(int i)
{
	return (i-1)/2;
}
int Heap::getLeft(int i)
{
	return (2*i+1);
}
int Heap::getRight(int i)
{
	return (2*i+2);
}
int Heap::getMin()
{
	if(heapSize>1)
	return heap[0];
	else 
	return INT_MIN;

}
void Heap::decreaseKey(int i,int data)
{
	heap[i]=data;
	while(i!=0 && heap[getParent(i)]>heap[i])
	{
		swap(&heap[getParent(i)],&heap[i]);
		i=getParent(i);
	}		
}
void Heap::deleteKey(int i)
{
	decreaseKey(i,INT_MIN);
	extractMin();
}
void Heap::createHeap(int a[],int n)
{
	


}
void Heap::printArray()
{
	for(int i=0;i<heapSize;i++)
	{
		cout<<heap[i]<<" ";
	
	}
} 
void Heap::minHeapify(int i)
{
	int l=getLeft(i);
	int r=getRight(i);
	int smallest=i;
	if(l<heapSize && heap[l]<heap[smallest])
	smallest=l;
	if(r<heapSize && heap[r]<heap[smallest])
	smallest=r;
	if(i!=smallest)
	{
		swap(&heap[smallest],&heap[i]);
		minHeapify(smallest);
	}


}
void Heap::swap(int *a,int *b)
{
	int temp=*a;
	*b=*a;
	*a=temp;

}
int Heap::extractMin()
{
	int  min;
	if(heapSize>1)
	{
		heap[0]=heap[heapSize-1];
		min=heap[0];
		heapSize--;
		minHeapify(0);
		return min;
	}
	
}
int main()
{


	return 0;
}
