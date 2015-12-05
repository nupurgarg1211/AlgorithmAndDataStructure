/* print max size subarray of size j-i+1 from a[i] to a[j ] having property like:

i<=k<=j and
a[i]<=a[i+1]<=a[i+2]<=....a[k]>=a[k+1]..>=a[j-1]>=a[j]
 */

#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int a[]= {40, 30, 20, 10};
	int n=sizeof(a)/sizeof(a[0]);
	int inc[n],dec[n];
	inc[0]=1;
	for(int i=1;i<n;i++)
	{
		if(a[i-1]<a[i])
		{
			inc[i]=inc[i-1]+1;
		}
		else
		inc[i]=1;	
	}
	
	dec[n-1]=1;
	for(int i=n-2;i>=0;i--)
	{
		if(a[i]>a[i+1])
		{
			dec[i]=dec[i+1]+1;
		}
		else
		dec[i]=1;
	}
	//cout<<"dec="<<endl;
	int max=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(max<inc[i]+dec[i]-1)
		{
		
			max=inc[i]+dec[i]-1;
		}
	
	}
	cout<<max<<endl;
	return 0;
}
