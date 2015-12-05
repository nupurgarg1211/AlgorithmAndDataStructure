#include<iostream>
#include<string>
using namespace std;

void checkPallindrome(string input,int low,int high,int n,int &max,int &start)
{
	//int start=0;
	while(input[low]==input[high] && low>=0 && high<n)
	{
		//cout << "low before " << low << " high before" << high << " start before " << start << endl;
		if(max<high-low+1)
		{
			//cout << "in the if\n";
			start=low;
			max=high-low+1;
		}
		low--;
		high++;
		//cout << "low later " << low << " high later" << high << " start after " << start << endl;
	
	}	
	//return start;
}
int main()
{
	string input;
	cin>>input;
	int max=1,start;
	int l=input.length();
	for(int i=0;i<l;i++)
	{
		checkPallindrome(input,i,i,l,max,start);
	
	}
	//cout<<input<<endl;
	cout<<start<<endl;
	string ans=input.substr(start,start+max);
	cout<<ans<<endl;
	cout<<max<<endl;
	return 0;
}
