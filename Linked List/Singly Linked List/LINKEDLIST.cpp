#include<iostream>

using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class linkedlist
{
	private:
		Node *first;
	public:
		linkedlist()
		{
			first=NULL;
		}
		linkedlist(int A[],int n);
		~linkedlist();
		int Length();
		void Insert(int index,int data);
		int Delete(int index);
		void Display();
		
};

linkedlist::linkedlist(int A[],int n)
{
	Node *t,*last;
	first=new Node;
	first->data=A[0];
	first->next=NULL;
	last=first;
	for(int i=1;i<n;i++)
		{
			t=new Node;
			t->data=A[i];
			t->next=NULL;
			last->next=t;
			last=t;
			
	}
	
}
linkedlist::~linkedlist()
{
	Node *p=first;
	while(first)
	{
		first=first->next;
		delete p;
		p=first;
	}
}
int linkedlist::Length()
{
	int l=0;
	Node *p=first;
	while(p)
	{
		p=p->next;
		l++;
	}
	return l;
	
}
void linkedlist::Insert(int index,int x)
{
	if(index<0 || index>Length())
		return ;
	Node *p=first;
	Node *t;
	t=new Node;
	t->data=x;
	
	if(index==0)
	{	t->next=first;
		first=t;
	}
	else
	{
		for(int i=0;i<index-1;i++)
		{	
			p=p->next;
			
		}
		t->next=p->next;
		p->next=t;	
	}
	
}
int linkedlist::Delete(int index)
{
	if(index<1 || index>Length())
		return 0;
	Node *p=first,*q;
	int x=-1;
	if(index==1)
	{	
		first=p->next;
		x=p->data;
		delete p;
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
void linkedlist::Display()
{	Node *p=first;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}
int main()
{	
	int A[]={1,2,3,4,5,6,7,8};
	linkedlist l(A,8);
	cout<<l.Length()<<endl;

	l.Display();
	return 0;
	
}
