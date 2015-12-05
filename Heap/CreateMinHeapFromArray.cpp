#include<iostream>
#include<climits>
using namespace std;
class Heap
{
	int capacity,heapSize,*heap;
	public:
	Heap(int c);
	int getCapacity();
	void setCapacity(int c);
	//int heapSize
	int getMin();
	int parent(int i);
	int getLeft(int i);
	int getRight(int i);
	int extractMin();
	void insertKey(int k);
	void swap(int &a,int &b);
	void printArray();
	void heapify(int i);
	void decreaseKey(int i,int newKey);//newKey is assumed to be less than heap[i]
	void deleteKey(int i);
	void createMinHeap(int a[]);
};
Heap::Heap(int c)
{
	capacity=c;
	heapSize=0;
	heap=new int[c];
	for(int i=0;i<6;i++)
	{
		cin>>heap[i];
		heapSize++;
	}
	createMinHeap(heap);

}
int Heap::getCapacity()
{
	return capacity;
}
void Heap::setCapacity(int c)
{
	capacity=c;

}
//int heapSize
int Heap::getMin()
{
	return heap[0];

}
int Heap::parent(int i)
{
	return ((i-1)/2);

}
int Heap::getLeft(int i)
{
	return (2*i+1);

}
int Heap::getRight(int i)
{
	return (2*i+2);

}
int Heap::extractMin()
{
	int min=heap[0];
	if(heapSize==1)
	{
		heapSize--;
		return min;
	}
	heap[0]=heap[heapSize-1];	
	heapSize--;
	heapify(0);
	return min;
}
void Heap::insertKey(int k)
{
	if(heapSize==capacity)
	{
		cout<<"heap full"<<endl;
		return;
	}
	heapSize++;
	int i=heapSize-1;
	heap[i]=k;
	while(i!=0 && heap[i]<heap[parent(i)])
	{
		swap(heap[i],heap[parent(i)]);
		//cout<<"swapped values are:"<<heap[i]<<" "<<heap[parent(i)]<<endl;
		i=parent(i);
	
	}	

}
void Heap::swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void Heap::printArray()
{
	for(int i=0;i<heapSize;i++)
	{
		cout<<heap[i]<<"  ";
	
	}
	cout<<endl;
}
void Heap::heapify(int i)
{
	int l=getLeft(i);
	int r=getRight(i);
	cout<<"heapify"<<endl;
	int smallest=i;
	if(l<heapSize && heap[l]<heap[smallest])
	{
		smallest=l;
	}
	if(r<heapSize && heap[r]<heap[smallest])
	{
		smallest=r;
	
	}
	if(smallest!=i)
	{
		swap(heap[smallest],heap[i]);
		heapify(smallest);
	
	}
}
void Heap::decreaseKey(int i,int newKey)
{
	heap[i]=newKey;
	while(i!=0 && heap[parent(i)]>heap[i])
	{
		swap(heap[parent(i)],heap[i]);
		i=parent(i);
	
	}
}
void Heap::deleteKey(int i)
{
	decreaseKey(i,INT_MIN);
	extractMin();
}
void Heap::createMinHeap(int a[])
{
	for(int i=(heapSize-1)/2;i>=0;i--)
	{
		heapify(i);
		cout<<"i="<<i<<endl;
	
	}

}
int main()
{
	Heap h(10);
	
	h.printArray();

}
