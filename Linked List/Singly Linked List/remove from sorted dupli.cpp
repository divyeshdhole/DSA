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
int main()
{
	int A[]={3,3,5,5,2,10,10,15};
	create(A,8);
	removeduplicate(first);
	display(first);
	return 0; 
	
}
 
