// Author:- Jatin Kumar
// Dijkstra's Algorithm:- single source shortest path problem

#include<iostream>
#include<limits.h>
#include<stdlib.h>
using namespace std;
#define infinity INT_MAX
struct node
{
	int distance;
	int number;
};
int n,heapsize;
bool visited[100];
int visitedDistance[100];
struct node *heap[10];
void dijkstras(int*,int);
void buildheap();
void minheapify(int);
int source,flag=0;
struct node* extractmin();
int main()
{	
	// user input
	cout<<"enter the no. of vertices=";
	cin>>n;
	heapsize=n;
	int costMatrix[n][n];
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
	cout<<"enter the source=";
	cin>>source;
	fill_n(visitedDistance,n,-1);
	dijkstras(&costMatrix[0][0],source);
}
void dijkstras(int *costMatrix,int x)
{
	// initialize the nodes
	for(int i=0;i<n;i++)
	{
		heap[i]=(struct node*)malloc(sizeof(struct node));
		heap[i]->distance=infinity;
		heap[i]->number=i;
	}
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	// we shall start from vertex x
	heap[x]->distance=0;
	buildheap();
	while(heapsize!=0)
	{	
		// delete minimum element from the heap
		struct node *temp=extractmin();
		int value=temp->number;
		for(int i=0;i<n;i++)
		{	
			// find neighbour nodes of that node
			if(visited[i] || *(costMatrix+value*n+i)==infinity)
			{
				continue;
			}
			else
			{
				// i is adjacent
				int newDistance=*(costMatrix+value*n+i);
				for(int j=0;j<heapsize;j++)
				{
					if(heap[j]->number==i)
					{
						// we are at node i
						// this is relax operation
						if(heap[j]->distance>newDistance+visitedDistance[value])
						{
							heap[j]->distance=newDistance+visitedDistance[value];
							int k=j;
							while(k>=0 && heap[k]->distance<heap[(k-1)/2]->distance)
							{	
								temp=heap[k];
								heap[k]=heap[(k-1)/2];
								heap[(k-1)/2]=temp;
								k=(k-1)/2;
							}
						}
						break;
					}
				}

			}
		}
		
	}
}
void buildheap()
{
	for(int i=(heapsize/2)-1;i>=0;i--)
	{
		minheapify(i);
	}
}
void minheapify(int i)
{
	int left=2*i+1;
	int right=2*i+2;
	int smallest;
	if(left<heapsize)
	{
		if(heap[left]->distance<heap[i]->distance)
		{
			smallest=left;
		}
		else
		{
			smallest=i;
		}
	}
	else
	{
		return;
	}
	if(right<heapsize)
	{
		if(heap[right]->distance<heap[smallest]->distance)
		{
			smallest=right;
		}
	}
	if(smallest!=i)
	{
		struct node *temp=heap[i];
		heap[i]=heap[smallest];
		heap[smallest]=temp;
		minheapify(smallest);
	}
}
struct node* extractmin()
{
	struct node *temp=heap[0];
	visited[temp->number]=true;
	visitedDistance[temp->number]=temp->distance;
	if(flag==0)
	{
		cout<<"\n\npath\tdistance\n";
		flag=1;
	}
	cout<<source<<"-----"<<temp->number;
	if((temp->distance==infinity || temp->distance<0))
	{
		cout<<"\t No path exists\n";
	}
	else
	{
		cout<<"\t   "<<temp->distance<<endl;
	}
	heap[0]=heap[heapsize-1];
	heapsize--;
	buildheap();
	return temp;
}
