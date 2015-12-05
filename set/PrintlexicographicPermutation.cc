#include<iostream>
#include<algorithm>
using namespace std;
int comp(const void * a,const void * b)
{
	return (*(char *)a-*(char *)b) ;
	

}
int findCeil(char first,string s,int l,int h)
{
	int ceil=l;
	for(int i=l+1;i<=h;i++)
	{
		if(first<s[i] && s[ceil]>s[i])
		{
			ceil=i;
		}
	}
	return ceil;
}
void swap(char &a,char &b)
{
	char temp=a;
	a=b;
	b=temp;

}
void reverse(string s,int l,int h)
{
	while(l<h)
	{
		swap(s[l],s[h]);
		l++;
		h--;
	
	}
}
void printSortedPermutation(string s,int size)
{
	//qsort(a,size,sizeof(a[0]),comp);
	//sort(s.begin()+1,s.begin()+4);
	//cout<<s<<endl;
	//int first,second;
	bool isFinished=false;
	sort(s.begin(),s.end());
	
	while(!isFinished)
	{
		cout<<s<<endl;
		int i;
		for(i=size-2;i>=0;i--)
		{
			if(s[i]<s[i+1])
			break;
	
		}
		if(i==-1)
		{
			isFinished=true;
		}
		else
		{
			//first=i;
			int ceilIndex=findCeil(s[i],s,i+1,size-1);
			//cout<<ceilIndex<<" "<<i<<endl;
			swap(s[i],s[ceilIndex]);
			sort(s.begin()+i+1,s.end());
			//cout<<s<<endl;
			cout<<i+1<<" "<<size-1<<endl;
			//reverse(s,i+1,size-1);
		}
	}
}
int main()
{
	//char a[]="ABCD";
	string a="ACBC";
	//int a[]={6,4,8,2,9};
	int size=a.length();
	printSortedPermutation(a,size);
	return 0;
}
