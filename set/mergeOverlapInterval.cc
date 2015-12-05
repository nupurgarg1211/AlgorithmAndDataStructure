#include<iostream>
#include<vector>

using namespace std;
struct cordinate
{
	int x;
	int y;
};
void merge(cordinate interval[],int l,int mid,int r)
{
	int n1=mid-l+1;
	int n2=r-mid;
	cordinate L[n1],R[n2];
	for(int i=0;i<n1;i++)
	{
		L[i].x=interval[l+i].x;
		L[i].y=interval[l+i].y;
	}
	for(int i=0;i<n2;i++)
	{
		R[i].x=interval[mid+1+i].x;
		R[i].y=interval[mid+1+i].y;
	}
	//cout<<"merge"<<endl;
	int i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(L[i].x<=R[j].x)
		{
			interval[k].x=L[i].x;
			interval[k].y=L[i].y;
			i++;
		}
		else
		{
			interval[k].x=R[j].x;
			interval[k].y=R[j].y;
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		interval[k].x=L[i].x;
		interval[k].y=L[i].y;
		i++;
		k++;
	
	}
	while(j<n2)
	{
		interval[k].x=R[j].x;
		interval[k].y=R[j].y;
		j++;
		k++;
	
	}
}
void mergesort(cordinate interval[],int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		mergesort(interval,0,mid);
		mergesort(interval,mid+1,r);
		merge(interval,l,mid,r);
	
	}

}
vector<pair<int,int> >  mergeOverlapIntervals(cordinate interval[],int num)
{
	vector<pair<int,int> > ans;
	int start=interval[0].x,end=interval[0].y;
	for(int i=1;i<num;)
	{
		while(end>interval[i].x && i<num)
		{
			if(end<interval[i].y)
			{
				end=interval[i].y;
			}
			
			i++;
		}
		ans.push_back(make_pair(start,end));
		start=interval[i].x;
		end=interval[i].y;
	
	}
	return ans;
}
void printIntervals(cordinate a[],int num)
{
	for(int i=0;i<num;i++)
	{
		cout<<a[i].x<<" "<<a[i].y<<endl;
	}

}
void printvector(vector<pair<int,int> >ans)
{
	for(vector<pair<int,int> >::iterator i=ans.begin();i!=ans.end();i++)
	{
		cout<<i->first<<" "<<i->second<<endl;
	}
}
int main()
{
	int num,a,b;
	cin>>num;
	cordinate interval[num];
	for(int i=0;i<num;i++)
	{
		cin>>a>>b;
		interval[i].x=a;
		interval[i].y=b;
	
	}
	//printIntervals(interval,num);
	mergesort(interval,0,num-1);
	//cout<<"here"<<endl;
	vector<pair<int,int> > ans=mergeOverlapIntervals(interval,num);
	//printIntervals(interval,num);
	cout<<"merged interval:"<<endl;
	printvector(ans);
	return 0;
}
