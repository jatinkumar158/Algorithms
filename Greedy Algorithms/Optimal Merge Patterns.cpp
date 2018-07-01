// Author:- Jatin Kumar
// Optimal merge pattern problem
// based on greedy approach
// problem is similar to huffman coding
// time complexity=O(n logn) but mine solution is taking O(n^2) (will optimize it later)

#include<bits/stdc++.h>
using namespace std;
struct node
{
	char name;
	int length;
	struct node *left;
	struct node *right;
};
void buildheap();
void minheapify(int);
int optimalmerge();
struct node* extractmin();
struct node *obj[100];
int heapsize,n,grandtotal=0;
int main()
{
	int n;
	cout<<"enter the no. of files=";
	cin>>n;
	heapsize=n;
	for(int i=0;i<n;i++)
	{	
		obj[i]=(struct node*)malloc(sizeof(struct node));
		cout<<"enter file name and record length of file "<<i+1<<":";
		cin>>obj[i]->name>>obj[i]->length;
		obj[i]->left=NULL;
		obj[i]->right=NULL;
	}
	buildheap();
	int totallength=optimalmerge();
	cout<<"minimum no. of movements="<<totallength<<"\n";	
}
void buildheap()
{
	for(int i=(heapsize/2)-1;i>=0;i--)
	{
		minheapify(i);
	}
}
void minheapify(int root)
{
	int left=2*root+1;
	int right=2*root+2;
	int smaller;
	if(left<heapsize)
	{
		if(obj[root]->length>obj[left]->length)
		{
			smaller=left;
		}
		else
		{
			smaller=root;
		}
	}
	else
	{
		return;
	}
	if(right<heapsize)
	{
		if(obj[right]->length<obj[smaller]->length)
		{
			smaller=right;
		}
	}
	if(smaller!=root)
	{
		struct node *temp=obj[root];
		obj[root]=obj[smaller];
		obj[smaller]=temp;
		minheapify(smaller);
	}
}
struct node* extractmin()
{
	struct node *temp=obj[0];
	obj[0]=obj[heapsize-1];
	heapsize--;
	if(heapsize!=0)
	{
		minheapify(0);
	}
	return temp;
}
int optimalmerge()
{
	while(heapsize>1)
	{
		struct node *first=extractmin();
		struct node *second=extractmin();
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->left=first;
		temp->right=second;
		temp->length=first->length+second->length;
		grandtotal=grandtotal+temp->length;
		obj[heapsize]=temp;
		heapsize++;
		buildheap();
	}
	return grandtotal;
}
