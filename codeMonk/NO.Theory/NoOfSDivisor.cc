#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long int beerInt;
	while(n--)
	{
		cin>>beerInt;
		bool flag=0;
		for(long long int i=2;i<beerInt/2;i++)
		{
			if(beerInt%i==0)
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			cout<<"NO";
			
		}
		else
		{
			int count=0;
			for(long long int i=2;i<=beerInt;i++)
			{
				if(beerInt%i==0)
				{
					count++;
					//cout<<count<<endl;
									
				}
				
				if(count>=3)
				{
					cout<<"YES";
					break;
				}
			
			}
			if(count<3)
			{
				cout<<"NO";
				
			
			}
		
		}
	}
	return 0;
}
