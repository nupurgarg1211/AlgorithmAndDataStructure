#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double n=14,k=2;
	int power=log2(n);
	//cout<<power<<endl;
	int pos=2*(n-pow(2,power))+1;
	cout<<pos;
	return 0;
}
