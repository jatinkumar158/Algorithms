// Implementer: Jatin Kumar
// Kadane's Algorithm (Dynamic Programming)
// for maximum sum subarray problem
// time complexity: O(n)


#include<iostream>
using namespace std;
int main()
{
		int n;
		cout<<"enter no. of elements:";
		cin>>n;
		int array[n];
		cout<<"enter elements:";
		for(int i=0;i<n;i++)
		{
			cin>>array[i];
		}
		int max=array[0],current=array[0];
		for(int i=1;i<n;i++)
		{
			if(array[i]+current>array[i])
			{
				current=array[i]+current;
			}
			else
			{
				current=array[i];
			}
			if(current>max)
			{
				max=current;
			}
		}
		cout<<"maximum sum is "<<max<<endl;
}
