#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	string s;
	getline(cin,s);	
	int a=0;
	//cout<<s<<endl;
	for(int i=0;i<s.length();i++)
	{
		
		if(s[i]>='A' && s[i]<='Z')
		{
			
			//cout<<(a ^ (1<<(s[i]-'A')))<<endl;
			if((a & (1<<(s[i]-'A')))==0)
			{	
				a=a ^ (1<<(s[i]-'A'));
				//cout<<"here"<<endl;
			}
		
		}
		else if(s[i]>='a' && s[i]<='z')
		{
			//cout<<s[i]<<endl;
			if((a & (1<<(s[i]-'a')))==0)
			{
				a=a ^ (1<<(s[i]-'a'));	
				//cout<<"here11"<<endl;
			}	
		}
		
	}
	//cout<<a<<endl;
	//cout<<pow(2,26)-1<<endl;
	if(a==(pow(2,26)-1))
	{
		cout<<"pangram"<<endl;
	}
	else
		cout<<"not pangram"<<endl;
	return 0;
}
