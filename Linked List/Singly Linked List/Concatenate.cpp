#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;


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

void create2(int A[],int n)
{
	struct Node *t,*last;
	
	second=(struct Node *)malloc(sizeof(struct Node));
	second->data=A[0];
	second->next=NULL;
	last=second;
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
	if(p==NULL)
		return 0;
	return count(p->next)+1;
}

void display(struct Node *p)
{
	if(p!=NULL)
	{	
		cout<<p->data<<" ";
		display(p->next);
		
		
	}
}
int max(struct Node *p)
{
	int m=INT32_MIN;
	while(p)
	{
		if(p->data>m)
		{
			m=p->data;
			p=p->next;
		}
	}
	return m;
}
int rmax(struct Node *p)
{
	int x=0;
	if(p==0)
		return INT32_MIN;
	x=rmax(p->next);
	if(x>p->data)
		return x;
	else
		return p->data;
}
int Delete(struct Node *p,int index)
{
	struct Node *q;
	int x=-1;
	
	if(index<1 || index>count(p))
		return -1;
	if(index==1)
	{
		q=first;
		x=first->data;
		first=first->next;
		delete q;
		return x;
	}
	else
	{
		for(int i=0;i<index-1;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		x=p->data;
		delete p;
		return x;
	}
}
int issorted(struct Node *p)
{
	int x=-65536;
	while(p!=NULL)
	{
		if(p->data<x)
			return 0;
		x=p->data;
		p=p->next;
	}
	return 1;
}
void removeduplicate(struct Node *p)
{
	struct Node *q=p->next;
	while(q!=NULL)
	{
		if(p->data!=q->data)
		{
			p=q;
			q=q->next;
		}
		else
		{
			p->next=q->next;
			delete q;
			q=p->next;
		}
	}
}
void reverse1(struct Node *p)
{
	int *A;
	struct Node *q=p;
	A=new int[count(p)];
	int i=0;
	while(q!=NULL)
	{
		A[i]=q->data;
		q=q->next;
		i++;
	}
	q=p;
	i--;
	while(q!=NULL)
	{
		q->data=A[i];
		q=q->next;
		i--;
	}
}
void reverse2(struct Node *p)
{
	struct Node *q=NULL,*r=NULL;
	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	first=q;
}
void reverse3(struct Node *q,struct Node *p)
{
	if(p!=NULL)
	{
		reverse3(p,p->next);
		p->next=q;
	}
	else
		first=q;
}

void concat(struct Node *p,struct Node *q)
{
	third=p;
	while(p->next!=NULL)
		p=p->next;
	p->next=q;
}
int main()
{
	int A[]={3,5,10,15};
	int B[]={1,4,9,7,5};
	create(A,4);
	create2(B,5);
	
	concat(first,second);
	display(third);
	
	return 0; 
	
}
 
