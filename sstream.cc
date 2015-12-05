#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	//string a="abc,bde,nsa";
	/*string a="1,2,3,4";
	istringstream ss(a);
	int token;
	while(getline(ss,token,','))//separate string if token is string if token is int don't work
	{
	
		cout<<token<<endl;
		cout<<"here"<<endl;
	
	}
	
	
	*/
	
	
	/*
	string a="abc$bde$ns";
	istringstream ss(a);
	string token;
	while(getline(ss,token,'$'))
	{
	
		cout<<token<<endl;
	}
	
	
	*/
	
	
	
	/*stringstream ss;
	ss.str("hiee,nupur");
	string a,b;
	ss>>a>>b;
	cout<<a<<" \n"<<b<<endl;*/
	char a=',';
	int value,ans[4];
	int max=4,count=0;
	while(max>count 	&& cin>>value>>a )
	{
		ans[count]=value;
		cout<<ans[count]<<endl;
		count++;
	}
	//ans[]
	return 0;
}
