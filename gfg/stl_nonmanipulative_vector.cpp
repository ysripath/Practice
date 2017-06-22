// Non manipulative methods for C++ stl vector

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>


using namespace std;

int main()
{
	vector<int> v;
	cout<<"Enter the size of the vector\n";
	int n;
	cin>>n;
	
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		v.push_back(temp);
	}
	
	cout<<"Current vector elements\n";
	for (auto i : v)
		cout<<i<<" ";
	cout<<endl;
	
	reverse(v.begin(), v.end());
	
	cout<<"Reveresed vector elements\n";
	for (auto i : v)
		cout<<i<<" ";
	cout<<endl;
	
	
	cout<<"Max element is "<<*max_element(v.begin(),v.end())<<endl;
	
	
	cout<<"Accumulated su=m "<<accumulate(v.begin(),v.end(),0);
	
	return 0;
}

