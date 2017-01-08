#include <iostream>
#include <vector>

using namespace std;


void rotate(vector<int>& v)
{
	int temp;
	int l = 0;
	for (auto itr = v.begin(); itr != v.end(); itr++)
		l++;

	for (int i = 0; i < l; i++)
	{
		if (i != 0)
		{
			v[0] = v[i];
			v[i] = temp;
			temp = v[0];
		}
		else if (i == 0)
			temp = v[i];
	}
	v[0] = temp;
}


int main()
{
	vector<int> v;
	cout<<"Enter N\n";
	int N;
	cin>>N;
	int n;
	for (int i = 0; i < N; i++)
	{
		cin>>n;
		v.push_back(n);
	}
	cout<<"Enter k value\n";
	int k;
	cin>>k;
	for (int i = 0; i < k; i++)
	{
		rotate(v);
	}
	for (auto i : v)
	{
		cout<<i<<" ";
	}
	cout<<endl;
}	
