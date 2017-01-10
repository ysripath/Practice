#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

int checkSOS(string str)
{
	int count = 0;
	if (!str.compare("SOS"))
		return count;
	else
	{
		char buf[10];
		strcpy(buf, str.c_str());
		if (buf[0] != 'S')
			count++;
		if (buf[1] != 'O')
			count++;
		if (buf[2] != 'S')
			count++;

	}
	return count;
}


int main() {
	string S;
	cin >> S;

	int l = S.size();
	char buf[100];
	strcpy(buf,S.c_str());
	int count = 0;
	for (int i = 0; i < l; i += 3)
	{
		string temp;
		temp = temp + buf[i] + buf[i + 1] + buf[i + 2];
		count += checkSOS(temp);
	}
	cout << count << endl;

	return 0;
}

