#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int a[]={3,10,2,1,12};
	int size=sizeof(a)/sizeof(a[0]);
	int diff=a[1]-a[0],min=a[0];
	for(int i=1;i<size;i++)
	{
		if(diff<(a[i]-min))
		{
			diff=a[i]-min;
		}
		if(min>a[i])
		{
			min=a[i];
		}
	
	}
	cout<<diff<<endl;
	return 0;
}
