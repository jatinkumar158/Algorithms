// Author:- Jatin Kumar
// Prim's Algorithm for finding minimum cost spanning tree
// time complexity=O(V^2)
// based on greedy approach

#include<bits/stdc++.h>
using namespace std;
int prims(int*);
void printEdgeList(int*);
int infinity=INT_MAX;
int n;
int main()
{
	cout<<"enter the no. of vertices=";
	cin>>n;
	int costMatrix[n][n];
	cout<<"enter cost matrix:\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>costMatrix[i][j];
			if(i!=j && costMatrix[i][j]==0)
			{
				costMatrix[i][j]=infinity;
			}
		}
	}
	int result=prims(&costMatrix[0][0]);
	cout<<"\n\nminimum cost is "<<result<<"\n";
}
int prims(int *costMatrix)
{
	int edgeList[n-1][3],minCost=0,k,l,minEdge,flag,counter;
	// find out edge with minimum cost
	// assume (0,1) to be minimum and then find actual minimum
	minEdge=*(costMatrix+0*n+1);
	k=0;
	l=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(*(costMatrix+i*n+j)==0)
			{
				continue;
			}
			else
			{
				if(minEdge>*(costMatrix+i*n+j))
				{
					minEdge=*(costMatrix+i*n+j);
					k=i;
					l=j;
				}
			}
		}
	}
	// k and l are end points of the edge
	// now add edge to our edge list
	// add its cost to our minCost variable;
	minCost=*(costMatrix+k*n+l);
	edgeList[0][0]=k;
	edgeList[0][1]=l;
	edgeList[0][2]=minCost;
	cout<<"min cost is "<<minCost<<endl;
	// now create an array named near that will find out adjacent edges and will keep track of all edges
	int near[n];
	// near[i]=j;  means that i is closest to j
	for(int i=0;i<n;i++)
	{
		// we shall check node i is closer to k or l
		if(*(costMatrix+i*n+k)<*(costMatrix+i*n+l))
		{
			near[i]=k;
		}
		else
		{
			near[i]=l;
		}
	}
	// as k and l are already added to our spanning tree
	// so make them -1 in near array
	near[k]=-1;
	near[l]=-1;
	// now run a loop for remaining edges
	for(int i=1;i<n-1;i++)
	{
		// find minimum cost edge
		flag=0;
		for(int j=0;j<n;j++)
		{
			if(near[j]==-1)
			{
				continue;
			}
			else
			{
				if(flag==0)
				{
					minEdge=*(costMatrix+j*n+near[j]);
					counter=j;
					flag=1;
				}
				else
				{
					if(minEdge>*(costMatrix+j*n+near[j]))
					{
						minEdge=*(costMatrix+j*n+near[j]);
						counter=j;
					}
				}
			}
		}
		// now we have index to node which is to be added in spanning tree
		// add this edge to our edge list
		edgeList[i][0]=counter;
		edgeList[i][1]=near[counter];
		edgeList[i][2]=minEdge;
		// compute cost
		minCost=minCost+*(costMatrix+counter*n+near[counter]);
		// as counter node is added to our tree so
		near[counter]=-1;
		// now we shall check whether our near list has some effect of this added node or not
		for(int j=0;j<n;j++)
		{
			if(near[j]!=-1 && *(costMatrix+j*n+near[j])>*(costMatrix+j*n+counter))
			{
				near[j]=counter;
			}
		}
	}
	printEdgeList(&edgeList[0][0]);
	return minCost;
}
void printEdgeList(int *temp)
{	
	cout<<"\n\nedges of spanning tree are given by:\n\n";
	cout<<"edge\tweight\n";
	for(int i=0;i<n-1;i++)
	{
		cout<<*(temp+i*3+0)<<"----"<<*(temp+i*3+1)<<"\t"<<*(temp+i*3+2)<<"\n";
	}
}
