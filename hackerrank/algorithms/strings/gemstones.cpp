#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

bool isPresentInAll(char c, vector<string> v)
{
	for (auto itr = v.begin(); itr != v.end(); itr++)
	{
		string temp = *itr;
		size_t found = temp.find(c);
		if (found == std::string::npos)
			return false;
	}
	return true;
}

int getGemStones(vector<string> v)
{
	bool arr[150] = { 0 };
	for (auto itr = v.begin(); itr != v.end(); itr++)
	{
		string temp = *itr;
		int l = temp.size();
		//char* buf = new char[l];
		char buf[10001];
		strcpy(buf, temp.c_str());
		for (int i = 0; i < l; i++)
		{
			if (arr[(int)buf[i]] == true)
				continue;
			char c = buf[i];
			if (isPresentInAll(c, v))
				arr[(int)c] = true;			
		}
	}

	int count = 0;
	for (int i = 97; i <= 122; i++)
	{
		if (arr[i] == true)
			count++;
	}
	return count;
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int N;
	cin >> N;
	vector<string> V;
	while (N != 0)
	{
		string temp;
		cin >> temp;
		V.push_back(temp);
		N--;
	}
	int count = getGemStones(V);
	cout << count << endl;
	return 0;
}

