#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;

class Node
{
	//friend class LinkedList;
	private:
	int value;
	Node *next;
	public:
	Node():next(NULL)
	{}
	Node(int val):value(val),next(NULL)
	{}
	Node(int val,Node *pnext):value(val),next(pnext)
	{}
	//getters
	/*int getvalue()
	{
		return value;
	} */
	Node* getNext()
	{
		return next;
	}
	Node* setNext(Node* node)
	{
		next = node;
	}
	void setValue(int val)
	{
		value = val;
	}
};

Node::int getvalue(){
	return value;
	}
class LinkedList
{
	private:
	Node *head;
	int size;
	
	public:
	LinkedList();
	LinkedList(int val);
	
	~LinkedList(void);
	
	void traverseLL();
	void insert(int val,int pos); 

};
LinkedList::LinkedList()	
{
	head=NULL;
	size = 0;

}
LinkedList::LinkedList(int val)	
{
	head = new Node(val);

}

void LinkedList::traverseLL()
{
	Node* current = head;
	if(current==NULL)
	{
		cout<<"Empty List !!";
		return;
	}
	while(current!=NULL)
	{
		cout<<current.getvalue()<<" ";
		current=current->next;
	
	}	
}

void LinkedList::insert(int val, int position)
{
	int k = 1;
	Node new_node(val);
	if(head == NULL)
		head = new_node;
	else
	{
		Node* current = head;
		Node* prev = NULL;
		while(position > k && current!=NULL)
		{
		
			k++;
			prev=current;
			current = current->getNext();
		
		}
		new_node.setNext(prev.getNext());
		//new_node->next=prev->next;
		prev.setNext(new_node);
	
	
	}
}
/*
void insert(struct node** head,int data,int position);
void deleteNode(struct node** head,int position);
void deleteLL(struct node** head);
void traverseLL(struct node** head);
int countElementsOfLL(struct node** head);
int searchElement(struct node *head,int data,int loc);
int FindNthNode(struct node* head,int position);
*/
int main()
{
	int choice,data,position;
	int numOfNodes,elementLoc,loc;
	Node *head=NULL;
	LinkedList ll;
	while(1)
	{
		cout<<"\n1.insert node\n";
		cout<<"2.delete node\n";
		cout<<"3.delete LL\n";
		cout<<"4.traverse LL\n";
		cout<<"5.exit\n";
		cout<<"6.count no. of nodes in LL\n";
		cout<<"7. search element in LL\n";
		cout<<"8.find Nth node\n";
		cin>>choice;
		switch(choice)
		{
			case 1:cout<<"enter data and position of node";
				cin>>data>>position;
				//cout<<head;
				ll.insert(data,position);
				
				break;
			/*case 2:cout<<"enter position of node";
				cin>>position;
				deleteNode(&head,position);
				break;
			case 3:cout<<"deleting complete LL";
				deleteLL(&head);
				break;*/
			case 4:cout<<"elements of LL are-";
				ll.traverseLL();
				break;
			case 5:exit(0);	
				
			/*case 6:	numOfNodes=countElementsOfLL(&head);
				cout<<"No. of nodes in LL= "<<numOfNodes<<"\n";
				break;
			case 7:	cin>>data;
				loc=1;
				elementLoc=searchElement(head,data,loc);
				if(elementLoc)
				cout<<"element is present at location= "<<elementLoc;
				else
				cout<<"Element not present";
				break;	
			case 8:	cin>>position;
				data=FindNthNode(head,position);
				if(data!=-1)	
				cout<<"element at "<<position<<" position is "<<data<<endl;
				else
				cout<<"No such position exists";
				break;*/
			default:cout<<"wrong option!!select correct option";				
	
		}
	}			
	return 0;	
}

/*void insert(struct node** head,int data,int position)
{
	//cout<<"in insert()";
	struct node* newNode=(struct node*)malloc(sizeof(struct node));
	if(!newNode)
	{
		cout<<"Memory Error";
	}
	struct node* current=*head; 
	struct node* prev=NULL;
	newNode->data=data;
	//cout<<"here";
	int k=1;
	if(position==1)
	{
		newNode->next=(*head);
		*head=newNode;
	}
	else
	{
		while(position >k && current!=NULL)
		{
		
			k++;
			prev=current;
			current = current -> next;
		
		}
		newNode->next=prev->next;
		prev->next=newNode;
	
	
	}

}
void deleteNode(struct node** head,int position)
{
	struct node* prev=NULL,*current;
	current=(*head);
	int k=1;
	if((*head)==NULL)
	{
		cout<<"List is empty";
		return;
	}
	if(position==1)
	{
		(*head)=current->next;
		free(current);
		return;
	
	}
	
	while(position>k && current!=NULL)
	{
		k++;
		prev=current;
		current=current->next;
	}
	prev->next=current->next;
	free(current);
	
}
void deleteLL(struct node** head)
{
	struct node* current=(*head);
	while(current!=NULL)
	{
		(*head)=current->next;
		free(current);
		current=(*head);
	
	}
}
void traverseLL(struct node** head)
{
	struct node* current=(*head);
	if(current==NULL)
	{
		cout<<"Empty List !!";
		return;
	}
	while(current!=NULL)
	{
		cout<<current->data<<" ";
		current=current->next;
	
	}	
}
int countElementsOfLL(struct node** head)
{
	struct node* current=(*head);
	int count=0;
	while(current!=NULL)
	{
		count++;
		current=current->next;
	}
	return count;
}
int searchElement(struct node *head,int data,int location)
{
	//static struct node* current=head;
	int loc=location;
	/*while(current!=NULL)
	{
		loc++;
		if(current->data==data)
		{
			return loc;
		}
		else
		{
			current=current->next;
		}
	}
	return 0;*/
	//recursive search
/*	if(head==NULL)
	return 0;
	if(head->data==data)
	{
		return loc;
		
		
	}
	else
	{
		loc++;
		head=head->next;
		int loc1=searchElement(head,data,loc);
		return loc1;
	}

}
int FindNthNode(struct node* head,int position)
{
	struct node * current=head;
	int count=0;
	while(current!=NULL)
	{
		count++;
		if(count==position)
			return current->data;
		current=current->next;
	}
	return -1;

}*/
