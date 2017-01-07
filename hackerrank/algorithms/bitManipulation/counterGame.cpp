#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long arr[64];

bool isPower(unsigned long long N)
{
	for (int i = 0; i < 63; i++)
		if (arr[i] == N)
			return true;
	return false;
}

int check(unsigned long long N)
{
	
	for (int i = 0; i < 64; i++)
	{
		arr[i] = pow(2,i);
	}
	bool flag = true;
	if (N==1)
		return 2;
	else
		{
			while(N!=1)
			{
				if (flag)
				{
					cout<<"Louis\n";
					flag = false;
				}
				else
				{
					cout<<"Richard\n";
					flag = true;
				}
				if (isPower(N))
				{
					N = N/2;
				}
				else
				{
					int k;
					for (k = 0; k < 64; k++)
					{
						if (arr[k] > N)
							break;
					}
					k--;
					N = arr[k];
					N = N/2;
				}
			}
		}
		if (flag)
			return 2;
		else
			return 1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int T;
	cin>>T;
	while (T != 0)
	{
		int N;
		cin>>N;
		int result = check(N);
		if (result == 1)
			cout<<"Louis\n";
		else
			cout<<"Richard\n";
		T--;
	}   
    return 0;
}

