#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	node * left,*right;
};
node * createNode(int k)
{
	node * newNode = (node *)malloc(sizeof(node));
	newNode->data=k;
	newNode->right=NULL;
	newNode->left=NULL;
	return newNode;
	
}
node * insertNode(node * root,int k)
{
	if(root==NULL)
	{
		node * newNode=createNode(k);
		root=newNode;
		return root;
	}
	else
	{
		if(root->data >=k)
		{
			root->left=insertNode(root->left,k);
		
		}
		else
		{
			root->right=insertNode(root->right,k);
		}
		
	}
	return root;
}
void inorder(node * root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

}
int max(int a,int b)
{
	return a>b?a:b;
}
int findDiameter(node * root,int &height)
{
	if(root==NULL)
	{
		height=0;
		return 0;
		
	}
	int lh=0,rh=0;
	
	int leftDiameter=findDiameter(root->left,lh);
	int rightDiameter=findDiameter(root->right,rh);
	height=max(lh,rh)+1;
	return max(lh+rh+1,max(leftDiameter,rightDiameter));
	

}
int main()
{
	int num,x,lh,rh;
	cin>>num;
	node * root=NULL;
	while(num--)
	{
		cin>>x;
		root=insertNode(root,x);
		
	
	}
	inorder(root);
	int height=0;
	int diameter=findDiameter(root,height);
	cout<<diameter<<endl;
	return 0;
}
