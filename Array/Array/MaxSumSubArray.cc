#include<iostream>
using namespace std;
int main()
{
	int a[]={5,5,4,10,4};
	int n=sizeof(a)/sizeof(a[0]);
	int GSum,sum=0,s=0,e;
	cin>>GSum;
	for(int i=0;i<n;i++)
	{
		if(sum<GSum)
		{
			sum=sum+a[i];
			e=i;
		}	
		while(sum>GSum)
		{
			sum=sum-a[s];
			s++;
			
		}
		if(sum==GSum)
		{
			cout<<"start="<<s<<" "<<"end"<<e<<endl;
			sum=0;
			s=i+1;
		
		}
				
	}
	
	return 0;
}
