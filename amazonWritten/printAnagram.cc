#include<iostream>
using namespace std;
bool ifAnagram(string input1,string input2)
{
	for(int i=0;i<num;i++)
	{
		
	
	
	}
	
	int n1=input1.length();
	int n2=input2.length();
	if(n1!=n2)
	{
		return false;
	}
	else
	{
		int hash1[26],hash2[26];
		for(int i=0;i<26;i++)
		{
			hash1[i]=0;
			hash2[i]=0;
		}
		for(int i=0;i<n1;i++)
		{
			hash1[input1[i]-'a']+=1;
			hash2[input2[i]-'a']+=1;
			
		}
		for(int i=0;i<n1;i++)
		{
			if(hash1[i]!=hash2[i])
				return false;		
				
		}
	}
	return true;
}
int main()
{
	int num;
	cin>>num;
	string input[num];
	for(int i=0;i<num;i++)
	{
		cin>>input[i];
	
	}
	for(int i=0;i<num-1;i++)
	{
		bool flag=ifAnagram(input[i],input[i+1]); 
		
	}
	return 0;
} 
