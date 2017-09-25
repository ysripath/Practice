#include <iostream>
#include <cstring>
using namespace std;


bool isPalindrome(char* str);

int main()
{
	char str[10];
	cout<<"Enter string to be checked for Palindrom\n";
	cin>>str;
	cout<<str<<endl;

	if (isPalindrome(str))
		cout<<"Palindrom\n";
	else
		cout<<"Not a palindrom\n";

	return 0;
}


bool isPalindrome(char* str)
{
	//cout<<"Inside isPlaindrome str - "<<str<<endl;
	int l = strlen(str);
	cout<<l<<endl;
        char* tmp = str;
	l--;
	int i = 0;
	while (l >= 0)
	{
		if (str[i++] != tmp[l--]) 
			return false;
	}

	return true;
}
