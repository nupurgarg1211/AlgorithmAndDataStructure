#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<vector>
using namespace std;
int calculateSumOfAsciiValue(string a)
{
	int sum=0;
	for(int i=0;i<a.length();i++)
	{
		sum+=a[i];
	
	}
	return sum;

}
void hashUrl(string url[],int size,map<int, vector<string> > &hash)
{
	for(int i=0;i<size;i++)
	{
		int asciiSum=calculateSumOfAsciiValue(url[i]);
		hash[asciiSum%101].push_back(url[i]);
		//cout<<hash[asciiSum%101]
		
		
	}

}
int main()
{
	int numOfUrl=4;
	map<int, vector<string> > hash;
	string url[]={{"www.google.com"},{"abc"},{"abcd"},{"abc"}};
	int size=sizeof(url)/sizeof(url[0]);
	hashUrl(url,size,hash);
	//cout<<calculateSumOfAsciiValue(url[1])<<endl;
	for(map<int, vector<string> > :: iterator it1=hash.begin();it1)
	cout<<
	
	
	return 0;
}
