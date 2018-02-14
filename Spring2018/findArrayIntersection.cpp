class Solution {
public:
    vector<int> intersect(vector<int>& num1, vector<int>& num2) {
        
        vector<int> result;
        
        if (num1.size() == 0 || num2.size() == 0)
        {
            return result;
        }
        
        vector<int> nums1;
        vector<int> nums2;
        if (num1.size() > num2.size())
        {
            nums1 = num1;
            nums2 = num2;
        }
        else
        {
            nums1 = num2;
            nums2 = num1;
        }
        
        
        
        
        map <int,  int> mapUtil;
        
        auto itr1 = nums1.begin();
        while (itr1 != nums1.end())
        {
            auto itrTemp = mapUtil.find(*itr1);
            if (itrTemp != mapUtil.end())
            {
                // already present
                itrTemp->second++;
            }
            else
            {
                mapUtil.insert(pair<int, int>(*itr1, 1));
            }
            itr1++;
        }
        
        
        auto itr2 = nums2.begin();
        while (itr2 != nums2.end())
        {
            auto itrTemp2 = mapUtil.find(*itr2);
            if (itrTemp2 != mapUtil.end())
            {
                // Found match
                if (itrTemp2->second > 0)
                {
                    itrTemp2->second--;
                    result.push_back(*itr2);
                }
            }
            itr2++;
        }
        
        
        return result;
    }
};
