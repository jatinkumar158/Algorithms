// Author:- Jatin Kumar
// Job Sequencing with deadlines:- given n jobs with their deadlines and profits
// task is to maximize the profit and job should be completed before its deadline
// greedy approach is used
// pick the job with maximum profit and place it as near as to it's deadline so that
// jobs having less deadline than it can also fit inside the array
// time complexity= O(n^2)

#include<bits/stdc++.h>
using namespace std;
// define the structure for the job
struct object
{
	char jobid;
	int deadline;
	int profit;
};
// as usual compare function
bool compare(struct object *x,struct object *y)
{
	return x->profit>y->profit;
}
int main()
{	
	int n,size,max,totalprofit=0;
	cout<<"enter the no. of jobs=";
	cin>>n;
	struct object *obj[n];
	// user input and finding maximum deadline
	for(int i=0;i<n;i++)
	{	
		obj[i]=(struct object*)malloc(sizeof(struct object));
		cout<<"enter jobid,deadline and profit of job "<<i+1<<":";
		cin>>obj[i]->jobid>>obj[i]->deadline>>obj[i]->profit;
		if(i==0)
		{
			max=obj[i]->deadline;
		}
		else
		{
			if(obj[i]->deadline>max)
				max=obj[i]->deadline;
		}
	}
	// sort them according to their profit
	size=sizeof(obj)/sizeof(obj[0]);
	sort(obj,obj+size,compare);
	// create array of max deadline size
	char array[max]={'\0'};	// null indicates that cell is empty
	for(int i=0;i<n;i++)
	{	
		// now pick the job with max deadline and
		// from that deadline traverse array back
		// to find an empty slot
		for(int j=(obj[i]->deadline)-1;j>=0;j--)
		{
			if(array[j]=='\0')	// cell is empty
			{	
				// count the total profit
				totalprofit=totalprofit+obj[i]->profit;
				array[j]=obj[i]->jobid;
				break;
			}
		}
	}
	// here will be the desired output
	cout<<"jobs selectd are:"<<"\t";
	for(int i=0;i<max;i++)
	{	
		if(array[i]=='\0')
			continue;
		cout<<array[i]<<"\t";
	}
	cout<<"\ntotal profit is "<<totalprofit<<"\n";
}
