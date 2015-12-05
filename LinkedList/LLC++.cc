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
	Node *next;
	public:
	Node();
	Node(int val);
	~Node();
	void setValue(int value);
	void setNext(Node *next);
	Node* getNext();
	int getValue();
	
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
Node::~Node()
{
	delete next;
}
void Node:: setValue(int value)
{
	val=value;
}
void Node:: setNext(Node *next1)
{

	next=next1;

}
int Node:: getValue()
{
	return val;

}
Node* Node:: getNext()
{

	return next;
}
class LinkedList
{
	
	public:
	Node *head;
	LinkedList();
	~LinkedList();
	Node* insert(int val,int pos);
	void TraverseLL();
	void deleteNode(int pos);
	void deleteLL();
	int countElementsOfLL();
	void reverseLL();
	Node * recursivereverseLL(Node *head);
	int findLoopAnditslength();
	Node* pairwiseswap(Node *head);
	void moveLastNodeToFirstNode();
	void removeDuplicate(int size);
	Node * intersectTwoSortedListR(Node *a,Node *b);
	LinkedList * intersectTwoSortedList(Node *a,Node *b);
	void deletealt();

};
LinkedList::LinkedList()
{
	head=NULL;
}
LinkedList::~LinkedList()
{
	delete head;
}
Node* LinkedList:: insert(int val,int pos)
{
	int k=1;
	Node *current=head;
	Node * prev=NULL;
	Node * newNode=new Node(val);
	if(head==NULL)
	{
		head=newNode;
		cout<<"here";
	}
	else if(pos==1)
	{
		newNode->setNext(head);
		head=newNode;
	
	}
	else
	{
		while(pos>k && current!=NULL)
		{
			k++;
			prev=current;
			current=current->getNext();
		}
		
		newNode->setNext(prev->getNext());
		prev->setNext(newNode);
	
	}
}
void LinkedList:: TraverseLL()
{
	Node * current=new Node();
	current=head;
	if(head==NULL)
	{
		cout<<"Empty List!!";
		return;
	
	}
	while(current!=NULL)
	{
		cout<<"node="<<current->getValue()<<endl;
		current=current->getNext();
	
	}
}
void LinkedList::deleteNode(int pos)
{
	Node* prev=NULL,*current=head;
	int k=1;
	if(head==NULL)
	{
		cout<<"List is Empty!!"<<endl;
		return;
	} 
	if(pos==1)
	{
		head=current->getNext();
		delete current;
		return;
	
	}
	while(pos>k && current!=NULL)
	{
		k++;
		prev=current;
		current=current->getNext();
		
	}
	prev->setNext(current->getNext());
	//delete current;
	

}
void LinkedList::deleteLL()
{
	Node * current=head;
	
	while(current!=NULL)
	{
		head=current->getNext();
		delete current;
		current=head;
		
	}
}
int LinkedList::countElementsOfLL()
{
	Node * current=head;
	int count=0;
	while(current!=NULL)
	{
		count++;
		current=current->getNext();
	}
	return count;
}
void LinkedList::reverseLL()
{
	Node * prev=NULL,*nextNode=NULL;
	while(head)
	{
		nextNode=head->getNext();
		head->setNext(prev);
		prev=head;
		head=nextNode;
	}
	head=prev;
	
}

Node * LinkedList::recursivereverseLL(Node *head)
{
	
	Node *nextNode=NULL;
	if(head==NULL)
	return NULL;
	if(head->getNext()==NULL)
	{
		return head;
	}
	
	nextNode=(head->getNext());
	head->setNext(NULL);
	Node * reverseRest=recursivereverseLL(nextNode);
	nextNode->setNext(head);
	return reverseRest;
	
	
	
}
int LinkedList::findLoopAnditslength()
{
	Node* fastptr=head,*slowptr=head;
	bool loopexists=0;
	int count=0;
	while( slowptr ||fastptr||fastptr->getNext())
	{
		fastptr=fastptr->getNext()->getNext();
		slowptr=slowptr->getNext();
		if(fastptr==slowptr)
		{
			loopexists=1;
			break;
		}
	}
	if(loopexists)
	{
		fastptr=fastptr->getNext();
		while(slowptr!=fastptr)
		{
			fastptr=fastptr->getNext();
			count++;
		
		}
	
	}
	return count;
}
Node* LinkedList:: pairwiseswap(Node *head)
{
	if(head==NULL ||head->getNext()==NULL)
	{
		return head;
	}
	Node * remaining=head->getNext()->getNext();
	Node * newHead=head->getNext();
	newHead->setNext(head);
	//head->getNext()->setNext(head);
	head->setNext(pairwiseswap(remaining));
	return newHead;
	

}

