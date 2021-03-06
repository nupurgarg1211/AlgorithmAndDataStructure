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
class BinaryTree
{
	Node *root;
	public:
	BinaryTree(int val);
	void setRoot(Node * node);
	Node *getRoot();
	void AddChild(Node * root,string childType,int val);
	void levelOrder(Node *node);
	int height(Node *node);
	void printLevelOrder(Node *node,int i);
	void printkDistantNode(Node *node,int k);
	bool IsBST(Node * node,int min,int max);
	
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



int BinaryTree::height(Node *node)
{
	int lheight=0,rheight=0;
	if(node==NULL)
	return 0;
	else if(node->getLeft()==NULL && node->getRight()==NULL)
	return 1;
	else
	{
		lheight=height(node->getLeft());
		rheight=height(node->getRight());
		if(lheight>rheight)
		return lheight+1;
		else
		return rheight+1;	
	
	}

}
void BinaryTree:: printkDistantNode(Node *node,int k)
{
	if(node == NULL)
	return ;
	if(k==0)
	{
		cout<<node->getData()<<endl;
	}	
	else
	{
		
		printkDistantNode(node->getLeft(),k-1);
		printkDistantNode(node->getRight(),k-1);	
	}
}
bool BinaryTree:: IsBST(Node * node,int min,int max)
{
	bool l,r;
	if(node==NULL)
	return 1;
	l=IsBST(node->getLeft(),min,node->getData()-1);
	r=IsBST(node->getRight(),node->getData()+1,max);
	if(node->getData()>=min && node->getData()<=max && l && r)
	{
		return 1;
	}
	else
		return 0;
	
	
}

int main()
{
	BinaryTree * BT=new BinaryTree(2);
	BT->AddChild(BT->getRoot(),"left",1);
	BT->AddChild(BT->getRoot(),"right",3);
	BT->AddChild(BT->getRoot()->getLeft(),"left",4);
	BT->AddChild(BT->getRoot()->getLeft(),"right",5);
	BT->AddChild(BT->getRoot()->getRight(),"left",6);
	//BT->printBinaryTree(BT->getRoot());
	//BT->levelOrder(BT->getRoot());
	BT->printkDistantNode(BT->getRoot(),2);
	if(BT->IsBST(BT->getRoot(),INT_MIN,INT_MAX))
	cout<<"YES"<<endl;
	else 
	cout<<"NO"<<endl;
	
	return 0;
}
