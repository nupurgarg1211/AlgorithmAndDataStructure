#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<int> ans)
{
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<endl;
	}
	
}
int main()
{
	int a[]={2,3,4,6,9};
	int b[]={4,6,8,10};
	int size1=sizeof(a)/sizeof(a[0]);
	int size2=sizeof(b)/sizeof(b[0]);
	vector <int> ans;
	int i=0,j=0;
	while(i<size1 && j<size2)
	{
		if(a[i]==b[j])
		{
			ans.push_back(a[i]);
			i++;
			j++;
		}
		else if(a[i]<b[j])
		{
			//ans.push_back(a[i]);
			i++;
		
		}
		else
		{
			//ans.push_back(b[j]);
			j++;	
		
		}
	}
	
	while(i<size1)
	{
		//ans.push_back(a[i]);
		i++;
	}
	
	while(j<size2)
	{
		//ans.push_back(b[j]);
		j++;	
	}
	
	printArray(ans);
	//while()
	
	return 0;
}
