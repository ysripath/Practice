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

bool isOnlyTwo(string str)
{
	int count = 0;
	char tempA;
	char tempB;
	int l = str.size();
	if (l <= 2)
		return true;
	char* buf = new char[l];
	strcpy(buf,str.c_str());
	tempA = buf[0];
	tempB = buf[1];
	for (int i = 2; i < l ; i++)
	{
		if (buf[i] != tempA || buf[i] != tempB)
			return false;
		
	}
	return true;
}

string remove(string str,char a)
{
	string temp;
	int l = str.size();
	char* buf = new char[l];
	strcpy(buf,str.c_str());
	for (int i = 0; i < l; i++)
	{
		if (buf[i] != a)
			temp = temp + buf[i];
	}
	return temp;
}

string remove(string str)
{
	
}

string check(string str)
{
	int l = str.size();
	char* buf = new char[l];
	strcpy(buf,str.c_str());
	int i = 0;

	while (i < l-1)
	{
		if (buf[i] == buf[i+1])
		{
			str = remove(str,buf[i]);
			l = str.size();
			if (l == 0)
				return string();
			strcpy(buf,str.c_str());
			i = 0;
			continue;
		}
		i++;
	}
	if (isOnlyTwo(str))
		return str;
	else
		
	
}

int main(){
    int len;
    cin >> len;
    string s;
    cin >> s;
	string temp = check(s);
	cout<<temp.size()<<endl;
    return 0;
}

