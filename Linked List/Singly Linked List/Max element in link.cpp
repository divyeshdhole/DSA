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
int main()
{
	int A[]={3,5,7,10,15};
	create(A,5);
	
	cout<<"Max is:"<<rmax(first);
	return 0;
	
}
 
