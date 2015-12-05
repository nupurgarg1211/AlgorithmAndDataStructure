#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int> &s,int temp)
{
	if(!s.empty())
	{
		int a=s.top();
		s.pop();
		insertAtBottom(s,temp);
		s.push(a);
	}
	else
	s.push(temp);
}
void reverse(stack <int> &s)
{
	if(!s.empty())
	{
		int temp=s.top();
		s.pop();
		reverse(s);
		insertAtBottom(s,temp);
		
	}
	
	
}
int main()
{
	stack<int> s;	
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	cout<<s.top()<<endl;
	reverse(s);
	cout<<"after reverse top="<<s.top()<<endl;
	return 0;
}
