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
int main()
{
	BST *bt=new BST(2);
	//Node * root;
	bt->setRoot(bt->insert(bt->getRoot(),45));
	bt->setRoot(bt->insert(bt->getRoot(),5));
	bt->setRoot(bt->insert(bt->getRoot(),7));
	bt->setRoot(bt->insert(bt->getRoot(),4));
	bt->setRoot(bt->insert(bt->getRoot(),3));
	bt->Inorder(bt->getRoot());
	bt->Delete(bt->getRoot(),5);
	cout<<"after deletion"<<endl;
	bt->Inorder(bt->getRoot());
	
	return 0;
}
