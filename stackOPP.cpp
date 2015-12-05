#include<iostream>
using namespace std;
class Node
{
	int data;
	Node *left,*right;
	public :
	Node(int val);
	int getData();
	void setData(int a);
	Node *getLeft();
	Node* getRight();
	void setLeft(Node * a);
	void setRight(Node *a);

};
Node::Node(int val)
{
	data=val;
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
Node * Node::getLeft()
{

	return left;
}
Node* Node::getRight()
{
	return right;
}
void Node::setLeft(Node * a)
{
	left=a;
}
void Node::setRight(Node *a)
{
	right=a;

}
class Stack
{
	Node * top;
	int size;
	Node * mid;
	
	public :
	Stack();
	void push(int val);
	int pop();
	int getMiddle();
	void deleteMiddle();
	//void setMiddle();
	void print();
	
	

};
Stack::Stack()
{
	top=NULL;
	size=0;
	mid=NULL;

}
void Stack::push(int val)
{
	Node * newNode=new Node(val);
	if(top==NULL)
	{
		top=newNode;
		mid=newNode;
		return;
	
	}
	else
	{
	
		top->setRight(newNode);
		newNode->setLeft(top);
		top=newNode;
	
	}
	size++;
	if(size%2!=0 &&size !=1)
	mid=mid->getRight();
	
	
	
}
int Stack::pop()
{
	if(top!=NULL)
	{
		int a=top->getData();
		Node *temp=top;
		top=top->getLeft();
		size--;
		if(size%2!=0)
		{
			mid->setLeft(mid);
		}
		
		delete temp;
		return a;
	}
}
int Stack::getMiddle()
{
	return mid->getData();	

}
void Stack::deleteMiddle()
{

	
	Node * temp=mid;
	if(size%2==0)
	{
		mid=mid->getLeft();
		mid->setRight(temp->getRight());
		temp->getRight()->setLeft(mid);
	}
	else
	{
		mid=mid->getRight();
		mid->setLeft(temp->getLeft());
		temp->getLeft()->setRight(mid);
	
	}
	size--;
	delete temp;
}

void Stack::print()
{
	Node * current=top;
	while(current!=NULL)
	{
		
		cout<<current->getData()<<endl;	
		current=current->getLeft();
	}
	
} 
int main()
{
	Stack s;
	s.push(5);	
	s.push(6);	
	s.push(2);	
	s.push(1);	
	s.push(3);	
	s.push(4);
	
	cout<<"Middle="<<s.getMiddle()<<endl;
	s.deleteMiddle();
	cout<<"Middle="<<s.getMiddle()<<endl;
	s.print();	
}



