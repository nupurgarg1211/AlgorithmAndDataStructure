#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
class QNode
{
	int data;
	QNode * next;
	public:
	QNode(int d);
	int getData();
	void setData(int a);
	QNode * getNext();
	void setNext(QNode * a);

};
QNode::QNode(int d)
{
	data=d;
	next=NULL;
}
int QNode:: getData()
{
	return data;
}
void QNode::setData(int a)
{
	data=a;
}
QNode * QNode:: getNext()
{
	return next;
}
void QNode:: setNext(QNode * a)
{
	next=a;

}
class Node
{
	int data;
	Node * left;
	Node * right;
	public:
	Node(int d);
	int getData();
	void setData(int a);
	Node * getLeft();
	void setLeft(Node * a);
	Node * getRight();
	void setRight(Node * a);

};
Node::Node(int d)
{
	data=d;
	left=NULL;
	right=NULL;
}
int Node:: getData()
{
	return data;
}
void Node::setData(int a)
{
	data=a;
}
Node * Node:: getLeft()
{
	return left;
}
void Node:: setLeft(Node * a)
{
	left=a;

}
Node * Node:: getRight()
{
	return right;
}
void Node:: setRight(Node * a)
{
	right=a;

}
class Queue
{
	QNode *front,*rear;
	int capacity,size;
	public:
	Queue();
	//Queue(int c);
	QNode *getFront();
	QNode *getRear();
	
	int getSize();
	void setFront(QNode *f);
	void setRear(QNode *r);
	//void setCapacity(int c);
	void setSize(int s);
	void enqueue(int data);
	void Traverse();
	int dequeue();
	
	bool isEmpty();
};
Queue::Queue()
{
	front=NULL;
	rear=NULL;
}

QNode *Queue::getFront()
{
	return front;
}
QNode *Queue::getRear()
{
	return rear;
}
//int Queue::getCapacity();
int Queue:: getSize()
{
	return size;
}
void Queue::setFront(QNode *f)
{
	front=f;

}
void Queue::setRear(QNode *r)
{
	rear=r;
	
}
//void Queue::setCapacity(int c);
void Queue::setSize(int s)
{
	size = s;
}
void Queue::enqueue(int data)
{
	QNode *newNode=new QNode(data);
	if(front==NULL||rear==NULL)
	{
		front=newNode;
		rear=newNode;	
	}
	
	else
	{
		rear->setNext(newNode);
		rear=rear->getNext();
	}
	

}
int Queue::dequeue()
{
	if(isEmpty())
	return -1;
	
	QNode * temp=front;
	int a=temp->getData();
	front=front->getNext();
	delete temp;
	return a;

}

bool Queue::isEmpty()
{
	if(front==NULL )
	return 1;
	else 
	return 0;
}
void Queue::Traverse()
{
	
	QNode * current=front;
	while(current!=NULL)
	{
		cout<<current->getData()<<endl;
		current=current->getNext();
	}

}
class BinaryTree
{
	Node * root;
	public:
	BinaryTree(int val);
	Node *getRoot();
	void setRoot(Node * a);
	void AddChild(Node * root,string childType,int val);	
	bool CheckCompleteBinaryTree(Node *root);
	void printBinaryTree(Node *root);

};
BinaryTree::BinaryTree(int val)
{
	Node *newNode=new Node(val);
	root=newNode;
	root->setLeft(NULL);
	root->setRight(NULL);
	//root->setData(val);
}
void BinaryTree:: setRoot(Node * a)
{
	root=a;

}
Node * BinaryTree::getRoot()
{
	return root;

}
void  BinaryTree::AddChild(Node * root,string childType,int val)
{
	Node * newNode=new Node(val);
	if(childType.compare("left")==0)
	root->setLeft(newNode);
	else if(childType.compare("right")==0)
	root->setRight(newNode);
	else 
	cout<<"Wrong childtype"<<endl;
}	
bool BinaryTree:: CheckCompleteBinaryTree(Node *root)
{
	if(root==NULL)
	return 1;
	Queue *q=new Queue();
	q->enqueue(root->getData());
	while(!(q->isEmpty()))
	{
		
	
	}

}
void BinaryTree:: printBinaryTree(Node *root)
{
	if(root==NULL)
	return;
	else
	{
		cout<<root->getData()<<endl;
		printBinaryTree(root->getLeft());
		printBinaryTree(root->getRight());
	
	}

}
int main()

{
	BinaryTree * BT=new BinaryTree(1);
	BT->AddChild(BT->getRoot(),"left",2);
	BT->AddChild(BT->getRoot(),"right",3);
	BT->AddChild(BT->getRoot()->getLeft(),"left",4);
	BT->AddChild(BT->getRoot()->getLeft(),"right",5);
	BT->AddChild(BT->getRoot()->getRight(),"left",6);
	BT->printBinaryTree(BT->getRoot());
	//Queue q;
	
	
	
				
	return 0;	
}
