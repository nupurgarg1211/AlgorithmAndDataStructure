#include<iostream>
using namespace std;
const int n=3;
const int m=4;
void printLCS(string x,string y,int m,int n,int l,int **L)
{
	char ans[l+1];
	ans[l]='\0';
	l--;
	int i=m,j=n;
	while(i!=0 && j!=0)
	{
		if(x[i-1]==y[j-1])
		{
			ans[l]=x[i-1];
			i--;
			j--;
		}
		else
		{
			if(L[i-1][j]>L[i][j-1])
			{
				i--;
			}
			else
				j--;
		}
	
	}
	cout<<ans<<endl;

}
int FindLCS(string x,string y,int m,int n)
{
	int L[n+1][m+1];
	for(int i=0;i<=m;i++)
	{
		L[0][i]=0;
	}
	for(int i=0;i<=n;i++)
	{
		L[i][0]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(y[i-1]==x[j-1])
			{
				L[i][j]=L[i-1][j-1]+1;
			}
			else
			{
				if(L[i-1][j]>L[i][j-1])
				{
					L[i][j]=L[i-1][j];
				}
				else
				{
					L[i][j]=L[i][j-1];
				}
			}
			
		}
	
	}
	printLCS(x,y,m,n,L[n][m],L);
	return L[n][m];
}
int main()
{
	string x="ABCD",y="ABD";
	int m=x.length(),n=y.length();
	int length=FindLCS(x,y,m,n);
	cout<<length<<endl;
	return 0;
}
