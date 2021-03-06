#include<iostream>
using namespace std;
const int N=4;
bool isSafe(int x,int y,int a[N][N])
{
	for(int i=0;i<y;i++)
	{
		if(a[x][i]==1)
		{
			return false;
		}
	
	}
	for(int i=x-1 ,j=y-1;i>=0 && j>=0;i--,j--)
	{
		if(a[i][j]==1)
		{
			return false;
		}
		
	}
	for(int i=x+1,j=y-1;i<N,j>=0;i++,j--)
	{
		if(a[i][j]==1)
		{
			return false;
		}
	}
	return true;

}
bool solveUtil(int a[N][N],int col)
{
	if(col>=N)
	return true;
	for(int k=0;k<N;k++)
	{
		int newx=k;
		if(isSafe(newx,col,a))
		{

			a[newx][col]=1;
			if(solveUtil(a,col+1))
			return true;
			a[newx][col]=0;
		}
		
	
	}
	return false;

}
void solve(int a[N][N])
{
	if(solveUtil(a,0))
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		
	}	
	else
	cout<<"NO Solution!!";

}
int main()
{
	int a[N][N]={{0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}};
	solve(a);
	return 0;
}
