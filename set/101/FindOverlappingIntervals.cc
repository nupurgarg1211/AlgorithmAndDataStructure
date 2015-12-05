#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	vector<pair<int,int> > interval,ans;
	int n,x,y,start,end;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		
		cin>>x>>y;
		interval.push_back(make_pair(x,y));
		
	
	}
	sort(interval.begin(),interval.end());
	start=interval[0].first;
	end=interval[0].second;
	//for(vector<pair<int,int> >::iterator i=interval.begin();i!=interval.end();i++)
	for(int i=1;i<n;)
	{
		
		cout<<i<<endl;
		while(end>=interval[i].first && i<n)
		{
			if(end<interval[i].second)
			{
				end=interval[i].second;
			}
			i++;
		
		}
		//end=interval[i-1].second;
		ans.push_back(make_pair(start,end));
		start=interval[i].first;
		end=interval[i].second;
		
	
	}
	
	for(vector<pair<int,int> >::iterator i=ans.begin();i!=ans.end();i++)
	{
		cout<<i->first<<" "<<i->second<<endl;
	
	}
	return 0;
}
