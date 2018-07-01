// Author:-Jatin Kumar
#include<iostream>
using namespace std;
void mergesort(int*,int,int);
void merge(int*,int,int,int);
int main()
{
	int n;
	cout<<"enter the no. of elements=";
	cin>>n;
	int array[n];
	cout<<"enter elements=";
	for (int i = 0; i < n; i++)
	{
		cin>>array[i];
	}
	mergesort(array,0,n-1);
	cout<<"sorted array is given  by:\n";
	for (int i = 0; i < n; i++)
	{
		cout<<array[i]<<"\t";
	}
	cout<<"\n";
}
void mergesort(int *temp,int p,int r)
{
	if(p<r)
	{	
		// find the middle position
		int q=(p+r)/2;
		// sort array from p to q
		mergesort(temp,p,q);
		// sort array from q+1 to r
		mergesort(temp,q+1,r);
		// now merge the subarrays
		merge(temp,p,q,r);
	}
}
void merge(int *temp,int p,int q,int r)
{	
	int n1=q-p+1+1;
	int n2=r-q+1;
	// create two subarrays of size n1 and n2
	int left[n1];
	int right[n2];
	// left and right will contain sorted elements
	for (int i = 0; i < n1-1; i++)
	{
		left[i]=*(temp+p+i);
	}
	for (int i = 0; i < n2-1; i++)
	{
		right[i]=*(temp+q+1+i);
	}
	// put some large number at the end of the two subarrays
	left[n1-1]=999999;
	right[n2-1]=999999;
	// now start compairing and make sorted array
	int i=0,j=0,k;
	for(int k=p;k<=r;k++)
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
	}
}
