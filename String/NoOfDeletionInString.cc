#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string a;
		cin>>a;
		int count=0;
		for(int i=1;i<a.length();i++)
		{
			if(a[i]==a[i-1])
			{
				count++;
			}
		
		}
		cout<<count<<endl;
	
	}
	
	return 0;
}
