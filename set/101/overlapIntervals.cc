#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;

int main()
{
	int n,x,y;
	cin>>n;
	vector <pair<int,int> > intervals,ans;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		intervals.push_back(make_pair(x,y));
		
	}
	sort(intervals.begin(),intervals.end());
	for(vector<pair< int,int> >::iterator i=intervals.begin();i!=intervals.end();)
	{
		//cout<<i->first<<" "<<i->second<<endl;
		/*1 2
		2 3
		5 7*/
		int start=i->first;
		i++;
		while((i-1)->second >= (i)->first)
		{
			i++;
		}	
		int end=i->second;
		ans.push_back(make_pair(start,end));
				
	}
	return 0;
}
