// Implementer: Jatin Kumar
// Problem: Given an array of size n.
// find the element which occure more than n/2 times
// Moore's Voting Algorithm is used
// Time Complexity: O(n)

#include<iostream>
using namespace std;
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int array[n];
		for(int i=0;i<n;i++)
		{
			cin>>array[i];
		}
		int count=0,candidate=array[0];
		for(int i=0;i<n;i++)
		{
			if(array[i]==candidate)
			{
				count++;
			}
			else
			{
				count--;
			}
			if(count==0)
			{
				candidate=array[i];
				count=1;
			}
		}
		count=0;
		for(int i=0;i<n;i++)
		{
			if(array[i]==candidate)
				count++;
		}
		if(count>n/2)
		{
			cout<<candidate<<endl;
		}
		else
		{
			cout<<"NO Majority Element"<<endl;
		}
	}
}
