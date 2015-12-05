#include<iostream>
#include<malloc.h>
using namespace std;
struct Node
{
	int data;
	Node * next;

};
Node * createNode(int key)
{
	Node * newNode=(Node *)malloc(sizeof(Node));
	newNode->data=key;
	newNode->next=NULL;
	return newNode;

}
Node * insertNode(int key,Node *root,int pos)
{
	Node * node=createNode(key);
	if(root==NULL)
	{
		root=node;
	}
	else
	{
		int count=1;
		Node * current=root;
		while((count)!=pos-1 && current->next!=NULL)
		{
			count ++;
			current=current->next;
		
		}
		node->next=current->next;
		current->next=node;
	}
	return root;


}
void SplitLL(Node * root,Node **a,Node **b)
{
	Node *slow=root,*fast=root->next;
	while(fast!=NULL)
	{
		fast=fast->next;
		if(fast!=NULL)
		{
			slow=slow->next;
			fast=fast->next;
		
		}
	
	}
	*a=root;
	*b=slow->next;
	slow->next=NULL;
}
Node * mergeLL(Node *start1,Node *start2)
{
	Node * result=NULL;
	if(start1==NULL)
	{
		return start2;
	}
	if(start2==NULL)
	{
		return start1;
	}
	if(start1->data>=start2->data)
	{
		result=start2;
		result->next=mergeLL(start1,start2->next);
		
	}
	else
	{
		result=start1;
		result->next=mergeLL(start1->next,start2);
	
	}
	return result;
}
void mergeSort(Node **root)
{
	Node * a,*b;
	if(*root==NULL || (*root)->next==NULL)
	{
		return;
	}
	SplitLL(*root,&a,&b);
	mergeSort(&a);
	mergeSort(&b);
	*root=mergeLL(a,b);
		
}
void printLL(Node *root)
{
	Node * current=root;
	while(current->next!=NULL)
	{
		cout<<current->data<<" ";
		current=current->next;
	
	}
	cout<<current->data;
}
int main()
{
	Node * root=NULL;
	root=insertNode(2,root,1);
	root=insertNode(6,root,2);
	root=insertNode(3,root,3);
	root=insertNode(1,root,4);
	root=insertNode(9,root,5);
	root=insertNode(4,root,2);
	mergeSort(&root);
	printLL(root);
	return 0;
}
