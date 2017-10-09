#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool test(string str);
int main()
{
	string str;
	cout<<"Enter the string\n";
	cin>>str;
	if (test(str))
		cout<<"Right\n";
	else
		cout<<"Wrong\n";

	return 0;
}

bool isCapital(char a)
{
	if (((int)a >= (int)'A') && ((int)a <= (int)'Z'))
		return true;
	else
		return false;
}
bool test(string str)
{
	int l = strlen(str.c_str());
	bool cFlag = false;
	bool sFlag = false;
	bool smallFlag = false;


	for (int i = 0; i < l; i++)
	{
		if (isCapital(str[i]))
		{
			if (!cFlag && i == 0)
			{
				cFlag = true;
				continue;
			}
			else if (cFlag && !smallFlag)
				sFlag = true; 
			else
				return false;
		}
		else
		{
			smallFlag = true;
		}
		if (cFlag && sFlag && smallFlag)
			return false;		
	}
	return true;
}

