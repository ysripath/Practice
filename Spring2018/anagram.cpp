class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> m;
        int l = s.length();
        for (int i = 0; i < l; i++)
        {
            char c = s[i];
            auto itr = m.find(c);
            if (itr != m.end())
            {
                itr->second++;
            }
            else {
                m.insert(pair<char, int>(c,1));
            }
        }
        
        l = t.length();
        
        for (int i = 0; i<l; i++)
        {
            char c = t[i];
            auto itr = m.find(c);
            if (itr == m.end())
                return false;
            else {
                itr->second--;
            }
            
        }
        
        auto itr = m.begin();
        while (itr != m.end())
        {
            if (itr->second >0)
                return false;
            itr++;
        }
        
        return true;
        
    }
};
