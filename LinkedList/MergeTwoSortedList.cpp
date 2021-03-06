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
	Node *insert(Node *head,int val,int pos);
	void TraverseLL(Node *head);
	Node *MergeTwoSortedList(Node *list1,Node *list2);
	Node *MergeTwoSortedListI(Node *list1,Node *list2);
	

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

Node * LinkedList::insert(Node *head,int val,int pos)
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
Node * LinkedList::MergeTwoSortedList(Node *list1,Node *list2)
{
	Node *newHead=new Node();
	Node *secondNode;
	if(list1==NULL)
	{
		newHead=list2;
		return newHead;
	}
	if(list2==NULL)
	{
		newHead=list1;
		return newHead;
	}
	else if(list1->getValue()<list2->getValue())
	{
		newHead=list1;
		secondNode=MergeTwoSortedList(list1->getNext(),list2);	
	
	}
	else
	{
		newHead=list2;
		secondNode=MergeTwoSortedList(list1,list2->getNext());	
	}
	newHead->setNext(secondNode);
	return newHead;
}
Node * LinkedList::MergeTwoSortedListI(Node *list1,Node *list2)
{
	Node newNode;
	Node *tail=&newNode;
	if(list1==NULL)
	{
		tail=list2;
		return tail;
	}
	else if(list2==NULL)
	{
		tail=list1;
		return tail;
	}
	while(list1!=NULL && list2!=NULL)
	{
		if(list1->getValue()<list2->getValue())
		{
			tail->setNext(list1);
			tail=tail->getNext();
			list1=list1->getNext();
	
		}
		else
		{
			tail->setNext(list2);
			tail=tail->getNext();
			list2=list2->getNext();
		}
	}
	
	if(list1==NULL && list2!=NULL)
	{
	
		tail->setNext(list2);
	}
	else if(list2==NULL &&list1!=NULL)
	{
	
		tail->setNext(list1);
	}
	return (newNode.getNext());
}
int main()
{
	LinkedList ll,ll2;
	Node *newHead;
	newHead=ll.insert(ll.getHead(),1,1);
	ll.setHead(newHead);
	newHead=ll.insert(ll.getHead(),4,2);
	ll.setHead(newHead);
	newHead=ll.insert(ll.getHead(),7,3);
	ll.setHead(newHead);
	newHead=ll.insert(ll.getHead(),9,4);
	ll.setHead(newHead);
	ll.TraverseLL(ll.getHead());
	cout<<"LL2-"<<endl;
	newHead=ll2.insert(ll2.getHead(),2,1);
	ll2.setHead(newHead);
	newHead=ll2.insert(ll2.getHead(),3,2);
	ll2.setHead(newHead);
	newHead=ll2.insert(ll2.getHead(),6,3);
	ll2.setHead(newHead);
	newHead=ll2.insert(ll2.getHead(),14,4);
	ll2.setHead(newHead);
	newHead=ll2.insert(ll2.getHead(),16,5);
	ll2.setHead(newHead);
	newHead=ll2.insert(ll2.getHead(),20,6);
	ll2.setHead(newHead);
	ll2.TraverseLL(ll2.getHead());
	
	cout<<"ll after merging"<<endl;
	newHead=ll.MergeTwoSortedListI(ll.getHead(),ll2.getHead());
	ll2.TraverseLL(newHead);
	return 0;	
}
