#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <cstring>
using namespace std;


bool funny(string str)
{

	int l = str.size();
	char buf[10001];
	strcpy(buf, str.c_str());
	int begin = 1;
	int end = l - 2;
	while (begin < l - 1 && end > 0)
	{
		int A = abs(((int)buf[begin] - (int)buf[begin - 1]));
		int B = abs(((int)buf[end] - (int)buf[end + 1]));
		if (A != B)
			return false;
		begin++;
		end--;
	}
	return true;
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int T;
	cin >> T;
	while (T != 0)
	{
		string S;
		cin >> S;
		if (funny(S))
			cout << "Funny\n";
		else
			cout << "Not Funny\n";
		T--;
	}
	return 0;
}

