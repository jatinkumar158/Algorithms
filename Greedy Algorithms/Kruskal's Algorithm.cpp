// Author :- Jatin Kumar
// Implementation of Kruskal's Algorithm
// based on greedy approach

#include<bits/stdc++.h>
using namespace std;
#define infinity INT_MAX
int n,edges=0,minimum,result,minCost=0;
int find(int,int*);
int uni(int,int,int*);
int main()
{
	cout<<"enter the no. of vertices=";
	cin>>n;
	int parent[n];
	fill_n(parent,n,-1);
	int costMatrix[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>costMatrix[i][j];
			if(i==j || costMatrix[i][j]==0)
			{
				costMatrix[i][j]=infinity;
			}
		}
	}
	int u,v,a,b,flag=0;
	cout<<"\n\n";
	while(edges!=(n-1))
	{	
		minimum=infinity;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(costMatrix[i][j]==infinity)
					continue;
				else
				{
					if(minimum>costMatrix[i][j])
					{
						minimum=costMatrix[i][j];
						a=i;
						b=j;
					}
				}
			}
		}
		u=find(a,parent);
		v=find(b,parent);
		result=uni(u,v,parent);
		if(flag==0)
		{
			cout<<"edge\tweight\n";
			flag=1;
		}
		if(result)
		{
			minCost=minCost+minimum;
			cout<<a<<"--"<<b<<"\t"<<minimum<<"\n";
			edges++;
		}
		costMatrix[a][b]=infinity;
		costMatrix[b][a]=infinity;
	}
	cout<<"minimum cost is "<<minCost<<"\n\n\n";
}
int find(int x,int *parent)
{	
	if(parent[x]==-1)
		return x;
	else
		return find(parent[x],parent);
}
int uni(int i,int j,int *parent)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	else
		return 0;
}
