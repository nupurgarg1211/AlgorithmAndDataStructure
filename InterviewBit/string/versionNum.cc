/*   
Compare two version numbers version1 and version2.

        If version1 > version2 return 1,
        If version1 < version2 return -1,
        otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 1.13

*/

#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int main()
{
	string a,b;
	cin>>a>>b;
	int i=0;
	while(a[i]!='.')
	{
		i++;	
	}
	string str1=a.substr(0,a.length()-i+1);
	int x=atoi(str1);
	cout<<x<<endl;
	return 0;
}
