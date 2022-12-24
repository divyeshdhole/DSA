#include <iostream>

using namespace std;;

int main()
{
	int a[5]={1,2,3,4,5};
	int *p;
	
	p=new int[5]; //OR in c:- p=(int *)malloc(5*sizeof(int) -->we write the (int *) before the malloc fun bcoz malloc function return the void ptr therefore before to use array element we have to typecast and include header file stdlib.h.
	p[0]=3;
	p[1]=1;
	p[2]=9;
	p[3]=4;
	p[4]=6;
	
	
	for(int i=0;i<5;i++)
		cout<<a[i]<<" ";
		
	cout<<endl;
	
	for(int i=0;i<5;i++)
		cout<<p[i]<<" ";
		
	delete []p;					//to delete heap memory. in c use free(p) to f\delete memory.
		return 0;	
}
