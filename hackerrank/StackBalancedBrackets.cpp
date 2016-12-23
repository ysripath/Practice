#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool balanced(string s)
{
	char buf[10000];
	strcpy(buf, s.c_str());
	int l = strlen(buf);
	stack<char> S;
	char temp;
	for (int i = 0; i < l; i++)
	{
		switch(buf[i])
		{
			case '{': { S.push(buf[i]);
					break;}
			case '(': { S.push(buf[i]); break;}
			case '[': { S.push(buf[i]); break;}
			case ']': {  
					if (S.size() == 0)
						return false;
					temp = S.top();
					if (temp != '[')
						return false;
					else
						S.pop();
					
					break;}
			case '}': {  
					if (S.size() == 0)
						return false;

					temp = S.top();
                                        if (temp != '{')
                                                return false;
                                        else
                                                S.pop();

                                        break;}
			case ')': {     if (S.size() == 0)
						return false;
					temp = S.top();
                                        if (temp != '(')
                                                return false;
                                        else
                                                S.pop();

                                        break;}
			default: {cout<<"Error while string parse\n"; break;}
		}
	}
	if (S.size() == 0)
		return true;
	else
		return false;
}


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
	if (balanced(s))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
    }
    return 0;
}

