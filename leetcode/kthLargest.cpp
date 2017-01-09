class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l = nums.size();
        int max = -1;
        
        int count = 0;
        int i = l-1;
        int temp = -1;
        /*while (count != k)
        {
            if (temp == -1)
            {
                if (k == 1)
                    return nums[i];
                temp = nums[i];
                i--;
                count++;
            }
            else
            {
                if (nums[i] == temp)
                    i--;
                else
                    {
                        i--;
                        count++;
                    }
            }
                
            
        }
        return nums[++i];*/
        while (count != k)
        {
            i--;
            count++;
        }
        return nums[++i];
    }
};
