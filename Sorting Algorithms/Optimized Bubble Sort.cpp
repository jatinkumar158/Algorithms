// Author:- Jatin Kumar
#include<iostream>
using namespace std;
int main()
{
	int n,temp;
	bool sorted;
	cout<<"enter the no. of elements=";
	cin>>n;
	int array[n];
	cout<<"enter the elements=";
	for(int i=0;i<n;i++)
		cin>>array[i];
	cout<<"before sorting:\n";
	for(int i=0;i<n;i++)
		cout<<array[i]<<"\t";
	cout<<endl;
	for(int i=0;i<n-1;i++)
	{	
		sorted=false;
		for(int j=0;j<n-1-i;j++)
		{	
			// if array is already sorted then
			// it will not go into comparison code
			if(array[j]>array[j+1])
			{
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
				sorted=true;
			}
		}
		if(sorted==false)	// array is already sorted
			break;
	}
	cout<<"after sorting:\n";
	for(int i=0;i<n;i++)
		cout<<array[i]<<"\t";
	cout<<endl;
}
