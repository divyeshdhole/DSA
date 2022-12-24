#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
}*first=NULL;


void create(int A[],int n)
{
	struct Node *t,*last;
	
	first=(struct Node *)malloc(sizeof(struct Node));
	first->data=A[0];
	first->next=NULL;
	last=first;
	for(int i=1;i<n;i++){
	    t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
		
	}	
}

int count(struct Node *p)
{
	int l=0;
	while(p!=0)
	{
		l++;
		p=p->next;
	}
	return l;
}

int rcount(struct Node *p)
{
	if(p!=NULL)
	{
		return rcount(p->next)+1;
	}
	return 0;
}

int sum(struct Node *p)
{
	int s=0;
	while(p!=NULL)
	{
		s+=p->data;
		p=p->next;
	}
	return s;
}

int rsum(struct Node *p)
{
	if(p==NULL)
	{
		return 0;
	}
	return rsum(p->next)+p->data;
}
void display(struct Node *p)
{
	if(p!=NULL)
	{
		
		cout<<p->data<<" ";
		display(p->next);
		
	}
}
struct Node * lsearch(struct Node *p,int key)
{	struct Node *q;
	while(p!=NULL)
	{
		if(key==p->data)
		{	
			q->next=p->next;
			p->next=first;
			first=p;
			return p;
		}
		q=p;
		p=p->next;
	}
	return NULL;
}

struct Node * rsearch(struct Node *p,int key)
{	
	if(p==NULL)
		return NULL;
	if(key==p->data)
		return p;
	return rsearch(p->next,key);
}

void insert(struct Node *p,int index,int x)
{	
	struct Node *t;
	if(index<0 ||index>count(p))
		return;
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
			p=p->next;
		t->next=p->next;
		p->next=t;
	}
	
}
int main()
{
	insert(first,0,4);
	insert(first,1,5);
	insert(first,2,30);
	insert(first,0,2);
	display(first);
	
	
	return 0;
	
}
