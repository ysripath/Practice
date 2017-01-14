#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> a, vector<int> b)
{
	vector<int> r;
	auto itrA = a.begin();
	auto itrB = b.begin();
	while (itrA != a.end() && itrB != b.end())
	{
		if (*itrA <= *itrB)
		{
			r.push_back(*itrA);
			itrA++;
		}
		else
		{
			r.push_back(*itrB);
			itrB++;
		}

	}

	while (itrA != a.end())
	{
		r.push_back(*itrA);
		itrA++;
	}
	while (itrB != b.end())
	{
		r.push_back(*itrB);
		itrB++;
	}
	return r;
}
vector<int> mergeSort(int begin, int end,vector<int> v)
{
	if (begin == end)
	{
		vector<int> V;
		V.push_back(v[begin]);
		return V;
	}
	else if (begin < end)
	{
		int mid = (begin + end) / 2;
//		if (mid == 0)
	//		mid = 1;
		vector<int> a = mergeSort(begin, mid, v);
		vector<int> b = mergeSort(mid+1, end, v);
		v = merge(a, b);
		return v;
	}
	else
	{
		vector<int> V;
		V.push_back(v[end]);
		return V;
	}
}
int main()
{
	cout << "Enter the number of items to be sorted\n";
	int N;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	v = mergeSort(0,N-1,v);

	cout << "Sorted list\n";
	for (auto itr : v)
	{
		cout << itr << " ";
	}

	return 0;
}