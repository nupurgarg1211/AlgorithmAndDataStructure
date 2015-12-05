#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
	int t,n;
	set<string> s;
	cin>>t;
	string a;
	while(t--)
	{
		cin>>n;
		while(n--)
		{
			cin>>a;
			s.insert(a);
			
		}
		for(set<string> :: iterator i=s.begin();i!=s.end();i++)
		{
			cout<<*i<<endl;
		
		}
	}
	return 0;

}
