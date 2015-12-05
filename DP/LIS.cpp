#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
int findMax(int a[],int n)
{
	int max=INT_MIN,loc=0;
	for(int i=0;i<n;i++)
	{
		if(max<a[i])
		{
			max=a[i];
			loc=i;
			
		}
	
	}
	
	return loc;

}
int LIS(int a[],int n)
{
	int L[n],P[n];
	cout<<n<<endl;
	//memset(L,1,sizeof(L));
	for(int i=0;i<n;i++)
	{
		L[i]=1;
		P[i]=-1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j] && L[i]<L[j]+1)
			{
				L[i]=L[j]+1;
				P[i]=j;
			
			}
		
		}
	
	}
	int maxIndex=findMax(L,n);
	for(int i=maxIndex;P[i]!=-1;)
	{
		cout<<a[i]<<endl;
		i=P[i];
	
	}
	return 0;


}
int main()
{
	int a[]={10, 22, 9, 33, 21, 50, 41, 60 };
	int n=sizeof(a)/sizeof(a[0]);
	LIS(a,n);
	return 0;
}
