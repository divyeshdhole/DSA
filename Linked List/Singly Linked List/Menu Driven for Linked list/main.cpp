#include<iostream>

using namespace std;

//Create the structure Node
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
		void createList();				//Create list
		int Length();			        //Returns the length of list
		void InsertAtBeg();				//Insert at Beg
		void InsertAtlast();			//Insert at last
		void InsertAtPos();				//Insert at given postion
		void DeleteFirst();				//Delete first Node
		void DeleteLast();				//Delete last Node
		void DeletePos();				//Delete particular position
		void Display();					//Display linked List
		~LinkedList();					//Destructor
		
};

//Destructor
LinkedList::~LinkedList()
{
	Node *p=first;
	while(first)
	{
		p=first;
		first=first->next;
		delete p;
		
	}
}
//Create Function
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

//Length Function
int LinkedList::Length()
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
//Insert at Beg Function
void LinkedList::InsertAtBeg()
{
	Node *newnode=new Node;
	cout<<"Enter the data: ";
	cin>>newnode->data;
	newnode->next=first;
	first=newnode;
}
//Insert at last Function

void LinkedList::InsertAtlast()
{
	Node *p=first;
	Node *newnode=new Node;
	cout<<"Enter the data: ";
	cin>>newnode->data;
	if(!first)
		first=newnode;
	else
	{
		while(p->next)
		p=p->next;
	p->next=newnode;
	}
	newnode->next=NULL;

}

//Insert at given Position
void LinkedList::InsertAtPos()
{
	int index=0;
	Node *p=first;
	Node *newnode=new Node;
	cout<<"Enter the data: ";
	cin>>newnode->data;
	cout<<"\nEnter the position: ";
	cin>>index;
	if(index<0 || index>Length())
	{
		cout<<"Index Not available....";
		return ;
	}
	if(index==0)
	{
		newnode->next=first;
		first=newnode;
	}
	else
	{
		for(int i=0;i<index-1;i++)
			p=p->next;
		newnode->next=p->next;
		p->next=newnode;
	}
	
}
//Delete first node Function
void LinkedList::DeleteFirst()
{
	if(first==NULL)
	{
		cout<<"List is empty"<<endl;
		return ;
	}
	int x;
	Node *p=first;
	first=first->next;
	x=p->data;
	delete p;
	cout<<x<<" is Deleted."<<endl;
	
}

//Delete last node Function
void LinkedList::DeleteLast()
{
	if(first==NULL)
	{
		cout<<"List is Empty"<<endl;
		return ;
	}
	int x;
	Node *p=first,*q=first;
	if(!first->next)
	{
		x=first->data;
		delete p;
		first=NULL;
		cout<<x<<" is Deleted."<<endl;
	}
	else
	{
		while(p->next)
		{
			q=p;
			p=p->next;
		}
		x=p->data;
		delete p;
		q->next=NULL;
		cout<<x<<" is Deleted."<<endl;
	}
}

//Delete at Postion
void LinkedList::DeletePos()
{
	if(first==NULL)
	{
		cout<<"List is empty"<<endl;
		return ;
	}
	int x;
	int index=0;
	Node *p=first,*q=first;
	cout<<"Enter the position to delete: "<<endl;
	cin>>index;
	if(index<0 || index>Length())
	{
		cout<<"Index Not available....";
		return ;
	}
	if(index==0)
	{
		first=first->next;
		x=p->data;
		delete p;
		cout<<x<<" is Deleted."<<endl;
	}
	else{
	
		for(int i=0;i<index-1;i++)
		{
			q=p;
			p=p->next;	
		}
		x=p->data;
		q->next=p->next;
		delete p;
		cout<<x<<" is Deleted."<<endl;
		
	}
}
//Display Function
void LinkedList::Display()
{	
	cout<<"---------------------------------------------------------------------\n";
	if(first==NULL)
		cout<<"List is Empty "<<endl;
	Node *p=first;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next; 
	}
	cout<<"\n---------------------------------------------------------------------\n";
}
int main()
{
	LinkedList l;
	int choice=0;;
	l.createList();

	while(1)
	{	
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"*****************************Mainu*******************************"<<endl;
		cout<<"1.Insert at first\n2.Insert at last\n3.Insert at Pos\n4.Delete first\n5.Delete last\n6.Delete pos\n7.length\n8.Display\n9.Exit"<<endl;
		cout<<"Enter Your choice: "<<endl;
		cin>>choice;	
		
		switch(choice)
		{
			case 1:
				l.InsertAtBeg();
				break;
			case 2:
				l.InsertAtlast();
				break;
			case 3:
				l.InsertAtPos();
				break;
			case 4:
				l.DeleteFirst();
				break;
			case 5:
				l.DeleteLast();
				break;
			case 6:
				l.DeletePos();
				break;
			case 7:
				cout<<"The length is: "<<l.Length()<<endl;
				break;
			case 8:
				l.Display();
				break;
			case 9:
				exit(0);
				break;
			default:
				cout<<"Invalid Input!"<<endl;
				
		}
	}
 	
	
	return 0;
}
