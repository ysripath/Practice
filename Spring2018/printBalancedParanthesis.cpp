#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;



 bool isValid(string s) {

        int l = s.length();
        if (l < 2)
            return false;
        
        stack<char> bracketStack;
        
        for (int i = 0; i < l ; i++)
        {
            char c = s[i];
        
        
            switch (c)
            {
                case '(': {
                    bracketStack.push(c);

                } break;
                case ')': {
                    if (bracketStack.empty())
                        return false;
                    if (bracketStack.top() == '(')
                    {
                        bracketStack.pop();
                    }
                    else
                        return false;

                } break;
                case '[': {
                    bracketStack.push(c);

                } break;
                case ']': {
                    if (bracketStack.empty())
                        return false;
                    if (bracketStack.top() == '[')
                    {
                        bracketStack.pop();
                    }
                    else
                        return false;

                } break;
                case '{': {
                    bracketStack.push(c);

                } break;
                case '}': {
                    if (bracketStack.empty())
                        return false;
                    if (bracketStack.top() == '{')
                    {
                        bracketStack.pop();
                    }
                    else
                        return false;

                } break;
                default:
                    return false;
            }
        }
        if (bracketStack.empty())
            return true;
        else
            return false;
        
    }
    
    
    
    void permute(string str, vector<string> &vec)
    {
        
        sort(str.begin(), str.end());
        
        do 
        {
            if (isValid(str))
            {
                vec.push_back(str);
            }
        } while (next_permutation(str.begin(), str.end()));
    }
    
    
    vector<string> generateParenthesis(int n) {
        vector<string> validStrings;
        if (n == 0) {
            validStrings.push_back("");
            return validStrings;
        }
        string mainString = "";
        int i;
        for (i = 0; i < n; i++)
            mainString += '(';
        for ( i; i < 2*n; i++)
            mainString += ')';
        
        //sort(mainString.begin(), mainString.end());
        
    
        permute(mainString, validStrings);
        return validStrings;
    }

int main()
{

	cout<<"Enter n value\n";
	int N;
	cin >> N;
	

	vector<string> vec = generateParenthesis(N);

	auto itr = vec.begin();
	while (itr != vec.end())
	{
		cout<<*itr<<endl;
		itr++;
	}
	
	return 0;
}


