#include<iostream>
using namespace std;
int main()
{
	int a[]={7, 3, 5, 4, 5, 3, 4};
	int n=sizeof(a)/sizeof(a[0]),ans=0;
	for(int i=0;i<n;i++)
	{
		ans^=a[i];
	}
	cout<<ans<<endl;
}
