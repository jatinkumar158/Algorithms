// Author:- Jatin Kumar

#include<iostream>
using namespace std;
int heapsize;
void buildheap(int*);
void maxheapify(int*,int);
void swap(int*,int,int);
void printheap(int*,int);
void heapsort(int *,int);
int main()
{
	int n,i;
	cout<<"enter the no. of elements=";
	cin>>n;
	heapsize=n;
	int array[n];
	for(i=0;i<n;i++)
	{
		cin>>array[i];
	}
	cout<<"Before Sorting"<<endl;
	printheap(array,n);
	buildheap(array);
	heapsort(array,n);
	cout<<"After Sorting"<<endl;
	printheap(array,n);
}
void buildheap(int *temp)
{
	int i;
	for(i=(heapsize/2)-1;i>=0;i--)
	{
		maxheapify(temp,i);
	}
}
void maxheapify(int *temp,int i)
{
	int left=2*i+1;
	int right=2*i+2;
	int largest;
	if(left<heapsize)
	{
		if(*(temp+i)<*(temp+left))
		{
			largest=left;
		}
		else
		{
			largest=i;
		}
	}
	else
	{
		return;
	}
	if(right<heapsize)
	{
		if(*(temp+largest)<*(temp+right))
		{
			largest=right;
		}
	}
	if(i!=largest)
	{
		swap(temp,i,largest);
		maxheapify(temp,largest);
	}
}
void swap(int *temp,int x,int y)
{
	int z=*(temp+x);
	*(temp+x)=*(temp+y);
	*(temp+y)=z;
}
void printheap(int *temp,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<*(temp+i)<<"\t";
	}
	cout<<endl;
}
void heapsort(int *temp,int n)
{	
	for(int i=0;i<n;i++)
	{
		swap(temp,0,n-i-1);
		heapsize--;
		maxheapify(temp,0);
	}
}