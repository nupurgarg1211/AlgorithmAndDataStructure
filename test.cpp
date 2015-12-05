#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;

bool compare(const string &a, const string &b){
	return a < b;
}
int main()
{
	string a[] = {"cat","dog","tac","god","act"};
	sort(a,a+5,compare);		
	for(int i = 0; i < 5; i++)
		cout << a[i] << endl;	
	return 0;	
}
