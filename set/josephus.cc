#include<iostream>
using namespace std;
int f(int n,int k)
{
	if(n==1)
	{
		return 1;
	}
	else
	{
		return (f(n-1,k)+k-1)%n+1;
	}

}
int main()
{
	int n=14,k=2;
	int pos=f(n,k);
	cout<<pos<<endl;
	return 0;
}
