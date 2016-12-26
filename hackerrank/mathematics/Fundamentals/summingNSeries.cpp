#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long double TN(long double n)
{
	return ((n*n) - ((n-1)*(n-1)));
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int T;
	cin>>T;
	long double sum = 0;
	while(T!=0)
	{
		long double n;
		cin>>n;
		//for (long double i =1; i <= n; i++)
		//{
			//sum+=TN(i);
		//}
		n = (long int)n % 1000000007;
        	sum = n*n;
		cout<<(long int)sum%1000000007<<endl;
		sum = 0;
		T--;
	}
    return 0;
}

