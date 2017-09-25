#include <iostream>
#include <cstring>

#define CHARA 'a'
#define CHARZ 'z'
#define CHARAA 'A'
#define CHARZZ 'Z'


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



char* convert(char* str)
{
	// convert case and remove special characters
	int l = strlen(str);
	char tmp[l];
	int c = 0;
	int i = 0;
	
	while (i < l)
	{
		if (((int)str[i] < (int)CHARA) || ((int)str[i] > (int)CHARZ))
		{
			if (((int)str[i] >= (int)CHARAA) && ((int)str[i] <= (int)CHARZZ))
			{
				tmp[c++] = (char)((int)str[i++] + 32);
			}
			else
			{
				i++;
			}
		}
		else
		{
			tmp[c++] = str[i++];
		}

	}
	return tmp;
}

bool isPalindrome(char* str)
{
	//cout<<"Inside isPlaindrome str - "<<str<<endl;

	// Convert case and remove punctuations and white space
	char* cmpStr = convert(str);
	int l = strlen(str);
	cout<<l<<endl;
        char* tmp = cmpStr;

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
