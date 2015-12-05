/*Given an unsorted array that may contain duplicates. Also given a number k which is smaller than size of array. Write a function that returns true if array contains duplicates within k distance.

Examples:

Input: k = 3, arr[] = {1, 2, 3, 4, 1, 2, 3, 4}
Output: false
All duplicates are more than k distance away.*/

#include<iostream>
#include<vector>
#include<cstdlib>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int a[]={1, 2, 3, 1, 4, 5};
	int k,n;
	n=sizeof(a)/sizeof(a[0]);
	cin>>k;
	unordered_map<int,int> hash;
	for(int i=0;i<n;i++)
	{
		if(hash[a[i]]==1)
		{
			cout<<"yes"<<endl;
			exit(0);
		
		}
		else
		{
			hash[a[i]]=1;
			if(i>=k)
			{
				//hash[a[i-k]]=0;
				hash.erase(a[i-k]);
			}
		
		
		}
	
	
	}
	cout<<"No"<<endl;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//map<int ,vector<int> > hash;
	/*int hash[1000000];
	for(int i=0;i<n;i++)
	{
		if(hash[a[i]]==1)
		{
			cout<<"YES"<<endl;
			exit(0);
		}
		else
		{		
			hash[a[i]]=1;
			//count++;
			if(i>=k)
			{
				hash[a[i-k]]=0;
			}
		}	
	
	}
	cout<<"NO"<<endl;*/
	return 0;
}
