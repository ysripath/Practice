class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if (!haystack.compare("") && !needle.compare(""))
            return 0;
        if (!needle.compare(""))
            return 0;
        if (!haystack.compare(""))
            return -1;
        if (needle.length() > haystack.length())
            return -1;
        
        int pos = haystack.find(needle.c_str());
        return pos;
    }
};