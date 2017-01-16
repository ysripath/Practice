#include <iostream>
#include <vector>

using namespace std;

void insertSort(vector<int>& v, int N)
{
	int l = v.size();
	int j = 1;
	int i = 0;

	for (int j = 1; j < l; j++)
	{
		i = j-1;
		int key = v[j];
		while (i>=0 && v[i] > key)
		{	
			v[i+1] = v[i];
			i--;
		}
		v[i+1] = key;
	}
}

int main()
{
	vector<int> v;
	cout<<"Enter the size of sequence to be sorted\n";
	int N;
	cin>>N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	insertSort(v,N);
	cout<<"Sorted list\n";
	for (int i = 0; i < N; i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}
