// Implementer: Jatin Kumar
// Problem: Given an array of positive numbers,find the maximum sum of a subsequence 
// with the constraint that no 2 numbers in the sequence should be adjacent in the array. 
// time complexity: O(n)

#include<iostream>
using namespace std;
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n,diff;
		cin>>n;
		int array[n];
		for(int i=0;i<n;i++)
		{
			cin>>array[i];
		}
		int inclusive;
		int exclusive,temp;
		for(int i=0;i<n;i++)
		{
			if(i==0)
			{
				// initialisation step
				inclusive=array[i];
				exclusive=0;
			}
			else
			{
				temp=inclusive;
				if(exclusive+array[i]>inclusive)
				{
					inclusive=exclusive+array[i];
				}
				exclusive=temp;
			}
		}
		if(inclusive>exclusive)
			cout<<inclusive<<endl;
		else
			cout<<exclusive<<endl;
	}
}
