// Reverse a C style string


//#define withSpace
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string reverse(string str);
void reverse2(char* str);

int main()
{
	cout<<"Enter the string to be reversed\n";
#ifdef withSpace
	string str;
	getline(cin,str);
	char* revStr = reverse(str);
#else
	char* str;
	cin>>str;
	//string revStr = 
	reverse2(str);
#endif
	cout<<"Reversed string\n";
	cout<<str<<endl;
	return 0;
}

string reverse(string str)
{
	char buf[100];
	strcpy(buf, str.c_str());
	int l = strlen(buf);
	char buf2[100];
	int k = 0;
	for (int i = l -1; i >=0; i--)
		buf2[k++] = buf[i];
	buf2[k] = '\0';
	return string(buf2);
}

void reverse2(char* str)
{
	char* end = str;
	char tmp;
	while(*end)
	{
		cout<<*end<<endl;
		++end;
	}
	cout<<"Debug1"<<endl;
	//--end;
	while (str < end)
	{
		tmp = *str;
		*str++ = *end;
		*end-- = tmp;
	}
	*str = '\0';
	cout<<"Debuf 2 "<<str<<endl;
	//return str;
}
