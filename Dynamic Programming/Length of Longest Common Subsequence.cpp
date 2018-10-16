// Written By: Jatin Kumar
// Length of longest common subsequence
// Based on dynamic programming
// Bottom up approach is used

#include<iostream>
#include<string.h>
using namespace std;
int maxElement(int,int);
int main()
{	
	int m,n;
	char x[20],y[20];
	cout<<"enter first string=";
	cin>>x;
	cout<<"enter second string=";
	cin>>y;
	m=strlen(x);
	n=strlen(y);
	int table[m+1][n+1];	
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{	
			if(i==0 || j==0)
			{
				table[i][j]=0;
			}
			else if(x[i-1]==y[j-1])
			{
				table[i][j]=1+table[i-1][j-1];
			}
			else
			{
				table[i][j]=maxElement(table[i][j-1],table[i-1][j]);
			}
		}
	}
	cout<<"length of longest common subsequence is "<<table[m][n]<<endl;
}
int maxElement(int x,int y)
{
	return (x>y?x:y);
}
