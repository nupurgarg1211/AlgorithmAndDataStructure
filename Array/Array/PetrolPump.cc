#include<iostream>
using namespace std;
struct petrolPump
{
	int petrol;
	int distance;
};
bool FindStart(petrolPump a[],int n)
{

	int currentPetrol=0;
	int start=0;
	int end=1;
	currentPetrol=a[0].petrol-a[0].distance;
	
	while(start!=end)
	{
		
		while(currentPetrol<0 )
		{
			currentPetrol=currentPetrol+(a[start].distance)-a[start].petrol;
			start=(start+1)%n;
			if(start==0)
			{
				return false;
			}
			
		}
		currentPetrol=currentPetrol+(a[end].petrol)-a[end].distance;
		end=(end+1)%n;
	}
	cout<<start<<endl;
	return true;
}
int main()
{
	petrolPump a[]={{4, 6}, {6, 5}, {7, 3} ,{4, 5}};
	int n=sizeof(a)/sizeof(a[0]);
	FindStart(a,n);
	return 0;
}
