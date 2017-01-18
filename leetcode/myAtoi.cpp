#include <string>
using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		if (!str.compare(""))
			return 0;
		int i = str.find_first_not_of(' ');
		bool sFlag = true;
		bool flag = false;
		int k = str.find_first_of("+");
		int m = str.find_first_of("-");
		if (k != -1 && m != -1)
			return 0;
		if (str[i] == '+' || str[i] == '-') {
			if (str[i] == '+')
				sFlag = true;
			else if (str[i] == '-')
				sFlag = false;
			flag = true;
		}
		//if (flag)
		//i++;
		i = str.find_first_not_of("0+-", i);
		if (i == -1)
			return 0;
		int temp = 0;
		int l = str.length();
		for (i; i < l; i++)
		{
			if ((int)str[i] >= 47 && (int)str[i] <= 57)
				temp = temp * 10 + ((int)str[i] - (int)'0');
			//	else if (str[i] == ' ')
			//	    return 0;
			else
				break;
		}
		if (sFlag)
		{
			if (temp <= INT_MIN)
				return INT_MAX;
			else
				return temp;
		}
		else
		{
			if (-temp >= INT_MAX)
				return INT_MIN;
			else
				return -temp;
		}

	}
};