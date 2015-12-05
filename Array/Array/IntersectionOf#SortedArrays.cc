#include<iostream>
using namespace std;
int main()
{
	int ar1[] = {1, 5, 10, 20, 40, 80},ar2[] = {6, 7, 20, 80, 100},ar3[] = {3, 4, 15, 20, 30, 70, 80, 120};
	//int ar1[] = {1, 5, 5},ar2[] = {3, 4, 5, 5, 10},ar3[] = {5, 5, 10, 20};
	int n1=sizeof(ar1)/sizeof(ar1[0]),n2=sizeof(ar2)/sizeof(ar2[0]),n3=sizeof(ar3)/sizeof(ar3[0]);
	int l=0,m=0,n=0;
	
	while(l<n1 && m<n2 && n<n3)
	{
		if(ar1[l]==ar2[m] && ar1[l]==ar3[n])
		{
			cout<<ar1[l]<<" ";
			l++;
			m++;
			n++;
		}
		else if(ar1[l]<ar2[m])
		{
			l++;
		}
		else if(ar2[m]<ar3[n])
		{
		
			m++;
		}
		else
		{
			n++;
		}
	
	}
	return 0;
}
