#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<string>
#include<cstdlib>
#include<queue>
using namespace std;
int a[5];
int fillResult(queue<int> q1,queue<int> q2,queue<int> q3,int n)
{
	int i=0;
	
	while(!(q1.empty()))
	{
		a[i++]=q1.front();
		//cout<<a[i-1]<<endl;
		q1.pop();
	}
	//cout<<"here \n"<<endl;
	while(!(q2.empty()))
	{
		
		a[i++]=q2.front();
		//cout<<a[i-1]<<endl;
		q2.pop();
	}
	while(!(q3.empty()))
	{
		a[i++]=q3.front();
		//cout<<a[i-1]<<endl;
		q3.pop();	
	}
	//cout<<"in fillResult"<<endl;
	//i=i--;
	return i;
	
}
void printResult(int res[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<res[i];
	
	}

}
bool comp_desc(int i1,int i2)
{
	return (i1>i2);

}
bool largestMultipleOfThree(int *input,int size)
{
	queue <int> q1,q2,q3;
	int sum=0;
	sort(input,input+size);
	//cout<<"pushed elements:";
	for(int i=0;i<size;i++)
	{
		sum=sum+input[i];
		if(input[i]%3==0)
		{
			q1.push(input[i]);
			//cout<<input[i]<<endl;
		}
		else if (input[i]%3==1)
		{
			q2.push(input[i]);
			//cout<<input[i]<<endl;
		}
		else if(input[i]%3==2)
		{
			q3.push(input[i]);
			//cout<<input[i]<<endl;
		}
	}
	if(sum%3==1)
	{
		if(!(q2.empty()))
			q2.pop();
		else
		{
			if(!(q3.empty()))
				q3.pop();
			else	
			return 0;	
				
			if(!(q3.empty()))
				q3.pop();
			else
			return 0;
		
		}	
	
	}
	else if(sum%3==2)
	{
		if(!(q3.empty()))
			q3.pop();
		else
		{
			if(!(q2.empty()))
				q2.pop();
			else	
			return 0;	
				
			if(!(q2.empty()))
				q2.pop();
			else
			return 0;

		}	
	
	
	
	}
	//cout<<"in f()"<<endl;
	int n=fillResult(q1,q2,q3,size);
	//cout<<"<n="<<n<<endl;
	sort(a,a+n,comp_desc);
	printResult(a,n);
	return 1;
}



int main()
{
	int input[]={8,1,7,6,0};
	int n=(sizeof(input)/sizeof(input[0]));
	if(largestMultipleOfThree(input,n)==0)
	cout<<"No. not possible!!";		
	return 0;	
}
