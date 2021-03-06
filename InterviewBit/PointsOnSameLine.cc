/*Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.*/
#include<iostream>
#include<map>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	if(a<0)
	{
		gcd(a*-1,b);
	}
	if(b<0)
	{
		gcd(a,-1*b);
	}
	gcd(b,a%b);

}
int main()
{
	int x[]={1,0,1,-1};
	int y[]={2,0,1,-1};
	int n=sizeof(x)/sizeof(x[0]);
	map< pair<int ,int> , int> M;
	int ans=0,MaxCount=0;
	for(int i=0;i<n;i++)
	{
		MaxCount=0;
		M.clear();
		for(int j=i+1;j<n;j++)
		{
			int xdiff=x[i]-x[j];
			int ydiff=y[i]-y[j];
			if(xdiff<0 && ydiff<0)
			{
				xdiff=-1*xdiff;
				ydiff=-1*ydiff;
			}
			int g=gcd(xdiff,ydiff);
			M[make_pair(xdiff/g,ydiff/g)]++;
			MaxCount=max(MaxCount,M[make_pair(xdiff/g,ydiff/g)]);				
		}
		ans=max(ans,MaxCount+1);
	}
	cout<<ans<<endl;
	return 0;
}
