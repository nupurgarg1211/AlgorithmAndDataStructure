#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int Tnum;
	cin>>Tnum;
	long long int input[Tnum]; 
	for(int i=0;i<Tnum;i++)
	{
		cin>>input[i];
	}
	priority_queue<long long int> PriorQueue;
	for(int i=0;i<Tnum;i++)
	{
		if(i<2)
		{
			cout<<"-1"<<endl;
			PriorQueue.push(input[i]);
			continue;
		}
		PriorQueue.push(input[i]);
		long long int firstL=PriorQueue.top();
		PriorQueue.pop();
		long long int secondL=PriorQueue.top();
		PriorQueue.pop();
		long long int thirdL=PriorQueue.top();
		PriorQueue.pop();
		PriorQueue.push(firstL);
		PriorQueue.push(secondL);
		PriorQueue.push(thirdL);
		cout<<firstL*secondL*thirdL<<endl;
		
	
	}
	return 0;
}
