#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
void f(int **a,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<endl;
		}
	
	}

}	
int main()
{
	int a[6][6]={0};	
	int n=6;
	f(a,n);	
	return 0;	
}
