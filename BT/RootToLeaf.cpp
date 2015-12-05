#include<iostream>
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
	void printBinaryTree(Node *root);
	bool rootToLeaf(Node *root,int sum);
	void printPaths(Node *node);
	void printArray(int path[],int size);
	void findRootToLeafPath(Node * node,int path[],int size);
	int LevelOrderSum(Node *node,int i);
	int getMaxWidth(Node *node);
	int getMax(int count[],int size);
	void MaxWidthR(Node *node,int count[],int level );
	int MaxWidth(Node * node);
	
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
void BinaryTree:: levelOrder(Node *node)
{
	int h=height(node);
	for(int i=1;i<=h;i++)
	{
		printLevelOrder(node,i);
		cout<<endl;
	
	}	
}
void  BinaryTree::printLevelOrder(Node *node,int i)
{
	if(node==NULL)
	{
		return;
	}
	else if(i==1)
	{
		cout<<node->getData()<<" ";
	}
	else
	{
		printLevelOrder(node->getLeft(),i-1);
		printLevelOrder(node->getRight(),i-1);
	}
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
bool BinaryTree:: rootToLeaf(Node *root,int sum)
{	
	bool l,r;
	if(root==NULL)
	return 0;
	if(root->getLeft()==NULL && root->getRight()==NULL&&sum==root->getData())
	return 1;
	else
	{
		int subsum=sum-root->getData();
		l=rootToLeaf(root->getLeft(),subsum);
		r=rootToLeaf(root->getRight(),subsum);
		if(l||r)
		return true;
		else false;
	
	}
}
void BinaryTree:: printPaths(Node *node)
{
	int paths[1000];
	findRootToLeafPath(node,paths,0);
	
}
void BinaryTree::printArray(int path[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<path[i]<<" ";
	
	}
	cout<<endl;
}
void BinaryTree::findRootToLeafPath(Node * node,int path[],int size)
{
	if(node==NULL)
	return;
	path[size]=node->getData();
	size++;
	if(node->getLeft()==NULL &&node ->getRight()==NULL)
	{
		
		printArray(path,size);
	}
	else
	{
		//if(node->getLeft()!=NULL)
		findRootToLeafPath(node->getLeft(),path,size);	
		//else if(node->getRight()!=NULL)
		findRootToLeafPath(node->getRight(),path,size);
	}
}
int BinaryTree::LevelOrderSum(Node *node,int i)
{
	if(node==NULL)
	{
		return 0;
	}
	else if(i==1)
	{
		return 1;
	}
	else
	{
		return LevelOrderSum(node->getLeft(),i-1)+LevelOrderSum(node->getRight(),i-1);
	}
}
int BinaryTree::getMaxWidth(Node *node)
{
	int h=height(node);
	int maxWidth=0,width;
	for(int i=1;i<=h;i++)
	{
		width=LevelOrderSum(node,i);
		if(maxWidth<width)
		maxWidth=width;
			
	}	
	return maxWidth;
}
int BinaryTree:: getMax(int count[],int size)
{
	int max=count[0];
	for(int i=0;i<size;i++)
	{
		if(max<count[i])
		max=count[i];
	
	}
	return max;
}
int BinaryTree::MaxWidth(Node * node)
{
	int h=height(node);
	
	int count[h];
	for(int i=0;i<h;i++)
	count[i]=0;
	//cout<<count[0]<<endl;
	MaxWidthR(node,count,0);
	
	return getMax(count,h);
	

}
void BinaryTree::MaxWidthR(Node *node,int count[],int level )
{
	if(node)
	{
		count[level]++;
		MaxWidthR(node->getLeft(),count,level+1 );
		MaxWidthR(node->getRight(),count,level+1 );
	
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
	//BT->printBinaryTree(BT->getRoot());
	BT->levelOrder(BT->getRoot());
	bool flag=BT->rootToLeaf(BT->getRoot(),11);
	if(flag)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
	
	BT->printPaths(BT->getRoot());
	cout<<BT->getMaxWidth(BT->getRoot())<<endl;
	cout<<"Max width in order n="<<BT->MaxWidth(BT->getRoot())<<endl;
	return 0;
}
