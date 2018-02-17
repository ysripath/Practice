class Solution {
public:
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
};
