#include<iostream>

using namespace std;

void print(int *arr, int m, int n){
	//arr=()
	for (int i = 0; i < m; i++){
      	for (int j = 0; j < n; j++)
			//cout<<arr[i][j]<<" ";
			cout << *((arr+i*n)+j) << " ";
		cout << endl;
	}
}

int main(){
	int l = 3;
	int r = 3;
	int array[l][r] = { {1,2,3},
			    		{4,5,6},
			    		{7,8,9} };
	print((int*)array,l,r);
	return 0;
}
