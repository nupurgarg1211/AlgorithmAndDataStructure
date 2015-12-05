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
	int val;
	Node * next;
	public:
	Node();
	Node(int value);
	int getValue();
	Node * getNext();
	void setValue(int value);
	void setNext(Node * a);

};

Node::Node()
{
	next=NULL;
}
Node::Node(int value)
{
	val=value;
	next=NULL;
}
int Node::getValue()
{
	return val;
}
Node * Node:: getNext()
{
	return next;
}
void Node:: setValue(int value)
{
	val=value;
}
void Node:: setNext(Node * a)
{
	next=a;
}
class LinkedList
{
	Node *head;
	public:
	LinkedList();
	~LinkedList();
	Node *getHead();
	void setHead(Node *a);
	Node *insert(Node * &head,int val,int pos);
	void TraverseLL(Node *head);
	void AlternateSplitLL(Node * &a,Node * &b,Node *head);
	
	

};
LinkedList::LinkedList()
{
	head=NULL;
}
LinkedList::~LinkedList()
{
	delete head;
}
Node *LinkedList::getHead()
{
	return head;
}
void LinkedList:: setHead(Node *a)
{
	head=a;
}

Node * LinkedList::insert(Node * &head,int val,int pos)
{
	Node *current=head,*prev=NULL;
	Node *newNode=new Node(val);
	int k=1;
	if(pos==1)
	{
		newNode->setNext(head);
		head=newNode;
		
	}
	else
	{
		while(pos>k && current!=NULL)
		{
			prev=current;
			current=current->getNext();
			k++;	
	
		}
		newNode->setNext(current);
		prev->setNext(newNode);	
	}
	return head;	
}
void  LinkedList:: TraverseLL(Node *head)
{
	Node *current=head;
	if(current==NULL)
	cout<<"List is empty";
	else
	{
		while(current!=NULL)
		{
			cout<<current->getValue()<<endl;
			current=current->getNext();
	
		}
	}

}
void LinkedList:: AlternateSplitLL(Node * &a,Node * &b,Node *head)
{
	Node *current=head;
	//Node headNode1,headNode2;
	//a=headNode1->getNext();
	//b=headNode2->getNext();
	Node *tail1,*tail2;
	int i=1;
	if(current==NULL)
	return;
	else if(current->getNext()==NULL)
	return;
	else
	{
		tail1=current;
		a=current;
		tail2=current->getNext();
		b=tail2;
		current=current->getNext()->getNext();
	
	}
	while(current!=NULL)
	{
		if(i%2)
		{
			tail1->setNext(current);
			tail1=tail1->getNext();
						
		}
		else
		{
			tail2->setNext(current);
			tail2=tail2->getNext();	
		}
		current=current->getNext();
		i++;
	
	}
	
}
int main()
{
	LinkedList ll,ll2;
	Node *newHead=ll.getHead();
	ll.insert(newHead,0,1);
	ll.setHead(newHead);
	ll.insert(newHead,1,2);
	ll.setHead(newHead);
	ll.insert(newHead,0,3);
	ll.setHead(newHead);
	ll.insert(newHead,1,4);
	ll.setHead(newHead);
	ll.insert(newHead,0,5);
	ll.setHead(newHead);
	ll.insert(newHead,1,6);
	ll.setHead(newHead);
	ll.insert(newHead,0,7);
	ll.setHead(newHead);
	ll.insert(newHead,1,8);
	ll.setHead(newHead);
	ll.insert(newHead,0,9);
	ll.setHead(newHead);
	ll.insert(newHead,1,10);
	ll.setHead(newHead);
	ll.TraverseLL(ll.getHead());
	Node * a=NULL,*b=NULL;
	ll.AlternateSplitLL(a,b,ll.getHead());
	cout<<"1st list:"<<endl;
	ll.TraverseLL(a);
	cout<<"2nd list:"<<endl;
	ll.TraverseLL(b);
		
}
