// Author:- Jatin Kumar
#include<iostream>
using namespace std;
int main()
{
	int n,min,temp,loc;
	cout<<"enter size of array=";
	cin>>n;
	int array[n];
	cout<<"enter the elements:\n";
	for(int i=0;i<n;i++)
		cin>>array[i];
	for(int i=0;i<n-1;i++)
	{	
		min=array[i];
		loc=i;
		for(int j=i+1;j<n;j++)
		{
			if(array[j]<min)
			{
				min=array[j];
				loc=j;
			}
		}
		temp=array[i];
		array[i]=array[loc];
		array[loc]=temp;
	}
	cout<<"sorted array is given by:\n";
	for(int i=0;i<n;i++)
		cout<<array[i]<<"\t";
	cout<<"\n";
}