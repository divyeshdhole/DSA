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
int main()
{
	int A[]={1,2,3,4,5};
	create(A,5);
	cout<<"The length is: "<<Length(first)<<endl;
	Display(first);
	return 0;
}
