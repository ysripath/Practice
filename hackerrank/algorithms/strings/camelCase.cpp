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

using namespace std;


int main(){
    string s;
    cin >> s;
	int l = s.size();
	char* buf = new char[l];
	strcpy(buf,s.c_str());
	int i=0;
	int count = 1;
	while ( i < l)
	{
		if (buf[i] >=65 && buf[i] <=90)
			count++;
		i++;
	}
	cout<<count<<endl;

    return 0;
}

