// Author:- Jatin Kumar
// using last element as pivot
#include<iostream>
using namespace std;
void quicksort(int *,int,int);
int partition(int*,int,int);
void swap(int*,int,int);
int main()
{
	int n;
	cout<<"enter the no. of elements=";
	cin>>n;
	int array[n];
	cout<<"enter elements:";
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
	}
	quicksort(array,0,n-1);
	cout<<"sorted array is given by:\n";
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<"\t";
	}
	cout<<"\n";
}
void quicksort(int *temp,int p,int r)
{
	if(p<r)
	{
		int q=partition(temp,p,r);
		quicksort(temp,p,q-1);
		quicksort(temp,q+1,r);
	}
}
int partition(int *temp,int p,int r)
{
	int x=*(temp+r);
	int i=p-1;
	for(int j=p;j<=r-1;j++)
	{
		if(*(temp+j)<=x)
		{
			i++;
			swap(temp,i,j);
		}
	}
	i++;
	swap(temp,i,r);
	return i;
}
void swap(int *temp,int x,int y)
{
	int z=*(temp+x);
	*(temp+x)=*(temp+y);
	*(temp+y)=z;
}
