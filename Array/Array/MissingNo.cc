#include<iostream>
using namespace std;
int main()
{
	int a[]={1,3,4,5,6,7,8};
	int size=sizeof(a)/sizeof(a[0])+1;
	int ans1=a[0],ans2=1;
	/*int sum=(size*(size+1))/2;
	int elemenSum=0;
	for(int i=0;i<size;i++)
	{
		sum=sum-a[i];
	
	}
	cout<<sum;*/
	for(int i=1;i<size;i++)
	{
		ans1=ans1^a[i];
		ans2=ans2^(i+1);
	
	}
	ans1=ans1^ans2;
	cout<<ans1;
	return 0;
}
