#include<iostream>
#include<utility>
#include<list>
using namespace std;
int main()
{
	//pair<int ,int> p;
	list<pair<int, int> > l;
	list<pair<int, int> >::iterator i,k;
	int n;
	cin>>n;
	while(n--)
	{
		int start,end;
		cin>>start>>end;
		
		l.push_back(make_pair(start,end));
	
	}
	l.sort();
	i=l.begin();
	i++;
	k=l.begin();
	for(;i!=l.end();i++)
	{
		
		if(i->first<k->second)
		{
			cout<<i->first<<","<<i->second<<endl;
			cout<<k->first<<","<<k->second<<endl;
		
		}
		//cout<<i->first<<" "<<i->second<<endl;
		k++;
	}
	return 0;
}
