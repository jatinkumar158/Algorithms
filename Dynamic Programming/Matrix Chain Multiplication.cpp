// Implementer: Jatin Kumar
// Matrix chain multiplication problem
// given the matrices, we have to find minimum no. of scalar multiplications
// dynamic programming bottom up approach is used
// time complexity= O(n^3)

#include<iostream>
#include<limits.h>
using namespace std;
#define infinity INT_MAX
int main()
{	
	int n,c,r;
	cout<<"enter the no. of matrices=";
	cin>>n;
	int m[n+1][n+1];	// assumption: matrix will start from index 1
	int p[n+1];			// to store the size of matrices
	for(int i=0;i<n;i++)
	{
		cout<<"enter the size of matrix "<<i+1<<": ";
		cin>>r>>c;
		if(i==n-1)
		{
			p[i]=r;
			p[i+1]=c;
		}
		else
		{
			p[i]=r;
		}
	}
	// make diagonal elements of the matrix zero
	for(int i=1;i<=n;i++)
	{
		m[i][i]=0;
	}
	for(int l=2;l<=n;l++)	// l represent the length
	{
		for(int i=1;i<=n-l+1;i++)
		{
			int j=l+i-1;
			m[i][j]=infinity;
			for(int k=i;k<=j-1;k++)
			{
				int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
				}
			}
		}
	}
	cout<<"minimum cost of multiplication is "<<m[1][n]<<endl;
}
