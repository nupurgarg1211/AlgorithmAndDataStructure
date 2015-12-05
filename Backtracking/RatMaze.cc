#include<iostream>
//#define N 4	
const int N = 4;
using namespace std;
bool isSafe(int x,int y,int a[N][N],int n)
{
	if(x<n && y<n && a[x][y]==1)
		return true;
	else 
		return false;


}
bool solveUtil(int x,int y,int x1[],int y1[],int sol[N][N],int a[N][N],int n)
{
	if(x==n-1 &&y==n-1)
	{
		return true;
	}
	for(int k=0;k<2;k++)
	{
		int newx=x+x1[k];
		int newy=y+y1[k];
		if(isSafe(newx,newy,a,n))
		{
			sol[newx][newy]=1;
			if(solveUtil(newx,newy,x1,y1,sol,a,n))
			{
				return true;
			
			}
			sol[newx][newy]=0;
		
		
		}
	}
	return false;
}
void solve(int a[N][N],int n)
{
	int sol[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			sol[i][j]=0;
		}
	
	}
	int x1[]={0,1};
	int y1[]={1,0};
	sol[0][0]=1;
	if(solveUtil(0,0,x1,y1,sol,a,n) == true)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
	
	}
	else
	{
		cout<<"No Solution!!"<<endl;
	}

}
int main()
{
	int a[N][N]={{1, 0, 0, 0},
                {1, 1, 0, 1},
                {0, 1, 0, 0},
                {1, 1, 1, 1}};
	
	int n=sizeof(a)/sizeof(a[0]);
	
	solve(a,n);
	return 0;
}
