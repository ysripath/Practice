#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int N;
	int Q;
	cin>>N;
	string* arr = new string[N];
	for (int i = 0; i < N; i++)
		cin>>arr[i];
	cin>>Q;
	string* qArr = new string[Q];
	for (int i = 0; i < Q; i++)
		cin>>qArr[i];

	for (int i = 0; i < Q; i++)
	{
		int count = 0;
		string temp = qArr[i];
		for (int i = 0; i < N; i++)
		{
			if (!temp.compare(arr[i]))
				count++;
		}
		cout<<count<<endl;
	}
    return 0;
}

