#include<iostream>
using namespace std;
class ArrayOpp
{
	public:
	void rotate(int a[],int d,int n);
	int gcd(int a,int b);
	void printArray(int a[],int n);

};
int ArrayOpp::gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	else
	{
		gcd(b,a%b);
	}

}
void ArrayOpp::printArray(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
	
		cout<<a[i]<<" ";
	}

}
void ArrayOpp::rotate(int a[],int d,int n)//d=rotate by d places,n=size of array
{
	int i=0,j,k;
	int group=gcd(d,n);
	cout<<group<<endl;
	while(i<group)
	{
		j=i;
		int temp=a[i];
		cout<<"temp="<<temp<<endl;
		while(1)
		{
			k=j+d;
			cout<<"in while";
			if (k >= n)
       				 k = k - n;
      			if (k == i)
      				  break;
			
			
			a[j]=a[k];
			cout<<"j="<<j<<"k="<<k<<endl;
			j=k;
		}
		
		a[j]=temp;
		cout<<"a[j]="<<a[j]<<"j="<<j<<endl;;
		i++;
	}

}
int main()
{
	int n,d;
	cin>>n;
	cin>>d;
	int a[n];
	ArrayOpp ob1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	
	}
	ob1.rotate(a,d,n);
	ob1.printArray(a,n);
	return 0;
}

