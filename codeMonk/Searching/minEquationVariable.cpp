#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long int t,a,b,c,k,x;
	double root,root1,root2;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>k;
		c=c-k;
		if(c==0)
		{
			cout<<"0"<<endl;
			continue;
		}
		root=sqrt((b*b-4*a*c));
		root1=(root+((-1)*b));
		root1=root1/(2*a);
		root2=(-1)*(root+b);
		root2=root2/(2*a);
		if(root2>=0)
		{
			cout<<ceil(root2)<<endl;
		
		}
		else if(root1>=0)
		cout<<ceil(root1)<<endl;	
	
	
	}

	return 0;
}
