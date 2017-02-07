#include <cstring>
#include <stdlib.h>

class Solution {
public:
    int countSegments(string s) {
        if(!s.compare(""))
        {
            return 0;
        }
        
        char* buf = new char[s.length()];
        char* buf2 = new char[s.length()];
        strcpy(buf,s.c_str());
        buf2 = strtok(buf," ");
        int count = 0;
        while (buf2 != NULL)
        {
            count++;
            buf2 = strtok(NULL," ");
        }
        return count;
    }
};