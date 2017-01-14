#include <iostream>
#include <vector>

using namespace std;
int partition(vector<int>& v, int begin, int end)
{
	if (begin == end)
		return begin;
	int temp = v[begin];
	int i = begin;
	int j;
	for (j = begin + 1; j <= end; j++)
	{
		if (v[j] < temp)
		{
			i++;
			int temp2 = v[j];
			v[j] = v[i];
			v[i] = temp2;
		}
	}
	int temp2 = v[i];
	v[i] = v[begin];
	v[begin] = temp2;
	return (i);
}

void quickSort(vector<int>& v, int begin, int end)
{
	if (begin < end)
	{
		int p = partition(v, begin,end);
		quickSort(v, begin, p - 1);
		quickSort(v, p + 1, end);
	}
}
int main()
{
	int N;
	cout << "enter the number of elements to be sorted\n";
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);

	}

	quickSort(v,0,N-1);
	for (auto itr : v)
	{
		cout << itr << " ";
	}

	return 0;
}
