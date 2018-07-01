// Author:- Jatin Kumar
#include<iostream>
using namespace std;
int main()
{
	int n,i,j,key;
	cout<<"enter the size of array=";
	cin>>n;
	int array[n];
	cout<<"enter elements=";
	for(i=0;i<n;i++)
		cin>>array[i];
	for(j=1;j<n;j++)
	{
		key=array[j];
		i=j-1;
		while(i>=0 && array[i]>key)
		{
			array[i+1]=array[i];
			i--;
		}
		array[i+1]=key;
	}
	cout<<"sorted array is given by:\n";
	for(i=0;i<n;i++)
		cout<<array[i]<<"\t";
	cout<<"\n";

}
