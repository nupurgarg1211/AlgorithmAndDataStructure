#include<iostream>
using namespace std;
void FindIndex(string a)
{
	int l=0,r=a.length()-1,count=0,flag = 0;
	while(l<r)
	{
		if(a[l]==a[r])
		{
			l++;
			r--;
		}
		else if(a[l]==a[r-1] )
		{
			//l++;
			
			count=r;
			r--;
		}
		else if(a[l+1]==a[r])
		{
			
			count=l;
			l++;
		}
		else{
			cout << count << endl;
			flag = 1;
			break;
		}
	
	}
	if(flag == 0)
	  cout<<"-1"<<endl;

}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string a;
		cin>>a;
		FindIndex(a);
	
	}
	return 0;
}
