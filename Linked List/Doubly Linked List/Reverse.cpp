#include<iostream>

using namespace std;

struct Node
{
	Node *prev;
	int data;
	Node *next;
}*first;

void create(int A[],int n)
{
	Node *t,*last;
	
	first=new Node;
	first->data=A[0];
	first->prev=first->next=NULL;
	last=first;
	
	for(int i=1;i<n;i++)
	{
		t=new Node;
		t->data=A[i];
		t->next=last->next;
		t->prev=last;
		last->next=t;
		last=t;
	}
}

void Display(Node *p)
{
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}

int Length(Node *p)
{
	int l=0;
	while(p)
	{
		l++;
		p=p->next;
	}
	return l;
}
void Insert(Node *p,int index,int x)
{
	if(index<0 || index>Length(p))
		return ;
	Node *t;
	t=new Node;
	t->data=x;
	if(index==0)
	{
		t->prev=NULL;
		t->next=first;
		first->prev=t;
		first=t;
		
	}
	else
	{
		for(int i=0;i<index-1;i++)
			p=p->next;
		t->next=p->next;
		t->prev=p;
		if(p->next)
			p->next->prev=t;
		p->next=t;
	}
	
}
int Delete(Node *p,int index)
{
	if(index<1 || index >Length(p))
		return -1;
	int x=-1;
	if(index==1)
	{
		first=first->next;
		if(first)
			first->prev=NULL;
		x=p->data;
		delete p;
	}
	else
	{
		for(int i=0;i<index-1;i++)
			p=p->next;
		p->prev->next=p->next;
		if(p->next)
			p->next->prev=p->prev;
		x=p->data;
	}
	return x;
}
void Reverse(Node *p)
{
	Node *temp;
	while(p)
	{
		temp=p->next;
		p->next=p->prev;
		p->prev=temp;
		p=p->prev;
		if(p!=NULL && p->next==NULL)
			first=p;
	}
}
int main()
{
	int A[]={1,2,3,4,5};
	create(A,5);
	Reverse(first);
	Display(first);
	return 0;
}
