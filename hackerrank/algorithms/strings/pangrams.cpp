#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
using namespace std;


bool isPanagram(string str)
{
	bool arr[100] = { 0 };
	int l = str.size();
	char* buf = new char[l];
	strcpy(buf,str.c_str());
	for (int i = 0; i < l; i++)
	{
		if ((int)buf[i] >= 65 && (int)buf[i] <= 90)
			arr[(int)buf[i]] = true;
	}
	for (int i = 65; i <= 90; i++)
	{
		if (arr[i] == false)
		{
			//delete[] buf;

			return false;
		}
	}
	//delete[] buf;
	return true;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	string str;
	getline(cin,str);
	transform(str.begin(),str.end(),str.begin(),::toupper);
	//cout<<str<<endl;
	if (isPanagram(str))
	{
		cout<<"pangram\n";
	}
	else
	{
		cout<<"not pangram\n";
	}
    return 0;
}


