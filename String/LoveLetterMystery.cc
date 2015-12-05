#include<iostream>
#include<cstdlib>
using namespace std;
void countOperationsForPalindrome(string a)
{
	int l=0,r=a.length()-1,count=0;
	while(l<=r)
	{
		if(a[l]!=a[r])
		{
			count=count+abs(a[r]-a[l]);
		}
		l++;
		r--;
	}
	cout<<count<<endl;

}
int main()
{
	int t;
	cin>>t;
	string a;
	while(t--)
	{
		cin>>a;
		countOperationsForPalindrome(a);
	
	}

	return 0;
}
