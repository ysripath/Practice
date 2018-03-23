class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int,int> util;
        int index = 0;
        auto itr = nums.begin();
        while (itr != nums.end())
        {
           util.insert(pair<int,int>(*itr,index));
            
            auto itr2 = util.find(target-*itr);
            if (itr2 != util.end()
                    && itr2->second != index) 
            {
                vector<int> temp = {itr2->second, index};
                return temp;
            }
            index++;
            itr++;
        }
        
        
    }
};
