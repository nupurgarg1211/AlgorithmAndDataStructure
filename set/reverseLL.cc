#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	node * next;
};
node * createNode(int k)
{
	node * newNode=(node *)malloc(sizeof(node));
	newNode->data=k;
	newNode->next=NULL;
	return newNode;
}
void insert(node **head,int k)
{
	node * current=*head;
	node *newNode=createNode(k);
	if(*head==NULL)
	{
		*head=newNode;
		return;
	}
	while(current->next!=NULL)
	{
		current=current->next;
	
	}
	current->next=newNode;
	

}
void printLL(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	
	}

}
void reverseLL(node **head)
{
	if(head==NULL)
	{
		return ;
	}
	node *current=*head;
	node *prev=NULL,*next=NULL;
	while(current->next!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	
	}
	current->next=prev;
	*head=current;
}
int main()
{
	node * head=NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	//printLL(head);
	reverseLL(&head);
	printLL(head);

}
