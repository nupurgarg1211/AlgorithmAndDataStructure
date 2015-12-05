#include<iostream>
#include<vector>
using namespace std;
int main()
{
	std::vector<int> foodPacket;
	int q,type,c;
	std::cin>>q;
	vector <int> ::iterator it;
	//it=foodPacket.begin();
	while(q--)
	{
		std::cin>>type;
		if(type==1)
		{
			if(foodPacket.size()==0)
			{
			
				std::cout<<"No Food"<<std::endl;
			}	
			else
			{
				it=foodPacket.end()-1;
				std::cout<<*it<<endl;
				//foodPacket.erase(foodPacket.begin());
				foodPacket.pop_back();
				//it--;
			}
		}
		else if(type==2)
		{
			std::cin>>c;
			foodPacket.push_back(c);
			//*it=c;
			//it++;
		
		}
	
	}
	return 0;
}
