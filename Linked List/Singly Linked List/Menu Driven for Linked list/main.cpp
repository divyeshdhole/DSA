#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};
class LinkedList
{
	private:
		Node *first;
	public:
		void createList();
		int Length();
		void InsertAtBeg();
		void InsertAtlast();
		void InsertAtPos();
		void DeleteFirst();
		void DeleteLast();
		void DeletePos();
		void Display();
		
};

void LinkedList::createList()
{
	Node *t,*last;
	int n;
	first=new Node;
	cout<<"How many node do u Want to create:"<<endl;
	cin>>n;
	if(n)
	{
		cout<<"Enter the data:\n";
		cin>>first->data;
		first->next=NULL;
		last=first;
		while(--n)
		{
			t=new Node;
			cout<"Enter the data:\n";
			cin>>t->data;
			t->next=NULL;
			last->next=t;
			last=t;
			
		}
	}
	else
		first=NULL;
	
}
void LinkedList::Display()
{	Node *p=first;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next; 
	}
}
int main()
{
	LinkedList l;
	l.createList();
	l.Display();
	
	return 0;
}
