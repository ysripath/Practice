#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void solve(int n, int r, int arr[])
{
	int* tempArr = new int[r];
	for (int i = 0; i < r; i++)
		tempArr[i] = arr[i];
	for (int i = r; i < n; i++)
		arr[i-r] = arr[i];
	int k = 0;
	for (int i = n-r; i < n; i++)
	{
		arr[i] = tempArr[k++];
	}
	for (int i = 0; i <n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int n, r;
	cin>>n>>r;
	int* arr  = new int[n];
	for (int i = 0; i <n; i++)
		cin>>arr[i];
	solve(n,r,arr);
    return 0;
}

