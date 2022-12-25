#include<iostream>

using namespace std;

struct Node
{
	Node *prev;
	int data;
	Node *next;
}*head;

void create(int A[],int n)
{
	Node *t,*last;
	head=new Node;
	head->data=A[0];
	head->next=head;
	head->prev=head;
	last=head;
	for(int i=1;i<n;i++)
	{
		t=new Node;
		t->data=A[i];
		t->next=head;
		head->prev=t;
		t->prev=last;
		last->next=t;
		last=t;
	}
}
void Display(Node *p)
{
	do
	{
		cout<<p->data<<" ";
		p=p->next;
	}while(p!=head);
}
int Length(Node *p)
{
	int l=0;
	do{
	
		p=p->next;
		l++;
	}while(p!=head);
	return l;
}
void Insert(Node *p,int index,int x)
{
	if(index<0 || index>Length(p))
		return ;
	Node *t;
	if(index==0)
	{	
		t=new Node;
		t->data=x;
		t->prev=head->prev;
		t->next=head;
		head->prev=t;
		t->prev->next=t;
		head=t;
	}
	else
	{
		for(int i=0;i<index-1;i++)
			p=p->next;
		t=new Node;
		t->data=x;
		t->next=p->next;
		t->prev=p;
		p->next=t;
		t->next->prev=t;
	}
}
int main()
{
	int A[]={1,2,3,4,5,6};
	create(A,6);
	
	Insert(head,6,8);
	Insert(head,0,9);
	Display(head);
	return 0;
	
}
