#include<iostream>
using namespace std;
int main()
{
	char a[][7]={
			{'*','*','*','>','*','*','*'},
			{'*','*','*','|','*','*','*'},
			{'*','*','*','|','*','*','*'},
			{'*','*','*','|','*','*','*'}
		};
	int n=sizeof(a)/sizeof(a[0]);	
	//cout<<n;
	char ans[7][4];
	int col=7,row=n;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			//cout<<a[j][i]<<" ";
			//cout<<j<<" "<<row-i-1<<endl;
			ans[j][row-i-1]=a[i][j];
		}
		//cout<<endl;
	
	}
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
