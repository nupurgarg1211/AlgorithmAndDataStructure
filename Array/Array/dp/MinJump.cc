#include<iostream>
#include<climits>
using namespace std;
int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int a[]={1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int n=sizeof(a)/sizeof(a[0]);
	int jump[n];
	jump[0]=0;
	for(int i=1;i<n;i++)
	{
		jump[i]=INT_MAX;
		for(int j=0;j<i;j++)
		{
			if(i-j<=a[j] && jump[j]!=INT_MAX)
			{
				jump[i]=min(jump[i],jump[j]+1);
				break;		
			}		
		}
	
	}
	cout<<jump[n-1];
	return 0;
}



