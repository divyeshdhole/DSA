#include<iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
}*first=NULL,*last=NULL;

int count(struct Node *p)
{
	if(p==NULL)
		return 0;
	return count(p->next)+1;
}

void create(int A[],int n)
{
	struct Node *t;
	first=new Node;
	
	first->data=A[0];
	first->next=NULL;
	last=first;
	for(int i=1;i<n;i++)
	{
		t=new Node;
		t->data=A[i];
		t->next=NULL;;
		last->next=t;
		last=t;	
	}
	
}
void display(struct Node *p)
{
	if(p!=NULL)
	{
		cout<<p->data<<" ";
		display(p->next);
	}
}
void insertnode(struct Node *p,int index,int x)
{
	if(index<0 || index>count(p))
		return ;
	struct Node *t,*q;
	t=new Node;
	t->data=x;
	if(index==0)
	{
		t->next=first;
		first=t;	
	}
	else
	{
		for(int i=0;i<index-1;i++)
		{	q=p;
			p=p->next;
		}
		t->next=p;
		q->next=t;
		
	}
		
}
int las(struct Node *p)
{
	last=new Node;
	while(p!=NULL)
	{
		p=p->next;
	}
	last=p;

}
void linsert(struct Node *p,int x)
{	
	struct Node *t;
	t=new Node;
	t->data=x;
	t->next=NULL;
	if(first==NULL)
	{
		first=last=t;
	
	}
	else
	{
		last->next=t;
		last=t;
	}
}
int insertsort(struct Node *p,int x)
{
	struct Node *q=NULL,*t;
	t=new Node;
	t->data=x;
	if(first==NULL)
	{
		first=t;
		
	}
	else
	{
		while(p && p->data<x)
		{
			q=p;
			p=p->next;
		}
		if(p=first)
		{
			t->next=first;
			first=t;
		}
		else
		{
			t->next=q->next;
			q->next=t;	
		}
	}
}
int Delete(struct Node *p,int index)
{	struct Node *q=NULL;
	int x;
	if(index<0 || index>count(p) )
		return 0;
	if(index==1)
	{
		x=p->data;
		first=p->next;
		delete p;
		return x;
	
	}
	else
	{
		for(int i=0;i<index-1 && p;i++)
		{	q=p;
			p=p->next;
		}
		if(p
		){
		q->next=p->next;
		x=p->data;
		delete p;
		return x;
		}
		
	}
}

int main()
{
	las(first);
	int A[]={1,5,2,7,9,3};
	create(A,6);
	Delete(first,2);




	
	display(first);
}
