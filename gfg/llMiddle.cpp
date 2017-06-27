#include <list>
#include <iostream>

using namespace std;

int mid(list<int>);

int main()
{
	list<int> l;
	cout<<"Enter size of LL\n";
	int n;
	cin>>n;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		l.push_back(temp);
	}
	cout<<"Elements are\n";
	for (auto itr : l)
		cout<<itr<<endl;
		
	cout<<"Middle element is \n";
	cout<<mid(l)<<endl;
	return 0;
}


int mid(list<int> l)
{
	auto h = l.begin();
	auto t = l.begin();
	
	while (h != l.end())
	{
		//cout<<*h<<endl;
		h++;
		if (h == l.end())
			return *t;
		h++;
		t++;
	}
	return *t;	 
}
