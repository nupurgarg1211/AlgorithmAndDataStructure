/*Given a set of inputs (x,y) which represent intervals, merge overlapping intervals
e.x. (3,4) ; (2,5) ; (1,4) ; (8,9)
output should be – (1,5) ; (8,9)*/
#include<iostream>
using namespace std;
struct cordinate
{
	int x;
	int y;
};
void swap(cordinate &x,cordinate &y)
{
	cordinate temp=x;
	x=y;
	y=temp;
}
/*void merge(cordinate intervalSet[],int start1,int end1,int end2)
{
	int start2=end1+1;
	cout<<"merge"<<start1<<" "<<start2<<endl;
	cout<<"end"<<end1<<" "<<end2<<endl;
	//while(start1<=end1 || start2<=end2)
	while(start1<=start2-1 && start2<end2)
	{
		cout<<intervalSet[start2].x<<" "<<intervalSet[start1].x<<endl;
		if(intervalSet[start2].x<intervalSet[start1].x)
		{
			swap(intervalSet[start1],intervalSet[start2]);
			cout<<"swapped="<<start1<<" "<<start2<<endl;
			//start2++;
		}
		
			start1++;
		
	
	}
}*/
void merge(cordinate a[],int l,int mid,int r)
{
	int n1=mid-l+1;
	int n2=r-mid;
	cordinate L[n1],R[n2];
	for(int i=0;i<n1;i++)
	{
		L[i].x=a[l+i].x;
		L[i].y=a[l+i].y;
	}
	for(int i=0;i<n2;i++)
	{
		R[i].x=a[mid+1+i].x;
		R[i].y=a[mid +1 +i].y;
	}
	int i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(L[i].x<=R[j].x)
		{
			a[k].x=L[i].x;
			a[k].y=L[i].y;
			i++;
		}
		else
		{
			a[k].x=R[j].x;
			a[k].y=R[j].y;
			j++;
		
		}
		k++;
	}
	while(i<n1)
	{
		a[k].x=L[i].x;
		a[k].y=L[i].y;
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k].x=R[j].x;
		a[k].y=R[j].y;
		j++;
		k++;
	
	}	

}
void Mergesort(cordinate intervalSet[],int l,int n)
{
	if(l<n)
	{
		//cout<<"here"<<endl;
		int mid=(l+n)/2;
		Mergesort(intervalSet,l,mid);
		Mergesort(intervalSet,mid+1,n);
		merge(intervalSet,l,mid,n);
	}
}
int main()
{
	int num,a,b;
	cin>>num;
	cordinate intervalSet[num];
	for(int i=0;i<num;i++)
	{
		cin>>a>>b;
		intervalSet[i].x=a;
		intervalSet[i].y=b;
	}
	Mergesort(intervalSet,0,num-1);
	for(int i=0;i<num;i++)
	{
		cout<<intervalSet[i].x<<" "<<intervalSet[i].y<<endl;
	}

}
