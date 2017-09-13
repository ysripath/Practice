#include <iostream>

using namespace std;
bool isPalindrome(int num);

int main()
{
	int n;
	cout<<"Enter the number to check\n";
	cin>>n;
	if(isPalindrome(n))
		cout<<"Palindrome\n";
	else
		cout<<"Not a palindrome\n";

	return 0;
}

bool isPalindrome(int x)
{
	// Return false if number is -ve or if its divisible by 10
	if ((x <0) || (x%10 == 0))
		return false;
	
	int rev = 0;
	while (x > rev)
	{
		int temp = x % 10;
		x = x/10;
		rev = rev*10 + temp;
	}

	return ((x==rev) || (x == rev/10));
}
