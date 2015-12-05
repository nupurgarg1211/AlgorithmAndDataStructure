/* Rotate array in O(n)  */
#include<iostream>
using namespace std;
void RReverse(int a[],int l,int r)
{
	if(l>=r)
	{
		return;
	}
	swap(a[l],a[r]);
	
	RReverse(a,l+1,r-1);	
	

}
void print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
	
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void rotateArrayByK(int a[],int n,int k)
{
	RReverse(a,0,k-1);
	RReverse(a,k,n-1);
	RReverse(a,0,n-1);
	
}
int main()
{
	int a[]={1,2,3,4,5,6};
	int n=sizeof(a)/sizeof(a[0]);
	int k;
	cin>>k;
	rotateArrayByK(a,n,k);
	print(a,n);
	return 0;
}
