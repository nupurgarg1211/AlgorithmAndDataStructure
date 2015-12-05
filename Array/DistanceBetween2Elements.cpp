#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;
int main()
{
	int a[]={3,5,4,2,6,5,6,6,5,4,8,3},x,y,index1=0,index2=0,diff=0,min=INT_MAX;
	int size=sizeof(a)/sizeof(a[0]);
	bool flag1=0,flag2=0;
	cin>>x>>y;
	for(int i=0;i<size;i++)
	{
		if(a[i]==x)
		{
			index1=i;
			flag1=1;
			//cout<<index1<<endl;;
			
		
		}
		else if(a[i]==y)
		{
			index2=i;
			flag2=1;
			//cout<<index2<<endl;
		
		}
		if(flag1==1 && flag2==1)
		{
			diff=abs(index1-index2);
			if(min>diff)
			{
				min=diff;
			}
		
		}
	
	}
	
	cout<<min<<endl;
	
	return 0;
}
