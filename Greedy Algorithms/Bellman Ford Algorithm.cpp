// Author:- Jatin Kumar
// Bellman Ford Algorithm
// based on greedy approach
// Good results in case of negetive weight graphs

#include<iostream>
#include<limits.h>
#define infinity INT_MAX/2
using namespace std;
int main()
{
	int n,source;
	cout<<"enter the no. of vertices:";
	cin>>n;
	int costMatrix[n][n];
	int distance[n];
	cout<<"enter cost matrix:\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>costMatrix[i][j];
			if(i==j || costMatrix[i][j]==0)
				costMatrix[i][j]=infinity;
		}
	}
	// now bellman ford algorithm begins
	// initialization step
	cout<<"enter the source vertex:";
	cin>>source;
	distance[source]=0;
	for(int i=0;i<n;i++)
	{	
		 if(i==source)
		 	continue;
		distance[i]=infinity;
	}
	// relax each edge n-1 times
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(costMatrix[j][k]!=infinity)
				{
					// there is an edge from j to k
					// so relax this edge
					if(distance[j]+costMatrix[j][k]<distance[k])
					{	
						distance[k]=distance[j]+costMatrix[j][k];
					}
				}
			}
		}
	}
	// after relaxing edges n-1 times 
	// Bellman Ford algorithm do one more relaxation step
	// if distances are updated then -ve cycle exists
	// and therefore no shortest path exists
	for(int j=0;j<n;j++)
	{
		for(int k=0;k<n;k++)
		{
			if(costMatrix[j][k]!=infinity)	// important
			{
				if(distance[j]+costMatrix[j][k]<distance[k])
				{
					cout<<"negetive cycle(loop) is there so no shortest path exits\n";
					return 0;
				}
			}
		}
	}


	cout<<"shortest paths are given by:\n";
	cout<<"\n\nPath\tDistance\n";
	for(int i=0;i<n;i++)
	{	
		if(distance[i]==infinity)
		{
			cout<<source<<"----"<<i<<"\t"<<"No path exists"<<"\n";	
		}
		else
		{
			cout<<source<<"----"<<i<<"\t"<<distance[i]<<"\n";
		}
	}
	cout<<"\n";
}
