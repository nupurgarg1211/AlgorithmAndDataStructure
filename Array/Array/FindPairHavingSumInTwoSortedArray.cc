/*

We are given two arrays ar1[0…m-1] and ar2[0..n-1] and a number x, we need to find the pair ar1[i] + ar2[j] such that absolute value of (ar1[i] + ar2[j] – x) is minimum.

Example:

Input:  ar1[] = {1, 4, 5, 7};
        ar2[] = {10, 20, 30, 40};
        x = 32        
*/
#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;
int main()
{
	int a[]= {1, 4, 5, 7};
	int b[]={10, 20, 30, 40};
	int n1=sizeof(a)/sizeof(a[0]),n2=sizeof(b)/sizeof(b[0]);
	int l=0,finall=0,r=n2-1,finalr,sum,diff=INT_MAX;
	cin>>sum;
	while(l<n1 && r>=0)
	{
		if(abs(sum-(a[l]+b[r]))<diff)
		{
			//cout<<abs(sum-(a[l]+b[r]))<<" "<<diff<<endl;
			finall=l;
			finalr=r;
			diff=abs(sum-(a[l]+b[r]));			
			//break;
		
		}
		else if(a[l]+b[r]<sum)
		{
			l++;
		
		}
		else
		{
			r--;
		
		}
	}
	cout<<a[finall]<<" "<<b[finalr]<<endl;
	return 0;
}
