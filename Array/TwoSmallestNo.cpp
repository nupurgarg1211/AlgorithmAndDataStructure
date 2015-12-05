#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int a[]={3,4,1,2};
	int size=sizeof(a)/sizeof(a[0]);
	int first=INT_MAX,second;
	for(int i=0;i<size;i++)
	{
		if(first>a[i])
		{
			second=first;
			first=a[i];
		}
		else if(a[i]<second)
		{
			second=a[i];
		}
	
	}
	if(second==INT_MAX)
	cout<<"NO second smallest element"<<endl;
	else
	cout<<first<<" "<<second<<endl;
	return 0;
}
