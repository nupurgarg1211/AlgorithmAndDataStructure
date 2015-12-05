/*1 2 3 4
5 6 7 8 
9 10 11 12
13 14 15 16 


o/p:1 2 3 4 8 12 16 16 14 13 9 5 6 7 11 10 */
#include<iostream>
const int m= 3;
const int n=4;
using namespace std;
void printSpiral(int input[m][n],int row,int col)
{
	int i, newR=0,newC=0;
	for(i=newR;i<col;i++)
	{
		cout<<input[newR][i]<<" ";
	}
	for(i=newC;i<row;i++)
	{
		cout<<input[i][newC]<<" ";
	}
	if()
	
}
int main()
{
	int input[][4]={
		{1 ,2 ,3, 4},
		{5, 6 ,7, 8 },
		{9, 10, 11, 12}
		//{13 ,14 ,15 ,16 }
	};
	
	//int size=sizeof(input)/sizeof(input[0]);
	//cout<<size<<endl;
	printSpiral(input,m,n);
	


}
