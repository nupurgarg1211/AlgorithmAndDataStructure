#include<iostream>
#include<stack>
using namespace std;
void printNextGreater(int a[],int size)
{
	stack<int> s;
	s.push(a[0]);
	for(int i=1;i<size;i++)
	{
		
		
		while(!(s.empty()) && a[i]>s.top() )
		{
			/*if(s.empty())
			{
				break;
			}*/
			cout<<s.top()<<" "<<a[i]<<endl;
			s.pop();
			//cout<<"here"<<endl;
		
		}
		
		s.push(a[i]);
	
	}
	while(!s.empty())
	{
		cout<<s.top()<<" "<<"-1"<<endl;
		s.pop();
	}
}

int main()
{
	//int a[]={1,5,2,3,4,9};
	int a[]={13, 7, 6, 12};
	int size=sizeof(a)/sizeof(a[0]);
	printNextGreater(a,size);
	return 0;
}
