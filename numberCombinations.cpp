#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <stdlib.h>
#include <cstdio>
using namespace std;



int N;
void printCom(vector<int> v, bool arr[], int k)
{
	if (k > N)
		return;
	string str;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == true)
		{
			
			char buf[1];
			sprintf(buf,"%d",v[i]);
			//string temp(buf);
			str = str + buf;
		}
		
		else if (arr[i] == false)
			break;
	}
	cout<<str<<endl;
	for (int i = k; i < N; i++)
	{
		arr[i] = true;
		printCom(v,arr,i+1);
	}
}

int main()
{
	vector<int> v;
	cout<<"Enter the N\n";
	
	cin>>N;
	cout<<"Enter the numbers\n";
	for (int i = 0; i < N; i++)
	{
		int n; 
		cin>>n;
		v.push_back(n);
	}

	bool* arr = new bool[N];
	for (int i = 0; i < N; i++)
		arr[i] = false;
	arr[0] = true;
	printCom(v,arr,1);
	return 0;
}
