#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int a[]={12, 34, 10, 6, 40,42,51,50};
	int n=sizeof(a)/sizeof(a[0]);
	int max=INT_MIN,max2;
	for(int i=0;i<n;i++)
	{
		if(max<a[i])
		{
			max2=max;
			max=a[i];
		}
		else if(max2<a[i])
		{
			max2=a[i];
		}
	
	}
	cout<<max2<<" "<<max<<endl;
	cout<<max2+max<<endl;
	return 0;
}
