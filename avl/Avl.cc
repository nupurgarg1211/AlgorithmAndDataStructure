#include<iostream>
using namespace std;
class Tree
{
	int data;
	int height;
	Tree *left,*right;
	public:
	Tree(int key,int h);
	int getData();
	int getHeight();
	void setData(int key);
	void setHeight(int h);
	Tree *getLeft();
	Tree *getRight();
	void setLeft(Tree *node);
	void setRight(Tree *node);
	Tree *insert(int key,Tree *node);
	Tree *deleteNode(int key,Tree *node);
	Tree *leftRotate(Tree * node);
	Tree * rightRotate(Tree *node);
	int max(Tree * a,Tree * b);
	int getBalance(Tree *node);
	int Height(Tree * node);
	void Inorder(Tree * node);
	Tree * minNode(Tree * node);
	
	
};
Tree ::Tree(int key,int h)
{
	data=key;
	height=h;
	left=NULL;
	right=NULL;
}
int Tree ::getData()
{
	return data;

}
int Tree ::getHeight()
{
	return height;
}
void Tree ::setData(int key)
{
	data=key;

}
void Tree ::setHeight(int h)
{

	height=h;
}
Tree * Tree ::getLeft()
{
	return left;

}
Tree * Tree ::getRight()
{
	return right;
}
void Tree ::setLeft(Tree *node)
{
	left=node;
}
void Tree ::setRight(Tree *node)
{
	right=node;

}
int Tree :: Height(Tree * node)
{
	if(node==NULL)
		return 0;
	else
		return node->height;	

}
int Tree ::max(Tree * a,Tree * b)
{
	if(a ==NULL && b==NULL )
	{
		return 0;
	}
	else if(a==NULL)
		return b->height;
	else if(b==NULL)
		return a->height;
	else
			
		return a->height<b->height?b->height:a->height;
}
int Tree ::getBalance(Tree *node)
{
	if(node==NULL)
		return 0;
	return Height(node->left)-Height(node->right);


}
Tree * Tree ::insert(int key,Tree *node)
{
	
	if(node==NULL)
	{
		Tree *root=new Tree(key,0);
		return root;
	}
	else
	{
		if(node->getData()<key)
		{
			node->right=insert(key,node->right);
			//cout<<"In if"<<endl;
		}
		else 
		{
			//cout<<"In else"<<endl;
			node->left=insert(key,node->left);
		}
	}
	node->height=max(node->getLeft(),node->getRight())+1;
	//cout<<node->height<<endl;
	int balance=getBalance(node);
	if(balance>1 && key<node->left->data)
	{
		node=rightRotate(node);
	}
	if(balance<-1 && key>node->right->data)
	{
		node=leftRotate(node);
	}
	if(balance>1 && key>node->left->data)
	{
		node->left=leftRotate(node->left);
		node=rightRotate(node);
	}
	if(balance <-1 && key<node->right->data)
	{
		node->right=rightRotate(node->right);
		node=leftRotate(node);
	}
	return node;
}

Tree * Tree ::leftRotate(Tree * node)
{
	Tree * x=node->right;
	Tree * T2=x->left;
	
	x->left=node;
	node->right=T2;
	
	node->height=max(node->left,node->right)+1;
	x->height=max(x->left,x->right)+1;
	
	return x;
}
Tree * Tree ::rightRotate(Tree *node)
{
	Tree * x=node->left;
	Tree * T2=x->right;
	
	
	x->right=node;
	node->left=T2;
	
	node->height=max(node->left,node->right)+1;
	x->height=max(x->left,x->right)+1;
	
	return x;

}
void Tree ::Inorder(Tree * node)
{
	if(node == NULL)
	return;
	
	Inorder(node->left);
	cout<<node->data<<" ";
	Inorder(node->right);

}
Tree * Tree ::minNode(Tree * node)
{
	//cout<<"in min node"<<endl;	
	//Tree * current=node;
	//cout<<node->data<<endl;
	while(node->left!=NULL)
	{
	
		node=node->left;
	} 

	return node;
}
Tree * Tree ::deleteNode(int key,Tree *node)
{
	if(node==NULL)
	{
		return node;
	}
	
	if(node->data>key)
		node->left=deleteNode(key,node->left);
	else if(node->data<key)
		node->right=deleteNode(key,node->right);
	
	else
	{
		if(node->left==NULL || node->right==NULL)
		{
			Tree * temp=node->left?node->left:node->right;
			if(temp==NULL)// No child
			{
				temp=node;
				node=NULL;
			}
			else
			{
				//node=temp;
				node->data=temp->data;
				node->height=temp->height;
				node->left=temp->left;
				node->right=temp->right;	
			}	
			delete(temp);	
		}
		else
		{
			//cout<<"in else"<<endl;
			//cout<<node->right->data<<endl;
			Tree * temp=minNode(node->right);
			//cout<<temp->data<<endl;
			node->data=temp->data;
			
			node->right=deleteNode(temp->data,temp->right);
			
		}
	
	}
	if(node == NULL)
	return node;
	
	node->height=max(node->left,node->right)+1;
	int balance=getBalance(node);
	if(balance >1 && getBalance(node->left)>=0)
	{
		return rightRotate(node);
	
	}
	if(balance >1 && getBalance(node->left)<0)
	{
	
		node->left=leftRotate(node->left);
		return rightRotate(node);
	}
	if(balance <-1 && getBalance(node->right)<=-1)
	{
		return leftRotate(node);
		
	}
	if(balance <-1 && getBalance(node->right)>-1)
	{
		node->right=rightRotate(node->right);
		return leftRotate(node);
	
	}
	
	return node;


}	

int main()
{
	Tree *avl=NULL;
	Tree *ob1;
	int key;
	cin>>key;
	avl=ob1->insert(key,avl);
	
	cin>>key;
	avl=ob1->insert(key,avl);
	
	cin>>key;
	avl=ob1->insert(key,avl);
	
	cin>>key;
	avl=ob1->insert(key,avl);
	
	ob1->Inorder(avl);
	cout<<"enter key to delete:"<<endl;
	cin>>key;
	
	ob1->deleteNode(key,avl);
	cout<<endl;
	ob1->Inorder(avl);
	
	cin>>key;
	
	ob1->deleteNode(key,avl);
	cout<<endl;
	ob1->Inorder(avl);
	
	
	return 0;
}
