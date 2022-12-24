#include<iostream>
//C style Code
using namespace std;

struct Node
{
	int data;
	Node *next;
}*head;

void create(int A[],int n)
{
	Node *t,*last;
	head=new Node;
	head->data=A[0];
	head->next=head;
	last=head;
	for(int i=1;i<n;i++)
	{
		t=new Node;
		t->data=A[i];
		t->next=last->next;
		last->next=t;
		last=t;
		
	}
}
void Display(Node *h)
{
	do
	{                                                                //Using Iteration
		cout<<h->data<<" ";
		h=h->next;
		
	}while(h!=head);
}

void rDisplay(Node *h)
{
	static int flag=0;
	if(h!=head || flag==0)                         //Using Recursion
	{
		flag=1;
		cout<<h->data<<" ";
		rDisplay(h->next);
		
	}
	
}
int length(Node *p)
{
	int l=0;
	do
	{	l++;
		p=p->next;
	}while(p!=head);
	return l;
}
void Insert(Node *p, int index,int x)
{
	Node *t;
	if(index<0 || index>length(p))
		return ;
	if(index==0)
	{
		t=new Node;
		t->data=x;
		if(head==NULL)
		{
			head=t;
			head->next=head;
			
		}
		else
		{
			while(p->next!=head)
				p=p->next;
				p->next=t;
				t->next=head;
				head=t;
		}
	}
	else
	{
		for(int i=0;i<index-1;i++)
			p=p->next;
		
		t=new Node;
		t->data=x;
		t->next=p->next;
		p->next=t;
		
	}
}

int Delete(Node *p,int index)
{
	Node *q;
	int x;
	if(index<1 || index>length(p))
		return -1;
	if(index==1)
	{
		while(p->next!=head)
			p=p->next;
			x=head->data;
		if(head==p)
		{
			delete(head);
			head=NULL;
		}
		else
		{
			p->next=head->next;
			delete head;
			head=p->next;
		}
		
		
	}
	else
	{
		for(int i=0;i<index-2;i++)
			p=p->next;
		q=p->next;
		p->next=q->next;
		x=q->data;
		delete q;
		
	}
	return x;
}
int main()
{
	int A[]={1,2,3,4,5,6};
	create(A,6);
	Delete(head,2);
	
	
	rDisplay(head);
	

}
