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

void display(struct Node *p)
{
	if(p!=NULL)
	{
		display(p->next);
		cout<<p->data<<" ";
		
	}
}
int main()
{
	int A[]={3,5,7,10,15};
	create(A,5);
	display(first);
	return 0;
	
}
 
