#include<iostream>

using namespace std;

struct Node 
{
	int data;
	struct Node *next;
}*first=NULL,*last=NULL;
int count(Node *p)
{
	if(p==NULL)
		return 0;
	return count(p->next)+1;
}
void insert(struct Node *p,int index,int x)
{
	if(index<0 && index>count(p))
		return ;
	struct Node *t;
	t=new Node;
	t->data=x;
	if(index==0)
	{
		t->next=first;
		first=t;
	}
	else{
		for(int i=0;i<index-1;i++)
			p=p->next;	
		t->next=p->next;
		p->next=t;
		
	}
		
}
void display(Node *p)
{
	if(p!=NULL)
	{
		cout<<p->data<<" ";
		display(p->next);
	}
}
void slistinsert(Node *p,int x)
{
	Node *q=NULL,*t;
	t=new Node;
	t->data=x;
	if(first==NULL)
		first=t;
	
	else{

		while(p && p->data<x)
		{	
			q=p;
			p=p->next;
		}
		if(p==first)
		{
			t->next=first;
			first=t;
		}
		else{
	
		t->next=q->next;
		q->next=t;
		}
	}
	
}

int main()
{
	insert(first,0,10);
	insert(first,0,8);
	insert(first,0,6);
	insert(first,0,3);
	slistinsert(first,4);
	slistinsert(first,6);
	
	display(first);
	
	return 0;
}
