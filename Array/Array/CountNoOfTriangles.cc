#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[]={4, 6, 3, 7};
	int n=sizeof(a)/sizeof(a[0]);
	int k=0,count=0;
	sort(a,a+n);
	for(int i=0;i<n-2;i++)
	{
		k=i+2;
		for(int j=i+1;j<n;j++)
		{
			
			
			while(a[i]+a[j]>a[k] && k<n)
			{
				cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
				k++;
			}	
			count+=k-j-1;
		
		}
	
	}
	cout<<count<<endl;
	return 0;
}
