#include<iostream>

using namespace std;

void TOH(int n,int A,int B,int C)
{
	if(n>0)
	{
		TOH(n-1,A,C,B);
		cout<<"("<<A<<","<<C<<")"<<endl;
		TOH(n-1,B,A,C);                       //Tower of hanoi problem.
	}
}
int main()
{
	TOH(5 ,1,2,3);
}
