#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string a;
		cin>>a;
		int n=a.length();
		string rev="";
		bool flag=0;
		rev=a;
		reverse(rev.begin(),rev.end());
		//cout<<rev<<endl;
		for(int i=1;i<n;i++)
		{
			//cout<<a[i]<<" "<<a[i-1]<<" "<<rev[i]<<" "<<rev[i-1]<<endl;
			if(abs(a[i]-a[i-1]) != abs(rev[i]-rev[i-1]))
			{
				//cout<<"here"<<endl;
				//continue;
				cout<<"Not Funny"<<endl;
				flag=1;
				break;	
				
			}
			
			
		}
		if(flag==0)	
			cout<<"Funny";
	}
	return 0;
}
