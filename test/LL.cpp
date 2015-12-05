/*1. Given two linked lists. Add them. 
e.g 1–>2–>3
3–>4
Output: 1–>5–>7
*/
#include<iostream>
//#include<bits/c++.std>
#include<vector>
#include<algorithm>
using namespace std;
vector<int >add(vector<int > LL1,vector<int> LL2,int l1,int l2)
{
	vector<int> ans;
	l1--;l2--;
	while(l1>=0 && l2>=0)
	{
		ans.push_back(LL1[l1]+LL2[l2]);
		l1--;
		l2--;
	}
	while(l1>=0)
	{
	
		ans.push_back(LL1[l1]);
		l1--;
	}
	while(l2>=0)
	{
	
		ans.push_back(LL2[l2]);
		l2--;
	}
	return ans;
}
void printLL(vector<int> ans)
{
	for(vector<int> ::iterator i=ans.begin();i!=ans.end();i++)
	{
		cout<<*i<<" "<<endl;	
	}

}
int main()
{
	int l1,l2,x;
	cin>>l1>>l2;
	vector<int> LL1,LL2;
	for(int i=0;i<l1;i++)
	{
		cin>>x;
		LL1.push_back(x);
		
		
	}
	for(int i=0;i<l2;i++)
	{
		cin>>x;
		LL2.push_back(x);
		
		
	}
	vector<int> ans=add(LL1,LL2,l1,l2);
	reverse(ans.begin(),ans.end());
	printLL(ans);
	return 0;
}

