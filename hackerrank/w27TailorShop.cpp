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

bool presentInMap(map<int, bool> m, int k)
{
	auto itr = m.find(k);
	if (itr == m.end())
		return false;
	else
		return true;
}


int main() {

	//map<int, bool> hashMap;
	bool arr[100000] = { 0 };
	int n;
	int p;
	cin >> n >> p;
	vector<int> a(n);
	for (int a_i = 0; a_i < n; a_i++) {
		cin >> a[a_i];
	}
	// your code goes here
	int totalN = 0;
	for (int i = 0; i<n; i++)
	{
		if (a[i] % p == 0)
		{
			int k = a[i] / p;
			//auto itr = hashMap.find(k);
			if (arr[k] != 0)
			{
				//k++;
				bool flag = true;

				while (flag)
				{
					k++;
					//itr = hashMap.find(k);
					if (arr[k] == 0)
						break;
				}

				totalN += k;
				//hashMap.insert(make_pair(k, true));
				arr[k] = 1;
			}
			else
			{
				totalN += k;
				//hashMap.insert(make_pair(k, true));
				arr[k] = 1;
			}
		}
		else
		{
			int k = a[i];
			while (k%p != 0)
				k--;
			k += p;
			a[i] = k;
			k = k / p;
			//auto itr = hashMap.find(k);
			if (arr[k] != 0)
			{
				//k++;
				bool flag = true;

				while (flag)
				{
					k++;
					//itr = hashMap.find(k);
					if (arr[k] == 0)
						break;
				}
				totalN += k;
				//hashMap.insert(make_pair(k, true));
				arr[k] = 1;
			}
			else
			{
				totalN += k;
				//hashMap.insert(make_pair(k, true));
				arr[k] = 1;
			}

		}
	}

	cout << totalN << endl;
	return 0;
}

