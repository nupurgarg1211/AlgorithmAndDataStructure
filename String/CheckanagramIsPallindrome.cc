#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool chkPalindrome(string a)
{
	string b=a;
	reverse(b.begin(),b.end());
	if(b==a)
		return 1;
	else 
		return 0;	
}
void swap(string &a,int i,int j)
{
	char temp=a[i];
	a[i]=a[j];
	a[j]=a[i];

}
void findAnagram(string a,int l,int r)
{
	int i;
	if(l==r)
	{
		if(chkPalindrome(a))
		{
			cout<<"here"<<endl;
			cout<<"YES"<<endl;
			exit(0);
		}
		return;	
	}
	else
	{
		for(i=l;i<=r;i++)
		{
			cout<<i<<" "<<r<<endl;
			swap(a,l,i);
			findAnagram(a,l+1,r);
			swap(a,l,i);
		}
	}
}


int main()
{
	string a;
	cin>>a;
	//cout<<a.length()<<endl;
	findAnagram(a,0,a.length()-1);
	cout<<"NO"<<endl;
	return 0;
}
