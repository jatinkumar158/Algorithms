// Implementer: Jatin Kumar
// Linear Search 
// Time Complexity: O(n)

#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"enter size of array=";
	cin>>n;
	int array[n];
	cout<<"enter elements:";
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
	}
	int counter;
	cout<<"enter the element to be searched:";
	cin>>counter;
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(array[i]==counter)
		{	
			flag=1;
			cout<<"element is found at index "<<i<<endl;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"Element is not presesnt"<<endl;
	}
}
