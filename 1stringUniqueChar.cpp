// check if the given string has unique set of characters
// *No additional data structures
// used a character array. O(n^2) solution


//#define bufferMethod

#include <iostream>
#include <string>
#include <string.h>
//#include <locale>
#include <cstring>

using namespace std;

bool isUnique2(string str);
bool isUnique(string str);

int main()
{
	cout<<"Enter the string\n";
	string str;
	getline(cin, str);
#ifdef bufferMethod
	if (isUnique(str))
#else
	if (isUnique2(str))
#endif
		cout<<"Unique\n";
	else
		cout<<"Not unique\n";
	return 0;
}

bool isUnique(string str)
{
	char buf[100];
	strcpy(buf, str.c_str());
	int l = strlen(buf);
	// O(n^2) solution
	for (int i = 0; i < l; i++)
	{
		if ( i == l-1)
			break;
		for (int j = i + 1; j < l; j++)
		{
			if (buf[i] == buf[j])
				return false;
		}
	}
	return true;
}


bool isUnique2(string str)
{
	// ASCII 65 - 90 A-Z
	bool arr[91] = { 0 };
	char buf[100];
	strcpy(buf,str.c_str());
	int l = strlen(buf);
	for (int i = 0; i < l; i++)
		buf[i] = toupper(buf[i]);
	for (int i = 0; i < l; i++)
	{
		if(arr[(int)buf[i]])
			return false;
		else
			arr[(int)buf[i]] = true;
	}
	return true;
}
