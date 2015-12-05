#include<iostream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string a="45 3 2#45 5 8",Q,P,b;
	
	istringstream ss(a);
	int flag=1,token;
	vector<int> Qu,Pr;
	while(getline(ss,b,'#'))
	{
		if(flag)
		{
			Q=b;
			flag=0;
			cout<<Q<<endl;
		}
		else
		{
			P=b;
			cout<<P<<endl;
		}
		
	
	}
	istringstream ss1(P);
	istringstream ss2(Q);
	while(ss1>>token)
	{
		//cout<<token<<endl;
		Qu.push_back(token);
	}
	//ss>>P;
	while(ss2>>token)
	{
		//cout<<token<<endl;
		Pr.push_back(token);
	}
	for(int i=0;i<3;i++)
	{
		cout<<Qu[i]<<" "<<Pr[i]<<endl;
	}
	return 0;
}

