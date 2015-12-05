#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int x;
	cin>>x;
	int digits=log(x)+1;
	int a=1,ans=0;	
	for(int i=digits;i>=0;i--)
	{
		int rem=x & (a<<i);
		cout<<rem<<endl;
		ans=ans ^ (rem>>(i));
		cout<<"ans="<<ans<<endl;
	
	}
	cout<<ans<<endl;
	return 0;
}
