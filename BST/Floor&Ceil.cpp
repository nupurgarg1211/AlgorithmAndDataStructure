#include<iostream>
#include<climits>
using namespace std;
class Node
{
	int data;
	Node * left;
	Node * right;
	public:
	Node(int val);
	int getData();
	void setData(int val);
	Node * getLeft();
	void setLeft(Node * node);
	Node * getRight();
	void setRight(Node * node);
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
void Node::setData(int val)
{
	data=val;
}
Node * Node::getLeft()
{

	return left;
}
void Node::setLeft(Node * node)
{
	left=node;

}
Node * Node::getRight()
{
	return right;

}
void Node::setRight(Node * node)
{
	right=node;

}
class BST
{
	Node *root;
	public:
	BST(int val);
	void setRoot(Node * node);
	Node *getRoot();
	Node * insert(Node * node,int key);
	void Inorder(Node * node);
	int Ceil(Node * node,int key);
	int Floor(Node * node ,int key);
	
};


BST::BST(int val)
{
	Node *newNode=new Node(val);
	root=newNode;
	root->setLeft(NULL);
	root->setRight(NULL);
	//root->setData(val);
}
void BST:: setRoot(Node * a)
{
	root=a;

}
Node * BST::getRoot()
{
	return root;

}

Node * BST::insert(Node * node,int key)
{
	if(node==NULL)
	{
		Node *newNode=new Node(key);
		return newNode;
	}
	else if(key<=node->getData())
	{
		node->setLeft(insert(node->getLeft(),key));
	
	}
	else if(key>node->getData())
	{
		node->setRight(insert(node->getRight(),key));
	
	}
	return node;
}

void BST::Inorder(Node * node)
{
	if(node==NULL)
	return ;
	
	Inorder(node->getLeft());
	cout<<node->getData()<<endl;
	Inorder(node->getRight());
}
int BST::Ceil(Node * node,int key)
{
	if(node==NULL)
	return INT_MIN;
	if(node->getData()==key)
	return key;
	if(node->getData()<key)
	{
		return Ceil(node->getRight(),key); 
	
	}
	else
	{
		int ans=Ceil(node->getLeft(),key);
		if(ans<key)
		return node->getData();
		else
		return ans;
	}
	
}
int BST::Floor(Node * node ,int key)
{
	if(node==NULL)
	return INT_MAX;
	if(node->getData()==key)
	return key;
	if(node->getData()>key)
	{
		return Floor(node->getLeft(),key); 
	
	}
	else
	{
		int ans=Floor(node->getRight(),key);
		if(ans>key)
		return node->getData();
		else
		return ans;
	}

}
int main()
{
	int key;
	BST *bt=new BST(2);
	//Node * root;
	bt->setRoot(bt->insert(bt->getRoot(),45));
	bt->setRoot(bt->insert(bt->getRoot(),5));
	bt->setRoot(bt->insert(bt->getRoot(),7));
	bt->setRoot(bt->insert(bt->getRoot(),4));
	bt->setRoot(bt->insert(bt->getRoot(),3));
	bt->Inorder(bt->getRoot());
	cin>>key;
	cout<<bt->Ceil(bt->getRoot(),key)<<endl;
	cin>>key;
	cout<<bt->Floor(bt->getRoot(),key)<<endl;
	return 0;
}
