// Author:- Jatin Kumar
// Huffman Coding:- given characters and their frequency of occurence (or you can give probability also)
// our task is to assign variable length codes to the characters
// time complexity: O(n logn) but for mine solution it is O(n^2)	(will optimize it later)
// to understand this code you must be familier with the concept of heap

#include<bits/stdc++.h>
using namespace std;
// define structure for the node
struct node
{
	struct node *left;	// pointers are used because we are going build huffman tree 
	struct node *right;
	int frequency;
	char character;
};
struct node *array[100];	// declare array of structures (it can hold 100 nodes)
int n,heapsize;
void buildminheap();
void minheapify(int);
struct node* extractmin();
struct node* huffmantree();
void printArray(int*,int);
void printvalues(struct node*,int*,int);
int  main()
{	
	// array a is used for storing the codes of the characters
	int a[100],top=0;	// top will take care of the index of array a
	cout<<"enter the no. of characters=";
	cin>>n;
	heapsize=n;
	for(int i=0;i<n;i++)
	{	
		// as our array of nodes is already created so directly
		// create the nodes and assign the address
		array[i]=(struct node*)malloc(sizeof(struct node));
		cout<<"enter character "<<i+1<<":";
		cin>>array[i]->character;
		cout<<"enter frequency of "<<array[i]->character<<":";
		cin>>array[i]->frequency;
		array[i]->left=NULL;
		// here null indicates that it is a leaf node
		array[i]->right=NULL;
	}
	// now build the minheap
	buildminheap();
	// now make huffman tree and get pointer to root of that tree
	struct node *root=huffmantree();
	// now as our tree is build, now we shall assign codes to each character
	printvalues(root,a,top);
	cout<<"Answer depends upon the structure of the tree\n";
}
void buildminheap()
{	
	// leaf are already nodes so run loop from first non-leaf to first node
	for(int i=(heapsize/2)-1;i>=0;i--)
	{
		minheapify(i);
	}
}
void minheapify(int i)
{	
	int l=2*i+1;
	int r=2*i+2;
	int smallest;
	if(l<heapsize)
	{
		// left child exists
		if(array[i]->frequency<array[l]->frequency)
		{
			smallest=i;
		}
		else
		{
			smallest=l;
		}
	}
	else
	{	
		// left child does not exists and obviously right child also doesn't exists
		// so it means we are at leaf and so simply return
		return;
	}
	if(r<heapsize)
	{
		// right child exists
		if(array[smallest]->frequency>array[r]->frequency)
		{
			smallest=r;
		}
	}
	// if smallest element is i itself then we don't need to swap
	if(smallest!=i)
	{	
		struct node *temp=array[i];
		array[i]=array[smallest];
		array[smallest]=temp;
	}
}
struct node* extractmin()
{
		struct node *temp=array[0];
		array[0]=array[heapsize-1];
		heapsize--;
		if(heapsize<0)
		{
			return NULL;
		}
		minheapify(0);
		return temp;
}
struct node* huffmantree()
{	
	while(heapsize>1)
	{	
		struct node *first=extractmin();
		struct node *second=extractmin();
		//after removing two smallest element from heap create a new node
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->left=first;
		temp->right=second;
		temp->frequency=first->frequency+second->frequency;
		temp->character='$';	// this line is not necessary
		// now put this node into the minheap
		array[heapsize]=temp;
		heapsize++;
		// now build heap again as newly inserted node may destroy heap property
		buildminheap();
	}
	// return the address of the only node remaining in heap
	// this node will contain sum of frequencies of all the characters
	// so this node will be root of our huffman tree
	return extractmin();
}
void printvalues(struct node *root,int a[],int top)
{	
	// I am giving 0 to left and 1 to right
	// this convention may vary and there could be different answers

	// now we shall treverse the tree atop to bottom and left to right and when we reach at leaf then
	// we shall print the content of our array a that contains code
	// it will be better if you take pen and paper and make a stack and see how this top variable is changing
	if(root->left!=NULL)
	{	
		// when we move left store 0 in array
		a[top]=0;
		// next value will be stored in next index of array
		// top is pointing to our index
		// so pass top+1
		printvalues(root->left,a,top+1);
	}
	if(root->right!=NULL)
	{	
		// when we move left store 1 in array
		a[top]=1;
		printvalues(root->right,a,top+1);
	}
	// we are at leaf node 
	if(root->left==NULL && root->right==NULL)
	{	
		// print the character
		cout<<root->character<<"  ";
		// print the code
		printArray(a,top);
	}
}
void printArray(int a[],int top)
{	
	// print the code stored in array a
	for(int i=0;i<top;i++)
	{
		cout<<a[i];
	}
	cout<<"\n";
}
