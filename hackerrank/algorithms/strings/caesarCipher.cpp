#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
using namespace std;

int check(int i, int k)
{
	if (i <= 90)
	{
		while (i != 90 && k != 0)
		{
			i++;
			k--;
		}
		if (k != 0)
		{
			i = 64;
			i = i + k;
		}
	}
	else
	{
		while (i != 122 && k != 0)
                {
                        i++;
			k--;
                }
                if (k != 0)
                {
                        i = 96;
                        i = i + k;
                }
	}
	return i;
}

string convert(string str, int q)
{
	int l = str.size();
	char* buf = new char[l];
	strcpy(buf,str.c_str());
	
	for (int i = 0; i < l; i++)
	{
		int k = (int)buf[i];
		if ((k >= 65 && k <= 90) || (k >= 97 && k <= 122))
		{
			/*if ((k > 90 && (q+k > 122)) || (k < 90 && (q+k >90)))
			{
				k = check(k,q);
				buf[i] = char(k);
			}
			else
			{
				
				buf[i] = char(k+q);
			}*/
			char a;
			if (isalpha(buf[i]))
			{
				a = isupper(buf[i])?'A':'a';
				buf[i] = (char)(a + ((int)buf[i] - (int)a + q)%26);	
			}
						 
		}
	}
	return string(buf);
}

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
	string res = convert(s,k);
	cout<<res<<endl;
    return 0;
}


