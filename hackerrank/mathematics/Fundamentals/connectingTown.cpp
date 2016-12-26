#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int T;
	cin>>T;
	int n;
	int prod = 1;
	int temp;
	while (T!=0)
	{
		cin>>n;
		n--;
		for (int i = 0; i <n; i++)
		{
			cin>>temp;
			prod =  (prod*temp)%1234567;
		}
		cout<<prod<<endl;
		prod = 1;
		T--;
	}
    return 0;
}

