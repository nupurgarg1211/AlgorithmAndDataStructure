#include<iostream>
#include<algorithm>
using namespace std;

class Word
{
	string str;
	int index;
	public:
	string getstr();
	int getindex();
	void setindex(int a);
	void setstr(string a);
	Word* createduplicate(int size,string input[],Word duplicate[]);
	void sortcharofwords(int size,Word duplicate[]);
	void sortduplicate(int size,Word duplicate[]);
	
};
string Word::getstr()
{
	return str;
}
int Word::getindex()
{
	return index;
}
void Word::setindex(int a)
{
	index=a;
}
void Word::setstr(string a)
{

	str=a;
}
Word* Word::createduplicate(int size,string input[],Word duplicate[])
{
	//Word duplicate[size];
	for(int i=0;i<size;i++)
	{
		duplicate[i].index=i;
		duplicate[i].str=input[i];
	
	}
	return duplicate;
}
void Word:: sortcharofwords(int size,Word duplicate[])
{
	for(int i=0;i<size;i++)
	{
		sort(duplicate[i].str.begin(),duplicate[i].str.end());
	}
}

/*void Word::sortduplicate(int size,Word duplicate[])
{
	sort(duplicate,duplicate+size,comp);
}*/

bool comp(Word &a,Word &b)
{
	return a.getstr()<b.getstr();
}
int main()
{
	Word duplicate[5];
	Word ob1;
	string input[5];
	for(int i=0;i<5;i++)
	{
		cin>>input[i];
	}
	ob1.createduplicate(5,input,duplicate);
	for(int i=0;i<5;i++)
	{
		cout<<duplicate[i].getindex()<<" "<<duplicate[i].getstr()<<endl;
	}
	ob1.sortcharofwords(5,duplicate);
	cout<<endl;
	
	sort(duplicate,duplicate+5,comp);
	cout << "aftersorting\n";
	for(int i=0;i<5;i++)
	{
		cout<<duplicate[i].getindex()<<" "<<duplicate[i].getstr()<<endl;
	}
	for(int i=0;i<5;i++)
	{
		cout<<input[duplicate[i].getindex()]<<endl;
	}
	return 0;
} 
