// Author:-Jatin Kumar
#include<iostream>
using namespace std;
void mergesort(int*,int,int);
void merge(int *,int,int,int);
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
	mergesort(array,0,n-1);
	cout<<"sorted array is given by:\n";
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<"\t";
	}
	cout<<"\n";
}
void mergesort(int *temp,int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		mergesort(temp,p,q);
		mergesort(temp,q+1,r);
		merge(temp,p,q,r);
	}
}
void merge(int *temp,int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int left[n1];
	int right[n2];
	for(int i=0;i<n1;i++)
	{
		left[i]=*(temp+p+i);
	}
	for(int i=0;i<n2;i++)
	{
		right[i]=*(temp+q+1+i);
	}
	int i=0,j=0,k=p;
	while(i<n1 && j<n2)
	{
		if(left[i]<right[j])
		{
			*(temp+k)=left[i];
			i++;
		}
		else
		{
			*(temp+k)=right[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		*(temp+k)=left[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		*(temp+k)=right[j];
		k++;
		j++;
	}
}
