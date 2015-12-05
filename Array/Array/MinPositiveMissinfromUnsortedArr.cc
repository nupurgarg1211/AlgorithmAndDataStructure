/* find smallest positive missing  in unsorted array having negative no. also
Input:  {2, 3, 7, 6, 8, -1, -10, 15}
 Output: 1

 Input:  { 2, 3, -7, 6, 8, 1, -10, 15 }
 Output: 4

 Input: {1, 1, 0, -1, -2}
 Output: 2 


*/
#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
int segregatePositiveNegative(int a[],int n)
{
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			swap(a[i],a[j]);
			j++;
		}
	}
	return j;
}
int findmissingPos(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
		if(a[abs(a[i])-1]>0 && abs(a[i])-1<n)
		{
			a[abs(a[i])-1]=-a[abs(a[i])-1];
			//cout<<"location="<<abs(a[i])-1<<endl;
		
		}
	
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			return i+1;
		}
	
	}
	return n+1;
}

int main()
{
	int a[]={ 2, 3, -7, 6, 8, 1, -10, 15 };
	int n=sizeof(a)/sizeof(a[0]);
	int min=INT_MAX;
	int shift=segregatePositiveNegative(a,n);
	int ans=findmissingPos(a+shift,n-shift);
	cout<<"smallest poitive missing="<<ans<<endl;
	return 0;
}
