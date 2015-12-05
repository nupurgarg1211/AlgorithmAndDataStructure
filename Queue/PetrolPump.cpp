#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<string>
#include<cstdlib>

using namespace std;
struct PetrolPump
{
	int petrol;
	int distance;

};
int FindStartingPoint(struct PetrolPump p[],int n)
{
	int current_petrol=0;
	int start=0,end=1;
	current_petrol=p[start].petrol - p[start].distance;
	while(current_petrol<0 ||start!=end)
	{
		while(current_petrol<0&&start!=end)
		{
			current_petrol=current_petrol-((p[start].petrol-p[start].distance));
			start=(start+1)%n;
			cout<<"c_petrol="<<current_petrol<<endl;
			cout<<"start="<<start<<endl;
			if(start==0)
			return -1;
		}
		
		current_petrol+=p[end].petrol-p[end].distance;
		end=(end+1)%n;
		cout<<"c_petrol="<<current_petrol<<endl;
		cout<<"end="<<end<<endl;
	
	}
	return start;

}
int main()
{
	struct PetrolPump p[]={{6,4},{3,6},{7,3}};
	int n=sizeof(p)/sizeof(p[0]);
	int start=FindStartingPoint(p,n);
	cout<<start<<endl;			
	return 0;	
}
