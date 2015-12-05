#include<iostream>
#include<stack>
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
	Node * search(Node * node,int key);
	void Inorder(Node * node);
	Node * Delete(Node * node,int key);
	Node *getMaxNode(Node *node);
	void KthSmallestElement(Node * node,int k,stack<int> &s,int &flag);
	void printElementsInRange(Node * node,int left,int right);
	Node * RemoveKeyOutsideRange(Node * node,int left,int right);
	bool IsBST(Node * node,int min,int max);
	Node * AddChild(Node * node,int key);
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
Node * BST:: search(Node * node,int key)
{
	if(node=NULL)
	{
		return NULL;
	}
	if(node->getData()==key)
	{
		return node;
	
	}
	else if(key<=node->getData())
	return search(node->getLeft(),key);
	else if(key>node->getData())
	return search(node->getRight(),key);
}
void BST::Inorder(Node * node)
{
	if(node==NULL)
	return ;
	
	Inorder(node->getLeft());
	cout<<node->getData()<<endl;
	Inorder(node->getRight());
}
Node * BST::Delete(Node * node,int key)
{
	if(node==NULL)
	return NULL;
	if(node ->getData()==key)
	{
		
		 if(node->getLeft()==NULL)
		{
			Node * temp=node->getRight();
			delete node;
			
			return temp;
			
		
		}
		else if(node->getRight()==NULL)
		{
			Node * temp=node->getLeft();
			
			delete node;
			return temp;
		
		}
		else
		{
			Node * temp=getMaxNode(node->getRight());
			node->setData(temp->getData());
			node->setRight(Delete(node->getRight(),temp->getData()));
		}
	}
	
	
	if(node->getData()>key)
	{
		node->setLeft(Delete(node->getLeft(),key));
	
	}
	else if(node->getData()<key)
	{
	
		node->setRight(Delete(node->getRight(),key));
	}
	
}
Node * BST::getMaxNode(Node *node)
{
	Node * current=node;
	//int max=current->getData();
	if(current->getLeft()!=NULL)
	{
		current=current->getLeft();
		//cout<<"in max node"<<endl;
	
	}
	//cout<<"min val in subtree="<<current->getData()<<endl;
	return current;

}
void BST::KthSmallestElement(Node * node,int k,stack<int> &s,int &flag)
{
	
	if(node==NULL)
	return ;
	
	
	
	KthSmallestElement(node->getLeft(),k,s,flag);
	if(flag == 1)
	return ;
	s.push(node->getData());
	cout<<"pushing in the stack " << node->getData()<<endl;
	if(s.size()==k)
	{
		flag = 1;
		//cout<<"here";
		return ;
	
	}
	KthSmallestElement(node->getRight(),k,s,flag);
	

}
void BST::printElementsInRange(Node * node,int left,int right)
{
	
	if(node==NULL)
	return;
	printElementsInRange(node->getLeft(),left,right);
	if(node->getData()>=left && node->getData()<=right)
	cout<<node->getData()<<" ";
	printElementsInRange(node->getRight(),left,right);
}
Node * BST::RemoveKeyOutsideRange(Node * node,int left,int right)
{
	if(node==NULL)
	return NULL;
	node->setLeft(RemoveKeyOutsideRange(node->getLeft(),left,right));
	node->setRight(RemoveKeyOutsideRange(node->getRight(),left,right));
	if(node->getData()<left )
	{
		Node * temp=node->getRight();
		delete node;
		return temp;
	
	}
	else if( node->getData()>right)
	{
		Node * temp=node->getLeft();
		delete node;
		return temp;
	
	}
	
	
	return node;
	
	

}
bool BST:: IsBST(Node * node,int min,int max)
{
	bool l,r;
	if(node==NULL)
	return 1;
	l=IsBST(node->getLeft(),min,node->getData()-1);
	r=IsBST(node->getRight(),node->getData()+1,max);
	if(node->getData()>=min && node->getData()<=max)
	{
		return 1;
	}
	if(l && r)
	return 0;
	else
	return 1;
	
	
}

int main()
{
	stack<int> s;
	BST *bt=new BST(2);
	//Node * root;
	bt->setRoot(bt->insert(bt->getRoot(),45));
	bt->setRoot(bt->insert(bt->getRoot(),5));
	bt->setRoot(bt->insert(bt->getRoot(),7));
	bt->setRoot(bt->insert(bt->getRoot(),4));
	bt->setRoot(bt->insert(bt->getRoot(),3));
	bt->Inorder(bt->getRoot());
	int flag = 0;
	bt->KthSmallestElement(bt->getRoot(),6,s,flag);
	cout<<endl << "ans " <<  s.top() <<endl;
	
	bt->printElementsInRange(bt->getRoot(),80,90);
	
	//bt->setRoot(bt->RemoveKeyOutsideRange(bt->getRoot(),0,5));
	bt->Inorder(bt->getRoot());
	
	if(bt->IsBST(bt->getRoot(),INT_MIN,INT_MAX))
	cout<<"YES"<<endl;
	else 
	cout<<"NO"<<endl;
	
	return 0;
}
