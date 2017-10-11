class Solution {
public:
    bool isEqual(char x, char y)
    {
        int a = (int)x;
        int b = (int)y;
        int diff = abs((int)'a' - (int)'A');
        if ((a == b) || (abs(a-diff) == b) || (a == abs(b-diff)))
            return true;
        else
            return false;
    }
    bool isAlpha(char c)
    {
        int a = (int)'a';
        int z = (int)'z';
        int A = (int)'A';
        int Z = (int)'Z';
        int zero = (int)'0';
        int nine = (int)'9';
        int v = (int)c;
        if ((v >= a && v <=z) || (v >= A && v <=Z) || (v >= zero && v <= nine))
            return true;
        else
            return false;
    }
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        
        int l = strlen(s.c_str());
        int b = 0;
        int e = l -1;
        string temp;
        for (int i = 0; i < l; i++)
        {
            if (isAlpha(s[i]))
                temp += s[i];
        }
        if (strlen(temp.c_str()) == 1)
            return true;
        l = strlen(temp.c_str());
        b = 0;
        e = l - 1;
        while (b < e)
        {
            if (toupper(temp[b]) == toupper(temp[e]))
            {
                b++;
                e--;
            }
            else
            {
                return  false;
            }
        }
        return true;
        
        
    }
};
