#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <cstring>
using namespace std;

bool parse(string temp)
{
	bool arr[100] = { 0 };
	int l = temp.size();
	char buf[1001];
	strcpy(buf,temp.c_str());
	int i = 0;
	while ( i < l-1)
	{
		if (buf[i] == buf[i+1])
			return false;
		i++;
	}
	return true;
}


string check(string str)
{
	int l = str.size();
	char buf[1001];
	strcpy(buf,str.c_str());
	int i = 0;
	bool arr[100] = { 0 };
	while ( i< l-1)
	{
		if (buf[i] == buf[i+1])
		{
			arr[i] = true;
			arr[i+1] = true;
			i +=2;
		}
		else
			i++;
			
	}
	bool emptyFlag = true;
	for (int i = 0; i < l; i++)
	{
		if (arr[i] == 0)
			emptyFlag = false;
	}
	string temp;
	if (emptyFlag)
		return string("Empty String");
	else
	{
		
		for (int i = 0; i < l; i++)
		{
			if (arr[i] == 0)
				temp = temp + buf[i];
		}
	}
	if(parse(temp))
		return temp;
	else
		return check(temp);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	string str;
	cin>>str;
	cout<<check(str)<<endl;
    return 0;
}

