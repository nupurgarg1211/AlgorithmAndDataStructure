#include<stdio.h>
#include<stdlib.h>
#include<iostream>
 using namespace std;
int max(int a, int b);
 int L[6][7];

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
   if (m-1 == 0 || n-1 == 0)
   {
    	L[m-1][n-1]=0;	
     return 0;
   
   }
   if (X[m-1] == Y[n-1])
   {
    
	    if(L[m-1][n-1]==-1)
	    {
	    	L[m-1][n-1]=1 + lcs(X, Y, m-1, n-1);
	    	return L[m-1][n-1];
	    
	    }
	    else
	    {
	    	L[m-1][n-1];
	    }
    }
   else
   {
   	int A,B;
   	if(L[m][n-1]==-1)
   	{
   		A=lcs(X, Y, m, n-1);
   	}
   	else
   		A=L[m][n-1];
   	if(L[m-1][n]==-1)
   	{
   		B=lcs(X, Y, m-1, n);
   	}
   	else
   		B=L[m-1][n];
   	return max(A,B);		  
   }
     
}
 
/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Driver program to test above function */
int main()
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
 
  int m = 6;
  int n = 7;
  
  for(int i=0;i<m;i++)
  {
  	for(int j=0;j<n;j++)
  	{
  		L[i][j]=-1;
  	
  	}
  }
 for(int i=0;i<m;i++)
  {
  	for(int j=0;j<n;j++)
  	{
  		cout<<L[i][j]<<" ";
  	
  	}
  	cout<<endl;
  }	
  printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );
   for(int i=0;i<m;i++)
  {
  	for(int j=0;j<n;j++)
  	{
  		cout<<L[i][j]<<" ";
  	
  	}
  	cout<<endl;
  }
 
  getchar();
  return 0;
}
