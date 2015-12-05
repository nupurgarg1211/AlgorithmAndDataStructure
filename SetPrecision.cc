#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a=3.14567;
	double b=3;
	double c=a*b;
	cout<<"without precision= "<<c<<endl;
	cout<<fixed<<showpoint;
	cout<<"with precision 3= "<<setprecision(3)<<c<<endl;
	cout<<scientific;
	cout<<"with scientific= "<<setprecision(4)<<c<<endl;
	return 0;
}
