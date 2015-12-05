/* Print max element in increasing and then decreasing array ex:

	34 45 47 56 67  78 89 90 98 97 99 65 63 52 41
	
	99 is the max element
 */
 #include<iostream>
 using namespace std;
 int findMax(int a[],int l,int r)
 {
 	if(l==r)
 	{
 		return a[l];
 	}
 	if(r==l+1 && a[r]>a[l])
 	{
		return a[r];
	}
	if(r==l+1 && a[r]<a[l])
 	{
		return a[r];
	}

 	int mid=(l+r)/2;
 	if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
 	{
 	
 		return a[mid];
 	}
 	else if(a[mid]<a[mid+1] && a[mid]>a[mid-1])
 	{
 		return findMax(a,mid+1,r);
 	}
 	else if(a[mid]>a[mid+1] && a[mid]<a[mid-1]) 
 	{
		return findMax(a,l,mid-1);
	}
 
 }
 int main()
 {
 	int a[]={1, 3, 50, 10, 9, 7, 6};
 	int n=sizeof(a)/sizeof(a[0]);
 	int max=findMax(a,0,n-1);
 	cout<<max<<endl;
 	return 0;
 }
