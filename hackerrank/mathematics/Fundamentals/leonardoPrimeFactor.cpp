#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 1 is not a prime number

long double n;

bool isPrime(long double n)
{
	long double sN = sqrt(n);
	for (long double i = 2; i <= sN; i++)
	{
		if (((long int)n%(long int)i) == 0)
			return false;
	}
	return true;
}


void solve()
{
	if (n == 1)
	{
		cout<<"0\n";
		return;
	}
	else if (n == 2)
	{
		cout<<"1\n";
		return;
	}
	int count = 0;
	long double prod = 1;
	for (long double i = 2; i <= n; i++)
	{
		if (isPrime(i))
		{
			prod *= i;
			if (prod > n)
			{
				cout<<count<<endl;
				return;
			}
			count++;
			if (prod == n)
			{
				cout<<count<<endl;
				return;
			}
		}
	}
	
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int q;
	cin>>q;
	while (q != 0)
	{
		cin>>n;
		solve();
		q--;
	}
    return 0;
}

