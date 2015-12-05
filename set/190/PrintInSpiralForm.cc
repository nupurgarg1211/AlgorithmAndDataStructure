/*1 2 3 4
5 6 7 8 
9 10 11 12
13 14 15 16 


o/p:1 2 3 4 8 12 16 16 14 13 9 5 6 7 11 10 */
#include<iostream>
using namespace std;
void printSpiral(int input[][4],int size)
{
	int flag=0,j=0,i=0;
	for(int k=0;k<=size*size;k++)
	{
		if(flag==0 )
		{
			//cout<<"i="<<i<<" "<<"j="<<j<<endl;			
			if(j<size && input[i][j]!=-1)
			{
				cout<<input[i][j]<<" ";
				input[i][j]=-1;
				j++;
			}
			else
			{
				i++;
				flag=1;
				j--;
			}
		}
		if(flag==1)
		{
			//cout<<"i="<<i<<" "<<"j="<<j<<endl;
			
			if(i<size && input[i][j]!=-1 )
			{
				cout<<input[i][j]<<" ";
				input[i][j]=-1;
				i++;
			
			}
			else
			{
				i--;
				j--;	
				flag=2;
			}
		}
		if(flag==2)
		{
			//cout<<"i="<<i<<" "<<"j="<<j<<endl;
			if(j>=0 && input[i][j]!=-1)
			{
				cout<<input[i][j]<<" ";
				input[i][j]=-1;
				j--;
			}
			else
			{
				j++;
				i--;
				flag=3;
			}	
		}
		if(flag==3)
		{
			//cout<<"i="<<i<<" "<<"j="<<j<<endl;
			if(i>=0 && input[i][j]!=-1)
			{
				cout<<input[i][j]<<" ";
				input[i][j]=-1;
				i--; 
			}
			else
			{
				i++;
				j++;
				flag=0;
			}
		}
	}
	
}
int main()
{
	int input[][4]={
		{1 ,2 ,3, 4},
		{5, 6 ,7, 8 },
		{9, 10, 11, 12}
		//{13 ,14 ,15 ,16 }
	};
	int size=sizeof(input)/sizeof(input[0]);
	cout<<size<<endl;
	printSpiral(input,size*4);
	


}
