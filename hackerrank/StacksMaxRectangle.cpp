#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

stack<int> S;

int solve()
{
	int maxArea = -1;
	int n = 1;
	while (S.size() != 0)
	{
		int ele = S.top();
		if (n*ele > maxArea)
			maxArea = n*ele;
	}
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
	cin>>N;
	int h;
	for (int i = 0; i < N; i++)
	{
		cin>>h;
		S.push(h);	
	}
	cout<<solve()<<endl;
    return 0;
}

