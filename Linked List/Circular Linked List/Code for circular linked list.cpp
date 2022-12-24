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
int main()
{
	int A[]={1,2,3,4,5,6};
	create(A,6);
	rDisplay(head);
	

}