void LinkedList:: moveLastNodeToFirstNode()
{
	Node* current=head,*prev=NULL;
	while(current->getNext()!=NULL)
	{
		prev=current;
		current=current->getNext();
	}
	prev->setNext(NULL);
	current->setNext(head);
	head=current;
}
void LinkedList:: removeDuplicate(int size)
{
	Node *current=head,*prev;
	int LLHash[size];
	while(current!=NULL)
	{
		if(LLHash[current->getValue()]==1)
		{
			if(current->getNext()!=NULL)
			prev->setNext(current->getNext());
			else
			prev->setNext(NULL);
			
		}
		else
		{
			LLHash[current->getValue()]=1;
			prev=current;
		}
		current=current->getNext();
	}
}
Node * LinkedList:: intersectTwoSortedListR(Node *a,Node *b)
{
	if(a==NULL ||b==NULL)
	return NULL;
	if(a->getValue()<b->getValue())
	return intersectTwoSortedListR(a->getNext(),b);
	if(a->getValue()>b->getValue())
	return intersectTwoSortedListR(a,b->getNext());
	Node *newHead=new Node();
	newHead->setValue(a->getValue());
	newHead->setNext(intersectTwoSortedListR(a->getNext(),b->getNext()));
	return newHead;
}
LinkedList * LinkedList::intersectTwoSortedList(Node *a,Node *b)
{
	LinkedList *newList=new LinkedList();
	int i=1;
	while(a!=NULL ||b!=NULL)
	{
		if(a->getValue()==b->getValue())
		{
			newList->insert(a->getValue(),i);
			i++;
			a=a->getNext();
			b=b->getNext();
		}
		else if(a->getValue()<b->getValue())
		a=a->getNext();
		else
		b=b->getNext();
	}
	return newList;

}
void LinkedList:: deletealt()
{
	Node * current=head->getNext(),*prev=head;
	while(current!=NULL && prev!=NULL)
	{
		prev->setNext(current->getNext());
		
		prev=prev->getNext();
		if(prev!=NULL)
		current=prev->getNext();
		
	}

}
main()
{
	LinkedList ll;
	ll.insert(5,1);
	ll.insert(6,2);
	ll.insert(4,1);
	ll.insert(7,4);
	ll.insert(8,5);
	ll.insert(9,6);
	ll.insert(5,6);
	ll.insert(4,7);
	ll.insert(4,6);
	ll.insert(5,3);
	ll.insert(9,2);
	
	//ll.deleteNode(2);
	//ll.deleteLL();
	ll.TraverseLL();
	cout<<"No. of elements in LL= "<<ll.countElementsOfLL()<<endl;
	ll.reverseLL();
	ll.TraverseLL();
	ll.head=ll.recursivereverseLL(ll.head);
	ll.TraverseLL();
	ll.head=ll.pairwiseswap(ll.head);
	cout<<"pairwise swap :"<<endl;
	ll.TraverseLL();
	ll.moveLastNodeToFirstNode();
	cout<<"after moving last node to first place";
	ll.TraverseLL();
	cout<<"after removing duplicate nodes";
	ll.removeDuplicate(ll.countElementsOfLL());
	ll.TraverseLL();
	cout<<"Merging 2 sorted list";
	LinkedList a;
	LinkedList b;
	for(int i=1;i<7;i++)
	a.insert(i,i);
	
	b.insert(2,1);
	b.insert(4,2);
	b.insert(6,3);
	
	//ll.head=ll.intersectTwoSortedListR(a.head,b.head);
	//ll.TraverseLL();
	
	LinkedList *list=ll.intersectTwoSortedList(a.head,b.head);
	list->TraverseLL();
	cout<<"Before deleting alt:"<<endl;
	ll.TraverseLL();
	cout<<"deleting alternate"<<endl;
	ll.deletealt();
	ll.TraverseLL();
	

}
