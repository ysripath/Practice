class Solution {
public:
    int firstUniqChar(string s) {
        int l = s.length();
        map<char,int> mapUtil;
        
        for (int i = 0; i < l; i++)
        {
            auto itr = mapUtil.find(s[i]);
            if (itr != mapUtil.end())
            {
                itr->second++;
            }
            else
            {
                mapUtil.insert(pair<char,int>(s[i], 1));
            }
        }
        
        for (int i = 0; i < l; i++)
        {
            auto itr = mapUtil.find(s[i]);
            if (itr->second == 1)
                return i;
        }
        return -1;
    }
};
