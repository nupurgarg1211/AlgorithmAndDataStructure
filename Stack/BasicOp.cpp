#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;

class Node
{
	int data;
	Node * next;
	public:
	Node();
	Node(int val);
	int getData();
	Node * getNext();
	void setData(int val);
	void setNext(Node *a);
	
};
Node::Node()
{
	next=NULL;
}
Node::Node(int val)
{
	data=val;
	next=NULL;
}
int Node::getData()
{
	return data;
}
Node * Node::getNext()
{

	return next;
}
void Node::setData(int val)
{
	data=val;
}
void Node::setNext(Node *a)
{
	next=a;
}
class Stack
{
	Node * top;
	int size;
	public:
	Stack();
	Node *getTop();
	int getSize();
	void setTop(Node *a);
	void push(int val);
	int pop();
	bool IsEmpty();
	string infixTOPostfix(string infix);
	void NextGreaterElement(int a[]);
	void Span(int n,int price[],int S[]);
	//bool IsFull();
	
};
Stack::Stack()
{
	top=NULL;
	size=0;

}
Node * Stack::getTop()
{
	return top;
}
int Stack::getSize()
{
	return size;
}
void Stack:: setTop(Node *a)
{
	top=a;
}
void Stack::push(int val)
{
	Node *current=new Node(val);
	current->setNext(top);
	top=current;
	size++;
		
}
int Stack::pop()
{
	Node * temp;
	int data;
	if(IsEmpty())
	{
		cout<<"stack is empty"<<endl;
		return -1;
	}
	else
	{
		temp=top;
		data=temp->getData();
		top=top->getNext();
		size--;
		delete temp;
		return data;
	}

}
bool Stack::IsEmpty()
{
	if(top==NULL)
	return 1;
	else
	return 0;

}
//bool Stack::IsFull();
string Stack:: infixTOPostfix(string infix)
{
	string postfix="";
	for(int i=0;i<infix.size();i++)
	{
		if(isdigit(infix[i]))
		{
			postfix=postfix+infix[i];
		}
		else if(infix[i]=='*'||infix[i]=='/'||infix[i]=='%')
		{
			
		
		}
		else if(infix[i]=='+'||infix[i]=='-')
		{
		
		
		}
	
	}

}
void Stack::NextGreaterElement(int a[])
{
	push(a[0]);
	int next,prev;
	int flag=0;
	for(int i=1;i<4;i++)
	{
		next=a[i];
		//cout<<"in for";
		while(!IsEmpty())
		{
			prev=pop();
			//cout<<prev;
			while(prev<next)
			{
				cout<<prev<<" "<<next<<endl;
				if(IsEmpty())
				{
					push(next);
					flag=1;
					break;
				
				}
				
				prev=pop();
			}
			if(flag==1)
			{
				flag=0;
				break;
			}
			if(prev>next)
			{
				//cout<<"aaaa";
				push(prev);
				push(next);
				break;
			}
		
		}
	
	
	}
	while(!IsEmpty())
	{
		int a=pop();
		//cout<<"here";
		cout<<a<<" "<<-1<<endl;
	
	}
}
void Stack:: Span(int n,int price[],int S[])
{
	S[0]=1;
	//Stack st;
	push(price[0]);
	int flag=0;
	for(int i=1;i<n;i++)
	{
		//int a=pop();
		flag=0;
		while(!IsEmpty()&&top->getData()<price[i])
		{
			int a=pop();
			cout<<"a="<<a<<"i="<<i<<endl;
			flag=1;
		}
		//push(a);
		if(flag==0)
		{
			S[i]=1;
			
		}
		else if(IsEmpty())
		{
			S[i]=i+1;
			//cout<<i<<"i+1"<<endl;
		}
		else
		S[i]=i-size+1;
		
		push(price[i]);
	}
	for(int i=0;i<n;i++)
	cout<<S[i]<<endl;
}
int main()
{
	Stack st;
	//int a[]={4,5,2,25};
	int price[]={100,80,60,70,60,75,85};
	int S[7];
	st.Span(7,price,S);
	/*
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	int a=st.pop();
	cout<<a<<endl;	
	a=st.pop();
	cout<<a<<endl;
	//String infix;
	//cin>>infix;
	//String postfix=st.infixTOPostfix(infix);
	//cout<<postfix;*/
	//st.NextGreaterElement(a);
	/*a=st.pop();
	cout<<a<<endl;	
	a=st.pop();
	cout<<a<<endl;
	a=st.pop();
	cout<<a<<endl;
	a=st.pop();
	cout<<a<<endl;
	a=st.pop();
	cout<<a<<endl;*/
	return 0;	
}
