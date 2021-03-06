#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Node
{
	int data;
	Node *next;
	public:
	Node(int val);
	int getData();
	void setData(int a);
	Node *getNext();
	void setNext(Node *a);
};
Node::Node(int val)
{
	data=val;
	next=NULL;

}
int Node:: getData()
{
	return data;

}
void Node:: setData(int a)
{
	data=a;
}
Node* Node::getNext()
{
	return next;
}
void Node::setNext(Node *a)
{
	next=a;
}
class LL
{
	Node *head;
	
	public:
	LL();
	Node *getHead();
	void setHead(Node * a);
	void insertNode(int a,int pos,Node * &head);
	void print(Node *head);
	void unionLL(Node *a,Node *b,Node * &res);
	void intersectionLL(Node *a,Node *b,Node * &res);
};
LL::LL()
{
	head=NULL;
}
Node *LL::getHead()
{
	return head;
	
}
void LL::setHead(Node * a)
{
	head=a;
}
void LL::insertNode(int a,int pos,Node * &head)
{
	Node * newNode=new Node(a);
	int count=1;
	if(head==NULL)
	{
		head=newNode;
	
	}
	else
	{
		Node * current=head;
		while(count!=pos-1)
		{
			count++;
			current=current->getNext();
		
		}
		newNode->setNext(current->getNext());
		current->setNext(newNode);
	
	}
}
void LL::print(Node *head)
{
	Node * current=head;
	while(current!=NULL)
	{
		cout<<current->getData()<<endl;
		current=current->getNext();
	}

}
void LL::unionLL(Node *a,Node *b,Node * &res)
{
	unordered_map <int,int> m;
	
	while(a!=NULL)
	{
		m[a->getData()]=1;
		a=a->getNext();
	
	}
	while(b!=NULL)
	{
		m[b->getData()]=1;
		b=b->getNext();
	
	}
	int i=1;
	for(unordered_map<int,int> ::iterator it=m.begin();it!=m.end();it++)
	{
		insertNode(it->first,i,res);
		i++;
	}
}
void LL::intersectionLL(Node *a,Node *b,Node * &res)
{
	unordered_map<int,int> m;
	while(a!=NULL)
	{
	
		m[a->getData()]=1;
		a=a->getNext();
	}
	int i=1;
	while(b!=NULL)
	{
		if(m[b->getData()]==1)
		{
			insertNode(b->getData(),i,res);
			i++;
		
		}
		b=b->getNext();
	
	}

}
int main()
{
	LL l;
	Node *head1=NULL,*head2=NULL,*res=NULL,*res1=NULL;
	l.insertNode(1,1,head1);	
	l.insertNode(2,2,head1);
	l.insertNode(3,3,head1);
	l.insertNode(4,4,head1);
	l.insertNode(5,5,head1);
	l.insertNode(6,6,head1);
	l.insertNode(1,1,head2);
	l.insertNode(2,2,head2);
	l.insertNode(3,3,head2);
	l.insertNode(4,4,head2);
	l.insertNode(5,5,head2);
	l.insertNode(6,6,head2);
	l.insertNode(7,7,head2);
	l.insertNode(8,8,head2);
	l.print(head1);
	cout<<"@@@"<<endl;
	l.print(head2);
	l.unionLL(head1,head2,res);
	cout<<"after union:"<<endl;
	l.print(res);
	
	l.intersectionLL(head1,head2,res1);
	cout<<"After Intersection:"<<endl;
	l.print(res1);
}
