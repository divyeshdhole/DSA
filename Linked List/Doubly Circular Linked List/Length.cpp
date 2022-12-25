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
int main()
{
	int A[]={1,2,3,4,5,6};
	create(A,6);
	Display(head);
	cout<<"\nThe length is:"<<Length(head);
}
