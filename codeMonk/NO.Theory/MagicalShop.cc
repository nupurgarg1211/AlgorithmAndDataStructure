#include<iostream>
#include<string>
using namespace std;
int main()
{
	long long int A,B,potions=0,c;
	string permission;
	cin>>A>>B;
	cin>>permission;
	for(int i=0;i<permission.length();i++)
	{
		
		if(permission[i]=='1')
		{
			potions=potions+A;
			cout<<A<<endl;
		}
		A=(A*A)%B;
	
	}
	cout<<potions%B;

	return 0;
}
