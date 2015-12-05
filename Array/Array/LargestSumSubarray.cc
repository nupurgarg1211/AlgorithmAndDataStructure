/* 
Write an efficient C program to find the sum of contiguous subarray within a one-dimensional array of
 numbers which has the largest sum.*/
 #include<iostream>
 using namespace std;
 int main()
 {
 	int a[]={-2, -3, 4, -1, -2, 1, 5, -3};
 	int maxending_here=0,MaxsoFar=0,n;
 	n=sizeof(a)/sizeof(a[0]);
 	for(int i=0;i<n;i++)
 	{
 		maxending_here+=a[i];
 		if(maxending_here>0 && maxending_here>MaxsoFar)
		{
			MaxsoFar=maxending_here;
		
		} 		
		if(maxending_here<0)
		maxending_here=0;
 	}
 	cout<<MaxsoFar<<endl;
 	return 0;
 }
