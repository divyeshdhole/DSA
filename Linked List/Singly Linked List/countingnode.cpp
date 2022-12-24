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
		display(p->next);
		cout<<p->data<<" ";
		
	}
}
int main()
{
	int A[]={3,5,7,10,15,8,12,20};
	create(A,8);
	cout<<"Length is(itration):"<<count(first)<<endl;
	cout<<"Length is(recursion):"<<rcount(first)<<endl;
	cout<<"The sum is(i):"<<sum(first)<<endl;
	cout<<"The sum is(r):"<<rsum(first);
	
	
	return 0;
	
}
 
